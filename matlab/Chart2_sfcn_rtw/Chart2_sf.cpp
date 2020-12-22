/*
 * Chart2_sf.cpp
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

#include <math.h>
#include "Chart2_sf.h"
#include "Chart2_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"

/* Named constants for Chart: '<Root>/Chart2' */
#define Chart2_IN_CATCH                ((uint8_T)1U)
#define Chart2_IN_GO_TO_START_FROM_NO_CATCH ((uint8_T)2U)
#define Chart2_IN_INIT                 ((uint8_T)3U)
#define Chart2_IN_INIT_GOTO_START      ((uint8_T)4U)
#define Chart2_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Chart2_IN_NO_VALID_BALL_VALUE  ((uint8_T)5U)
#define Chart2_IN_READY                ((uint8_T)6U)
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *Chart2_malloc(SimStruct *S);

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
static boolean_T Chart2_isBallValueValid(const real_T data_point[3]);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.cpp"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/*
 * Function for Chart: '<Root>/Chart2'
 * function valid  = isBallValueValid(data_point)
 */
static boolean_T Chart2_isBallValueValid(const real_T data_point[3])
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
    /* SystemInitialize for Chart: '<Root>/Chart2' */
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_NO_ACTIVE_CHILD;
  } else {                             /* SystemReset for Chart: '<Root>/Chart2' */
    ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 1))[0] = 0U;
    ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_NO_ACTIVE_CHILD;
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

  Chart2_malloc(S);
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
  B_Chart2_T *_rtB;
  _rtB = ((B_Chart2_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 0, 0)) {
    /* Chart: '<Root>/Chart2' */
    if (((uint32_T *)ssGetDWork(S, 0))[0] < 262143U) {
      ((uint32_T *)ssGetDWork(S, 0))[0] = ((uint32_T *)ssGetDWork(S, 0))[0] + 1U;
    }

    /* Gateway: Chart2 */
    /* During: Chart2 */
    if (((uint8_T *)ssGetDWork(S, 1))[0] == 0U) {
      /* Entry: Chart2 */
      ((uint8_T *)ssGetDWork(S, 1))[0] = 1U;

      /* Entry Internal: Chart2 */
      /* Transition: '<S1>:27' */
      ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
       case Chart2_IN_CATCH:
        _rtB->state = 2.0;

        /* During 'CATCH': '<S1>:17' */
        /* '<S1>:128:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:128' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_NO_VALID_BALL_VALUE;
            ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

            /* Entry 'NO_VALID_BALL_VALUE': '<S1>:79' */
            /* '<S1>:79:1' state=3; */
            _rtB->state = 3.0;

            /* '<S1>:79:1' use_pred=0; */
            _rtB->use_pred = 0.0;

            /* '<S1>:79:1' trajectory_update = 0; */
            _rtB->trajectory_update = 0.0;
          } else {
            /* '<S1>:17:4' init_estimator=0; */
            _rtB->init_estimator = 0.0;
          }
        }
        break;

       case Chart2_IN_GO_TO_START_FROM_NO_CATCH:
        _rtB->state = 4.0;

        /* During 'GO_TO_START_FROM_NO_CATCH': '<S1>:87' */
        /* '<S1>:127:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:127' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_READY;

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

       case Chart2_IN_INIT:
        _rtB->state = 0.0;
        _rtB->use_pred = 0.0;

        /* During 'INIT': '<S1>:95' */
        /* '<S1>:107:1' sf_internal_predicateOutput = init_goto_start && motion_enable; */
        if ((*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] != 0.0) &&
            (*((const real_T **)ssGetInputPortSignalPtrs(S, 5))[0] != 0.0)) {
          /* Transition: '<S1>:107' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT_GOTO_START;
          ((uint32_T *)ssGetDWork(S, 0))[0] = 0U;

          /* Entry 'INIT_GOTO_START': '<S1>:103' */
          /* '<S1>:103:1' trajectory_update = 1; */
          _rtB->trajectory_update = 1.0;

          /* '<S1>:103:1' t_catch_predict=[t_in,t_in+10]; */
          _rtB->t_catch_predict[0] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 0))[0];
          _rtB->t_catch_predict[1] = *((const real_T **)ssGetInputPortSignalPtrs
            (S, 0))[0] + 10.0;

          /* '<S1>:103:3' pd=motive_ts; */
          /* '<S1>:103:4' pd_p=positions.start_p; */
          _rtB->pd[0] = *((const real_T **)ssGetInputPortSignalPtrs(S, 6))[0];
          _rtB->pd_p[0] = 0.0;
          _rtB->pd[1] = *((const real_T **)ssGetInputPortSignalPtrs(S, 6))[1];
          _rtB->pd_p[1] = 0.0;
          _rtB->pd[2] = *((const real_T **)ssGetInputPortSignalPtrs(S, 6))[2];
          _rtB->pd_p[2] = 0.0;
        }
        break;

       case Chart2_IN_INIT_GOTO_START:
        /* During 'INIT_GOTO_START': '<S1>:103' */
        /* '<S1>:126:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:126' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_READY;

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

       case Chart2_IN_NO_VALID_BALL_VALUE:
        _rtB->state = 3.0;
        _rtB->use_pred = 0.0;

        /* During 'NO_VALID_BALL_VALUE': '<S1>:79' */
        /* '<S1>:129:1' sf_internal_predicateOutput = reset_flow_chart; */
        if (*((const boolean_T **)ssGetInputPortSignalPtrs(S, 3))[0]) {
          /* Transition: '<S1>:129' */
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
              Chart2_IN_GO_TO_START_FROM_NO_CATCH;
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
          ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_INIT;

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
          if (Chart2_isBallValueValid(*(const real_T **)ssGetInputPortSignalPtrs
               (S, 1))) {
            /* Transition: '<S1>:26' */
            ((uint8_T *)ssGetDWork(S, 2))[0] = Chart2_IN_CATCH;

            /* Entry 'CATCH': '<S1>:17' */
            /* '<S1>:17:1' t_catch_predict=[t_in+1,t_in+2]; */
            _rtB->t_catch_predict[0] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 0))[0] + 1.0;
            _rtB->t_catch_predict[1] = *((const real_T **)
              ssGetInputPortSignalPtrs(S, 0))[0] + 2.0;

            /* '<S1>:17:2' state=2; */
            _rtB->state = 2.0;

            /* '<S1>:17:3' t_start=t_in; */
            _rtB->t_start = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0];

            /* '<S1>:17:3' init_estimator=1; */
            _rtB->init_estimator = 1.0;
          }
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart2' */

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

    /* Outport: '<Root>/init_estimator' */
    ((real_T *)ssGetOutputPortSignal(S, 7))[0] = _rtB->init_estimator;
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
#  include "Chart2_mid.h"
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

  /* outport number: 7 */
  if (!ssSetOutputPortVectorDimension(S, 7, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 7, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 7, 5.0E-5);
  ssSetOutputPortOffsetTime(S, 7, 0.0);
  ssSetOutputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 7))
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

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 3))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 5.0E-5);
    ssSetInputPortOffsetTime(S, 6, 0.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 3)) {
    return;
  }

  /* '<Root>/Chart2': DWORK3 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* '<Root>/Chart2': DWORK1 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT8);

  /* '<Root>/Chart2': DWORK2 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_UINT8);

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
# define S_FUNCTION_NAME               Chart2_sf

extern "C" {

# include "cg_sfun.h"

}
#endif                                 /* defined(MATLAB_MEX_FILE) */
