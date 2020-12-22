/*
 * Chart3_sf_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Chart3_sf".
 *
 * Model version              : 1.3600
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct  6 18:52:48 2020
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Chart3_sf_types_h_
#define RTW_HEADER_Chart3_sf_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
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

#ifndef DEFINED_TYPEDEF_FOR_struct_45Uo8IsROXGEfVnLRiCZVB_
#define DEFINED_TYPEDEF_FOR_struct_45Uo8IsROXGEfVnLRiCZVB_

typedef struct {
  real_T T_optitrack;
  real_T T_iiwa;
  real_T T_optiTask;
  real_T cycle_time_ratio;
} struct_45Uo8IsROXGEfVnLRiCZVB;

#endif

/* Custom Type definition for MATLAB Function: '<S2>/Parabola Estimator' */
#ifndef struct_tag_sDzCfTiIapKTB3mCVdDRUZC
#define struct_tag_sDzCfTiIapKTB3mCVdDRUZC

struct tag_sDzCfTiIapKTB3mCVdDRUZC
{
  real_T x0_est;
  real_T vx0_est;
  real_T y0_est;
  real_T vy0_est;
  real_T z0_est;
  real_T vz0_est;
};

#endif                                 /*struct_tag_sDzCfTiIapKTB3mCVdDRUZC*/

#ifndef typedef_sDzCfTiIapKTB3mCVdDRUZC_Chart3_T
#define typedef_sDzCfTiIapKTB3mCVdDRUZC_Chart3_T

typedef struct tag_sDzCfTiIapKTB3mCVdDRUZC sDzCfTiIapKTB3mCVdDRUZC_Chart3_T;

#endif                                 /*typedef_sDzCfTiIapKTB3mCVdDRUZC_Chart3_T*/
#endif                                 /* RTW_HEADER_Chart3_sf_types_h_ */
