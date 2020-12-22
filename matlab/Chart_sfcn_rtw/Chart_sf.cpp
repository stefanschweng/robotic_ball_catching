/*
 * Chart_sf.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Chart_sf".
 *
 * Model version              : 1.2954
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Mon Aug 10 13:35:49 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include <math.h>
#include "Chart_sf.h"
#include "Chart_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Chart_IN_CATCH                 ((uint8_T)1U)
#define Chart_IN_GO_TO_HAND_OVER       ((uint8_T)2U)
#define Chart_IN_GO_TO_START_FROM_CATCH ((uint8_T)3U)
#define Chart_IN_GO_TO_START_FROM_NO_CATCH ((uint8_T)4U)
#define Chart_IN_INIT                  ((uint8_T)5U)
#define Chart_IN_INIT_GOTO_START       ((uint8_T)6U)
#define Chart_IN_NO_ACTIVE_CHILD       ((uint8_T)0U)
#define Chart_IN_NO_VALID_BALL_VALUE   ((uint8_T)7U)
#define Chart_IN_READY                 ((uint8_T)8U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Chart_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)
#ifdef __cplusplus

extern "C" {

#endif

  extern void * utMalloc(size_t);
  extern void utFree(void *);

#ifdef __cplusplus

}
#endif
#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void Chart_estimate_parabola_n(real_T t_in, const real_T point_in[3],
  const struct_drdASX3xMwFWgTYNtyjTdF *b_estimator_init_struct, real_T init,
  real_T *estimations_x0_est, real_T *estimations_vx0_est, real_T
  *estimations_y0_est, real_T *estimations_vy0_est, real_T *estimations_z0_est,
  real_T *estimations_vz0_est, SimStruct * const S);

/* Forward declaration for local functions */
static boolean_T Chart_isBallValueValid(const real_T data_point[3]);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.cpp"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<S2>/Parabola Estimator' */
static void Chart_estimate_parabola_n(real_T t_in, const real_T point_in[3],
  const struct_drdASX3xMwFWgTYNtyjTdF *b_estimator_init_struct, real_T init,
  real_T *estimations_x0_est, real_T *estimations_vx0_est, real_T
  *estimations_y0_est, real_T *estimations_vy0_est, real_T *estimations_z0_est,
  real_T *estimations_vz0_est, SimStruct * const S)
{
  real_T kx_i[2];
  real_T ky_i[2];
  real_T kz_i[2];
  real_T b_estimator_init_struct_0;
  real_T kx_i_0[4];
  real_T tmp[4];
  int32_T i;
  real_T y_tmp;
  if ((!((boolean_T *)ssGetDWork(S, 12))[0]) || (init != 0.0)) {
    ((real_T *)ssGetDWork(S, 5))[0] = b_estimator_init_struct->px_est_last[0];
    ((real_T *)ssGetDWork(S, 5))[1] = b_estimator_init_struct->px_est_last[1];
    ((boolean_T *)ssGetDWork(S, 12))[0] = true;
    ((real_T *)ssGetDWork(S, 6))[0] = b_estimator_init_struct->Px_last[0];
    ((real_T *)ssGetDWork(S, 6))[1] = b_estimator_init_struct->Px_last[1];
    ((real_T *)ssGetDWork(S, 6))[2] = b_estimator_init_struct->Px_last[2];
    ((real_T *)ssGetDWork(S, 6))[3] = b_estimator_init_struct->Px_last[3];
    ((real_T *)ssGetDWork(S, 7))[0] = b_estimator_init_struct->py_est_last[0];
    ((real_T *)ssGetDWork(S, 7))[1] = b_estimator_init_struct->py_est_last[1];
    ((real_T *)ssGetDWork(S, 8))[0] = b_estimator_init_struct->Py_last[0];
    ((real_T *)ssGetDWork(S, 8))[1] = b_estimator_init_struct->Py_last[1];
    ((real_T *)ssGetDWork(S, 8))[2] = b_estimator_init_struct->Py_last[2];
    ((real_T *)ssGetDWork(S, 8))[3] = b_estimator_init_struct->Py_last[3];
    ((real_T *)ssGetDWork(S, 9))[0] = b_estimator_init_struct->pz_est_last[0];
    ((real_T *)ssGetDWork(S, 9))[1] = b_estimator_init_struct->pz_est_last[1];
    ((real_T *)ssGetDWork(S, 10))[0] = b_estimator_init_struct->Pz_last[0];
    ((real_T *)ssGetDWork(S, 10))[1] = b_estimator_init_struct->Pz_last[1];
    ((real_T *)ssGetDWork(S, 10))[2] = b_estimator_init_struct->Pz_last[2];
    ((real_T *)ssGetDWork(S, 10))[3] = b_estimator_init_struct->Pz_last[3];
  }

  b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 6))[3] +
    ((real_T *)ssGetDWork(S, 6))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S, 6))
    [1] + ((real_T *)ssGetDWork(S, 6))[0])) + b_estimator_init_struct->q;
  y_tmp = 1.0 / b_estimator_init_struct->q;
  kx_i[0] = (((real_T *)ssGetDWork(S, 6))[2] * t_in + ((real_T *)ssGetDWork(S, 6))
             [0]) / b_estimator_init_struct_0;
  kx_i[1] = (((real_T *)ssGetDWork(S, 6))[3] * t_in + ((real_T *)ssGetDWork(S, 6))
             [1]) / b_estimator_init_struct_0;
  b_estimator_init_struct_0 = point_in[0] - (t_in * ((real_T *)ssGetDWork(S, 5))
    [1] + ((real_T *)ssGetDWork(S, 5))[0]);
  ((real_T *)ssGetDWork(S, 5))[0] = kx_i[0] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 5))[0];
  ((real_T *)ssGetDWork(S, 5))[1] = kx_i[1] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 5))[1];
  *estimations_x0_est = ((real_T *)ssGetDWork(S, 5))[0];
  *estimations_vx0_est = ((real_T *)ssGetDWork(S, 5))[1];
  b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 8))[3] +
    ((real_T *)ssGetDWork(S, 8))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S, 8))
    [1] + ((real_T *)ssGetDWork(S, 8))[0])) + b_estimator_init_struct->q;
  ky_i[0] = (((real_T *)ssGetDWork(S, 8))[2] * t_in + ((real_T *)ssGetDWork(S, 8))
             [0]) / b_estimator_init_struct_0;
  ky_i[1] = (((real_T *)ssGetDWork(S, 8))[3] * t_in + ((real_T *)ssGetDWork(S, 8))
             [1]) / b_estimator_init_struct_0;
  b_estimator_init_struct_0 = point_in[1] - (t_in * ((real_T *)ssGetDWork(S, 7))
    [1] + ((real_T *)ssGetDWork(S, 7))[0]);
  ((real_T *)ssGetDWork(S, 7))[0] = ky_i[0] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 7))[0];
  ((real_T *)ssGetDWork(S, 7))[1] = ky_i[1] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 7))[1];
  *estimations_y0_est = ((real_T *)ssGetDWork(S, 7))[0];
  *estimations_vy0_est = ((real_T *)ssGetDWork(S, 7))[1];
  b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 10))[3] +
    ((real_T *)ssGetDWork(S, 10))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S,
    10))[1] + ((real_T *)ssGetDWork(S, 10))[0])) + b_estimator_init_struct->q;
  kz_i[0] = (((real_T *)ssGetDWork(S, 10))[2] * t_in + ((real_T *)ssGetDWork(S,
    10))[0]) / b_estimator_init_struct_0;
  kz_i[1] = (((real_T *)ssGetDWork(S, 10))[3] * t_in + ((real_T *)ssGetDWork(S,
    10))[1]) / b_estimator_init_struct_0;
  b_estimator_init_struct_0 = (t_in * t_in * 4.905 + point_in[2]) - (t_in *
    ((real_T *)ssGetDWork(S, 9))[1] + ((real_T *)ssGetDWork(S, 9))[0]);
  ((real_T *)ssGetDWork(S, 9))[0] = kz_i[0] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 9))[0];
  ((real_T *)ssGetDWork(S, 9))[1] = kz_i[1] * b_estimator_init_struct_0 +
    ((real_T *)ssGetDWork(S, 9))[1];
  *estimations_z0_est = ((real_T *)ssGetDWork(S, 9))[0];
  *estimations_vz0_est = ((real_T *)ssGetDWork(S, 9))[1];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = kx_i[i];
    kx_i_0[i + 2] = kx_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = ((real_T *)ssGetDWork(S, 6))[i] - (b_estimator_init_struct_0 *
      ((real_T *)ssGetDWork(S, 6))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S, 6))
      [0]);
    tmp[i + 2] = ((real_T *)ssGetDWork(S, 6))[i + 2] -
      (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 6))[3] + kx_i_0[i] *
       ((real_T *)ssGetDWork(S, 6))[2]);
  }

  ((real_T *)ssGetDWork(S, 6))[0] = y_tmp * tmp[0];
  ((real_T *)ssGetDWork(S, 6))[1] = y_tmp * tmp[1];
  ((real_T *)ssGetDWork(S, 6))[2] = y_tmp * tmp[2];
  ((real_T *)ssGetDWork(S, 6))[3] = y_tmp * tmp[3];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = ky_i[i];
    kx_i_0[i + 2] = ky_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = ((real_T *)ssGetDWork(S, 8))[i] - (b_estimator_init_struct_0 *
      ((real_T *)ssGetDWork(S, 8))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S, 8))
      [0]);
    tmp[i + 2] = ((real_T *)ssGetDWork(S, 8))[i + 2] -
      (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 8))[3] + kx_i_0[i] *
       ((real_T *)ssGetDWork(S, 8))[2]);
  }

  ((real_T *)ssGetDWork(S, 8))[0] = y_tmp * tmp[0];
  ((real_T *)ssGetDWork(S, 8))[1] = y_tmp * tmp[1];
  ((real_T *)ssGetDWork(S, 8))[2] = y_tmp * tmp[2];
  ((real_T *)ssGetDWork(S, 8))[3] = y_tmp * tmp[3];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = kz_i[i];
    kx_i_0[i + 2] = kz_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = ((real_T *)ssGetDWork(S, 10))[i] - (b_estimator_init_struct_0 *
      ((real_T *)ssGetDWork(S, 10))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S, 10))
      [0]);
    tmp[i + 2] = ((real_T *)ssGetDWork(S, 10))[i + 2] -
      (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 10))[3] + kx_i_0[i] *
       ((real_T *)ssGetDWork(S, 10))[2]);
  }

  ((real_T *)ssGetDWork(S, 10))[0] = y_tmp * tmp[0];
  ((real_T *)ssGetDWork(S, 10))[1] = y_tmp * tmp[1];
  ((real_T *)ssGetDWork(S, 10))[2] = y_tmp * tmp[2];
  ((real_T *)ssGetDWork(S, 10))[3] = y_tmp * tmp[3];
}

/* System initialize for function-call system: '<S1>/estimate_parabola' */
void Chart_estimate_parabola_Init(SimStruct * const S,
  B_estimate_parabola_Chart_T *localB)
{
  /* SystemInitialize for MATLAB Function: '<S2>/Parabola Estimator' */
  ((boolean_T *)ssGetDWork(S, 11))[0] = false;
  ((boolean_T *)ssGetDWork(S, 12))[0] = false;

  /* SystemInitialize for Outport: '<S2>/pd' */
  localB->pd[0] = 0.0;

  /* SystemInitialize for Outport: '<S2>/pd_p' */
  localB->pd_p[0] = 0.0;

  /* SystemInitialize for Outport: '<S2>/pd' */
  localB->pd[1] = 0.0;

  /* SystemInitialize for Outport: '<S2>/pd_p' */
  localB->pd_p[1] = 0.0;

  /* SystemInitialize for Outport: '<S2>/pd' */
  localB->pd[2] = 0.0;

  /* SystemInitialize for Outport: '<S2>/pd_p' */
  localB->pd_p[2] = 0.0;

  /* SystemInitialize for Outport: '<S2>/use_pred' */
  localB->use_pred = 0.0;

  /* SystemInitialize for Outport: '<S2>/t_catch_predict' */
  localB->t_catch_predict[0] = 0.0;
  localB->t_catch_predict[1] = 0.0;
}

/* Output and update for function-call system: '<S1>/estimate_parabola' */
void Chart_estimate_parabola(SimStruct * const S, real_T rtu_t_in, real_T
  rtu_t_start, const real_T rtu_point_in[3], real_T rtu_init,
  B_estimate_parabola_Chart_T *localB)
{
  real_T t_for_est;
  real_T t_start_g;
  real_T x_out;
  real_T z_out;
  real_T x_out_p;
  real_T y_out_p;
  real_T z_out_p;

  /* MATLAB Function: '<S2>/Parabola Estimator' */
  /* MATLAB Function 'Chart/estimate_parabola/Parabola Estimator': '<S3>:1' */
  /* '<S3>:1:3' */
  /* '<S3>:1:4' */
  if ((rtu_init != 0.0) || (!((boolean_T *)ssGetDWork(S, 11))[0])) {
    /* '<S3>:1:6' */
    /* '<S3>:1:7' */
    ((real_T *)ssGetDWork(S, 3))[0] = 0.0;

    /* '<S3>:1:8' */
    ((real_T *)ssGetDWork(S, 4))[0] = rtu_t_start + 0.1;
    ((real_T *)ssGetDWork(S, 4))[1] = (rtu_t_start + 0.1) + 1.0;
    ((boolean_T *)ssGetDWork(S, 11))[0] = true;
  }

  if ((rtu_t_in >= ((real_T *)ssGetDWork(S, 4))[0]) && (rtu_t_in <= ((real_T *)
        ssGetDWork(S, 4))[1])) {
    /* '<S3>:1:11' */
    /* '<S3>:1:12' */
    ((real_T *)ssGetDWork(S, 3))[0] = 1.0;

    /* '<S3>:1:15' */
    Chart_estimate_parabola_n(rtu_t_in - rtu_t_start, rtu_point_in,
      &Chart_ConstP.ParabolaEstimator_estimator_init_struct, rtu_init, &x_out,
      &x_out_p, &t_start_g, &y_out_p, &z_out, &z_out_p, (SimStruct * const )S);

    /* '<S3>:1:16' */
    /* '<S3>:1:17' */
    /* '<S3>:1:18' */
    /* '<S3>:1:19' */
    /* '<S3>:1:20' */
    /* '<S3>:1:21' */
    /* '<S3>:1:34' */
    /* '<S3>:1:37' */
    t_for_est = -(std::sqrt((19.62 * z_out + -15.696000000000002) + z_out_p *
      z_out_p) + z_out_p) / -9.81;

    /* '<S3>:1:48' */
    localB->pd[0] = x_out_p * t_for_est + x_out;

    /* '<S3>:1:49' */
    localB->pd[1] = y_out_p * t_for_est + t_start_g;

    /* '<S3>:1:50' */
    localB->pd[2] = (z_out_p * t_for_est + z_out) - t_for_est * t_for_est *
      4.905;

    /* '<S3>:1:53' */
    /* '<S3>:1:54' */
    /* '<S3>:1:55' */
    z_out_p -= 9.81 * t_for_est;

    /* '<S3>:1:57' */
    ((real_T *)ssGetDWork(S, 4))[0] = rtu_t_start + 0.1;
    ((real_T *)ssGetDWork(S, 4))[1] = t_for_est + rtu_t_start;
  } else {
    /* '<S3>:1:59' */
    Chart_estimate_parabola_n(rtu_t_in - rtu_t_start, rtu_point_in,
      &Chart_ConstP.ParabolaEstimator_estimator_init_struct, rtu_init,
      &t_start_g, &x_out_p, &y_out_p, &z_out_p, &x_out, &z_out, (SimStruct *
      const )S);

    /* '<S3>:1:61' */
    localB->pd[0] = 0.0;

    /* '<S3>:1:62' */
    localB->pd[1] = 0.0;

    /* '<S3>:1:63' */
    localB->pd[2] = 0.0;

    /* '<S3>:1:65' */
    x_out_p = 0.0;

    /* '<S3>:1:66' */
    y_out_p = 0.0;

    /* '<S3>:1:67' */
    z_out_p = 0.0;
  }

  /* '<S3>:1:71' */
  /* '<S3>:1:72' */
  /* '<S3>:1:74' */
  /* '<S3>:1:75' */
  localB->pd_p[0] = -x_out_p;
  localB->pd_p[1] = -y_out_p;
  localB->pd_p[2] = -z_out_p;
  localB->use_pred = ((real_T *)ssGetDWork(S, 3))[0];
  localB->t_catch_predict[0] = ((real_T *)ssGetDWork(S, 4))[0];
  localB->t_catch_predict[1] = ((real_T *)ssGetDWork(S, 4))[1];

  /* End of MATLAB Function: '<S2>/Parabola Estimator' */
}

/* Termination for function-call system: '<S1>/estimate_parabola' */
void Chart_estimate_parabola_Term(SimStruct *const S)
{
}

/* Function for Chart: '<Root>/Chart' */
static boolean_T Chart_isBallValueValid(const real_T data_point[3])
{
  boolean_T b;

  /* MATLAB Function 'isBallValueValid': '<S1>:66' */
  if ((data_point[0] == 0.0) && (data_point[1] == 0.0) && (data_point[2] == 0.0))
  {
    /* '<S1>:66:2' */
    b = true;
  } else {
    b = false;
  }

  /* '<S1>:66:2' */
  return !b;
}

/* System initialize for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  if (ssIsFirstInitCond(S)) {
    B_Chart_T *_rtB;
    _rtB = ((B_Chart_T *) ssGetLocalBlockIO(S));
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<Root>/Chart' incorporates:
     *  SubSystem: '<S1>/estimate_parabola'
     */
    Chart_estimate_parabola_Init((SimStruct * const )S, &_rtB->estimate_parabola);
  } else {                             /* SystemReset for Chart: '<Root>/Chart' */
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_NO_ACTIVE_CHILD;
  }
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  if (ssGetSolverMode(S) == SOLVER_MODE_MULTITASKING) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "solver mode set to auto or multitasking "
                     "because this S-Function was created from a model with "
                     "solver mode set to singletasking. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

#  endif

  Chart_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  B_Chart_T *_rtB;
  _rtB = ((B_Chart_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 0, 0)) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
     *  Chart: '<Root>/Chart'
     */
    _rtB->TmpSignalConversionAtSFunctionInport4[0] = *((const real_T **)
      ssGetInputPortSignalPtrs(S, 3))[0];
    _rtB->TmpSignalConversionAtSFunctionInport4[1] = *((const real_T **)
      ssGetInputPortSignalPtrs(S, 4))[0];
    _rtB->TmpSignalConversionAtSFunctionInport4[2] = *((const real_T **)
      ssGetInputPortSignalPtrs(S, 5))[0];

    /* Chart: '<Root>/Chart' */
    if (((uint32_T *)ssGetDWork(S, 0))[0] < 131071U) {
      ((uint32_T *)ssGetDWork(S, 0))[0] = ((uint32_T *)ssGetDWork(S, 0))[0] + 1U;
    }

    /* Gateway: Chart */
    /* During: Chart */
    if (((uint8_T *)ssGetDWork(S, 1))[0] == 0U) {
      /* Entry: Chart */
      ((uint8_T *)ssGetDWork(S, 1))[0] = 1U;

      /* Entry Internal: Chart */
      /* Transition: '<S1>:27' */
      ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_INIT;

      /* Entry 'INIT': '<S1>:95' */
      _rtB->use_pred = 0.0;
      _rtB->t_catch_predict[0] = 0.0;
      _rtB->t_catch_predict[1] = 0.0;
      _rtB->p0[0] = 0.0;
      _rtB->p0_p[0] = 0.0;
      _rtB->pd[0] = 0.0;
      _rtB->pd_p[0] = 0.0;
      _rtB->p0[1] = 0.0;
      _rtB->p0_p[1] = 0.0;
      _rtB->pd[1] = 0.0;
      _rtB->pd_p[1] = 0.0;
      _rtB->p0[2] = 1.332;
      _rtB->p0_p[2] = 0.0;
      _rtB->pd[2] = 1.332;
      _rtB->pd_p[2] = 0.0;
    } else {
      switch (((uint8_T *)ssGetDWork(S, 2))[0]) {
       case Chart_IN_CATCH:
        _rtB->state = 2.0;

        /* During 'CATCH': '<S1>:17' */
        if (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] >
            _rtB->t_catch_predict[1]) {
          /* Transition: '<S1>:20' */
          /* Exit 'CATCH': '<S1>:17' */
          _rtB->use_pred = 0.0;
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_NO_VALID_BALL_VALUE;
          ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

          /* Entry 'NO_VALID_BALL_VALUE': '<S1>:79' */
          _rtB->state = 3.0;
        } else {
          /* Simulink Function 'estimate_parabola': '<S1>:52' */
          _rtB->t_in = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
          _rtB->t_start_p = _rtB->t_start;
          _rtB->point_in[0] = _rtB->TmpSignalConversionAtSFunctionInport4[0];
          _rtB->point_in[1] = _rtB->TmpSignalConversionAtSFunctionInport4[1];
          _rtB->point_in[2] = _rtB->TmpSignalConversionAtSFunctionInport4[2];
          _rtB->init = 0.0;

          /* Outputs for Function Call SubSystem: '<S1>/estimate_parabola' */
          Chart_estimate_parabola((SimStruct * const )S, _rtB->t_in,
            _rtB->t_start_p, _rtB->point_in, _rtB->init,
            &_rtB->estimate_parabola);

          /* End of Outputs for SubSystem: '<S1>/estimate_parabola' */
          _rtB->pd[0] = _rtB->estimate_parabola.pd[0];
          _rtB->pd_p[0] = _rtB->estimate_parabola.pd_p[0];
          _rtB->pd[1] = _rtB->estimate_parabola.pd[1];
          _rtB->pd_p[1] = _rtB->estimate_parabola.pd_p[1];
          _rtB->pd[2] = _rtB->estimate_parabola.pd[2];
          _rtB->pd_p[2] = _rtB->estimate_parabola.pd_p[2];
          _rtB->use_pred = _rtB->estimate_parabola.use_pred;
          _rtB->t_catch_predict[0] = _rtB->estimate_parabola.t_catch_predict[0];
          _rtB->t_catch_predict[1] = _rtB->estimate_parabola.t_catch_predict[1];
        }
        break;

       case Chart_IN_GO_TO_HAND_OVER:
        _rtB->state = 4.0;

        /* During 'GO_TO_HAND_OVER': '<S1>:18' */
        if ((((uint32_T *)ssGetDWork(S, 0))[0] >= 80000U) && (*((const real_T **)
              ssGetInputPortSignalPtrs(S, 0))[0] != 0.0)) {
          /* Transition: '<S1>:24' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_GO_TO_START_FROM_CATCH;
          ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

          /* Entry 'GO_TO_START_FROM_CATCH': '<S1>:21' */
          _rtB->state = 5.0;
          _rtB->t_catch_predict[0] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 2))[0];
          _rtB->t_catch_predict[1] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 2))[0] + 10.0;
          _rtB->p0[0] = 0.4;
          _rtB->p0_p[0] = 1.0;
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->p0[1] = 0.0;
          _rtB->p0_p[1] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->p0[2] = 0.8;
          _rtB->p0_p[2] = 1.0;
          _rtB->pd[2] = 0.8;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart_IN_GO_TO_START_FROM_CATCH:
        _rtB->state = 5.0;

        /* During 'GO_TO_START_FROM_CATCH': '<S1>:21' */
        /* Transition: '<S1>:91' */
        if (((uint32_T *)ssGetDWork(S, 0))[0] >= 80000U) {
          /* Transition: '<S1>:25' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_READY;

          /* Entry 'READY': '<S1>:16' */
          _rtB->state = 1.0;
          _rtB->p0[0] = 0.4;
          _rtB->p0_p[0] = 0.0;
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->p0[1] = 0.0;
          _rtB->p0_p[1] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->p0[2] = 0.8;
          _rtB->p0_p[2] = 0.0;
          _rtB->pd[2] = 0.8;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart_IN_GO_TO_START_FROM_NO_CATCH:
        _rtB->state = 6.0;

        /* During 'GO_TO_START_FROM_NO_CATCH': '<S1>:87' */
        /* Transition: '<S1>:90' */
        if (((uint32_T *)ssGetDWork(S, 0))[0] >= 80000U) {
          /* Transition: '<S1>:25' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_READY;

          /* Entry 'READY': '<S1>:16' */
          _rtB->state = 1.0;
          _rtB->p0[0] = 0.4;
          _rtB->p0_p[0] = 0.0;
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->p0[1] = 0.0;
          _rtB->p0_p[1] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->p0[2] = 0.8;
          _rtB->p0_p[2] = 0.0;
          _rtB->pd[2] = 0.8;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart_IN_INIT:
        /* During 'INIT': '<S1>:95' */
        if (*((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0] != 0.0) {
          /* Transition: '<S1>:107' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_INIT_GOTO_START;
          ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

          /* Entry 'INIT_GOTO_START': '<S1>:103' */
          _rtB->t_catch_predict[0] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 2))[0];
          _rtB->t_catch_predict[1] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 2))[0] + 5.0;
          _rtB->p0[0] = 0.0;
          _rtB->p0_p[0] = 0.0;
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->p0[1] = 0.0;
          _rtB->p0_p[1] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->p0[2] = 1.332;
          _rtB->p0_p[2] = 0.0;
          _rtB->pd[2] = 0.8;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart_IN_INIT_GOTO_START:
        /* During 'INIT_GOTO_START': '<S1>:103' */
        if (((uint32_T *)ssGetDWork(S, 0))[0] >= 40000U) {
          /* Transition: '<S1>:108' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_READY;

          /* Entry 'READY': '<S1>:16' */
          _rtB->state = 1.0;
          _rtB->p0[0] = 0.4;
          _rtB->p0_p[0] = 0.0;
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->p0[1] = 0.0;
          _rtB->p0_p[1] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->p0[2] = 0.8;
          _rtB->p0_p[2] = 0.0;
          _rtB->pd[2] = 0.8;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart_IN_NO_VALID_BALL_VALUE:
        _rtB->state = 3.0;

        /* During 'NO_VALID_BALL_VALUE': '<S1>:79' */
        if (((uint32_T *)ssGetDWork(S, 0))[0] >= 8000U) {
          /* Transition: '<S1>:86' */
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] != 0.0) {
            /* Transition: '<S1>:81' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_GO_TO_HAND_OVER;
            ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

            /* Entry 'GO_TO_HAND_OVER': '<S1>:18' */
            _rtB->state = 4.0;
            _rtB->t_catch_predict[0] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 2))[0];
            _rtB->t_catch_predict[1] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 2))[0] + 10.0;
            _rtB->p0[0] = _rtB->pd[0];
            _rtB->p0_p[0] = _rtB->pd_p[0];
            _rtB->pd[0] = 0.4;
            _rtB->pd_p[0] = 1.0;
            _rtB->p0[1] = _rtB->pd[1];
            _rtB->p0_p[1] = _rtB->pd_p[1];
            _rtB->pd[1] = 0.0;
            _rtB->pd_p[1] = 0.0;
            _rtB->p0[2] = _rtB->pd[2];
            _rtB->p0_p[2] = _rtB->pd_p[2];
            _rtB->pd[2] = 0.8;
            _rtB->pd_p[2] = 1.0;
          } else {
            /* Transition: '<S1>:88' */
            ((uint8_T *)ssGetDWork(S, 2))[0] =
              Chart_IN_GO_TO_START_FROM_NO_CATCH;
            ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

            /* Entry 'GO_TO_START_FROM_NO_CATCH': '<S1>:87' */
            _rtB->state = 6.0;
            _rtB->t_catch_predict[0] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 2))[0];
            _rtB->t_catch_predict[1] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 2))[0] + 10.0;
            _rtB->p0[0] = _rtB->pd[0];
            _rtB->p0_p[0] = _rtB->pd_p[0];
            _rtB->pd[0] = 0.4;
            _rtB->pd_p[0] = 0.0;
            _rtB->p0[1] = _rtB->pd[1];
            _rtB->p0_p[1] = _rtB->pd_p[1];
            _rtB->pd[1] = 0.0;
            _rtB->pd_p[1] = 0.0;
            _rtB->p0[2] = _rtB->pd[2];
            _rtB->p0_p[2] = _rtB->pd_p[2];
            _rtB->pd[2] = 0.8;
            _rtB->pd_p[2] = 0.0;
          }
        }
        break;

       default:
        _rtB->state = 1.0;

        /* During 'READY': '<S1>:16' */
        if (Chart_isBallValueValid(_rtB->TmpSignalConversionAtSFunctionInport4))
        {
          /* Transition: '<S1>:26' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_CATCH;

          /* Entry 'CATCH': '<S1>:17' */
          _rtB->state = 2.0;
          _rtB->t_start = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];

          /* Simulink Function 'estimate_parabola': '<S1>:52' */
          _rtB->t_in = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
          _rtB->t_start_p = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
          _rtB->point_in[0] = _rtB->TmpSignalConversionAtSFunctionInport4[0];
          _rtB->point_in[1] = _rtB->TmpSignalConversionAtSFunctionInport4[1];
          _rtB->point_in[2] = _rtB->TmpSignalConversionAtSFunctionInport4[2];
          _rtB->init = 1.0;

          /* Outputs for Function Call SubSystem: '<S1>/estimate_parabola' */
          Chart_estimate_parabola((SimStruct * const )S, _rtB->t_in,
            _rtB->t_start_p, _rtB->point_in, _rtB->init,
            &_rtB->estimate_parabola);

          /* End of Outputs for SubSystem: '<S1>/estimate_parabola' */
          _rtB->pd[0] = _rtB->estimate_parabola.pd[0];
          _rtB->pd_p[0] = _rtB->estimate_parabola.pd_p[0];
          _rtB->pd[1] = _rtB->estimate_parabola.pd[1];
          _rtB->pd_p[1] = _rtB->estimate_parabola.pd_p[1];
          _rtB->pd[2] = _rtB->estimate_parabola.pd[2];
          _rtB->pd_p[2] = _rtB->estimate_parabola.pd_p[2];
          _rtB->use_pred = _rtB->estimate_parabola.use_pred;
          _rtB->t_catch_predict[0] = _rtB->estimate_parabola.t_catch_predict[0];
          _rtB->t_catch_predict[1] = _rtB->estimate_parabola.t_catch_predict[1];
        } else {
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 7))[0] != 0.0) {
            /* Transition: '<S1>:111' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart_IN_INIT;

            /* Entry 'INIT': '<S1>:95' */
            _rtB->use_pred = 0.0;
            _rtB->t_catch_predict[0] = 0.0;
            _rtB->t_catch_predict[1] = 0.0;
            _rtB->p0[0] = 0.0;
            _rtB->p0_p[0] = 0.0;
            _rtB->pd[0] = 0.0;
            _rtB->pd_p[0] = 0.0;
            _rtB->p0[1] = 0.0;
            _rtB->p0_p[1] = 0.0;
            _rtB->pd[1] = 0.0;
            _rtB->pd_p[1] = 0.0;
            _rtB->p0[2] = 1.332;
            _rtB->p0_p[2] = 0.0;
            _rtB->pd[2] = 1.332;
            _rtB->pd_p[2] = 0.0;
          }
        }
        break;
      }
    }

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->pd[0];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->pd_p[0];

    /* Outport: '<Root>/p0' */
    ((real_T *)ssGetOutputPortSignal(S, 5))[0] = _rtB->p0[0];

    /* Outport: '<Root>/p0_p' */
    ((real_T *)ssGetOutputPortSignal(S, 6))[0] = _rtB->p0_p[0];

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[1] = _rtB->pd[1];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[1] = _rtB->pd_p[1];

    /* Outport: '<Root>/p0' */
    ((real_T *)ssGetOutputPortSignal(S, 5))[1] = _rtB->p0[1];

    /* Outport: '<Root>/p0_p' */
    ((real_T *)ssGetOutputPortSignal(S, 6))[1] = _rtB->p0_p[1];

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[2] = _rtB->pd[2];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[2] = _rtB->pd_p[2];

    /* Outport: '<Root>/p0' */
    ((real_T *)ssGetOutputPortSignal(S, 5))[2] = _rtB->p0[2];

    /* Outport: '<Root>/p0_p' */
    ((real_T *)ssGetOutputPortSignal(S, 6))[2] = _rtB->p0_p[2];

    /* Outport: '<Root>/t_catch_predict' */
    ((real_T *)ssGetOutputPortSignal(S, 3))[0] = _rtB->t_catch_predict[0];
    ((real_T *)ssGetOutputPortSignal(S, 3))[1] = _rtB->t_catch_predict[1];

    /* Outport: '<Root>/state' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->state;

    /* Outport: '<Root>/use_pred' */
    ((real_T *)ssGetOutputPortSignal(S, 4))[0] = _rtB->use_pred;

    /* Outport: '<Root>/t_start' */
    ((real_T *)ssGetOutputPortSignal(S, 7))[0] = _rtB->t_start;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "Chart_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 8))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.000125);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.000125);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 0.000125);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* outport number: 3 */
  if (!ssSetOutputPortMatrixDimensions(S, 3, 1, 2))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 3, 0.000125);
  ssSetOutputPortOffsetTime(S, 3, 0.0);
  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 4, 0.000125);
  ssSetOutputPortOffsetTime(S, 4, 0.0);
  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* outport number: 5 */
  if (!ssSetOutputPortVectorDimension(S, 5, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 5, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 5, 0.000125);
  ssSetOutputPortOffsetTime(S, 5, 0.0);
  ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);

  /* outport number: 6 */
  if (!ssSetOutputPortVectorDimension(S, 6, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 6, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 6, 0.000125);
  ssSetOutputPortOffsetTime(S, 6, 0.0);
  ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);

  /* outport number: 7 */
  if (!ssSetOutputPortVectorDimension(S, 7, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 7, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 7, 0.000125);
  ssSetOutputPortOffsetTime(S, 7, 0.0);
  ssSetOutputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 8))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.000125);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.000125);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.008);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 0.000125);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortSampleTime(S, 4, 0.000125);
    ssSetInputPortOffsetTime(S, 4, 0.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortSampleTime(S, 5, 0.000125);
    ssSetInputPortOffsetTime(S, 5, 0.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 0.000125);
    ssSetInputPortOffsetTime(S, 6, 0.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 7 */
  {
    if (!ssSetInputPortVectorDimension(S, 7, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 7, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 7, 1);
    ssSetInputPortSampleTime(S, 7, 0.000125);
    ssSetInputPortOffsetTime(S, 7, 0.0);
    ssSetInputPortOverWritable(S, 7, 0);
    ssSetInputPortOptimOpts(S, 7, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 13)) {
    return;
  }

  /* '<Root>/Chart': DWORK3 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* '<Root>/Chart': DWORK1 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT8);

  /* '<Root>/Chart': DWORK2 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_UINT8);

  /* '<S2>/Parabola Estimator': DWORK1 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);

  /* '<S2>/Parabola Estimator': DWORK2 */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 2);

  /* '<S2>/Parabola Estimator': DWORK4 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 2);

  /* '<S2>/Parabola Estimator': DWORK6 */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 4);

  /* '<S2>/Parabola Estimator': DWORK7 */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 2);

  /* '<S2>/Parabola Estimator': DWORK8 */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 4);

  /* '<S2>/Parabola Estimator': DWORK9 */
  ssSetDWorkName(S, 9, "DWORK9");
  ssSetDWorkWidth(S, 9, 2);

  /* '<S2>/Parabola Estimator': DWORK10 */
  ssSetDWorkName(S, 10, "DWORK10");
  ssSetDWorkWidth(S, 10, 4);

  /* '<S2>/Parabola Estimator': DWORK3 */
  ssSetDWorkName(S, 11, "DWORK11");
  ssSetDWorkWidth(S, 11, 1);
  ssSetDWorkDataType(S, 11, SS_BOOLEAN);

  /* '<S2>/Parabola Estimator': DWORK5 */
  ssSetDWorkName(S, 12, "DWORK12");
  ssSetDWorkWidth(S, 12, 1);
  ssSetDWorkDataType(S, 12, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.000125);
  ssSetSampleTime(S, 1, 0.008);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Chart_sf

extern "C" {

# include "cg_sfun.h"

}
#endif                                 /* defined(MATLAB_MEX_FILE) */
