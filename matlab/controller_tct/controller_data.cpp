/*
 * controller_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller".
 *
 * Model version              : 1.2877
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C++ source code generated on : Mon Jun 22 12:41:17 2020
 *
 * Target selection: TwinCAT.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "controller.h"
#include "controller_private.h"

/* Block parameters (auto storage) */
P_controller_T controller_P = {
  /* Variable: filter_tau_T_1
   * Referenced by: '<S6>/f_tau'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_tau_p_T_1
   * Referenced by: '<S6>/f_tau_p'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_tau_p_slow_T_1
   * Referenced by: '<S6>/f_tau_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_tau_slow_T_1
   * Referenced by: '<S6>/f_tau_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_p_T_1
   * Referenced by: '<S6>/f_theta_p'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_theta_p_slow_T_1
   * Referenced by: '<S6>/f_theta_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_slow_T_1
   * Referenced by: '<S6>/f_theta_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: sensor_torque_offset
   * Referenced by: '<S6>/Constant'
   */
  { 0.53, -0.095, -0.189, 0.07, -0.058, 0.0025, -0.12 },

  /* Computed Parameter: tau_fm_hat_Y0
   * Referenced by: '<S2>/tau_fm_hat'
   */
  0.0,

  /* Expression: [200;200;300;300;500;1000;1000]
   * Referenced by: '<S2>/L'
   */
  { 200.0, 200.0, 300.0, 300.0, 500.0, 1000.0, 1000.0 },

  /* Expression: [zeros(6,1);0.2]
   * Referenced by: '<S2>/tau_c_plus'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  /* Expression: [zeros(6,1);0.28]
   * Referenced by: '<S2>/tau_c_minus'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.28 },

  /* Expression: [zeros(6,1);120]
   * Referenced by: '<S2>/E'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 120.0 },

  /* Expression: [zeros(6,1);0.5]
   * Referenced by: '<S2>/tau_v'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5 },

  /* Expression: 0
   * Referenced by: '<S2>/use_theta_p_hat'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/use_q_p'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/subtract_model'
   */
  0.0,

  /* Expression: zeros(param_robot.n,1)
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: tau_d_gravcomp_q_Y0
   * Referenced by: '<S12>/tau_d_gravcomp_q'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S12>/Gravitation compensation K_D'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S12>/slope_factor'
   */
  1.0,

  /* Computed Parameter: tau_d_joint_ea_Y0
   * Referenced by: '<S13>/tau_d_joint_ea'
   */
  0.0,

  /* Expression: 8000
   * Referenced by: '<S13>/Joint-based E//A Linearization K_I'
   */
  8000.0,

  /* Expression: 1200
   * Referenced by: '<S13>/Joint-based E//A Linearization K_0'
   */
  1200.0,

  /* Expression: 60
   * Referenced by: '<S13>/Joint-based E//A Linearization K_1'
   */
  60.0,

  /* Expression: zeros(param_robot.n,1)
   * Referenced by: '<S8>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant16'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant15'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant14'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant13'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<Root>/Constant12'
   */
  90.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant17'
   */
  0.0,

  /* Expression: 15
   * Referenced by: '<S8>/T'
   */
  15.0,

  /* Expression: zeros(7,1)
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/FictionCompensationEnabled'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/MotionEnableValue'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/MotionDisableValue'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant22'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant7'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant9'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant10'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant23'
   */
  1.0,

  /* Computed Parameter: RigidBodyControllerSelector_Value
   * Referenced by: '<Root>/Rigid Body Controller Selector'
   */
  1U,

  /* Computed Parameter: JointTargetPositionSelector_Value
   * Referenced by: '<Root>/Joint Target Position Selector'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S2>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<S2>/Manual Switch4'
   */
  0U
};
