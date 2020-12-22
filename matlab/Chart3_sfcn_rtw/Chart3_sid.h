/*
 * Chart3_sid.h
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
 *
 * SOURCES: Chart3_sf.c
 */

/* statically allocated instance data for model: Chart3 */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Chart3_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Chart3_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 36232341U);
    ssSetChecksumVal(rts, 1, 1996593888U);
    ssSetChecksumVal(rts, 2, 1601017336U);
    ssSetChecksumVal(rts, 3, 2646201708U);
  }
}
