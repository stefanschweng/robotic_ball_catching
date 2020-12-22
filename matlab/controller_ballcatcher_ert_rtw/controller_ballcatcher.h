//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_ballcatcher.h
//
// Code generated for Simulink model 'controller_ballcatcher'.
//
// Model version                  : 1.2934
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Aug 10 09:08:57 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_ballcatcher_h_
#define RTW_HEADER_controller_ballcatcher_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <cmath>
#include <math.h>
#include <string.h>
#ifndef controller_ballcatcher_COMMON_INCLUDES_
# define controller_ballcatcher_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#endif                                 // controller_ballcatcher_COMMON_INCLUDES_ 

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// user code (top of header file)
#define fflush(stdout)
#define printf(...)                    m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG,__VA_ARGS__)
#ifndef DEFINED_TYPEDEF_FOR_Marker_
#define DEFINED_TYPEDEF_FOR_Marker_

typedef struct {
  int16_T MarkerID;
  int16_T ModelID;
  real_T x;
  real_T y;
  real_T z;
  real_T markerSize;
  real_T bOccluded;
  real_T bPCSolved;
  real_T bModelSolved;
  real_T residualError;
} Marker;

#endif

#ifndef DEFINED_TYPEDEF_FOR_robot_model_
#define DEFINED_TYPEDEF_FOR_robot_model_

typedef struct {
  real_T q[7];
  real_T q_p[7];
  real_T H[16];
  real_T J[42];
  real_T J_p[42];
  real_T M[49];
  real_T C[49];
  real_T g[7];
} robot_model;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_PcUEPt9FJnxk90L3HMZRgE_
#define DEFINED_TYPEDEF_FOR_struct_PcUEPt9FJnxk90L3HMZRgE_

typedef struct {
  real_T candle[3];
  real_T start[3];
  real_T hand_over[3];
  real_T candle_p[3];
  real_T start_p[3];
  real_T hand_over_p[3];
  real_T T_candle[16];
} struct_PcUEPt9FJnxk90L3HMZRgE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_drdASX3xMwFWgTYNtyjTdF_
#define DEFINED_TYPEDEF_FOR_struct_drdASX3xMwFWgTYNtyjTdF_

typedef struct {
  real_T alpha0;
  real_T px_est_last[2];
  real_T Px_last[4];
  real_T py_est_last[2];
  real_T Py_last[4];
  real_T pz_est_last[2];
  real_T Pz_last[4];
  real_T q;
  real_T t_move_start;
  real_T seed1;
  real_T seed2;
  real_T seed3;
} struct_drdASX3xMwFWgTYNtyjTdF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_bnj9PLm1Rht6xDHAOlfP8G_
#define DEFINED_TYPEDEF_FOR_struct_bnj9PLm1Rht6xDHAOlfP8G_

typedef struct {
  boolean_T hanging;
  real_T R_0[9];
  real_T p_0[3];
  real_T n;
  real_T g;
  real_T beta;
  real_T l__0;
  real_T l__1;
  real_T l__2;
  real_T l__3;
  real_T l__4;
  real_T l__5;
  real_T l__6;
  real_T l__7;
  real_T d__1;
  real_T d__3;
  real_T d__5;
  real_T m__l1;
  real_T m__l2;
  real_T m__l3;
  real_T m__l4;
  real_T m__l5;
  real_T m__l6;
  real_T m__l7;
  real_T s__l1x;
  real_T s__l1y;
  real_T s__l1z;
  real_T s__l2x;
  real_T s__l2y;
  real_T s__l2z;
  real_T s__l3x;
  real_T s__l3y;
  real_T s__l3z;
  real_T s__l4x;
  real_T s__l4y;
  real_T s__l4z;
  real_T s__l5x;
  real_T s__l5y;
  real_T s__l5z;
  real_T s__l6x;
  real_T s__l6y;
  real_T s__l6z;
  real_T s__l7x;
  real_T s__l7y;
  real_T s__l7z;
  real_T I__l1xx;
  real_T I__l1yy;
  real_T I__l1zz;
  real_T I__l2xx;
  real_T I__l2yy;
  real_T I__l2zz;
  real_T I__l3xx;
  real_T I__l3yy;
  real_T I__l3zz;
  real_T I__l4xx;
  real_T I__l4yy;
  real_T I__l4zz;
  real_T I__l5xx;
  real_T I__l5yy;
  real_T I__l5zz;
  real_T I__l6xx;
  real_T I__l6yy;
  real_T I__l6zz;
  real_T I__l7xx;
  real_T I__l7yy;
  real_T I__l7zz;
  real_T n__1;
  real_T n__2;
  real_T n__3;
  real_T n__4;
  real_T n__5;
  real_T n__6;
  real_T n__7;
  real_T N[49];
  real_T I__r1xx;
  real_T I__r1yy;
  real_T I__r1zz;
  real_T I__r2xx;
  real_T I__r2yy;
  real_T I__r2zz;
  real_T I__r3xx;
  real_T I__r3yy;
  real_T I__r3zz;
  real_T I__r4xx;
  real_T I__r4yy;
  real_T I__r4zz;
  real_T I__r5xx;
  real_T I__r5yy;
  real_T I__r5zz;
  real_T I__r6xx;
  real_T I__r6yy;
  real_T I__r6zz;
  real_T I__r7xx;
  real_T I__r7yy;
  real_T I__r7zz;
  real_T B[49];
  real_T K__1;
  real_T K__2;
  real_T K__3;
  real_T K__4;
  real_T K__5;
  real_T K__6;
  real_T K__7;
  real_T K[49];
  real_T tau_max[49];
  real_T q_limit_upper[7];
  real_T q_limit_lower[7];
} struct_bnj9PLm1Rht6xDHAOlfP8G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_H3kGAq3Wz3sWw17UGJeD0B_
#define DEFINED_TYPEDEF_FOR_struct_H3kGAq3Wz3sWw17UGJeD0B_

typedef struct {
  real_T x[111];
  real_T y[111];
  real_T z[111];
} struct_H3kGAq3Wz3sWw17UGJeD0B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_LmDCZkCYQjsHLaJv8qLWFF_
#define DEFINED_TYPEDEF_FOR_struct_LmDCZkCYQjsHLaJv8qLWFF_

typedef struct {
  real_T x0;
  real_T y0;
  real_T z0;
  real_T vx0;
  real_T vy0;
  real_T vz0;
  struct_H3kGAq3Wz3sWw17UGJeD0B optitrack;
} struct_LmDCZkCYQjsHLaJv8qLWFF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_6KsaStIdjpBuRBst70TZDB_
#define DEFINED_TYPEDEF_FOR_struct_6KsaStIdjpBuRBst70TZDB_

typedef struct {
  real_T q_limit_upper[8];
  real_T q_limit_lower[8];
  real_T q_limit_range[8];
  real_T q_limit_slope[8];
  real_T q_limit_gain[8];
  boolean_T barrierfunction;
} struct_6KsaStIdjpBuRBst70TZDB;

#endif

// Custom Type definition for MATLAB Function: '<Root>/Singular Perturbation Controller' 
#ifndef struct_tag_sIbjh2WiriJotNb04AnYjk
#define struct_tag_sIbjh2WiriJotNb04AnYjk

struct tag_sIbjh2WiriJotNb04AnYjk
{
  real_T K_tau[7];
  real_T D_tau[7];
};

#endif                                 //struct_tag_sIbjh2WiriJotNb04AnYjk

#ifndef typedef_sIbjh2WiriJotNb04AnYjk
#define typedef_sIbjh2WiriJotNb04AnYjk

typedef struct tag_sIbjh2WiriJotNb04AnYjk sIbjh2WiriJotNb04AnYjk;

#endif                                 //typedef_sIbjh2WiriJotNb04AnYjk

// Custom Type definition for MATLAB Function: '<S21>/Gravitation compensation q-based' 
#ifndef struct_tag_sYA73Qec6CU8SREGMfkPEgE
#define struct_tag_sYA73Qec6CU8SREGMfkPEgE

struct tag_sYA73Qec6CU8SREGMfkPEgE
{
  real_T q_limit_upper[8];
  real_T q_limit_lower[8];
  real_T q_limit_range[8];
  real_T q_limit_slope[8];
  real_T q_limit_gain[8];
  boolean_T barrierfunction;
};

#endif                                 //struct_tag_sYA73Qec6CU8SREGMfkPEgE

#ifndef typedef_sYA73Qec6CU8SREGMfkPEgE
#define typedef_sYA73Qec6CU8SREGMfkPEgE

typedef struct tag_sYA73Qec6CU8SREGMfkPEgE sYA73Qec6CU8SREGMfkPEgE;

#endif                                 //typedef_sYA73Qec6CU8SREGMfkPEgE

// Custom Type definition for MATLAB Function: '<Root>/Robot Pose Logger'
#ifndef struct_tag_sL6LJlPlxhdTxZzXh5NTaQC
#define struct_tag_sL6LJlPlxhdTxZzXh5NTaQC

struct tag_sL6LJlPlxhdTxZzXh5NTaQC
{
  int32_T intNumBits;
};

#endif                                 //struct_tag_sL6LJlPlxhdTxZzXh5NTaQC

#ifndef typedef_sL6LJlPlxhdTxZzXh5NTaQC
#define typedef_sL6LJlPlxhdTxZzXh5NTaQC

typedef struct tag_sL6LJlPlxhdTxZzXh5NTaQC sL6LJlPlxhdTxZzXh5NTaQC;

#endif                                 //typedef_sL6LJlPlxhdTxZzXh5NTaQC

// Custom Type definition for MATLAB Function: '<Root>/Robot Model'
#ifndef struct_tag_sYAUkIU1G7S9rEYvehBuTuE
#define struct_tag_sYAUkIU1G7S9rEYvehBuTuE

struct tag_sYAUkIU1G7S9rEYvehBuTuE
{
  boolean_T hanging;
  real_T R_0[9];
  real_T p_0[3];
  real_T n;
  real_T g;
  real_T beta;
  real_T l__0;
  real_T l__1;
  real_T l__2;
  real_T l__3;
  real_T l__4;
  real_T l__5;
  real_T l__6;
  real_T l__7;
  real_T d__1;
  real_T d__3;
  real_T d__5;
  real_T m__l1;
  real_T m__l2;
  real_T m__l3;
  real_T m__l4;
  real_T m__l5;
  real_T m__l6;
  real_T m__l7;
  real_T s__l1x;
  real_T s__l1y;
  real_T s__l1z;
  real_T s__l2x;
  real_T s__l2y;
  real_T s__l2z;
  real_T s__l3x;
  real_T s__l3y;
  real_T s__l3z;
  real_T s__l4x;
  real_T s__l4y;
  real_T s__l4z;
  real_T s__l5x;
  real_T s__l5y;
  real_T s__l5z;
  real_T s__l6x;
  real_T s__l6y;
  real_T s__l6z;
  real_T s__l7x;
  real_T s__l7y;
  real_T s__l7z;
  real_T I__l1xx;
  real_T I__l1yy;
  real_T I__l1zz;
  real_T I__l2xx;
  real_T I__l2yy;
  real_T I__l2zz;
  real_T I__l3xx;
  real_T I__l3yy;
  real_T I__l3zz;
  real_T I__l4xx;
  real_T I__l4yy;
  real_T I__l4zz;
  real_T I__l5xx;
  real_T I__l5yy;
  real_T I__l5zz;
  real_T I__l6xx;
  real_T I__l6yy;
  real_T I__l6zz;
  real_T I__l7xx;
  real_T I__l7yy;
  real_T I__l7zz;
  real_T n__1;
  real_T n__2;
  real_T n__3;
  real_T n__4;
  real_T n__5;
  real_T n__6;
  real_T n__7;
  real_T N[49];
  real_T I__r1xx;
  real_T I__r1yy;
  real_T I__r1zz;
  real_T I__r2xx;
  real_T I__r2yy;
  real_T I__r2zz;
  real_T I__r3xx;
  real_T I__r3yy;
  real_T I__r3zz;
  real_T I__r4xx;
  real_T I__r4yy;
  real_T I__r4zz;
  real_T I__r5xx;
  real_T I__r5yy;
  real_T I__r5zz;
  real_T I__r6xx;
  real_T I__r6yy;
  real_T I__r6zz;
  real_T I__r7xx;
  real_T I__r7yy;
  real_T I__r7zz;
  real_T B[49];
  real_T K__1;
  real_T K__2;
  real_T K__3;
  real_T K__4;
  real_T K__5;
  real_T K__6;
  real_T K__7;
  real_T K[49];
  real_T tau_max[49];
  real_T q_limit_upper[7];
  real_T q_limit_lower[7];
};

#endif                                 //struct_tag_sYAUkIU1G7S9rEYvehBuTuE

#ifndef typedef_sYAUkIU1G7S9rEYvehBuTuE
#define typedef_sYAUkIU1G7S9rEYvehBuTuE

typedef struct tag_sYAUkIU1G7S9rEYvehBuTuE sYAUkIU1G7S9rEYvehBuTuE;

#endif                                 //typedef_sYAUkIU1G7S9rEYvehBuTuE

// Custom Type definition for MATLAB Function: '<Root>/Singular Perturbation Controller' 
#ifndef struct_tag_s4MKGw1B25wsAV6ch7ESgCG
#define struct_tag_s4MKGw1B25wsAV6ch7ESgCG

struct tag_s4MKGw1B25wsAV6ch7ESgCG
{
  real_T K_0[49];
  real_T K_1[49];
};

#endif                                 //struct_tag_s4MKGw1B25wsAV6ch7ESgCG

#ifndef typedef_s4MKGw1B25wsAV6ch7ESgCG
#define typedef_s4MKGw1B25wsAV6ch7ESgCG

typedef struct tag_s4MKGw1B25wsAV6ch7ESgCG s4MKGw1B25wsAV6ch7ESgCG;

#endif                                 //typedef_s4MKGw1B25wsAV6ch7ESgCG

#ifndef struct_tag_sB8DzM3WKvHdFb2f61DlrPF
#define struct_tag_sB8DzM3WKvHdFb2f61DlrPF

struct tag_sB8DzM3WKvHdFb2f61DlrPF
{
  real_T T_a;
  sIbjh2WiriJotNb04AnYjk singular_perturbation;
  s4MKGw1B25wsAV6ch7ESgCG joint;
};

#endif                                 //struct_tag_sB8DzM3WKvHdFb2f61DlrPF

#ifndef typedef_sB8DzM3WKvHdFb2f61DlrPF
#define typedef_sB8DzM3WKvHdFb2f61DlrPF

typedef struct tag_sB8DzM3WKvHdFb2f61DlrPF sB8DzM3WKvHdFb2f61DlrPF;

#endif                                 //typedef_sB8DzM3WKvHdFb2f61DlrPF

// Block signals and states (default storage) for system '<S1>/estimate_parabola' 
typedef struct {
  real_T t_catch_predict_p[2];         // '<S16>/Parabola Estimator'
  real_T px_est_last[2];               // '<S16>/Parabola Estimator'
  real_T Px_last[4];                   // '<S16>/Parabola Estimator'
  real_T py_est_last[2];               // '<S16>/Parabola Estimator'
  real_T Py_last[4];                   // '<S16>/Parabola Estimator'
  real_T pz_est_last[2];               // '<S16>/Parabola Estimator'
  real_T Pz_last[4];                   // '<S16>/Parabola Estimator'
  real_T use_pred_p;                   // '<S16>/Parabola Estimator'
  boolean_T t_catch_predict_p_not_empty;// '<S16>/Parabola Estimator'
  boolean_T px_est_last_not_empty;     // '<S16>/Parabola Estimator'
} DW_estimate_parabola;

// Block signals and states (default storage) for system '<Root>'
typedef struct {
  DW_estimate_parabola estimate_parabola_j;// '<S1>/estimate_parabola'
  real_T tau_d[7];                     // '<S22>/Joint-based E//A Linearization' 
  real_T Add2[7];                      // '<S4>/Add2'
  real_T pd[3];                        // '<Root>/Chart'
  real_T t_catch_predict[2];           // '<Root>/Chart'
  real_T p0[3];                        // '<Root>/Chart'
  real_T x[7];                         // '<S11>/f_theta_slow'
  real_T x_n[7];                       // '<S11>/f_theta_p_slow'
  real_T x_j[7];                       // '<S11>/f_theta_p'
  real_T x_l[7];                       // '<S11>/f_tau_slow'
  real_T x_k[7];                       // '<S11>/f_tau_p_slow'
  real_T x_m[7];                       // '<S11>/f_tau_p'
  real_T x_mn[7];                      // '<S11>/f_tau'
  real_T e_I[7];                       // '<S22>/Joint-based E//A Linearization' 
  real_T x_theta_p_hat[7];             // '<S4>/Friction Observer discrete'
  real_T TmpRTBAtDigitalClockOutport1; // '<Root>/Digital Clock'
  real_T state;                        // '<Root>/Chart'
  real_T use_pred;                     // '<Root>/Chart'
  real_T t_start;                      // '<Root>/Chart'
  real_T TmpRTBAtDigitalClockOutport1_Buffer0;// synthesized block
  real_T last_application_button;      // '<Root>/Robot Pose Logger'
  real_T t_throw_start;                // '<Root>/Parabola'
  real_T throw_pers;                   // '<Root>/Parabola'
  uint16_T temporalCounter_i1;         // '<Root>/Chart'
  uint8_T is_active_c9_controller_ballcatcher;// '<Root>/Chart'
  uint8_T is_c9_controller_ballcatcher;// '<Root>/Chart'
  boolean_T x_not_empty;               // '<S11>/f_theta_slow'
  boolean_T x_not_empty_l;             // '<S11>/f_theta_p_slow'
  boolean_T x_not_empty_e;             // '<S11>/f_theta_p'
  boolean_T x_not_empty_j;             // '<S11>/f_tau_slow'
  boolean_T x_not_empty_k;             // '<S11>/f_tau_p_slow'
  boolean_T x_not_empty_km;            // '<S11>/f_tau_p'
  boolean_T x_not_empty_c;             // '<S11>/f_tau'
  boolean_T last_application_button_not_empty;// '<Root>/Robot Pose Logger'
  boolean_T e_I_not_empty;             // '<S22>/Joint-based E//A Linearization' 
  boolean_T JointbasedEALinearization_MODE;// '<S8>/Joint-based E//A Linearization' 
  boolean_T Gravitationcompensationqbased_MODE;// '<S8>/Gravitation compensation q-based' 
} DW;

// Constant parameters (default storage)
typedef struct {
  // Expression: param_robot
  //  Referenced by: '<Root>/MATLAB Function'

  struct_bnj9PLm1Rht6xDHAOlfP8G MATLABFunction_param_robot;

  // Pooled Parameter (Expression: positions)
  //  Referenced by:
  //    '<Root>/Chart'
  //    '<Root>/MATLAB Function'

  struct_PcUEPt9FJnxk90L3HMZRgE pooled1;

  // Expression: estimator_init_struct
  //  Referenced by: '<S16>/Parabola Estimator'

  struct_drdASX3xMwFWgTYNtyjTdF ParabolaEstimator_estimator_init_struct;

  // Expression: [200;200;300;300;500;1000;1000]
  //  Referenced by: '<S4>/L'

  real_T L_Value[7];

  // Expression: [zeros(6,1);0.2]
  //  Referenced by: '<S4>/tau_c_plus'

  real_T tau_c_plus_Value[7];

  // Expression: [zeros(6,1);0.28]
  //  Referenced by: '<S4>/tau_c_minus'

  real_T tau_c_minus_Value[7];

  // Expression: [zeros(6,1);120]
  //  Referenced by: '<S4>/E'

  real_T E_Value[7];

  // Expression: [zeros(6,1);0.5]
  //  Referenced by: '<S4>/tau_v'

  real_T tau_v_Value[7];

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S11>/f_tau'
  //    '<S11>/f_tau_p'
  //    '<S11>/f_theta_p'

  real_T pooled5[7];

  // Expression: sensor_torque_offset
  //  Referenced by: '<S11>/Constant'

  real_T Constant_Value[7];
} ConstP;

// External inputs (root inport signals with default storage)
typedef struct {
  real_T fast_sensor_torque[7];        // '<Root>/fast_sensor_torque'
  real_T fast_sensor_position[7];      // '<Root>/fast_sensor_position'
  real_T fast_sensor_motor_torque_feedback[7];// '<Root>/fast_sensor_motor_torque_feedback' 
  real_T motion_enabled;               // '<Root>/motion_enabled'
  real_T sensor_mft_application_button;// '<Root>/sensor_mft_application_button' 
  Marker motive_marker_input;          // '<Root>/motive_marker_input'
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T fast_control_motor_torque[7]; // '<Root>/fast_control_motor_torque'
  real_T MotionEnable;                 // '<Root>/MotionEnable'
  real_T MotionDisable;                // '<Root>/MotionDisable'
  real_T fast_control_motor_enable[7]; // '<Root>/fast_control_motor_enable'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

// Constant parameters (default storage)
extern const ConstP rtConstP;

// Class declaration for model controller_ballcatcher
class controller_ballcatcherModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step0();

  // model step function
  void step1();

  // model step function
  void step2();

  // Constructor
  controller_ballcatcherModelClass();

  // Destructor
  ~controller_ballcatcherModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>'
  boolean_T isBallValueValid(const real_T data_point[3]);
  void trvec2tform(const real_T t[3], real_T H[16]);
  void mldivide_l(const real_T A[16], real_T B_1[16]);
  real_T norm(const real_T x[3]);
  void wrap(real_T lambda[7]);
  void inverse_kinematics_analytic(const real_T x_d[16], const
    struct_bnj9PLm1Rht6xDHAOlfP8G *param, boolean_T *success, real_T q[7]);
  void iiwa_reduced_inertia_matrix(const real_T q[7], const
    sYAUkIU1G7S9rEYvehBuTuE *param, real_T tmpreturn[49]);
  void iiwa_reduced_coriolis_matrix(const real_T q[7], const real_T q__p[7],
    const sYAUkIU1G7S9rEYvehBuTuE *param, real_T tmpreturn[49]);
  void mldivide(const real_T A[49], real_T B_0[7]);
  void mldivide_ln(const real_T A[36], real_T B_2[6]);
  real_T polyval(const real_T p_data[], const int32_T p_size[2], real_T x);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Constant11' : Unused code path elimination
//  Block '<Root>/Constant12' : Unused code path elimination
//  Block '<Root>/Constant13' : Unused code path elimination
//  Block '<Root>/Constant14' : Unused code path elimination
//  Block '<Root>/Constant15' : Unused code path elimination
//  Block '<Root>/Constant16' : Unused code path elimination
//  Block '<Root>/Constant17' : Unused code path elimination
//  Block '<Root>/Constant2' : Unused code path elimination
//  Block '<Root>/Constant5' : Unused code path elimination
//  Block '<Root>/Constant6' : Unused code path elimination
//  Block '<S3>/Gain1' : Unused code path elimination
//  Block '<Root>/Joint Target Position Selector' : Unused code path elimination
//  Block '<S4>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S4>/Manual Switch4' : Eliminated due to constant selection input
//  Block '<Root>/Manual Switch' : Eliminated due to constant selection input
//  Block '<Root>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<Root>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<Root>/Manual Switch3' : Eliminated due to constant selection input
//  Block '<Root>/Manual Switch7' : Eliminated due to constant selection input
//  Block '<Root>/Noise active' : Eliminated due to constant selection input
//  Block '<Root>/Constant18' : Unused code path elimination
//  Block '<Root>/Constant20' : Unused code path elimination
//  Block '<Root>/Constant24' : Unused code path elimination
//  Block '<S32>/Output' : Unused code path elimination
//  Block '<S32>/White Noise' : Unused code path elimination
//  Block '<S33>/Output' : Unused code path elimination
//  Block '<S33>/White Noise' : Unused code path elimination
//  Block '<S34>/Output' : Unused code path elimination
//  Block '<S34>/White Noise' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'controller_ballcatcher'
//  '<S1>'   : 'controller_ballcatcher/Chart'
//  '<S2>'   : 'controller_ballcatcher/Computed Torque Controller'
//  '<S3>'   : 'controller_ballcatcher/Degrees to Radians'
//  '<S4>'   : 'controller_ballcatcher/Friction Compensation'
//  '<S5>'   : 'controller_ballcatcher/MATLAB Function'
//  '<S6>'   : 'controller_ballcatcher/MATLAB Function1'
//  '<S7>'   : 'controller_ballcatcher/Parabola'
//  '<S8>'   : 'controller_ballcatcher/Rigid Body Controller'
//  '<S9>'   : 'controller_ballcatcher/Robot Model'
//  '<S10>'  : 'controller_ballcatcher/Robot Pose Logger'
//  '<S11>'  : 'controller_ballcatcher/Sensor Filters'
//  '<S12>'  : 'controller_ballcatcher/Singular Perturbation Controller'
//  '<S13>'  : 'controller_ballcatcher/Subsystem'
//  '<S14>'  : 'controller_ballcatcher/Trajectory Generation'
//  '<S15>'  : 'controller_ballcatcher/Trajectoy Generator'
//  '<S16>'  : 'controller_ballcatcher/Chart/estimate_parabola'
//  '<S17>'  : 'controller_ballcatcher/Chart/estimate_parabola/Parabola Estimator'
//  '<S18>'  : 'controller_ballcatcher/Friction Compensation/Friction Observer discrete'
//  '<S19>'  : 'controller_ballcatcher/Rigid Body Controller/Controller Enable'
//  '<S20>'  : 'controller_ballcatcher/Rigid Body Controller/Controller Selector'
//  '<S21>'  : 'controller_ballcatcher/Rigid Body Controller/Gravitation compensation q-based'
//  '<S22>'  : 'controller_ballcatcher/Rigid Body Controller/Joint-based E//A Linearization'
//  '<S23>'  : 'controller_ballcatcher/Rigid Body Controller/Gravitation compensation q-based/Gravitation compensation q-based'
//  '<S24>'  : 'controller_ballcatcher/Rigid Body Controller/Joint-based E//A Linearization/Joint-based E//A Linearization'
//  '<S25>'  : 'controller_ballcatcher/Sensor Filters/f_tau'
//  '<S26>'  : 'controller_ballcatcher/Sensor Filters/f_tau_p'
//  '<S27>'  : 'controller_ballcatcher/Sensor Filters/f_tau_p_slow'
//  '<S28>'  : 'controller_ballcatcher/Sensor Filters/f_tau_slow'
//  '<S29>'  : 'controller_ballcatcher/Sensor Filters/f_theta_p'
//  '<S30>'  : 'controller_ballcatcher/Sensor Filters/f_theta_p_slow'
//  '<S31>'  : 'controller_ballcatcher/Sensor Filters/f_theta_slow'
//  '<S32>'  : 'controller_ballcatcher/Subsystem/Band-Limited White Noise'
//  '<S33>'  : 'controller_ballcatcher/Subsystem/Band-Limited White Noise1'
//  '<S34>'  : 'controller_ballcatcher/Subsystem/Band-Limited White Noise2'
//  '<S35>'  : 'controller_ballcatcher/Trajectory Generation/Trajectory generator q'

#endif                                 // RTW_HEADER_controller_ballcatcher_h_

//
// File trailer for generated code.
//
// [EOF]
//
