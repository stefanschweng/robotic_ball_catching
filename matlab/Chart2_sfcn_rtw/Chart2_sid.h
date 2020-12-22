/*
 * Chart2_sid.h
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
 *
 * SOURCES: Chart2_sf.c
 */

/* statically allocated instance data for model: Chart2 */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Chart2_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Chart2_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1172131831U);
    ssSetChecksumVal(rts, 1, 2372174090U);
    ssSetChecksumVal(rts, 2, 3586846249U);
    ssSetChecksumVal(rts, 3, 3156954372U);
  }
}
