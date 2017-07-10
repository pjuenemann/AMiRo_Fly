#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf_conversions/tf_eigen.h>

#include <rsb/Factory.h>
#include <rsb/Version.h>
#include <rsb/Event.h>
#include <rsb/Handler.h>
#include <rsb/converter/Repository.h>
#include <rsb/converter/ProtocolBufferConverter.h>
#include "enum.pb.h"
#include "loc.pb.h"
#include "pose.pb.h"
#include "rotation.pb.h"
#include "shapes.pb.h"
#include "vertex.pb.h"
#include "TwbTracking.h"

#include <string>

#include <rsc/threading/SynchronizedQueue.h>
#include <rsb/util/QueuePushHandler.h>

// RST Proto types
#include <rst/geometry/Pose.pb.h>
#include <rst/geometry/Translation.pb.h>
#include <rst/geometry/Rotation.pb.h>

using namespace rsb;
using namespace rsb::converter;

tf::Transform getTfFromTrackingObject(twbTrackingProcess::TrackingObject &object) {
  std::cerr << "(x, y, theta): " << "( " << object.pos.x << ", " << object.pos.y << ", " << object.pos.theta << " )" <<  std::endl;
  tf::Transform transform;
  tf::Quaternion q;
  tf::Vector3 translation;
  translation.setZero();
  translation.setX(object.pos.x);
  translation.setY(object.pos.y);
  q.setRPY(0.0,0.0,2 * M_PI - object.pos.theta);
  transform.setOrigin(translation);
  transform.setRotation(q);
  return transform;
}

 /**
 * This programm publishes a tf for every the last received pose
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_to_tf_bridge");
  ros::NodeHandle n("~");

  // ROS STUFF
  std::string parentFrame;
  std::string childFramePrefix, childFrameSuffix;
  std::string rsbScope;
  int rateArg;

  n.param<std::string>("frame_id", parentFrame, "world");
  n.param<std::string>("child_frame_prefix", childFramePrefix, "");
  n.param<std::string>("child_frame_suffix", childFrameSuffix, "");
  n.param<std::string>("rsb_scope", rsbScope, twbTrackingProcess::getTrackingScope());
  n.param<int>("rate", rateArg, 1);

  tf::TransformBroadcaster br;
  ros::Rate rate(rateArg);

  // RSB STUFF
  // Get the RSB factory
  rsb::Factory& factory = rsb::getFactory();

  // Register converters
  twbTrackingProcess::registerTracking();

  rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>::Ptr converterObject(new rsb::converter::ProtocolBufferConverter<twbTracking::proto::Object>);
  rsb::converter::converterRepository<std::string>()->registerConverter(converterObject);

  // prepare rsb listener for tracking data
  rsb::ListenerPtr trackingListener = factory.createListener(rsbScope, twbTrackingProcess::getTrackingRSBConfig());
  boost::shared_ptr<rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>>trackingQueue(new rsc::threading::SynchronizedQueue<boost::shared_ptr<twbTracking::proto::ObjectList>>(1));
  trackingListener->addHandler(rsb::HandlerPtr(new rsb::util::QueuePushHandler<twbTracking::proto::ObjectList>(trackingQueue)));


  twbTracking::proto::ObjectList trackingPoseList;
  std::vector<twbTrackingProcess::TrackingObject> trackingObjectList;

  // PROCESS THE POSE
  while (ros::ok()) {

    trackingObjectList = twbTrackingProcess::getNextTrackingObjects(trackingQueue);
    if (trackingObjectList.size() != 0) {
      if (trackingObjectList.at(0).id >= 0) {
        for (int idx = 0; idx < trackingObjectList.size(); idx++) {
          std::cerr << "ID: " << trackingObjectList.at(idx).id << " - "; 
          br.sendTransform(tf::StampedTransform( getTfFromTrackingObject(trackingObjectList.at(idx)),
                                                 ros::Time::now(),
                                                 parentFrame,
                                                 childFramePrefix + std::to_string(trackingObjectList.at(idx).id) + childFrameSuffix));
        }
      }
    }
    std::cerr << "----- " << std::endl;
    rate.sleep();
  }

  return 0;
}
