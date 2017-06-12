//============================================================================
// Name        : main.cxx
// Author      : tkorthals <tkorthals@cit-ec.uni-bielefeld.de>
// Description : Wrapper for the Kalman filter
//============================================================================

#define INFO_MSG_
// #define DEBUG_MSG_
// #define SUCCESS_MSG_
#define WARNING_MSG_
#define ERROR_MSG_
#include <MSG.h>

#include <iostream>
#include <boost/thread.hpp>
#include <boost/program_options.hpp>
#include <boost/shared_ptr.hpp>
#include <Eigen/Geometry>

// Flightcontroller stuff
#ifdef __cplusplus
extern "C" {
#endif
#include <rt_defines.h>
#include <PoseEstimationController.h>
#include <base85.h>
#ifdef __cplusplus
} // closing brace for extern "C"
#endif

/* commands as in serial_cli of FC
 typedef enum {
     CMD_ROLL        = 0x0,
     CMD_PITCH       = 0x1,
     CMD_YAW         = 0x2,
     CMD_THROTTLE    = 0x3,
     CMD_AUX1        = 0x4,
     CMD_AUX2        = 0x5,
     CMD_AUX3        = 0x6,
     CMD_AUX4        = 0x7,
     CMD_AUX5        = 0x8,
     CMD_AUX6        = 0x9,
     CMD_AUX7        = 0xA,
     CMD_AUX8        = 0xB,
     CMD_GET         = 0xC,
     CMD_GET_VALUES  = 0xD
} byteCmd_t; */

#define MAXBYTES 1024
typedef union {
    uint8_t data[44];
    struct {
        int32_t accSmooth[3];
        int32_t gyroADC[3];
        int32_t baroAlt;
        int32_t baroTemp;
        int32_t magADC[3];
    } values;
} sensorData_t;


// RSB
#include <rsb/Factory.h>
#include <rsb/Version.h>
#include <rsb/Event.h>
#include <rsb/Handler.h>
#include <rsb/converter/Repository.h>
#include <rsb/util/QueuePushHandler.h>
using namespace rsb;

// RST
#include <rsb/converter/ProtocolBufferConverter.h>

// RSC
#include <rsc/misc/SignalWaiter.h>
#include <rsc/threading/PeriodicTask.h>
#include <rsc/threading/ThreadedTaskExecutor.h>
#include <rsc/threading/SynchronizedQueue.h>
using namespace rsc::misc;

// TWB
#include <TwbTracking.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>  // int32
#include <errno.h>

// #include <ControllerAreaNetwork.h>

using namespace std;

inline Eigen::Quaterniond
euler2Quaternion( const double roll,
                  const double pitch,
                  const double yaw )
{
    Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
    Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
    Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());

    const Eigen::Quaterniond q = yawAngle * pitchAngle * rollAngle;
    return q;
}


class task: public rsc::threading::PeriodicTask {
public:

    task(int fd, const unsigned int& ms = 10) :
            rsc::threading::PeriodicTask(ms), fd(fd){
    }

    virtual ~task() {
    }

    virtual void execute() {

          for(;;) {

            const int count = read(fd, buffer, MAXBYTES); //TODO: check when read finished

            // Decode
            for (int i = 0; i < count; i++) {
                if (buffer[i] == '\n') {
                    // Decode data and put into struct
                    decode_85(decoded.data, (uint8_t*) buf_decode, 55);
                    // TODO Check for TWB data
                    // TODO Include KF
                    INFO_MSG(decoded.values.accSmooth[0] << ", " << decoded.values.accSmooth[1] << ", " << decoded.values.accSmooth[2] << ", " << decoded.values.gyroADC[0] << ", " << decoded.values.gyroADC[1] << ", " << decoded.values.gyroADC[2] << ", " << decoded.values.baroAlt << ", " << decoded.values.baroTemp << ", " << decoded.values.magADC[0] << ", " << decoded.values.magADC[1] << ", " << decoded.values.magADC[2] << "\n");
                    // TODO Process the controller and send the commands to the FC
                    {
                      uint8_t inbuf[4] = {0,0,0x05,0xDC}; // 1 byte: ROLL command, 2 byte: 0 = "empty byte" to have 4 bytes for encoding with base85, 3, 4 bytes: value (3: high byte, 4: low byte)
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      uint8_t inbuf[4] = {1,0,0x05,0xDC};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      uint8_t inbuf[4] = {2,0,0x05,0xDC};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      uint8_t inbuf[4] = {3,0,0x05,0xDC};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    
                    // Cleanup
                    count_decode = 0;
                    count_msgs++;
                    break;
                } else {
                    buf_decode[count_decode] = buffer[i];
                    count_decode++;
                }
            }
        }

    }

private:

    int fd;
    char buffer[MAXBYTES];
    char buf_decode[55];
    uint8_t buf[5];
    sensorData_t decoded;
    int count_decode = 0;
    int count_msgs = 0;

};

int main(int argc, char **argv) {
  INFO_MSG("")
  // Handle program options
  namespace po = boost::program_options;
  
  std::string rsbInScope = "/twb";
  std::string serialInterface = "/dev/ttyACM0";
  uint32_t rsbPeriod = 10;

  po::options_description options("Allowed options");
  options.add_options()("help,h", "Display a help message.")
    ("inscope,o", po::value < std::string > (&rsbInScope), "Scope for receiving TWB messages")
    ("period,t", po::value < uint32_t > (&rsbPeriod), "Update interval in milliseconds (Should meet the RT interval of the filter)")
    ("serialInterface,s", po::value< std::string > (&serialInterface), "Serial interface location");

  // allow to give the value as a positional argument
  po::positional_options_description p;
  p.add("value", 1);

  po::variables_map vm;
  po::store( po::command_line_parser(argc, argv).options(options).positional(p).run(), vm);

  // first, process the help option
  if (vm.count("help")) {
      std::cout << options << "\n";
      exit(1);
  }

  // afterwards, let program options handle argument errors
  po::notify(vm);

  // Register new converter for std::vector<int>
  boost::shared_ptr< rsb::converter::ProtocolBufferConverter<rst::geometry::Pose> >
      converter(new rsb::converter::ProtocolBufferConverter<rst::geometry::Pose>());
  rsb::converter::converterRepository<std::string>()->registerConverter(converter);

  // Prepare RSB informer
  rsb::Factory& factory = rsb::getFactory();
  // TODO Include TWB listener

  // Init the CAN interface
//   ControllerAreaNetwork CAN;


  // TTY stuff initialization
  int fd = open(serialInterface.c_str(), O_RDWR);
  if (fd < 0) {
    ERROR_MSG("Error opening " << serialInterface << ": " << strerror(errno) << "\n");
    return -1;
  }
  char buf = '#';
  write(fd, &buf, 1);
  
  // Init KF
//   PoseEstimationController_initialize();
  
  // Periodic task excecution
  rsc::threading::ThreadedTaskExecutor exec;
  exec.schedule(rsc::threading::TaskPtr(new task(rsbPeriod, fd)));

  // Wait until finish
  rsc::misc::initSignalWaiter();
  return rsc::misc::suggestedExitCode(rsc::misc::waitForSignal());
}
