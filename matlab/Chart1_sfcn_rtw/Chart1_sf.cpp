/*
 * Chart1_sf.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Chart1_sf".
 *
 * Model version              : 1.3628
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct 13 14:51:01 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include <math.h>
#include "Chart1_sf.h"
#include "Chart1_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define Chart1_IN_CATCH                ((uint8_T)1U)
#define Chart1_IN_GO_TO_START_FROM_NO_CATCH ((uint8_T)2U)
#define Chart1_IN_INIT                 ((uint8_T)3U)
#define Chart1_IN_INIT_GOTO_START      ((uint8_T)4U)
#define Chart1_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Chart1_IN_NO_VALID_BALL_VALUE  ((uint8_T)5U)
#define Chart1_IN_READY                ((uint8_T)6U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Chart1_malloc(SimStruct *S);

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
static boolean_T Chart1_isequal(const real_T varargin_1[3], const real_T
  varargin_2[3]);
static void Chart1_estimate_parabola_f(real_T t_in, const real_T point_in[3],
  const struct_3PKqMdhV3cqvODbHdLwLIG *b_estimator_init_struct, real_T init,
  sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *estimations, real_T *prediction_update,
  SimStruct * const S);

/* Forward declaration for local functions */
static boolean_T Chart1_isBallValueValid(const real_T data_point[3]);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.cpp"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<S2>/Parabola Estimator' */
static boolean_T Chart1_isequal(const real_T varargin_1[3], const real_T
  varargin_2[3])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/*
 * Function for MATLAB Function: '<S2>/Parabola Estimator'
 * function [estimations,prediction_update] = estimate_parabola(t_in,point_in,estimator_init_struct,init)
 */
static void Chart1_estimate_parabola_f(real_T t_in, const real_T point_in[3],
  const struct_3PKqMdhV3cqvODbHdLwLIG *b_estimator_init_struct, real_T init,
  sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *estimations, real_T *prediction_update,
  SimStruct * const S)
{
  real_T kx_i[2];
  real_T ky_i[2];
  real_T kz_i[2];
  real_T tmp[3];
  real_T b_estimator_init_struct_0;
  real_T kx_i_0[4];
  real_T tmp_0[4];
  int32_T i;
  real_T y_tmp;

  /* 'estimate_parabola:3' g = 9.81; */
  /* 'estimate_parabola:4' estimations = struct(); */
  /* 'estimate_parabola:5' prediction_update = 0; */
  *prediction_update = 0.0;

  /* 'estimate_parabola:9' if (isempty(px_est_last) || init) */
  if ((!((boolean_T *)ssGetDWork(S, 21))[0]) || (init != 0.0)) {
    /* 'estimate_parabola:10' px_est_last = [point_in(1);0]; */
    ((real_T *)ssGetDWork(S, 12))[0] = point_in[0];
    ((real_T *)ssGetDWork(S, 12))[1] = 0.0;
    ((boolean_T *)ssGetDWork(S, 21))[0] = true;

    /* 'estimate_parabola:11' Px_last = estimator_init_struct.Px_last; */
    /* 'estimate_parabola:13' py_est_last = [point_in(2);0]; */
    ((real_T *)ssGetDWork(S, 14))[0] = point_in[1];
    ((real_T *)ssGetDWork(S, 14))[1] = 0.0;

    /* 'estimate_parabola:14' Py_last = estimator_init_struct.Py_last; */
    /* 'estimate_parabola:16' pz_est_last = [point_in(3);0]; */
    ((real_T *)ssGetDWork(S, 16))[0] = point_in[2];
    ((real_T *)ssGetDWork(S, 16))[1] = 0.0;

    /* 'estimate_parabola:17' Pz_last = estimator_init_struct.Pz_last; */
    ((real_T *)ssGetDWork(S, 13))[0] = b_estimator_init_struct->Px_last[0];
    ((real_T *)ssGetDWork(S, 15))[0] = b_estimator_init_struct->Py_last[0];
    ((real_T *)ssGetDWork(S, 17))[0] = b_estimator_init_struct->Pz_last[0];
    ((real_T *)ssGetDWork(S, 13))[1] = b_estimator_init_struct->Px_last[1];
    ((real_T *)ssGetDWork(S, 15))[1] = b_estimator_init_struct->Py_last[1];
    ((real_T *)ssGetDWork(S, 17))[1] = b_estimator_init_struct->Pz_last[1];
    ((real_T *)ssGetDWork(S, 13))[2] = b_estimator_init_struct->Px_last[2];
    ((real_T *)ssGetDWork(S, 15))[2] = b_estimator_init_struct->Py_last[2];
    ((real_T *)ssGetDWork(S, 17))[2] = b_estimator_init_struct->Pz_last[2];
    ((real_T *)ssGetDWork(S, 13))[3] = b_estimator_init_struct->Px_last[3];
    ((real_T *)ssGetDWork(S, 15))[3] = b_estimator_init_struct->Py_last[3];
    ((real_T *)ssGetDWork(S, 17))[3] = b_estimator_init_struct->Pz_last[3];

    /* 'estimate_parabola:19' estimations_last = struct(); */
    /* 'estimate_parabola:20' estimations_last.x0_est = point_in(1); */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).x0_est = point_in[0];

    /* 'estimate_parabola:21' estimations_last.vx0_est = 0; */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vx0_est = 0.0;

    /* 'estimate_parabola:22' estimations_last.y0_est = point_in(2); */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).y0_est = point_in[1];

    /* 'estimate_parabola:23' estimations_last.vy0_est = 0; */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vy0_est = 0.0;

    /* 'estimate_parabola:24' estimations_last.z0_est = point_in(3); */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).z0_est = point_in[2];

    /* 'estimate_parabola:25' estimations_last.vz0_est = 0; */
    (*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vz0_est = 0.0;

    /* 'estimate_parabola:27' point_in_last = zeros(3,1); */
    ((real_T *)ssGetDWork(S, 18))[0] = 0.0;
    ((real_T *)ssGetDWork(S, 18))[1] = 0.0;
    ((real_T *)ssGetDWork(S, 18))[2] = 0.0;
  }

  /* 'estimate_parabola:30' if (isequal(point_in,zeros(3,1)) || isequal(point_in,point_in_last)) */
  tmp[0] = 0.0;
  tmp[1] = 0.0;
  tmp[2] = 0.0;
  if (Chart1_isequal(point_in, tmp) || Chart1_isequal(point_in, &((real_T *)
        ssGetDWork(S, 18))[0])) {
    /* 'estimate_parabola:31' estimations = estimations_last; */
    *estimations = ((sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3))[0];
  } else {
    /* 'estimate_parabola:32' else */
    /* 'estimate_parabola:34' x_in = point_in(1); */
    /* 'estimate_parabola:35' y_in = point_in(2); */
    /* 'estimate_parabola:36' z_in = point_in(3)+g/2*t_in^2; */
    /* 'estimate_parabola:39' f1 = @(x) 1; */
    /* 'estimate_parabola:40' fx = @(x) x; */
    /* 'estimate_parabola:42' s_i = [ f1(t_in);... */
    /* 'estimate_parabola:43'              fx(t_in) ]; */
    /* 'estimate_parabola:46' q = estimator_init_struct.q; */
    /* 'estimate_parabola:48' kx_i = (Px_last*s_i)/(q + s_i'*Px_last*s_i); */
    b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 13))[3] +
      ((real_T *)ssGetDWork(S, 13))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S,
      13))[1] + ((real_T *)ssGetDWork(S, 13))[0])) + b_estimator_init_struct->q;

    /* 'estimate_parabola:49' Px_i = (1/q)*(Px_last - kx_i*s_i'*Px_last); */
    y_tmp = 1.0 / b_estimator_init_struct->q;

    /* 'estimate_parabola:50' px_est = px_est_last + kx_i*(x_in - s_i'*px_est_last); */
    kx_i[0] = (((real_T *)ssGetDWork(S, 13))[2] * t_in + ((real_T *)ssGetDWork(S,
      13))[0]) / b_estimator_init_struct_0;
    kx_i[1] = (((real_T *)ssGetDWork(S, 13))[3] * t_in + ((real_T *)ssGetDWork(S,
      13))[1]) / b_estimator_init_struct_0;
    b_estimator_init_struct_0 = point_in[0] - (t_in * ((real_T *)ssGetDWork(S,
      12))[1] + ((real_T *)ssGetDWork(S, 12))[0]);
    ((real_T *)ssGetDWork(S, 12))[0] = kx_i[0] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 12))[0];
    ((real_T *)ssGetDWork(S, 12))[1] = kx_i[1] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 12))[1];

    /* 'estimate_parabola:52' estimations.x0_est = px_est(1); */
    estimations->x0_est = ((real_T *)ssGetDWork(S, 12))[0];

    /* 'estimate_parabola:53' estimations.vx0_est = px_est(2); */
    estimations->vx0_est = ((real_T *)ssGetDWork(S, 12))[1];

    /* 'estimate_parabola:56' ky_i = (Py_last*s_i)/(q + s_i'*Py_last*s_i); */
    b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 15))[3] +
      ((real_T *)ssGetDWork(S, 15))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S,
      15))[1] + ((real_T *)ssGetDWork(S, 15))[0])) + b_estimator_init_struct->q;

    /* 'estimate_parabola:57' Py_i = (1/q)*(Py_last - ky_i*s_i'*Py_last); */
    /* 'estimate_parabola:58' py_est = py_est_last + ky_i*(y_in - s_i'*py_est_last); */
    ky_i[0] = (((real_T *)ssGetDWork(S, 15))[2] * t_in + ((real_T *)ssGetDWork(S,
      15))[0]) / b_estimator_init_struct_0;
    ky_i[1] = (((real_T *)ssGetDWork(S, 15))[3] * t_in + ((real_T *)ssGetDWork(S,
      15))[1]) / b_estimator_init_struct_0;
    b_estimator_init_struct_0 = point_in[1] - (t_in * ((real_T *)ssGetDWork(S,
      14))[1] + ((real_T *)ssGetDWork(S, 14))[0]);
    ((real_T *)ssGetDWork(S, 14))[0] = ky_i[0] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 14))[0];
    ((real_T *)ssGetDWork(S, 14))[1] = ky_i[1] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 14))[1];

    /* 'estimate_parabola:60' estimations.y0_est = py_est(1); */
    estimations->y0_est = ((real_T *)ssGetDWork(S, 14))[0];

    /* 'estimate_parabola:61' estimations.vy0_est = py_est(2); */
    estimations->vy0_est = ((real_T *)ssGetDWork(S, 14))[1];

    /* 'estimate_parabola:64' kz_i = (Pz_last*s_i)/(q + s_i'*Pz_last*s_i); */
    b_estimator_init_struct_0 = ((t_in * ((real_T *)ssGetDWork(S, 17))[3] +
      ((real_T *)ssGetDWork(S, 17))[2]) * t_in + (t_in * ((real_T *)ssGetDWork(S,
      17))[1] + ((real_T *)ssGetDWork(S, 17))[0])) + b_estimator_init_struct->q;

    /* 'estimate_parabola:65' Pz_i = (1/q)*(Pz_last - kz_i*s_i'*Pz_last); */
    /* 'estimate_parabola:66' pz_est = pz_est_last + kz_i*(z_in - s_i'*pz_est_last); */
    kz_i[0] = (((real_T *)ssGetDWork(S, 17))[2] * t_in + ((real_T *)ssGetDWork(S,
      17))[0]) / b_estimator_init_struct_0;
    kz_i[1] = (((real_T *)ssGetDWork(S, 17))[3] * t_in + ((real_T *)ssGetDWork(S,
      17))[1]) / b_estimator_init_struct_0;
    b_estimator_init_struct_0 = (t_in * t_in * 4.905 + point_in[2]) - (t_in *
      ((real_T *)ssGetDWork(S, 16))[1] + ((real_T *)ssGetDWork(S, 16))[0]);
    ((real_T *)ssGetDWork(S, 16))[0] = kz_i[0] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 16))[0];
    ((real_T *)ssGetDWork(S, 16))[1] = kz_i[1] * b_estimator_init_struct_0 +
      ((real_T *)ssGetDWork(S, 16))[1];

    /* 'estimate_parabola:68' estimations.z0_est = pz_est(1); */
    estimations->z0_est = ((real_T *)ssGetDWork(S, 16))[0];

    /* 'estimate_parabola:69' estimations.vz0_est = pz_est(2); */
    estimations->vz0_est = ((real_T *)ssGetDWork(S, 16))[1];

    /* 'estimate_parabola:72' px_est_last = px_est; */
    /* 'estimate_parabola:73' Px_last = Px_i; */
    for (i = 0; i < 2; i++) {
      kx_i_0[i] = kx_i[i];
      kx_i_0[i + 2] = kx_i[i] * t_in;
      b_estimator_init_struct_0 = kx_i_0[i + 2];
      tmp_0[i] = ((real_T *)ssGetDWork(S, 13))[i] - (b_estimator_init_struct_0 *
        ((real_T *)ssGetDWork(S, 13))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S,
        13))[0]);
      tmp_0[i + 2] = ((real_T *)ssGetDWork(S, 13))[i + 2] -
        (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 13))[3] + kx_i_0[i]
         * ((real_T *)ssGetDWork(S, 13))[2]);
    }

    ((real_T *)ssGetDWork(S, 13))[0] = y_tmp * tmp_0[0];
    ((real_T *)ssGetDWork(S, 13))[1] = y_tmp * tmp_0[1];
    ((real_T *)ssGetDWork(S, 13))[2] = y_tmp * tmp_0[2];
    ((real_T *)ssGetDWork(S, 13))[3] = y_tmp * tmp_0[3];

    /* 'estimate_parabola:74' py_est_last = py_est; */
    /* 'estimate_parabola:75' Py_last = Py_i; */
    for (i = 0; i < 2; i++) {
      kx_i_0[i] = ky_i[i];
      kx_i_0[i + 2] = ky_i[i] * t_in;
      b_estimator_init_struct_0 = kx_i_0[i + 2];
      tmp_0[i] = ((real_T *)ssGetDWork(S, 15))[i] - (b_estimator_init_struct_0 *
        ((real_T *)ssGetDWork(S, 15))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S,
        15))[0]);
      tmp_0[i + 2] = ((real_T *)ssGetDWork(S, 15))[i + 2] -
        (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 15))[3] + kx_i_0[i]
         * ((real_T *)ssGetDWork(S, 15))[2]);
    }

    ((real_T *)ssGetDWork(S, 15))[0] = y_tmp * tmp_0[0];
    ((real_T *)ssGetDWork(S, 15))[1] = y_tmp * tmp_0[1];
    ((real_T *)ssGetDWork(S, 15))[2] = y_tmp * tmp_0[2];
    ((real_T *)ssGetDWork(S, 15))[3] = y_tmp * tmp_0[3];

    /* 'estimate_parabola:76' pz_est_last = pz_est; */
    /* 'estimate_parabola:77' Pz_last = Pz_i; */
    for (i = 0; i < 2; i++) {
      kx_i_0[i] = kz_i[i];
      kx_i_0[i + 2] = kz_i[i] * t_in;
      b_estimator_init_struct_0 = kx_i_0[i + 2];
      tmp_0[i] = ((real_T *)ssGetDWork(S, 17))[i] - (b_estimator_init_struct_0 *
        ((real_T *)ssGetDWork(S, 17))[1] + kx_i_0[i] * ((real_T *)ssGetDWork(S,
        17))[0]);
      tmp_0[i + 2] = ((real_T *)ssGetDWork(S, 17))[i + 2] -
        (b_estimator_init_struct_0 * ((real_T *)ssGetDWork(S, 17))[3] + kx_i_0[i]
         * ((real_T *)ssGetDWork(S, 17))[2]);
    }

    ((real_T *)ssGetDWork(S, 17))[0] = y_tmp * tmp_0[0];
    ((real_T *)ssGetDWork(S, 17))[1] = y_tmp * tmp_0[1];
    ((real_T *)ssGetDWork(S, 17))[2] = y_tmp * tmp_0[2];
    ((real_T *)ssGetDWork(S, 17))[3] = y_tmp * tmp_0[3];

    /* 'estimate_parabola:79' if estimations_last.x0_est ~= estimations.x0_est ||... */
    /* 'estimate_parabola:80'          estimations_last.y0_est ~= estimations.y0_est ||... */
    /* 'estimate_parabola:81'          estimations_last.z0_est ~= estimations.z0_est ||... */
    /* 'estimate_parabola:82'          estimations_last.vx0_est ~= estimations.vx0_est ||... */
    /* 'estimate_parabola:83'          estimations_last.vy0_est ~= estimations.vy0_est ||... */
    /* 'estimate_parabola:84'          estimations_last.vz0_est ~= estimations.vz0_est */
    if (((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).x0_est !=
         ((real_T *)ssGetDWork(S, 12))[0]) ||
        ((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).y0_est !=
         ((real_T *)ssGetDWork(S, 14))[0]) ||
        ((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).z0_est !=
         ((real_T *)ssGetDWork(S, 16))[0]) ||
        ((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vx0_est !=
         ((real_T *)ssGetDWork(S, 12))[1]) ||
        ((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vy0_est !=
         ((real_T *)ssGetDWork(S, 14))[1]) ||
        ((*(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3)).vz0_est !=
         ((real_T *)ssGetDWork(S, 16))[1])) {
      /* 'estimate_parabola:85' prediction_update = 1; */
      *prediction_update = 1.0;
    }

    /* 'estimate_parabola:88' estimations_last = estimations; */
    ((sDzCfTiIapKTB3mCVdDRUZC_Chart1_T *)ssGetDWork(S, 3))[0] = *estimations;
  }

  /* 'estimate_parabola:91' point_in_last = point_in; */
  ((real_T *)ssGetDWork(S, 18))[0] = point_in[0];
  ((real_T *)ssGetDWork(S, 18))[1] = point_in[1];
  ((real_T *)ssGetDWork(S, 18))[2] = point_in[2];
}

/* System initialize for function-call system: '<S1>/estimate_parabola' */
void Chart1_estimate_parabola_Init(SimStruct * const S,
  B_estimate_parabola_Chart1_T *localB)
{
  /* SystemInitialize for MATLAB Function: '<S2>/Parabola Estimator' */
  ((boolean_T *)ssGetDWork(S, 19))[0] = false;
  ((boolean_T *)ssGetDWork(S, 21))[0] = false;

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

  /* SystemInitialize for Outport: '<S2>/pred_update' */
  localB->prediction_update = 0.0;
}

/* Output and update for function-call system: '<S1>/estimate_parabola' */
void Chart1_estimate_parabola(SimStruct * const S, real_T rtu_t_in, real_T
  rtu_t_start, const real_T rtu_point_in[3], real_T rtu_init, real_T
  rtu_init_number_of_samples, B_estimate_parabola_Chart1_T *localB)
{
  real_T t_for_est;
  real_T t_move_start;
  real_T t_start_g;
  sDzCfTiIapKTB3mCVdDRUZC_Chart1_T estimations;

  /* MATLAB Function: '<S2>/Parabola Estimator' */
  /* MATLAB Function 'Chart1/estimate_parabola/Parabola Estimator': '<S3>:1' */
  /* '<S3>:1:3' t_for_est = t_in-t_start; */
  t_for_est = rtu_t_in - rtu_t_start;

  /* '<S3>:1:4' t_move_start = timing.T_optitrack*init_number_of_samples; */
  t_move_start = 0.004 * rtu_init_number_of_samples;

  /* '<S3>:1:5' t_start_g = t_start + t_move_start; */
  t_start_g = rtu_t_start + t_move_start;

  /* '<S3>:1:6' prediction_update = 0; */
  localB->prediction_update = 0.0;

  /* '<S3>:1:9' if init || isempty(t_catch_predict_p) */
  if ((rtu_init != 0.0) || (!((boolean_T *)ssGetDWork(S, 19))[0])) {
    /* '<S3>:1:10' use_pred_p = 0; */
    ((real_T *)ssGetDWork(S, 4))[0] = 0.0;

    /* '<S3>:1:11' t_catch_predict_p = [t_start_g,t_start_g+1]; */
    ((real_T *)ssGetDWork(S, 5))[0] = t_start_g;
    ((real_T *)ssGetDWork(S, 5))[1] = t_start_g + 1.0;
    ((boolean_T *)ssGetDWork(S, 19))[0] = true;

    /* '<S3>:1:12' t_zd = t_move_start+0.5; */
    ((real_T *)ssGetDWork(S, 6))[0] = t_move_start + 0.5;

    /* '<S3>:1:13' i = 0; */
    ((real_T *)ssGetDWork(S, 7))[0] = 0.0;

    /* '<S3>:1:14' pd__ = zeros(1,3); */
    /* '<S3>:1:15' pd_p__ = zeros(1,3); */
    ((real_T *)ssGetDWork(S, 8))[0] = 0.0;
    ((real_T *)ssGetDWork(S, 9))[0] = 0.0;
    ((real_T *)ssGetDWork(S, 8))[1] = 0.0;
    ((real_T *)ssGetDWork(S, 9))[1] = 0.0;
    ((real_T *)ssGetDWork(S, 8))[2] = 0.0;
    ((real_T *)ssGetDWork(S, 9))[2] = 0.0;

    /* '<S3>:1:16' t_in_last = t_in; */
    ((real_T *)ssGetDWork(S, 10))[0] = rtu_t_in;

    /* '<S3>:1:17' t_cnt=0; */
    ((real_T *)ssGetDWork(S, 11))[0] = 0.0;

    /* '<S3>:1:18' blocked=false; */
    ((boolean_T *)ssGetDWork(S, 20))[0] = false;
  }

  /* '<S3>:1:21' if i == 0 */
  if (((real_T *)ssGetDWork(S, 7))[0] == 0.0) {
    /* '<S3>:1:22' if t_in >= t_catch_predict_p(1) && t_in <= t_catch_predict_p(2) && ~blocked */
    if ((rtu_t_in >= ((real_T *)ssGetDWork(S, 5))[0]) && (rtu_t_in <= ((real_T *)
          ssGetDWork(S, 5))[1]) && (!((boolean_T *)ssGetDWork(S, 20))[0])) {
      /* '<S3>:1:23' blocked=true; */
      ((boolean_T *)ssGetDWork(S, 20))[0] = true;

      /* '<S3>:1:24' use_pred_p = 1; */
      ((real_T *)ssGetDWork(S, 4))[0] = 1.0;

      /* '<S3>:1:25' g = 9.81; */
      /* '<S3>:1:27' [estimations,prediction_update]=estimate_parabola(t_for_est,point_in,estimator_init_struct,init); */
      Chart1_estimate_parabola_f(t_for_est, rtu_point_in,
        &Chart1_ConstP.ParabolaEstimator_estimator_init_struct, rtu_init,
        &estimations, &localB->prediction_update, (SimStruct * const )S);

      /* '<S3>:1:28' x0_est = estimations.x0_est; */
      /* '<S3>:1:29' vx0_est = estimations.vx0_est; */
      /* '<S3>:1:30' y0_est = estimations.y0_est; */
      /* '<S3>:1:31' vy0_est = estimations.vy0_est; */
      /* '<S3>:1:32' z0_est = estimations.z0_est; */
      /* '<S3>:1:33' vz0_est = estimations.vz0_est; */
      /* '<S3>:1:36' x = @(ti,x0_t,vx0_t) ( x0_t + vx0_t*ti ); */
      /* '<S3>:1:37' y = @(ti,y0_t,vy0_t) ( y0_t + vy0_t*ti ); */
      /* '<S3>:1:38' z = @(ti,z0_t,vz0_t) ( z0_t + vz0_t*ti - (g/2)*ti.^2 ); */
      /* '<S3>:1:41' x_p = @(vx0_t) ( vx0_t ); */
      /* '<S3>:1:42' y_p = @(vy0_t) ( vy0_t ); */
      /* '<S3>:1:43' z_p = @(ti,vz0_t) ( vz0_t - g*ti ); */
      /* '<S3>:1:46' za = -(g/2); */
      /* '<S3>:1:47' zb = vz0_est; */
      /* '<S3>:1:48' zc = z0_est; */
      /* '<S3>:1:50' descriminant = -4*za*zc+4*za*height_of_catch+zb^2; */
      t_for_est = (19.62 * estimations.z0_est + -17.658) + estimations.vz0_est *
        estimations.vz0_est;

      /* '<S3>:1:51' if descriminant >= 0 */
      if (t_for_est >= 0.0) {
        /* '<S3>:1:52' t_zd = -(zb+sqrt(descriminant))/(2*za); */
        ((real_T *)ssGetDWork(S, 6))[0] = -(estimations.vz0_est + std::sqrt
          (t_for_est)) / -9.81;
      } else {
        /* '<S3>:1:53' else */
      }

      /* '<S3>:1:58' x_out = x(t_zd,x0_est,vx0_est); */
      /* '<S3>:1:59' y_out = y(t_zd,y0_est,vy0_est); */
      /* '<S3>:1:60' z_out = z(t_zd,z0_est,vz0_est); */
      /* '<S3>:1:61' pd__ = [x_out,y_out,z_out]; */
      ((real_T *)ssGetDWork(S, 8))[0] = estimations.vx0_est * ((real_T *)
        ssGetDWork(S, 6))[0] + estimations.x0_est;
      ((real_T *)ssGetDWork(S, 8))[1] = estimations.vy0_est * ((real_T *)
        ssGetDWork(S, 6))[0] + estimations.y0_est;
      ((real_T *)ssGetDWork(S, 8))[2] = (estimations.vz0_est * ((real_T *)
        ssGetDWork(S, 6))[0] + estimations.z0_est) - ((real_T *)ssGetDWork(S, 6))
        [0] * ((real_T *)ssGetDWork(S, 6))[0] * 4.905;

      /* '<S3>:1:64' x_out_p = x_p(vx0_est); */
      /* '<S3>:1:65' y_out_p = y_p(vy0_est); */
      /* '<S3>:1:66' z_out_p = z_p(t_zd,vz0_est); */
      /* '<S3>:1:67' pd_p__ = [x_out_p,y_out_p,z_out_p]*(-1); */
      ((real_T *)ssGetDWork(S, 9))[0] = -estimations.vx0_est;
      ((real_T *)ssGetDWork(S, 9))[1] = -estimations.vy0_est;
      ((real_T *)ssGetDWork(S, 9))[2] = -(estimations.vz0_est - 9.81 * ((real_T *)
        ssGetDWork(S, 6))[0]);

      /* '<S3>:1:70' t_catch_predict_p = [t_start_g,t_zd+t_start]; */
      ((real_T *)ssGetDWork(S, 5))[0] = t_start_g;
      ((real_T *)ssGetDWork(S, 5))[1] = ((real_T *)ssGetDWork(S, 6))[0] +
        rtu_t_start;
    } else {
      /* '<S3>:1:71' else */
      /* '<S3>:1:72' use_pred_p = 0; */
      ((real_T *)ssGetDWork(S, 4))[0] = 0.0;

      /* '<S3>:1:73' [estimations,~]=estimate_parabola(t_for_est,point_in,estimator_init_struct,init); */
      Chart1_estimate_parabola_f(t_for_est, rtu_point_in,
        &Chart1_ConstP.ParabolaEstimator_estimator_init_struct, rtu_init,
        &estimations, &t_start_g, (SimStruct * const )S);

      /* '<S3>:1:73' ~ */
      /* '<S3>:1:75' x_out = 0; */
      /* '<S3>:1:76' y_out = 0; */
      /* '<S3>:1:77' z_out = 0; */
      /* '<S3>:1:78' pd__ = [x_out,y_out,z_out]; */
      /* '<S3>:1:80' x_out_p = 0; */
      /* '<S3>:1:81' y_out_p = 0; */
      /* '<S3>:1:82' z_out_p = 0; */
      /* '<S3>:1:83' pd_p__ = [x_out_p,y_out_p,z_out_p]*(-1); */
      ((real_T *)ssGetDWork(S, 8))[0] = 0.0;
      ((real_T *)ssGetDWork(S, 9))[0] = -0.0;
      ((real_T *)ssGetDWork(S, 8))[1] = 0.0;
      ((real_T *)ssGetDWork(S, 9))[1] = -0.0;
      ((real_T *)ssGetDWork(S, 8))[2] = 0.0;
      ((real_T *)ssGetDWork(S, 9))[2] = -0.0;
    }
  }

  /* '<S3>:1:88' use_pred = use_pred_p; */
  localB->use_pred = ((real_T *)ssGetDWork(S, 4))[0];

  /* '<S3>:1:89' t_catch_predict = t_catch_predict_p; */
  localB->t_catch_predict[0] = ((real_T *)ssGetDWork(S, 5))[0];
  localB->t_catch_predict[1] = ((real_T *)ssGetDWork(S, 5))[1];

  /* '<S3>:1:91' pd = pd__; */
  /* '<S3>:1:92' pd_p = pd_p__; */
  localB->pd[0] = ((real_T *)ssGetDWork(S, 8))[0];
  localB->pd_p[0] = ((real_T *)ssGetDWork(S, 9))[0];
  localB->pd[1] = ((real_T *)ssGetDWork(S, 8))[1];
  localB->pd_p[1] = ((real_T *)ssGetDWork(S, 9))[1];
  localB->pd[2] = ((real_T *)ssGetDWork(S, 8))[2];
  localB->pd_p[2] = ((real_T *)ssGetDWork(S, 9))[2];

  /* '<S3>:1:94' i = i+1; */
  ((real_T *)ssGetDWork(S, 7))[0] = ((real_T *)ssGetDWork(S, 7))[0] + 1.0;

  /* '<S3>:1:96' if i == timing.cycle_time_ratio */
  if (((real_T *)ssGetDWork(S, 7))[0] == 80.0) {
    /* '<S3>:1:97' i = 0; */
    ((real_T *)ssGetDWork(S, 7))[0] = 0.0;
  }

  /* '<S3>:1:100' if t_in == t_in_last */
  if (rtu_t_in == ((real_T *)ssGetDWork(S, 10))[0]) {
    /* '<S3>:1:101' t_cnt=t_cnt+1; */
    ((real_T *)ssGetDWork(S, 11))[0] = ((real_T *)ssGetDWork(S, 11))[0] + 1.0;
  } else {
    /* '<S3>:1:102' else */
    /* '<S3>:1:103' t_cnt=0; */
    ((real_T *)ssGetDWork(S, 11))[0] = 0.0;
  }

  /* End of MATLAB Function: '<S2>/Parabola Estimator' */
}

/* Termination for function-call system: '<S1>/estimate_parabola' */
void Chart1_estimate_parabola_Term(SimStruct *const S)
{
}

/*
 * Function for Chart: '<Root>/Chart1'
 * function valid  = isBallValueValid(data_point)
 */
static boolean_T Chart1_isBallValueValid(const real_T data_point[3])
{
  boolean_T b;

  /* MATLAB Function 'isBallValueValid': '<S1>:66' */
  /* '<S1>:66:2' valid = ~(data_point(1) == 0 && data_point(2) == 0 && data_point(3) == 0); */
  if ((data_point[0] == 0.0) && (data_point[1] == 0.0) && (data_point[2] == 0.0))
  {
    b = true;
  } else {
    b = false;
  }

  return !b;
}

/* System initialize for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  if (ssIsFirstInitCond(S)) {
    B_Chart1_T *_rtB;
    _rtB = ((B_Chart1_T *) ssGetLocalBlockIO(S));
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<Root>/Chart1' incorporates:
     *  SubSystem: '<S1>/estimate_parabola'
     */
    Chart1_estimate_parabola_Init((SimStruct * const )S,
      &_rtB->estimate_parabola);
  } else {                             /* SystemReset for Chart: '<Root>/Chart1' */
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_NO_ACTIVE_CHILD;
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

  Chart1_malloc(S);
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
  B_Chart1_T *_rtB;
  _rtB = ((B_Chart1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 0, 0)) {
    /* Chart: '<Root>/Chart1' */
    if (((uint32_T *)ssGetDWork(S, 0))[0] < 262143U) {
      ((uint32_T *)ssGetDWork(S, 0))[0] = ((uint32_T *)ssGetDWork(S, 0))[0] + 1U;
    }

    /* Gateway: Chart1 */
    /* During: Chart1 */
    if (((uint8_T *)ssGetDWork(S, 1))[0] == 0U) {
      /* Entry: Chart1 */
      ((uint8_T *)ssGetDWork(S, 1))[0] = 1U;

      /* Entry Internal: Chart1 */
      /* Transition: '<S1>:27' */
      ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

      /* Entry 'INIT': '<S1>:95' */
      /* '<S1>:95:1' state=0; */
      _rtB->state = 0.0;

      /* '<S1>:95:1' use_pred=0; */
      _rtB->use_pred = 0.0;

      /* '<S1>:95:1' trajectory_update = 0; */
      _rtB->trajectory_update = 0.0;

      /* '<S1>:95:4' t_catch_predict=[0,0]; */
      _rtB->t_catch_predict[0] = 0.0;
      _rtB->t_catch_predict[1] = 0.0;
    } else {
      switch (((uint8_T *)ssGetDWork(S, 2))[0]) {
       case Chart1_IN_CATCH:
        _rtB->state = 2.0;

        /* During 'CATCH': '<S1>:17' */
        /* '<S1>:128:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:128' */
          /* Exit 'CATCH': '<S1>:17' */
          /* '<S1>:17:4' use_pred=0; */
          /* '<S1>:17:4' trajectory_update = 0; */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

          /* Entry 'INIT': '<S1>:95' */
          /* '<S1>:95:1' state=0; */
          _rtB->state = 0.0;

          /* '<S1>:95:1' use_pred=0; */
          _rtB->use_pred = 0.0;

          /* '<S1>:95:1' trajectory_update = 0; */
          _rtB->trajectory_update = 0.0;

          /* '<S1>:95:4' t_catch_predict=[0,0]; */
          _rtB->t_catch_predict[0] = 0.0;
          _rtB->t_catch_predict[1] = 0.0;
        } else {
          /* '<S1>:20:1' sf_internal_predicateOutput = t_in > t_catch_predict(2); */
          if (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] >
              _rtB->t_catch_predict[1]) {
            /* Transition: '<S1>:20' */
            /* Exit 'CATCH': '<S1>:17' */
            /* '<S1>:17:4' use_pred=0; */
            _rtB->use_pred = 0.0;

            /* '<S1>:17:4' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_NO_VALID_BALL_VALUE;
            ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

            /* Entry 'NO_VALID_BALL_VALUE': '<S1>:79' */
            /* '<S1>:79:1' state=3; */
            _rtB->state = 3.0;
          } else {
            /* '<S1>:17:3' [pd,pd_p,use_pred,t_catch_predict,trajectory_update] = estimate_parabola(t_in,t_start,point_in,0,init_number_of_samples); */
            /* Simulink Function 'estimate_parabola': '<S1>:52' */
            _rtB->t_in = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
            _rtB->t_start_a = _rtB->t_start;
            _rtB->point_in[0] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [0];
            _rtB->point_in[1] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [1];
            _rtB->point_in[2] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [2];
            _rtB->init = 0.0;
            _rtB->init_number_of_samples = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 4))[0];

            /* Outputs for Function Call SubSystem: '<S1>/estimate_parabola' */
            Chart1_estimate_parabola((SimStruct * const )S, _rtB->t_in,
              _rtB->t_start_a, _rtB->point_in, _rtB->init,
              _rtB->init_number_of_samples, &_rtB->estimate_parabola);

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
            _rtB->trajectory_update = _rtB->estimate_parabola.prediction_update;
          }
        }
        break;

       case Chart1_IN_GO_TO_START_FROM_NO_CATCH:
        _rtB->state = 4.0;

        /* During 'GO_TO_START_FROM_NO_CATCH': '<S1>:87' */
        /* '<S1>:127:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:127' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

          /* Entry 'INIT': '<S1>:95' */
          /* '<S1>:95:1' state=0; */
          _rtB->state = 0.0;

          /* '<S1>:95:1' use_pred=0; */
          _rtB->use_pred = 0.0;

          /* '<S1>:95:1' trajectory_update = 0; */
          _rtB->trajectory_update = 0.0;

          /* '<S1>:95:4' t_catch_predict=[0,0]; */
          _rtB->t_catch_predict[0] = 0.0;
          _rtB->t_catch_predict[1] = 0.0;
        } else {
          /* '<S1>:25:1' sf_internal_predicateOutput = after(10,sec); */
          if (((uint32_T *)ssGetDWork(S, 0))[0] >= 200000U) {
            /* Transition: '<S1>:25' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_READY;

            /* Entry 'READY': '<S1>:16' */
            /* '<S1>:16:1' state=1; */
            _rtB->state = 1.0;

            /* '<S1>:16:1' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
          } else {
            /* '<S1>:87:3' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
          }
        }
        break;

       case Chart1_IN_INIT:
        _rtB->state = 0.0;

        /* During 'INIT': '<S1>:95' */
        /* '<S1>:107:1' sf_internal_predicateOutput = init_goto_start && motion_enable; */
        if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] != 0.0) &&
            (*((const real_T **)ssGetInputPortSignalPtrs(S, 5))[0] != 0.0)) {
          /* Transition: '<S1>:107' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT_GOTO_START;
          ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

          /* Entry 'INIT_GOTO_START': '<S1>:103' */
          /* '<S1>:103:1' trajectory_update = 1; */
          _rtB->trajectory_update = 1.0;

          /* '<S1>:103:1' t_catch_predict=[t_in,t_in+10]; */
          _rtB->t_catch_predict[0] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 0))[0];
          _rtB->t_catch_predict[1] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 0))[0] + 10.0;

          /* '<S1>:103:3' pd=positions.start; */
          /* '<S1>:103:4' pd_p=positions.start_p; */
          _rtB->pd[0] = 0.4;
          _rtB->pd_p[0] = 0.0;
          _rtB->pd[1] = 0.0;
          _rtB->pd_p[1] = 0.0;
          _rtB->pd[2] = 0.95;
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart1_IN_INIT_GOTO_START:
        /* During 'INIT_GOTO_START': '<S1>:103' */
        /* '<S1>:126:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:126' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

          /* Entry 'INIT': '<S1>:95' */
          /* '<S1>:95:1' state=0; */
          _rtB->state = 0.0;

          /* '<S1>:95:1' use_pred=0; */
          _rtB->use_pred = 0.0;

          /* '<S1>:95:1' trajectory_update = 0; */
          _rtB->trajectory_update = 0.0;

          /* '<S1>:95:4' t_catch_predict=[0,0]; */
          _rtB->t_catch_predict[0] = 0.0;
          _rtB->t_catch_predict[1] = 0.0;
        } else {
          /* '<S1>:123:1' sf_internal_predicateOutput = after(10,sec); */
          if (((uint32_T *)ssGetDWork(S, 0))[0] >= 200000U) {
            /* Transition: '<S1>:123' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_READY;

            /* Entry 'READY': '<S1>:16' */
            /* '<S1>:16:1' state=1; */
            _rtB->state = 1.0;

            /* '<S1>:16:1' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
          } else {
            /* '<S1>:103:4' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
          }
        }
        break;

       case Chart1_IN_NO_VALID_BALL_VALUE:
        _rtB->state = 3.0;

        /* During 'NO_VALID_BALL_VALUE': '<S1>:79' */
        /* '<S1>:129:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:129' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

          /* Entry 'INIT': '<S1>:95' */
          /* '<S1>:95:1' state=0; */
          _rtB->state = 0.0;

          /* '<S1>:95:1' use_pred=0; */
          _rtB->use_pred = 0.0;

          /* '<S1>:95:1' trajectory_update = 0; */
          _rtB->trajectory_update = 0.0;

          /* '<S1>:95:4' t_catch_predict=[0,0]; */
          _rtB->t_catch_predict[0] = 0.0;
          _rtB->t_catch_predict[1] = 0.0;
        } else {
          /* '<S1>:88:1' sf_internal_predicateOutput = after(3,sec); */
          if (((uint32_T *)ssGetDWork(S, 0))[0] >= 60000U) {
            /* Transition: '<S1>:88' */
            ((uint8_T *)ssGetDWork(S, 2))[0] =
              Chart1_IN_GO_TO_START_FROM_NO_CATCH;
            ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

            /* Entry 'GO_TO_START_FROM_NO_CATCH': '<S1>:87' */
            /* '<S1>:87:1' trajectory_update = 1; */
            _rtB->trajectory_update = 1.0;

            /* '<S1>:87:1' state=4; */
            _rtB->state = 4.0;

            /* '<S1>:87:2' t_catch_predict=[t_in,t_in+10]; */
            _rtB->t_catch_predict[0] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 0))[0];
            _rtB->t_catch_predict[1] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 0))[0] + 10.0;

            /* '<S1>:87:4' pd=positions.start; */
            /* '<S1>:87:5' pd_p=positions.start_p; */
            _rtB->pd[0] = 0.4;
            _rtB->pd_p[0] = 0.0;
            _rtB->pd[1] = 0.0;
            _rtB->pd_p[1] = 0.0;
            _rtB->pd[2] = 0.95;
            _rtB->pd_p[2] = 0.0;
          }
        }
        break;

       default:
        _rtB->state = 1.0;

        /* During 'READY': '<S1>:16' */
        /* '<S1>:111:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:111' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_INIT;

          /* Entry 'INIT': '<S1>:95' */
          /* '<S1>:95:1' state=0; */
          _rtB->state = 0.0;

          /* '<S1>:95:1' use_pred=0; */
          _rtB->use_pred = 0.0;

          /* '<S1>:95:1' trajectory_update = 0; */
          _rtB->trajectory_update = 0.0;

          /* '<S1>:95:4' t_catch_predict=[0,0]; */
          _rtB->t_catch_predict[0] = 0.0;
          _rtB->t_catch_predict[1] = 0.0;
        } else {
          /* '<S1>:26:1' sf_internal_predicateOutput = isBallValueValid(point_in); */
          if (Chart1_isBallValueValid(*(const real_T **)ssGetInputPortSignalPtrs
               (S, 1))) {
            /* Transition: '<S1>:26' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart1_IN_CATCH;

            /* Entry 'CATCH': '<S1>:17' */
            /* '<S1>:17:1' state=2; */
            _rtB->state = 2.0;

            /* '<S1>:17:1' t_start=t_in; */
            _rtB->t_start = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];

            /* '<S1>:17:1' [pd,pd_p,use_pred,t_catch_predict,trajectory_update] = estimate_parabola(t_in,t_in,point_in,1,init_number_of_samples); */
            /* Simulink Function 'estimate_parabola': '<S1>:52' */
            _rtB->t_in = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];
            _rtB->t_start_a = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
              [0];
            _rtB->point_in[0] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [0];
            _rtB->point_in[1] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [1];
            _rtB->point_in[2] = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
              [2];
            _rtB->init = 1.0;
            _rtB->init_number_of_samples = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 4))[0];

            /* Outputs for Function Call SubSystem: '<S1>/estimate_parabola' */
            Chart1_estimate_parabola((SimStruct * const )S, _rtB->t_in,
              _rtB->t_start_a, _rtB->point_in, _rtB->init,
              _rtB->init_number_of_samples, &_rtB->estimate_parabola);

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
            _rtB->trajectory_update = _rtB->estimate_parabola.prediction_update;
          }
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart1' */

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->pd[0];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->pd_p[0];

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[1] = _rtB->pd[1];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[1] = _rtB->pd_p[1];

    /* Outport: '<Root>/pd' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[2] = _rtB->pd[2];

    /* Outport: '<Root>/pd_p' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[2] = _rtB->pd_p[2];

    /* Outport: '<Root>/t_catch_predict' */
    ((real_T *)ssGetOutputPortSignal(S, 3))[0] = _rtB->t_catch_predict[0];
    ((real_T *)ssGetOutputPortSignal(S, 3))[1] = _rtB->t_catch_predict[1];

    /* Outport: '<Root>/state' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->state;

    /* Outport: '<Root>/use_pred' */
    ((real_T *)ssGetOutputPortSignal(S, 4))[0] = _rtB->use_pred;

    /* Outport: '<Root>/t_start' */
    ((real_T *)ssGetOutputPortSignal(S, 5))[0] = _rtB->t_start;

    /* Outport: '<Root>/trajectory_update' */
    ((real_T *)ssGetOutputPortSignal(S, 6))[0] = _rtB->trajectory_update;
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
#  include "Chart1_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 7))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* outport number: 3 */
  if (!ssSetOutputPortMatrixDimensions(S, 3, 1, 2))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 3, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 3, 0.0);
  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* outport number: 4 */
  if (!ssSetOutputPortVectorDimension(S, 4, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 4, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 4, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 4, 0.0);
  ssSetOutputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

  /* outport number: 5 */
  if (!ssSetOutputPortVectorDimension(S, 5, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 5, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 5, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 5, 0.0);
  ssSetOutputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);

  /* outport number: 6 */
  if (!ssSetOutputPortVectorDimension(S, 6, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 6, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 6, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 6, 0.0);
  ssSetOutputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 6))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.004);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 3))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 5.0E-5);
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
    ssSetInputPortSampleTime(S, 2, 5.0E-5);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 5.0E-5);
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
    ssSetInputPortSampleTime(S, 4, 5.0E-5);
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
    ssSetInputPortSampleTime(S, 5, 5.0E-5);
    ssSetInputPortOffsetTime(S, 5, 0.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 22)) {
    return;
  }

  /* '<Root>/Chart1': DWORK3 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* '<Root>/Chart1': DWORK1 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT8);

  /* '<Root>/Chart1': DWORK2 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_UINT8);

  /* '<S2>/Parabola Estimator': DWORK18 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 1);

#if SS_SFCN_FOR_SIM

  {
    int id = ssRegisterDataType(S, "sDzCfTiIapKTB3mCVdDRUZC_Chart1_T");
    if (id == INVALID_DTYPE_ID )
      return;
    if (!ssSetDataTypeSize(S, id, sizeof(sDzCfTiIapKTB3mCVdDRUZC_Chart1_T)))
      return;
    ssSetDWorkDataType(S, 3, id);
  }

#endif

  /* '<S2>/Parabola Estimator': DWORK1 */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 1);

  /* '<S2>/Parabola Estimator': DWORK2 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 2);

  /* '<S2>/Parabola Estimator': DWORK4 */
  ssSetDWorkName(S, 6, "DWORK6");
  ssSetDWorkWidth(S, 6, 1);

  /* '<S2>/Parabola Estimator': DWORK5 */
  ssSetDWorkName(S, 7, "DWORK7");
  ssSetDWorkWidth(S, 7, 1);

  /* '<S2>/Parabola Estimator': DWORK6 */
  ssSetDWorkName(S, 8, "DWORK8");
  ssSetDWorkWidth(S, 8, 3);

  /* '<S2>/Parabola Estimator': DWORK7 */
  ssSetDWorkName(S, 9, "DWORK9");
  ssSetDWorkWidth(S, 9, 3);

  /* '<S2>/Parabola Estimator': DWORK8 */
  ssSetDWorkName(S, 10, "DWORK10");
  ssSetDWorkWidth(S, 10, 1);

  /* '<S2>/Parabola Estimator': DWORK9 */
  ssSetDWorkName(S, 11, "DWORK11");
  ssSetDWorkWidth(S, 11, 1);

  /* '<S2>/Parabola Estimator': DWORK11 */
  ssSetDWorkName(S, 12, "DWORK12");
  ssSetDWorkWidth(S, 12, 2);

  /* '<S2>/Parabola Estimator': DWORK13 */
  ssSetDWorkName(S, 13, "DWORK13");
  ssSetDWorkWidth(S, 13, 4);

  /* '<S2>/Parabola Estimator': DWORK14 */
  ssSetDWorkName(S, 14, "DWORK14");
  ssSetDWorkWidth(S, 14, 2);

  /* '<S2>/Parabola Estimator': DWORK15 */
  ssSetDWorkName(S, 15, "DWORK15");
  ssSetDWorkWidth(S, 15, 4);

  /* '<S2>/Parabola Estimator': DWORK16 */
  ssSetDWorkName(S, 16, "DWORK16");
  ssSetDWorkWidth(S, 16, 2);

  /* '<S2>/Parabola Estimator': DWORK17 */
  ssSetDWorkName(S, 17, "DWORK17");
  ssSetDWorkWidth(S, 17, 4);

  /* '<S2>/Parabola Estimator': DWORK19 */
  ssSetDWorkName(S, 18, "DWORK18");
  ssSetDWorkWidth(S, 18, 3);

  /* '<S2>/Parabola Estimator': DWORK3 */
  ssSetDWorkName(S, 19, "DWORK19");
  ssSetDWorkWidth(S, 19, 1);
  ssSetDWorkDataType(S, 19, SS_BOOLEAN);

  /* '<S2>/Parabola Estimator': DWORK10 */
  ssSetDWorkName(S, 20, "DWORK20");
  ssSetDWorkWidth(S, 20, 1);
  ssSetDWorkDataType(S, 20, SS_BOOLEAN);

  /* '<S2>/Parabola Estimator': DWORK12 */
  ssSetDWorkName(S, 21, "DWORK21");
  ssSetDWorkWidth(S, 21, 1);
  ssSetDWorkDataType(S, 21, SS_BOOLEAN);

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
  ssSetSampleTime(S, 0, 5.0E-5);
  ssSetSampleTime(S, 1, 0.004);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               Chart1_sf

extern "C" {

# include "cg_sfun.h"

}
#endif                                 /* defined(MATLAB_MEX_FILE) */
