﻿// ****************** rt_sfcn_helper.cpp *******************************
// Generated by TwinCAT Target for MATLAB/Simulink (TE1400)
// MATLAB R2018b (win64)
// TwinCAT 3.1.4024
// TwinCAT Target 1.2.1237
// Beckhoff Automation GmbH & Co. KG     (www.beckhoff.com)
// *************************************************************
/*
 * rt_sfcn_helper.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "controller_ballcatcher_inv_kin".
 *
 * Model version              : 1.3680
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C++ source code generated on : Tue Oct 13 22:13:19 2020
 *
 * Target selection: TwinCAT.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 *
 */

#include "stdafx.h"
#include "Ccontroller_ballcatcher_inv_kin.h"
#include "rt_sfcn_helper.h"
/*
 * Abstract:
 *      Helper functions for noninlined S-Functions. Used by noninlined
 *      S-Functions configured for calling function-call subsystems.
 */

/* Helper function to make function calls from non-inlined S-functions. */
extern "C"

/* Helper function to make function enables from non-inlined S-functions. */
extern "C"

/* Helper function to make function disables from non-inlined S-functions. */
extern "C"

/* end rt_sfcn_helper.c */


int_T Ccontroller_ballcatcher_inv_kin::rt_CallSys (SimStruct *S, int_T element, int_T tid)
{
  (*(S)->callSys.fcns[element])((S)->callSys.args1[element],
    (S)->callSys.args2[element], tid);
  if (ssGetErrorStatus(S) != (NULL)) {
    return 0;
  } else {
    return 1;
  }
}

int_T Ccontroller_ballcatcher_inv_kin::rt_EnableSys (SimStruct *S, int_T element, int_T tid)
{
  if ((S)->callSys.fcns[ssGetOutputPortWidth(S,0)+element] != (NULL)) {
    (*(S)->callSys.fcns[ssGetOutputPortWidth(S,0)+element])
      ((S)->callSys.args1[element],
       (S)->callSys.args2[element], tid);
    if (ssGetErrorStatus(S) != (NULL)) {
      return 0;
    }
  }

  if ((S)->callSys.fcns[2*ssGetOutputPortWidth(S,0)+element] != (NULL)) {
    (*(S)->callSys.fcns[2*ssGetOutputPortWidth(S,0)+element])
      ((S)->callSys.args1[element],
       (S)->callSys.args2[element], tid);
    if (ssGetErrorStatus(S) != (NULL)) {
      return 0;
    }
  }

  return 1;
}

int_T Ccontroller_ballcatcher_inv_kin::rt_DisableSys (SimStruct *S, int_T element, int_T tid)
{
  (*(S)->callSys.fcns[3*ssGetOutputPortWidth(S,0)+element])
    ((S)->callSys.args1[element],
     (S)->callSys.args2[element], tid);
  if (ssGetErrorStatus(S) != (NULL)) {
    return 0;
  } else {
    return 1;
  }
}