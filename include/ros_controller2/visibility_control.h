#ifndef ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
#define ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_CONTROLLER2_EXPORT __attribute__ ((dllexport))
    #define ROS_CONTROLLER2_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_CONTROLLER2_EXPORT __declspec(dllexport)
    #define ROS_CONTROLLER2_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_CONTROLLER2_BUILDING_LIBRARY
    #define ROS_CONTROLLER2_PUBLIC ROS_CONTROLLER2_EXPORT
  #else
    #define ROS_CONTROLLER2_PUBLIC ROS_CONTROLLER2_IMPORT
  #endif
  #define ROS_CONTROLLER2_PUBLIC_TYPE ROS_CONTROLLER2_PUBLIC
  #define ROS_CONTROLLER2_LOCAL
#else
  #define ROS_CONTROLLER2_EXPORT __attribute__ ((visibility("default")))
  #define ROS_CONTROLLER2_IMPORT
  #if __GNUC__ >= 4
    #define ROS_CONTROLLER2_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_CONTROLLER2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_CONTROLLER2_PUBLIC
    #define ROS_CONTROLLER2_LOCAL
  #endif
  #define ROS_CONTROLLER2_PUBLIC_TYPE
#endif
#endif  // ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
// Generated 15-Nov-2024 14:17:13
// Copyright 2019-2020 The MathWorks, Inc.
