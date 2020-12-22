/*
 * Chart_sid.h
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
 *
 * SOURCES: Chart_sf.c
 */

/* statically allocated instance data for model: Chart */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Chart_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Chart_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 538319935U);
    ssSetChecksumVal(rts, 1, 1081203209U);
    ssSetChecksumVal(rts, 2, 2388185215U);
    ssSetChecksumVal(rts, 3, 2864257659U);
  }
}
