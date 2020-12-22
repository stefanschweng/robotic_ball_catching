/*
 * Chart2_sf.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Chart2_sf".
 *
 * Model version              : 1.3679
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct 13 22:10:48 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Chart2_sf_h_
#define RTW_HEADER_Chart2_sf_h_
#include <string.h>
#include <stddef.h>
#ifndef Chart2_sf_COMMON_INCLUDES_
# define Chart2_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                Chart2_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* Chart2_sf_COMMON_INCLUDES_ */

#include "Chart2_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* user code (top of header file) */
#define fflush(stdout)
#define printf(...)                    m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG,__VA_ARGS__)

/* Block signals (default storage) */
typedef struct {
  real_T state;                        /* '<Root>/Chart2' */
  real_T pd[3];                        /* '<Root>/Chart2' */
  real_T pd_p[3];                      /* '<Root>/Chart2' */
  real_T t_catch_predict[2];           /* '<Root>/Chart2' */
  real_T use_pred;                     /* '<Root>/Chart2' */
  real_T t_start;                      /* '<Root>/Chart2' */
  real_T trajectory_update;            /* '<Root>/Chart2' */
  real_T init_estimator;               /* '<Root>/Chart2' */
  real_T SFunction_o10;                /* '<Root>/Chart2' */
  real_T SFunction_o11;                /* '<Root>/Chart2' */
  real_T SFunction_o12;                /* '<Root>/Chart2' */
  real_T SFunction_o13;                /* '<Root>/Chart2' */
  real_T SFunction_o14;                /* '<Root>/Chart2' */
  real_T SFunction_o15;                /* '<Root>/Chart2' */
} B_Chart2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T *t_in;                        /* '<Root>/t_in' */
  real_T *point_in[3];                 /* '<Root>/point_in' */
  real_T *init_goto_start;             /* '<Root>/init_goto_start' */
  boolean_T *reset_flow_chart;         /* '<Root>/reset_flow_chart' */
  real_T *init_number_of_samples;      /* '<Root>/init_number_of_samples' */
  real_T *motion_enable;               /* '<Root>/motion_enable' */
  real_T *motive_ts[3];                /* '<Root>/motive_ts' */
} ExternalUPtrs_Chart2_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T *state;                       /* '<Root>/state' */
  real_T *pd[3];                       /* '<Root>/pd' */
  real_T *pd_p[3];                     /* '<Root>/pd_p' */
  real_T *t_catch_predict[2];          /* '<Root>/t_catch_predict' */
  real_T *use_pred;                    /* '<Root>/use_pred' */
  real_T *t_start;                     /* '<Root>/t_start' */
  real_T *trajectory_update;           /* '<Root>/trajectory_update' */
  real_T *init_estimator;              /* '<Root>/init_estimator' */
} ExtY_Chart2_T;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('controller_ballcatcher_inv_kin/Chart2')    - opens subsystem controller_ballcatcher_inv_kin/Chart2
 * hilite_system('controller_ballcatcher_inv_kin/Chart2/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller_ballcatcher_inv_kin'
 * '<S1>'   : 'controller_ballcatcher_inv_kin/Chart2'
 * '<S2>'   : 'controller_ballcatcher_inv_kin/Chart2/estimate_parabola'
 * '<S3>'   : 'controller_ballcatcher_inv_kin/Chart2/estimate_parabola/Parabola Estimator'
 */
#endif                                 /* RTW_HEADER_Chart2_sf_h_ */
