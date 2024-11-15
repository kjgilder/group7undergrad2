#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ros_controller2";

// For Block ros_controller2/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Sub_ros_controller2_55;

// For Block ros_controller2/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Sub_ros_controller2_57;

// For Block ros_controller2/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Pub_ros_controller2_60;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

