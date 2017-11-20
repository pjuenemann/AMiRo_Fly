<<<<<<< HEAD
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

struct {
    uint8_t u_z;
    uint8_t u_psi;
    uint8_t u_phi;
    uint8_t u_theta;
} output;

struct {
    uint8_t posX;
    uint8_t posY;
    uint8_t posZ;
} dataTWB; 

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
#include "TwbTracking.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>  // int32
#include <errno.h>

// #include <ControllerAreaNetwork.h>

using namespace std;

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (rtU.enableDrone) {
      INFO_MSG("Filter");
  }
  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */
  //ExtU rtU;
  rtU.TWB_data[0] = dataTWB.posX;
  rtU.TWB_data[1] = dataTWB.posY;
  rtU.TWB_data[2] = dataTWB.posZ;

  // Set x_desired 
  rtU.x_desired[0] = 1;
  rtU.x_desired[1] = 1;
  rtU.x_desired[2] = 1;
  rtU.x_desired[3] = 0;
  /* Step the model for base rate */
  PoseEstimationController_step();
  /* Get model outputs here */
  output.u_z = rtY.u[0];
  output.u_psi = rtY.u[1];
  output.u_phi = rtY.u[2];
  output.u_theta = rtY.u[3];
  /* Get state estimation after KF step */
  INFO_MSG(rtY.x[0] << ", " << rtY.x[1] << ", " << rtY.x[2] << ", " << rtY.x[3] << ", " << rtY.x[4] << ", " << rtY.x[5] << ", " << rtY.x[6] << ", " << rtY.x[7] << ", " << rtY.x[8] << ", " << rtY.x[9] << ", " << rtY.x[10] << ", " << rtY.x[11]);
  INFO_MSG((int) output.u_z << ", " << (int) output.u_psi << ", " << (int) output.u_phi << ", " << (int) output.u_theta);
  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

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

    task(const std::string interface, boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>>trackingQueue, int32_t markerId, const unsigned int& ms = 10) :
            rsc::threading::PeriodicTask(ms), trackingQueue(trackingQueue), markerId(markerId) {
        fd = open(interface.c_str(), O_RDWR);
        if (fd < 0) {
            ERROR_MSG("Error opening " << interface << ": " << strerror(errno) << "\n");
        }
        char buf = '#';
        write(fd, &buf, 1);
    }

    virtual ~task() {
    }

    virtual void execute() {
/*        struct timeval t0;
        struct timeval t1;
        float elapsed;
        time_t mtime;
        char buff[80];
        struct tm * timeinfo;

        gettimeofday(&t0, 0);
        
        for(;;) {
	const int count = read(fd, buffer, MAXBYTES); //TODO: check when read finished
		//gettimeofday(&t1, 0);
   		//elapsed = timedifference_msec(t0, t1);
		//if (elapsed > 1000) {
		//	printf("Messages/Second: %i\n", count_msgs);
		//	gettimeofday(&t0, 0);
		//	count_msgs = 0;
		//}

		for (int i = 0; i < count; i++) {
			if (buffer[i] == '\n') {
				// decode data and put into struct
				decode_85(decoded.data, (uint8_t*) buf_decode, 55);
				//time(&mtime);				
				//timeinfo = localtime (&mtime);
				//strftime(buff, sizeof(buff), "%Y-%m-%dT%H:%M:%S.", timeinfo);
				// print with timestamp formatted in same way as in data from TWB
				//fprintf(fp, "%s%06ld+02:00,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", buff, t1.tv_usec, decoded.values.accSmooth[0], decoded.values.accSmooth[1], decoded.values.accSmooth[2], decoded.values.gyroADC[0], decoded.values.gyroADC[1], decoded.values.gyroADC[2], decoded.values.baroAlt, decoded.values.baroTemp, decoded.values.magADC[0], decoded.values.magADC[1], decoded.values.magADC[2]);
                                INFO_MSG((int)decoded.values.accSmooth[0] << ", " << (int)decoded.values.accSmooth[1] << ", " << (int)decoded.values.accSmooth[2] << ", " << decoded.values.gyroADC[0] << ", " << decoded.values.gyroADC[1] << ", " << decoded.values.gyroADC[2] << ", " << decoded.values.baroAlt << ", " << decoded.values.baroTemp << ", " << decoded.values.magADC[0] << ", " << decoded.values.magADC[1] << ", " << decoded.values.magADC[2] << "\n");
				count_decode = 0;
				count_msgs++;
			} else {
				buf_decode[count_decode] = buffer[i];
				count_decode++;
			}
		}
	}*/
        
        
        
          for(;;) {
            // dataTwbAvailable = false;
            const int count = read(fd, buffer, MAXBYTES); //TODO: check when read finished
            INFO_MSG(count);
            // if (fd == 0) dann überprüfe buffer 
            // Decode
            rtU.enableDrone = false;
            for (int i = 0; i < count; i++) {
                if (buffer[i] == '\n') {    //buffer leer, dann dekodieren und Berechnungen damit starten
                    // Decode data and put into struct
                    rtU.enableDrone = true;
                    decode_85(decoded.data, (uint8_t*) buf_decode, 55);
                    // Check for TWB data
                    // TODO Add non blocking request for TWB data
                    trackingObjectList = twbTrackingProcess::getNextTrackingObjects(trackingQueue, -1);
                    // überprüfen ob liste leer, dann nur mit FC Daten ausführen
                    rtU.enableTWB = false;
                    if (trackingObjectList.size() != 0) {
                        if (trackingObjectList.at(0).id >= 0) {
                            for (int idx = 0; idx < trackingObjectList.size(); idx++) {
                                if ( trackingObjectList.at(idx).id == markerId) {
                                    // TODO Do something with the coordinates
                                    // dataTwbAvailable = true;
                                    rtU.enableTWB = true;
                                    dataTWB.posX = trackingObjectList.at(idx).pos.x;
                                    dataTWB.posY = trackingObjectList.at(idx).pos.y;
                                    dataTWB.posZ = trackingObjectList.at(idx).pos.z;
                                    //  trackingObjectList.at(idx).pos.theta;
                                }
                            
                            }
                        }
                    }
                    // TODO Include KF
                    INFO_MSG("DRONE");
                    INFO_MSG((int)decoded.values.accSmooth[0] << ", " << (int)decoded.values.accSmooth[1] << ", " << (int)decoded.values.accSmooth[2] << ", " << decoded.values.gyroADC[0] << ", " << decoded.values.gyroADC[1] << ", " << decoded.values.gyroADC[2] << ", " << decoded.values.baroAlt << ", " << decoded.values.baroTemp << ", " << decoded.values.magADC[0] << ", " << decoded.values.magADC[1] << ", " << decoded.values.magADC[2] << "\n");
                    // Set decoded data from FC sensors
                    rtU.drone_raw_data[0] = (int)decoded.values.gyroADC[0];
                    rtU.drone_raw_data[1] = (int)decoded.values.gyroADC[1];
                    rtU.drone_raw_data[2] = (int)decoded.values.gyroADC[2];
                    rtU.drone_raw_data[3] = (int)decoded.values.accSmooth[0];
                    rtU.drone_raw_data[4] = (int)decoded.values.accSmooth[1];
                    rtU.drone_raw_data[5] = (int)decoded.values.accSmooth[2];
                    rtU.drone_raw_data[6] = (int)decoded.values.magADC[0];
                    rtU.drone_raw_data[7] = (int)decoded.values.magADC[1];
                    rtU.drone_raw_data[8] = (int)decoded.values.magADC[2];
                    rtU.drone_raw_data[9] = (int)decoded.values.baroAlt;
                    rtU.drone_raw_data[10] = (int)decoded.values.baroTemp;
                    for (int i = 0; i < 10; i++) {
                        if (abs(rtU.drone_raw_data[i]) > 30000) {
                            rtU.enableDrone = false;
                            INFO_MSG("TREFFER");
                            break;
                        }
                    }
                    //rt_OneStep();
                    // TODO Process the controller and send the commands to the FC
                    // 0: ROLL, 1: PITCH, 2: YAW, 3: THROTTLE
                    /*{
                      uint8_t inbuf[4] = {0,0,*((uint8_t*)&output.u_z + 1),*((uint8_t*)&output.u_z + 0)}; // 1 byte: ROLL command, 2 byte: 0 = "empty byte" to have 4 bytes for encoding with base85, 3, 4 bytes: value (3: high byte, 4: low byte)
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      uint8_t inbuf[4] = {1,0,0xD4,0xC2};//{1,0,*((uint8_t*)&output.u_psi + 1),*((uint8_t*)&output.u_psi + 0)};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      uint8_t inbuf[4] = {2,0,0xD4,0xC2};//{2,0,*((uint8_t*)&output.u_phi + 1),*((uint8_t*)&output.u_phi + 0)};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }
                    {
                      //uint8_t inbuf[4] = {3,0,*((uint8_t*)&output.u_theta + 1),*((uint8_t*)&output.u_theta + 0)};
                      uint8_t inbuf[4] = {3,0,0xD4,0xC2};
                      encode_85(buf, inbuf, 4);                
                      write(fd, &buf, 4);
                    }*/
                    // Cleanup
                    count_decode = 0;
                    count_msgs++;
                    break;
                } else {    //Solange noch was in buffer ist, fülle damit buf_decode
                    buf_decode[count_decode] = buffer[i];
                    count_decode++;
                }
            }
        }

    }

private:

    int fd;
    boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>> trackingQueue;
    int32_t markerId;
    char buffer[MAXBYTES];
    char buf_decode[55];
    uint8_t buf[5];
    sensorData_t decoded;
    int count_decode = 0;
    int count_msgs = 0;
    twbTracking::proto::ObjectList trackingPoseList;
    std::vector<twbTrackingProcess::TrackingObject> trackingObjectList;
    // bool dataTwbAvailable;

};

int main(int argc, char **argv) {
  INFO_MSG("")
  // Handle program options
  namespace po = boost::program_options;
  
  std::string rsbInScope = "/twb";
  std::string serialInterface = "/dev/ttyACM0";
  uint32_t rsbPeriod = 10;
  int32_t markerId = -1;

  po::options_description options("Allowed options");
  options.add_options()("help,h", "Display a help message.")
    ("inscope,o", po::value < std::string > (&rsbInScope), "Scope for receiving TWB messages")
    ("markerId,i", po::value < int32_t > (&markerId), "Marker ID attached to drone")
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

  // Register new converter
  twbTrackingProcess::registerTracking();  
  rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>::Ptr converterObject(new rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>);
  rsb::converter::converterRepository<std::string>()->registerConverter(converterObject);

  // Prepare RSB
  rsb::Factory& factory = rsb::getFactory();
  // TODO Revert if you realy want to work with the TWB
//  rsb::ListenerPtr trackingListener = factory.createListener(rsbInScope, twbTrackingProcess::getTrackingRSBConfig());
  rsb::ListenerPtr trackingListener = factory.createListener(rsbInScope);
  boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>>trackingQueue(new rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>(1));
  trackingListener->addHandler(rsb::HandlerPtr(new rsb::util::QueuePushHandler<twbTracking::proto::ObjectList>(trackingQueue)));

  // Init the CAN interface
//   ControllerAreaNetwork CAN;


  // TTY stuff initialization
  int fd = open(serialInterface.c_str(), O_RDWR | O_NONBLOCK);
  if (fd < 0) {
    ERROR_MSG("Error opening " << serialInterface << ": " << strerror(errno) << "\n");
    return -1;
  }
  char buf = '#';
  write(fd, &buf, 1);
  
  // Init KF
  PoseEstimationController_initialize();
  
  // Periodic task excecution
  rsc::threading::ThreadedTaskExecutor exec;
  exec.schedule(rsc::threading::TaskPtr(new task(serialInterface, trackingQueue, markerId, rsbPeriod)));

  // Wait until finish
  rsc::misc::initSignalWaiter();
  return rsc::misc::suggestedExitCode(rsc::misc::waitForSignal());
}
=======
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
#include <termios.h>
#include <unistd.h>

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

struct {
    uint8_t u_z;
    uint8_t u_psi;
    uint8_t u_phi;
    uint8_t u_theta;
} output;

struct {
    uint8_t posX;
    uint8_t posY;
    uint8_t posZ;
} dataTWB; 

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
#include "TwbTracking.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>  // int32
#include <errno.h>

// #include <ControllerAreaNetwork.h>

using namespace std;

void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;
  if (rtU.enableDrone) {
      INFO_MSG("Filterschritt");
  }
  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */
  //ExtU rtU;
  rtU.TWB_data[0] = dataTWB.posX;
  rtU.TWB_data[1] = dataTWB.posY;
  rtU.TWB_data[2] = dataTWB.posZ;

  // Set x_desired 
  rtU.x_desired[0] = 1;
  rtU.x_desired[1] = 1;
  rtU.x_desired[2] = 1;
  rtU.x_desired[3] = 0;
  /* Step the model for base rate */
  PoseEstimationController_step();
  /* Get model outputs here */
  output.u_z = rtY.u[0];
  output.u_psi = rtY.u[1];
  output.u_phi = rtY.u[2];
  output.u_theta = rtY.u[3];
  /* Get state estimation after KF step */
  INFO_MSG("Zustandsvorhersage für Drohne");
  INFO_MSG(rtY.x[0] << ", " << rtY.x[1] << ", " << rtY.x[2] << ", " << rtY.x[3] << ", " << rtY.x[4] << ", " << rtY.x[5] << ", " << rtY.x[6] << ", " << rtY.x[7] << ", " << rtY.x[8] << ", " << rtY.x[9] << ", " << rtY.x[10] << ", " << rtY.x[11]);
  INFO_MSG("Steueroutputs");
  INFO_MSG((int) output.u_z << ", " << (int) output.u_psi << ", " << (int) output.u_phi << ", " << (int) output.u_theta);
  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

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


/*class task: public rsc::threading::PeriodicTask {
public:

    task(const std::string interface, boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>>trackingQueue, int32_t markerId, const unsigned int& ms = 10) :
            rsc::threading::PeriodicTask(ms), trackingQueue(trackingQueue), markerId(markerId) {
        
    }

    virtual ~task() {
    }

    virtual void execute() {
        
          
            

    }

private:

    /*int fd;
    boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>> trackingQueue;
    int32_t markerId;
    char buffer[MAXBYTES];
    char buf_decode[55];
    uint8_t buf[5];
    sensorData_t decoded;
    int count_decode = 0;
    int count_msgs = 0;
    twbTracking::proto::ObjectList trackingPoseList;
    std::vector<twbTrackingProcess::TrackingObject> trackingObjectList;*/
    // bool dataTwbAvailable;

//};

int main(int argc, char **argv) {
  INFO_MSG("")
  //int fd;
    //boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>> trackingQueue;
    //int32_t markerId;
    //char buffer[MAXBYTES];
    //char buf_decode[55];
    //char buf;
    //sensorData_t decoded;
    //int count_decode = 0;
    //int count_msgs = 0;
    twbTracking::proto::ObjectList trackingPoseList;
    std::vector<twbTrackingProcess::TrackingObject> trackingObjectList;
  // Handle program options
  namespace po = boost::program_options;
  
  std::string rsbInScope = "/twb";
  std::string serialInterface = "/dev/ttyACM0";
  uint32_t rsbPeriod = 10;
  int32_t markerId = -1;

  po::options_description options("Allowed options");
  options.add_options()("help,h", "Display a help message.")
    ("inscope,o", po::value < std::string > (&rsbInScope), "Scope for receiving TWB messages")
    ("markerId,i", po::value < int32_t > (&markerId), "Marker ID attached to drone")
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

  // Register new converter
  twbTrackingProcess::registerTracking();  
  rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>::Ptr converterObject(new rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>);
  rsb::converter::converterRepository<std::string>()->registerConverter(converterObject);

  // Prepare RSB
  rsb::Factory& factory = rsb::getFactory();
  // TODO Revert if you realy want to work with the TWB
//  rsb::ListenerPtr trackingListener = factory.createListener(rsbInScope, twbTrackingProcess::getTrackingRSBConfig());
  rsb::ListenerPtr trackingListener = factory.createListener(rsbInScope);
  boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>>trackingQueue(new rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>(1));
  trackingListener->addHandler(rsb::HandlerPtr(new rsb::util::QueuePushHandler<twbTracking::proto::ObjectList>(trackingQueue)));

  // Init the CAN interface
//   ControllerAreaNetwork CAN;


  // TTY stuff initialization
  /*int fd = open(serialInterface.c_str(), O_RDWR | O_NONBLOCK);
  if (fd < 0) {
    ERROR_MSG("Error opening " << serialInterface << ": " << strerror(errno) << "\n");
    return -1;
  }
  char buf = '#';
  write(fd, &buf, 1);*/
  
  // Init KF
  PoseEstimationController_initialize();
  
  // Periodic task excecution
  rsc::threading::ThreadedTaskExecutor exec;
  //exec.schedule(rsc::threading::TaskPtr(new task(serialInterface, trackingQueue, markerId, rsbPeriod)));
  char buffer[MAXBYTES];
	char buf_decode[55];
	sensorData_t decoded;
	int count, count_decode, count_msgs;
        int fd = open("/dev/ttyACM0", O_RDWR);
	char buf = '#';
	uint8_t buff[5];
	write(fd, &buf, 1);
	count_decode = 0;
	count_msgs = 0;

   	/*gettimeofday(&t0, 0);
	FILE *fp;
	fp=fopen(argv[1], "w");
	fprintf(fp, "timestamp,accSmooth[0],accSmooth[1],accSmooth[2],gyroADC[0],gyroADC[1],gyroADC[2],baroAlt,baroTemp,magADC[0],magADC[1],magADC[2]\n");
*/
    while(1) {
		count = read(fd, buffer, MAXBYTES); //TODO: check when read finished
		for (int i = 0; i < count; i++) {
                        rtU.enableDrone = false;
			if (buffer[i] == '\n') {
				// decode data and put into struct
				decode_85(decoded.data, (uint8_t*) buf_decode, 55);

				printf("%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\n", decoded.values.accSmooth[0], decoded.values.accSmooth[1], decoded.values.accSmooth[2], decoded.values.gyroADC[0], decoded.values.gyroADC[1], decoded.values.gyroADC[2], decoded.values.baroAlt, decoded.values.baroTemp, decoded.values.magADC[0], decoded.values.magADC[1], decoded.values.magADC[2]);
                                
                                
                            // Decode data and put into struct
                            rtU.enableDrone = true;

                            //INFO_MSG("Sensorwerte Drohne!!!!!");
                            //INFO_MSG("AccX: " << decoded.values.accSmooth[0] << ", AccY: " << decoded.values.accSmooth[1] << ", AccZ: " << (int)decoded.values.accSmooth[2] << ", GyroX: " << decoded.values.gyroADC[0] << ", GyroY: " << decoded.values.gyroADC[1] << ", GyroZ: " << decoded.values.gyroADC[2] << ", BaroAlt: " << decoded.values.baroAlt << ", BaroTemp: " << decoded.values.baroTemp << ", MagX: " << decoded.values.magADC[0] << ", MagY: " << decoded.values.magADC[1] << ", MagZ: " << decoded.values.magADC[2] << "\n");
                            // Set decoded data from FC sensors
                            rtU.drone_raw_data[0] = (int)decoded.values.gyroADC[0];
                            rtU.drone_raw_data[1] = (int)decoded.values.gyroADC[1];
                            rtU.drone_raw_data[2] = (int)decoded.values.gyroADC[2];
                            rtU.drone_raw_data[3] = (int)decoded.values.accSmooth[0];
                            rtU.drone_raw_data[4] = (int)decoded.values.accSmooth[1];
                            rtU.drone_raw_data[5] = (int)decoded.values.accSmooth[2];
                            rtU.drone_raw_data[6] = (int)decoded.values.magADC[0];
                            rtU.drone_raw_data[7] = (int)decoded.values.magADC[1];
                            rtU.drone_raw_data[8] = (int)decoded.values.magADC[2];
                            rtU.drone_raw_data[9] = (int)decoded.values.baroAlt;
                            rtU.drone_raw_data[10] = (int)decoded.values.baroTemp;
                            // Check for TWB data
                            // TODO Add non blocking request for TWB data
                            trackingObjectList = twbTrackingProcess::getNextTrackingObjects(trackingQueue, -1);
                            // überprüfen ob liste leer, dann nur mit FC Daten ausführen
                            rtU.enableTWB = false;
                            if (trackingObjectList.size() != 0) {
                                if (trackingObjectList.at(0).id >= 0) {
                                    for (int idx = 0; idx < trackingObjectList.size(); idx++) {
                                        if ( trackingObjectList.at(idx).id == markerId) {
                                            // TODO Do something with the coordinates
                                            // dataTwbAvailable = true;
                                            rtU.enableTWB = true;
                                            dataTWB.posX = trackingObjectList.at(idx).pos.x;
                                            dataTWB.posY = trackingObjectList.at(idx).pos.y;
                                            dataTWB.posZ = trackingObjectList.at(idx).pos.z;
                                            //  trackingObjectList.at(idx).pos.theta;
                                        }
                                    }
                                }
                            }
    

                            // TODO Include KF
                            
                            /*for (int i = 0; i < 10; i++) {
                                if (abs(rtU.drone_raw_data[i]) > 32000) {
                                    rtU.enableDrone = false;
                                    INFO_MSG("Fehlerhafte Sensorwerte!!!");
                                    break;
                                }
                            }
                            tcflush(fd,TCIOFLUSH);
                            usleep(1000);*/
                            rt_OneStep();
                            // TODO Process the controller and send the commands to the FC
                            // 0: ROLL, 1: PITCH, 2: YAW, 3: THROTTLE
                            //tcflush(fd,TCIOFLUSH);
                            //usleep(1000);
                            {
                            uint8_t inbuf[4] = {0,0,*((uint8_t*)&output.u_z + 1),*((uint8_t*)&output.u_z + 0)}; // 1 byte: ROLL command, 2 byte: 0 = "empty byte" to have 4 bytes for encoding with base85, 3, 4 bytes: value (3: high byte, 4: low byte)
                            encode_85(buff, inbuf, 4);                
                            write(fd, buff, 4);
                            }
                            {
                            uint8_t inbuf[4] = {1,0,0xD4,0xC2};//{1,0,*((uint8_t*)&output.u_psi + 1),*((uint8_t*)&output.u_psi + 0)};
                            encode_85(buff, inbuf, 4);                
                            write(fd, buff, 4);
                            }
                            {
                            uint8_t inbuf[4] = {2,0,0xD4,0xC2};//{2,0,*((uint8_t*)&output.u_phi + 1),*((uint8_t*)&output.u_phi + 0)};
                            encode_85(buff, inbuf, 4);                
                            write(fd, buff, 4);
                            }
                            {
                            //uint8_t inbuf[4] = {3,0,*((uint8_t*)&output.u_theta + 1),*((uint8_t*)&output.u_theta + 0)};
                            uint8_t inbuf[4] = {3,0,0xD4,0xC2};
                            encode_85(buff, inbuf, 4);                
                            write(fd, buff, 4);
                            }
                            //usleep(1000);
                            //tcflush(fd,TCIOFLUSH);
				count_decode = 0;
				count_msgs++;
			} else {
				buf_decode[count_decode] = buffer[i];
				count_decode++;
			}
		}
	}


  // Wait until finish
  rsc::misc::initSignalWaiter();
  return rsc::misc::suggestedExitCode(rsc::misc::waitForSignal());
}
>>>>>>> 50afed968f1899b516d169a606c19cf0ffd99ce0
