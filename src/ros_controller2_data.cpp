/*
 * ros_controller2_data.cpp
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

/* Block parameters (default storage) */
P_ros_controller2_T ros_controller2_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S4>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S5>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 500
   * Referenced by: '<Root>/initial_space_to_int'
   */
  500.0,

  /* Start of '<S5>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S7>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S5>/Enabled Subsystem' */

  /* Start of '<S4>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S6>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  /* End of '<S4>/Enabled Subsystem' */
};
