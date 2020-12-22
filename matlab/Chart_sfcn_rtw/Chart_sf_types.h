/*
 * Chart_sf_types.h
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

#ifndef RTW_HEADER_Chart_sf_types_h_
#define RTW_HEADER_Chart_sf_types_h_
#include "rtwtypes.h"
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
#endif                                 /* RTW_HEADER_Chart_sf_types_h_ */
