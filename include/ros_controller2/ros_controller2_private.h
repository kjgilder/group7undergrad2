/*
 * ros_controller2_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ros_controller2".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Nov 15 14:17:06 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ros_controller2_private_h_
#define ros_controller2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ros_controller2.h"
#include "ros_controller2_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void ros_contr_EnabledSubsystem_Init(B_EnabledSubsystem_ros_contro_T
  *localB, P_EnabledSubsystem_ros_contro_T *localP);
extern void ros_controller_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_ros_controller2_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_ros_contro_T *localB);

/* private model entry point functions */
extern void ros_controller2_derivatives(void);

#endif                                 /* ros_controller2_private_h_ */
