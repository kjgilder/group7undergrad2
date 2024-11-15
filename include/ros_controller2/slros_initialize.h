#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ros_controller2_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ros_controller2/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Sub_ros_controller2_55;

// For Block ros_controller2/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Sub_ros_controller2_57;

// For Block ros_controller2/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ros_controller2_std_msgs_Float64> Pub_ros_controller2_60;

void slros_node_init(int argc, char** argv);

#endif
