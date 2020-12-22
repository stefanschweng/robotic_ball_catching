/*
 * controller_ballcatcher_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_ballcatcher".
 *
 * Model version              : 1.3592
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct 13 22:18:08 2020
 *
 * Target selection: TwinCAT.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "controller_ballcatcher.h"
#include "controller_ballcatcher_private.h"

/* Block parameters (default storage) */
P_controller_ballcatcher_T controller_ballcatcher_P = {
  /* Variable: param_robot
   * Referenced by: '<Root>/Trajectory Generator'
   */
  {
    0,

    { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

    { 0.0, 0.0, 0.0 },
    7.0,
    9.81,
    0.0,
    0.1525,
    0.2075,
    0.2325,
    0.1875,
    0.2125,
    0.1875,
    0.0796,
    0.0724,
    0.013,
    0.011,
    0.062,
    6.495,
    8.807,
    2.8,
    5.283,
    1.889,
    2.32,
    0.863,
    0.0,
    -0.01439,
    0.102503,
    -1.2e-5,
    -0.06472,
    0.017804,
    -0.000208,
    0.01601,
    0.087283,
    -0.000203,
    0.098639,
    0.022478,
    -5.7e-5,
    -0.014468,
    0.062938,
    -0.000363,
    -0.016982,
    0.042269,
    0.0019040000000000003,
    -9.3e-5,
    0.018862000000000004,
    0.0690761441316632,
    0.0711085586914514,
    0.0200625854402119,
    0.0824701683534692,
    0.0164110968055191,
    0.0873510892661361,
    0.0230152941318817,
    0.0228661554143474,
    0.0554482283748983,
    0.0472789668341968,
    0.00964726804146909,
    0.0466529007761679,
    0.0138359953358589,
    0.0116859337751969,
    0.00571863785412578,
    0.00732758787216765,
    0.00477633755783711,
    0.00606797638550296,
    0.000884,
    0.000888,
    0.001105,
    160.0,
    160.0,
    160.0,
    160.0,
    100.0,
    160.0,
    160.0,

    { 160.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 160.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 160.0 },
    0.000185,
    0.000185,
    0.00042316695312500003,
    0.000185,
    0.000185,
    0.00042316695312500003,
    0.000129,
    0.000129,
    0.0001910384375,
    0.000129,
    0.000129,
    0.0001910384375,
    7.5e-5,
    7.5e-5,
    0.0001470968,
    1.5e-5,
    1.5e-5,
    1.851125e-5,
    1.5e-5,
    1.5e-5,
    1.851125e-5,

    { 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.833074000000002,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.4709679999999998, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.473888, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.473888 },
    60000.0,
    60000.0,
    40000.0,
    40000.0,
    40000.0,
    20000.0,
    20000.0,

    { 60000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 60000.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      20000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20000.0 },

    { 320.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 320.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 176.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 176.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 110.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40.0 },

    { 160.0, 160.0, 88.0, 88.0, 55.0, 20.0, 20.0 },

    { 2.9670597283903604, 2.0943951023931953, 2.9670597283903604,
      2.0943951023931953, 2.9670597283903604, 2.0943951023931953,
      3.0543261909900763 },

    { -2.9670597283903604, -2.0943951023931953, -2.9670597283903604,
      -2.0943951023931953, -2.9670597283903604, -2.0943951023931953,
      -3.0543261909900763 },

    { 1.4835298641951802, 1.4835298641951802, 1.7453292519943295,
      1.3089969389957472, 2.2689280275926285, 2.3561944901923448,
      2.3561944901923448 },

    { -1.4835298641951802, -1.4835298641951802, -1.7453292519943295,
      -1.3089969389957472, -2.2689280275926285, -2.3561944901923448,
      -2.3561944901923448 }
  },

  /* Variable: timing
   * Referenced by: '<Root>/Trajectory Generator'
   */
  {
    0.004,
    0.000125,
    5.0e-5,
    80.0
  },

  /* Variable: filter_tau_T_1
   * Referenced by: '<S5>/f_tau'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_tau_p_T_1
   * Referenced by: '<S5>/f_tau_p'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_tau_p_slow_T_1
   * Referenced by: '<S5>/f_tau_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_tau_slow_T_1
   * Referenced by: '<S5>/f_tau_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_p_T_1
   * Referenced by: '<S5>/f_theta_p'
   */
  { 0.00039788735772973834, 0.00039788735772973834, 0.00039788735772973834,
    0.00039788735772973834, 0.0003183098861837907, 0.00015915494309189535,
    0.00015915494309189535 },

  /* Variable: filter_theta_p_slow_T_1
   * Referenced by: '<S5>/f_theta_p_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: filter_theta_slow_T_1
   * Referenced by: '<S5>/f_theta_slow'
   */
  { 0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667, 0.00079577471545947667, 0.00079577471545947667,
    0.00079577471545947667 },

  /* Variable: sensor_torque_offset
   * Referenced by: '<S5>/Constant'
   */
  { 0.53, -0.095, -0.189, 0.07, -0.058, 0.0025, -0.12 },

  /* Computed Parameter: tau_fm_hat_Y0
   * Referenced by: '<S1>/tau_fm_hat'
   */
  0.0,

  /* Expression: [200;200;300;300;500;1000;1000]
   * Referenced by: '<S1>/L'
   */
  { 200.0, 200.0, 300.0, 300.0, 500.0, 1000.0, 1000.0 },

  /* Expression: 0
   * Referenced by: '<S1>/use_theta_p_hat'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/use_q_p'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/subtract_model'
   */
  0.0,

  /* Expression: [zeros(6,1);0.2]
   * Referenced by: '<S1>/tau_c_plus'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  /* Expression: [zeros(6,1);0.28]
   * Referenced by: '<S1>/tau_c_minus'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.28 },

  /* Expression: [zeros(6,1);120]
   * Referenced by: '<S1>/E'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 120.0 },

  /* Expression: [zeros(6,1);0.5]
   * Referenced by: '<S1>/tau_v'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5 },

  /* Expression: zeros(param_robot.n,1)
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: tau_d_gravcomp_q_Y0
   * Referenced by: '<S11>/tau_d_gravcomp_q'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S11>/Gravitation compensation K_D'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S11>/slope_factor'
   */
  1.0,

  /* Computed Parameter: tau_d_joint_ea_Y0
   * Referenced by: '<S12>/tau_d_joint_ea'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Joint-based E//A Linearization K_I'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S12>/Joint-based E//A Linearization K_0'
   */
  100.0,

  /* Expression: 20
   * Referenced by: '<S12>/Joint-based E//A Linearization K_1'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 50e-3
   * Referenced by: '<Root>/Constant'
   */
  0.05,

  /* Expression: zeros(7,1)
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/FictionCompensationEnabled'
   */
  1.0,

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

  /* Computed Parameter: UnitDelay1_InitialCondition
   * Referenced by: '<Root>/Unit Delay1'
   */
  0,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S1>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<S1>/Manual Switch4'
   */
  0U
};
