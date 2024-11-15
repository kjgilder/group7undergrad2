/*
 * ros_controller2.cpp
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

#include "ros_controller2.h"
#include "rtwtypes.h"
#include "ros_controller2_types.h"
#include "ros_controller2_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>

/* Block signals (default storage) */
B_ros_controller2_T ros_controller2_B;

/* Continuous states */
X_ros_controller2_T ros_controller2_X;

/* Disabled State Vector */
XDis_ros_controller2_T ros_controller2_XDis;

/* Block states (default storage) */
DW_ros_controller2_T ros_controller2_DW;

/* Real-time model */
RT_MODEL_ros_controller2_T ros_controller2_M_ = RT_MODEL_ros_controller2_T();
RT_MODEL_ros_controller2_T *const ros_controller2_M = &ros_controller2_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ros_controller2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ros_controller2_step();
  ros_controller2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ros_controller2_step();
  ros_controller2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 */
void ros_contr_EnabledSubsystem_Init(B_EnabledSubsystem_ros_contro_T *localB,
  P_EnabledSubsystem_ros_contro_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
   *  Outport: '<S6>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 */
void ros_controller_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_ros_controller2_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_ros_contro_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S6>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model step function */
void ros_controller2_step(void)
{
  /* local block i/o variables */
  SL_Bus_ros_controller2_std_msgs_Float64 rtb_SourceBlock_o2;
  SL_Bus_ros_controller2_std_msgs_Float64 rtb_SourceBlock_o2_p;
  boolean_T rtb_SourceBlock_o1;
  boolean_T rtb_SourceBlock_o1_e;
  SL_Bus_ros_controller2_std_msgs_Float64 rtb_BusAssignment;
  real_T distance_to_intersection;
  real_T rtb_Clock;
  real_T vel_ego;
  if (rtmIsMajorTimeStep(ros_controller2_M)) {
    /* set solver stop time */
    if (!(ros_controller2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ros_controller2_M->solverInfo,
                            ((ros_controller2_M->Timing.clockTickH0 + 1) *
        ros_controller2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ros_controller2_M->solverInfo,
                            ((ros_controller2_M->Timing.clockTick0 + 1) *
        ros_controller2_M->Timing.stepSize0 +
        ros_controller2_M->Timing.clockTickH0 *
        ros_controller2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ros_controller2_M)) {
    ros_controller2_M->Timing.t[0] = rtsiGetT(&ros_controller2_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = ros_controller2_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ros_controller2_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S4>/SourceBlock' */
    rtb_SourceBlock_o1_e = Sub_ros_controller2_55.getLatestMessage
      (&rtb_SourceBlock_o2_p);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
    ros_controller_EnabledSubsystem(rtb_SourceBlock_o1_e, &rtb_SourceBlock_o2_p,
      &ros_controller2_B.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
    /* MATLABSystem: '<S5>/SourceBlock' */
    rtb_SourceBlock_o1 = Sub_ros_controller2_57.getLatestMessage
      (&rtb_SourceBlock_o2);

    /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
    ros_controller_EnabledSubsystem(rtb_SourceBlock_o1, &rtb_SourceBlock_o2,
      &ros_controller2_B.EnabledSubsystem_m);

    /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe2' */
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/initial_space_to_int'
   *  Integrator: '<Root>/Integrator'
   */
  vel_ego = ros_controller2_B.EnabledSubsystem.In1.Data;
  if (ros_controller2_B.EnabledSubsystem_m.In1.Data < 0.0) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = 0.0;
  } else {
    if ((ros_controller2_B.EnabledSubsystem.In1.Data > -0.01) &&
        (ros_controller2_B.EnabledSubsystem.In1.Data < 0.01)) {
      vel_ego = 0.01;
    }

    distance_to_intersection = ros_controller2_P.initial_space_to_int_Value -
      ros_controller2_X.Integrator_CSTATE;
    if ((36.0 - rtb_Clock < 1.0) && (36.0 - rtb_Clock > 0.0)) {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = 15.0 - vel_ego;
    } else if ((distance_to_intersection < 100.0) && (distance_to_intersection >
                0.0)) {
      rtb_Clock = (distance_to_intersection - (36.0 - rtb_Clock) * vel_ego) *
        2.0 / ((36.0 - rtb_Clock) * (36.0 - rtb_Clock));
      if ((15.0 - vel_ego <= rtb_Clock) || rtIsNaN(rtb_Clock)) {
        /* BusAssignment: '<Root>/Bus Assignment' */
        rtb_BusAssignment.Data = 15.0 - vel_ego;
      } else {
        /* BusAssignment: '<Root>/Bus Assignment' */
        rtb_BusAssignment.Data = rtb_Clock;
      }
    } else {
      /* BusAssignment: '<Root>/Bus Assignment' */
      rtb_BusAssignment.Data = 15.0 - vel_ego;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_ros_controller2_60.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(ros_controller2_M)) {
    rt_ertODEUpdateContinuousStates(&ros_controller2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ros_controller2_M->Timing.clockTick0)) {
      ++ros_controller2_M->Timing.clockTickH0;
    }

    ros_controller2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ros_controller2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      ros_controller2_M->Timing.clockTick1++;
      if (!ros_controller2_M->Timing.clockTick1) {
        ros_controller2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ros_controller2_derivatives(void)
{
  XDot_ros_controller2_T *_rtXdot;
  _rtXdot = ((XDot_ros_controller2_T *) ros_controller2_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = ros_controller2_B.EnabledSubsystem.In1.Data;
}

/* Model initialize function */
void ros_controller2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ros_controller2_M->solverInfo,
                          &ros_controller2_M->Timing.simTimeStep);
    rtsiSetTPtr(&ros_controller2_M->solverInfo, &rtmGetTPtr(ros_controller2_M));
    rtsiSetStepSizePtr(&ros_controller2_M->solverInfo,
                       &ros_controller2_M->Timing.stepSize0);
    rtsiSetdXPtr(&ros_controller2_M->solverInfo, &ros_controller2_M->derivs);
    rtsiSetContStatesPtr(&ros_controller2_M->solverInfo, (real_T **)
                         &ros_controller2_M->contStates);
    rtsiSetNumContStatesPtr(&ros_controller2_M->solverInfo,
      &ros_controller2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ros_controller2_M->solverInfo,
      &ros_controller2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ros_controller2_M->solverInfo,
      &ros_controller2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ros_controller2_M->solverInfo,
      &ros_controller2_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ros_controller2_M->solverInfo, (boolean_T**)
      &ros_controller2_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ros_controller2_M->solverInfo, (&rtmGetErrorStatus
      (ros_controller2_M)));
    rtsiSetRTModelPtr(&ros_controller2_M->solverInfo, ros_controller2_M);
  }

  rtsiSetSimTimeStep(&ros_controller2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ros_controller2_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ros_controller2_M->solverInfo, false);
  ros_controller2_M->intgData.y = ros_controller2_M->odeY;
  ros_controller2_M->intgData.f[0] = ros_controller2_M->odeF[0];
  ros_controller2_M->intgData.f[1] = ros_controller2_M->odeF[1];
  ros_controller2_M->intgData.f[2] = ros_controller2_M->odeF[2];
  ros_controller2_M->contStates = ((X_ros_controller2_T *) &ros_controller2_X);
  ros_controller2_M->contStateDisabled = ((XDis_ros_controller2_T *)
    &ros_controller2_XDis);
  ros_controller2_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ros_controller2_M->solverInfo, static_cast<void *>
                    (&ros_controller2_M->intgData));
  rtsiSetSolverName(&ros_controller2_M->solverInfo,"ode3");
  rtmSetTPtr(ros_controller2_M, &ros_controller2_M->Timing.tArray[0]);
  ros_controller2_M->Timing.stepSize0 = 2.0;

  /* block I/O */
  (void) memset((static_cast<void *>(&ros_controller2_B)), 0,
                sizeof(B_ros_controller2_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&ros_controller2_X), 0,
                  sizeof(X_ros_controller2_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&ros_controller2_XDis), 0,
                  sizeof(XDis_ros_controller2_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&ros_controller2_DW), 0,
                sizeof(DW_ros_controller2_T));

  {
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[11];
    static const char_T b_zeroDelimTopic_1[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_2[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_3[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    ros_controller2_DW.obj_n.matlabCodegenIsDeleted = false;
    ros_controller2_DW.objisempty_l = true;
    ros_controller2_DW.obj_n.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_ros_controller2_55.createSubscriber(&b_zeroDelimTopic[0], 1);
    ros_controller2_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    ros_controller2_DW.obj_f.matlabCodegenIsDeleted = false;
    ros_controller2_DW.objisempty = true;
    ros_controller2_DW.obj_f.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Sub_ros_controller2_57.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ros_controller2_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    ros_controller2_DW.obj.matlabCodegenIsDeleted = false;
    ros_controller2_DW.objisempty_h = true;
    ros_controller2_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Pub_ros_controller2_60.createPublisher(&b_zeroDelimTopic_0[0], 1);
    ros_controller2_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  ros_controller2_X.Integrator_CSTATE = ros_controller2_P.Integrator_IC;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  ros_contr_EnabledSubsystem_Init(&ros_controller2_B.EnabledSubsystem,
    &ros_controller2_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  ros_contr_EnabledSubsystem_Init(&ros_controller2_B.EnabledSubsystem_m,
    &ros_controller2_P.EnabledSubsystem_m);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */
}

/* Model terminate function */
void ros_controller2_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!ros_controller2_DW.obj_n.matlabCodegenIsDeleted) {
    ros_controller2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!ros_controller2_DW.obj_f.matlabCodegenIsDeleted) {
    ros_controller2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!ros_controller2_DW.obj.matlabCodegenIsDeleted) {
    ros_controller2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
