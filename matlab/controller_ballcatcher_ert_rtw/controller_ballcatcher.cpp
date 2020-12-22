//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_ballcatcher.cpp
//
// Code generated for Simulink model 'controller_ballcatcher'.
//
// Model version                  : 1.2934
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Aug 10 09:08:57 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "controller_ballcatcher.h"

// Named constants for Chart: '<Root>/Chart'
#define IN_CATCH                       ((uint8_T)1U)
#define IN_GO_TO_HAND_OVER             ((uint8_T)2U)
#define IN_GO_TO_START_FROM_CATCH      ((uint8_T)3U)
#define IN_GO_TO_START_FROM_NO_CATCH   ((uint8_T)4U)
#define IN_INIT                        ((uint8_T)5U)
#define IN_INIT_GOTO_START             ((uint8_T)6U)
#define IN_NO_VALID_BALL_VALUE         ((uint8_T)7U)
#define IN_READY                       ((uint8_T)8U)
#define NumBitsPerChar                 8U

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
static void estimate_parabola(real_T rtu_t_in, real_T rtu_t_start, const real_T
  rtu_point_in[3], real_T rtu_init, real_T rty_pd[3], real_T rty_pd_p[3], real_T
  *rty_use_pred, real_T rty_t_catch_predict[2], DW_estimate_parabola *localDW);

// Forward declaration for local functions
static void estimate_parabola_n(real_T t_in, const real_T point_in[3], const
  struct_drdASX3xMwFWgTYNtyjTdF *b_estimator_init_struct, real_T init, real_T
  *estimations_x0_est, real_T *estimations_vx0_est, real_T *estimations_y0_est,
  real_T *estimations_vy0_est, real_T *estimations_z0_est, real_T
  *estimations_vz0_est, DW_estimate_parabola *localDW);
extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   // do nothing
# else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}
// Function for MATLAB Function: '<S16>/Parabola Estimator'
  static void estimate_parabola_n(real_T t_in, const real_T point_in[3], const
  struct_drdASX3xMwFWgTYNtyjTdF *b_estimator_init_struct, real_T init, real_T
  *estimations_x0_est, real_T *estimations_vx0_est, real_T *estimations_y0_est,
  real_T *estimations_vy0_est, real_T *estimations_z0_est, real_T
  *estimations_vz0_est, DW_estimate_parabola *localDW)
{
  real_T kx_i[2];
  real_T ky_i[2];
  real_T kz_i[2];
  real_T b_estimator_init_struct_0;
  real_T kx_i_0[4];
  real_T tmp[4];
  int32_T i;
  real_T y_tmp;
  if ((!localDW->px_est_last_not_empty) || (init != 0.0)) {
    localDW->px_est_last[0] = b_estimator_init_struct->px_est_last[0];
    localDW->px_est_last[1] = b_estimator_init_struct->px_est_last[1];
    localDW->px_est_last_not_empty = true;
    localDW->Px_last[0] = b_estimator_init_struct->Px_last[0];
    localDW->Px_last[1] = b_estimator_init_struct->Px_last[1];
    localDW->Px_last[2] = b_estimator_init_struct->Px_last[2];
    localDW->Px_last[3] = b_estimator_init_struct->Px_last[3];
    localDW->py_est_last[0] = b_estimator_init_struct->py_est_last[0];
    localDW->py_est_last[1] = b_estimator_init_struct->py_est_last[1];
    localDW->Py_last[0] = b_estimator_init_struct->Py_last[0];
    localDW->Py_last[1] = b_estimator_init_struct->Py_last[1];
    localDW->Py_last[2] = b_estimator_init_struct->Py_last[2];
    localDW->Py_last[3] = b_estimator_init_struct->Py_last[3];
    localDW->pz_est_last[0] = b_estimator_init_struct->pz_est_last[0];
    localDW->pz_est_last[1] = b_estimator_init_struct->pz_est_last[1];
    localDW->Pz_last[0] = b_estimator_init_struct->Pz_last[0];
    localDW->Pz_last[1] = b_estimator_init_struct->Pz_last[1];
    localDW->Pz_last[2] = b_estimator_init_struct->Pz_last[2];
    localDW->Pz_last[3] = b_estimator_init_struct->Pz_last[3];
  }

  b_estimator_init_struct_0 = ((t_in * localDW->Px_last[3] + localDW->Px_last[2])
    * t_in + (t_in * localDW->Px_last[1] + localDW->Px_last[0])) +
    b_estimator_init_struct->q;
  y_tmp = 1.0 / b_estimator_init_struct->q;
  kx_i[0] = (localDW->Px_last[2] * t_in + localDW->Px_last[0]) /
    b_estimator_init_struct_0;
  kx_i[1] = (localDW->Px_last[3] * t_in + localDW->Px_last[1]) /
    b_estimator_init_struct_0;
  b_estimator_init_struct_0 = point_in[0] - (t_in * localDW->px_est_last[1] +
    localDW->px_est_last[0]);
  localDW->px_est_last[0] += kx_i[0] * b_estimator_init_struct_0;
  localDW->px_est_last[1] += kx_i[1] * b_estimator_init_struct_0;
  *estimations_x0_est = localDW->px_est_last[0];
  *estimations_vx0_est = localDW->px_est_last[1];
  b_estimator_init_struct_0 = ((t_in * localDW->Py_last[3] + localDW->Py_last[2])
    * t_in + (t_in * localDW->Py_last[1] + localDW->Py_last[0])) +
    b_estimator_init_struct->q;
  ky_i[0] = (localDW->Py_last[2] * t_in + localDW->Py_last[0]) /
    b_estimator_init_struct_0;
  ky_i[1] = (localDW->Py_last[3] * t_in + localDW->Py_last[1]) /
    b_estimator_init_struct_0;
  b_estimator_init_struct_0 = point_in[1] - (t_in * localDW->py_est_last[1] +
    localDW->py_est_last[0]);
  localDW->py_est_last[0] += ky_i[0] * b_estimator_init_struct_0;
  localDW->py_est_last[1] += ky_i[1] * b_estimator_init_struct_0;
  *estimations_y0_est = localDW->py_est_last[0];
  *estimations_vy0_est = localDW->py_est_last[1];
  b_estimator_init_struct_0 = ((t_in * localDW->Pz_last[3] + localDW->Pz_last[2])
    * t_in + (t_in * localDW->Pz_last[1] + localDW->Pz_last[0])) +
    b_estimator_init_struct->q;
  kz_i[0] = (localDW->Pz_last[2] * t_in + localDW->Pz_last[0]) /
    b_estimator_init_struct_0;
  kz_i[1] = (localDW->Pz_last[3] * t_in + localDW->Pz_last[1]) /
    b_estimator_init_struct_0;
  b_estimator_init_struct_0 = (t_in * t_in * 4.905 + point_in[2]) - (t_in *
    localDW->pz_est_last[1] + localDW->pz_est_last[0]);
  localDW->pz_est_last[0] += kz_i[0] * b_estimator_init_struct_0;
  localDW->pz_est_last[1] += kz_i[1] * b_estimator_init_struct_0;
  *estimations_z0_est = localDW->pz_est_last[0];
  *estimations_vz0_est = localDW->pz_est_last[1];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = kx_i[i];
    kx_i_0[i + 2] = kx_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = localDW->Px_last[i] - (b_estimator_init_struct_0 * localDW->
      Px_last[1] + kx_i_0[i] * localDW->Px_last[0]);
    tmp[i + 2] = localDW->Px_last[i + 2] - (b_estimator_init_struct_0 *
      localDW->Px_last[3] + kx_i_0[i] * localDW->Px_last[2]);
  }

  localDW->Px_last[0] = y_tmp * tmp[0];
  localDW->Px_last[1] = y_tmp * tmp[1];
  localDW->Px_last[2] = y_tmp * tmp[2];
  localDW->Px_last[3] = y_tmp * tmp[3];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = ky_i[i];
    kx_i_0[i + 2] = ky_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = localDW->Py_last[i] - (b_estimator_init_struct_0 * localDW->
      Py_last[1] + kx_i_0[i] * localDW->Py_last[0]);
    tmp[i + 2] = localDW->Py_last[i + 2] - (b_estimator_init_struct_0 *
      localDW->Py_last[3] + kx_i_0[i] * localDW->Py_last[2]);
  }

  localDW->Py_last[0] = y_tmp * tmp[0];
  localDW->Py_last[1] = y_tmp * tmp[1];
  localDW->Py_last[2] = y_tmp * tmp[2];
  localDW->Py_last[3] = y_tmp * tmp[3];
  for (i = 0; i < 2; i++) {
    kx_i_0[i] = kz_i[i];
    kx_i_0[i + 2] = kz_i[i] * t_in;
    b_estimator_init_struct_0 = kx_i_0[i + 2];
    tmp[i] = localDW->Pz_last[i] - (b_estimator_init_struct_0 * localDW->
      Pz_last[1] + kx_i_0[i] * localDW->Pz_last[0]);
    tmp[i + 2] = localDW->Pz_last[i + 2] - (b_estimator_init_struct_0 *
      localDW->Pz_last[3] + kx_i_0[i] * localDW->Pz_last[2]);
  }

  localDW->Pz_last[0] = y_tmp * tmp[0];
  localDW->Pz_last[1] = y_tmp * tmp[1];
  localDW->Pz_last[2] = y_tmp * tmp[2];
  localDW->Pz_last[3] = y_tmp * tmp[3];
}

// Output and update for function-call system: '<S1>/estimate_parabola'
static void estimate_parabola(real_T rtu_t_in, real_T rtu_t_start, const real_T
  rtu_point_in[3], real_T rtu_init, real_T rty_pd[3], real_T rty_pd_p[3], real_T
  *rty_use_pred, real_T rty_t_catch_predict[2], DW_estimate_parabola *localDW)
{
  real_T t_for_est;
  real_T t_start_g;
  real_T x_out;
  real_T z_out;
  real_T x_out_p;
  real_T y_out_p;
  real_T z_out_p;

  // MATLAB Function: '<S16>/Parabola Estimator'
  if ((rtu_init != 0.0) || (!localDW->t_catch_predict_p_not_empty)) {
    localDW->use_pred_p = 0.0;
    localDW->t_catch_predict_p[0] = rtu_t_start + 0.1;
    localDW->t_catch_predict_p[1] = (rtu_t_start + 0.1) + 1.0;
    localDW->t_catch_predict_p_not_empty = true;
  }

  if ((rtu_t_in >= localDW->t_catch_predict_p[0]) && (rtu_t_in <=
       localDW->t_catch_predict_p[1])) {
    localDW->use_pred_p = 1.0;
    estimate_parabola_n(rtu_t_in - rtu_t_start, rtu_point_in,
                        &rtConstP.ParabolaEstimator_estimator_init_struct,
                        rtu_init, &x_out, &x_out_p, &t_start_g, &y_out_p, &z_out,
                        &z_out_p, localDW);
    t_for_est = -(std::sqrt((19.62 * z_out + -15.696000000000002) + z_out_p *
      z_out_p) + z_out_p) / -9.81;
    rty_pd[0] = x_out_p * t_for_est + x_out;
    t_start_g += y_out_p * t_for_est;
    z_out = (z_out_p * t_for_est + z_out) - t_for_est * t_for_est * 4.905;
    z_out_p -= 9.81 * t_for_est;
    localDW->t_catch_predict_p[0] = rtu_t_start + 0.1;
    localDW->t_catch_predict_p[1] = t_for_est + rtu_t_start;
  } else {
    estimate_parabola_n(rtu_t_in - rtu_t_start, rtu_point_in,
                        &rtConstP.ParabolaEstimator_estimator_init_struct,
                        rtu_init, &t_start_g, &x_out_p, &y_out_p, &z_out_p,
                        &x_out, &z_out, localDW);
    rty_pd[0] = 0.0;
    t_start_g = 0.0;
    z_out = 0.0;
    x_out_p = 0.0;
    y_out_p = 0.0;
    z_out_p = 0.0;
  }

  rty_pd[1] = t_start_g;
  rty_pd[2] = z_out;
  rty_pd_p[0] = -x_out_p;
  rty_pd_p[1] = -y_out_p;
  rty_pd_p[2] = -z_out_p;
  *rty_use_pred = localDW->use_pred_p;
  rty_t_catch_predict[0] = localDW->t_catch_predict_p[0];
  rty_t_catch_predict[1] = localDW->t_catch_predict_p[1];

  // End of MATLAB Function: '<S16>/Parabola Estimator'
}

// Function for Chart: '<Root>/Chart'
boolean_T controller_ballcatcherModelClass::isBallValueValid(const real_T
  data_point[3])
{
  return (!(data_point[0] == 0.0)) || ((!(data_point[1] == 0.0)) ||
    (!(data_point[2] == 0.0)));
}

// Function for MATLAB Function: '<Root>/Trajectoy Generator'
void controller_ballcatcherModelClass::trvec2tform(const real_T t[3], real_T H
  [16])
{
  int8_T b_I[16];
  int32_T k;
  int32_T iacol_tmp;
  for (k = 0; k < 16; k++) {
    b_I[k] = 0;
  }

  b_I[0] = 1;
  b_I[5] = 1;
  b_I[10] = 1;
  b_I[15] = 1;
  for (k = 0; k < 4; k++) {
    iacol_tmp = k << 2;
    H[iacol_tmp] = b_I[iacol_tmp];
    H[iacol_tmp + 1] = b_I[iacol_tmp + 1];
    H[iacol_tmp + 2] = b_I[iacol_tmp + 2];
    H[iacol_tmp + 3] = b_I[iacol_tmp + 3];
  }

  H[12] = t[0];
  H[13] = t[1];
  H[14] = t[2];
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void controller_ballcatcherModelClass::mldivide_l(const real_T A[16], real_T
  B_1[16])
{
  int32_T ip;
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    ip = j * 5;
    iy = 0;
    ix = ip;
    smax = std::abs(b_A[ip]);
    for (k = 2; k <= 4 - j; k++) {
      ix++;
      s = std::abs(b_A[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_A[ip + iy] != 0.0) {
      if (iy != 0) {
        k = j + iy;
        ipiv[j] = (int8_T)(k + 1);
        smax = b_A[j];
        b_A[j] = b_A[k];
        b_A[k] = smax;
        ix = j + 4;
        iy = k + 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
      }

      iy = (ip - j) + 4;
      for (ix = ip + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[ip];
      }
    }

    iy = ip + 5;
    ix = ip + 4;
    for (k = 0; k <= 2 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = ip + 1;
        d = (iy - j) + 3;
        for (ijA = iy; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  for (j = 0; j < 3; j++) {
    if (j + 1 != ipiv[j]) {
      ip = ipiv[j] - 1;
      smax = B_1[j];
      B_1[j] = B_1[ip];
      B_1[ip] = smax;
      smax = B_1[j + 4];
      B_1[j + 4] = B_1[ip + 4];
      B_1[ip + 4] = smax;
      smax = B_1[j + 8];
      B_1[j + 8] = B_1[ip + 8];
      B_1[ip + 8] = smax;
      smax = B_1[j + 12];
      B_1[j + 12] = B_1[ip + 12];
      B_1[ip + 12] = smax;
    }
  }

  for (j = 0; j < 4; j++) {
    ix = j << 2;
    if (B_1[ix] != 0.0) {
      for (k = 2; k < 5; k++) {
        ip = (k + ix) - 1;
        B_1[ip] -= b_A[k - 1] * B_1[ix];
      }
    }

    if (B_1[1 + ix] != 0.0) {
      for (k = 3; k < 5; k++) {
        ip = (k + ix) - 1;
        B_1[ip] -= B_1[1 + ix] * b_A[k + 3];
      }
    }

    smax = B_1[2 + ix];
    if (smax != 0.0) {
      B_1[ix + 3] -= smax * b_A[11];
    }
  }

  for (j = 0; j < 4; j++) {
    ip = j << 2;
    smax = B_1[3 + ip];
    if (smax != 0.0) {
      B_1[3 + ip] = smax / b_A[15];
      for (k = 0; k < 3; k++) {
        ix = k + ip;
        B_1[ix] -= B_1[3 + ip] * b_A[k + 12];
      }
    }

    smax = B_1[2 + ip];
    if (smax != 0.0) {
      B_1[2 + ip] = smax / b_A[10];
      for (k = 0; k < 2; k++) {
        ix = k + ip;
        B_1[ix] -= B_1[2 + ip] * b_A[k + 8];
      }
    }

    smax = B_1[1 + ip];
    if (smax != 0.0) {
      B_1[1 + ip] = smax / b_A[5];
      B_1[ip] -= B_1[1 + ip] * b_A[4];
    }

    if (B_1[ip] != 0.0) {
      B_1[ip] /= b_A[0];
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T controller_ballcatcherModelClass::norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void controller_ballcatcherModelClass::wrap(real_T lambda[7])
{
  real_T z1_data[7];
  boolean_T b[7];
  boolean_T c[7];
  int8_T d_data[7];
  int32_T trueCount;
  real_T b_lambda_data[7];
  boolean_T e_data[7];
  real_T b_z1_data[7];
  real_T r;
  boolean_T rEQ0;
  real_T q;
  int32_T i;
  boolean_T c_0;
  int32_T d_size_idx_0;
  int8_T b_lambda_idx_0;
  int32_T exitg1;
  trueCount = 0;
  for (i = 0; i < 7; i++) {
    rEQ0 = (lambda[i] < -3.1415926535897931);
    c_0 = (3.1415926535897931 < lambda[i]);
    if (rEQ0 || c_0) {
      trueCount++;
    }

    b[i] = rEQ0;
    c[i] = c_0;
  }

  d_size_idx_0 = trueCount;
  trueCount = 0;
  for (i = 0; i < 7; i++) {
    if (b[i] || c[i]) {
      d_data[trueCount] = (int8_T)(i + 1);
      trueCount++;
    }
  }

  for (i = 0; i < d_size_idx_0; i++) {
    b_lambda_data[i] = lambda[d_data[i] - 1] + 3.1415926535897931;
  }

  b_lambda_idx_0 = (int8_T)d_size_idx_0;
  d_size_idx_0 = (int8_T)d_size_idx_0;
  if (0 <= d_size_idx_0 - 1) {
    memcpy(&b_z1_data[0], &z1_data[0], d_size_idx_0 * sizeof(real_T));
  }

  trueCount = 0;
  do {
    exitg1 = 0;
    i = b_lambda_idx_0 - 1;
    if (trueCount <= i) {
      if ((!rtIsInf(b_lambda_data[trueCount])) && (!rtIsNaN
           (b_lambda_data[trueCount]))) {
        if (b_lambda_data[trueCount] == 0.0) {
          r = 0.0;
        } else {
          r = std::fmod(b_lambda_data[trueCount], 6.2831853071795862);
          rEQ0 = (r == 0.0);
          if (!rEQ0) {
            q = std::abs(b_lambda_data[trueCount] / 6.2831853071795862);
            rEQ0 = (std::abs(q - std::floor(q + 0.5)) <= 2.2204460492503131E-16 *
                    q);
          }

          if (rEQ0) {
            r = 0.0;
          } else {
            if (b_lambda_data[trueCount] < 0.0) {
              r += 6.2831853071795862;
            }
          }
        }
      } else {
        r = (rtNaN);
      }

      b_z1_data[trueCount] = r;
      trueCount++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (0 <= d_size_idx_0 - 1) {
    memcpy(&z1_data[0], &b_z1_data[0], d_size_idx_0 * sizeof(real_T));
  }

  for (trueCount = 0; trueCount < d_size_idx_0; trueCount++) {
    e_data[trueCount] = (b_z1_data[trueCount] == 0.0);
  }

  for (trueCount = 0; trueCount <= i; trueCount++) {
    if (e_data[trueCount] && (b_lambda_data[trueCount] > 0.0)) {
      z1_data[trueCount] = 6.2831853071795862;
    }
  }

  trueCount = 0;
  for (i = 0; i < 7; i++) {
    if (b[i] || c[i]) {
      lambda[i] = z1_data[trueCount] - 3.1415926535897931;
      trueCount++;
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void controller_ballcatcherModelClass::inverse_kinematics_analytic(const real_T
  x_d[16], const struct_bnj9PLm1Rht6xDHAOlfP8G *param, boolean_T *success,
  real_T q[7])
{
  real_T d__se;
  real_T d__ew;
  real_T H_7[16];
  real_T x__sw[3];
  real_T u__sw[3];
  real_T tmp;
  real_T R_0_3_o[9];
  real_T A_s[9];
  real_T B_s[9];
  real_T C_s[9];
  real_T B_w[9];
  real_T C_w[9];
  real_T psi_list[17];
  real_T t1;
  real_T t2;
  real_T t4;
  real_T t9;
  real_T S[9];
  real_T b_y[8];
  boolean_T c_y;
  boolean_T c_x[7];
  static const int8_T b[3] = { 0, 1, 0 };

  int32_T i;
  real_T param_0[16];
  real_T tmp_0[3];
  real_T S_0[9];
  real_T u__sw_0[9];
  real_T S_1[9];
  real_T tmp_1;
  int32_T param_tmp;
  real_T r_tmp;
  real_T tmp_tmp;
  int32_T A_s_tmp;
  int32_T A_s_tmp_0;
  int32_T R_0_3_o_tmp;
  boolean_T exitg1;
  boolean_T exitg2;
  *success = false;
  for (i = 0; i < 7; i++) {
    q[i] = 0.0;
  }

  d__se = param->l__2 + param->l__3;
  d__ew = param->l__4 + param->l__5;
  memcpy(&H_7[0], &x_d[0], sizeof(real_T) << 4U);
  for (i = 0; i < 3; i++) {
    param_tmp = i << 2;
    param_0[param_tmp] = param->R_0[3 * i];
    param_0[1 + param_tmp] = param->R_0[3 * i + 1];
    param_0[2 + param_tmp] = param->R_0[3 * i + 2];
    param_0[12 + i] = param->p_0[i];
  }

  param_0[3] = 0.0;
  param_0[7] = 0.0;
  param_0[11] = 0.0;
  param_0[15] = 1.0;
  mldivide_l(param_0, H_7);
  tmp_0[0] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[2] = param->l__0 + param->l__1;
  tmp_1 = param->l__6 + param->l__7;
  for (i = 0; i < 3; i++) {
    x__sw[i] = (H_7[12 + i] - tmp_0[i]) - ((H_7[i + 4] * 0.0 + H_7[i] * 0.0) +
      H_7[i + 8] * tmp_1);
  }

  tmp_1 = norm(x__sw);
  u__sw[0] = x__sw[0] / tmp_1;
  u__sw[1] = x__sw[1] / tmp_1;
  u__sw[2] = x__sw[2] / tmp_1;
  tmp_tmp = d__ew * d__ew;
  t9 = d__se * d__se;
  tmp = ((tmp_1 * tmp_1 - t9) - tmp_tmp) / (2.0 * d__se * d__ew);
  if (!(std::abs(tmp) > 1.0)) {
    tmp_1 = std::acos(tmp);
    q[3] = tmp_1;
    if ((!(tmp_1 >= param->q_limit_upper[3])) && (!(tmp_1 <=
          param->q_limit_lower[3]))) {
      r_tmp = rt_atan2d_snf(x__sw[1], x__sw[0]);
      q[0] = r_tmp;
      t1 = std::cos(tmp_1);
      t2 = d__ew * t1;
      t4 = std::sin(tmp_1);
      t9 += 2.0 * d__se * t2 + tmp_tmp;
      tmp = (t9 - x__sw[2] * x__sw[2]) * tmp_tmp * (t4 * t4);
      if (tmp >= 0.0) {
        tmp = std::sqrt(tmp);
        t9 = 1.0 / t9;
        d__ew = (tmp_tmp * x__sw[2] * (t1 + 1.0) * (t1 - 1.0) + (t2 + d__se) *
                 tmp) * (1.0 / t4 * t9 / d__ew);
        d__se = ((d__se * x__sw[2] + x__sw[2] * t2) + tmp) * t9;
        tmp = rt_atan2d_snf(d__ew, d__se);
        q[1] = tmp;
        d__se = std::cos(r_tmp);
        d__ew = std::cos(tmp);
        R_0_3_o[0] = d__se * d__ew;
        tmp = std::sin(tmp);
        R_0_3_o[3] = -d__se * tmp;
        tmp_tmp = std::sin(r_tmp);
        R_0_3_o[6] = -tmp_tmp;
        R_0_3_o[1] = tmp_tmp * d__ew;
        R_0_3_o[4] = -std::sin(r_tmp) * tmp;
        R_0_3_o[7] = d__se;
        R_0_3_o[2] = -tmp;
        R_0_3_o[5] = -d__ew;
        R_0_3_o[8] = 0.0;
        memset(&S[0], 0, 9U * sizeof(real_T));
        S[3] = -u__sw[2];
        S[6] = u__sw[1];
        S[7] = -u__sw[0];
        S[1] = u__sw[2];
        S[2] = -u__sw[1];
        S[5] = u__sw[0];
        for (i = 0; i < 3; i++) {
          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = param_tmp + 3 * i;
            A_s[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * i + param_tmp;
            A_s[A_s_tmp] = A_s[A_s_tmp_0] + R_0_3_o[3 * i] * S[param_tmp];
            A_s[A_s_tmp] = R_0_3_o[3 * i + 1] * S[param_tmp + 3] + A_s[A_s_tmp_0];
            A_s[A_s_tmp] = R_0_3_o[3 * i + 2] * S[param_tmp + 6] + A_s[A_s_tmp_0];
          }
        }

        memset(&S[0], 0, 9U * sizeof(real_T));
        S[3] = -u__sw[2];
        S[6] = u__sw[1];
        S[7] = -u__sw[0];
        S[1] = u__sw[2];
        S[2] = -u__sw[1];
        S[5] = u__sw[0];
        for (i = 0; i < 3; i++) {
          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            S_0[i + 3 * param_tmp] = -((S[3 * param_tmp + 1] * S[i + 3] + S[3 *
              param_tmp] * S[i]) + S[3 * param_tmp + 2] * S[i + 6]);
          }

          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            B_s[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * param_tmp + i;
            B_s[A_s_tmp] = B_s[A_s_tmp_0] + R_0_3_o[3 * param_tmp] * S_0[i];
            B_s[A_s_tmp] = R_0_3_o[3 * param_tmp + 1] * S_0[i + 3] +
              B_s[A_s_tmp_0];
            B_s[A_s_tmp] = R_0_3_o[3 * param_tmp + 2] * S_0[i + 6] +
              B_s[A_s_tmp_0];
            u__sw_0[A_s_tmp] = u__sw[i] * u__sw[param_tmp];
          }

          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            C_s[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * param_tmp + i;
            C_s[A_s_tmp] = C_s[A_s_tmp_0] + R_0_3_o[3 * param_tmp] * u__sw_0[i];
            C_s[A_s_tmp] = R_0_3_o[3 * param_tmp + 1] * u__sw_0[i + 3] +
              C_s[A_s_tmp_0];
            C_s[A_s_tmp] = R_0_3_o[3 * param_tmp + 2] * u__sw_0[i + 6] +
              C_s[A_s_tmp_0];
          }
        }

        r_tmp = std::cos(tmp_1);
        S[0] = r_tmp;
        S[1] = 0.0;
        d__se = std::sin(tmp_1);
        S[2] = d__se;
        S[3] = d__se;
        S[4] = 0.0;
        S[5] = -r_tmp;
        for (i = 0; i < 3; i++) {
          S[6 + i] = b[i];
          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            S_0[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * param_tmp + i;
            S_0[A_s_tmp] = S_0[A_s_tmp_0] + S[i] * A_s[param_tmp];
            S_0[A_s_tmp] = S_0[A_s_tmp_0] + S[i + 3] * A_s[param_tmp + 3];
            S_0[A_s_tmp] = S_0[A_s_tmp_0] + S[i + 6] * A_s[param_tmp + 6];
          }

          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            R_0_3_o[A_s_tmp] = 0.0;
            u__sw_0[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * param_tmp + i;
            R_0_3_o_tmp = param_tmp << 2;
            R_0_3_o[A_s_tmp] = R_0_3_o[A_s_tmp_0] + H_7[R_0_3_o_tmp] * S_0[i];
            u__sw_0[A_s_tmp] = u__sw_0[A_s_tmp_0] + S[i] * B_s[param_tmp];
            R_0_3_o[A_s_tmp] = H_7[R_0_3_o_tmp + 1] * S_0[i + 3] +
              R_0_3_o[A_s_tmp_0];
            u__sw_0[A_s_tmp] = u__sw_0[A_s_tmp_0] + S[i + 3] * B_s[param_tmp + 3];
            R_0_3_o[A_s_tmp] = H_7[R_0_3_o_tmp + 2] * S_0[i + 6] +
              R_0_3_o[A_s_tmp_0];
            u__sw_0[A_s_tmp] = u__sw_0[A_s_tmp_0] + S[i + 6] * B_s[param_tmp + 6];
          }

          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            B_w[A_s_tmp] = 0.0;
            S_1[A_s_tmp] = 0.0;
            A_s_tmp_0 = 3 * param_tmp + i;
            R_0_3_o_tmp = param_tmp << 2;
            B_w[A_s_tmp] = B_w[A_s_tmp_0] + H_7[R_0_3_o_tmp] * u__sw_0[i];
            S_1[A_s_tmp] = S_1[A_s_tmp_0] + S[i] * C_s[param_tmp];
            B_w[A_s_tmp] = H_7[R_0_3_o_tmp + 1] * u__sw_0[i + 3] + B_w[A_s_tmp_0];
            S_1[A_s_tmp] = S_1[A_s_tmp_0] + S[i + 3] * C_s[param_tmp + 3];
            B_w[A_s_tmp] = H_7[R_0_3_o_tmp + 2] * u__sw_0[i + 6] + B_w[A_s_tmp_0];
            S_1[A_s_tmp] = S_1[A_s_tmp_0] + S[i + 6] * C_s[param_tmp + 6];
          }

          for (param_tmp = 0; param_tmp < 3; param_tmp++) {
            A_s_tmp = i + 3 * param_tmp;
            C_w[A_s_tmp] = 0.0;
            A_s_tmp_0 = param_tmp << 2;
            R_0_3_o_tmp = 3 * param_tmp + i;
            C_w[A_s_tmp] = C_w[R_0_3_o_tmp] + H_7[A_s_tmp_0] * S_1[i];
            C_w[A_s_tmp] = H_7[A_s_tmp_0 + 1] * S_1[i + 3] + C_w[R_0_3_o_tmp];
            C_w[A_s_tmp] = H_7[A_s_tmp_0 + 2] * S_1[i + 6] + C_w[R_0_3_o_tmp];
          }
        }

        q[3] = -tmp_1;
        S[8] = 3.1415926535897931;
        S[0] = 0.0;
        for (param_tmp = 0; param_tmp < 7; param_tmp++) {
          S[param_tmp + 1] = (1.0 + (real_T)param_tmp) * 0.39269908169872414;
        }

        b_y[7] = -3.1415926535897931;
        b_y[0] = -0.39269908169872414;
        for (param_tmp = 0; param_tmp < 6; param_tmp++) {
          b_y[param_tmp + 1] = (1.0 + (real_T)param_tmp) * -0.39269908169872414
            + -0.39269908169872414;
        }

        memcpy(&psi_list[0], &S[0], 9U * sizeof(real_T));
        memcpy(&psi_list[9], &b_y[0], sizeof(real_T) << 3U);
        param_tmp = 0;
        exitg1 = false;
        while ((!exitg1) && (param_tmp < 17)) {
          r_tmp = std::sin(psi_list[param_tmp]);
          d__se = std::cos(psi_list[param_tmp]);
          q[0] = rt_atan2d_snf((-A_s[4] * r_tmp - B_s[4] * d__se) - C_s[4],
                               (-A_s[3] * r_tmp - B_s[3] * d__se) - C_s[3]);
          tmp = (-A_s[5] * r_tmp - B_s[5] * d__se) - C_s[5];
          if (std::abs(tmp) > 1.0) {
            param_tmp++;
          } else {
            q[1] = std::acos(tmp);
            q[2] = rt_atan2d_snf((A_s[8] * r_tmp + B_s[8] * d__se) + C_s[8],
                                 (-A_s[2] * r_tmp - B_s[2] * d__se) - C_s[2]);
            q[3] = -tmp_1;
            q[4] = rt_atan2d_snf((R_0_3_o[7] * r_tmp + B_w[7] * d__se) + C_w[7],
                                 (R_0_3_o[6] * r_tmp + B_w[6] * d__se) + C_w[6]);
            tmp = (R_0_3_o[8] * r_tmp + B_w[8] * d__se) + C_w[8];
            if (std::abs(tmp) > 1.0) {
              param_tmp++;
            } else {
              q[5] = std::acos(tmp);
              q[6] = rt_atan2d_snf((R_0_3_o[5] * r_tmp + B_w[5] * d__se) + C_w[5],
                                   (-R_0_3_o[2] * r_tmp - B_w[2] * d__se) - C_w
                                   [2]);
              wrap(q);
              if (q[0] < param->q_limit_lower[0]) {
                q[0] += 3.1415926535897931;
                q[1] = -q[1];
                q[2] += 3.1415926535897931;
                wrap(q);
              } else {
                if (q[0] > param->q_limit_upper[0]) {
                  q[0] -= 3.1415926535897931;
                  q[1] = -q[1];
                  q[2] -= 3.1415926535897931;
                  wrap(q);
                }
              }

              if (q[2] < param->q_limit_lower[2]) {
                q[2] += 3.1415926535897931;
                q[3] = -q[3];
                q[4] += 3.1415926535897931;
                wrap(q);
              } else {
                if (q[2] > param->q_limit_upper[2]) {
                  q[2] -= 3.1415926535897931;
                  q[3] = -q[3];
                  q[4] -= 3.1415926535897931;
                  wrap(q);
                }
              }

              if ((q[4] < param->q_limit_lower[4]) || (q[6] <
                   param->q_limit_lower[6])) {
                q[4] += 3.1415926535897931;
                q[5] = -q[5];
                q[6] += 3.1415926535897931;
                wrap(q);
              } else {
                if ((q[4] > param->q_limit_upper[4]) || (q[6] >
                     param->q_limit_upper[6])) {
                  q[4] -= 3.1415926535897931;
                  q[5] = -q[5];
                  q[6] -= 3.1415926535897931;
                  wrap(q);
                }
              }

              for (i = 0; i < 7; i++) {
                c_x[i] = (q[i] <= param->q_limit_upper[i]);
              }

              c_y = true;
              i = 0;
              exitg2 = false;
              while ((!exitg2) && (i < 7)) {
                if (!c_x[i]) {
                  c_y = false;
                  exitg2 = true;
                } else {
                  i++;
                }
              }

              if (c_y) {
                for (i = 0; i < 7; i++) {
                  c_x[i] = (q[i] >= param->q_limit_lower[i]);
                }

                i = 0;
                exitg2 = false;
                while ((!exitg2) && (i < 7)) {
                  if (!c_x[i]) {
                    c_y = false;
                    exitg2 = true;
                  } else {
                    i++;
                  }
                }

                if (c_y) {
                  *success = true;
                  exitg1 = true;
                } else {
                  param_tmp++;
                }
              } else {
                param_tmp++;
              }
            }
          }
        }

        if (!*success) {
          for (i = 0; i < 7; i++) {
            q[i] = 0.0;
          }
        }
      } else {
        for (i = 0; i < 7; i++) {
          q[i] = 0.0;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/Robot Model'
void controller_ballcatcherModelClass::iiwa_reduced_inertia_matrix(const real_T
  q[7], const sYAUkIU1G7S9rEYvehBuTuE *param, real_T tmpreturn[49])
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t13;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t19;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t25;
  real_T t26;
  real_T t28;
  real_T t30;
  real_T t31;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t36;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t46;
  real_T t54;
  real_T t55;
  real_T t56;
  real_T t59;
  real_T t60;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t66;
  real_T t67;
  real_T t69;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t76;
  real_T t77;
  real_T t78;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t84;
  real_T t87;
  real_T t88;
  real_T t89;
  real_T t90;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t101;
  real_T t102;
  real_T t103;
  real_T t105;
  real_T t106;
  real_T t107;
  real_T t110;
  real_T t112;
  real_T t113;
  real_T t116;
  real_T t117;
  real_T t120;
  real_T t122;
  real_T t123;
  real_T t125;
  real_T t127;
  real_T t128;
  real_T t132;
  real_T t133;
  real_T t134;
  real_T t135;
  real_T t136;
  real_T t138;
  real_T t139;
  real_T t140;
  real_T t141;
  real_T t142;
  real_T t144;
  real_T t145;
  real_T t148;
  real_T t149;
  real_T t153;
  real_T t154;
  real_T t155;
  real_T t158;
  real_T t159;
  real_T t164;
  real_T t165;
  real_T t166;
  real_T t168;
  real_T t169;
  real_T t171;
  real_T t173;
  real_T t174;
  real_T t175;
  real_T t177;
  real_T t183;
  real_T t184;
  real_T t186;
  real_T t189;
  real_T t190;
  real_T t193;
  real_T t194;
  real_T t195;
  real_T t197;
  real_T t199;
  real_T t200;
  real_T t201;
  real_T t203;
  real_T t208;
  real_T t210;
  real_T t212;
  real_T t213;
  real_T t215;
  real_T t216;
  real_T t218;
  real_T t220;
  real_T t225;
  real_T t229;
  real_T t231;
  real_T t234;
  real_T t235;
  real_T t236;
  real_T t240;
  real_T t241;
  real_T t242;
  real_T t244;
  real_T t245;
  real_T t246;
  real_T t248;
  real_T t249;
  real_T t254;
  real_T t258;
  real_T t260;
  real_T t264;
  real_T t265;
  real_T t268;
  real_T t270;
  real_T t271;
  real_T t273;
  real_T t274;
  real_T t275;
  real_T t277;
  real_T t280;
  real_T t286;
  real_T t287;
  real_T t291;
  real_T t292;
  real_T t293;
  real_T t294;
  real_T t296;
  real_T t297;
  real_T t299;
  real_T t300;
  real_T t301;
  real_T t302;
  real_T t303;
  real_T t306;
  real_T t311;
  real_T t312;
  real_T t318;
  real_T t320;
  real_T t322;
  real_T t323;
  real_T t326;
  real_T t327;
  real_T t328;
  real_T t331;
  real_T t332;
  real_T t333;
  real_T t337;
  real_T t338;
  real_T t339;
  real_T t340;
  real_T t344;
  real_T t346;
  real_T t347;
  real_T t349;
  real_T t353;
  real_T t356;
  real_T t358;
  real_T t359;
  real_T t360;
  real_T t362;
  real_T t363;
  real_T t365;
  real_T t366;
  real_T t367;
  real_T t369;
  real_T t372;
  real_T t373;
  real_T t375;
  real_T t377;
  real_T t378;
  real_T t379;
  real_T t396;
  real_T t399;
  real_T t401;
  real_T t404;
  real_T t409;
  real_T t410;
  real_T t437;
  real_T t439;
  real_T t441;
  real_T t443;
  real_T t446;
  real_T t448;
  real_T t452;
  real_T t455;
  real_T t456;
  real_T t467;
  real_T t468;
  real_T t470;
  real_T t471;
  real_T t475;
  real_T t476;
  real_T t483;
  real_T t488;
  real_T t493;
  real_T t498;
  real_T t502;
  real_T t503;
  real_T t504;
  real_T t512;
  real_T t513;
  real_T t514;
  real_T t515;
  real_T t516;
  real_T t519;
  real_T t523;
  real_T t527;
  real_T t534;
  real_T t536;
  real_T t544;
  real_T t548;
  real_T t549;
  real_T t553;
  real_T t558;
  real_T t567;
  real_T t573;
  real_T t576;
  real_T t577;
  real_T t581;
  real_T t582;
  real_T t584;
  real_T t586;
  real_T t590;
  real_T t595;
  real_T t596;
  real_T t598;
  real_T t608;
  real_T t610;
  real_T t1053;
  real_T t1081;
  real_T t1172;
  real_T t86_tmp;
  real_T t137_tmp;
  real_T t166_tmp;
  real_T t199_tmp;
  real_T t332_tmp;
  real_T t80_tmp;
  real_T t573_tmp;
  real_T tmpreturn_tmp;
  real_T tmpreturn_tmp_0;
  real_T tmpreturn_tmp_1;
  real_T tmpreturn_tmp_2;
  real_T t299_tmp;
  real_T t249_tmp;
  real_T t350_tmp;
  real_T t299_tmp_0;
  real_T tmpreturn_tmp_tmp;
  real_T t332_tmp_tmp;
  t2 = std::sin(q[5]);
  t3 = param->s__l7x * t2;
  t4 = param->l__4 + param->l__5;
  t5 = param->m__l7 * t4;
  t7 = std::cos(q[6]);
  t10 = 2.0 * t3 * t5 * t7;
  t11 = param->m__l7 * param->s__l7y;
  t12 = t7 * t11;
  t13 = std::sin(q[6]);
  t14 = param->s__l7x * t13;
  t15 = t14 * param->m__l7;
  t16 = param->d__5 - param->s__l6z;
  t17 = t16 * param->m__l6;
  t18 = param->m__l5 * param->s__l5y;
  t19 = ((-t12 - t15) + t17) - t18;
  t21 = std::sin(q[4]);
  t22 = t19 * t21;
  t23 = param->s__l4x * param->m__l4;
  t25 = param->l__2 + param->l__3;
  t26 = (t22 + t23) * t25;
  t28 = std::sin(q[3]);
  t30 = 2.0 * t26 * t28;
  t31 = param->l__4 * param->l__4;
  t33 = 2.0 * param->l__4 * param->l__5;
  t34 = param->l__5 * param->l__5;
  t35 = param->s__l6x * param->s__l6x;
  t36 = param->l__2 * param->l__2;
  t38 = 2.0 * param->l__2 * param->l__3;
  t39 = param->l__3 * param->l__3;
  t40 = t16 * t16;
  t46 = param->s__l2y * param->s__l2y;
  t54 = param->s__l7y * param->s__l7y;
  t55 = param->s__l7x * param->s__l7x;
  t56 = t25 * t25;
  t59 = t28 * t25;
  t60 = param->s__l7x * t7;
  t62 = param->s__l7y * t13;
  t63 = t62 * param->m__l7;
  t64 = param->m__l6 * param->s__l6x;
  t65 = (param->m__l7 * t60 - t63) + t64;
  t66 = t59 * t65;
  t67 = t7 * t7;
  t69 = param->s__l7x * param->s__l7y;
  t70 = t67 * param->m__l7 * t69;
  t71 = 2.0 * t70;
  t72 = t55 - t54;
  t74 = (param->m__l7 * t72 - param->I__l7xx) + param->I__l7yy;
  t75 = t13 * t74;
  t76 = t75 * t7;
  t77 = param->m__l7 * param->s__l7x;
  t78 = t77 * param->s__l7y;
  t79 = t64 * t16;
  t80_tmp = (-t71 - t76) + t78;
  t80 = t80_tmp + t79;
  t81 = t21 * t80;
  t84 = std::cos(q[5]);
  t86_tmp = param->l__6 + param->s__l7z;
  t87 = t86_tmp * param->m__l7;
  t88 = param->m__l6 * param->s__l6y;
  t89 = t87 - t88;
  t90 = t89 * t2;
  t91 = param->m__l5 * param->s__l5x;
  t92 = t90 + t91;
  t93 = t92 * t25;
  t95 = 2.0 * t93 * t28;
  t96 = param->s__l7y * t2;
  t97 = t87 * t7;
  t98 = t96 * t97;
  t99 = t86_tmp * t13;
  t100 = t77 * t99;
  t101 = t88 * t16;
  t102 = t100 + t101;
  t103 = t102 * t2;
  t105 = param->s__l5x * param->s__l5y * param->m__l5;
  t106 = (t98 + t103) + t105;
  t107 = t21 * t106;
  t110 = std::cos(q[4]);
  t112 = param->s__l3x * param->s__l3x;
  t113 = param->s__l3z * param->s__l3z;
  t116 = param->s__l5y * param->s__l5y;
  t117 = param->s__l5z * param->s__l5z;
  t120 = 2.0 * t72;
  t122 = 2.0 * param->I__l7xx;
  t123 = 2.0 * param->I__l7yy;
  t125 = ((param->m__l7 * t120 - t122) + t123) * t67;
  t127 = t7 * t13 * t78;
  t128 = 4.0 * t127;
  t240 = param->s__l7z + param->l__6;
  t244 = -param->s__l7z - param->l__6;
  t132 = (t240 + param->s__l7y) * (t244 + param->s__l7y) * param->m__l7;
  t133 = 2.0 * t132;
  t134 = param->s__l6y * param->s__l6y;
  t135 = t35 - t134;
  t137_tmp = 2.0 * t135 * param->m__l6;
  t138 = 2.0 * param->I__l6xx;
  t139 = 2.0 * param->I__l6yy;
  t140 = 2.0 * param->I__l7zz;
  t141 = ((((((t125 - t128) + t133) + t137_tmp) - t138) + t139) - t123) + t140;
  t142 = t84 * t84;
  t144 = t3 * t97;
  t145 = 4.0 * t144;
  t99 *= t11;
  t3 = t64 * param->s__l6y;
  t148 = -t99 - t3;
  t149 = 4.0 * t148;
  t153 = -t86_tmp * param->m__l7 + t88;
  t154 = t4 * t153;
  t155 = 2.0 * t154;
  t158 = param->s__l5x * param->s__l5x;
  t159 = t158 - t117;
  t164 = param->s__l4y * param->s__l4y;
  t165 = param->s__l4z * param->s__l4z;
  t166_tmp = param->d__3 * param->d__3 - 2.0 * param->d__3 * param->s__l4z;
  t166 = (t166_tmp - t164) + t165;
  t168 = param->s__l3y * param->s__l3y;
  t169 = -t112 + t168;
  t171 = t86_tmp * t7;
  t97 = t77 * t171;
  t173 = (t97 - t99) - t3;
  t174 = 2.0 * t173;
  t175 = t174 * t142;
  t177 = t74 * t2 * t67;
  t183 = ((t96 * t13 + param->l__4 / 2.0) + param->l__5 / 2.0) * t77 * t7;
  t184 = 2.0 * t183;
  t186 = -t135 * param->m__l6;
  t189 = -t63 + t64;
  t190 = t4 * t189;
  t193 = t154 * t2;
  t194 = param->l__4 + param->s__l5z;
  t195 = t91 * t194;
  t63 = ((((((((((((-t132 + t186) + param->I__l6xx) - param->I__l6yy) +
                 param->I__l7yy) - param->I__l7zz) * t2 + (-t177 + t184)) + t190)
             * t84 + t175) - t97) - t193) + t99) + t3) + t195;
  t197 = t63 * t110;
  t199_tmp = t171 * t11 + t100;
  t199 = t199_tmp + t101;
  t200 = t199 * t21;
  t201 = t200 * t84;
  t203 = t2 * t67 * t78;
  t101 = 2.0 * t203;
  t171 = t13 * t2 * t74;
  t208 = -t11 * t4 + t171;
  t210 = -t78 - t79;
  t212 = t4 * t13;
  t213 = t77 * t212;
  t215 = t4 * t16 * param->m__l6;
  t216 = t194 * t18;
  t218 = (((((t2 * t210 + t208 * t7) + t101) - t213) + t215) - t216) * t21;
  t220 = param->s__l4y * param->s__l4x * param->m__l4;
  t194 = std::cos(q[3]);
  t225 = (((t197 - t201) + t218) + t220) * (2.0 * t28) * t194;
  t72 = (-param->m__l7 * t72 + param->I__l7xx) - param->I__l7yy;
  t229 = t72 * t67;
  t127 *= 2.0;
  t1053 = t229 + t127;
  t231 = (((((t1053 - t132) + t186) + param->I__l6xx) - param->I__l6yy) +
          param->I__l7yy) - param->I__l7zz;
  t186 = t231 * t142;
  t234 = -t173 * t2;
  t235 = t234 * t84;
  t236 = 2.0 * t235;
  t240 = (t240 + param->s__l7x) * (t244 + param->s__l7x) * param->m__l7;
  t241 = (-param->s__l6y + param->d__5) - param->s__l6z;
  t242 = (param->s__l6y + param->d__5) - param->s__l6z;
  t244 = t241 * t242 * param->m__l6;
  t245 = -t158 + t116;
  t246 = t245 * param->m__l5;
  t248 = t110 * t110;
  t249_tmp = (((t186 + t236) + t229) + t127) + t240;
  t249 = ((((((((t249_tmp + t244) + t246) + param->I__l5xx) - param->I__l5yy) +
             param->I__l6yy) - param->I__l6zz) - param->I__l7xx) +
          param->I__l7zz) * t248;
  t286 = t2 * t4;
  t254 = (t286 + t62) * (2.0 * t77) * t7;
  t258 = ((t86_tmp - param->l__5) - param->l__4) * ((t86_tmp + param->l__5) +
    param->l__4) + -t54;
  t260 = (((-t31 - t33) - t34) - t35) + t134;
  t264 = -t80 * t84;
  t265 = ((t264 + t98) + t103) + t105;
  t268 = 2.0 * t265 * t21 * t110;
  t270 = 2.0 * t190 * t2;
  t271 = param->l__4 * param->m__l5;
  t273 = 2.0 * t271 * param->s__l5z;
  t274 = t31 * param->m__l5;
  t275 = 2.0 * t144;
  t277 = 2.0 * -t148;
  t280 = ((t2 * t277 - t155) - t275) * t84;
  t286 = (t286 / 2.0 + t62) * param->s__l7x * param->m__l7 * t7;
  t287 = 4.0 * t286;
  t291 = t54 - (t4 + param->s__l7x) * ((-param->l__4 - param->l__5) +
    param->s__l7x);
  t292 = t291 * param->m__l7;
  t293 = (-param->s__l6x + param->d__5) - param->s__l6z;
  t294 = t16 + param->s__l6x;
  t296 = ((-t293 * t294 + t31) + t33) + t34;
  t297 = t296 * param->m__l6;
  t299 = -t116 + t117;
  t300 = t299 * param->m__l5;
  t301 = param->s__l4x * param->s__l4x;
  t302 = -t301 + t164;
  t303 = t302 * param->m__l4;
  t306 = t194 * t194;
  t311 = std::cos(q[2]);
  t312 = t311 * t311;
  t76 = (4.0 * t70 + 2.0 * t76) - 2.0 * t78;
  t318 = t76 - 2.0 * t79;
  t320 = 2.0 * t98;
  t322 = 2.0 * t102 * t2;
  t323 = 2.0 * t105;
  t326 = t74 * t67;
  t327 = t135 * param->m__l6;
  t1172 = t326 - t127;
  t328 = (((((t1172 + t132) + t327) - param->I__l6xx) + param->I__l6yy) -
          param->I__l7yy) + param->I__l7zz;
  t135 = t328 * t142;
  t331 = -t245 * param->m__l5;
  t332_tmp_tmp = t135 - t236;
  t332_tmp = ((t332_tmp_tmp + t326) - t127) - t240;
  t332 = (((((((t332_tmp - t244) + t331) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t333 = t332 * t21;
  t74 = t80 * t84;
  t337 = -t102 * t2;
  t338 = param->d__3 - param->s__l4z;
  t339 = t23 * t338;
  t340 = ((((((((t318 * t84 + t320) + t322) + t323) * t248 + t333 * t110) + t74)
            - t98) + t337) - t105) + t339;
  t70 = t84 * t199;
  t344 = -t208 * t7;
  t346 = -t210 * t2;
  t347 = (((((t70 - t101) + t344) + t346) + t213) - t215) + t216;
  t349 = t347 * t28 * t110;
  t350_tmp = t21 * t28;
  t353 = 2.0 * t350_tmp * -t173 * t142;
  t327 = (((((t132 + t327) - param->I__l6xx) + param->I__l6yy) - param->I__l7yy)
          + param->I__l7zz) * t2;
  t184 = (t177 - t184) + t327;
  t356 = t184 - t190;
  t327 = t356 * t21;
  t358 = t28 * t84;
  t359 = t327 * t358;
  t360 = (((t193 + t97) - t99) - t3) - t195;
  t362 = param->s__l4y * param->m__l4;
  t363 = t362 * t338;
  t365 = (t21 * t360 - t363) * t28;
  t366 = param->m__l3 * param->s__l3x;
  t367 = t366 * param->s__l3y;
  t369 = std::sin(q[2]);
  t372 = (((((t194 * t340 - t349) + t353) + t359) + t365) + t367) * 2.0 * t369 *
    t311;
  t373 = t89 * t84;
  t375 = t77 * t2 * t7;
  t377 = -t189 * t2;
  t378 = t4 * param->m__l6;
  t379 = param->s__l5z * param->m__l5;
  t132 = t332 * t248;
  t277 *= -t2;
  t120 = ((-param->m__l7 * t120 + t122) - t123) * t67;
  t291 = -t291 * param->m__l7;
  t396 = -t296 * param->m__l6;
  t399 = -t299 * param->m__l5;
  t401 = -t302 * param->m__l4;
  t302 = (((((((((-t273 + t399) + param->I__l7yy) - param->I__l7xx) + t401) -
              param->I__l4xx) + param->I__l4yy) - param->I__l5yy) +
           param->I__l5zz) + param->I__l6xx) - param->I__l6zz;
  t299_tmp = t132 - t268;
  t299_tmp_0 = t275 + t277;
  t299 = ((((((((t299_tmp_0 + t155) * t84 + (t299_tmp + t135)) + t120) + t287) +
             t270) + t291) + t396) - t274) + t302;
  t404 = t299 * t306;
  t409 = ((((((-t137_tmp + t123) + t128) - t133) + t138) - t139) - t140) + t120;
  t410 = t409 * t142;
  t437 = ((-t149 * t2 - t145) - t155) * t84;
  t439 = -t258 * param->m__l7;
  t441 = -t260 * param->m__l6;
  t443 = -t159 * param->m__l5;
  t446 = -t166 * param->m__l4;
  t448 = -t169 * param->m__l3;
  t452 = t39 * param->m__l4;
  t455 = 2.0 * t28 * t63 * t110;
  t456 = t200 * t28;
  t136 = t153 * t25;
  t296 = 2.0 * t213;
  t467 = 2.0 * t215;
  t468 = 2.0 * t216;
  t470 = (((((2.0 * -t210 * t2 + 2.0 * -t208 * t7) - 4.0 * t203) + t296) - t467)
          + t468) * t21;
  t471 = 2.0 * t220;
  t475 = ((((((-t375 + t377) + t5) + t378) + t362) + t379) + t271) * t25;
  t476 = 2.0 * t475;
  t483 = param->s__l2x * param->s__l2x;
  t488 = -param->m__l3 - param->m__l4;
  t493 = -(2.0 * param->l__3 * param->m__l4) - 2.0 * param->m__l3 *
    param->s__l3z;
  t498 = std::cos(q[1]);
  t502 = std::sin(q[1]);
  t503 = 4.0 * -t173;
  t504 = t503 * t142;
  t512 = 2.0 * t97;
  t513 = 2.0 * t193;
  t514 = 2.0 * t99;
  t515 = 2.0 * t3;
  t516 = 2.0 * t195;
  t519 = 2.0 * t201;
  t523 = t332 * t28 * t248;
  t332 = t25 * t65;
  t527 = -2.0 * t28 * t81 - t332;
  t203 = t328 * t28;
  t534 = t203 * t142;
  t536 = (t2 * -t148 - t144) - t154;
  t544 = t136 * t28;
  t144 = -t544 - t200;
  t548 = t366 * param->s__l3z;
  t549 = t366 * param->l__2;
  t553 = t21 * -t173;
  t366 = 2.0 * t553 * t142;
  t558 = t21 * -t360;
  t567 = t203 * t21 * t142;
  t573_tmp = t1172 - t240;
  t573 = ((((((((t573_tmp - t244) + t331) - param->I__l5xx) + param->I__l5yy) -
             param->I__l6yy) + param->I__l6zz) + param->I__l7xx) -
          param->I__l7zz) * t21 * t28;
  t576 = ((param->m__l6 * -t16 + t12) + t15) + t18;
  t577 = t25 * t576;
  t581 = t332 * t21;
  t582 = t80 * t28;
  t148 = t581 + t582;
  t584 = t148 * t369;
  t586 = ((-t98 + t337) - t105) + t339;
  t590 = t25 * t21;
  t12 = t338 * param->m__l4;
  t595 = (param->s__l3y * param->m__l3 + t12) * param->l__2;
  t596 = t12 * param->l__3;
  t598 = param->s__l3z * param->s__l3y * param->m__l3;
  t608 = -t488 * t36;
  t610 = -t493 * param->l__2;
  t12 = (t301 + t164) * param->m__l4;
  t1081 = t567 - 2.0 * t234 * t350_tmp * t84;
  tmpreturn_tmp_tmp = (t31 + t33) + t34;
  tmpreturn_tmp = tmpreturn_tmp_tmp + t35;
  tmpreturn_tmp_0 = t54 + t55;
  tmpreturn_tmp_1 = (2.0 * t456 + 2.0 * t136) * t84;
  tmpreturn_tmp_2 = (t36 + t38) + t39;
  tmpreturn[0] = (((((((((((((((((((((((((((((((((((((((((((((((t133 + t137_tmp)
    - t138) + t139) - t123) + t140) * t2 + (2.0 * t177 - 4.0 * t183)) - 2.0 *
    t190) * t84 + t504) + t512) + t513) - t514) - t515) - t516) * t110 + t519) +
    t470) - t471) * t306 + ((((((((((((((((((t125 - t287) - t270) + t292) + t297)
    + t274) + t273) + t300) - param->I__l7yy) + param->I__l7xx) + t303) +
    param->I__l4xx) - param->I__l4yy) + param->I__l5yy) - param->I__l5zz) -
    param->I__l6xx) + param->I__l6zz) * t28 + (((((2.0 * t107 * t28 + t527 * t84)
    - t93) * t110 + -t523) - t534) + 2.0 * t28 * t536 * t84)) - t26) * t194) +
    t197) + t144 * t84) + t475 * t28) + t218) - t548) - t549) + t220) * t311 +
    ((((t110 * t347 - t327 * t84) + t363) - t366) + t558) * t369 * t194) + 2.0 *
    t28 * t265 * t369 * t248) + ((t1081 + t573) + t577) * t369 * t110) + t584 *
    t84) + t586 * t369 * t28) + t92 * t369 * t590) + ((t595 + t596) + t598) *
    t369) + param->s__l2y * param->s__l2x * param->m__l2) * (-2.0 * t502) * t498
    + param->I__l4zz) + param->I__l3yy) + param->I__l2xx) + param->I__l1zz) -
    t270) + t273) + t608) + t610) + t12) + t132) + t186) + t280) + t274) + t452)
                  + param->I__l5xx) + ((((((((((((((((((((((((((((-t225 + t410)
    + t437) - t254) - param->I__l6xx) + param->I__l6yy) + param->I__l7zz) + t404)
    + param->I__l4zz) + param->I__l3yy) + t439) + t441) + t443) +
    ((((((((((((t446 + t448) - param->I__l4yy) - param->I__l5zz) -
    param->I__l3xx) - param->I__l7yy) - t268) - t270) + t273) + t132) + t326) +
      t274) + param->I__l5xx)) * t312 + ((param->I__l7xx + t135) + t326)) - t452)
    - param->I__l5xx) + param->I__l5yy) + param->I__l6zz) - t236) +
    (((tmpreturn_tmp_1 + -t455) + (t470 - t471) * t28) - t476) * t194) +
    ((t166_tmp - t301) + t165) * param->m__l4) + (t168 - t113) * param->m__l3) +
    (t483 - t46) * param->m__l2) + ((((-t36 - t38) - t39) + t158) - t116) *
    param->m__l5) + t488 * t36) + t493 * param->l__2) + (((((((((((((((((((((2.0
    * t245 * param->m__l5 + 2.0 * param->I__l5xx) - 2.0 * param->I__l5yy) - 2.0 *
    param->I__l6zz) - t122) + t128) + t139) + t140) + 4.0 * t235) + 2.0 * t240)
    + 2.0 * t244) + t120) + t410) * t248 + ((((((-t30 - t372) - param->I__l6yy)
    - param->I__l7zz) + t404) - t127) + ((((t134 - t36) - t38) - t39) - t40) *
    param->m__l6)) + (((t86_tmp + param->l__3) + param->l__2) * ((t86_tmp -
    param->l__3) - param->l__2) + -t55) * param->m__l7) + (((-2.0 * t66 - 4.0 *
    t81) * t84 - t95) + 4.0 * t107) * t110) + param->I__l4xx) + param->I__l3zz)
    + param->I__l2yy) - param->I__l4zz) - param->I__l3yy) - param->I__l2xx)) *
    (t498 * t498) + ((((((((((((((((((((t149 * t2 + t145) + t155) * t84 + t141 *
    t142) + t159 * param->m__l5) + t166 * param->m__l4) + t169 * param->m__l3) +
    t225) + t249) + t254) + param->I__l6xx) - param->I__l6yy) - param->I__l7zz)
    + t258 * param->m__l7) + t260 * param->m__l6) + ((((((((((((t273 + t300) -
    param->I__l7yy) + param->I__l7xx) + t303) + param->I__l4xx) - param->I__l4yy)
    + param->I__l5yy) - param->I__l5zz) - param->I__l6xx) + param->I__l6zz) +
    (((((((((t249 + t268) + t186) + t280) + t125) - t287) - t270) + t292) + t297)
     + t274)) * t306 + (((((((((((-param->I__l4zz - param->I__l3yy) +
    param->I__l4yy) + param->I__l5zz) + param->I__l3xx) + param->I__l7yy) + t268)
    + t270) - t273) + t229) - t274) - param->I__l5xx))) * t312 +
    (((((((((((tmpreturn_tmp + t36) + t38) + t39) + t40) * param->m__l6 + (-t10
    + t30)) + (((-(2.0 * param->d__1 * param->s__l2z) + param->d__1 *
                 param->d__1) + t46) + param->s__l2z * param->s__l2z) *
          param->m__l2) + (param->s__l1x * param->s__l1x + param->s__l1y *
    param->s__l1y) * param->m__l1) + ((((tmpreturn_tmp_0 + t31) + t33) + t34) +
    t56) * param->m__l7) + (((2.0 * t66 + 2.0 * t81) * t84 + t95) - 2.0 * t107) *
       t110) + (t112 + t113) * param->m__l3) + ((tmpreturn_tmp_2 + t116) + t117)
     * param->m__l5)) + t372) + (((((((t373 - t375) + t377) + t5) + t378) + t362)
    + t379) + t271) * 2.0 * t25 * t194) + param->I__l6yy) + param->I__l7zz));
  t30 = t64 * -t16;
  t169 = t76 + 2.0 * t30;
  t88 *= -t16;
  t122 = t199_tmp - t88;
  t107 = -t241 * t242 * param->m__l6;
  t159 = (((((((t332_tmp + t107) + t331) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t190 = t80_tmp - t30;
  t76 = t190 * t84;
  t241 = -t122 * t2;
  t242 = ((((((2.0 * t2 * t122 + t169 * t84) + t323) * t248 + t159 * t21 * t110)
            + t76) + t241) - t105) + t339;
  t64 = t122 * t84;
  t218 = t190 * t2;
  t166 = t4 * t7;
  t133 = t11 * t166;
  t16 = t4 * -t16 * param->m__l6;
  t225 = ((((t64 + t218) + t133) + t213) + t16) + t216;
  t38 = t225 * t28 * t110;
  t235 = t328 * t2;
  t183 = t4 * t65;
  t123 = t235 - t183;
  t95 = t21 * t123;
  t39 = t95 * t358;
  t81 = -t190 * t84;
  t372 = t2 * t122;
  t377 = (t81 + t372) + t105;
  t404 = 2.0 * t377 * t21 * t110;
  t245 = t2 * t231 + t183;
  t175 = (((((t245 * t84 + t99) + t3) - t97) + t175) - t193) + t195;
  t36 = t175 * t110;
  t470 = t21 * -t122;
  t475 = t470 * t84;
  t122 = t183 * t2;
  t138 = 2.0 * t122;
  t488 = t159 * t248;
  t258 = (t174 * t2 + t155) * t84;
  t293 = (((t293 * t294 - t31) - t33) - t34) * param->m__l6;
  t139 = t95 * t84;
  t140 = (((((((t573_tmp + t107) + t331) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t265 = t28 * t140 * t21;
  t145 = t93 * t21;
  t33 = 2.0 * t183;
  t149 = 2.0 * t133;
  t294 = t159 * t28;
  t260 = (t234 - t154) * t28;
  t231 = -t174 * t142;
  t159 = -t65 * t2;
  t34 = (((((t159 + t5) + t378) + t379) + t271) + t362) * t25 * t28;
  t347 = t558 + t363;
  t493 = param->d__1 - param->s__l2z;
  t80_tmp = ((t138 + t120) + t128) + t291;
  tmpreturn[7] = ((((((((((((((((((-param->I__l5zz - t404) - ((((((t2 * -t190 -
    t213) - t216) - t133) - t16) * t21 + (t36 + t475)) + t220) * 2.0 * t28 *
    t194) - t138) + (t2 * t503 - t155) * t84) + t488) - param->I__l3xx) -
    param->I__l7yy) + t273) + t326) + t274) + param->I__l5xx) + ((((((((((t488 -
    t404) + t135) + t258) + t138) + t120) + t128) + t291) + t293) - t274) + t302)
                        * t306) + ((((((((((((t410 - param->I__l6xx) +
    param->I__l6yy) + param->I__l7zz) - t127) + param->I__l4zz) + param->I__l3yy)
    + t439) + t441) + t443) + t446) + t448) - param->I__l4yy)) * t502 * t369 -
                      ((((((((((((t110 * t225 + t363) - t366) + t558) - t139) *
    t194 + 2.0 * t377 * t28 * t248) + ((t1081 + t265) + t577) * t110) + (t28 *
    t190 + t581) * t84) + ((t241 - t105) + t339) * t28) + t145) + t595) + t596)
                       + t598) * t498) * t311 + (((((t194 * t242 + t353) + t365)
    + t367) - t38) + t39) * 2.0 * t502 * t312) - (((((((((((((((((((((((t80_tmp
    + t293) - t274) - t273) + t399) + param->I__l7yy) - param->I__l7xx) + t401)
    - param->I__l4xx) + param->I__l4yy) - param->I__l5yy) + param->I__l5zz) +
    param->I__l6xx) - param->I__l6zz) * t28 + ((((((-2.0 * t21 * t28 * -t190 +
    t332) * t84 - (t372 + t105) * 2.0 * t21 * t28) + t93) * t110 + t294 * t248)
    + t534) - 2.0 * t260 * t84)) + t26) * t194 + ((((((((((t2 * t409 + t33) *
    t84 + -t503 * t142) - t513) - t512) + t514) + t515) + t516) * t110 + 2.0 *
    t475) + ((((t2 * t169 - t296) - t468) - 2.0 * t16) - t149) * t21) + t471) *
    t306) + ((((((t123 * t84 - t99) - t3) + t97) + t193) - t195) + t231) * t110)
    + (t544 - t470) * t84) - t34) + ((((t218 + t133) + t213) + t16) + t216) *
    t21) + t548) + t549) - t220) * t498 * t369) - t242 * t502 * t194) +
                  (((((-param->m__l2 * param->s__l2x * t493 + t28 * t347) - t353)
                     - t367) + t38) - t39) * t502) - t498 * t493 * param->m__l2 *
    param->s__l2y;
  t169 = ((((t2 * -t80 - t213) + t215) - t216) - t133) * t21;
  t470 = ((t36 - t201) + t169) + t220;
  t404 = t311 * t28;
  t38 = t369 * t199;
  t26 = t199 * t2;
  t190 = t80 * t2;
  t581 = (((t190 + t133) + t213) - t215) + t216;
  t372 = t203 * t311;
  t377 = 2.0 * -t173 * t369 * t21;
  t241 = (t21 * t576 - t23) * t25;
  t475 = t28 * t369;
  t242 = (t264 + t26) + t105;
  t31 = t28 * t2;
  t264 = t581 * t21;
  t218 = -t199 * t2;
  t225 = t21 * t242;
  t488 = 2.0 * t225 * t110;
  t39 = t154 * t84;
  t365 = param->s__l7z * param->s__l7z;
  t576 = 2.0 * param->s__l7z * param->l__6;
  t409 = param->l__6 * param->l__6;
  t493 = t4 * t4;
  t503 = (tmpreturn_tmp + t134) * param->m__l6;
  t534 = (t158 + t117) * param->m__l5;
  t164 = ((t166_tmp + t164) + t165) * param->m__l4;
  t112 = (t112 + t168) * param->m__l3;
  tmpreturn[14] = (((((((((((((((((((((((((((((t132 - t488) + t135) + t258) +
    t138) + t120) + t128) + t291) + t396) - t274) + t302) * t306 - 2.0 * t28 *
    t470 * t194) + t249) + t488) - 2.0 * t39) - t138) + t326) - t127) + ((((t54
    + t365) + t576) + t409) + t493) * param->m__l7) + t503) + t274) + t273) +
    t534) + param->I__l7xx) + t164) + param->I__l5yy) + param->I__l6zz) + t112)
                    + param->I__l3zz) + param->I__l4xx) * t498 +
    ((((((((((((((((((((((t80_tmp + t396) - t274) - t273) + t399) +
                      param->I__l7yy) - param->I__l7xx) + t401) - param->I__l4xx)
                  + param->I__l4yy) - param->I__l5yy) + param->I__l5zz) +
               param->I__l6xx) - param->I__l6zz) * t28 - t241) * t311 +
            ((((((-2.0 * t21 * (t26 + t105) * t28 + t93) * t311 + (-t311 * t527
    - t38) * t84) - t369 * t581) * t110 + t404 * t132) + (t372 + t377) * t142) +
             (-2.0 * t311 * t260 + t369 * t95) * t84)) - t347 * t369) * t194 +
          2.0 * t311 * t470 * t306) - 2.0 * t475 * t242 * t248) + ((((2.0 * t369
            * t553 * t31 + t311 * t123) * t84 + (-t21 * t328 * t475 + t311 *
            -t174) * t142) + t360 * t311) - (t573 + t577) * t369) * t110) +
       (t311 * -t144 - t584) * t84) + ((((-t34 + t264) + t548) + t549) - t220) *
      t311) - ((((((t218 - t105) + t339) * t28 + t145) + t595) + t596) + t598) *
     t369) * t502;
  t34 = t328 * t369;
  t347 = t80 * t311;
  t399 = t21 * t194;
  t488 = t80 * t369;
  t401 = t153 * t2 - t91;
  t527 = ((((-t101 + t344) + t346) + t213) - t215) + t216;
  t470 = -t173 * t28;
  t475 = t25 * t19;
  t573 = ((((((param->m__l6 * -t4 + param->m__l7 * -t4) + t189 * t2) - t271) -
            t362) + t375) - t379) * t25;
  t249 = (tmpreturn_tmp_0 + t493) * param->m__l7;
  t258 = (tmpreturn_tmp + t40) * param->m__l6;
  t117 = (t116 + t117) * param->m__l5;
  t337 = ((t74 - t98) + t337) - t105;
  t260 = t199 * t194;
  t493 = -t360 * t194;
  t396 = t194 * t338 * t362;
  t1081 = 2.0 * t194 * t234;
  tmpreturn[21] = ((((((((((((t1081 * t311 - 2.0 * t488) * t21 - (-t199 * t311 +
    t369 * t332) * t28) * t84 + -t328 * t311 * t399 * t142) + (-t194 * t311 *
    t140 + 2.0 * t106 * t369) * t21) + (t25 * t369 * t401 + t311 * t527) * t28) *
    t110 + ((((2.0 * t194 * t347 + 2.0 * t234 * t369) * t84 + -t34 * t142) - 2.0
             * t311 * t106 * t194) - t140 * t369) * t248) + (-2.0 * t21 * t311 *
    t470 + t34) * t142) + (((t369 * t136 - t347) * t194 + -t404 * t327) - 2.0 *
    t536 * t369) * t84) + (t311 * -t360 - t369 * t475) * t28 * t21) + (-t311 *
    t586 + t369 * t573) * t194) + (-param->s__l4x * t25 * t369 + param->s__l4y *
    t311 * t338) * param->m__l4 * t28) - (((((((((((-t10 - t270) + t249) + t258)
    + t274) + t273) + t117) + t12) + param->I__l4zz) + param->I__l5xx) +
    param->I__l6yy) + param->I__l7zz) * t369) * t502 + ((((((((((-2.0 * t234 *
    t350_tmp + t260) * t84 + t567) + t265) + t527 * t194) * t110 + -2.0 * t337 *
    t28 * t248) - 2.0 * t553 * t194 * t142) + (-t21 * t194 * t356 + t582) * t84)
    + t493 * t21) + t396) + t28 * t586) * t498;
  t536 = t194 * t110;
  t567 = 2.0 * t31 * -t173;
  t553 = t332 * t194;
  t265 = t475 * t21;
  t404 = t86_tmp * t86_tmp;
  t106 = (t55 + t404) * param->m__l7;
  t40 = (t134 + t40) * param->m__l6;
  t327 = (t158 + t116) * param->m__l5;
  t1053 = (((((t1053 + t106) + t40) + t327) + param->I__l5zz) + param->I__l6xx)
    + param->I__l7yy;
  t34 = t28 * t1053;
  t347 = -t360 * t28;
  tmpreturn_tmp = t110 * t28;
  tmpreturn[28] = ((((((((t194 * t245 + t332) * t311 - t38) * t110 + (-t200 *
    t194 - t567) * t311) + ((-t553 + t235) - t183) * (t369 * t21)) * t84 +
                      ((-2.0 * t536 * -t173 * t311 + t372) + t377) * t142) +
                     ((t493 + t93) * t311 - (((((-t194 * t475 + t213) - t215) +
    t216) + t133) + t190) * t369) * t110) + ((-t194 * t264 + t265) + t34) * t311)
                   - (((((t194 * t93 + t99) + t3) - t97) - t193) + t195) * t369 *
                   t21) * t502 + ((((((tmpreturn_tmp * t123 - t1081) + t456) *
    t84 + (2.0 * t110 * t470 + t194 * t328) * t142) - t347 * t110) + t1053 *
    t194) + t264 * t28) * t498;
  t1081 = (t194 * t4 + param->l__2) + param->l__3;
  t372 = t54 + t404;
  t193 = t372 * param->m__l7;
  t377 = t35 + t134;
  t234 = t377 * param->m__l6;
  t35 = (((t1172 + t193) + param->I__l7xx) + t234) + param->I__l6zz;
  t328 = t80 * t110;
  t456 = t199 * t28;
  t235 = t136 * t536;
  t245 = t154 * t110;
  t404 = t110 * t199;
  t470 = t65 * t194;
  t475 = t80 * t194;
  tmpreturn[35] = ((((((-t1081 * t153 * t311 + t488) * t84 + (-t1081 * t311 *
    t65 - t38) * t2) + t35 * t194 * t311) * t21 + ((-t328 * t194 - t456) * t311
    - ((t235 + t245) - t66) * t369) * t84) + ((t404 * t194 - t582) * t311 -
    ((t110 * t470 * t25 + t110 * t183) + t544) * t369) * t2) + t35 * t110 * t369)
    * t502 - (((((((((-t39 - t122) + t326) - t127) + t193) + t234) +
                 param->I__l6zz) + param->I__l7xx) * t28 * t21 + (-t328 * t28 +
    t260) * t84) + (tmpreturn_tmp * t199 + t475) * t2) * t498;
  t153 = t86_tmp * t311;
  t38 = t369 * param->s__l7y;
  t199 = (t194 * t25 + param->l__4) + param->l__5;
  t39 = -param->s__l7x * t153 * t194 + t38 * t199;
  t488 = t369 * param->s__l7x;
  t260 = param->s__l7y * t153 * t194 + t199 * t488;
  t1053 = param->s__l7x * t1081 * t311 - t38 * t86_tmp;
  t1081 = param->s__l7y * t1081 * t311 + t488 * t86_tmp;
  t153 = (t55 + t54) * param->m__l7 + param->I__l7zz;
  t1172 = t153 * t194;
  t493 = t21 * param->m__l7;
  t199 = param->s__l7x * t86_tmp;
  t544 = param->s__l7y * t86_tmp;
  t183 = t2 * t21;
  t60 -= t62;
  t582 = t153 * t2;
  t62 = ((-t60 * t84 * t87 + t11 * t212) - t166 * t77) + t582;
  t375 = t350_tmp * param->m__l7;
  t212 = param->s__l7y * t4;
  t166 = param->s__l7x * t4;
  t584 = t194 * t2;
  tmpreturn[42] = (((((((-(t39 * t7 + t260 * t13) * param->m__l7 * t84 +
    param->m__l7 * t1053 * t7) - param->m__l7 * t1081 * t13) - t1172 * t2 * t311)
                      * t110 + ((-t1053 * t493 * t13 - t1081 * t493 * t7) + t153
    * t28 * t311) * t84) - ((t38 * t25 - t199 * t311) * t2 * t28 + t260 * t21) *
                     param->m__l7 * t7) + (t39 * t21 - (t488 * t25 + t544 * t311)
    * t31) * param->m__l7 * t13) + t369 * t153 * t183) * t502 + ((((t375 * t212 *
    t7 + t375 * t166 * t13) + t1172) * t84 + t62 * t28 * t110) + ((param->s__l7x
    * t584 + param->s__l7y * t350_tmp) * t7 - (-param->s__l7x * t350_tmp +
    param->s__l7y * t584) * t13) * t87) * t498;
  tmpreturn[1] = tmpreturn[7];
  t488 = t65 * t84;
  t498 = ((t488 + t90) + t91) * t25;
  t502 = t183 * t67 * t78;
  t90 = 2.0 * t502;
  t91 = t208 * t21 * t7;
  t65 = -t210 * t21 * t2;
  t208 = (-t213 + t215) - t216;
  t1081 = t208 * t21;
  tmpreturn[8] = (((((((((((((((t1081 + t90) + t91) - t65) + t197) - t201) +
    t220) * (-2.0 * t28) * t312 - 2.0 * t340 * t369 * t311) + t455) -
                        tmpreturn_tmp_1) + ((((2.0 * t208 * t21 + 4.0 * t502) +
    2.0 * t91) - 2.0 * t65) + t471) * t28) + t476) * t194 + (((((((2.0 *
    tmpreturn_tmp * t498 + param->I__l6xx) + t127) + param->I__l2zz) + (t311 -
    1.0) * t299 * (t311 + 1.0) * t306) + param->I__l4yy) + param->I__l5zz) +
    ((((t55 + t365) + t576) + t409) + t56) * param->m__l7)) + param->I__l3xx) +
                   ((tmpreturn_tmp_2 + t158) + t116) * param->m__l5) +
                  ((t166_tmp + t301) + t165) * param->m__l4) +
    (((((((((((((((t299_tmp + t410) + t437) + t326) - t254) - t270) + t439) +
             t441) + t274) + t273) + t443) + (((((((((((-param->I__l7yy + t446)
    + param->I__l6yy) + param->I__l7zz) - param->I__l6xx) + t448) -
    param->I__l3xx) + param->I__l3yy) - param->I__l4yy) + param->I__l4zz) +
           param->I__l5xx) - param->I__l5zz)) * t312 + (((((((((t168 + t113) *
    param->m__l3 + (t483 + t46) * param->m__l2) + param->I__l7yy) + t608) + t610)
            + t135) + t229) + t452) + ((((-2.0 * param->d__5 * param->s__l6z +
             param->s__l6z * param->s__l6z) + param->d__5 * param->d__5) + t134)
          + t56) * param->m__l6)) + ((((-t15 + t17) - t18) * t21 + -t11 * t7 *
         t21) + t23) * (2.0 * t25) * t28) + (((((-t77 * t21 * t86_tmp * t7 -
           t154 * t183) + ((t99 + t3) + t195) * t21) + t363) * t28 + ((t349 -
          t353) - t359)) - t367) * (2.0 * t369) * t311) - t236);
  t15 = (((((t70 + t190) + t133) + t213) - t215) + t216) * t110;
  tmpreturn[15] = (((((((((((((((((((((((((((((t2 * -t174 - t155) * t84 + t186)
    - t138) + t125) - t128) + t292) + t297) + t274) + t273) + t300) -
    param->I__l7yy) + param->I__l7xx) + t303) + param->I__l4xx) - param->I__l4yy)
    + param->I__l5yy) - param->I__l5zz) - param->I__l6xx) + param->I__l6zz) *
    t28 + ((2.0 * t28 * t225 - t498) * t110 + -t523)) + t241) * t194 +
    ((((((((((t141 * t2 - t33) * t84 + t504) + t513) + t512) - t514) - t515) -
        t516) * t110 + t519) + ((((-t2 * t318 + t296) - t467) + t468) + t149) *
      t21) - t471) * t306) + t36) + ((((((t373 + t159) + t5) + t378) + t379) +
    t271) + t362) * t25 * t28) - t201) + t169) - t548) - t549) + t220) * t369 -
    ((((((((((((t15 - t366) - t139) + t558) + t363) * t194 + 2.0 * t28 * t242 *
            t248) + (t28 * t333 + t577) * t110) + (((t74 + t218) - t105) + t339)
          * t28) + t590 * t488) + t145) + t595) + t596) + t598) * t311;
  tmpreturn[22] = ((((((((((((((((((((((((((t249_tmp - t107) + t246) +
    param->I__l5xx) - param->I__l5yy) + param->I__l6yy) - param->I__l6zz) -
    param->I__l7xx) + param->I__l7zz) * t248 + (((t21 * t318 - t66) * t84 +
    ((t320 + t322) + t323) * t21) + t59 * t401) * t110) + t135) + (((t194 * t136
    + t155) + t275) + t277) * t84) - t59 * t22) + t573 * t194) - t23 * t59) +
    t10) + t270) - t249) - t258) - t274) - t273) - t117) - t12) - param->I__l4zz)
                     - param->I__l5xx) - param->I__l6yy) - param->I__l7zz) *
    t311 + ((((((((((-2.0 * t183 * t194 * -t173 - t456) * t84 + t399 * t135) +
                   t140 * t194 * t21) - t28 * t527) * t110 + -2.0 * t194 * t337 *
                 t248) + t353) + (t350_tmp * t356 + t475) * t84) - t347 * t21) +
             t586 * t194) - t28 * param->m__l4 * param->s__l4y * t338) * t369;
  t5 = t110 * -t173;
  t22 = t110 * t123 + t200;
  t23 = t360 * t110;
  tmpreturn[29] = ((((((2.0 * t5 * t194 - t203) * t142 + ((-t110 * t332 + t22 *
    t194) + t567) * t84) + (t23 + t264) * t194) - t93 * t110) - t265) - t34) *
    t369 - ((((((t470 * t590 + t404) - t95) * t84 + -t366) - (t110 * t19 - t21 *
    t92) * t25 * t194) + t581 * t110) + t558) * t311;
  t19 = -t372 * param->m__l7;
  t92 = -t377 * param->m__l6;
  tmpreturn[36] = (((-t26 * t110 - ((((((-t122 + t326) - t127) + t193) + t234) +
    param->I__l6zz) + param->I__l7xx) * t21) * t194 + (((t154 * t21 + t328) *
    t194 + t136 * t21) + t456) * t84) + t2 * t148) * t369 - ((((((((t122 + t229)
    + t127) + t19) + t92) - param->I__l6zz) - param->I__l7xx) * t110 + ((((t21 *
    -t80 + t235) + t245) - t66) * t84 + t110 * t2 * t553)) + -t144 * t2) * t311;
  t80 = t86_tmp * t84;
  t93 = (t80 + param->l__4) + param->l__5;
  t66 = (t4 * t84 + param->l__6) + param->s__l7z;
  t154 = t66 * param->s__l7y;
  t59 = param->s__l7x * t25;
  t125 = t21 * param->s__l7y;
  t128 = t25 * t84;
  t141 = t66 * param->s__l7x;
  t17 = param->s__l7y * t25;
  t18 = t21 * param->s__l7x;
  t36 = t110 * t84;
  tmpreturn[43] = ((-((((param->s__l7x * t110 * t93 - t154 * t21) * t194 + t59 *
                        t110) - t125 * t128) + t31 * t199) * param->m__l7 * t7 +
                    ((((param->s__l7y * t110 * t93 + t141 * t21) * t194 + t17 *
                       t110) + t18 * t128) + t31 * t544) * param->m__l7 * t13) +
                   (t536 * t2 - t358) * t153) * t369 - (((((((param->s__l7y *
    t36 + t18) * t25 * t194 + t154 * t110) + t18 * t80) + t166 * t21) + t31 *
    t17) * param->m__l7 * t7 + (((((param->s__l7x * t36 - t125) * t25 * t194 +
    t141 * t110) - t125 * t80) - t212 * t21) + t31 * t59) * param->m__l7 * t13)
    - t582 * t21) * t311;
  tmpreturn[2] = tmpreturn[14];
  tmpreturn[9] = tmpreturn[15];
  t25 = 2.0 * t2 * t173 * t84;
  t89 *= t4;
  t173 = t4 * -t189;
  t4 = t173 * t2;
  t311 = 2.0 * t4;
  t189 = t89 * t84;
  tmpreturn_tmp = t135 + t25;
  tmpreturn[16] = (((((((((((((((((((((((((((((((((((((((tmpreturn_tmp + t326) -
    t127) - t240) - t244) + t331) - param->I__l5xx) + param->I__l5yy) -
    param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz) * t248
    - t268) + t135) + (t299_tmp_0 - 2.0 * t89) * t84) + t120) + t287) - t311) +
    t291) + t293) - t274) + t302) * t306 + (((((((((((((t184 + t173) * t84 +
    t231) + t97) - t89 * t2) - t99) - t3) - t195) * t110 + t201) - t90) - t91) +
    t65) - t1081) - t220) * (2.0 * t28) * t194) + ((((((((((((t186 - t25) + t229)
    + t127) + t240) + t244) + t246) + param->I__l5xx) - param->I__l5yy) +
    param->I__l6yy) - param->I__l6zz) - param->I__l7xx) + param->I__l7zz) * t248)
    + t268) + 2.0 * t189) + t326) - t254) + t311) + ((((tmpreturn_tmp_tmp + t409)
    + t576) + t54) + t365) * param->m__l7) + t503) + t274) + t273) + t534) +
                        param->I__l7xx) + t164) + param->I__l5yy) +
                     param->I__l6zz) + param->I__l4xx) + t112) + param->I__l3zz;
  t31 = t100 - t88;
  tmpreturn[23] = ((((((((((t64 - t101) + t344) + (t78 - t30) * t2) + t213) +
                        t16) + t216) * t194 + t294 * t21) * t110 + (((t31 * t2 +
    t105) + t81) + t98) * (2.0 * t28) * t248) + t63 * t194 * t21) + ((((-t31 *
    t2 - t105) + t339) + t76) - t98) * t28) + t396;
  tmpreturn[30] = ((((((((t332_tmp_tmp + t229) + t127) + t106) + t40) +
                      param->I__l7yy) + t327) + param->I__l5zz) + param->I__l6xx)
    * t194 + (((2.0 * t5 * t142 + t22 * t84) + t23) + t264) * t28;
  t98 = ((((((-t189 + t229) + 2.0 * t286) - t4) + t19) + t92) - param->I__l6zz)
    - param->I__l7xx;
  tmpreturn[37] = ((((-2.0 * t69 * t84 * t67 * param->m__l7 + (-t75 * t84 - t87 *
    t96) * t7) + -t210 * t84) - t103) * t110 + t98 * t21) * t28 - ((((t11 * t80
    - t171) * t7 + -t101) + t102 * t84) + t346) * t194;
  t11 = param->s__l7y * t7 + t14;
  t84 = param->m__l7 * t60 * t2 * t86_tmp + t153 * t84;
  tmpreturn[44] = (param->m__l7 * t66 * t11 * t21 + t110 * t62) * t28 + t84 *
    t194;
  tmpreturn[3] = tmpreturn[21];
  tmpreturn[10] = tmpreturn[22];
  tmpreturn[17] = tmpreturn[23];
  tmpreturn[24] = ((((((((((((((2.0 * t110 * t21 * t337 + param->I__l4zz) +
    param->I__l5xx) + param->I__l6yy) + param->I__l7zz) - t10) + t186) - t270) +
    t273) + t274) + t280) + t132) + t12) + t249) + t258) + t117;
  tmpreturn[31] = t21 * t175 + t15;
  tmpreturn[38] = t98 * t110 - (t74 - t26) * t21;
  tmpreturn[45] = param->m__l7 * t110 * t66 * t11 - t62 * t21;
  tmpreturn[4] = tmpreturn[28];
  tmpreturn[11] = tmpreturn[29];
  tmpreturn[18] = tmpreturn[30];
  tmpreturn[25] = tmpreturn[31];
  tmpreturn[32] = (((((((tmpreturn_tmp + t229) + t127) + t106) + t40) +
                     param->I__l7yy) + param->I__l6xx) + t327) + param->I__l5zz;
  tmpreturn[39] = (((-t13 * t72 * t7 + t71) - t78) - t79) * t2 - t70;
  tmpreturn[46] = t84;
  tmpreturn[5] = tmpreturn[35];
  tmpreturn[12] = tmpreturn[36];
  tmpreturn[19] = tmpreturn[37];
  tmpreturn[26] = tmpreturn[38];
  tmpreturn[33] = tmpreturn[39];
  tmpreturn[40] = t35;
  tmpreturn[47] = -t87 * t11;
  tmpreturn[6] = tmpreturn[42];
  tmpreturn[13] = tmpreturn[43];
  tmpreturn[20] = tmpreturn[44];
  tmpreturn[27] = tmpreturn[45];
  tmpreturn[34] = t84;
  tmpreturn[41] = tmpreturn[47];
  tmpreturn[48] = t153;
}

// Function for MATLAB Function: '<Root>/Robot Model'
void controller_ballcatcherModelClass::iiwa_reduced_coriolis_matrix(const real_T
  q[7], const real_T q__p[7], const sYAUkIU1G7S9rEYvehBuTuE *param, real_T
  tmpreturn[49])
{
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t7;
  real_T t8;
  real_T t9;
  real_T t10;
  real_T t11;
  real_T t12;
  real_T t14;
  real_T t15;
  real_T t16;
  real_T t17;
  real_T t18;
  real_T t21;
  real_T t22;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t26;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t31;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T t35;
  real_T t38;
  real_T t39;
  real_T t40;
  real_T t41;
  real_T t42;
  real_T t43;
  real_T t45;
  real_T t46;
  real_T t47;
  real_T t48;
  real_T t49;
  real_T t50;
  real_T t51;
  real_T t52;
  real_T t53;
  real_T t54;
  real_T t56;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t60;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t67;
  real_T t68;
  real_T t69;
  real_T t70;
  real_T t71;
  real_T t72;
  real_T t73;
  real_T t74;
  real_T t76;
  real_T t77;
  real_T t78;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t85;
  real_T t86;
  real_T t87;
  real_T t89;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t98;
  real_T t99;
  real_T t100;
  real_T t101;
  real_T t102;
  real_T t105;
  real_T t106;
  real_T t107;
  real_T t108;
  real_T t109;
  real_T t110;
  real_T t111;
  real_T t112;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t116;
  real_T t117;
  real_T t118;
  real_T t119;
  real_T t120;
  real_T t122;
  real_T t123;
  real_T t124;
  real_T t126;
  real_T t127;
  real_T t128;
  real_T t130;
  real_T t132;
  real_T t133;
  real_T t136;
  real_T t139;
  real_T t140;
  real_T t142;
  real_T t143;
  real_T t144;
  real_T t145;
  real_T t146;
  real_T t147;
  real_T t148;
  real_T t149;
  real_T t150;
  real_T t151;
  real_T t152;
  real_T t154;
  real_T t155;
  real_T t156;
  real_T t157;
  real_T t158;
  real_T t160;
  real_T t163;
  real_T t166;
  real_T t167;
  real_T t170;
  real_T t171;
  real_T t172;
  real_T t173;
  real_T t174;
  real_T t175;
  real_T t178;
  real_T t179;
  real_T t180;
  real_T t181;
  real_T t182;
  real_T t183;
  real_T t184;
  real_T t185;
  real_T t187;
  real_T t188;
  real_T t189;
  real_T t191;
  real_T t192;
  real_T t193;
  real_T t194;
  real_T t195;
  real_T t196;
  real_T t197;
  real_T t199;
  real_T t200;
  real_T t201;
  real_T t203;
  real_T t204;
  real_T t205;
  real_T t206;
  real_T t207;
  real_T t209;
  real_T t211;
  real_T t214;
  real_T t215;
  real_T t216;
  real_T t217;
  real_T t218;
  real_T t219;
  real_T t220;
  real_T t221;
  real_T t222;
  real_T t225;
  real_T t226;
  real_T t227;
  real_T t228;
  real_T t229;
  real_T t230;
  real_T t231;
  real_T t232;
  real_T t233;
  real_T t234;
  real_T t235;
  real_T t236;
  real_T t239;
  real_T t240;
  real_T t241;
  real_T t243;
  real_T t245;
  real_T t246;
  real_T t248;
  real_T t249;
  real_T t251;
  real_T t252;
  real_T t253;
  real_T t254;
  real_T t255;
  real_T t256;
  real_T t257;
  real_T t258;
  real_T t259;
  real_T t260;
  real_T t261;
  real_T t262;
  real_T t263;
  real_T t264;
  real_T t265;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t269;
  real_T t270;
  real_T t271;
  real_T t274;
  real_T t275;
  real_T t276;
  real_T t277;
  real_T t278;
  real_T t281;
  real_T t282;
  real_T t283;
  real_T t284;
  real_T t288;
  real_T t289;
  real_T t290;
  real_T t291;
  real_T t293;
  real_T t294;
  real_T t295;
  real_T t296;
  real_T t297;
  real_T t299;
  real_T t300;
  real_T t301;
  real_T t302;
  real_T t303;
  real_T t304;
  real_T t305;
  real_T t306;
  real_T t308;
  real_T t309;
  real_T t310;
  real_T t311;
  real_T t312;
  real_T t313;
  real_T t314;
  real_T t315;
  real_T t316;
  real_T t317;
  real_T t319;
  real_T t320;
  real_T t321;
  real_T t324;
  real_T t325;
  real_T t326;
  real_T t327;
  real_T t328;
  real_T t329;
  real_T t330;
  real_T t331;
  real_T t332;
  real_T t334;
  real_T t335;
  real_T t336;
  real_T t337;
  real_T t338;
  real_T t340;
  real_T t341;
  real_T t342;
  real_T t343;
  real_T t344;
  real_T t345;
  real_T t346;
  real_T t347;
  real_T t349;
  real_T t350;
  real_T t351;
  real_T t352;
  real_T t353;
  real_T t354;
  real_T t356;
  real_T t358;
  real_T t359;
  real_T t360;
  real_T t361;
  real_T t362;
  real_T t364;
  real_T t365;
  real_T t366;
  real_T t367;
  real_T t370;
  real_T t371;
  real_T t372;
  real_T t373;
  real_T t374;
  real_T t375;
  real_T t376;
  real_T t377;
  real_T t380;
  real_T t381;
  real_T t383;
  real_T t385;
  real_T t386;
  real_T t387;
  real_T t389;
  real_T t392;
  real_T t395;
  real_T t396;
  real_T t398;
  real_T t400;
  real_T t401;
  real_T t402;
  real_T t404;
  real_T t406;
  real_T t407;
  real_T t408;
  real_T t411;
  real_T t412;
  real_T t413;
  real_T t414;
  real_T t415;
  real_T t416;
  real_T t417;
  real_T t418;
  real_T t419;
  real_T t422;
  real_T t423;
  real_T t424;
  real_T t426;
  real_T t427;
  real_T t428;
  real_T t429;
  real_T t431;
  real_T t432;
  real_T t433;
  real_T t434;
  real_T t435;
  real_T t438;
  real_T t439;
  real_T t440;
  real_T t442;
  real_T t446;
  real_T t447;
  real_T t448;
  real_T t449;
  real_T t450;
  real_T t452;
  real_T t453;
  real_T t455;
  real_T t456;
  real_T t457;
  real_T t458;
  real_T t463;
  real_T t464;
  real_T t465;
  real_T t466;
  real_T t467;
  real_T t469;
  real_T t471;
  real_T t473;
  real_T t474;
  real_T t475;
  real_T t479;
  real_T t481;
  real_T t482;
  real_T t484;
  real_T t486;
  real_T t487;
  real_T t489;
  real_T t490;
  real_T t491;
  real_T t495;
  real_T t496;
  real_T t497;
  real_T t499;
  real_T t500;
  real_T t501;
  real_T t503;
  real_T t504;
  real_T t505;
  real_T t506;
  real_T t508;
  real_T t509;
  real_T t510;
  real_T t511;
  real_T t512;
  real_T t513;
  real_T t514;
  real_T t515;
  real_T t516;
  real_T t517;
  real_T t519;
  real_T t521;
  real_T t522;
  real_T t523;
  real_T t524;
  real_T t525;
  real_T t526;
  real_T t529;
  real_T t530;
  real_T t532;
  real_T t533;
  real_T t534;
  real_T t537;
  real_T t538;
  real_T t539;
  real_T t541;
  real_T t542;
  real_T t543;
  real_T t544;
  real_T t545;
  real_T t549;
  real_T t550;
  real_T t551;
  real_T t552;
  real_T t553;
  real_T t554;
  real_T t555;
  real_T t557;
  real_T t558;
  real_T t561;
  real_T t562;
  real_T t564;
  real_T t565;
  real_T t566;
  real_T t567;
  real_T t568;
  real_T t570;
  real_T t571;
  real_T t572;
  real_T t573;
  real_T t575;
  real_T t576;
  real_T t578;
  real_T t579;
  real_T t580;
  real_T t586;
  real_T t588;
  real_T t589;
  real_T t592;
  real_T t593;
  real_T t595;
  real_T t596;
  real_T t598;
  real_T t599;
  real_T t600;
  real_T t601;
  real_T t605;
  real_T t606;
  real_T t607;
  real_T t608;
  real_T t609;
  real_T t613;
  real_T t614;
  real_T t615;
  real_T t617;
  real_T t618;
  real_T t622;
  real_T t623;
  real_T t625;
  real_T t626;
  real_T t627;
  real_T t628;
  real_T t633;
  real_T t634;
  real_T t638;
  real_T t639;
  real_T t640;
  real_T t643;
  real_T t644;
  real_T t645;
  real_T t649;
  real_T t650;
  real_T t653;
  real_T t657;
  real_T t659;
  real_T t660;
  real_T t661;
  real_T t662;
  real_T t665;
  real_T t666;
  real_T t667;
  real_T t668;
  real_T t669;
  real_T t670;
  real_T t671;
  real_T t672;
  real_T t675;
  real_T t676;
  real_T t677;
  real_T t678;
  real_T t679;
  real_T t680;
  real_T t684;
  real_T t685;
  real_T t688;
  real_T t690;
  real_T t693;
  real_T t694;
  real_T t695;
  real_T t696;
  real_T t697;
  real_T t698;
  real_T t699;
  real_T t700;
  real_T t701;
  real_T t704;
  real_T t705;
  real_T t706;
  real_T t707;
  real_T t708;
  real_T t709;
  real_T t712;
  real_T t714;
  real_T t715;
  real_T t716;
  real_T t717;
  real_T t720;
  real_T t721;
  real_T t722;
  real_T t723;
  real_T t724;
  real_T t725;
  real_T t726;
  real_T t729;
  real_T t730;
  real_T t731;
  real_T t732;
  real_T t733;
  real_T t734;
  real_T t735;
  real_T t738;
  real_T t740;
  real_T t741;
  real_T t744;
  real_T t746;
  real_T t749;
  real_T t750;
  real_T t752;
  real_T t753;
  real_T t757;
  real_T t758;
  real_T t761;
  real_T t762;
  real_T t763;
  real_T t764;
  real_T t767;
  real_T t770;
  real_T t771;
  real_T t772;
  real_T t773;
  real_T t775;
  real_T t777;
  real_T t780;
  real_T t781;
  real_T t784;
  real_T t785;
  real_T t786;
  real_T t787;
  real_T t788;
  real_T t789;
  real_T t791;
  real_T t792;
  real_T t793;
  real_T t796;
  real_T t797;
  real_T t798;
  real_T t799;
  real_T t800;
  real_T t801;
  real_T t802;
  real_T t805;
  real_T t806;
  real_T t807;
  real_T t808;
  real_T t810;
  real_T t811;
  real_T t814;
  real_T t815;
  real_T t817;
  real_T t818;
  real_T t821;
  real_T t822;
  real_T t823;
  real_T t824;
  real_T t825;
  real_T t828;
  real_T t831;
  real_T t832;
  real_T t833;
  real_T t834;
  real_T t837;
  real_T t839;
  real_T t840;
  real_T t842;
  real_T t847;
  real_T t848;
  real_T t849;
  real_T t851;
  real_T t854;
  real_T t855;
  real_T t856;
  real_T t858;
  real_T t859;
  real_T t860;
  real_T t863;
  real_T t866;
  real_T t867;
  real_T t868;
  real_T t871;
  real_T t875;
  real_T t876;
  real_T t877;
  real_T t878;
  real_T t879;
  real_T t880;
  real_T t881;
  real_T t885;
  real_T t886;
  real_T t888;
  real_T t889;
  real_T t890;
  real_T t891;
  real_T t892;
  real_T t893;
  real_T t894;
  real_T t895;
  real_T t896;
  real_T t897;
  real_T t898;
  real_T t899;
  real_T t906;
  real_T t912;
  real_T t913;
  real_T t914;
  real_T t915;
  real_T t918;
  real_T t919;
  real_T t920;
  real_T t921;
  real_T t927;
  real_T t930;
  real_T t932;
  real_T t933;
  real_T t937;
  real_T t938;
  real_T t939;
  real_T t940;
  real_T t941;
  real_T t942;
  real_T t943;
  real_T t946;
  real_T t947;
  real_T t948;
  real_T t949;
  real_T t952;
  real_T t955;
  real_T t956;
  real_T t957;
  real_T t958;
  real_T t960;
  real_T t963;
  real_T t964;
  real_T t965;
  real_T t966;
  real_T t967;
  real_T t968;
  real_T t969;
  real_T t970;
  real_T t972;
  real_T t973;
  real_T t974;
  real_T t976;
  real_T t977;
  real_T t979;
  real_T t980;
  real_T t981;
  real_T t984;
  real_T t987;
  real_T t991;
  real_T t992;
  real_T t994;
  real_T t995;
  real_T t996;
  real_T t999;
  real_T t1002;
  real_T t1003;
  real_T t1004;
  real_T t1005;
  real_T t1006;
  real_T t1008;
  real_T t1012;
  real_T t1013;
  real_T t1014;
  real_T t1015;
  real_T t1017;
  real_T t1018;
  real_T t1019;
  real_T t1020;
  real_T t1021;
  real_T t1022;
  real_T t1023;
  real_T t1026;
  real_T t1027;
  real_T t1028;
  real_T t1029;
  real_T t1030;
  real_T t1031;
  real_T t1032;
  real_T t1033;
  real_T t1034;
  real_T t1035;
  real_T t1038;
  real_T t1039;
  real_T t1040;
  real_T t1041;
  real_T t1043;
  real_T t1044;
  real_T t1045;
  real_T t1047;
  real_T t1048;
  real_T t1049;
  real_T t1051;
  real_T t1054;
  real_T t1055;
  real_T t1057;
  real_T t1059;
  real_T t1060;
  real_T t1063;
  real_T t1066;
  real_T t1069;
  real_T t1070;
  real_T t1072;
  real_T t1074;
  real_T t1076;
  real_T t1077;
  real_T t1079;
  real_T t1080;
  real_T t1081;
  real_T t1082;
  real_T t1085;
  real_T t1087;
  real_T t1089;
  real_T t1091;
  real_T t1092;
  real_T t1093;
  real_T t1096;
  real_T t1099;
  real_T t1100;
  real_T t1101;
  real_T t1103;
  real_T t1104;
  real_T t1105;
  real_T t1108;
  real_T t1110;
  real_T t1116;
  real_T t1117;
  real_T t1118;
  real_T t1119;
  real_T t1120;
  real_T t1121;
  real_T t1123;
  real_T t1124;
  real_T t1126;
  real_T t1127;
  real_T t1128;
  real_T t1130;
  real_T t1132;
  real_T t1133;
  real_T t1134;
  real_T t1136;
  real_T t1137;
  real_T t1138;
  real_T t1139;
  real_T t1140;
  real_T t1141;
  real_T t1142;
  real_T t1145;
  real_T t1147;
  real_T t1151;
  real_T t1152;
  real_T t1154;
  real_T t1155;
  real_T t1157;
  real_T t1158;
  real_T t1160;
  real_T t1163;
  real_T t1164;
  real_T t1170;
  real_T t1173;
  real_T t1175;
  real_T t1177;
  real_T t1178;
  real_T t1179;
  real_T t1181;
  real_T t1182;
  real_T t1183;
  real_T t1185;
  real_T t1186;
  real_T t1187;
  real_T t1189;
  real_T t1194;
  real_T t1195;
  real_T t1197;
  real_T t1199;
  real_T t1202;
  real_T t1204;
  real_T t1210;
  real_T t1213;
  real_T t1214;
  real_T t1216;
  real_T t1222;
  real_T t1226;
  real_T t1230;
  real_T t1232;
  real_T t1233;
  real_T t1235;
  real_T t1239;
  real_T t1240;
  real_T t1250;
  real_T t1257;
  real_T t1258;
  real_T t1259;
  real_T t1260;
  real_T t1262;
  real_T t1263;
  real_T t1269;
  real_T t1270;
  real_T t1271;
  real_T t1273;
  real_T t1274;
  real_T t1277;
  real_T t1278;
  real_T t1281;
  real_T t1283;
  real_T t1284;
  real_T t1289;
  real_T t1290;
  real_T t1292;
  real_T t1293;
  real_T t1296;
  real_T t1297;
  real_T t1298;
  real_T t1301;
  real_T t1302;
  real_T t1303;
  real_T t1304;
  real_T t1305;
  real_T t1308;
  real_T t1309;
  real_T t1314;
  real_T t1316;
  real_T t1319;
  real_T t1322;
  real_T t1326;
  real_T t1327;
  real_T t1329;
  real_T t1330;
  real_T t1331;
  real_T t1334;
  real_T t1337;
  real_T t1338;
  real_T t1339;
  real_T t1345;
  real_T t1346;
  real_T t1347;
  real_T t1348;
  real_T t1352;
  real_T t1353;
  real_T t1354;
  real_T t1359;
  real_T t1362;
  real_T t1363;
  real_T t1368;
  real_T t1369;
  real_T t1371;
  real_T t1373;
  real_T t1374;
  real_T t1378;
  real_T t1382;
  real_T t1384;
  real_T t1387;
  real_T t1389;
  real_T t1393;
  real_T t1394;
  real_T t1395;
  real_T t1397;
  real_T t1398;
  real_T t1399;
  real_T t1401;
  real_T t1403;
  real_T t1406;
  real_T t1411;
  real_T t1412;
  real_T t1416;
  real_T t1417;
  real_T t1419;
  real_T t1420;
  real_T t1423;
  real_T t1424;
  real_T t1426;
  real_T t1429;
  real_T t1431;
  real_T t1432;
  real_T t1433;
  real_T t1436;
  real_T t1437;
  real_T t1443;
  real_T t1446;
  real_T t1447;
  real_T t1451;
  real_T t1452;
  real_T t1456;
  real_T t1457;
  real_T t1458;
  real_T t1460;
  real_T t1462;
  real_T t1476;
  real_T t1484;
  real_T t1489;
  real_T t1492;
  real_T t1496;
  real_T t1503;
  real_T t1510;
  real_T t1511;
  real_T t1519;
  real_T t1520;
  real_T t1523;
  real_T t1534;
  real_T t1535;
  real_T t1540;
  real_T t1541;
  real_T t1544;
  real_T t1546;
  real_T t1551;
  real_T t1567;
  real_T t1569;
  real_T t1573;
  real_T t1578;
  real_T t1580;
  real_T t1582;
  real_T t1583;
  real_T t1586;
  real_T t1596;
  real_T t1597;
  real_T t1600;
  real_T t1601;
  real_T t1603;
  real_T t1608;
  real_T t1609;
  real_T t1616;
  real_T t1619;
  real_T t1620;
  real_T t1629;
  real_T t1639;
  real_T t1640;
  real_T t1644;
  real_T t1648;
  real_T t1663;
  real_T t1664;
  real_T t1666;
  real_T t1667;
  real_T t1668;
  real_T t1676;
  real_T t1678;
  real_T t1680;
  real_T t1681;
  real_T t1684;
  real_T t1689;
  real_T t1707;
  real_T t1709;
  real_T t1714;
  real_T t1718;
  real_T t1721;
  real_T t1724;
  real_T t1733;
  real_T t1736;
  real_T t1738;
  real_T t1739;
  real_T t1740;
  real_T t1747;
  real_T t1755;
  real_T t1757;
  real_T t1761;
  real_T t1763;
  real_T t1764;
  real_T t1774;
  real_T t1780;
  real_T t1782;
  real_T t1787;
  real_T t1788;
  real_T t1791;
  real_T t1794;
  real_T t1798;
  real_T t1799;
  real_T t1806;
  real_T t1818;
  real_T t1819;
  real_T t1822;
  real_T t1825;
  real_T t1826;
  real_T t1829;
  real_T t1831;
  real_T t1839;
  real_T t1845;
  real_T t1850;
  real_T t1853;
  real_T t1854;
  real_T t1858;
  real_T t1859;
  real_T t1861;
  real_T t1862;
  real_T t1863;
  real_T t1865;
  real_T t1871;
  real_T t1876;
  real_T t1877;
  real_T t1882;
  real_T t1884;
  real_T t1971;
  real_T t1990;
  real_T t2003;
  real_T t2009;
  real_T t2010;
  real_T t2013;
  real_T t2031;
  real_T t2032;
  real_T t2036;
  real_T t2038;
  real_T t2050;
  real_T t2052;
  real_T t2057;
  real_T t2085;
  real_T t2093;
  real_T t2097;
  real_T t2099;
  real_T t2101;
  real_T t2108;
  real_T t2110;
  real_T t2115;
  real_T t2119;
  real_T t2121;
  real_T t2122;
  real_T t2123;
  real_T t2129;
  real_T t2135;
  real_T t2137;
  real_T t2139;
  real_T t2143;
  real_T t2145;
  real_T t2147;
  real_T t2149;
  real_T t2152;
  real_T t2154;
  real_T t2155;
  real_T t2162;
  real_T t2163;
  real_T t2168;
  real_T t2169;
  real_T t2170;
  real_T t2173;
  real_T t2185;
  real_T t2189;
  real_T t2190;
  real_T t2191;
  real_T t2195;
  real_T t2198;
  real_T t2205;
  real_T t2217;
  real_T t2223;
  real_T t2227;
  real_T t2230;
  real_T t2231;
  real_T t2235;
  real_T t2237;
  real_T t2238;
  real_T t2239;
  real_T t2241;
  real_T t2244;
  real_T t2248;
  real_T t2250;
  real_T t2254;
  real_T t2255;
  real_T t2259;
  real_T t2265;
  real_T t2266;
  real_T t2268;
  real_T t2277;
  real_T t2279;
  real_T t2280;
  real_T t2284;
  real_T t2289;
  real_T t2294;
  real_T t2303;
  real_T t2304;
  real_T t2307;
  real_T t2309;
  real_T t2311;
  real_T t2315;
  real_T t2316;
  real_T t2319;
  real_T t2335;
  real_T t2347;
  real_T t2348;
  real_T t2350;
  real_T t2351;
  real_T t2352;
  real_T t2353;
  real_T t2354;
  real_T t2357;
  real_T t2358;
  real_T t2359;
  real_T t2362;
  real_T t2364;
  real_T t2369;
  real_T t2383;
  real_T t2385;
  real_T t2389;
  real_T t2397;
  real_T t2399;
  real_T t2400;
  real_T t2402;
  real_T t2407;
  real_T t2410;
  real_T t2411;
  real_T t2413;
  real_T t2414;
  real_T t2415;
  real_T t2421;
  real_T t2422;
  real_T t2423;
  real_T t2426;
  real_T t2434;
  real_T t2436;
  real_T t2437;
  real_T t2438;
  real_T t2440;
  real_T t2441;
  real_T t2444;
  real_T t2448;
  real_T t2449;
  real_T t2452;
  real_T t2453;
  real_T t2457;
  real_T t2458;
  real_T t2469;
  real_T t2472;
  real_T t2473;
  real_T t2475;
  real_T t2483;
  real_T t2485;
  real_T t2492;
  real_T t2496;
  real_T t2497;
  real_T t2506;
  real_T t2509;
  real_T t2518;
  real_T t2540;
  real_T t2547;
  real_T t2554;
  real_T t2576;
  real_T t2578;
  real_T t2586;
  real_T t2593;
  real_T t2598;
  real_T t2625;
  real_T t2635;
  real_T t2641;
  real_T t2643;
  real_T t2644;
  real_T t2645;
  real_T t2646;
  real_T t2652;
  real_T t2659;
  real_T t2660;
  real_T t2661;
  real_T t2662;
  real_T t2665;
  real_T t2681;
  real_T t2692;
  real_T t2695;
  real_T t2698;
  real_T t2702;
  real_T t2707;
  real_T t2711;
  real_T t2713;
  real_T t2715;
  real_T t2716;
  real_T t2735;
  real_T t2746;
  real_T t2748;
  real_T t2754;
  real_T t2763;
  real_T t2776;
  real_T t2778;
  real_T t2794;
  real_T t2808;
  real_T t2819;
  real_T t2820;
  real_T t2842;
  real_T t2843;
  real_T t2848;
  real_T t2849;
  real_T t2853;
  real_T t2856;
  real_T t2863;
  real_T t2864;
  real_T t2880;
  real_T t2881;
  real_T t2887;
  real_T t2892;
  real_T t2893;
  real_T t2900;
  real_T t2903;
  real_T t2904;
  real_T t2910;
  real_T t2911;
  real_T t2912;
  real_T t2913;
  real_T t2914;
  real_T t2917;
  real_T t2923;
  real_T t2936;
  real_T t2938;
  real_T t2939;
  real_T t2945;
  real_T t2947;
  real_T t2948;
  real_T t2949;
  real_T t2950;
  real_T t2956;
  real_T t2957;
  real_T t2971;
  real_T t2973;
  real_T t2983;
  real_T t3001;
  real_T t3004;
  real_T t3010;
  real_T t3017;
  real_T t3018;
  real_T t3019;
  real_T t3024;
  real_T t3040;
  real_T t3093;
  real_T t3100;
  real_T t3113;
  real_T t3115;
  real_T t3120;
  real_T t3169;
  real_T t3172;
  real_T t3183;
  real_T t3185;
  real_T t3193;
  real_T t3197;
  real_T t3198;
  real_T t3203;
  real_T t3204;
  real_T t3208;
  real_T t3210;
  real_T t3217;
  real_T t3226;
  real_T t3229;
  real_T t3230;
  real_T t3233;
  real_T t3235;
  real_T t3236;
  real_T t3252;
  real_T t3268;
  real_T t3292;
  real_T t3294;
  real_T t3301;
  real_T t3303;
  real_T t3307;
  real_T t3310;
  real_T t3314;
  real_T t3319;
  real_T t3323;
  real_T t3324;
  real_T t3325;
  real_T t3326;
  real_T t3327;
  real_T t3328;
  real_T t3329;
  real_T t3330;
  real_T t3331;
  real_T t3344;
  real_T t3345;
  real_T t3346;
  real_T t3355;
  real_T t3356;
  real_T t3369;
  real_T t3372;
  real_T t3397;
  real_T t3402;
  real_T t3408;
  real_T t3412;
  real_T t3423;
  real_T t3425;
  real_T t3430;
  real_T t3431;
  real_T t3432;
  real_T t3437;
  real_T t3438;
  real_T t3444;
  real_T t3466;
  real_T t3469;
  real_T t3486;
  real_T t3491;
  real_T t3494;
  real_T t3503;
  real_T t3506;
  real_T t3522;
  real_T t3530;
  real_T t3538;
  real_T t3545;
  real_T t3560;
  real_T t3568;
  real_T t3573;
  real_T t3574;
  real_T t3575;
  real_T t3576;
  real_T t3584;
  real_T t3585;
  real_T t3588;
  real_T t3590;
  real_T t3591;
  real_T t3592;
  real_T t3601;
  real_T t3602;
  real_T t3611;
  real_T t3623;
  real_T t3634;
  real_T t3635;
  real_T t3652;
  real_T t3657;
  real_T t3663;
  real_T t3664;
  real_T t3675;
  real_T t3679;
  real_T t3681;
  real_T t3686;
  real_T t3687;
  real_T t3696;
  real_T t3697;
  real_T t3699;
  real_T t3700;
  real_T t3701;
  real_T t3714;
  real_T t3715;
  real_T t3721;
  real_T t3726;
  real_T t3730;
  real_T t3731;
  real_T t3786;
  real_T t3796;
  real_T t3806;
  real_T t3819;
  real_T t3823;
  real_T t3826;
  real_T t3827;
  real_T t3828;
  real_T t3832;
  real_T t3833;
  real_T t3838;
  real_T t3839;
  real_T t3866;
  real_T t3875;
  real_T t3881;
  real_T t3882;
  real_T t3883;
  real_T t3887;
  real_T t3891;
  real_T t3895;
  real_T t3896;
  real_T t3903;
  real_T t3908;
  real_T t3910;
  real_T t3916;
  real_T t3918;
  real_T t3933;
  real_T t3934;
  real_T t3936;
  real_T t3938;
  real_T t3940;
  real_T t3941;
  real_T t3944;
  real_T t3947;
  real_T t3949;
  real_T t3950;
  real_T t3951;
  real_T t3956;
  real_T t3964;
  real_T t3965;
  real_T t3993;
  real_T t4000;
  real_T t4010;
  real_T t4015;
  real_T t4024;
  real_T t4032;
  real_T t4033;
  real_T t4044;
  real_T t4048;
  real_T t4050;
  real_T t4054;
  real_T t4060;
  real_T t4065;
  real_T t4067;
  real_T t4068;
  real_T t4071;
  real_T t4072;
  real_T t4073;
  real_T t4078;
  real_T t4082;
  real_T t4087;
  real_T t4110;
  real_T t4113;
  real_T t4116;
  real_T t4121;
  real_T t4171;
  real_T t4180;
  real_T t4185;
  real_T t4186;
  real_T t4191;
  real_T t4203;
  real_T t4204;
  real_T t4207;
  real_T t4210;
  real_T t4216;
  real_T t4220;
  real_T t4222;
  real_T t4227;
  real_T t4229;
  real_T t4231;
  real_T t4243;
  real_T t4246;
  real_T t4266;
  real_T t4273;
  real_T t4291;
  real_T t4297;
  real_T t4320;
  real_T t4323;
  real_T t4324;
  real_T t4327;
  real_T t4330;
  real_T t4331;
  real_T t4332;
  real_T t4335;
  real_T t4345;
  real_T t4346;
  real_T t4349;
  real_T t4354;
  real_T t4355;
  real_T t4357;
  real_T t4360;
  real_T t4362;
  real_T t4365;
  real_T t4370;
  real_T t4372;
  real_T t4379;
  real_T t4380;
  real_T t4381;
  real_T t4382;
  real_T t4384;
  real_T t4395;
  real_T t4407;
  real_T t4409;
  real_T t4411;
  real_T t4413;
  real_T t4421;
  real_T t4425;
  real_T t4426;
  real_T t4427;
  real_T t4444;
  real_T t4445;
  real_T t4447;
  real_T t4449;
  real_T t4452;
  real_T t4458;
  real_T t4459;
  real_T t4464;
  real_T t4476;
  real_T t4494;
  real_T t4496;
  real_T t4497;
  real_T t4503;
  real_T t4505;
  real_T t4517;
  real_T t4526;
  real_T t4528;
  real_T t4533;
  real_T t4537;
  real_T t4538;
  real_T t4539;
  real_T t4540;
  real_T t4550;
  real_T t4564;
  real_T t4572;
  real_T t4583;
  real_T t4589;
  real_T t4594;
  real_T t4599;
  real_T t4607;
  real_T t4608;
  real_T t4613;
  real_T t4614;
  real_T t4620;
  real_T t4623;
  real_T t4626;
  real_T t4629;
  real_T t4630;
  real_T t4631;
  real_T t4632;
  real_T t4635;
  real_T t4640;
  real_T t4641;
  real_T t4642;
  real_T t4653;
  real_T t4657;
  real_T t4658;
  real_T t4661;
  real_T t4670;
  real_T t4676;
  real_T t4679;
  real_T t4681;
  real_T t4693;
  real_T t4711;
  real_T t4714;
  real_T t4733;
  real_T t4739;
  real_T t4742;
  real_T t4748;
  real_T t4751;
  real_T t4752;
  real_T t4754;
  real_T t4766;
  real_T t4772;
  real_T t4775;
  real_T t4782;
  real_T t4783;
  real_T t4797;
  real_T t4800;
  real_T t4807;
  real_T t4810;
  real_T t4824;
  real_T t4830;
  real_T t4836;
  real_T t4842;
  real_T t4844;
  real_T t4846;
  real_T t4854;
  real_T t4855;
  real_T t4856;
  real_T t4857;
  real_T t4858;
  real_T t4859;
  real_T t4860;
  real_T t4874;
  real_T t4875;
  real_T t4876;
  real_T t4880;
  real_T t4888;
  real_T t4889;
  real_T t4890;
  real_T t4893;
  real_T t4913;
  real_T t4914;
  real_T t4918;
  real_T t4920;
  real_T t4921;
  real_T t4922;
  real_T t4928;
  real_T t4933;
  real_T t4971;
  real_T t4982;
  real_T t4996;
  real_T t5052;
  real_T t5054;
  real_T t5067;
  real_T t5071;
  real_T t5076;
  real_T t5077;
  real_T t5082;
  real_T t5083;
  real_T t5085;
  real_T t5086;
  real_T t5101;
  real_T t5103;
  real_T t5105;
  real_T t5118;
  real_T t5171;
  real_T t5172;
  real_T t5191;
  real_T t5208;
  real_T t5226;
  real_T t5228;
  real_T t5230;
  real_T t5231;
  real_T t5286;
  real_T t5299;
  real_T t5300;
  real_T t5301;
  real_T t5303;
  real_T t5304;
  real_T t5305;
  real_T t5310;
  real_T t5344;
  real_T t5363;
  real_T t5370;
  real_T t5374;
  real_T t5398;
  real_T t5458;
  real_T t5479;
  real_T t5480;
  real_T t5481;
  real_T t5491;
  real_T t5492;
  real_T t5496;
  real_T t5502;
  real_T t5524;
  real_T t5525;
  real_T t5526;
  real_T t5546;
  real_T t5547;
  real_T t5558;
  real_T t5571;
  real_T t5572;
  real_T t5584;
  real_T t5585;
  real_T t5598;
  real_T t5616;
  real_T t5626;
  real_T t5628;
  real_T t5629;
  real_T t5633;
  real_T t5635;
  real_T t5658;
  real_T t5690;
  real_T t5691;
  real_T t5694;
  real_T t5710;
  real_T t5726;
  real_T t5727;
  real_T t5729;
  real_T t5731;
  real_T t5748;
  real_T t5760;
  real_T t5761;
  real_T t5762;
  real_T t5763;
  real_T t5764;
  real_T t5769;
  real_T t5778;
  real_T t5779;
  real_T t5796;
  real_T t5805;
  real_T t5809;
  real_T t5826;
  real_T t5828;
  real_T t5831;
  real_T t5833;
  real_T t5842;
  real_T t5843;
  real_T t5860;
  real_T t5864;
  real_T t5867;
  real_T t5868;
  real_T t5869;
  real_T t5874;
  real_T t5875;
  real_T t5899;
  real_T t5908;
  real_T t5922;
  real_T t5927;
  real_T t5928;
  real_T t5935;
  real_T t5946;
  real_T t5947;
  real_T t5948;
  real_T t5949;
  real_T t5950;
  real_T t5956;
  real_T t5957;
  real_T t5959;
  real_T t5973;
  real_T t6026;
  real_T t6027;
  real_T t6033;
  real_T t6034;
  real_T t6035;
  real_T t6039;
  real_T t6040;
  real_T t6055;
  real_T t6057;
  real_T t6060;
  real_T t6083;
  real_T t6092;
  real_T t6099;
  real_T t6109;
  real_T t6113;
  real_T t6119;
  real_T t6125;
  real_T t6126;
  real_T t6137;
  real_T t6139;
  real_T t6148;
  real_T t6152;
  real_T t6159;
  real_T t6162;
  real_T t6164;
  real_T t6175;
  real_T t6193;
  real_T t6194;
  real_T t6197;
  real_T t6205;
  real_T t6209;
  real_T t6222;
  real_T t6227;
  real_T t6240;
  real_T t6244;
  real_T t6245;
  real_T t6247;
  real_T t6252;
  real_T t6253;
  real_T t6259;
  real_T t6261;
  real_T t6263;
  real_T t6268;
  real_T t6273;
  real_T t6274;
  real_T t6277;
  real_T t6278;
  real_T t6279;
  real_T t6281;
  real_T t6284;
  real_T t6285;
  real_T t6290;
  real_T t6296;
  real_T t6300;
  real_T t6301;
  real_T t6306;
  real_T t6309;
  real_T t6310;
  real_T t6315;
  real_T t6316;
  real_T t6328;
  real_T t6331;
  real_T t6334;
  real_T t6335;
  real_T t6341;
  real_T t6347;
  real_T t6349;
  real_T t6350;
  real_T t6353;
  real_T t6356;
  real_T t6359;
  real_T t6363;
  real_T t6366;
  real_T t6368;
  real_T t6370;
  real_T t6372;
  real_T t6377;
  real_T t6378;
  real_T t6386;
  real_T t6402;
  real_T t6410;
  real_T t6411;
  real_T t6414;
  real_T t6421;
  real_T t6427;
  real_T t6429;
  real_T t6445;
  real_T t6449;
  real_T t6451;
  real_T t6452;
  real_T t6458;
  real_T t6459;
  real_T t6467;
  real_T t6473;
  real_T t6488;
  real_T t6497;
  real_T t6510;
  real_T t6512;
  real_T t6514;
  real_T t6523;
  real_T t6524;
  real_T t6525;
  real_T t6526;
  real_T t6529;
  real_T t6543;
  real_T t6556;
  real_T t6557;
  real_T t6560;
  real_T t6568;
  real_T t6569;
  real_T t6570;
  real_T t6581;
  real_T t6585;
  real_T t6587;
  real_T t6590;
  real_T t6592;
  real_T t6615;
  real_T t6628;
  real_T t6632;
  real_T t6638;
  real_T t6643;
  real_T t6644;
  real_T t6664;
  real_T t6669;
  real_T t6670;
  real_T t6671;
  real_T t6679;
  real_T t6682;
  real_T t6683;
  real_T t6689;
  real_T t6695;
  real_T t6698;
  real_T t6699;
  real_T t6700;
  real_T t6705;
  real_T t6717;
  real_T t6722;
  real_T t6723;
  real_T t6725;
  real_T t6726;
  real_T t6727;
  real_T t6728;
  real_T t6729;
  real_T t6733;
  real_T t6738;
  real_T t6739;
  real_T t6740;
  real_T t6741;
  real_T t6744;
  real_T t6745;
  real_T t6746;
  real_T t6747;
  real_T t6748;
  real_T t6752;
  real_T t6754;
  real_T t6755;
  real_T t6764;
  real_T t6766;
  real_T t6767;
  real_T t6770;
  real_T t6778;
  real_T t6779;
  real_T t6781;
  real_T t6782;
  real_T t6783;
  real_T t6797;
  real_T t6807;
  real_T t6817;
  real_T t6818;
  real_T t6819;
  real_T t6821;
  real_T t6822;
  real_T t6825;
  real_T t6828;
  real_T t6833;
  real_T t6834;
  real_T t6837;
  real_T t6839;
  real_T t6841;
  real_T t6844;
  real_T t6848;
  real_T t6849;
  real_T t6852;
  real_T t6853;
  real_T t6856;
  real_T t6861;
  real_T t6868;
  real_T t6870;
  real_T t6873;
  real_T t6877;
  real_T t6880;
  real_T t6882;
  real_T t6883;
  real_T t6884;
  real_T t6887;
  real_T t6889;
  real_T t6892;
  real_T t6895;
  real_T t6896;
  real_T t6897;
  real_T t6902;
  real_T t6903;
  real_T t6904;
  real_T t6906;
  real_T t6908;
  real_T t6911;
  real_T t6912;
  real_T t6913;
  real_T t6914;
  real_T t6918;
  real_T t6919;
  real_T t6920;
  real_T t6921;
  real_T t6922;
  real_T t6926;
  real_T t6931;
  real_T t6932;
  real_T t6933;
  real_T t6936;
  real_T t6943;
  real_T t6947;
  real_T t6949;
  real_T t6961;
  real_T t6963;
  real_T t6967;
  real_T t6972;
  real_T t6975;
  real_T t6976;
  real_T t6977;
  real_T t6983;
  real_T t6987;
  real_T t6989;
  real_T t6992;
  real_T t6996;
  real_T t6998;
  real_T t7004;
  real_T t7005;
  real_T t7010;
  real_T t7013;
  real_T t7015;
  real_T t7023;
  real_T t7026;
  real_T t7039;
  real_T t7044;
  real_T t7047;
  real_T t7049;
  real_T t7051;
  real_T t7055;
  real_T t7060;
  real_T t7063;
  real_T t7064;
  real_T t7065;
  real_T t7068;
  real_T t7069;
  real_T t7070;
  real_T t7075;
  real_T t7077;
  real_T t7080;
  real_T t7081;
  real_T t7083;
  real_T t7085;
  real_T t7087;
  real_T t7095;
  real_T t7105;
  real_T t7111;
  real_T t7115;
  real_T t7117;
  real_T t7122;
  real_T t7124;
  real_T t7126;
  real_T t7128;
  real_T t7130;
  real_T t7136;
  real_T t7139;
  real_T t7146;
  real_T t7149;
  real_T t7150;
  real_T t7151;
  real_T t7153;
  real_T t7156;
  real_T t7160;
  real_T t7161;
  real_T t7166;
  real_T t7170;
  real_T t7173;
  real_T t7181;
  real_T t7192;
  real_T t7194;
  real_T t7196;
  real_T t7201;
  real_T t7202;
  real_T t7203;
  real_T t7207;
  real_T t7216;
  real_T t7220;
  real_T t7221;
  real_T t7222;
  real_T t7228;
  real_T t7229;
  real_T t7231;
  real_T t7232;
  real_T t7236;
  real_T t7241;
  real_T t7248;
  real_T t7252;
  real_T t7255;
  real_T t7263;
  real_T t7265;
  real_T t7266;
  real_T t7268;
  real_T t7278;
  real_T t7281;
  real_T t7282;
  real_T t7288;
  real_T t7294;
  real_T t7297;
  real_T t7298;
  real_T t7300;
  real_T t7311;
  real_T t7314;
  real_T t7316;
  real_T t7325;
  real_T t7334;
  real_T t7337;
  real_T t7340;
  real_T t7344;
  real_T t7347;
  real_T t7352;
  real_T t7355;
  real_T t7360;
  real_T t7361;
  real_T t7362;
  real_T t7365;
  real_T t7367;
  real_T t7369;
  real_T t7371;
  real_T t7372;
  real_T t7376;
  real_T t7379;
  real_T t7386;
  real_T t7387;
  real_T t7392;
  real_T t7395;
  real_T t7396;
  real_T t7397;
  real_T t7398;
  real_T t7402;
  real_T t7405;
  real_T t7407;
  real_T t7409;
  real_T t7414;
  real_T t7417;
  real_T t7420;
  real_T t7421;
  real_T t7425;
  real_T t7430;
  real_T t7431;
  real_T t7437;
  real_T t7440;
  real_T t7443;
  real_T t7444;
  real_T t7447;
  real_T t7450;
  real_T t7452;
  real_T t7463;
  real_T t7465;
  real_T t7467;
  real_T t7478;
  real_T t7480;
  real_T t7494;
  real_T t7500;
  real_T t7518;
  real_T t7519;
  real_T t7521;
  real_T t7524;
  real_T t7532;
  real_T t7537;
  real_T t7539;
  real_T t7542;
  real_T t7543;
  real_T t7552;
  real_T t7555;
  real_T t7558;
  real_T t7565;
  real_T t7586;
  real_T t7596;
  real_T t7607;
  real_T t7614;
  real_T t7616;
  real_T t7617;
  real_T t7625;
  real_T t7626;
  real_T t7627;
  real_T t7634;
  real_T t7645;
  real_T t7651;
  real_T t7654;
  real_T t7655;
  real_T t7656;
  real_T t7658;
  real_T t7666;
  real_T t7669;
  real_T t7676;
  real_T t7677;
  real_T t7684;
  real_T t7686;
  real_T t7689;
  real_T t7698;
  real_T t7701;
  real_T t7708;
  real_T t7726;
  real_T t7733;
  real_T t7738;
  real_T t7739;
  real_T t7747;
  real_T t7748;
  real_T t7752;
  real_T t7755;
  real_T t7759;
  real_T t7761;
  real_T t7772;
  real_T t7773;
  real_T t7774;
  real_T t7775;
  real_T t7776;
  real_T t7784;
  real_T t7791;
  real_T t7792;
  real_T t7794;
  real_T t7797;
  real_T t7799;
  real_T t7801;
  real_T t7802;
  real_T t7805;
  real_T t7812;
  real_T t7817;
  real_T t7824;
  real_T t7826;
  real_T t7829;
  real_T t7832;
  real_T t7833;
  real_T t7837;
  real_T t7838;
  real_T t7849;
  real_T t7851;
  real_T t7858;
  real_T t7862;
  real_T t7863;
  real_T t7867;
  real_T t7873;
  real_T t7874;
  real_T t7876;
  real_T t7877;
  real_T t7885;
  real_T t7899;
  real_T t7900;
  real_T t7904;
  real_T t7918;
  real_T t7922;
  real_T t7923;
  real_T t7924;
  real_T t7928;
  real_T t7930;
  real_T t7943;
  real_T t7948;
  real_T t7950;
  real_T t7951;
  real_T t7956;
  real_T t7966;
  real_T t7976;
  real_T t7977;
  real_T t7978;
  real_T t7994;
  real_T t8000;
  real_T t8006;
  real_T t8007;
  real_T t8014;
  real_T t8017;
  real_T t8023;
  real_T t8027;
  real_T t8032;
  real_T t8036;
  real_T t8050;
  real_T t8056;
  real_T t8060;
  real_T t8064;
  real_T t8065;
  real_T t8066;
  real_T t8073;
  real_T t8074;
  real_T t8077;
  real_T t8079;
  real_T t8080;
  real_T t8081;
  real_T t8104;
  real_T t8105;
  real_T t8111;
  real_T t8112;
  real_T t8119;
  real_T t8128;
  real_T t8132;
  real_T t8137;
  real_T t8141;
  real_T t8146;
  real_T t8163;
  real_T t8167;
  real_T t8182;
  real_T t8198;
  real_T t8207;
  real_T t8209;
  real_T t8212;
  real_T t8219;
  real_T t8231;
  real_T t8234;
  real_T t8235;
  real_T t8240;
  real_T t8244;
  real_T t8245;
  real_T t8246;
  real_T t8259;
  real_T t8273;
  real_T t8284;
  real_T t8285;
  real_T t8287;
  real_T t8296;
  real_T t8300;
  real_T t8309;
  real_T t8311;
  real_T t8312;
  real_T t8317;
  real_T t8328;
  real_T t8329;
  real_T t8333;
  real_T t8336;
  real_T t8337;
  real_T t8342;
  real_T t8347;
  real_T t8354;
  real_T t8361;
  real_T t8364;
  real_T t8365;
  real_T t8369;
  real_T t8373;
  real_T t8385;
  real_T t8388;
  real_T t8391;
  real_T t8417;
  real_T t8436;
  real_T t8439;
  real_T t8443;
  real_T t8455;
  real_T t8486;
  real_T t8507;
  real_T t8510;
  real_T t8511;
  real_T t8523;
  real_T t8524;
  real_T t8528;
  real_T t8533;
  real_T t8548;
  real_T t8549;
  real_T t8555;
  real_T t8561;
  real_T t168_tmp;
  real_T t20_tmp;
  real_T t886_tmp;
  real_T t815_tmp;
  real_T t576_tmp;
  real_T tmpreturn_tmp;
  real_T tmpreturn_tmp_0;
  real_T t876_tmp;
  real_T t386_tmp;
  real_T t2863_tmp;
  real_T t1882_tmp;
  real_T t1767_tmp;
  real_T tmpreturn_tmp_1;
  real_T tmpreturn_tmp_2;
  real_T t2244_tmp;
  real_T tmpreturn_tmp_3;
  real_T t404_tmp;
  real_T t420_tmp;
  real_T tmpreturn_tmp_4;
  real_T t323_tmp;
  real_T tmpreturn_tmp_5;
  real_T t1049_tmp;
  real_T tmpreturn_tmp_6;
  real_T t2707_tmp;
  real_T t6149_tmp;
  real_T t851_tmp;
  real_T t6568_tmp;
  real_T tmpreturn_tmp_7;
  real_T t8342_tmp;
  real_T tmpreturn_tmp_8;
  real_T t7669_tmp;
  real_T tmpreturn_tmp_9;
  real_T tmpreturn_tmp_a;
  real_T tmpreturn_tmp_b;
  real_T tmpreturn_tmp_c;
  real_T t1839_tmp;
  real_T t688_tmp;
  real_T tmpreturn_tmp_d;
  real_T t601_tmp;
  real_T tmpreturn_tmp_e;
  real_T tmpreturn_tmp_f;
  real_T tmpreturn_tmp_g;
  real_T t471_tmp;
  real_T tmpreturn_tmp_h;
  real_T tmpreturn_tmp_i;
  real_T t1853_tmp;
  real_T tmpreturn_tmp_j;
  real_T tmpreturn_tmp_k;
  real_T t6664_tmp;
  real_T tmpreturn_tmp_l;
  real_T t141_tmp;
  real_T t8523_tmp;
  real_T tmpreturn_tmp_m;
  real_T t7129_tmp;
  real_T t169_tmp;
  real_T tmpreturn_tmp_n;
  real_T tmpreturn_tmp_o;
  real_T tmpreturn_tmp_p;
  real_T tmpreturn_tmp_q;
  real_T t6514_tmp;
  real_T tmpreturn_tmp_r;
  real_T tmpreturn_tmp_s;
  real_T tmpreturn_tmp_t;
  real_T t2939_tmp;
  real_T t5633_tmp;
  real_T t878_tmp;
  real_T t751_tmp;
  real_T t148_tmp;
  real_T tmpreturn_tmp_u;
  real_T tmpreturn_tmp_v;
  real_T tmpreturn_tmp_w;
  real_T t516_tmp;
  real_T tmpreturn_tmp_x;
  real_T t1079_tmp;
  real_T t148_tmp_tmp;
  real_T tmpreturn_tmp_y;
  real_T t5710_tmp;
  real_T tmpreturn_tmp_z;
  real_T tmpreturn_tmp_10;
  real_T t589_tmp_tmp;
  real_T tmpreturn_tmp_11;
  real_T tmpreturn_tmp_12;
  real_T tmpreturn_tmp_13;
  real_T tmpreturn_tmp_14;
  real_T tmpreturn_tmp_15;
  real_T t4772_tmp;
  real_T tmpreturn_tmp_16;
  real_T tmpreturn_tmp_17;
  real_T tmpreturn_tmp_18;
  real_T tmpreturn_tmp_19;
  real_T t6931_tmp;
  real_T tmpreturn_tmp_1a;
  real_T tmpreturn_tmp_1b;
  real_T tmpreturn_tmp_1c;
  t2 = std::cos(q[6]);
  t3 = t2 * t2;
  t4 = t3 * param->m__l7;
  t5 = param->s__l7x * param->s__l7y;
  t7 = t5 * q__p[6];
  t8 = t4 * t7;
  t9 = 2.0 * t8;
  t10 = param->s__l7x * param->s__l7x;
  t11 = param->s__l7y * param->s__l7y;
  t12 = t10 - t11;
  t14 = (param->m__l7 * t12 - param->I__l7xx) + param->I__l7yy;
  t15 = q__p[6] * t14;
  t16 = std::sin(q[6]);
  t17 = t15 * t16;
  t18 = param->m__l7 * param->s__l7x;
  t20_tmp = param->l__6 + param->s__l7z;
  t21 = q__p[5] * t20_tmp;
  t22 = t18 * t21;
  t23 = 2.0 * t22;
  t24 = -t17 + t23;
  t25 = t24 * t2;
  t26 = param->m__l7 * param->s__l7y;
  t27 = t21 * t16;
  t28 = t26 * t27;
  t29 = 2.0 * t28;
  t31 = param->s__l6x * param->s__l6y;
  t32 = q__p[5] * param->m__l6 * t31;
  t33 = 2.0 * t32;
  t34 = param->s__l7y * q__p[6];
  t35 = t18 * t34;
  t38 = std::cos(q[5]);
  t39 = t38 * t38;
  t40 = ((((-t9 + t25) - t29) - t33) + t35) * t39;
  t41 = t14 * q__p[5];
  t42 = std::sin(q[5]);
  t43 = t41 * t42;
  t45 = param->s__l7y * q__p[4];
  t46 = t18 * t45;
  t47 = 4.0 * t46;
  t48 = -t43 - t47;
  t49 = t48 * t3;
  t50 = param->s__l7x * q__p[5];
  t51 = t50 * t16;
  t52 = q__p[6] * t20_tmp;
  t53 = t52 / 2.0;
  t54 = t51 - t53;
  t56 = t26 * t54 * t42;
  t57 = q__p[4] * t14;
  t58 = t57 * t16;
  t59 = t56 - t58;
  t60 = 2.0 * t59;
  t61 = t60 * t2;
  t62 = t52 * t16;
  t63 = t18 * t62;
  t196 = param->s__l7z + param->l__6;
  t64 = t196 + param->s__l7y;
  t204 = -param->s__l7z - param->l__6;
  t65 = t204 + param->s__l7y;
  t67 = t64 * t65 * param->m__l7;
  t68 = param->s__l6x * param->s__l6x;
  t69 = param->s__l6y * param->s__l6y;
  t70 = t68 - t69;
  t71 = t70 * param->m__l6;
  t72 = ((((t67 + t71) - param->I__l6xx) + param->I__l6yy) - param->I__l7yy) +
    param->I__l7zz;
  t73 = t72 * q__p[5];
  t74 = -t63 - t73;
  t750 = t74 * t42;
  t76 = t18 * param->s__l7y;
  t77 = param->m__l6 * param->s__l6x;
  t78 = param->d__5 - param->s__l6z;
  t79 = t77 * t78;
  t80 = t76 + t79;
  t81 = q__p[4] * t80;
  t82 = 2.0 * t81;
  t85 = q__p[4] * t20_tmp;
  t86 = t85 * t42;
  t87 = t26 * t86;
  t576 = ((-2.0 * t87 - t17) - t22) * t2;
  t91 = t20_tmp * t16;
  t92 = t18 * t91;
  t93 = param->m__l6 * param->s__l6y;
  t94 = t93 * t78;
  t95 = t92 + t94;
  t96 = q__p[4] * t95;
  t97 = t96 * t42;
  t98 = 2.0 * t97;
  t99 = q__p[4] * param->m__l5;
  t100 = param->s__l5x * param->s__l5y;
  t101 = t99 * t100;
  t102 = 2.0 * t101;
  t105 = std::cos(q[4]);
  t106 = t105 * t105;
  t107 = (((((((((((t49 + t61) + t750) + t82) * t38 + t40) - t9) + t576) - t98)
             + t28) - t102) + t32) + t35) * t106;
  t108 = t14 * t3;
  t109 = t2 * t16;
  t110 = t109 * t76;
  t111 = 2.0 * t110;
  t6268 = t108 - t111;
  t112 = (((((t6268 + t67) + t71) - param->I__l6xx) + param->I__l6yy) -
          param->I__l7yy) + param->I__l7zz;
  t113 = q__p[4] * t112;
  t114 = std::sin(q[4]);
  t115 = t113 * t114;
  t116 = t20_tmp * t2;
  t117 = t18 * t116;
  t118 = t26 * t91;
  t119 = t77 * param->s__l6y;
  t120 = (-t117 + t118) + t119;
  t122 = t120 * q__p[3];
  t123 = 4.0 * t122;
  t124 = -t115 + t123;
  t126 = t15 * t3;
  t127 = 2.0 * t126;
  t128 = q__p[4] * param->s__l7x;
  t15 = t42 * t20_tmp;
  t130 = t128 * t15;
  t132 = param->s__l7x * q__p[6];
  t133 = t132 * t16;
  t136 = (t133 - t21 / 4.0) * param->s__l7y;
  t139 = (-t130 / 2.0 + t136) * param->m__l7 * t2;
  t140 = 4.0 * t139;
  t141_tmp = t118 + t119;
  t142 = q__p[4] * t141_tmp;
  t143 = t142 * t42;
  t144 = 2.0 * t143;
  t145 = t18 * t27;
  t146 = t10 * q__p[6];
  t147 = q__p[6] * t11;
  t148 = t146 - t147;
  t149 = t148 * param->m__l7;
  t150 = param->s__l6y * q__p[5];
  t151 = t78 * param->m__l6;
  t152 = t150 * t151;
  t3356 = param->I__l7xx - param->I__l7yy;
  t154 = t3356 * q__p[6];
  t155 = (((((-t127 + t140) + t144) - t145) + t149) - t152) - t154;
  t156 = t155 * t114;
  t157 = t14 * t42;
  t158 = t157 * t3;
  t27 = param->s__l7y * t42;
  t160 = t27 * t16;
  t163 = (param->l__4 / 2.0 + t160) + param->l__5 / 2.0;
  t166 = 2.0 * t18 * t163 * t2;
  t167 = t72 * t42;
  t168_tmp = param->l__4 + param->l__5;
  t169_tmp = param->s__l7y * t16;
  t170 = t169_tmp * param->m__l7;
  t171 = -t170 + t77;
  t172 = t168_tmp * t171;
  t173 = ((t158 - t166) + t167) - t172;
  t174 = t173 * q__p[3];
  t175 = 2.0 * t174;
  t178 = q__p[5] * t42;
  t179 = t178 * t76;
  t180 = 2.0 * t179;
  t181 = t180 - t57;
  t182 = t181 * t3;
  t183 = t41 * t16;
  t184 = t18 * t52;
  t185 = t183 - t184;
  t187 = t45 * t16;
  t188 = t18 * t187;
  t189 = 2.0 * t188;
  t191 = (t185 * t42 + t189) * t2;
  t192 = t26 * t62;
  t193 = t80 * q__p[5];
  t194 = t192 - t193;
  t195 = t194 * t42;
  t196 += param->s__l7x;
  t197 = t204 + param->s__l7x;
  t199 = t196 * t197 * param->m__l7;
  t200 = (-param->s__l6y + param->d__5) - param->s__l6z;
  t201 = (param->s__l6y + param->d__5) - param->s__l6z;
  t203 = t200 * t201 * param->m__l6;
  t204 = param->s__l5x * param->s__l5x;
  t205 = param->s__l5y * param->s__l5y;
  t206 = t204 - t205;
  t207 = t206 * param->m__l5;
  t209 = ((((((((-t199 - t203) + param->I__l7xx) + t207) - param->I__l5xx) +
             param->I__l5yy) - param->I__l6yy) + param->I__l6zz) -
          param->I__l7zz) * q__p[4];
  t2205 = (t182 + t191) + t195;
  t211 = (t2205 - t209) * t114;
  t214 = param->m__l7 * -t20_tmp + t93;
  t215 = t214 * t168_tmp;
  t216 = t215 * t42;
  t217 = param->m__l5 * param->s__l5x;
  t218 = param->l__4 + param->s__l5z;
  t219 = t217 * t218;
  t220 = (((-t216 - t117) + t118) + t119) + t219;
  t221 = t220 * q__p[3];
  t222 = 2.0 * t221;
  t225 = t116 * t26;
  t226 = (t225 + t92) + t94;
  t227 = t226 * q__p[3];
  t228 = t227 * t114;
  t229 = 2.0 * t228;
  t230 = 2.0 * t46;
  t231 = -t43 + t230;
  t232 = t231 * t3;
  t233 = 2.0 * t56;
  t234 = q__p[5] * t168_tmp;
  t235 = t18 * t234;
  t236 = (t233 + t58) + t235;
  t239 = t26 * t234 * t16;
  t240 = t78 * q__p[4];
  t241 = t240 - t234;
  t243 = param->m__l6 * t241 * param->s__l6x;
  t245 = ((((((t2 * t236 + t229) + t232) - t239) - t243) - t46) + t750) * t38;
  t246 = t42 * t3;
  t248 = 2.0 * t246 * t76;
  t249 = t16 * t42;
  t251 = t26 * t168_tmp;
  t252 = -t14 * t249 + t251;
  t253 = t252 * t2;
  t254 = t80 * t42;
  t255 = t16 * t168_tmp;
  t256 = t18 * t255;
  t257 = t168_tmp * t78;
  t258 = t257 * param->m__l6;
  t259 = param->m__l5 * param->s__l5y;
  t260 = t259 * t218;
  t2149 = -t248 + t253;
  t261 = (((t2149 + t254) + t256) - t258) + t260;
  t262 = t261 * q__p[3];
  t263 = t262 * t114;
  t264 = 2.0 * t263;
  t265 = 4.0 * t8;
  t266 = q__p[6] * t168_tmp;
  t267 = t85 - t266;
  t268 = t267 * param->m__l7;
  t269 = t268 * t27;
  t270 = 2.0 * t17;
  t94 = t16 * param->s__l7x;
  t274 = t268 * t94;
  t275 = t20_tmp * param->m__l7;
  t276 = t234 * t275;
  t277 = t93 * t241;
  t278 = (t274 + t276) + t277;
  t281 = param->s__l4x * param->m__l4;
  t282 = q__p[3] * param->s__l4y * t281;
  t283 = 2.0 * t282;
  t284 = 2.0 * t35;
  t241 = std::cos(q[3]);
  t288 = t241 * t241;
  t1850 = ((t269 + t270) - t22) * t2;
  t289 = ((((((((((((((((t156 + t175) * t38 + t124 * t39) + t211) - t222) * t105
                     + t107) + t40) + t245) + t264) + t265) + t1850) + t278 *
               t42) + t28) - t283) + t101) + t32) - t284) * t288;
  t290 = std::sin(q[3]);
  t291 = t290 * t112;
  t293 = t291 * q__p[3] * t39;
  t294 = t42 * t120;
  t295 = q__p[3] * t290;
  t296 = t294 * t295;
  t297 = 2.0 * t296;
  t299 = t4 * t5;
  t300 = 2.0 * t299;
  t301 = t16 * t14;
  t302 = t301 * t2;
  t303 = ((-t300 - t302) + t76) + t79;
  t304 = q__p[2] * t303;
  t305 = 4.0 * t304;
  t306 = t297 + t305;
  t2492 = t6268 - t199;
  t308 = (((((((t2492 - t203) + t207) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t309 = q__p[3] * t308;
  t310 = t309 * t290;
  t311 = t275 * t2;
  t312 = t27 * t311;
  t313 = t95 * t42;
  t314 = t100 * param->m__l5;
  t315 = (t312 + t313) + t314;
  t316 = q__p[2] * t315;
  t317 = 4.0 * t316;
  t319 = (((t306 * t38 - t293) - t310) - t317) * t106;
  t320 = t41 * t3;
  t321 = 2.0 * t320;
  t323_tmp = param->m__l7 * t2;
  t324 = param->s__l7y * t54 * t323_tmp;
  t325 = 4.0 * t324;
  t326 = 2.0 * t63;
  t327 = 2.0 * t73;
  t328 = ((t321 - t325) + t326) + t327;
  t329 = t328 * t290;
  t330 = t114 * q__p[2];
  t331 = t330 * t112;
  t332 = 2.0 * t331;
  t335 = q__p[3] * t303;
  t336 = t335 * t114;
  t337 = 2.0 * t336;
  t338 = q__p[6] * t3;
  t340 = t76 * t338 * t42;
  t341 = 4.0 * t340;
  t342 = 4.0 * t22;
  t343 = -t270 + t342;
  t344 = t343 * t42;
  t345 = t85 + t266;
  t346 = t345 * param->m__l7;
  t347 = t346 * param->s__l7y;
  t349 = (t344 + t347) * t2;
  t350 = 4.0 * t28;
  t351 = 4.0 * t32;
  t352 = (-t350 - t351) + t284;
  t353 = t352 * t42;
  t354 = t346 * t94;
  t54 = t240 + t234;
  t356 = t93 * t54;
  t358 = ((((((-t337 - t341) + t349) + t353) + t354) - t276) + t356) * t290;
  t359 = q__p[2] * t42;
  t360 = t120 * t114;
  t361 = t359 * t360;
  t362 = 4.0 * t361;
  t365 = q__p[3] * t315;
  t366 = t365 * t114;
  t367 = 2.0 * t366;
  t100 = param->m__l7 * t42;
  t370 = t5 * t100 * q__p[4];
  t371 = 2.0 * t370;
  t372 = -t371 - t41;
  t373 = t372 * t3;
  t374 = -t58 + t235;
  t375 = t374 * t42;
  t376 = t168_tmp / 2.0;
  t377 = t376 * q__p[4];
  t4291 = t51 + t377;
  t380 = (t4291 - t53) * param->m__l7 * param->s__l7y;
  t381 = 2.0 * t380;
  t383 = (t375 + t381) * t2;
  t385 = param->m__l6 * t54 * param->s__l6x;
  t386_tmp = -t239 + t46;
  t386 = t386_tmp + t385;
  t387 = t386 * t42;
  t389 = -t168_tmp * q__p[4];
  t392 = (t389 + t52) * param->m__l7 * t94;
  t395 = q__p[5] * t64 * t65 * param->m__l7;
  t396 = t257 * q__p[4];
  t398 = -t70 * q__p[5];
  t400 = (-t396 + t398) * param->m__l6;
  t401 = q__p[4] * t218;
  t402 = t259 * t401;
  t404_tmp = param->I__l6xx - param->I__l6yy;
  t404 = ((t404_tmp + param->I__l7yy) - param->I__l7zz) * q__p[5];
  t467 = ((((t367 + t373) + t383) + t387) - t392) - t395;
  t406 = (((t467 + t400) + t402) + t404) * t290;
  t407 = t330 * t308;
  t408 = 2.0 * t407;
  t411 = q__p[4] * t120;
  t412 = t411 * t114;
  t413 = 2.0 * t412;
  t414 = t112 * q__p[3];
  t415 = t413 + t414;
  t416 = t415 * t290;
  t417 = t416 * t39;
  t418 = t57 * t42;
  t419 = q__p[5] * param->s__l7y;
  t420_tmp = t18 * t419;
  t257 = 2.0 * t420_tmp;
  t422 = -t418 - t257;
  t423 = t422 * t3;
  t424 = q__p[4] * t42;
  t426 = t76 * t424 * t16;
  t427 = 2.0 * t426;
  t428 = t168_tmp * q__p[4];
  t429 = t428 + t52;
  t431 = t429 * param->m__l7 * param->s__l7x;
  t432 = (t427 - t183) + t431;
  t433 = t432 * t2;
  t434 = t72 * q__p[4];
  t435 = t434 * t42;
  t54 = param->m__l7 * t16;
  t438 = param->s__l7y * t429 * t54;
  t439 = q__p[5] * t78;
  t440 = t428 + t439;
  t442 = param->m__l6 * t440 * param->s__l6x;
  t429 = param->s__l7x * t42;
  t446 = t429 * t311;
  t447 = t141_tmp * t42;
  t854 = -t446 + t447;
  t448 = t854 - t215;
  t449 = t448 * q__p[3];
  t450 = 2.0 * t449;
  t452 = ((((((t423 + t433) - t435) - t438) + t420_tmp) + t442) * t114 + t450) *
    t290;
  t453 = 2.0 * t304;
  t455 = (t452 - t453) * t38;
  t456 = t157 * t338;
  t457 = 2.0 * t456;
  t458 = t136 * t42;
  t463 = (t458 - t267 * param->s__l7x / 4.0) * param->m__l7 * t2;
  t464 = 4.0 * t463;
  t465 = t428 * t20_tmp;
  t2115 = -t147 + t146;
  t466 = t2115 + t465;
  t469 = param->s__l6y * t440 * param->m__l6;
  t471_tmp = -t145 + t466 * param->m__l7;
  t471 = ((t471_tmp - t469) - t154) * t42;
  t473 = param->s__l7y * t267 * t54;
  t474 = t119 + t219;
  t475 = q__p[4] * t474;
  t479 = 2.0 * -t12;
  t481 = 2.0 * param->I__l7xx;
  t482 = 2.0 * param->I__l7yy;
  t484 = ((param->m__l7 * t479 + t481) - t482) * t3;
  t486 = t376 * t42 + t169_tmp;
  t487 = param->s__l7x * t486;
  t489 = 4.0 * t487 * t323_tmp;
  t490 = t172 * t42;
  t491 = 2.0 * t490;
  t495 = (t168_tmp + param->s__l7x) * ((-param->l__4 - param->l__5) +
    param->s__l7x) + -t11;
  t496 = t495 * param->m__l7;
  t497 = param->l__4 * param->l__4;
  t499 = 2.0 * param->l__4 * param->l__5;
  t267 = -param->s__l6z + param->d__5;
  t500 = t267 - param->l__5;
  t501 = t267 + param->l__5;
  t503 = ((t500 * t501 - t497) - t499) - t68;
  t504 = t503 * param->m__l6;
  t505 = t497 * param->m__l5;
  t506 = param->l__4 * param->m__l5;
  t508 = 2.0 * t506 * param->s__l5z;
  t509 = param->s__l5z * param->s__l5z;
  t510 = t205 - t509;
  t511 = t510 * param->m__l5;
  t512 = param->s__l4x * param->s__l4x;
  t513 = param->s__l4y * param->s__l4y;
  t514 = t512 - t513;
  t515 = t514 * param->m__l4;
  t516_tmp = ((t484 + t489) + t491) + t496;
  t516 = ((((((((((((t516_tmp + t504) - t505) - t508) + param->I__l7yy) -
                 param->I__l7xx) + t511) + t515) - param->I__l4xx) +
             param->I__l4yy) - param->I__l5yy) + param->I__l5zz) +
          param->I__l6xx) - param->I__l6zz;
  t517 = t516 * q__p[3];
  t364 = -t457 + t464;
  t519 = ((((t364 + t471) + t473) + t475) * t114 - t517) * t290;
  t521 = -t95 * t42;
  t522 = param->d__3 - param->s__l4z;
  t523 = t281 * t522;
  t524 = ((-t312 + t521) - t314) + t523;
  t525 = q__p[2] * t524;
  t526 = 2.0 * t525;
  t529 = 2.0 * t122;
  t530 = -t115 - t529;
  t532 = q__p[2] * t226;
  t533 = t532 * t290;
  t534 = 2.0 * t533;
  t537 = q__p[2] * t261;
  t538 = t537 * t290;
  t539 = 2.0 * t538;
  t541 = ((((((t534 + t156) - t174) * t38 + t530 * t39) + t539) + t211) + t221) *
    t105;
  t542 = q__p[2] * t120;
  t543 = t114 * t290;
  t544 = t542 * t543;
  t545 = 4.0 * t544;
  t156 = -t343 * t2;
  t549 = (((((-t545 + t265) + t156) + t350) + t351) - t284) * t39;
  t550 = t114 * t173;
  t551 = q__p[2] * t290;
  t552 = t550 * t551;
  t553 = 2.0 * t552;
  t554 = t43 + t46;
  t557 = 4.0 * t56;
  t558 = (-t557 + t58) - t235;
  t561 = 2.0 * -t74;
  t562 = t561 * t42;
  t2121 = t3 * (2.0 * t554);
  t564 = (((((((t2 * t558 + t2121) - t228) + t239) - t385) - t46) - t553) + t562)
    * t38;
  t565 = t114 * t220;
  t566 = param->s__l4y * param->m__l4;
  t567 = t566 * t522;
  t568 = t565 + t567;
  t570 = q__p[2] * t568 * t290;
  t571 = 2.0 * t570;
  t572 = t346 * t27;
  t881 = ((t572 - t17) + t23) * t2;
  t576_tmp = ((t354 - t276) + t356) * t42;
  t578 = param->s__l3x * param->s__l3y;
  t579 = q__p[2] * param->m__l3 * t578;
  t580 = 2.0 * t579;
  t346 = std::cos(q[2]);
  t267 = t346 * t346;
  t586 = t112 * t39;
  t588 = 2.0 * t294 * t38;
  t589_tmp_tmp = t586 - t588;
  t2123 = ((t589_tmp_tmp + t108) - t111) - t199;
  t589 = (((((((t2123 - t203) + t207) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t440 = std::sin(q[2]);
  t592 = t440 * t106;
  t593 = q__p[2] * t589 * t592;
  t595 = q__p[1] * t120;
  t596 = t595 * t39;
  t598 = t440 * t114;
  t599 = t304 * t598;
  t600 = 2.0 * t599;
  t601 = t173 * q__p[1];
  t605 = t114 * t315;
  t606 = q__p[2] * t440;
  t607 = t605 * t606;
  t608 = 2.0 * t607;
  t609 = q__p[1] * t220;
  t613 = t606 * t586;
  t614 = q__p[1] * t226;
  t615 = t614 * t114;
  t617 = t448 * q__p[2];
  t618 = t617 * t440;
  t622 = t114 * t261;
  t623 = t622 * q__p[1];
  t625 = q__p[2] * t516;
  t626 = t625 * t440;
  t627 = q__p[1] * param->s__l4y;
  t628 = t627 * t281;
  t338 = q__p[1] * t290;
  t633 = q__p[4] * t440;
  t634 = t338 - t633;
  t638 = t42 * q__p[1];
  t639 = t120 * t290;
  t640 = t638 * t639;
  t643 = -t148 * param->m__l7;
  t2863 = (((t127 - t140) - t144) + t145) + t643;
  t644 = (t2863 + t152) + t154;
  t645 = t440 * t644;
  t649 = q__p[1] * t308;
  t650 = t649 * t290;
  t653 = -t181 * t3;
  t657 = (t42 * -t185 - t189) * t2;
  t659 = -t194 * t42;
  t2947 = t653 + t657;
  t5299 = t2947 + t659;
  t660 = t5299 + t209;
  t661 = t440 * t660;
  t662 = 2.0 * t661;
  t665 = t542 * t290;
  t666 = t17 / 2.0;
  t667 = t666 - t22;
  t668 = t667 * t2;
  t669 = t35 / 2.0;
  t670 = (((t8 + t668) + t28) + t32) - t669;
  t671 = t670 * t114;
  t672 = t665 - t671;
  t675 = 4.0 * t672 * t440 * t39;
  t676 = q__p[1] * t303;
  t677 = t676 * t114;
  t678 = 4.0 * t677;
  t679 = t173 * q__p[2];
  t680 = t679 * t440;
  t684 = t43 / 2.0;
  t685 = -t684 - t230;
  t688 = t74 / 2.0;
  t2957 = t2 * t59;
  t690 = ((t2957 + t3 * t685) + t42 * t688) + t81;
  t693 = 4.0 * t440 * t690 * t114;
  t694 = t227 * t440;
  t695 = param->l__2 + param->l__3;
  t696 = q__p[1] * t695;
  t697 = param->s__l7x * t2;
  t698 = t697 * param->m__l7;
  t699 = (t698 - t170) + t77;
  t700 = t696 * t699;
  t701 = 2.0 * t700;
  t704 = q__p[1] * t315;
  t705 = t704 * t114;
  t706 = 4.0 * t705;
  t707 = q__p[2] * t220;
  t708 = t707 * t440;
  t709 = 2.0 * t708;
  t712 = t22 / 2.0;
  t3019 = ((t87 + t666) + t712) * t2;
  t715 = t28 / 2.0;
  t716 = t32 / 2.0;
  t2910 = t8 + t3019;
  t717 = ((((t2910 + t97) - t715) + t101) - t716) - t669;
  t720 = 4.0 * t717 * t440 * t114;
  t721 = t262 * t440;
  t722 = t275 - t93;
  t723 = t722 * t42;
  t724 = t723 + t217;
  t725 = t696 * t724;
  t726 = 2.0 * t725;
  t729 = t112 * q__p[1];
  t730 = t729 * t290;
  t731 = 2.0 * t730;
  t732 = t122 * t114;
  t733 = 2.0 * t732;
  t734 = -t733 + t113;
  t735 = t734 * t440;
  t738 = t532 * t598;
  t740 = t448 * q__p[1];
  t741 = 4.0 * t740;
  t744 = t174 * t114;
  t2173 = (((-t744 + t127) - t140) - t144) + t145;
  t746 = (((t2173 + t643) + t152) + t154) * t440;
  t749 = t537 * t598;
  t751_tmp = param->s__l4y * param->s__l4x * param->m__l4;
  t752 = t606 * t751_tmp;
  t753 = t516 * q__p[1];
  t757 = t221 * t440;
  t758 = t26 * t2;
  t170 = t94 * param->m__l7;
  t761 = -t78 * param->m__l6;
  t762 = ((t758 + t170) + t761) + t259;
  t763 = q__p[1] * t762;
  t764 = t763 * t695;
  t767 = (t757 - 2.0 * t764) * t114;
  t770 = q__p[4] * t196 * t197 * param->m__l7;
  t771 = q__p[4] * t200;
  t772 = t201 * param->m__l6;
  t773 = t771 * t772;
  t775 = t567 * q__p[3];
  t777 = ((((((param->I__l7xx + t207) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) - param->I__l7zz) * q__p[4];
  t780 = t281 * t696;
  t781 = 2.0 * t780;
  t784 = q__p[2] * t112;
  t785 = t784 * t39;
  t786 = t335 * t290;
  t787 = t359 * t120;
  t788 = t786 - t787;
  t789 = 2.0 * t788;
  t791 = t365 * t290;
  t792 = 2.0 * t791;
  t793 = q__p[2] * t308;
  t796 = (((t38 * t789 + t785) - t792) + t793) * t440 * t106;
  t797 = t414 * t114;
  t798 = 2.0 * t411;
  t799 = t797 - t798;
  t800 = t440 * t799;
  t801 = t800 * t290;
  t802 = 4.0 * t595;
  t805 = q__p[3] * t114;
  t806 = t294 * t805;
  t807 = 2.0 * t806;
  t2168 = -t807 + t423;
  t808 = ((((t2168 + t433) - t435) - t438) + t420_tmp) + t442;
  t810 = t440 * t808 * t290;
  t811 = 2.0 * t601;
  t814 = t309 * t114;
  t815_tmp = (t814 - t457) + t464;
  t815 = ((t815_tmp + t471) + t473) + t475;
  t817 = t815 * t440 * t290;
  t818 = 2.0 * t609;
  t821 = 2.0 * t324;
  t822 = ((t320 - t821) + t63) + t73;
  t823 = t114 * t822;
  t824 = t823 * t290;
  t825 = -t824 + t784;
  t828 = 2.0 * t440 * t825 * t39;
  t831 = (((((-t341 + t349) + t353) + t354) - t276) + t356) * t440 * t114;
  t832 = t335 * t440;
  t833 = t696 * t214;
  t834 = 2.0 * t833;
  t837 = 2.0 * t615;
  t839 = t854 - t215 / 2.0;
  t840 = q__p[2] * t839;
  t842 = 4.0 * t840 * t440;
  t847 = (((((((t373 + t383) + t387) - t392) - t395) + t400) + t402) + t404) *
    t440 * t114;
  t848 = t524 * q__p[3];
  t849 = t848 * t440;
  t851_tmp = t18 * t42;
  t851 = t851_tmp * t2;
  t854 = t168_tmp * param->m__l7;
  t855 = t168_tmp * param->m__l6;
  t856 = param->s__l5z * param->m__l5;
  t858 = ((((((t42 * -t171 + t506) + t566) - t851) + t854) + t855) + t856) *
    t695;
  t859 = t858 * q__p[1];
  t860 = 2.0 * t859;
  t863 = 2.0 * t623;
  t400 = (param->m__l7 * -t12 + param->I__l7xx) - param->I__l7yy;
  t866 = t400 * t3;
  t867 = t168_tmp * t42;
  t868 = t867 + t169_tmp;
  t871 = 2.0 * t18 * t868 * t2;
  t876_tmp = (((t20_tmp - param->l__5) - param->l__4) * ((t20_tmp + param->l__5)
    + param->l__4) + -t11) * param->m__l7;
  t877 = param->l__5 * param->l__5;
  t878_tmp = (-t497 - t499) - t877;
  t334 = ((t878_tmp - t68) + t69) * param->m__l6;
  t876 = (t204 - t509) * param->m__l5;
  t885 = param->s__l4z * param->s__l4z;
  t886_tmp = param->d__3 * param->d__3 - 2.0 * param->d__3 * param->s__l4z;
  t879 = ((t886_tmp - t513) + t885) * param->m__l4;
  t888 = param->s__l3x * param->s__l3x;
  t889 = param->s__l3y * param->s__l3y;
  t890 = -t888 + t889;
  t891 = t890 * param->m__l3;
  t892 = ((((((((((((((((((t866 + t871) + t491) + t876_tmp) + t334) - t505) -
                      t508) + param->I__l7yy) + t876) - param->I__l6yy) -
                  param->I__l7zz) + t879) + param->I__l6xx) - param->I__l5xx) +
              t891) + param->I__l3xx) - param->I__l3yy) + param->I__l4yy) -
          param->I__l4zz) + param->I__l5zz;
  t893 = q__p[2] * t892;
  t894 = t893 * t440;
  t895 = param->m__l3 * param->s__l3x;
  t896 = t895 * param->l__2;
  t897 = t895 * param->s__l3z;
  t898 = (-t896 - t897) + t751_tmp;
  t899 = q__p[1] * t898;
  t906 = 2.0 * t316;
  t383 = 2.0 * t361;
  t912 = t614 * t440;
  t913 = 2.0 * t912;
  t914 = q__p[3] * t695;
  t915 = t914 * t699;
  t918 = q__p[1] * t261;
  t919 = t918 * t440;
  t920 = 2.0 * t919;
  t921 = t914 * t724;
  t927 = 4.0 * t595 * t598;
  t930 = t173 * t440;
  t433 = q__p[1] * t114;
  t932 = t930 * t433;
  t933 = 2.0 * t932;
  t196 = q__p[2] * param->s__l7x;
  t937 = t196 * param->s__l7y * t3 * param->m__l7;
  t938 = 2.0 * t937;
  t939 = q__p[2] * t14;
  t940 = t939 * t16;
  t941 = q__p[5] * t695;
  t942 = t18 * t941;
  t943 = -t940 + t942;
  t946 = t26 * t941 * t16;
  t947 = param->m__l7 * q__p[2];
  t948 = t5 * t947;
  t949 = t78 * q__p[2];
  t197 = t949 + t941;
  t952 = t197 * param->m__l6 * param->s__l6x;
  t955 = t609 * t440;
  t956 = 2.0 * t955;
  t957 = t762 * t695;
  t958 = t957 * q__p[3];
  t960 = (-t956 + t958) * t114;
  t963 = t566 * q__p[1] * t522 * t440;
  t964 = 2.0 * t963;
  t965 = t20_tmp * q__p[2];
  t966 = q__p[6] * t695;
  t967 = t965 + t966;
  t968 = param->s__l7y * t967;
  t969 = t100 * t2;
  t970 = t968 * t969;
  t12 = t967 * t16;
  t972 = t18 * t12;
  t973 = t695 * param->m__l7;
  t974 = t21 * t973;
  t976 = param->s__l6y * t197 * param->m__l6;
  t979 = -t314 + t523;
  t980 = t979 * q__p[2];
  t981 = t281 * t914;
  t984 = (((t265 + t156) + t350) + t351) - t284;
  t197 = t440 * t290;
  t987 = t676 * t197;
  t156 = 2.0 * t43;
  t991 = 8.0 * t46 + t156;
  t992 = t991 * t3;
  t994 = 4.0 * -t59;
  t995 = t994 * t2;
  t996 = 4.0 * t81;
  t999 = t704 * t197;
  t1002 = (4.0 * t87 + t270) + t23;
  t1003 = t1002 * t2;
  t1004 = 4.0 * t97;
  t1005 = 4.0 * t101;
  t1006 = ((((((((((((4.0 * t987 + t992) + t995) + t562) - t996) * t38 + t984 *
                  t39) - 4.0 * t999) + t265) + t1003) + t1004) - t29) + t1005) -
           t33) - t284;
  t1008 = t598 * t730;
  t1012 = t120 * t440;
  t1013 = t1012 * t114;
  t1014 = t638 * t1013;
  t1015 = 4.0 * t1014;
  t1017 = -t20_tmp * q__p[2] + t966;
  t1018 = t1017 * t2;
  t1019 = t26 * t1018;
  t1020 = t1017 * t16;
  t1021 = t18 * t1020;
  t1022 = t949 - t941;
  t1023 = t93 * t1022;
  t1026 = 4.0 * t126;
  t1027 = 8.0 * t139;
  t1028 = 4.0 * t143;
  t1029 = 2.0 * t145;
  t1030 = 2.0 * -t148;
  t1031 = t1030 * param->m__l7;
  t1032 = 2.0 * t152;
  t1033 = 2.0 * t154;
  t1034 = (((((t1026 - t1027) - t1028) + t1029) + t1031) + t1032) + t1033;
  t1035 = t1034 * t114;
  t1038 = t440 * q__p[1];
  t1039 = t308 * t114;
  t1040 = t1038 * t1039;
  t1041 = 2.0 * t1040;
  t1043 = t76 * t246 * q__p[2];
  t1044 = 2.0 * t1043;
  t1045 = t940 + t942;
  t1047 = -t168_tmp * q__p[2];
  t1048 = q__p[4] * t695;
  t1049 = t1047 + t1048;
  t940 = param->m__l7 * t1049;
  t1051 = t940 * param->s__l7y;
  t1054 = t77 * t1022;
  t1055 = (-t946 - t948) - t1054;
  t1057 = t940 * t94;
  t1059 = t1049 * t78 * param->m__l6;
  t1060 = t218 * q__p[2];
  t940 = t1060 - t1048;
  t1063 = t940 * param->m__l5 * param->s__l5y;
  t1066 = 4.0 * t179;
  t218 = 2.0 * t57 + -t1066;
  t1069 = t218 * t3;
  t1070 = 2.0 * -t185;
  t1072 = 4.0 * t188;
  t1074 = (t1070 * t42 - t1072) * t2;
  t1022 = 2.0 * -t194;
  t1076 = t1022 * t42;
  t1077 = 2.0 * t209;
  t1079_tmp = (t1069 + t1074) + t1076;
  t1079 = (t1079_tmp + t1077) * t114;
  t1080 = t695 * t440;
  t1081 = t763 * t1080;
  t1082 = 2.0 * t1081;
  t1085 = 2.0 * t544;
  t1087 = (((((t1085 - t9) + t25) - t29) - t33) + t35) * t39;
  t1089 = t157 * q__p[2] * t3;
  t763 = q__p[2] * param->s__l7y;
  t1091 = t763 * t249;
  t1092 = t376 * q__p[2];
  t1093 = t1048 / 2.0;
  t1446 = t1091 + t1092;
  t1096 = (t1446 - t1093) * param->m__l7 * t697;
  t1099 = t72 * q__p[2] * t42;
  t1100 = t171 * t1049;
  t1101 = ((t1089 - 2.0 * t1096) + t1099) + t1100;
  t1103 = t676 * t440;
  t1104 = 2.0 * t1103;
  t1105 = t914 * t214;
  t1108 = t699 * t440;
  t1110 = 2.0 * t696 * t1108;
  t1116 = t1049 * t214 * t42;
  t1117 = t967 * t2;
  t1118 = t18 * t1117;
  t1119 = t26 * t12;
  t1120 = param->s__l6y * q__p[2];
  t1121 = t77 * t1120;
  t1123 = t940 * param->s__l5x * param->m__l5;
  t1124 = (((-t1116 + t1118) - t1119) - t1121) - t1123;
  t1126 = q__p[1] * t524;
  t1127 = t1126 * t440;
  t1128 = 2.0 * t1127;
  t1130 = t42 * t695;
  t1132 = t18 * q__p[3] * t1130 * t2;
  t1133 = t171 * t42;
  t1134 = t914 * t1133;
  t376 = q__p[3] * t168_tmp;
  t1136 = t376 * t973;
  t1137 = t695 * param->m__l6;
  t1138 = t376 * t1137;
  t1139 = t522 * q__p[2];
  t1140 = t566 * t1139;
  t1141 = (t506 + t566) + t856;
  t1142 = t914 * t1141;
  t1145 = t724 * t440;
  t1147 = 2.0 * t696 * t1145;
  t1151 = t522 * param->m__l4;
  t1152 = param->s__l3y * param->m__l3;
  t1154 = (t1151 + t1152) * param->l__2;
  t1155 = t1151 * param->l__3;
  t1157 = param->s__l3z * param->s__l3y * param->m__l3;
  t1158 = (t1154 + t1155) + t1157;
  t1160 = q__p[1] * t1158 * t440;
  t1163 = param->m__l2 * param->s__l2x;
  t1164 = q__p[1] * param->s__l2y * t1163;
  t940 = std::cos(q[1]);
  t1170 = t940 * t940;
  t12 = std::sin(q[1]);
  t1173 = -t70 * param->m__l6;
  t1049_tmp = t866 + t111;
  t1049 = (((((t1049_tmp - t67) + t1173) + param->I__l6xx) - param->I__l6yy) +
           param->I__l7yy) - param->I__l7zz;
  t1175 = t1049 * t39;
  t1177 = -t206 * param->m__l5;
  t1178 = (((((((((((t1175 + t588) + t866) + t111) + t199) + t203) + t1177) +
               param->I__l5xx) - param->I__l5yy) + param->I__l6yy) -
            param->I__l6zz) - param->I__l7xx) + param->I__l7zz;
  t1179 = t1178 * t106;
  t1181 = -t303 * t38;
  t1182 = ((t1181 + t312) + t313) + t314;
  t1183 = t1182 * t114;
  t1185 = 2.0 * t1183 * t105;
  t1186 = 2.0 * t446;
  t1187 = 2.0 * t141_tmp;
  t1189 = 2.0 * t215;
  t1194 = (-param->m__l7 * t479 - t481) + t482;
  t1195 = t1194 * t3;
  t1197 = -t495 * param->m__l7;
  t1199 = -t503 * param->m__l6;
  t1202 = -t510 * param->m__l5;
  t1204 = -t514 * param->m__l4;
  t1210 = 2.0 * t70;
  t1213 = 2.0 * param->I__l6yy;
  t1214 = 2.0 * param->I__l7zz;
  t1216 = (((((((param->m__l6 * t1210 - 2.0 * param->I__l6xx) - 4.0 * t110) +
               t1195) + t1213) + t1214) - t482) + 2.0 * t67) * t39;
  t1222 = ((-4.0 * t141_tmp * t42 + t1189) + 4.0 * t446) * t38;
  t110 = 2.0 * -t120;
  t1226 = ((((-t67 + t1173) + param->I__l6xx) - param->I__l6yy) + param->I__l7yy)
    - param->I__l7zz;
  t1230 = ((((((((t1226 * t42 - t158) + t166) + t172) * t38 + t110 * t39) - t117)
             - t216) + t118) + t119) + t219;
  t1232 = t226 * t114;
  t1233 = t1232 * t38;
  t1235 = -t252 * t2;
  t1239 = (((((-t80 * t42 + t1235) + t248) - t256) + t258) - t260) * t114;
  t1240 = ((t105 * t1230 - t1233) + t1239) + t751_tmp;
  t1250 = t589 * q__p[3] * t106;
  t1257 = (((-4.0 * t320 + 8.0 * t324) - 4.0 * t63) - 4.0 * t73) * t39;
  t1258 = 4.0 * t336;
  t1259 = 8.0 * t340;
  t1260 = 4.0 * t17;
  t1262 = t1260 - 8.0 * t22;
  t1263 = t1262 * t42;
  t1269 = 4.0 * t35;
  t1270 = (8.0 * t28 + 8.0 * t32) - t1269;
  t1271 = t1270 * t42;
  t1273 = 2.0 * t276;
  t1274 = 2.0 * t356;
  t1277 = 4.0 * t366;
  t1278 = 4.0 * t370;
  t479 = 2.0 * t41;
  t158 = t1278 + t479;
  t1281 = t158 * t3;
  t1283 = 2.0 * -t374;
  t1284 = t1283 * t42;
  t1289 = 2.0 * -t386;
  t1290 = t1289 * t42;
  t1292 = 2.0 * t395;
  t1293 = 2.0 * t396;
  t1296 = (t1210 * q__p[5] + t1293) * param->m__l6;
  t1297 = 2.0 * t402;
  t1298 = 2.0 * t404;
  t1301 = 4.0 * t412;
  t1302 = 2.0 * t414;
  t1303 = t1301 + t1302;
  t1304 = t1303 * t39;
  t1305 = 2.0 * t418;
  t412 = 4.0 * t420_tmp;
  t514 = t1305 + t412;
  t1308 = t514 * t3;
  t166 = 2.0 * t183;
  t1314 = 2.0 * t435;
  t1316 = 2.0 * t442;
  t1319 = 4.0 * t449;
  t1322 = 4.0 * t456;
  t446 = 2.0 * -t466;
  t1327 = 2.0 * t469;
  t3575 = t1029 + t446 * param->m__l7;
  t1329 = ((t3575 + t1327) + t1033) * t42;
  t1330 = 2.0 * t473;
  t1331 = 2.0 * t475;
  t1334 = 2.0 * t517;
  t1337 = t290 * t670;
  t1338 = t1337 * t39;
  t1339 = 4.0 * t1338;
  t991 = -t991 * t3;
  t1345 = -t561 * t42;
  t510 = (t991 + -t994 * t2) + t1345;
  t1346 = t510 + t996;
  t1347 = t1346 * t290;
  t1348 = 4.0 * t1103;
  t991 = -t265 + -t1002 * t2;
  t1353 = ((((t991 - t1004) + t29) - t1005) + t33) + t284;
  t1354 = t1353 * t290;
  t561 = t704 * t440;
  t1359 = 2.0 * t115;
  t1362 = (8.0 * t122 + -t1359) * t290;
  t1363 = t598 * t729;
  t1002 = 2.0 * t1363;
  t1368 = -t1030 * param->m__l7;
  t3887 = (((-t1026 + t1027) + t1028) - t1029) + t1368;
  t1369 = (t3887 - t1032) - t1033;
  t1371 = 4.0 * t174;
  t1373 = (t114 * t1369 + t1371) * t290;
  t1374 = t26 * t1117;
  t1378 = -t218 * t3;
  t1382 = (-t1070 * t42 + t1072) * t2;
  t1384 = -t1022 * t42;
  t1387 = 4.0 * t221;
  t3576 = t1378 + t1382;
  t1389 = (((t3576 + t1384) - t1077) * t114 - t1387) * t290;
  t1022 = t168_tmp * q__p[2];
  t1393 = t1022 + t1048;
  t1394 = t1393 * param->s__l7y;
  t1395 = t1394 * param->m__l7;
  t1397 = (-t943 * t42 - t1395) * t2;
  t1398 = (t946 - t948) - t952;
  t1399 = t1398 * t42;
  t1401 = t1393 * param->m__l7 * t94;
  t1403 = t1393 * t78 * param->m__l6;
  t1030 = t1060 + t1048;
  t1406 = t1030 * param->m__l5 * param->s__l5y;
  t1070 = t343 * t2;
  t1411 = ((((-t265 + t1070) - t350) - t351) + t284) * t290;
  t1412 = t542 * t114;
  t1416 = 4.0 * t228;
  t1417 = -t156 + t47;
  t1419 = 2.0 * t58;
  t1420 = 2.0 * t235;
  t1423 = 2.0 * t239;
  t1424 = 2.0 * t243;
  t575 = ((t557 + t1419) + t1420) * t2;
  t1426 = ((((((t1417 * t3 + t575) + t1345) + t1416) - t1423) - t1424) - t230) *
    t290;
  t1429 = (t1446 + t1093) * param->m__l7 * t697;
  t1431 = t171 * t1393;
  t1432 = ((t1089 - 2.0 * t1429) + t1099) - t1431;
  t1433 = t1432 * t114;
  t1436 = 4.0 * t263;
  t1437 = 8.0 * t8;
  t1443 = 4.0 * t282;
  t1446 = t1393 * t214;
  t1447 = t1446 * t42;
  t1451 = t1030 * param->s__l5x * param->m__l5;
  t1452 = (((-t1018 * t18 + t1020 * t26) - t1121) + t1447) - t1451;
  t1456 = t414 * t39;
  t1457 = t304 * t290;
  t1458 = t294 * q__p[3];
  t1030 = t1457 + t1458;
  t1460 = 2.0 * t1030;
  t1462 = t316 * t290;
  t1117 = 2.0 * t1462;
  t994 = t330 * t291;
  t1476 = -t695 / 2.0;
  t1484 = t695 * q__p[2];
  t1489 = t695 * t78 * q__p[2];
  t1492 = t259 * t1484;
  t1496 = t595 * t598 * t290;
  t2586 = t1484 + t389;
  t1503 = t2586 - t52;
  t1510 = -t695 * q__p[2];
  t1511 = (t1510 + t428) + t439;
  t1519 = t42 * t1017 * t758;
  t1520 = (-t1021 + t974) + t1023;
  t1523 = -t979 * q__p[2];
  t1534 = param->m__l6 * q__p[4];
  t1535 = t31 * t1534;
  t1540 = t895 * param->s__l3y;
  t1541 = t1038 * t1540;
  t1544 = t14 * q__p[3] * t3;
  t1017 = 2.0 * t1544;
  t1546 = t486 * param->m__l7;
  t31 = param->s__l7x * q__p[3];
  t1551 = t376 * t1133;
  t1567 = t589 * q__p[1];
  t1569 = t440 * t39;
  t1573 = -2.0 * t677 + 2.0 * t680;
  t1578 = t729 * t39;
  t1580 = 2.0 * t738 + 2.0 * t740;
  t1582 = 2.0 * t749;
  t1583 = 2.0 * t752;
  t1586 = t551 * t586;
  t1018 = t359 * t639;
  t1020 = 2.0 * t365;
  t1596 = t595 * t290;
  t1597 = 4.0 * t1596;
  t1600 = -t599 - t601;
  t1601 = 2.0 * t1600;
  t1619 = t1484 + t428;
  t1603 = t1619 + t52;
  t1608 = t26 * t1603 * t16;
  t1609 = t1619 + t439;
  t1616 = t607 + t609;
  t1620 = t20_tmp * t1619;
  t1629 = (t1484 + t401) * param->s__l5x * param->m__l5;
  t482 = t551 * t112;
  t1639 = -t615 + t618;
  t1640 = 2.0 * t1639;
  t1644 = 2.0 * t628;
  t1648 = -t1476 * q__p[2];
  t1663 = t15 * t2;
  t1664 = t26 * q__p[3] * t1663;
  t599 = t95 * q__p[3];
  t1666 = t599 * t42;
  t1667 = t281 * t1484;
  t1668 = q__p[3] * t979;
  t607 = t197 * q__p[4];
  t1676 = (-t607 + q__p[1]) * t112 * t39;
  t1678 = t645 * t290;
  t1680 = t638 * t120;
  t1681 = 4.0 * t1680;
  t1684 = t661 * t290;
  t1689 = t671 * t290;
  t1707 = t290 * t735 - t729;
  t1709 = t965 * t695;
  t661 = t1510 + t439;
  t1714 = param->s__l6y * t661 * param->m__l6;
  t1718 = ((-t1019 - t1021) + t974) + t1023;
  t1721 = 2.0 * t1680;
  t1724 = t1484 - t52;
  t1733 = param->m__l6 * t661 * param->s__l6x;
  t1736 = t10 * q__p[4];
  t1738 = t168_tmp * t695 * q__p[2];
  t1739 = t20_tmp * t20_tmp;
  t1740 = q__p[4] * t1739;
  t1747 = t695 * t1141 * q__p[2];
  t1755 = (-t1045 * t42 - t1051) * t2;
  t1757 = -t1055 * t42;
  t1761 = q__p[2] * t898;
  t1767_tmp = (-(((-param->s__l7z + param->l__2) - param->l__6) + param->l__3) *
               ((t20_tmp + param->l__3) + param->l__2) - t10) * param->m__l7;
  t1774 = ((((2.0 * param->d__5 * param->s__l6z - param->s__l6z * param->s__l6z)
             - param->d__5 * param->d__5) - t695 * t695) + t69) * param->m__l6;
  t1141 = param->l__2 * param->l__2;
  t661 = param->l__3 * param->l__3;
  t1780 = ((((-2.0 * param->l__2 * param->l__3 - t1141) - t661) + t204) - t205) *
    param->m__l5;
  t1782 = (-param->m__l3 - param->m__l4) * t1141;
  t1787 = (-2.0 * param->l__3 * param->m__l4 - 2.0 * param->m__l3 *
           param->s__l3z) * param->l__2;
  t1788 = t661 * param->m__l4;
  t1791 = ((t886_tmp - t512) + t885) * param->m__l4;
  t1794 = (t889 - param->s__l3z * param->s__l3z) * param->m__l3;
  t1798 = (param->s__l2x * param->s__l2x - param->s__l2y * param->s__l2y) *
    param->m__l2;
  t1799 = ((((((((((t1791 + param->I__l5yy) + param->I__l6zz) - param->I__l5xx)
                 + t1794) + param->I__l4xx) - param->I__l3yy) - param->I__l4zz)
             + t1798) - param->I__l2xx) + param->I__l2yy) + param->I__l3zz;
  t1806 = -t24 * t2;
  t661 = ((((t9 + t1806) + t29) + t33) - t35) * t39;
  t48 = -t48 * t3;
  t60 = -t60 * t2;
  t1141 = -t74 * t42;
  t48 = (t48 + t60) + t1141;
  t1680 = t48 - t82;
  t1818 = (((((((t1680 * t38 - t576) + t102) + t661) - t28) - t32) - t35) + t9)
    + t98;
  t1819 = t1818 * t106;
  t1822 = t644 * t114;
  t1825 = t660 * t114;
  t1826 = (((t1822 - t175) * t38 + -t124 * t39) + t1825) + t222;
  t1829 = -t231 * t3;
  t1831 = -t2 * t236;
  t1839_tmp = -t278 * t42;
  t1839 = ((((((((((((((((-t229 + t1829) + t1831) + t1141) + t239) + t46) + t243)
                    * t38 + ((t1826 * t105 + t1819) + t661)) - t264) - t265) -
                 t1850) + t1839_tmp) - t28) + t283) - t101) - t32) + t284) *
    t288;
  t1845 = -t328 * t290;
  t89 = -t343 * t42;
  t1850 = (t89 - t347) * t2;
  t660 = -t352 * t42;
  t1853_tmp = t337 + t341;
  t1853 = ((((t1853_tmp + t1850) + t660) - t354) + t276) - t356;
  t1854 = t1853 * t290;
  t1858 = -t372 * t3;
  t1859 = -t374 * t42;
  t1861 = (t1859 - t381) * t2;
  t1862 = -t386 * t42;
  t1863 = q__p[5] * t70;
  t1865 = (t396 + t1863) * param->m__l6;
  t1871 = -t422 * t3;
  t1876 = (((((-t432 * t2 + t1871) - t420_tmp) + t435) + t438) - t442) * t114 -
    t450;
  t1877 = t1876 * t290;
  t466 = -t466 * param->m__l7;
  t1882_tmp = t145 + t466;
  t1882 = ((t1882_tmp + t469) + t154) * t42;
  t464 = t457 - t464;
  t1884 = (((t464 + t1882) - t473) - t475) * t114;
  t372 = (((((t545 - t265) + t1070) - t350) - t351) + t284) * t39;
  t352 = t330 * t586;
  t1971 = t598 * t39;
  t271 = 2.0 * t595 * t1971;
  t236 = 2.0 * t987;
  t343 = 2.0 * t999;
  t545 = t1038 * t290;
  t1990 = t545 - q__p[4];
  t231 = 2.0 * t1014;
  t2003 = (((((-t1085 + t9) + t1806) + t29) + t33) - t35) * t39;
  t2009 = t696 * t1108 * t114;
  t2010 = t43 + t230;
  t1806 = t2010 * t3;
  t2013 = ((-t233 + t58) - t235) * t2;
  t432 = t50 * t20_tmp;
  t345 = (param->s__l7y * t345 * t42 + t432) * param->m__l7 * t2;
  tmpreturn_tmp = ((-t972 + t974) - t976) * t42;
  tmpreturn_tmp_0 = -(4.0 * t426) + t166;
  tmpreturn_tmp_1 = t1258 + t1259;
  tmpreturn_tmp_6 = t51 + t1648;
  tmpreturn_tmp_7 = 2.0 * param->s__l7y;
  tmpreturn_tmp_e = t1452 * t114;
  tmpreturn_tmp_h = (t329 - t332) * t39 + (t358 + t362) * t38;
  tmpreturn_tmp_i = ((((-t367 + t1858) + t1861) + t1862) + t392) + t395;
  tmpreturn_tmp_z = t383 + t912;
  tmpreturn[0] =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((t1373 -
    t1015) - t1374) - t972) + t974) - t976) * t38 + (t1362 + t1002) * t39) +
    t1389) + t1041) + t1044) + t1397) + t1399) - t1401) + t1403) - t1406) * t105
    + ((((t1347 - t1348) * t38 + -t1339) + t1354) + 4.0 * t561) * t106) + (2.0 *
    t1412 + t1411) * t39) + (((t1426 + t1433) + t1104) + t1105) * t38) +
    (((((((((2.0 * t269 + t1260) - t23) * t2 + (t1436 + t1437)) + 2.0 * t278 *
    t42) + t29) - t1443) + t102) + t33) - t1269) * t290) + tmpreturn_tmp_e) +
    t1128) + t1132) + t1134) - t1136) - t1138) - t1140) - t1142) * t241 +
    (((((((((((((((((((((t1263 - 2.0 * t347) * t2 + tmpreturn_tmp_1) + t1271) -
    2.0 * t354) + t1273) - t1274) * t38 + t1257) - t1277) + t1281) + (t1284 -
    4.0 * t380) * t2) + t1290) + 2.0 * t392) + t1292) + t1296) - t1297) - t1298)
    * t105 + 2.0 * t1250) + t1304) + (((((((tmpreturn_tmp_0 - 2.0 * t431) * t2 +
    t1308) + t1314) + 2.0 * t438) - t257) - t1316) * t114 - t1319) * t38) +
    ((((t1322 - 8.0 * t463) + t1329) - t1330) - t1331) * t114) + t1334) * t288)
    + (((t1460 * t38 - t1456) - t1117) - t309) * t106) +
    (((((((((((((((((((((t383 - t913) - t915) * t290 - t337) - t341) + t349) +
    t353) + t354) - t276) + t356) * t38 + ((((-t994 + t321) - t325) + t326) +
    t327) * t39) + ((-t407 - t920) - t921) * t290) + t367) + t373) + ((((t1476 *
    q__p[2] + t377) + t51) - t53) * tmpreturn_tmp_7 * param->m__l7 + t375) * t2)
    + t387) - (t2586 + t52) * param->m__l7 * t94) - t395) + ((t1489 - t396) +
    t398) * param->m__l6) - t1492) + t402) + t404) * t105) + ((4.0 * t1496 -
    t413) - t414) * t39) + (((((((((-param->m__l7 * param->s__l7x * t1503 - t183)
    + t427) * t2 + t423) - t435) + param->s__l7y * t1503 * t54) + t420_tmp) +
    param->m__l6 * t1511 * param->s__l6x) * t114 + (((((t1045 * t2 - t1054) +
    t933) + t938) - t946) - t948) * t290) + t450) * t38) + (((((t1520 * t42 -
    t1519) + t1523) + t960) - t964) - t981) * t290) + ((((((((t2115 - (t1484 -
    t428) * t20_tmp) * param->m__l7 + -t145) - param->s__l6y * t1511 *
    param->m__l6) - t154) * t42 + t364) + t473) + t1535) + (t1510 + t401) * t217)
    * t114) + 2.0 * t1541) + t1017) - 4.0 * t1546 * t31 * t2) - 2.0 * t1551) -
    t495 * q__p[3] * param->m__l7) - t503 * q__p[3] * param->m__l6) + (((-t522 *
    param->m__l4 - t1152) * param->l__2 - t1155) - t1157) * q__p[2]) -
    (((((((((((-t505 - t508) + param->I__l7yy) - param->I__l7xx) + t511) + t515)
    - param->I__l4xx) + param->I__l4yy) - param->I__l5yy) + param->I__l5zz) +
    param->I__l6xx) - param->I__l6zz) * q__p[3]) * t346 + (((((((((((((((((t1187
    * t42 - t1186) - t1189) * t38 + ((t1179 + t1185) + t1175)) + t1195) - t489)
    - t491) + t1197) + t1199) + t505) + ((((((((((t508 - param->I__l7yy) +
    param->I__l7xx) + t1202) + t1204) + param->I__l4xx) - param->I__l4yy) +
    param->I__l5yy) - param->I__l5zz) - param->I__l6xx) + param->I__l6zz)) *
    t288 + ((((((-t505 + param->I__l7yy) + t1179) + param->I__l3xx) -
    param->I__l3yy) + param->I__l4yy) + param->I__l5zz)) + t491) - t508) + t1216)
    + t1222) + 2.0 * t290 * t1240 * t241) + ((((((((((((t1185 + param->I__l6xx)
    - param->I__l6yy) - param->I__l7zz) - param->I__l5xx) + t871) -
    param->I__l4zz) + t866) + t876_tmp) + t334) + t876) + t879) + t891)) * q__p
    [1] * t267) + (((((((((4.0 * t1569 * t542 + t1573 * t38) + 2.0 * t705) -
    t709) * t105 + -t1567 * t106) - t1578) + t1580 * t38) + t1582) - t1583) -
    t753) * t288) + (((((((((((t1601 * t290 - (((((((t1603 * t18 - t183) + t427)
    * t2 + t2168) - t435) - t1608) + t420_tmp) + param->m__l6 * t1609 *
    param->s__l6x) * t440) * t38 + (-t1597 - t800) * t39) + 2.0 * t1616 * t290)
    - ((((((((t2115 + t1620) * param->m__l7 + -t145) - param->s__l6y * t1609 *
    param->m__l6) - t154) * t42 + t815_tmp) + t473) + t1535) + t1629) * t440) *
    t105 + -((((-2.0 * t1018 - 2.0 * t335) * t38 + t1586) + t793 * t290) + t1020)
    * t440 * t106) - (t482 - 2.0 * t823) * t440 * t39) + (((t1640 * t290 + t831)
    - t832) - t834) * t38) + ((-t863 - t626) + t1644) * t290) +
    (((((((((((tmpreturn_tmp_6 + t377) - t53) * (2.0 * t26) + t375) * t2 + t373)
    + t387) + (t1619 - t52) * param->m__l7 * t94) - t395) + ((-t1489 - t396) +
    t398) * param->m__l6) + t1492) + t402) + t404) * t440 * t114) + (((t1664 +
    t1666) - t1667) - t1668) * t440) + t860) * t241) + ((((-2.0 * t1678 - t1681)
    * t38 + 2.0 * t1676) - 2.0 * t1684) + 2.0 * t649) * t106) + ((((((((-t693 +
    t694) + t701) * t290 + t678) - t1101 * t440) * t38 + (-2.0 * t1689 + t542) *
    -2.0 * t440 * t39) + ((t720 + t721) + t726) * t290) - t706) + -t1124 * t440)
    * t105) + t1707 * t39) + (((((t2173 + ((t147 - t146) + t1709) * param->m__l7)
    + t1714) + t154) * t440 * t290 - t1718 * t440 * t114) + t1721) * t38) +
    (((((((((((-t1724 * t18 - t183) * t42 - t189) * t2 + t653) + ((t16 * t1724 *
    t26 + t1733) + t420_tmp) * t42) + ((-t1736 + t1738) + t1740) * param->m__l7)
    + (-t201 * t771 + t1738) * param->m__l6) + t1747) + t775) + t777) * t440 +
    t767) + t781) * t290) - (((((-t1044 + t1755) + t1757) - t1057) + t1059) +
    t1063) * t440 * t114) + t1761 * t440) - ((((((((((t6268 + t1767_tmp) + t1774)
    + param->I__l7xx) + t1780) + t1782) + t1787) - t1788) - param->I__l6yy) -
    param->I__l7zz) + t1799) * q__p[1]) * t12 * t940 +
                     (((((((((((((((((((((((((((((((((((t678 - 2.0 * t680) *
    t290 - t693) + t694) + t701) * t38 + -t675) + (-t706 + t709) * t290) + t720)
    + t721) + t726) * t105 + (((2.0 * t634 * t112 * t39 + (-4.0 * t640 - 2.0 *
    t645) * t38) + 2.0 * t650) - t662) * t106) + (t731 + t735) * t39) + ((-2.0 *
    t738 - t741) * t290 + t746) * t38) + ((-2.0 * t749 + 2.0 * t752) + 2.0 *
    t753) * t290) + t767) + ((((t5299 - t770) - t773) + t775) + t777) * t440) +
    t781) * t241 + ((((((((((-t600 - 4.0 * t601) * t38 + -8.0 * t596) + t608) +
    4.0 * t609) * t105 + -t593) - t613) + (-4.0 * t615 + 2.0 * t618) * t38) -
    4.0 * t623) - t626) + 4.0 * t628) * t288) - t796) + ((((((t810 - t600) +
    t811) * t38 + (t801 + t802) * t39) + t817) + t608) - t818) * t105) + t828) +
    ((((-t831 + t832) + t834) * t290 + t837) - t842) * t38) + ((-t847 + t849) -
    t860) * t290) + t863) + t894) - 2.0 * t899) * t346 +
    (((((((((((((((((((((((tmpreturn_tmp_h + t406) - t408) * t105 + t319) - t417)
    + t455) + t519) - t526) * t241 + t289) + t107) + t541) + t549) + t564) +
    t571) - t263) - t9) + t881) + t576_tmp) - t29) + t282) + t101) - t33) + t35)
    - t580) * t267) + t289) + ((((((((((((((((((t358 - t383) - t913) - t915) *
    t38 + (t329 + t331) * t39) + t406) + t407) - t920) - t921) * t105 + ((((2.0 *
    t296 - 2.0 * t304) * t38 + -t293) - t310) + t906) * t106) + (-t415 * t290 +
    t927) * t39) + ((((((t2 * t943 + t452) + t933) - t938) - t946) + t948) +
    t952) * t38) + t519) + t960) - t964) - t970) + tmpreturn_tmp) + t980) - t981)
    * t241) + t1006 * t106) + (((((((((((t1015 + t1019) + t1021) - t974) - t1023)
    * t290 + t1035) - t174) * t38 + ((-2.0 * t1008 + 2.0 * t115) - 2.0 * t122) *
    t39) + ((((((t1045 * t42 + t1051) * t2 + (-t1041 + t1044)) + t1055 * t42) +
    t1057) - t1059) - t1063) * t290) + t1079) - t1082) + t221) * t105) + t1087)
    + (((((((t1101 * t114 - t1104) - t1105) * t290 + (-t1110 - t227) * t114) +
    t49) + t61) + t750) + t82) * t38) + (((((((t1124 * t114 - t1128) - t1132) -
    t1134) + t1136) + t1138) - t1140) + t1142) * t290) + (-t1147 - t262) * t114)
                      + ((((((((((-2.0 * t1160 - t9) + t576) - t98) + t28) +
    t282) - t102) + t32) + t35) - 2.0 * t1164) + t579)) * t1170) +
                    ((((((((((((((((((((((((((tmpreturn_tmp_i + t1865) - t402) -
    t404) * t290 + ((t1845 + t332) * t39 + (t1854 - t362) * t38)) + t408) * t105
    + (((-t306 * t38 + t293) + t310) + t317) * t106) + t417) + (t1877 + t453) *
    t38) + (t1884 + t517) * t290) + t526) * t241 + t1839) + t1819) + ((((((-t534
    + t1822) + t174) * t38 + -t530 * t39) - t539) + t1825) - t221) * t105) +
    t372) + (((((((-t2 * t558 - t2121) + t1345) + t228) - t239) + t385) + t46) +
    t553) * t38) - t571) + t263) + t9) - t881) - t576_tmp) + t29) - t282) - t101)
                       + t33) - t35) + t580) * t267) +
                   ((((((((((((((((((((((((t1573 * t290 + t693) - t694) - t700) *
    t38 + t675) + (2.0 * t705 - 2.0 * t708) * t290) - t720) - t721) - t725) *
    t105 + (((-(t338 - 2.0 * t633) * t112 * t39 + (2.0 * t640 + 2.0 * t645) *
    t38) - t650) + t662) * t106) + (-t730 - t735) * t39) + (t1580 * t290 - t746)
    * t38) + ((t1582 - t1583) - t753) * t290) + (-t757 + t764) * t114) +
    ((((t2205 + t770) + t773) - t775) - t777) * t440) - t780) * t241 + (((((((((
    -t1601 * t38 + 4.0 * t596) - t608) - t818) * t105 + t593) + t613) - t1640 *
    t38) + t863) + t626) - t1644) * t288) + t796) + (((((-t801 - 2.0 * t595) *
    t39 + ((-t810 + t600) - t601) * t38) - t817) - t608) + t609) * t105) - t828)
    + ((((t831 - t832) - t833) * t290 - t615) + t842) * t38) + ((t847 - t849) +
    t859) * t290) - t623) - t894) + t899) * t346) +
                  ((((((((((((((tmpreturn_tmp_z + t915) * t38 + -t352) - t407) +
    t919) + t921) * t105 + -2.0 * q__p[2] * t1182 * t106) - t271) + (((((-t943 *
    t2 - t932) + t938) + t946) - t948) - t952) * t38) + (t955 - t958) * t114) +
                       t963) + t970) - tmpreturn_tmp) + t1523) + t981) * t241) +
                 (((((((((((((-t236 + t49) + t61) + t750) + t82) * t38 + t40) +
    t343) - t9) + t576) - t98) + t28) - t102) + t32) + t35) * t106) +
                (((((((((-t231 - t1019) - t1021) + t974) + t1023) * t290 - t1822)
                    * t38 + t114 * t1990 * t586) + ((((((t1040 - t1044) + t1755)
    + t1757) - t1057) + t1059) + t1063) * t290) + t211) + t1081) * t105) + t2003)
              + (((((((((-t1101 * t114 + t1103) + t1105) * t290 + t2009) + t1806)
                     + t2013) + t1141) + t239) - t46) - t385) * t38) +
             (((((((t114 * -t1124 + t1127) + t1132) + t1134) - t1136) - t1138) +
               t1140) - t1142) * t290) + t696 * t1145 * t114) + t1160) + t345) +
         t576_tmp) - t28) + t101) - t32) + t1164) - t579;
  t201 = -t200 * t201 * param->m__l6;
  t628 = (((((((t2123 + t201) + t207) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t2031 = t628 * t106;
  t2032 = t77 * -t78;
  t6350 = (t300 + t302) - t76;
  t623 = t6350 + t2032;
  t211 = t93 * -t78;
  t2036 = t92 - t211;
  t82 = t2036 * t42;
  t3623 = t623 * t38;
  t2038 = ((t3623 + t82) + t312) + t314;
  t725 = ((-t1187 * t42 + t1186) + t1189) * t38;
  t2050 = (((t500 * t501 - t497) - t499) - t68) * param->m__l6;
  t2052 = (((((((((-t508 + param->I__l7yy) - param->I__l7xx) + t511) + t515) -
               param->I__l4xx) + param->I__l4yy) - param->I__l5yy) +
            param->I__l5zz) + param->I__l6xx) - param->I__l6zz;
  t49 = q__p[0] * t940;
  t2057 = t49 - q__p[2];
  t645 = t113 * t39;
  t1609 = t150 * t761;
  t150 = -t76 + t2032;
  t694 = t150 * q__p[5];
  t2085 = -t192 - t694;
  t735 = ((((((((-t199 + t201) + param->I__l7xx) + t207) - param->I__l5xx) +
             param->I__l5yy) - param->I__l6yy) + param->I__l6zz) -
          param->I__l7zz) * q__p[4];
  t2093 = t639 * t49;
  t2097 = t173 * t290;
  t2099 = 4.0 * t2097 * t49;
  t61 = t679 * t290;
  t2101 = 4.0 * t61;
  t2110 = q__p[4] * t150;
  t650 = (-t225 - t92) + t211;
  t2115 = t650 * q__p[3];
  t2119 = t290 * t220;
  t2121 = 4.0 * t2119 * t49;
  t2122 = t707 * t290;
  t2123 = 4.0 * t2122;
  t2129 = q__p[4] * -t2036 * t42;
  t2135 = -t150 * t42;
  t211 = t168_tmp * -t78;
  t2137 = t211 * param->m__l6;
  t662 = (((t2149 + t2135) + t256) + t2137) + t260;
  t2139 = q__p[3] * t662;
  t2143 = 4.0 * t732;
  t1603 = 2.0 * t113;
  t2145 = t2143 - t1603;
  t2147 = t290 * t650;
  t732 = q__p[0] * t114;
  t2149 = t732 * t940;
  t2152 = t650 * q__p[2];
  t2154 = 4.0 * t2152 * t543;
  t2155 = 2.0 * t744;
  t675 = 2.0 * t1609;
  t2162 = (((((t150 * t42 + t1235) - t2137) + t248) - t256) - t260) * t114 +
    t751_tmp;
  t2163 = t2162 * t290;
  t2168 = 4.0 * q__p[2] * t2162 * t290;
  t2169 = t221 * t114;
  t2170 = 2.0 * t2169;
  t2173 = -2.0 * t2085 * t42;
  t2185 = 2.0 * t775;
  t150 = q__p[1] * t940;
  t2195 = 2.0 * t312;
  t2198 = 2.0 * t314;
  t1573 = t628 * t114 * t105;
  t2205 = -t2036 * t42;
  t225 = q__p[0] * t42;
  t726 = t120 * t940 * t225;
  t2217 = t623 * q__p[3];
  t693 = (((((((t2492 + t201) + t207) - param->I__l5xx) + param->I__l5yy) -
            param->I__l6yy) + param->I__l6zz) + param->I__l7xx) - param->I__l7zz;
  t2223 = t693 * q__p[0];
  t746 = 2.0 * t2223 * t940;
  t721 = (t312 + t82) + t314;
  t2227 = q__p[3] * t721;
  t2230 = t693 * q__p[2];
  t2231 = 2.0 * t2230;
  t2235 = t290 * t799 * t39;
  t2237 = t623 * q__p[0];
  t2238 = t114 * t940;
  t2239 = t2237 * t2238;
  t2241 = 4.0 * t806;
  t452 = param->s__l7z * q__p[6];
  t495 = param->l__6 * q__p[6];
  t4054 = t452 + t495;
  t2244_tmp = t4054 + t428;
  t600 = t18 * t2244_tmp;
  t806 = tmpreturn_tmp_0 - 2.0 * t600;
  t2248 = t806 * t2;
  t2250 = t26 * t2244_tmp * t16;
  t558 = 2.0 * t2250;
  t1309 = q__p[5] * -t78 + t389;
  t2254 = t77 * t1309;
  t2255 = 2.0 * t2254;
  t82 = t623 * q__p[2];
  t2259 = t82 * t114;
  t2265 = 4.0 * t732 * t721 * t940;
  t2266 = t693 * q__p[3];
  t2268 = 2.0 * t2266 * t114;
  t530 = param->s__l7z * q__p[4];
  t555 = q__p[4] * param->l__6;
  t60 = t530 + t555;
  t799 = t60 - t266;
  t700 = (t458 - t799 * param->s__l7x / 4.0) * param->m__l7 * t2;
  t2277 = 8.0 * t700;
  t2279 = param->s__l6y * t1309 * param->m__l6;
  t2280 = 2.0 * t2279;
  t201 = t799 * param->m__l7;
  t2284 = t201 * t169_tmp;
  t573 = 2.0 * t2284;
  t2289 = 4.0 * t330 * t721;
  t799 = t112 * q__p[0];
  t2294 = (t940 * t799 - t784) + t824;
  t817 = t60 + t266;
  t2303 = param->m__l7 * t817;
  t2304 = t2303 * param->s__l7y;
  t593 = 2.0 * t2304;
  t2307 = (-t1262 * t42 + t593) * t2;
  t2309 = -t1270 * t42;
  t2311 = t18 * t817 * t16;
  t596 = 2.0 * t2311;
  t757 = -t78 * q__p[4];
  t784 = t757 - t234;
  t2315 = t93 * t784;
  t2316 = 2.0 * t2315;
  t2319 = 2.0 * t2217;
  t2335 = ((((((((((((((((((-t890 * param->m__l3 - t879) - t876) - t334) -
    t876_tmp) - param->I__l3xx) + param->I__l3yy) - param->I__l4yy) +
                     param->I__l4zz) + param->I__l5xx) - param->I__l5zz) -
                  param->I__l6xx) + param->I__l6yy) - param->I__l7yy) +
               param->I__l7zz) + t108) - t491) + t505) + t508) - t871;
  t767 = -t158 * t3;
  t771 = -t1283 * t42;
  t608 = t452 / 2.0;
  t613 = t495 / 2.0;
  t618 = t428 / 2.0;
  t2347 = (((t51 - t608) - t613) + t618) * t26;
  t2348 = 4.0 * t2347;
  t2350 = (t771 + t2348) * t2;
  t2351 = t77 * t784;
  t2352 = t386_tmp - t2351;
  t386_tmp = 2.0 * t2352 * t42;
  t2357 = (t4054 - t428) * t18 * t16;
  t2358 = 2.0 * t2357;
  t2359 = t211 * q__p[4];
  t2362 = -t1210 * q__p[5];
  t2364 = (2.0 * t2359 + t2362) * param->m__l6;
  t764 = ((-t312 + t2205) - t314) + t523;
  t2369 = 2.0 * q__p[3] * t764;
  t1309 = t120 * t39;
  t2383 = 2.0 * t543 * t1309;
  t2385 = t550 * t290 * t38;
  t2389 = (-t114 * t220 - t567) * t290;
  t2397 = t670 * t39;
  t2399 = -t3 * t685;
  t2402 = -t42 * t688;
  t2407 = t115 / 2.0;
  t337 = (t2407 - t529) * t39;
  t2410 = 2.0 * t139;
  t2411 = t145 / 2.0;
  t458 = -t148 / 2.0;
  t2413 = t458 * param->m__l7;
  t2414 = t1609 / 2.0;
  t2415 = t154 / 2.0;
  t2421 = t57 / 2.0 + -t179;
  t2422 = t2421 * t3;
  t2423 = -t185 / 2.0;
  t2426 = (t2423 * t42 - t188) * t2;
  t2434 = t2115 * t114;
  t2436 = (t684 - t46) * t3;
  t2437 = t58 / 2.0;
  t2438 = t235 / 2.0;
  t2440 = ((-t56 - t2437) - t2438) * t2;
  t2441 = t239 / 2.0;
  t684 = t46 / 2.0;
  t688 = t757 + t234;
  t2444 = t77 * t688;
  t2448 = t2139 * t114;
  t2449 = t201 * t27;
  t2452 = ((-t2449 / 2.0 - t17) + t712) * t2;
  t2453 = t201 * t94;
  t2457 = ((t93 * t688 / 2.0 - t2453 / 2.0) - t276 / 2.0) * t42;
  t2458 = t101 / 2.0;
  t2469 = q__p[0] * t39;
  t2472 = t173 * q__p[0];
  t2473 = t2472 * t1170;
  t2475 = t623 * q__p[1];
  t500 = t220 * q__p[0];
  t2483 = t500 * t1170;
  t2485 = t114 * t721;
  t2492 = t440 * t940;
  t2496 = t650 * q__p[0];
  t2497 = t114 * t1170;
  t2506 = t2162 * q__p[0];
  t2509 = (((((((((((((((t484 + t489) + t491) + t496) + t2050) - t505) - t508) +
                   param->I__l7yy) - param->I__l7xx) + t511) + t515) -
               param->I__l4xx) + param->I__l4yy) - param->I__l5yy) +
            param->I__l5zz) + param->I__l6xx) - param->I__l6zz;
  t2518 = 4.0 * t82;
  t332 = t822 * t290;
  t685 = t294 * t440;
  t2540 = t2217 * t114;
  t2547 = t650 * q__p[1];
  t2554 = t2227 * t114;
  t1210 = t360 * q__p[1];
  t1179 = 4.0 * t1210;
  t2576 = -t514 * t3;
  t2578 = -t806 * t2;
  t796 = t601 * t114;
  t2586 = 2.0 * t796;
  t2593 = -t446 * param->m__l7;
  t2598 = q__p[3] * t2509;
  t780 = t568 * q__p[1];
  t446 = t290 * t42;
  t1601 = q__p[0] * t120;
  t875 = t1601 * t1170;
  t2625 = t693 * t290;
  t514 = q__p[0] * t1170;
  t2635 = t595 * t197;
  t1644 = 4.0 * t2635;
  t2641 = t623 * t114;
  t2643 = t695 * t699;
  t2644 = t2643 / 2.0;
  t2645 = t2641 * t290 - t2644;
  t2646 = t2645 * q__p[0];
  t349 = t2097 * t1038;
  t2652 = 2.0 * t623 * q__p[5];
  t2659 = t724 * t695;
  t2660 = t2659 / 2.0;
  t2661 = t2485 * t290 - t2660;
  t2662 = t2661 * q__p[0];
  t2665 = t220 * t440;
  t358 = t338 * t2665;
  t1583 = t133 - t21 / 2.0;
  t1262 = t2 * param->s__l7y;
  t709 = t1583 * param->m__l7 * t1262;
  t1580 = 2.0 * t709;
  t1270 = param->m__l7 * t10;
  t82 = t1270 * q__p[6];
  t806 = (t3356 - param->I__l7zz) * q__p[6];
  t201 = t806 / 2.0;
  t2681 = (((((-t126 + t1580) - t145) + t82) + t1609) - t201) * (2.0 * t42);
  t2692 = 2.0 * t291 * q__p[0];
  t2695 = t448 * t290;
  t2698 = t433 * t440;
  t211 = t670 * t42;
  t2702 = t211 * t114;
  t501 = 4.0 * t2702;
  t2707 = 4.0 * t2695 * q__p[0];
  t2711 = ((-t758 - t170) + t151) - t259;
  t2713 = t114 * t2711 + t281;
  t801 = t695 * t2713;
  t2715 = t2509 * t290 + t801;
  t2716 = t2715 * q__p[0];
  t519 = t26 * t52 * t2;
  t398 = t1739 * param->m__l7;
  t401 = param->m__l6 * t69;
  t878 = param->I__l6xx / 2.0;
  t880 = param->I__l6yy / 2.0;
  t886 = param->I__l6zz / 2.0;
  t890 = param->I__l7xx / 2.0;
  t784 = param->I__l7yy / 2.0;
  t824 = param->I__l7zz / 2.0;
  t688_tmp = t398 + t401;
  t688 = (((((t688_tmp + t878) - t880) + t886) + t890) + t784) - t824;
  t306 = q__p[5] * t688;
  t406 = (-t519 - t63) + t306;
  t2735 = 2.0 * t406;
  t701 = t440 * t670;
  t810 = t701 * t39;
  t2746 = t510 - 4.0 * t2110;
  t2748 = t623 * t290;
  t2754 = ((((t991 + 4.0 * t2129) + t29) - t1005) + t33) + t284;
  t2763 = 2.0 * t291 * t433;
  t991 = t440 * q__p[0];
  t1640 = t991 * t940;
  t2776 = t638 * t290;
  t2778 = 4.0 * t360 * t2776;
  t781 = 2.0 * t735;
  t2794 = t114 * t2625 + t957;
  t1755 = t639 * t2149;
  t2808 = 2.0 * t2434;
  t2819 = t2643 * t114;
  t2820 = t2748 - t2819;
  t2842 = t2659 * t114;
  t2843 = (((t764 * t290 + t1154) + t1155) + t1157) + t2842;
  t2848 = t290 * q__p[4];
  t2849 = t1038 - t2848;
  t828 = t2849 * t112 * t39;
  t510 = t42 * t440;
  t2853 = t595 * t510;
  t1582 = (((-t126 + t2410) + t143) - t2411) + -t458 * param->m__l7;
  t2856 = (t1582 + t2414) - t2415;
  t800 = t693 * q__p[1];
  t831 = t800 * t440;
  t2863_tmp = t2085 * t42;
  t2864 = (t2947 + t2863_tmp) + t735;
  t1352 = 8.0 * t875;
  t458 = 4.0 * t1601;
  t2880 = t48 + 2.0 * t2110;
  t2881 = t2880 * t114;
  t2887 = 2.0 * t2472;
  t2892 = ((((t2910 - t2129) - t715) + t101) - t716) - t669;
  t2893 = t2892 * t114;
  t2900 = 2.0 * t500;
  t2903 = t729 * t440;
  t2904 = t734 * t290;
  t2910 = t214 * t695;
  t2911 = t2910 * t290;
  t2912 = t114 * t650;
  t2913 = -t2911 + t2912;
  t2914 = t2913 * q__p[0];
  t2917 = t839 * q__p[1];
  t48 = t34 * t16;
  t2923 = (-t86 + t48) * t18 * t2;
  t60 = param->m__l7 * t11;
  t86 = ((t60 + t890) - t784) + t824;
  t1283 = t86 * q__p[6];
  t2936 = t858 * t290;
  t2938 = (((t114 * t662 - t2936) - t751_tmp) + t896) + t897;
  t2939 = t2938 * q__p[0];
  t2945 = t18 * q__p[6] * t1663;
  t2947 = t91 * t42;
  t2948 = t26 * q__p[6] * t2947;
  t2949 = t1740 * param->m__l7;
  t2950 = t1534 * t69;
  t1534 = param->I__l5zz / 2.0;
  t1663 = param->I__l5xx / 2.0;
  t413 = param->I__l5yy / 2.0;
  t503 = param->m__l5 * t204;
  t2956 = (((((((((t1534 - t1663) + t413) - t880) + t886) + t890) - t824) + t878)
            + t503) + t784) * q__p[4];
  t204 = t49 + q__p[2];
  t1452 = 2.0 * t628 * t204 * t106;
  t894 = q__p[1] * t39;
  t2971 = t1012 * t894;
  t2973 = t601 * t440;
  t1724 = t112 * t204;
  t842 = 2.0 * t1724 * t39;
  t2983 = t448 * q__p[0];
  t3001 = -t328 * t39;
  t3004 = (t89 - t2304) * t2;
  t3010 = (t1859 - 2.0 * t2347) * t2;
  t3017 = t415 * t39;
  t3018 = (-t427 + t183) - t600;
  t3024 = 4.0 * t700;
  t958 = t112 * t1990 * t39;
  t3040 = t595 * t446 * t440;
  t960 = t2625 * t1038;
  t963 = 8.0 * t665;
  t860 = 4.0 * t671;
  t964 = 2.0 * t291 * t1038 * t39;
  t600 = 4.0 * t709;
  t427 = 2.0 * t82;
  t847 = 2.0 * t16 * t2010 * t2;
  t849 = 2.0 * t694 * t42;
  t3093 = param->m__l5 * t205;
  t859 = (((((((((((-t78 * -t78 * param->m__l6 + t1270) + t878) + t880) - t886)
                - t890) + t784) + t824) + t1534) + t1663) - t413) + t3093) *
    (2.0 * q__p[4]);
  t205 = t290 * t39;
  t3100 = t701 * t205;
  t3113 = -t124 * t290;
  t3115 = t729 * t114;
  t3120 = t650 * t440;
  t1189 = t360 * t638;
  t1081 = t800 * t114;
  t1757 = t732 * t1170;
  t3169 = 2.0 * t930 * t732;
  t3172 = t568 * t440;
  t3183 = q__p[0] * t568;
  t3185 = 2.0 * t3183 * t440;
  t1101 = t628 * q__p[0];
  t3193 = t120 * t2849;
  t1124 = 4.0 * t3193 * t39;
  t124 = t290 * t695;
  t3197 = t124 * t699;
  t3198 = t3197 / 2.0;
  t3203 = 2.0 * t2973;
  t3204 = t57 * t246;
  t2010 = t45 * t249;
  t4594 = (t2010 + t608) + t613;
  t3208 = (t4594 + t618) * t18 * t2;
  t3210 = t77 * t428;
  t3217 = t2659 * t290 / 2.0;
  t694 = t34 * t249;
  t700 = t530 / 2.0;
  t701 = t555 / 2.0;
  t709 = t266 / 2.0;
  t3226 = ((t694 - t700) - t701) + t709;
  t1187 = t18 * t3226 * t2;
  t3229 = 2.0 * t1187;
  t3230 = -t147 + t465;
  t3233 = param->s__l6y * q__p[4] * t855;
  t3235 = (t3356 + param->I__l7zz) * q__p[6];
  t3236 = t3235 / 2.0;
  t3252 = t2304 / 2.0;
  t246 = ((t28 + t32) - t669) * t42;
  t1503 = t2311 / 2.0;
  t1511 = t276 / 2.0;
  t970 = 4.0 * t617;
  t1128 = t801 * t290;
  t3268 = 2.0 * t1128;
  t749 = (t51 + t618) * param->m__l7 * param->s__l7y;
  t1145 = 2.0 * t749;
  t1160 = t18 * t428 * t16;
  t1164 = t60 * q__p[5];
  t899 = t68 * q__p[5];
  t3292 = t2359 - t899;
  t3294 = ((((-param->I__l6zz - param->I__l7xx) + param->I__l6xx) -
            param->I__l6yy) + param->I__l7yy) - param->I__l7zz;
  t720 = q__p[5] * t3294;
  t1175 = t720 / 2.0;
  t3301 = t939 * t3;
  t939 = 2.0 * t3301;
  t3303 = param->s__l7x * t868;
  t3307 = t1022 * t1133;
  t1019 = 4.0 * t3307;
  t3310 = t168_tmp * t168_tmp + t11;
  t3314 = ((t497 + t499) + t877) + t68;
  t3319 = param->d__1 - param->s__l2z;
  t3323 = param->m__l3 * t888;
  t3324 = param->m__l4 * t513;
  t3325 = param->m__l5 * t509;
  t3326 = param->I__l3xx / 2.0;
  t3327 = param->I__l3yy / 2.0;
  t3328 = param->I__l3zz / 2.0;
  t3329 = param->I__l4xx / 2.0;
  t3330 = param->I__l4yy / 2.0;
  t3331 = param->I__l4zz / 2.0;
  t3344 = t320 / 2.0;
  t3345 = t63 / 2.0;
  t3346 = t73 / 2.0;
  t3355 = t446 * t120;
  t3356 = t991 * t2497;
  t977 = (t89 - t593) * t2;
  t11 = t732 * t440;
  t3369 = 4.0 * t11 * t3355;
  t3372 = t2794 * t440;
  t513 = 4.0 * t749;
  t1021 = (t1284 - t513) * t2;
  t888 = 2.0 * t1160;
  t749 = 2.0 * t1164;
  t3397 = t360 * t338;
  t3402 = t2820 * t440;
  t1041 = 2.0 * t3204;
  t1186 = 4.0 * t3208;
  t752 = 2.0 * t3210;
  t3408 = (((t1041 - t1186) + t1314) + t558) - t752;
  t3412 = t2097 * t433;
  t509 = 2.0 * t3412;
  t3423 = param->s__l2y * param->s__l2x * param->m__l2;
  t3425 = (t2843 * t440 + t3423) * q__p[0];
  t1187 *= 4.0;
  t3430 = -2.0 * t3230;
  t3431 = t3430 * param->m__l7;
  t3432 = 2.0 * t3233;
  t3437 = t3310 * param->m__l7;
  t3438 = t3314 * param->m__l6;
  t1523 = ((((((((((-param->I__l4yy + param->I__l4zz) + param->I__l5xx) +
                  param->I__l5yy) - param->I__l5zz) - param->I__l6xx) +
               param->I__l6yy) + param->I__l6zz) + param->I__l7xx) -
            param->I__l7yy) + param->I__l7zz) / 2.0 + (((((((((t108 - t871) -
    t491) + t3437) + t3438) + t3325) + t505) + t3324) + t508) + t3329);
  t3444 = 2.0 * t1523 * q__p[3];
  tmpreturn_tmp = 4.0 * t74 * t42;
  tmpreturn_tmp_0 = t2352 * t42;
  tmpreturn_tmp_2 = (t2399 + -t59 * t2) + t2402;
  tmpreturn_tmp_3 = -t456 + t3229;
  tmpreturn_tmp_4 = (4.0 * t299 + 2.0 * t302) - 2.0 * t76;
  tmpreturn_tmp_5 = 2.0 * t290 * ((((((t2169 + t2945) - t2948) + t2949) + t2950)
    + t2956) + t775);
  tmpreturn_tmp_c = (((t126 - t2410) - t143) + t2411) + t2413;
  tmpreturn_tmp_f = t2145 * t39;
  tmpreturn_tmp_j = (((t1871 + t3018 * t2) + t435) + t2250) - t420_tmp;
  tmpreturn_tmp_k = t457 - t3024;
  tmpreturn_tmp_o = (((t2576 + t2578) - t1314) - t558) + t257;
  tmpreturn_tmp_p = -t1029 + t2593;
  tmpreturn_tmp_q = -t1322 + t2277;
  tmpreturn_tmp_s = -2.0 * t290 * ((((t744 - t126) + 2.0 * t2923) + t144) -
    t1283);
  tmpreturn_tmp_t = t457 - t1187;
  tmpreturn_tmp_u = (((t340 + (t42 * t667 - t3252) * t2) + t246) - t1503) +
    t1511;
  tmpreturn_tmp_x = (((t341 + t977) + t660) - t596) + t1273;
  tmpreturn_tmp_1c = -2.0 * t105 * t114;
  tmpreturn[7] = (((((((((((((((((((((((((((((((((((((((((((((((tmpreturn_tmp_2
    + t2110) * t38 + t2397) + t8) + t3019) - t2129) - t715) + t101) - t716) -
    t669) * t106 + ((((((tmpreturn_tmp_c - t2414) + t2415) * t114 - t174) * t38
    + t337) + ((t2863_tmp / 2.0 + (t2422 + t2426)) + t735 / 2.0) * t114) + t221)
    * t105) + t2397) + ((((((t2434 + t2436) + t2440) + t2402) + t2441) + t684) -
    t2444 / 2.0) * t38) - t2448) - t9) + t2452) + t2457) - t715) + t35) - t716)
    - t2458) + t282) * -4.0 * t440 * t12 + 2.0 * t1038 * t628 * t940 * t106) +
    ((((((-4.0 * t940 * t2475 * t598 + 4.0 * t2472) - 8.0 * t2473) * t38 +
    (t1170 - 0.5) * -16.0 * t120 * t2469) + 8.0 * t2483) - 4.0 * t1038 * t2485 *
    t940) - 4.0 * t500) * t105) + 2.0 * t729 * t2492 * t39) + ((-4.0 * t114 *
    t2496 - 4.0 * t2492 * t740) + 8.0 * t2496 * t2497) * t38) + 8.0 * t2506 *
    t1170) + 2.0 * q__p[1] * t2509 * t2492) - 4.0 * t2506) * t288 +
    ((((((((((((((((((((((((((4.0 * t2540 - t1259) + t2307) + t2309) + t596) -
    t1273) - t2316) * t290 + 8.0 * t361) * t440 + -8.0 * t685 * t2149) - 2.0 *
    t2547) * t38 + ((t2238 * t799 + t332) - t331) * (4.0 * t440) * t39) + 4.0 *
    t693 * t440 * t2149) + (((((((((4.0 * t2554 + t767) + t2350) + t386_tmp) -
    t2358) - t1292) + t2364) + t1297) + t1298) * t290 - 4.0 * t2230 * t114) *
    t440) + 2.0 * q__p[1] * t662) * t105 + ((((((-4.0 * t940 * t2237 + t2518) -
    t297) * t38 + t293) - 4.0 * q__p[0] * t721 * t940) + t2266 * t290) + 4.0 *
    q__p[2] * t721) * -2.0 * t440 * t106) + (-2.0 * t416 * t440 - t1179) * t39)
    + (((((tmpreturn_tmp_o - t2255) * t114 + t1319) * t290 + t2518) * t440 +
    -4.0 * t623 * t440 * t49) - t2586) * t38) + 4.0 * t440 * t764 * t49) +
    (((((((tmpreturn_tmp_p + t2280) - t1033) * t42 + tmpreturn_tmp_q) + t573) +
    t1331) * t114 - 2.0 * t2598) * t290 - 4.0 * q__p[2] * t764) * t440) + 2.0 *
    t780) * t12 + ((((((-4.0 * t940 * t2217 + 4.0 * t446 * t1601) - 8.0 * t446 *
    t875) * t38 + 4.0 * t291 * (t1170 - 0.5) * q__p[0] * t39) + 4.0 * t2625 *
    t514) - 4.0 * t2227 * t940) - 2.0 * t2625 * q__p[0]) * t106) + ((((((((4.0 *
    t349 + t2241) + t2652) * t940 + -8.0 * t2646 * t1170) + 4.0 * t2646) * t38 +
    (-t1644 + t797) * -2.0 * t940 * t39) - 8.0 * t2662 * t1170) + ((-4.0 * t358
    - t2268) - t2681) * t940) + 4.0 * t2662) * t105) + ((2.0 * t940 * t823 + 4.0
    * t514 * t291) - t2692) * t39) + ((((-4.0 * t2147 * t2698 + t2319) - t501) *
    t940 + -8.0 * t2695 * t514) + t2707) * t38) + 4.0 * t2716 * t1170) + ((-4.0 *
    t2162 * t440 * t338 + t114 * t2735) - t2369) * t940) - 2.0 * t2716) * t241)
    + ((((((((((((((((t3887 + t675) - t1033) * t114 + -4.0 * t2152 * t290) -
    t175) * t440 + 4.0 * t2147 * t1640) - t2778) * t38 + ((-t1359 - t123) * t440
    + t2763) * t39) - 4.0 * t197 * q__p[0] * t662 * t940) + ((((t3576 + t2173) -
    t781) * t114 + 4.0 * q__p[2] * t662 * t290) + t222) * t440) + 2.0 * t2794 *
    q__p[1]) * t105 + ((((4.0 * t2748 * q__p[1] + t2746 * t440) * t38 + -4.0 *
    t810) + t2754 * t440) + 4.0 * t338 * t721) * t106) + ((((((t1755 - t544) +
    t8) + t668) + t28) + t32) - t669) * (8.0 * t440) * t39) + (((((((((-8.0 *
    t56 + t1419) - t1420) * t2 + ((-4.0 * t552 + t2808) + 4.0 * t554 * t3)) -
    tmpreturn_tmp) + t1423) - t230) + 2.0 * t2351) * t440 + 4.0 * t2097 * t440 *
    t2149) - 2.0 * t2820 * q__p[1]) * t38) + (t2389 + t1540) * 4.0 * t440 * t49)
    + ((((((((((2.0 * t27 * t2303 - t270) + t342) * t2 + ((4.0 * t570 - 2.0 *
    t2448) - t265)) + ((2.0 * t2311 - 2.0 * t276) - 2.0 * t2315) * t42) - t350)
    - 4.0 * t579) + t283) + t102) - t351) + t284) * t440) + 2.0 * q__p[1] *
       t2843) * t12) + ((((2.0 * t2856 * t290 - 2.0 * t2853) * t38 + t828) +
    t831) - t290 * t2864) * 2.0 * t940 * t106) + (((((((-4.0 * t2475 * t598 +
    2.0 * t290 * (t2881 - t2115)) * t940 + 4.0 * t2473) - t2887) * t38 + ((4.0 *
    t1337 * t2238 + t1352) - t458) * t39) - 4.0 * t2483) + ((t2139 / 2.0 + t2893)
    * (4.0 * t290) + -4.0 * t1038 * t2485) * t940) + t2900) * t105) - (t2903 -
    t2904 / 2.0) * 4.0 * t940 * t39) + (((tmpreturn_tmp_s + 8.0 * t2917 * t440) *
    t940 + -4.0 * t2914 * t1170) + 2.0 * t2914) * t38) + 4.0 * t2939 * t1170) +
    (2.0 * t2335 * t440 * q__p[1] + tmpreturn_tmp_5) * t940) - 2.0 * t2939) *
    t346 / 2.0 + ((((((((((((((((((((((((((((-4.0 * t43 - 16.0 * t46) * t3 + 8.0
    * t2 * t59) + tmpreturn_tmp) - 8.0 * t2110) * t114 + (-t2099 + t2101)) + 2.0
    * t2115) * t38 + ((-8.0 * t2093 + 8.0 * t665) - 8.0 * t671) * t39) + t2121)
    - t2123) + ((((((((-8.0 * t87 - t1260) - t342) * t2 + -t1437) + 8.0 * t2129)
    + t350) - 8.0 * t101) + t351) + t1269) * t114) - 2.0 * t2139) * t105 +
    (((((((((((4.0 * -t148 * param->m__l7 + 8.0 * t126) - 16.0 * t139) - 8.0 *
    t143) + 4.0 * t145) + 4.0 * t154) - 4.0 * t1609) * t38 + 4.0 * t645) + (-8.0
    * t179 + 4.0 * t57) * t3) + (4.0 * t42 * -t185 - 8.0 * t188) * t2) + 4.0 *
    t2085 * t42) + 4.0 * t735) * t106) + tmpreturn_tmp_f) + (((((((((4.0 * t2147
    * t2149 - t1026) + t1027) + t1028) - t1029) - t1033) + t1368) - t2154) +
    t2155) + t675) * t38) + 4.0 * t2163 * t49) - t2168) - t2170) + t1378) +
    t1382) + t2173) + 2.0 * t770) - 2.0 * q__p[4] * -t200 * t772) + ((((((2.0 *
    -t206 * param->m__l5 + 2.0 * param->I__l5xx) - 2.0 * param->I__l5yy) - 2.0 *
    param->I__l6zz) + t1213) + t1214) - t481) * q__p[4]) - t2185) * t12 +
                     ((((((((((tmpreturn_tmp_4 + 2.0 * t2032) * t38 + t2195) +
    2.0 * t2036 * t42) + t2198) * t106 + t1573) - t3623) - t312) + t2205) - t314)
                      + t523) * (4.0 * t150)) * t241 +
                    ((((((((((tmpreturn_tmp_1c * t2038 + t2031) + t725) + t2050)
    + t2052) + t484) + t489) + t491) + t496) - t505) + t586) * (-2.0 * t12) *
                    t2057 * t288) + ((((((((((((((((((t2241 + t1308) + t2248) +
    t1314) + t558) - t257) + t2255) * t290 + 4.0 * t2239) - 4.0 * t2259) * t38 +
    -2.0 * t2235) + t2265) + (((((t3575 - t2280) + t1033) * t42 + ((-t2268 +
    t1322) - t2277)) - t573) - t1331) * t290) - t2289) * t105 + ((((((-4.0 *
    t2217 * t290 + 4.0 * t726) - 4.0 * t787) * t38 + -2.0 * t112 * t2057 * t39)
    - t746) - 4.0 * t2227 * t290) + t2231) * t106) + 4.0 * t2294 * t39) +
    ((((((((-t1259 + t2307) + t2309) + t596) - t1273) - t2316) * t114 + t2319) *
      t290 + -8.0 * t839 * q__p[0] * t940) + 8.0 * t840) * t38) - 2.0 * t2335 *
    q__p[0] * t940) + ((((((((t767 + t2350) + t386_tmp) - t2358) - t1292) +
    t2364) + t1297) + t1298) * t114 - t2369) * t290) + 2.0 * t2335 * q__p[2]) *
                   t12) + ((((((((((-t650 * t38 + t2135) + t2137) - t248) + t253)
    + t256) + t260) * -t290 * t105 + t2383) + t2385) + t2389) + t1540) * (4.0 *
    q__p[1]) * t940) * t267 / 2.0) + (((((((((((((4.0 * t2239 - 4.0 * t2973) +
    4.0 * t2259) * t38 + -8.0 * t2971) + t2265) + 4.0 * t955) + t2289) * t105 +
    -t1452) - t842) + ((4.0 * t940 * t2983 + 4.0 * t2547 * t598) + 4.0 * t617) *
    t38) - 2.0 * t2509 * q__p[0] * t940) + 4.0 * q__p[1] * t2162 * t440) - 2.0 *
    q__p[2] * t2509) * t12 - (((((((((((((((((((((-2.0 * t2540 + t341) + t3004)
    + t660) - t2311) + t276) + t2315) * t38 + t3001) - 2.0 * t2554) + t1858) +
    t3010) - tmpreturn_tmp_0) + t2357) + t395) + (-t2359 + t1863) * param->m__l6)
    - t402) - t404) * t105 + q__p[3] * t628 * t106) + t3017) + ((tmpreturn_tmp_j
    + t2254) * t114 - t450) * t38) + (((((t1882_tmp - t2279) + t154) * t42 +
    tmpreturn_tmp_k) - t2284) - t475) * t114) + t2598) * 2.0 * t440 * t940) *
    t288 / 2.0) + ((((((((((((((((((((((((((((((-4.0 * t3040 - t1026) + t1027) +
    t1028) - t1029) + t1368) + t675) - t1033) * t38 + 2.0 * t958) + 2.0 * t960)
    + t1378) + t1382) + t2173) - t781) * t106 + ((((((((-4.0 * t2645 * t440 *
    q__p[1] - t2099) - t2101) + 2.0 * t2881) * t38 + ((-8.0 * t2093 - t963) +
    t860) * t39) + t2121) - 4.0 * q__p[1] * t2661 * t440) + t2123) + 4.0 * t2893)
    * t105) + t964) + (((((((((t290 * t2912 - t2910) * 4.0 * q__p[0] * t940 -
    4.0 * t740 * t197) + t2154) + t127) - t600) + t1029) - t427) - t675) + t806)
    * t38) + (t2163 + t858) * 4.0 * q__p[0] * t940) + 2.0 * q__p[1] * t2715 *
    t440) + t2168) + t1069) - t847) - t849) - t859) * t12 - ((((-t290 * t2880 *
    t440 / 2.0 + t2475) * t38 + -t3100) - t290 * t2892 * t440) + q__p[1] * t721)
    * (4.0 * t940) * t106) + ((((((((t114 * t2856 + t174) * (-4.0 * t290) * t440
    + 4.0 * t1189) * t940 + 4.0 * t3120 * t514) - 2.0 * t3120 * q__p[0]) * t38 +
    (-t3113 * t440 + t3115) * -2.0 * t940 * t39) - 4.0 * t991 * t662 * t1170) +
    ((t114 * t2864 + t222) * (2.0 * t290) * t440 - 2.0 * t1081) * t940) + 2.0 *
    t991 * t662) * t105) + ((t1337 * t940 / 2.0 + t1601 * t2497) - t1601 * t114 /
    2.0) * 8.0 * t440 * t39) + (((((((((t2808 + t1829) + t1831) + t1141) + t239)
    + t46) - t2444) * (2.0 * t290) * t440 + 2.0 * t2475) * t940 + 4.0 * t930 *
    t1757) - t3169) * t38) - 4.0 * t3172 * t514) + (((((((((-t2448 - t9) + t2452)
    + t2457) - t715) + t35) - t716) - t2458) + t282) * (4.0 * t290) * t440 - 2.0
    * q__p[1] * t764) * t940) + t3185) * t241 / 2.0) +
                        ((((((((((((((((((((-t3198 + t2641) * -8.0 * q__p[0] *
    t940 + t3203) - ((((t3204 - 2.0 * t3208) + t435) + t2250) - t3210) * (2.0 *
    t290)) * t38 + t1124) - (-t3217 + t2485) * 8.0 * q__p[0] * t940) - t956) +
    (((((param->m__l7 * t3230 - t3233) - t3236) * t42 + tmpreturn_tmp_3) + t2284)
    + t475) * 2.0 * t290) * t105 + 4.0 * t1101 * t940 * t106) - 2.0 * t2294 *
    t39) + (((tmpreturn_tmp_u + t2315 / 2.0) * 4.0 * t114 * t290 + (4.0 * t726 -
    2.0 * t2913 * q__p[1] * t440)) - t970) * t38) - ((((((((((t1767_tmp +
    ((-t3268 + t108) - t111)) + t1774) + param->I__l7xx) + t1780) + t1782) +
    t1787) - t1788) - param->I__l7zz) - param->I__l6yy) + t1799) * 2.0 * q__p[0]
    * t940) + 2.0 * q__p[1] * t2938 * t440) - ((((((((t375 + t1145) * t2 + t373)
    + tmpreturn_tmp_0) + t1160) - t1164) + t3292 * param->m__l6) + t402) + t1175)
    * 2.0 * t114 * t290) - t939) + 4.0 * t947 * t3303 * t2) + t1019) - 2.0 *
    q__p[2] * t3310 * param->m__l7) - 2.0 * q__p[2] * t3314 * param->m__l6) +
    2.0 * param->m__l2 * param->s__l2y * t3319 * q__p[1]) -
    (((((((((((((((((((t3323 + t3324) + t3325) + t508) + t505) - t3326) + t3327)
    + t3328) + t3329) - t3330) + t3331) + t1663) + t413) - t1534) - t878) + t880)
        + t886) + t890) - t784) + t824) * 2.0 * q__p[2]) * t12 / 2.0) - 4.0 *
                       t290 * (t1170 - 0.5) * t2038 * t991 * t106) +
                      ((((((((tmpreturn_tmp_x + t2316) * t440 - 2.0 * t2147 *
    q__p[1]) * t940 + 8.0 * t3355 * t3356) - t3369) * t38 + (((((t3344 - t324) +
    t3345) + t3346) * t940 + t291 * t1757) - t291 * t732 / 2.0) * -4.0 * t440 *
    t39) - 4.0 * t3372 * t514) + ((((((((-2.0 * t3292 * param->m__l6 - t386_tmp)
    + t1281) - t1297) - t720) + t1021) - t888) + t749) * t440 + 2.0 * t338 *
    t662) * t940) + 2.0 * t3372 * q__p[0]) * t105 / 2.0) + (t415 * t440 - 2.0 *
    t3397) * t940 * t39) + ((((t114 * t3408 - t1319) * t440 - t509) * t940 + 4.0
    * t3402 * t514) - 2.0 * t3402 * q__p[0]) * t38 / 2.0) - 2.0 * t3425 * t1170)
                  + (((((((t3431 + t3432) + t3235) * t42 + tmpreturn_tmp_t) -
                        t573) - t1331) * t114 - t3444) * t440 - ((t1163 * t3319
    + t1540) + t2389) * 2.0 * q__p[1]) * t940 / 2.0) + t3425;
  t10 = q__p[1] * t267;
  t499 = t1182 * q__p[1];
  t497 = t114 * t267;
  t2139 = 4.0 * t499 * t497;
  t3466 = (((((t1263 - t593) * t2 + tmpreturn_tmp_1) + t1271) - t596) + t1273) -
    t1274;
  t3469 = (t1284 - t2348) * t2;
  t56 = t204 * t120;
  t1163 = t56 * t1569;
  t1213 = t2472 * t2492;
  t1214 = t991 * t220 * t940;
  t148_tmp_tmp = t586 + t725;
  t148_tmp = (((t148_tmp_tmp + t484) + t489) + t491) + t496;
  t148 = ((((((((((((t148_tmp + t504) - t505) - t508) + param->I__l7yy) + t511)
                - param->I__l7xx) + t515) - param->I__l4xx) + param->I__l4yy) -
            param->I__l5yy) + param->I__l5zz) + param->I__l6xx) - param->I__l6zz;
  t3486 = q__p[1] * t148;
  t3491 = (((((t1308 + t2248) + t1314) + t558) - t257) - t1316) * t114 - t1319;
  t3494 = ((((t1322 - t2277) + t1329) - t573) - t1331) * t114;
  t2147 = 2.0 * t1578;
  t877 = t622 - t751_tmp;
  t3503 = q__p[0] * t877;
  t3506 = t877 * q__p[2];
  t139 = (t940 + 1.0) * q__p[0];
  t2050 = t139 * t440;
  t2152 = (t940 - 1.0) * t589;
  t2154 = 2.0 * t2050 * t2152 * t346;
  t3522 = ((((((((tmpreturn_tmp_2 - t81) * t38 + t2397) + t8) + t3019) + t97) -
             t715) - t669) + t101) - t716;
  t2162 = 4.0 * t3522 * t940;
  t2163 = (t940 + 1.0) * t1182;
  t714 = (t940 - 1.0) * t440;
  t3530 = q__p[0] * t346;
  t2205 = 4.0 * t2163 * t114 * t714 * t3530;
  t3538 = t148 * q__p[0];
  t2217 = t714 * t346;
  t3545 = (t2453 + t276) + t277;
  t415 = t204 * t290;
  t3560 = t589 * t440;
  t3568 = 4.0 * t1363;
  t1308 = t226 * q__p[0];
  t1263 = t1308 * t940;
  t3573 = 2.0 * t1263;
  t3574 = 8.0 * t1014;
  t3575 = param->s__l7z * q__p[2];
  t3576 = q__p[2] * param->l__6;
  tmpreturn_tmp = t3575 + t3576;
  t1014 = tmpreturn_tmp + t966;
  t2399 = t1014 * param->s__l7y;
  t2400 = param->s__l7x * t1014;
  t3584 = 2.0 * t974;
  t3585 = 2.0 * t976;
  t3588 = q__p[0] * t261;
  t1271 = t3588 * t940;
  t3590 = 2.0 * t1271;
  t3591 = 4.0 * t1040;
  t3592 = 4.0 * t1043;
  t3601 = 2.0 * t1403;
  t3602 = 2.0 * t1406;
  t1014 = t114 * t303;
  t3611 = t1014 * t290;
  t481 = t3611 + t2644;
  t2227 = t1484 / 2.0;
  t3623 = t2244_tmp + t1484;
  t2578 = param->s__l7y * t3623;
  t1578 = t2578 * t54;
  t1326 = param->s__l6x * t1619 * param->m__l6;
  t668 = t605 * t290;
  t3634 = t668 - t2660;
  t3635 = t3634 * t440;
  t2108 = -t147 + t1620;
  t2099 = t1619 * param->s__l6y * param->m__l6;
  t1368 = ((((((param->m__l7 * t2108 - t3236) - t2099) * t42 + tmpreturn_tmp_3)
             + t2284) + t1535) + t1629) * 2.0 * t440;
  t1363 = (t1233 + t622) - t751_tmp;
  t3652 = t1363 * q__p[1];
  t1040 = t290 * t267;
  t1763 = t360 * t49;
  t3657 = 4.0 * t1763;
  t1764 = t732 * t173 * t940;
  t3663 = 2.0 * t1764;
  t3664 = 2.0 * t1089;
  t2237 = t1022 / 2.0;
  t2593 = 2.0 * t1099;
  t3675 = 2.0 * t1105;
  t3679 = 2.0 * t3183 * t940;
  t3681 = (2.0 * t2449 + t1260) - t23;
  t2239 = 2.0 * t3545;
  t3686 = ((((((((t2 * t3681 + t2239 * t42) + t102) - t1269) + t1436) + t1437) -
             t1443) + t29) + t33) * t290;
  t3687 = 4.0 * t1127;
  t2115 = tmpreturn_tmp - t966;
  t3696 = 2.0 * t1132;
  t3697 = 2.0 * t1134;
  t2413 = 2.0 * t1136;
  t3699 = 2.0 * t1138;
  t3700 = 2.0 * t1142;
  t3701 = 2.0 * t1140;
  t714 = t290 * t940;
  t2085 = t799 * t714;
  t3714 = 2.0 * t340;
  t3715 = t24 * t42;
  t342 = (-t29 - t33) + t35;
  t2277 = t342 * t42;
  t1799 = (((-t3714 + (t3715 + t2304) * t2) + t2277) + t2311) - t276;
  t3721 = (t1799 + t356) * t114;
  t3726 = t516 * t290;
  t3730 = t3726 - (t114 * t762 - t281) * t695;
  t3731 = t3730 * q__p[0];
  t772 = t877 * q__p[1];
  t1863 = param->s__l7x * t1619 * t54;
  t2057 = (-t1489 - t899) - t396;
  t2304 = t2057 * param->m__l6;
  t1127 = (t940 - 1.0) * q__p[0];
  t2121 = t1127 * t267;
  t2644 = 2.0 * t414 * t714 * t39;
  t179 = t303 * q__p[0];
  t3229 = t179 * t1170;
  t200 = t315 * q__p[0];
  t3236 = t200 * t1170;
  t206 = 4.0 * t200;
  t1260 = q__p[0] * t290;
  t3786 = t1230 * t440;
  t2254 = (t940 - 1.0) * t346;
  t148 = t112 * t114;
  t2032 = t148 * t514;
  t3796 = t148 * q__p[0];
  t297 = 2.0 * t3796;
  t2036 = t294 * t1757;
  t24 = -t24 * t42;
  t1322 = -t342 * t42;
  t3806 = t356 / 2.0;
  t342 = t294 * t732;
  t2509 = -t370 - t41 / 2.0;
  t3819 = t374 / 2.0;
  t3823 = t386 / 2.0;
  t3826 = t395 / 2.0;
  t3827 = t396 / 2.0;
  t3828 = -t70 / 2.0;
  t3832 = t402 / 2.0;
  t3833 = t404 / 2.0;
  t3838 = t1039 * q__p[0];
  t3839 = 2.0 * t3838;
  t2101 = t303 * t38;
  t386_tmp = ((t2101 - t312) + t521) - t314;
  t386 = t386_tmp + t523;
  t1329 = t1363 * q__p[0];
  t374 = t940 * t39;
  t3866 = t524 * q__p[0];
  t3875 = 2.0 * t3866;
  t3881 = 2.0 * t1456;
  t3882 = t303 * t290;
  t3883 = t3882 * t49;
  t3887 = t315 * t290;
  t2038 = t3887 * t49;
  t41 = 4.0 * t1462;
  t3891 = 2.0 * t309;
  t2820 = (((t645 + t644 * t38) + t653) + t657) + t659;
  t3895 = t2820 + t209;
  t3896 = t3895 * t290;
  t644 = t1260 * t940;
  t1462 = t148 * t644;
  t3903 = 2.0 * t1462;
  t2248 = 2.0 * t994;
  t2453 = t3355 * t2149;
  t3908 = 4.0 * t2453;
  t3910 = 2.0 * t915;
  t70 = 4.0 * t211;
  t3916 = t1039 * t290;
  t3918 = (t3916 + t957) * q__p[0];
  t2255 = t4054 + t1484;
  t3933 = q__p[5] * t1739 * param->m__l7;
  t3934 = 2.0 * t3933;
  t3936 = q__p[5] * t69 + t1489;
  t1739 = 2.0 * t3936;
  t3938 = t1739 * param->m__l6;
  t3940 = ((((t404_tmp + param->I__l6zz) + param->I__l7xx) + param->I__l7yy) -
           param->I__l7zz) * q__p[5];
  t3941 = 2.0 * t1492;
  t3944 = t1601 * t940;
  t3947 = t2472 * t940;
  t3949 = t114 * t690;
  t3950 = t3949 * t290;
  t3951 = t1089 / 2.0;
  t3956 = t1099 / 2.0;
  t1089 = t1048 - t1022;
  t340 = t500 * t940;
  t3964 = t717 * t114;
  t3965 = t3964 * t290;
  t1099 = -t695 * q__p[4] + t1060;
  t1216 = ((((((((((t1216 + t1222) + t866) + t871) + t491) + t876_tmp) + t334) -
              t505) - t508) + param->I__l7yy) + t876) +
    ((((((((((-param->I__l7zz - param->I__l6yy) + t879) + param->I__l6xx) -
           param->I__l5xx) + t891) + param->I__l3xx) - param->I__l3yy) +
       param->I__l4yy) - param->I__l4zz) + param->I__l5zz);
  t1060 = t2819 + t3882;
  t3993 = t1060 * q__p[0];
  t2123 = 2.0 * t1045;
  t4000 = 2.0 * t946;
  t717 = 2.0 * t948;
  t2129 = -t695 * q__p[5] + t949;
  t1222 = t77 * t2129;
  t2137 = t420_tmp * t3;
  t4010 = 2.0 * t2137;
  t2135 = -t1484 * t18 - t183;
  t4015 = t26 * t1484 * t16;
  t2093 = t439 - t1484;
  t1489 = t77 * t2093;
  t1871 = t290 * t524;
  t74 = t1871 + t2842;
  t4024 = ((t74 + t1154) + t1155) + t1157;
  t59 = t780 * t440;
  t949 = t695 * t114;
  t4032 = t762 * q__p[3] * t949;
  t4033 = 2.0 * t4032;
  t2646 = t2115 * param->s__l7x * t54;
  t2259 = t93 * t2129;
  t4044 = 2.0 * t981;
  t4048 = 4.0 * t1541;
  t4050 = t1583 * t42 * t758;
  t762 = 4.0 * t4050;
  t1154 = t146 - t1709;
  t2173 = 2.0 * t1154;
  t4054 = t2173 * param->m__l7;
  t2265 = t2093 * param->s__l6y * param->m__l6;
  t4060 = t217 * t1484;
  t1541 = 2.0 * t4060;
  t4065 = t76 * t109 * q__p[3];
  t758 = 4.0 * t4065;
  t4067 = t1270 * q__p[3];
  t4068 = 2.0 * t4067;
  t2129 = t78 * t78;
  t4071 = q__p[3] * t2129 * param->m__l6;
  t4072 = 2.0 * t4071;
  t4073 = param->m__l4 * t512;
  t4078 = t1158 * q__p[2];
  t4082 = t1232 + t2911;
  t4087 = -t1154 * param->m__l7;
  t2168 = param->s__l7y * t2115;
  t4110 = t1736 - t1738;
  t4113 = t2129 * q__p[4] - t1738;
  t4116 = (((((((((t3093 + t1663) - t413) + t880) - t886) - t890) + t824) + t784)
            + t878) + t1534) * q__p[4];
  t4121 = t2123 * t42;
  t2093 = (t940 + 1.0) * t290;
  t1154 = (((((t226 * t38 - t248) + t253) + t254) + t256) - t258) + t260;
  t248 = t226 * t290;
  t4171 = t248 * q__p[0];
  t253 = 2.0 * t4171;
  t4180 = t1260 * t261;
  t512 = 2.0 * t4180;
  t4185 = t568 * t290;
  t4186 = ((-t2383 - t2385) + t4185) - t1540;
  t4191 = q__p[0] * t1216;
  t2383 = (t940 - 1.0) * t114;
  t4203 = t46 * t3;
  t4204 = 4.0 * t4203;
  t4207 = (-2.0 * t58 - 2.0 * t235) * t2;
  t4210 = t732 * t2097;
  t1736 = 2.0 * t4210;
  t4216 = (t4185 - t1540) * q__p[0];
  t4220 = (-2.0 * t2449 - 2.0 * t17) * t2;
  t4222 = -t2239 * t42;
  tmpreturn_tmp = 2.0 * param->m__l7;
  tmpreturn_tmp_0 = (t126 - t1580) + t145;
  tmpreturn_tmp_1 = -t1029 + t4054;
  tmpreturn_tmp_2 = 4.0 * param->m__l7;
  tmpreturn_tmp_3 = t336 + t3714;
  tmpreturn_tmp_d = t3823 * t42;
  tmpreturn_tmp_g = ((-t4010 + t2135 * t2) + t4015) + t420_tmp;
  t126 = 2.0 * param->s__l7x;
  tmpreturn_tmp_l = 2.0 * t26 * t42;
  tmpreturn_tmp_m = tmpreturn_tmp * param->s__l7y;
  tmpreturn_tmp_n = -t2936 + t622;
  tmpreturn_tmp_r = t2 * ((t2449 + t270) - t22);
  t3545 *= t42;
  tmpreturn[14] = (((((((((((((((((((((((((((((((((((((((((((((((((-2.0 *
    t323_tmp * t2399 - 2.0 * t2400 * t54) + t1373) - t3573) + t3574) + t3584) -
    t3585) * t38 + (t1362 - t3568) * t39) - t3590) + t1389) - t3591) + t3592) +
    (2.0 * -t943 * t42 - 2.0 * t1395) * t2) + 2.0 * t1398 * t42) - 2.0 * t1401)
    + t3601) - t3602) * t346 + -4.0 * t338 * t1230 * t267) - (t338 - t633 / 2.0)
    * (8.0 * t120) * t39) + (((((t3204 - ((t4594 + t377) + t2227) *
    tmpreturn_tmp * t697) + t435) + t1578) - t1326) * 2.0 * t440 + (-4.0 * t991 *
    t481 * t940 + 4.0 * t1600 * t290)) * t38) + 4.0 * t3635 * t49) + 4.0 * t1616
    * t290) - t1368) * t105 + (((((8.0 * t1103 + t1347) * t38 + -t1339) + t1354)
    - 8.0 * t561) * t346 - 2.0 * t415 * t3560) * t106) + 4.0 * t3652 * t1040) +
    ((((((((((((((((t3664 - ((-t1476 * q__p[4] + t1091) + t2237) *
    tmpreturn_tmp_2 * t697) + t2593) - 2.0 * t1431) * t114 + ((t3663 + t1426) -
    t1348)) + t3675) * t38 + ((t3657 + t1411) + 4.0 * t1412) * t39) - t3679) +
    t3686) - t3687) + ((((-2.0 * t16 * t26 * t2115 + 2.0 * t18 * t2 * t2115) -
    2.0 * t1121) + 2.0 * t1447) - 2.0 * t1451) * t114) + t3696) + t3697) - t2413)
    - t3699) - t3700) - t3701) * t346) - ((t2085 + t482) - t823) * 2.0 * t440 *
    t39) + ((4.0 * t1639 * t290 + 4.0 * t2695 * t1640) + 2.0 * t3721 * t440) *
    t38) - 2.0 * t3731 * t2492) + (-2.0 * t626 - 4.0 * t772) * t290) +
    (((((((((((t4291 + t2227) * 2.0 * param->s__l7y * param->m__l7 + t375) * t2
    + t373) + t387) + t1863) - t1164) + t2304) + t402) + q__p[5] * t3294 / 2.0)
    + t1492) * t114 - t1667) * 2.0 * t440) * t12 + ((((((4.0 * t940 * t294 *
    t295 + 4.0 * t179) - 4.0 * t3229) * t38 + (-8.0 * t2163 * t2121 - t2644)) +
    4.0 * t3236) - 2.0 * t309 * t714) - t206) * t106) + ((((((-4.0 * t2036 -
    ((((((t24 - t3252) * t2 + tmpreturn_tmp_3) + t1322) - t1503) + t1511) -
    t3806) * (4.0 * t290) * t940) + 4.0 * t342) * t38 + ((-4.0 * t732 * (t940 +
    1.0) * t2152 * t267 + 4.0 * t1260 * (t940 + 1.0) * t3786 * t2254) + ((4.0 *
    t940 * t332 + 2.0 * t2032) - t297) * t39)) + 2.0 * t1039 * t514) +
    ((((((((t3819 * t42 + t2347) * t2 + (t2509 * t3 + t366)) + tmpreturn_tmp_d)
    - t2357 / 2.0) - t3826) + (q__p[5] * t3828 - t3827) * param->m__l6) + t3832)
    + t3833) * 4.0 * t290 * t940) - t3839) * t105) - 4.0 * t386 * (t940 + 1.0) *
    t2121) - 4.0 * t1329 * t290 * (t940 + 1.0) * t440 * t2254) - 2.0 * t416 *
    t374) + ((((((((-t3018 * t2 - t2250) + t420_tmp) + t423) - t435) + t442) *
               t114 + t450) * 2.0 * t290 * t940 + 2.0 * t3229) - 2.0 * t179) *
    t38) + 2.0 * t3866 * t1170) + (((((-t457 + t3024) + t471) + t2284) + t475) *
    t114 - t517) * (2.0 * t290) * t940) - t3875) * t241 / 2.0 +
    ((((((((((((((((((((((((((((t3466 * t38 + t1257) - t1277) + t1281) + t1290)
    + t1292) + t1296) - t1297) - t1298) + t2358) + t3469) * t346 + -t2139) + 8.0
    * t1163) + ((4.0 * t1213 + 4.0 * t680) - 4.0 * t677) * t38) - 4.0 * t1214) -
    4.0 * t708) + t706) * t105 + ((q__p[3] * t346 + t10) - q__p[1]) * 2.0 * t589
    * t106) + 2.0 * t3486 * t267) + (((t3491 * t38 + t1304) + t1334) + t3494) *
    t346) - t2147) + ((4.0 * t1232 * t1640 + 4.0 * t738) + 4.0 * t740) * t38) +
           4.0 * t3503 * t2492) + 4.0 * t3506 * t440) - 2.0 * t753) * t12 +
        (-t2154 - t2162) * t106) + (-2.0 * t940 * t1826 + t2205) * t105) - 2.0 *
      t3538 * (t940 + 1.0) * t2217) + ((((((((((tmpreturn_tmp_r + t3545) + t101)
    + t245) + t264) + t265) + t28) - t283) - t284) + t32) + t40) * 2.0 * t940) *
    t288 / 2.0) + ((((((((((((((((((((((((((4.0 * t912 + t362) - t3910) * t290 +
    t3908) - t1258) - t70) * t38 + (((((-t3903 - t2248) + t321) - t325) + t326)
    + t327) * t39) - 2.0 * t3918 * t940) + ((4.0 * t919 - t408) - 2.0 * t921) *
    t290) + t1277) - 2.0 * t2255 * param->s__l7y * t323_tmp) - 2.0 * t2255 *
    param->s__l7x * t54) + t3934) + t3938) + t3940) - t3941) * t346 + -t2139) +
    (((((((((((((t1476 * q__p[4] + t1091) + t2237) * param->m__l7 * t697 +
    ((-t3947 / 2.0 - t3950) - t3951)) - t3956) - t171 * t1089 / 2.0) * t38 +
    ((-t3944 + t1689) - t542) * t39) + t340 / 2.0) + t3965) - t2400 * t323_tmp /
    2.0) + t214 * t1089 * t42 / 2.0) + t2399 * t54 / 2.0) + t1121 / 2.0) +
    param->m__l5 * t1099 * param->s__l5x / 2.0) * 4.0 * t440) * t105 +
    ((((((((4.0 * t3883 + 4.0 * t1457) + 4.0 * t1458) * t38 + -t3881) - 4.0 *
    t2038) - t41) - t3891) * t346 + 2.0 * t1567 * t267) - 2.0 * t3896 * t440) *
    t106) - 2.0 * q__p[1] * t1216 * t267) + ((((((((((((((((((t2 * t2123 - t4000)
    - t717) - 2.0 * t1222) - 4.0 * t932) + 4.0 * t937) * t290 + -2.0 * t3993 *
    t940) + (tmpreturn_tmp_g + t1489) * 2.0 * t114) * t38 + -8.0 * t1596 * t1971)
    - 2.0 * t4024 * q__p[0] * t940) + ((((tmpreturn_tmp_l * t2115 * t2 + (4.0 *
    t59 + t4033)) + ((2.0 * t2646 + 2.0 * t974) + 2.0 * t2259) * t42) - t4044) -
    2.0 * t980) * t290) - t4048) + ((((tmpreturn_tmp_1 - 2.0 * t2265) - t806) *
    t42 + (-t457 + t762)) - t1541) * t114) + t1017) - t758) - t4068) - t4072) +
    (((((((((((((-2.0 * t4073 - 2.0 * t3093) + param->I__l4xx) - param->I__l4yy)
    - param->I__l4zz) - param->I__l5xx) + param->I__l5yy) - param->I__l5zz) -
    param->I__l6xx) - param->I__l6yy) + param->I__l6zz) + param->I__l7xx) -
    param->I__l7yy) - param->I__l7zz) * q__p[3]) - 2.0 * t4078) * t346) + t2147)
                       + ((((((tmpreturn_tmp_0 + t4087) + t2265) + t201) * 2.0 *
    t440 * t290 + -2.0 * t4082 * t440 * t49) - (((t323_tmp * t2168 + t2646) +
    t2259) + t974) * (2.0 * t114) * t440) - t741) * t38) - (((tmpreturn_tmp_n +
    t897) + t896) - t751_tmp) * (2.0 * t440) * t49) - (((((((-t2135 * t42 + t189)
    * t2 + t182) + ((-t4015 - t420_tmp) - t1489) * t42) + t4110 * param->m__l7)
    + t4113 * param->m__l6) + t4116) - t1747) * 2.0 * t440 * t290) +
                    (((((((tmpreturn_tmp_m * t1089 + t4121) * t2 + t3592) +
    ((-2.0 * t946 - 2.0 * t948) - 2.0 * t1222) * t42) + t126 * t1089 * t54) -
                       2.0 * t78 * t1089 * param->m__l6) - 2.0 * t259 * t1099) *
                     t114 - 2.0 * q__p[2] * -t898) * t440) - (((((((((((((-t1534
    - t491) + t508) - t878) + t880) + t824) + t1663) + t413) + t886) - t871) +
    t3328) + t3331) + t108) + (((((((((((t505 + t890) - t784) + t3437) + t3438)
    + t3323) + t3324) + t3325) - t3326) + t3327) + t3329) - t3330)) * 2.0 *
                   q__p[1]) * t12 / 2.0) + (-t2154 + t2162) * t106 / 2.0) +
    ((((((4.0 * t2093 * t1154 * t2121 + t2205) + (t115 - t529) * 2.0 * t940 *
         t39) + ((-2.0 * t248 * t514 + (t1035 - t175) * t940) + t253) * t38) -
       2.0 * t1260 * t261 * t1170) + (t1079 + t222) * t940) + t512) * t105 / 2.0)
                        + 2.0 * t139 * t4186 * (t940 - 1.0) * t267) + (t940 +
    1.0) * t4191 * t2217) + 2.0 * t639 * (t940 + 1.0) * t2383 * t2469) + (((((((
    -t229 - t4204) + t4207) + t1423) + t230) + t1424) * t940 + 2.0 * t732 *
    t2097 * t1170) - t1736) * t38 / 2.0) - t4216 * t1170) + ((((((-t264 - t265)
    + t4220) + t4222) + t283) - t102) + t284) * t940 / 2.0) + t4216;
  t4227 = -t110 * t39;
  t4229 = (((((t173 * t38 + t117) - t118) - t119) + t216) - t219) + t4227;
  t1600 = t4229 * t105;
  t4231 = ((t1600 + t1233) + t622) - t751_tmp;
  t1616 = ((((((((((2.0 * t105 * t114 * t386_tmp + t2031) + t725) + t2052) +
                 t484) + t489) + t491) + t496) + t504) - t505) + t586) * q__p[0];
  t4243 = t290 * t1170;
  t4246 = t290 * t106;
  t2205 = t614 * t12;
  t362 = 2.0 * t2205;
  t416 = t732 * t3882;
  t2892 = t120 * t12;
  t423 = t433 * t2892;
  t2400 = 4.0 * t423;
  t4266 = t173 * t12;
  t4273 = (((((((((((((((t1195 - t489) - t491) + t1197) + t1199) + t505) + t508)
                   - param->I__l7yy) + t1202) + param->I__l7xx) + t1204) +
               param->I__l4xx) - param->I__l4yy) + param->I__l5yy) -
            param->I__l5zz) - param->I__l6xx) + param->I__l6zz;
  t1639 = q__p[0] * t4231;
  t189 = q__p[1] * t12;
  t633 = t290 * t386_tmp;
  t4291 = t433 * t42;
  t741 = t639 * t12;
  t4297 = t693 * t114;
  t245 = t303 * t12;
  t2347 = t338 * t245;
  t2598 = t732 * t226;
  t471 = t290 * t12;
  t4320 = 2.0 * t2971;
  t626 = t330 * t303;
  t871 = t626 + t2973;
  t4323 = t871 * t38;
  t4324 = t330 * t315;
  t4327 = t785 / 2.0;
  t1091 = t1232 * t1038;
  t2469 = t1091 - t617;
  t4330 = t2469 * t38;
  t4331 = t918 * t598;
  t4332 = t1546 * t2;
  t1826 = t196 * t4332;
  t4335 = t1038 * t751_tmp;
  t753 = ((((((((((((t1197 + t1199) + t505) + t508) - param->I__l7yy) + t1202) +
                param->I__l7xx) + t1204) + param->I__l4xx) - param->I__l4yy) +
            param->I__l5yy) - param->I__l5zz) - param->I__l6xx) + param->I__l6zz;
  t1971 = t753 * q__p[2];
  t738 = t360 * t39;
  t4345 = 2.0 * t738;
  t4346 = t550 * t38;
  t4349 = t440 * t1170;
  t708 = t386_tmp * q__p[1];
  t4354 = 4.0 * t708 * t106;
  t4355 = t1260 * t2892;
  t4357 = 2.0 * t3115;
  t4360 = t1260 * t4266;
  t4362 = 4.0 * t1189;
  t4365 = t500 * t471;
  t4370 = t1232 * t290;
  t4372 = t2910 / 4.0 + t4370;
  t2389 = 2.0 * t676;
  t4379 = t877 * t290;
  t4380 = -t168_tmp * param->m__l7;
  t4381 = -t168_tmp * param->m__l6;
  t4382 = (((((t851 + t1133) + t4380) + t4381) - t566) - t856) - t506;
  t2973 = t4382 * t695;
  t4384 = t2973 / 4.0;
  t4395 = 2.0 * t3040;
  t4407 = t1014 * t1038;
  t937 = -t4407 + t679;
  t4409 = 4.0 * t937;
  t4411 = ((t992 + t995) + t562) - t996;
  t3823 = t4411 * t114;
  t4413 = 2.0 * t227;
  t1567 = t991 * t226;
  t992 = 2.0 * t1567;
  t1089 = t315 * t440;
  t4421 = t433 * t1089;
  t4425 = (((((t265 + t1003) + t1004) - t29) + t1005) - t33) - t284;
  t4426 = t4425 * t114;
  t4427 = 2.0 * t262;
  t2163 = t732 * t1012;
  t1003 = 4.0 * t2163;
  t1004 = t532 * t114;
  t1099 = t740 * t440;
  t4444 = t1004 + t1099;
  t4445 = 4.0 * t4444;
  t4447 = 4.0 * t2923;
  t4449 = 2.0 * t147 - 2.0 * t1709;
  t4452 = 2.0 * t1120 * t1137;
  t1216 = t537 * t114;
  t4458 = 4.0 * t1216;
  t4459 = q__p[1] * t14;
  t2540 = t440 * t3;
  t1222 = t4459 * t2540;
  t147 = param->s__l7x * q__p[1];
  t4464 = t147 * param->m__l7;
  t1489 = t4464 * t486 * t440 * t2;
  t2923 = t1038 * t490;
  t3040 = 4.0 * t2923;
  t2031 = t753 * q__p[1] * t440;
  t2971 = q__p[2] * param->s__l4y * t281;
  t4476 = 4.0 * t2971;
  t680 = t1484 + t52;
  t2385 = param->m__l7 * t680;
  t4494 = 2.0 * q__p[4] * t69 - 2.0 * t1738;
  t4496 = 2.0 * t1747;
  t4497 = 2.0 * t2956;
  t4503 = tmpreturn_tmp_4 - 2.0 * t79;
  t1503 = t12 * t106;
  t4517 = t3198 + t1014;
  t2893 = q__p[0] * t4517;
  t69 = t614 * t290;
  t995 = 2.0 * t69;
  t4526 = t214 * t42 - t217;
  t4528 = t124 * t4526 / 2.0;
  t4533 = t918 * t290;
  t996 = 2.0 * t4533;
  t4537 = t799 * t12;
  t4538 = 2.0 * t4537;
  t4539 = 4.0 * t3397;
  t4540 = -t4538 - t4539;
  t1747 = t4540 * t39;
  t4550 = t780 * t290;
  t2399 = t12 * q__p[2];
  t1546 = -4.0 * t788;
  t2189 = t991 * t3882;
  t4564 = 4.0 * t791;
  t4572 = 2.0 * t805 * t291;
  t788 = t1038 * t120;
  t486 = 4.0 * t788;
  t1709 = 4.0 * t2137;
  t4583 = 2.0 * t2135;
  t2547 = 2.0 * t4015;
  t3024 = 2.0 * t1733;
  t4589 = 4.0 * t626;
  t4594 = 2.0 * t1714;
  t4599 = 4.0 * t4324;
  t4607 = t12 * t822;
  t4608 = t543 * t39;
  t753 = 2.0 * t335;
  t4613 = (t501 + t753) * t290;
  t4614 = 2.0 * t1091;
  t740 = 2.0 * t2189;
  t4620 = t2385 * t1262;
  t4623 = t18 * t680 * t16;
  t4626 = -t1739 * param->m__l6;
  t4629 = 2.0 * t1664;
  t4630 = 2.0 * t1666;
  t4631 = 2.0 * t1667;
  t4632 = 2.0 * t1668;
  t4635 = 2.0 * t4331;
  t2554 = t5 * q__p[2];
  t1667 = t109 * param->m__l7;
  t1668 = 4.0 * t2554 * t1667;
  t4640 = 2.0 * t4335;
  t4641 = t2129 * param->m__l6;
  t4505 = t1270 + t4641;
  t4642 = (((((((((((((t4505 + t4073) + t3093) - t3329) + t3330) + t3331) +
                  t1663) - t413) + t1534) + t878) + t880) - t886) - t890) + t784)
    + t824;
  t4653 = t628 * q__p[1];
  t4657 = 2.0 * t542 * t39;
  t4658 = t937 * t38;
  t4661 = t1038 * t586;
  t4670 = t628 * t290;
  t4676 = t4526 * t695;
  t4679 = t291 * t39;
  t4681 = 2.0 * t2695 * t38;
  t1091 = t991 * t245;
  t791 = t12 * t440;
  t1257 = t200 * t791;
  t4693 = 4.0 * t1257;
  t1339 = 4.0 * t365;
  t1411 = t440 * t112;
  t1476 = t1411 * t12;
  t1739 = 8.0 * t2635;
  t1347 = 2.0 * t797;
  t4711 = -4.0 * t871;
  t871 = q__p[5] * t303;
  t4714 = 2.0 * t871;
  t1354 = t598 * t12;
  t1580 = ((tmpreturn_tmp_0 - t82) + t152) + t201;
  t937 = t1580 * t42;
  t1664 = 2.0 * t1091;
  t4733 = -4.0 * t2469;
  t4739 = 4.0 * t4331;
  t4742 = 4.0 * t4335;
  t2576 = -t114 * t2735;
  t4748 = 2.0 * t848;
  t4751 = t699 * t38;
  t4752 = (t4751 + t723) + t217;
  t797 = t791 * q__p[3];
  t4754 = -t797 + q__p[0];
  t2735 = q__p[6] * t2;
  t2190 = q__p[6] * t16;
  t4766 = t18 * t2190;
  t723 = t214 * q__p[5];
  t2645 = t4766 + t723;
  t4772_tmp = t114 * q__p[3];
  t4772 = ((param->m__l4 * param->s__l4x * q__p[3] + t4772_tmp * t2711) + t26 *
           t42 * t2735) + t42 * t2645;
  t4775 = t2713 * q__p[0];
  t4782 = t4082 * t38;
  t4783 = t2973 * t290;
  t2973 = t991 * t248 * t12;
  t4797 = t1346 * t114;
  t4800 = 2.0 * t679;
  t2162 = t261 * t440;
  t4807 = t1353 * t114;
  t4810 = 2.0 * t707;
  t3252 = t11 * t741;
  t1120 = 4.0 * t3252;
  t1346 = t1260 * t114;
  t1666 = 2.0 * t1283;
  t4824 = (((t2155 - t127) + t4447) + t1028) - t1666;
  t1004 *= 2.0;
  t4830 = t197 * t12;
  t4836 = 2.0 * t1216;
  t4842 = ((((((((((((((((t3437 + t3438) + t3324) + t3325) + t508) + t505) +
                     t3329) - t3330) + t3331) + t1663) + t413) - t1534) - t878)
              + t880) + t886) + t890) - t784) + t824;
  t4844 = q__p[1] * t4842 * t440;
  t4846 = 2.0 * t2971;
  t1005 = q__p[4] * t114;
  t4854 = t26 * t2735;
  t4855 = (t4854 + t4766) + t723;
  t4856 = t695 * t4855;
  t4857 = t4856 * t290;
  t4858 = t152 / 2.0;
  t4859 = (t1582 - t4858) - t2415;
  t4860 = t4859 * t114;
  t1353 = t50 * t42;
  t723 = t1353 + t45;
  t1582 = (-t170 + t151) - t259;
  t2250 = (t323_tmp * t723 + t171 * q__p[5] * t42) - q__p[4] * t1582;
  t4874 = t2250 * t695 * t290;
  t4875 = t5299 + t735;
  t4876 = t4875 * t114;
  t4880 = t12 * t670;
  t4888 = (t114 * q__p[4] * t699 - q__p[3] * t214) * t695 * t290;
  t4889 = param->l__4 * q__p[5];
  t4890 = q__p[5] * param->l__5;
  t2713 = (t4889 + t4890) + t240;
  t4893 = param->s__l6x * t2713 * param->m__l6;
  t1137 = q__p[0] * t214;
  t3294 = t214 * q__p[4];
  t2469 = ((-t18 * t2735 - t217 * q__p[4]) + t26 * t2190) + t42 * t3294;
  t4913 = (t114 * t2469 + q__p[3] * t4382) * t695 * t290;
  t4914 = t817 * param->s__l7y;
  t4918 = (t42 * t4914 + t432) * param->m__l7 * t2;
  t4920 = t2713 * param->s__l6y * param->m__l6;
  t4921 = (-t2311 + t276) - t4920;
  t4922 = t4921 * t42;
  tmpreturn_tmp_0 = t4494 * param->m__l6;
  tmpreturn_tmp_4 = t42 * (2.0 * t95);
  tmpreturn_tmp_v = (4.0 * t4324 + 4.0 * t955) * t290;
  tmpreturn_tmp_w = t290 * (4.0 * t4421 - 4.0 * t707);
  tmpreturn[21] = ((((((((((((((((((((((((((((((((((16.0 * t4355 - t4357) * t39
    + (8.0 * t4360 + t4362) * t38) - 8.0 * t4365) - 2.0 * t1081) * t105 + t4354)
    + (8.0 * t12 * q__p[0] * t4372 - t2389) * t38) + 8.0 * q__p[0] * (t4379 +
    t4384) * t12) - 2.0 * t1126) * t940 + ((((t105 * t1154 - t4345) - t4346) +
    t565) + t567) * (2.0 * q__p[0]) * t4349) - (((((((((((((-t4395 + t127) -
    t140) - t144) + t145) + t643) + t152) + t154) * t38 + (t545 + q__p[4]) *
    t112 * t39) + t960) + t653) + t657) + t659) + t735) * (2.0 * t12) * t106) +
    ((((((t290 * t4409 + t3823) + t4413) * t12 - t992) * t38 + (t671 / 2.0 +
    t665) * (8.0 * t12) * t39) + ((tmpreturn_tmp_w + t4426) + t4427) * t12) -
    2.0 * t3588 * t440) * t105) + (((-2.0 * t1038 * t291 - t2143) + t1603) * t12
    + t1003) * t39) + ((((((((param->m__l7 * t4449 + t290 * t4445) - t1028) +
    t127) - t2155) + t3235) - t4447) + t4452) * t12 + t3169) * t38) +
    (((((((((((((4.0 * t1222 + t4458) - 8.0 * t1489) - t3040) + 2.0 * t2031) -
    t4476) * t290 + t2170) + 2.0 * t429 * t2385 * t2) + (2.0 * t1484 * t77 - 2.0
    * t169_tmp * t2385) * t42) + (-2.0 * t1738 + 2.0 * t1740) * param->m__l7) +
    tmpreturn_tmp_0) - t4496) + t2185) + t4497) * t12) - t3185) * t241 +
    ((((((((((t628 * q__p[2] * t106 / 2.0 + t1616 * t940) + (((t4320 + t4323) -
    t4324) - t955) * t105) + t4327) + t4330) + t4331) - t3301) + 2.0 * t1826) +
    t3307) - t4335) - t1971 / 2.0) * (4.0 * t12) * t288) + (((((((((t38 * t4503
    + tmpreturn_tmp_4) + t2195) + t2198) * t106 + t1573) + t2101) - t312) + t521)
    - t314) + t523) * (2.0 * t1260 * t440) * t1170) + (((((((((((((((((((-t1128
    + t1195) - t489) - t491) + t1197) + t1199) + t505) + t508) - param->I__l7yy)
    + t1202) + param->I__l7xx) + t1204) + param->I__l4xx) - param->I__l4yy) +
    param->I__l5yy) - param->I__l5zz) - param->I__l6xx) + param->I__l6zz) * (2.0
    * q__p[0]) * t12 + ((((((-4.0 * t12 * t2893 + t995) * t38 + 4.0 * q__p[0] *
    (t4528 + t605) * t12) + t996) * t105 + -2.0 * t1101 * t1503) + t1747) + (4.0
    * t12 * t2983 - t509) * t38)) + 2.0 * t4550) * t940) + ((((t12 * t1546 + 4.0
    * t2189) * t38 + -2.0 * t2399 * t586) + (t4564 - t2231) * t12) - 4.0 * t1260
    * t1089) * t106) + (((((((((((t2 * t4583 - t2241) + t257) - t1709) + t2547)
    + t3024) * t290 - t4589) - t3203) * t12 + t3369) * t38 + ((t4572 - t486) *
    t12 - 2.0 * t1260 * t598 * t112) * t39) + ((((((tmpreturn_tmp_1 - t4594) -
    t806) * t42 + ((t2268 - t457) + t762)) - t1541) * t290 + t4599) + t956) *
    t12) - 2.0 * t1260 * t4297 * t440) * t105) - 2.0 * t4607 * t4608) + ((t4613
    - t4614) * t12 - t740) * t38) + ((((((((((((((2.0 * t4620 + 2.0 * t4623) -
    t3934) + t4626) + t3941) - t3940) * t114 - t4629) - t4630) - t4631) + t4632)
    * t290 - t4635) + t939) - t1668) + t4640) - 2.0 * t4642 * q__p[2]) * t12) -
    2.0 * t3866 * t197) * t346 / 2.0 + (((((((((((((((4.0 * t416 + -t362) * t38
    - 2.0 * t918 * t12) - 4.0 * t1260 * t605) * t105 + (-2.0 * t1616 * t4243 +
    2.0 * t1101 * t4246)) + (t2400 + t2692) * t39) + (2.0 * t4266 * t433 - t2707)
    * t38) - 2.0 * t780 * t12) - 2.0 * t1260 * t4273) * t241 + 4.0 * t139 *
    t4231 * (t940 - 1.0) * t288) - 2.0 * t1639 * t1170) + 4.0 * t189 * t633 *
    t106) + ((((-2.0 * t12 * t148 * t338 + t458) * t39 + (4.0 * t4291 * t741 +
    t2887) * t38) - 2.0 * t338 * t4297 * t12) - t2900) * t105) + (-2.0 * t2347 +
    2.0 * t2598) * t38) - 2.0 * t1126 * t471) + 2.0 * t3503) * t267 / 2.0) +
    ((((((((((((t4657 + t4658) + t4421) - t707) * t105 + (t1639 * t940 - t4653 *
    t592 / 2.0)) - t4661 / 2.0) + t4444 * t38) + t1216) + t1222) - 2.0 * t1489)
       - t2923) + t2031 / 2.0) - t2971) * 2.0 * t940 * t288) +
    (((((((((((((((((4.0 * t12 * t294 * t11 + t290 * t4711) - t2241) + t4714) *
    t38 + ((-2.0 * t732 * t1476 - t1739) + t1347) * t39) - 2.0 * t2223 * t1354)
    + tmpreturn_tmp_v) + t2268) - 2.0 * t937) * t105 + ((((((4.0 * t1091 + 4.0 *
    t1018) - 4.0 * t335) * t38 + -2.0 * t1586) - t4693) - 2.0 * t2230 * t290) +
    t1339) * t106) + (-2.0 * t482 - 2.0 * t823) * t39) + (((t290 * t4733 + t501)
    + t753) - t1664) * t38) - 2.0 * t3866 * t791) + (((((4.0 * t3301 + -t4739) -
    8.0 * t1826) - t1019) + t4742) + 2.0 * t1971) * t290) + t2576) + t4748) *
      t940 + ((((((((2.0 * t3611 + t2643) * t38 - 2.0 * t668) - t4676) * t105 +
                  t4670 * t106) + t4679) - t4681) + t3726) + t801) * (-2.0 *
    q__p[0]) * t1170) + (((t1108 * t12 * q__p[5] * t38 + t105 * t4752 * t4754) -
    t12 * t4772 * t440) + t4775) * (2.0 * t695)) * t241 / 2.0) - ((((t1600 +
    t4782) + t4783) + t622) - t751_tmp) * q__p[0] * t1170) +
                        ((((((((((((((((((t4797 - t4413) * t290 + 2.0 * t2973) -
    t4800) * t38 + (-4.0 * t1689 - 4.0 * t542) * t39) + 2.0 * t1260 * t2162 *
    t12) + (t4807 - t4427) * t290) + t4810) * t105 + (t2820 + t735) * (2.0 *
    t290) * t106) + ((t2145 * t290 + 2.0 * t2903) - t1120) * t39) + (((-2.0 *
    t12 * t1346 * t930 + t290 * t4824) - 4.0 * t1099) - t1004) * t38) + 2.0 *
    t3183 * t4830) - tmpreturn_tmp_5) - t4836) - 2.0 * t1222) + 4.0 * t4464 *
    t868 * t440 * t2) + t3040) - 2.0 * t4844) + t4846) * t940 / 2.0) + t1818 *
                       t12 * t592) + ((((t4857 - 2.0 * t4860) * t38 + t1005 *
    t586) + t4874) + t4876) * t791 * t105) - 2.0 * t4880 * t1569) +
                    (((((((-t4888 + t1806) + t2013) + t1141) + t239) - t46) -
                      t4893) * -2.0 * t440 * t12 + 2.0 * t1137 * t124) * t38 /
                    2.0) + (((((-t4913 - t4918) + t4922) + t28) + t32) - t101) *
                   t440 * t12) + q__p[0] * t4382 * t124;
  t4928 = t514 - q__p[0];
  t2223 = t4928 * t267;
  t1199 = t346 * q__p[1];
  t2230 = t1199 * t791;
  t1818 = t940 * t204;
  t4933 = (t2223 + t2230) + t1818;
  t3324 = t1178 * t267;
  t2231 = 4.0 * t1458;
  t2625 = ((((((((t1049_tmp + t199) + t203) + t1177) + param->I__l5xx) -
              param->I__l5yy) + param->I__l6yy) - param->I__l6zz) -
           param->I__l7xx) + param->I__l7zz;
  t3183 = t2625 * q__p[3];
  t3438 = 2.0 * t3183;
  t2692 = (t940 - 1.0) * t1178 * t2050;
  t3325 = t1178 * t12;
  t523 = t386_tmp * t440;
  t2735 = (-2.0 * t714 * t523 + t3325) * q__p[1];
  t1569 = (t940 + 1.0) * (t940 - 1.0);
  t1600 = t386_tmp * q__p[0];
  t2707_tmp = t1569 * t1600;
  t2707 = t2707_tmp * t267;
  t4971 = 2.0 * t523 * t12;
  t1616 = (t1178 * t714 + t4971) * q__p[1];
  t1586 = q__p[2] / 2.0 + t49;
  t1573 = t1586 * t290;
  t2820 = t225 * t940;
  t4982 = t639 * t2820;
  t2887 = t290 * t2625;
  t3169 = t2625 * q__p[2];
  t1639 = t3169 * t290;
  t4996 = -t296 - t304;
  t1826 = 2.0 * t3183 * t290;
  t1971 = t433 * t1411 * t39;
  t2189 = q__p[1] * t2625;
  t2190 = t2189 * t598;
  t523 = t114 * t204;
  t2713 = t523 * t586;
  t2191 = t2625 * t114;
  t1541 = t3169 * t114;
  t1740 = t114 * t12;
  t1089 = t708 * t1740;
  t1099 = t1018 - t335;
  t1216 = 4.0 * t1099;
  t5052 = t1038 * t248;
  t1222 = 2.0 * t5052;
  t5054 = 2.0 * t4920;
  t2050 = t2887 * t114;
  t3437 = t695 * t2711;
  t3198 = (t3437 / 2.0 + t2050) * q__p[0];
  t1489 = 2.0 * t1639 + t1339;
  t5067 = t918 * t197;
  t2923 = 2.0 * t5067;
  t2900 = (tmpreturn_tmp_6 + t618) * t26;
  t5071 = 4.0 * t2900;
  t2255 = (t239 - t46) - t4893;
  t2903 = 2.0 * t2255;
  t5076 = t2903 * t42;
  t5077 = 2.0 * t1863;
  t143 = -2.0 * t2057;
  t2254 = q__p[4] * param->l__4;
  t5082 = t2254 * t259;
  t5083 = 2.0 * t5082;
  t5085 = t99 * param->s__l5y * param->s__l5z;
  t5086 = 2.0 * t5085;
  t5101 = t965 - t966;
  t5103 = t18 * t5101 * t2;
  t5105 = param->m__l7 * t5101 * t169_tmp;
  t5118 = t1230 * q__p[1];
  t3120 = (t940 + 1.0) * t120;
  t2057 = t2643 / 4.0 + t3611;
  t5171 = t601 * t290;
  t5172 = 2.0 * t5171;
  t601_tmp = t2010 + t1648;
  t601 = (((t601_tmp + t608) + t613) + t618) * param->m__l7 * t697;
  t2101 = t668 - t2659 / 4.0;
  t2110 = -t1117 + t3183;
  t5191 = t2711 * t440;
  t5208 = (t344 + t593) * t2;
  t3040 = 4.0 * t342;
  t99 = t124 * t2711;
  t2031 = t99 / 2.0;
  t5226 = (t771 + t513) * t2;
  t5228 = -t2903 * t42;
  t5230 = -2.0 * t899 - 2.0 * t396;
  t5231 = t5230 * param->m__l6;
  t3323 = (t2191 + t99) * 2.0 * q__p[0];
  t2129 = t679 * t114;
  t2903 = 2.0 * t565 * t49;
  t2135 = t707 * t114;
  t2137 = t1038 * t565;
  t2139 = t1230 * t114;
  t2147 = (t2819 / 2.0 + t3882) * q__p[0];
  t5286 = 2.0 * t1326;
  t2152 = 2.0 * t1457;
  t2154 = (-t2842 / 2.0 + t3887) * q__p[0];
  t5299 = -2.0 * t2108;
  t5300 = t5299 * param->m__l7;
  t5301 = 2.0 * t2099;
  t5303 = ((t5300 + t5301) + t3235) * t42;
  t5304 = 2.0 * t1535;
  t5305 = 2.0 * t1629;
  t2108 = ((((((((((t398 + t503) + t401) - t1663) + t413) + t1534) + t878) -
              t880) + t886) + t890) + t784) - t824;
  t1535 = t2108 * q__p[3];
  t5310 = 2.0 * t1535;
  t4494 = (t1049_tmp + t1270) + t4641;
  t2217 = (((((((((t4494 + t3093) + t1663) - t413) + t1534) + t878) + t880) -
             t886) - t890) + t784) + t824;
  t2227 = t822 * t42;
  t396 = t17 - t22;
  t5344 = t396 * t2;
  t99 = t699 * t114;
  t5363 = t1048 * t99;
  t2483 = t2227 * t290;
  t5370 = -t2469 * t695 * t114;
  t2469 = 2.0 * t396 * t2;
  t5374 = (((t265 + t2469) + t29) + t33) - t284;
  t2237 = t5374 * t290;
  t2239 = 2.0 * t561;
  t396 = t42 * t940;
  t2385 = q__p[1] * t2108;
  t5398 = t2085 + t823;
  t2353 = t3437 * t114;
  t2354 = t2353 + t2887;
  t1629 = t124 * t99;
  t2359 = (((t1629 / 2.0 - t300) - t302) + t76) + t79;
  t5458 = t290 * -t3408 + t3203;
  t2414 = 4.0 * t296;
  t2485 = ((((t1629 - t300) - t302) + t76) + t79) * q__p[0];
  t1629 = t724 * t290 * t949;
  t2496 = t1629 / 2.0;
  t5479 = ((-t3430 * param->m__l7 - t3235) - t3432) * t42;
  t2145 = -t457 + t1187;
  t5480 = ((t2145 + t5479) + t573) + t1331;
  t5481 = t5480 * t290;
  t2641 = (((-t1629 + t312) + t313) + t314) * q__p[0];
  tmpreturn_tmp_1 = t42 * t943;
  tmpreturn_tmp_6 = -t1398 * t42;
  tmpreturn_tmp_y = t2255 * t42;
  tmpreturn_tmp_10 = (-t4564 - 2.0 * t3169) * t114;
  tmpreturn[28] = (((((((((((((((((((((((((((((((((((((((((((((t114 * t1216 +
    t1273) + t660) - t596) + t977) + t341) + 8.0 * t2453) + t1222) - t5054) *
    t38 + (((((-4.0 * t1462 - t2248) - t321) + t325) - t326) - t327) * t39) +
    4.0 * t3198 * t940) + t1489 * t114) + t2923) + t1281) + (t1284 - t5071) * t2)
    + t5076) - t5077) + t749) + t143 * param->m__l6) - t3941) - t5083) - t5086)
    - t720) * t12 + -8.0 * t11 * t386_tmp * t1569) * t346 + (2.0 * q__p[0] *
    (t940 - 1.0) * t2093 * t1154 + 8.0 * t1089) * t267) + ((((((2.0 * t1432 *
    t440 + 2.0 * t1213) - t678) * t38 + 4.0 * t1163) - 2.0 * t1214) + t706) -
    ((((-t5103 - t1447) + t5105) + t1121) + t1451) * 2.0 * t440) * t12) - ((((((
    -t1263 + t231) - t532) * t38 + -t1971) - t1271) + t2190) - t537) * (2.0 *
    t714)) * t241 + (((((((2.0 * t2149 * t294 + t383) + t912) * t38 + -t2713) +
    t2191 * t49) + t1541) + t919) * 2.0 * t940 + (((((((-t3573 + t231) - t532) *
    t38 + -t1971) - t3590) + t2190) - t537) * (2.0 * t12) * t346 + 2.0 * t2383 *
    t1178 * t139 * t267)) * t288) + (2.0 * t1178 * q__p[0] * (t940 + 1.0) *
    t2383 - 2.0 * t471 * t5118) * t267) + (((((((t3573 + t1015) - 2.0 * t4856) *
    t38 + -2.0 * t1971) + t3590) + 2.0 * t2190) - 2.0 * t2250 * t695) * t12 -
    ((((((t2472 * t4349 / 2.0 + t676 * t2238) - t2472 * t440 / 2.0) * t38 +
    (t940 - 1.0) * t3120 * t991 * t39) - t2665 * t514 / 2.0) - t704 * t2238) +
     t2665 * q__p[0] / 2.0) * (4.0 * t290)) * t346) + ((((((((((t3204 - 2.0 *
    t601) + t435) + t1578) - t1326) * 2.0 * t440 + ((-8.0 * t2057 * t440 * t49 -
    4.0 * t440 * t1030 * t114) - t5172)) * t38 + (-4.0 * t120 * t634 + 2.0 *
    t414 * t598) * t39) + 8.0 * t2101 * q__p[0] * t2492) - 2.0 * t2110 * t440 *
    t114) + (-2.0 * t5191 * t914 + 2.0 * t609) * t290) - t1368) * t12) + (((2.0 *
    t331 + 2.0 * t332) * t940 + 4.0 * t2032) - t297) * t39) + (((((((((-t341 +
    t5208) + t353) + t596) - t1273) + t5054) * t290 + -t1546 * t114) - t913) *
    t940 + -8.0 * t2036) + t3040) * t38) - (t2191 + t2031) * 4.0 * q__p[0] *
    t1170) + ((((((((((t767 + t5226) + t5228) + t888) - t749) + t5231) + t5083)
                 + t5086) + t720) * t290 + tmpreturn_tmp_10) - t920) * t940) +
    t3323) * t105 / 2.0 + ((((((((((((((((((8.0 * t3883 + 4.0 * t1457) + t2231) *
    t38 + -t3881) - 8.0 * t2038) - t41) + t3438) * t12 + 4.0 * t2692) * t346 +
    -4.0 * t189 * t3324) + 2.0 * t2735) * t241 + 4.0 * t4933 * t386_tmp * t288)
    + 4.0 * t2707) + 2.0 * t1616 * t346) + ((((((2.0 * t4982 + t1018) - t335) *
    t38 + -t1573 * t586) + t2887 * t49) + t1639 / 2.0) + t365) * 4.0 * t440 *
    t12) + t2644) + ((4.0 * t940 * t4996 + 4.0 * t179) - 8.0 * t3229) * t38) +
    8.0 * t3236) + (-t1826 + t317) * t940) - t206) * t106 / 2.0) + ((-2.0 *
    t2707 - ((((-4.0 * t360 * t1586 * t39 + ((-t3663 - t2129) + t1103) * t38) +
               t2903) + t2135) - t561) * 2.0 * t12 * t346) - ((((((t940 * t179 +
    t304) + t932) * t38 + t271) - t200 * t940) - t2137) - t316) * 2.0 * t940) *
    t288 / 2.0) + (((((((((((((((((-2.0 * t349 + t1041) - 4.0 * t601) + t1314) +
    2.0 * t1578) - t5286) * t114 + -4.0 * t2147 * t940) - t2152) - t2231) * t38
    + (-4.0 * t114 * t120 * t1990 + t1302) * t39) + 4.0 * t2154 * t940) +
    ((((((2.0 * t358 + t457) - t1187) + t5303) - t573) - t5304) - t5305) * t114)
                        + t1117) + t5310) * t12 - 2.0 * t2692) * t346 + (2.0 *
    q__p[0] * t290 * t1569 * t2139 + 2.0 * t1178 * t189) * t267) +
                    ((((((((tmpreturn_tmp_1 + t1395) * t2 + -t1044) +
    tmpreturn_tmp_6) + t1401) - t1403) + t1406) * (2.0 * t440) * t114 +
                      (((((t1263 + t1374) + t972) - t974) + t976) * 2.0 * t440 *
                       t114 * t38 + 2.0 * t2162 * t2149)) - 2.0 * t2217 * q__p[1])
                    * t12) + (((((((((((((((-2.0 * t1755 - t1085) - t9) + t25) -
    t29) - t33) + t35) * t39 + (((-t3947 * t543 - t2227) - t552) + t987) * t38)
    + t2119 * t2149) + t2119 * t330) - t999) + t9) + t5344) + t28) + t32) - t35)
                   * 2.0 * t940) * t241 / 2.0) + (2.0 * t114 * t12 * t1154 *
    t338 - 2.0 * t2707_tmp) * t267 / 2.0) + (((((((((-2.0 * t1764 - 2.0 * t5363)
    - 2.0 * t2483) - 2.0 * t1103) * t38 + (-4.0 * t1763 - 4.0 * t1337) * t39) +
    t2903) - 2.0 * t5370) + t2237) + t2239) * t12 - ((((((t1170 * t1308 * t598 -
    t1308 * t598) + 2.0 * t396 * t595) * t38 + -t729 * t374) + t2162 * t1757) -
    t2385 * t940) - t2162 * t732) * 2.0 * t290) * t346 / 2.0) + (((((((((((((2.0
    * t2900 + t375) * t2 + t373) - tmpreturn_tmp_y) + t1863) - t1164) + t2304) +
    t1492) + t5082) + t5085) + t1175) * 2.0 * t440 + (2.0 * t1080 * q__p[3] *
    t724 - 2.0 * t918) * t290) * t114 + ((((((t1799 + t4920) * 2.0 * t440 + (2.0
    * t1108 * t914 - 2.0 * t614) * t290) * t114 + -4.0 * t3355 * t1640) + 2.0 *
    t832) * t38 + 2.0 * t5398 * t440 * t39) - 2.0 * t2354 * q__p[0] * t2492)) -
    (t290 * q__p[2] * t2217 + t365) * 2.0 * t440) * t12 / 2.0) - (-2.0 * t114 *
    t3193 + q__p[3] * t291) * t940 * t39) + ((((t114 * t5458 + t453) + t2414) *
    t940 + 4.0 * t2359 * q__p[0] * t1170) - 2.0 * t2485) * t38 / 2.0) -
                    (((-t2496 + t312) + t313) + t314) * 2.0 * q__p[0] * t1170) +
                   (((t5481 - t956) * t114 - 2.0 * t1535 * t290) - t906) * t940 /
                   2.0) + t2641;
  t5491 = t4933 * t288;
  t5492 = t12 * t1586;
  t375 = t150 * t440;
  t5496 = t5492 * t346 - t375 / 2.0;
  t1085 = 2.0 * t514;
  t1108 = t940 * q__p[2];
  t5502 = ((((((2.0 * t241 * t290 * t5496 + q__p[0]) - t797) + t2223) + t2230) +
            t5491) - t1085) - t1108;
  t832 = t1049 * t1170;
  t601 = t1260 * t832;
  t3208 = 4.0 * t601;
  t1535 = t1260 * t1049;
  t2887 = t2163 * t1170;
  t1629 = 8.0 * t2887;
  t1640 = t1049 * t290;
  t987 = t1038 * t1640;
  t5524 = 2.0 * t57 * t3;
  t5525 = q__p[3] * t20_tmp;
  t5526 = t5525 * t114;
  t2661 = 4.0 * t18 * (-t5526 + t187) * t2;
  t1755 = t141_tmp * q__p[3];
  t1757 = t1755 * t114;
  t2662 = 4.0 * t1757;
  t678 = q__p[4] * t1226;
  t2715 = 2.0 * t678;
  t3193 = (((-4.0 * t987 - t5524) + t2661) + t2662) + t2715;
  t3204 = 8.0 * t2163;
  t3203 = t551 * t1049 * t940;
  t5546 = q__p[0] * t1049;
  t5547 = t5546 * t12;
  t3430 = -4.0 * t5547 + 4.0 * t3397;
  t2223 = 2.0 * t2399 * t1049;
  t2230 = 8.0 * t3252;
  t2880 = ((t5524 - t2661) - t2662) - t2715;
  t2231 = t2880 * t290;
  t5558 = t1038 * t1049;
  t2692 = 2.0 * t5558;
  t2707 = 4.0 * t1740 * t290 * t542 * t440;
  t3230 = t4933 * t120 * t288;
  t5571 = 8.0 * t4355;
  t5572 = t433 * t1049;
  t2900 = 4.0 * t471 * t542;
  t1457 = t440 * t1049;
  t724 = t1457 * t12;
  t5584 = t114 * t14;
  t5585 = q__p[3] * t3;
  t1432 = 2.0 * t5584 * t5585;
  t57 = q__p[3] * param->s__l7y;
  t25 = t114 * t16;
  t1799 = t57 * t25;
  t2093 = (t1799 + t85) * 4.0 * param->s__l7x * t323_tmp;
  t2939 = t1226 * q__p[3];
  t2383 = 2.0 * t2939 * t114;
  t5598 = 4.0 * t142;
  t3169 = ((((-4.0 * t732 * t724 + t1644) - t1432) + t2093) + t2383) - t5598;
  t3183 = 2.0 * t330 * t724;
  t3185 = q__p[1] * t1049;
  t2248 = t3185 * t12;
  t3301 = 4.0 * t543 * t2248;
  t3307 = 8.0 * t1601;
  t2453 = t1457 * t1170;
  t3369 = 4.0 * t1346 * t2453;
  t2856 = ((-t1432 + t2093) + t2383) - t5598;
  t5616 = t2856 * t290;
  t1163 = 8.0 * t788;
  t2085 = t991 * t1049;
  t1213 = 4.0 * t543 * t2085;
  t1214 = 4.0 * t875;
  t5626 = t543 * t3185;
  t5628 = t5584 * q__p[4] * t3;
  t5629 = t45 * t25;
  t5633_tmp = 2.0 * t18 * (t5629 - t5525);
  t5633 = t5633_tmp * t2;
  t5635 = 2.0 * t1755;
  t1263 = 2.0 * t5626 - (((t114 * t678 - t5628) + t5633) + t5635) * 2.0 * t440;
  t1644 = t226 * t267;
  t724 = t1308 * t4349;
  t1271 = 4.0 * t724;
  t678 = t446 * q__p[0];
  t999 = t12 * t1049;
  t1578 = 4.0 * t678 * t999 * t940;
  t5658 = t1049 * t42;
  t2434 = t551 * t5658;
  t1326 = 2.0 * t2434 - 2.0 * t227;
  t1368 = 4.0 * t1567;
  t1308 = t12 * t226;
  t6819 = t940 * t446;
  t1763 = (t6819 * t1457 + t1308) * q__p[1];
  t1764 = (t940 * t248 - t510 * t999) * q__p[1];
  t2913 = t225 * t832;
  t1863 = 4.0 * t2913;
  t2304 = q__p[2] * t1049;
  t2644 = t2304 * t42;
  t5690 = t248 * q__p[3];
  t5691 = 2.0 * t5690;
  t3229 = (-4.0 * t2973 - 2.0 * t2644) + t5691;
  t5694 = t1049 * q__p[3];
  t2903 = t5694 * t42;
  t3236 = 2.0 * t440 * (t2903 + t533) * t12;
  t2032 = 2.0 * t225 * t1049;
  t3210 = t1127 * t114;
  t5710_tmp = 4.0 * -t120;
  t5710 = t5710_tmp * t42 + t215;
  t2912 = q__p[0] * t5710;
  t2036 = 4.0 * t787;
  t832 = t1038 * param->s__l7y;
  t787 = t114 * param->m__l7;
  t3018 = t832 * t787 * t116;
  t3252 = t1038 * t95 * t114;
  t2518 = t215 * q__p[2];
  t2038 = (((2.0 * t940 * t2912 - t2036) + t3018) + t3252) + t2518;
  t5726 = t2598 * t940;
  t5727 = 4.0 * t2853;
  t912 = t330 * param->s__l7y;
  t5729 = t912 * t311;
  t5731 = q__p[2] * t95 * t114;
  t2255 = t215 * t1038;
  t2853 = (((t5726 + t5727) + t5729) + t5731) - t2255;
  t1462 = 2.0 * t1260 * t5710 * t1170;
  t1226 = t114 * t42;
  t2248 = (-2.0 * t1260 * t5710 + 4.0 * t2248 * t1226) + t1462;
  t5748 = t1226 * q__p[0];
  t2453 *= 4.0 * t5748;
  t1567 = t2910 / 2.0 + t4370;
  t1739 = (((-t1739 + t1432) - t2093) - t2383) + t5598;
  t5760 = (-t5729 - t5731) + t2255;
  t5761 = 2.0 * t5760;
  t5762 = t5761 * t290;
  t5763 = -t146 + t1620;
  t5764 = 2.0 * t5763;
  t2259 = q__p[4] * param->l__5;
  t2971 = ((t1510 - t2254) - t2259) + t439;
  t5769 = t2971 * param->s__l6y * param->m__l6;
  t2085 *= 4.0 * t1226;
  t2093 = 8.0 * t1018;
  t5778 = (t3018 + t3252) + t2518;
  t5779 = 2.0 * t5778;
  t2383 = t5779 * t290;
  t2099 = t1226 * t3185;
  t2347 = (-2.0 * t1170 * t732 * t226 - 2.0 * t2347) + 2.0 * t2598;
  t5796 = t197 * t1170;
  t2449 = 2.0 * t179 * t5796;
  t2973 = -2.0 * t1049 * t543 * t638 + 2.0 * t12 * t2912;
  t5805 = 2.0 * t786;
  t3018 *= 2.0;
  t3252 *= 2.0;
  t5809 = 2.0 * t3294 * t695;
  t2162 = (t2911 / 2.0 + t1232) * (4.0 * q__p[0]) * t1170;
  t1620 = t543 * t42;
  t2163 = 4.0 * t1620 * t991 * t999;
  t5826 = 2.0 * t146 - 2.0 * t465;
  t5828 = (-t2254 - t2259) + t439;
  t5831 = 2.0 * t5828 * param->s__l6y * param->m__l6;
  t5833 = (((((param->m__l7 * t5826 - t1029) - t127) - t806) + t600) - t5831) *
    t290;
  t2254 = 2.0 * t2255;
  t2911 = t114 * t1049;
  t5842 = t2910 * t295;
  t5843 = t20_tmp * t114;
  t2255 = t599 * t114;
  t2259 = q__p[0] * t4082;
  t2265 = 2.0 * t2259;
  t2266 = t168_tmp * t699;
  t5860 = t5658 + t2266;
  t5864 = t179 * t2238;
  t2279 = t1038 * t5658;
  t5867 = t3 * t114;
  t5868 = t5867 * param->m__l7;
  t5869 = t2554 * t5868;
  t2598 = q__p[2] * t16;
  t146 = t440 * param->m__l7;
  t5874 = t147 * t146 * t168_tmp;
  t5875 = -t5584 * t2598 - t5874;
  t2280 = q__p[2] * t80 * t114;
  t7784 = t1038 * t168_tmp;
  t2289 = t7784 * -t171;
  t3294 = t5860 * q__p[0];
  t2294 = t3294 * t940;
  t999 = t147 * param->s__l7y;
  t2303 = t999 * t2540 * t787;
  t2315 = 2.0 * t2303;
  t465 = t16 * t440;
  t2316 = t465 * t4459 * t114;
  t2319 = t196 * t854;
  t2348 = -t2316 + t2319;
  t5899 = t2348 * t2;
  t2335 = t80 * t440 * t433;
  t2351 = t1022 * -t171;
  t5908 = t543 * t1170;
  t2352 = t179 * t5908;
  t2364 = 2.0 * t724;
  t724 = q__p[0] * t12;
  t2369 = t290 * t5860 * t724;
  t2434 *= 2.0;
  t2444 = 4.0 * t2303;
  t5922 = 2.0 * t2348;
  t2448 = t5922 * t2;
  t2452 = 2.0 * t2335;
  t2457 = 2.0 * t2351;
  t5927 = (((-t2444 + t2448) + t2452) - t2457) * t290;
  t5928 = q__p[5] * t114;
  t5935 = t3611 + t2643;
  t2473 = 2.0 * q__p[0] * t5935 * t1170;
  t2843 = t5710 * t440;
  t2475 = 2.0 * t732 * t2843 * t12;
  t2506 = 2.0 * t987;
  t2661 = (((-t2506 - t5524) + t2661) + t2662) + t2715;
  t5946 = 4.0 * t5869;
  t5947 = 2.0 * t5875;
  t5948 = t5947 * t2;
  t5949 = 2.0 * t2280;
  t5950 = 2.0 * t2289;
  t2662 = (((-t5946 + t5948) + t5949) + t5950) * t290;
  t5956 = 4.0 * t330 * t685;
  t5957 = t31 * t1080;
  t987 = q__p[1] * param->s__l7y;
  t5959 = t987 * t20_tmp;
  t2715 = -t171 * t440;
  t5973 = q__p[0] * t695;
  t2716 = 2.0 * t5973 * t699;
  t2808 = (t2266 / 2.0 + t5658) * q__p[0];
  t2748 = 4.0 * t2808 * t1170;
  t2794 = 2.0 * t543 * t5710 * q__p[1] * t12;
  t2808 *= 4.0;
  t2843 = 2.0 * t1346 * t2843 * t1170;
  t2864 = t3197 + t1014;
  t2880 = -t2880 * t290;
  t2881 = 4.0 * t5558;
  t387 = 2.0 * -t1055;
  t2912 = 2.0 * t543 * t2912 * t440;
  t2913 *= 2.0;
  t2914 = t114 * t2910 + t248;
  t2938 = t2914 * q__p[0] * t791;
  t6026 = q__p[5] * t290 * t114;
  t6027 = -t6026 + q__p[2];
  t6033 = t85 * t114;
  t6034 = t57 * t16;
  t6035 = t6033 + t6034;
  t6039 = t142 * t114;
  t6040 = 2.0 * t6039;
  t2939_tmp = (-t1544 + 2.0 * t18 * t6035 * t2) - t6040;
  t2939 = (t2939_tmp + t2939) * 2.0 * t440 + t4539;
  t3197 = (t2646 + t974) + t1023;
  t6055 = q__p[6] * t114;
  t3292 = t6055 * t108;
  t6057 = t1583 * param->s__l7y;
  t1583 = t31 * t168_tmp;
  t6060 = t1583 / 2.0;
  t3310 = t376 * -t171;
  t3314 = 2.0 * t3294;
  t6353 = t179 * t510;
  t6083 = t6353 * t1170;
  t3319 = 4.0 * t6083;
  t3372 = 4.0 * t1260 * t2892 * t940;
  t1398 = t335 * t42;
  t3402 = -2.0 * t1398 + 2.0 * t665;
  t3425 = 4.0 * t6353;
  t6099 = (t2492 * t639 + t42 * t245) * q__p[1];
  t6109 = (t3882 * t396 - t2892 * t440) * q__p[1];
  t6113 = t510 * t12;
  t6119 = (-4.0 * t290 * t179 * t6113 + 2.0 * t446 * t335) - 2.0 * t542;
  t6125 = (t359 * t3882 + t122) * 2.0 * t440 * t12;
  t6126 = 2.0 * t1601;
  t1601 = (t940 + 1.0) * t114;
  t2892 = t2266 * t42;
  t6137 = (((((((t2892 + t866) + t111) - t67) + t1173) + param->I__l6xx) -
            param->I__l6yy) + param->I__l7yy) - param->I__l7zz;
  t67 = q__p[0] * t6137;
  t6139 = t67 * t940;
  t6148 = 2.0 * t5869;
  t6149_tmp = t5875 * t2;
  t6152 = ((((-t6148 + t6149_tmp) + t2280) + t2289) * t42 + t179 * t1226 * t940)
    - t5558;
  t6159 = 2.0 * t1260 * t6137 * t1170;
  t6162 = (-2.0 * t1260 * t6137 + t2400) + t6159;
  t6164 = 4.0 * t2887;
  t6175 = (((-t5947 * t2 + t5946) - t5949) - t5950) * t290;
  t2646 = -t1619 * t18 - t183;
  t2887 = t26 * t1619 * t16;
  t5558 = t2971 * param->m__l6 * param->s__l6x;
  t2971 = (-t5526 / 2.0 + t187) * (4.0 * t18) * t2;
  t6193 = 2.0 * t1757;
  t6194 = param->m__l6 * t68;
  t5526 = ((((((t60 + t6194) - t878) + t880) + t886) + t890) - t784) + t824;
  t5947 = q__p[4] * t5526;
  t6197 = 2.0 * t5947;
  t68 = t226 * t440;
  t6205 = 2.0 * t225 * t68 * t12;
  t6209 = 2.0 * t551 * t1049;
  t6222 = ((t114 * t179 - t2497 * t179) + t1308 * t338) * t42;
  t6227 = 2.0 * t678 * t68 * t1170;
  t1055 = 2.0 * t12 * t67 - 2.0 * t3397;
  t6240 = q__p[2] * t688;
  t6244 = t42 * t226;
  t6245 = t6244 * t440;
  t6247 = 2.0 * t1260 * t6245;
  t1619 = t42 * t1170;
  t6252 = 4.0 * t2893 * t1619;
  t6253 = t128 * t854;
  t6259 = 2.0 * t45 * t854 * t16;
  t6261 = 2.0 * t77 * t5828;
  t6263 = (((((2.0 * t183 + 2.0 * t6253) * t2 + t1709) - t6259) - t257) - t6261)
    * t290;
  t866 = t6268 + t60;
  t6268 = ((((((t866 + t6194) - t878) + t880) + t886) + t890) - t784) + t824;
  t6273 = t699 * t290;
  t6274 = t914 * t6273;
  t6277 = 2.0 * t5 * q__p[3] * t5868;
  t6278 = t301 * t805;
  t6279 = q__p[6] * param->m__l7;
  t67 = param->s__l7y * t168_tmp;
  t6281 = t6279 * t67;
  t6284 = t80 * q__p[3];
  t6285 = t6284 * t114;
  t6290 = t6350 * q__p[6];
  t6296 = 2.0 * t225 * t2864;
  t6300 = ((t216 + t117) - t118) - t119;
  t6301 = t6300 * q__p[0];
  t6306 = t732 * t6244 * t940;
  t6309 = -t5760 * t42 / 2.0;
  t6310 = t788 / 2.0;
  t6315 = t6301 * t940;
  t6316 = t5778 * t42;
  t6328 = ((t1170 * t732 * t248 + t12 * t676) - t732 * t248) * t42;
  t6331 = 2.0 * t6083;
  t6334 = 4.0 * t290 * t6300 * t724;
  t6335 = t114 * t688;
  t6341 = -t5779 * t290;
  t68 = t168_tmp * t114;
  t6347 = 2.0 * t665;
  t2893 = t6350 * t114;
  t6349 = t2893 * q__p[6];
  t6350 = 2.0 * t6349;
  t6353 *= 2.0;
  t6356 = t4370 + t2910;
  t6359 = 2.0 * q__p[0] * t6356 * t1619;
  t5779 = t440 * t6137;
  t6363 = 2.0 * t732 * t5779 * t12;
  t6366 = 2.0 * t2635;
  t2635 = t128 * t311;
  t6368 = 2.0 * t2635;
  t6370 = t688 * q__p[3] * t114;
  t6372 = 2.0 * t142;
  t6377 = t1393 * param->s__l7x;
  t6378 = t146 * t114;
  t1619 = t16 * q__p[1];
  t6386 = -t171 * t114;
  t665 = t440 * q__p[3];
  t6402 = 2.0 * t1137 * t1130;
  t6410 = (((2.0 * t117 + t216) - 2.0 * t118) - 2.0 * t119) * q__p[0];
  t6411 = t6410 * t1170;
  t6414 = t543 * q__p[1] * t6137 * t12;
  t6421 = 2.0 * t1346 * t5779 * t1170;
  t6427 = -t2173 * param->m__l7;
  t943 = (t127 - t600) + t1029;
  t6429 = (((t943 + t6427) + t4594) + t806) * t290;
  t6445 = 2.0 * t543 * t991 * t6137;
  t6449 = t440 * t1060;
  t6451 = t225 * t6449 * t12;
  t6452 = t114 * t4855;
  t6458 = t290 * q__p[6];
  t6459 = t2893 * t6458;
  t6467 = t854 * t114;
  t6473 = q__p[1] * t168_tmp;
  t6488 = t215 * q__p[3];
  t6497 = t5525 / 2.0;
  tmpreturn_tmp_8 = -2.0 * t12 * q__p[0];
  tmpreturn_tmp_11 = t2973 * t940;
  tmpreturn_tmp_12 = t940 * (-t5571 - 2.0 * t5572);
  tmpreturn_tmp_13 = t3169 * t940;
  tmpreturn_tmp_14 = t1263 * t12;
  tmpreturn_tmp_15 = t1055 * t940;
  tmpreturn[35] = (((((((((((((((((((((((((((((((((((((((param->m__l7 * t5764 +
    t42 * t1739) + t1029) + t127) + t806) - t600) + t5762) + 2.0 * t5769) * t12
    + ((-4.0 * t12 * q__p[0] * t1567 - t2389) * t940 + -t2453)) + t2085) * t346
    + t2248 * t267) + t1462) + (((-t1664 - t2093) + t2383) + t753) * t940) -
    (q__p[5] * t2643 * t440 + t2099) * 2.0 * t12) * t241 + ((-2.0 * t226 * (t940
    + 1.0) * t3210 * t267 - 2.0 * t12 * t2038 * t346) - 2.0 * t940 * t2853) *
    t288) + t2347 * t267) + ((((((-t2036 + t5805) - t3018) - t3252) - t5809) *
    t12 + (tmpreturn_tmp_11 + t2449)) - t740) * t346) + t2162) + ((((((t5616 +
    t486) * t42 + -t2163) + t5833) + 2.0 * t5729) + 2.0 * t5731) - t2254) * t940)
    + ((((-t551 * t2911 * t42 + t5842) - (t168_tmp * t50 - t57 * t5843) *
    param->m__l7 * t2) + t2255) + t234 * -t171) * 2.0 * t440 * t12) - t2265) *
    t105 + ((((((((((((t12 * t1326 - t1271) + t1578) + t1368) * t346 + 4.0 *
    t189 * t1644) - 2.0 * t1763) * t241 + 2.0 * t4933 * t42 * t1049 * t288) +
    2.0 * t1569 * t42 * t5546 * t267) - 2.0 * t1764 * t346) - t1863) + t3229 *
    t940) - t3236) + t2032) * t106) + (((t940 + 1.0) * 2.0 * t5860 * t2121 -
    (((((t5864 - t2279 / 2.0) - t5869) + t6149_tmp / 2.0) + t2280 / 2.0) + t2289
    / 2.0) * 4.0 * t12 * t346) + (((((t2294 + t2644) - t2315) + t5899) + t2335)
    - t2351) * 2.0 * t940) * t288) + (((((((((-2.0 * t2266 * t5928 + t2434) +
    t5927) * t12 + ((4.0 * t2369 - 4.0 * t1189) * t940 + t2364)) - t992) * t346
    + ((2.0 * t2352 - 2.0 * t2205) - 2.0 * t416) * t267) + t2473) + (((t42 *
    t2661 - t4714) + t2475) + t2662) * t940) + ((((tmpreturn_tmp * (t5957 +
    t5959) * t2 + -t5956) + 2.0 * t1446 * t598) - 2.0 * t914 * t2715) + 2.0 *
    q__p[1] * t95) * t12) - t2716) * t241) + ((-t2748 + t2794) + t2808) * t267)
    + (((((((((((-t2 * t4583 - t257) + t1709) - t2547) - t3024) * t290 + (t2880
    - t2881) * t42) - t5946) + (-t114 * t2123 - 2.0 * t5874) * t2) + t387 * t114)
         + t5950) * t12 + (2.0 * t724 * t2864 * t940 + -t2843)) + t2912) * t346)
    + t2913) + (-2.0 * t168_tmp * t6027 * t699 + 2.0 * t2938) * t940) + ((((2.0 *
    t2 * t26 * t2115 * t440 - 2.0 * t215 * t433) + 2.0 * t440 * t3197) * t290 +
    t2939 * t42) - (((t3292 - (t114 * t6057 + t6060) * 2.0 * param->m__l7 * t2)
                     + (((param->m__l7 * t5763 + t145) + t201) + t5769) * t114)
                    + t3310) * 2.0 * t440) * t12) - t3314) * t38 / 2.0 +
    ((((((((((((((((((-t3208 - 8.0 * t423) + 4.0 * t1535) * t267 + ((t12 * t3193
    + t1629) - t3204) * t346) - t3208) - 4.0 * t3203) + t2400) * t241 + 8.0 *
    t5496 * t1049 * t288) + (t940 * t3430 - t2223) * t346) + ((t2230 + t2231) +
    t2692) * t940) + t2707) * t105 + -4.0 * t5502 * t120 * t106) - 4.0 * t3230)
          + (((tmpreturn_tmp_12 - t2900) * t346 + tmpreturn_tmp_13) - t3183) *
          t241) + ((t1352 - t3301) - t3307) * t267) + (((t5616 + t1163) * t12 +
    t3369) - t1213) * t346) - t1214) + tmpreturn_tmp_14) + t458) * t39 / 2.0) +
    ((((((((((((t12 * t3402 - t3319) + t3372) + t3425) * t346 + 4.0 * t245 *
             t638 * t267) - 2.0 * t6099) * t241 + 2.0 * t3230) + 2.0 * t1127 *
          t3120 * t267) - 2.0 * t6109 * t346) - t1214) + t6119 * t940) - t6125)
     + t6126) * t106 / 2.0) + (((((((((((((((((((((((2.0 * t2 * t2646 + t257) -
    t1709) + t6175) + 2.0 * t2887) + 2.0 * t5558) * t42 + t2506) + t5524) -
    t2971) - t6193) + t6197) * t12 + ((tmpreturn_tmp_8 * t481 + t614) * (2.0 *
    t42) * t940 + -t6164)) + t1003) * t346 + t6162 * t267) + t6159) + (((t5927 -
    t4413) * t42 + t6205) + t6209) * t940) + (t510 * t4856 - t1210) * 2.0 * t12)
    * t241 + ((-2.0 * t303 * (t940 - 1.0) * q__p[0] * t1601 * t42 * t267 - (((((
    -t2315 + t5899) + t2335) - t2351) * t42 + 2.0 * t6139) + t2304) * 2.0 * t12 *
               t346) - 2.0 * t6152 * t940) * t288) + 2.0 * t6222 * t267) +
    (((((((-2.0 * t128 * t973 + 2.0 * t2316) * t2 + (-t5691 + t2444)) - t2452) +
        2.0 * t1048 * -t171) * t42 + 2.0 * t6240) * t12 + (tmpreturn_tmp_15 +
    -t6227)) + t6247) * t346) + t6252) + (((((((t6263 - t5946) + t5948) + t5949)
    + t5950) * t42 + -t1120) + (((-t5524 + t2971) + t6193) - t6197) * t290) +
    2.0 * t1038 * t6268) * t940) + ((((((-t6278 + t6281) * t2 + (t6274 - t6277))
    + t6285) + t2645 * t168_tmp) * t42 - t544) - t6290) * 2.0 * t440 * t12) -
    t6296) * t105 / 2.0) + ((((t6306 + t6309) + t6310) * 4.0 * t12 * t346 + -2.0
    * t1569 * t6301 * t267) - ((t6315 + t6316) - t542) * 2.0 * t940) * t288 /
    2.0) + ((((((((((((((t5762 + t127) - t600) + t1029) - t427) + t1032) + t806)
                   * t42 + t6363) - t6366) - t6368) - 2.0 * t6370) + t6372) *
              t940 + (((((((2.0 * t4855 * t68 + t6341) * t42 + t6347) - t6350) *
    t12 + ((2.0 * q__p[1] * t6335 - t6334) * t940 + t6331)) - t6353) * t346 +
                       -2.0 * t6328 * t267) - t6359)) + ((((((-2.0 * t14 * t1619
    + 2.0 * t6377 * t6378) * t2 + -4.0 * t4 * t999) - 2.0 * t1393 * t440 * t6386)
    - 2.0 * t2910 * t665) + 2.0 * t80 * q__p[1]) * t42 - 2.0 * t330 * t440 *
    t6268) * t12) + t6402) * t241 / 2.0) + ((2.0 * t6411 + 2.0 * t6414) - 2.0 *
    t6410) * t267 / 2.0) + (((((((-2.0 * t2 * t2168 * t787 - 2.0 * t114 * t3197)
    + t2254) + t6429) * t42 + ((-2.0 * t2635 - 2.0 * t6370) + 2.0 * t142) * t290)
    - t486) * t12 + (-t6421 - 2.0 * t724 * t4082 * t42 * t940)) + t6445) * t346 /
                      2.0) + t875) + (((t214 * q__p[2] - t290 * t6452) * (2.0 *
    t168_tmp) * t42 + 2.0 * t6451) + 2.0 * t6459) * t940 / 2.0) + (((((((-2.0 *
    t1045 * t440 - 2.0 * t147 * t6467) * t2 + -4.0 * t2554 * t2540 *
    param->m__l7) + 2.0 * t6473 * t6386) + t387 * t440) * t290 - (((-2.0 * t5 *
    q__p[5] * t5868 + t2646 * t114 * t2) + ((t2887 + t420_tmp) + t5558) * t114)
    + t6488) * 2.0 * t440) * t42 + 2.0 * t433 * t6268 * t290) + ((((t5629 -
    t6497) * 2.0 * param->s__l7x * t323_tmp + -t5628) - t5947 * t114) + t1755) *
    2.0 * t440) * t12 / 2.0) + t6301;
  t6510 = t10 * t12;
  t5779 = t514 * t440;
  t6512 = q__p[3] * t12;
  t4 = t6512 / 2.0;
  t6514_tmp = t5779 - t991;
  t6514 = t6514_tmp + t4;
  t1055 = t724 * t440;
  t6523 = t1055 - q__p[3] / 2.0;
  t6524 = t6523 * t940;
  t6525 = t2399 * t440;
  t6526 = t6525 / 2.0;
  t6529 = ((t150 * t346 / 2.0 + t6524) + t6526) * t290 + ((t6514 * t346 + -t6510)
    + t189 / 2.0) * t241;
  t1446 = t290 * t346;
  t3120 = t940 * t1990;
  t3208 = t2848 / 2.0;
  t6543 = t1038 - t3208;
  t2643 = t18 * t39;
  t6556 = (t940 + 1.0) * t400 * t267;
  t6557 = t3210 * t6556;
  t5616 = t2820 * t76;
  t6560 = t440 * t400;
  t5691 = t6560 * t433;
  t5729 = t359 * t76;
  t5731 = 2.0 * t5729;
  t6568_tmp = t732 * t400;
  t6568 = t6568_tmp * t940;
  t6569 = q__p[2] * t400;
  t6570 = t6569 * t114;
  t2910 = t1038 * t42;
  t142 = t2910 * t76;
  t5762 = 2.0 * t142;
  t5763 = ((t6568 + t6570) - t5762) * t940;
  t5769 = t1569 * t267;
  t6581 = t5 * t5769;
  t2635 = t400 * t290;
  t6585 = t2635 * t940;
  t6587 = t6569 * t543;
  t1263 = t100 * t5;
  t6590 = t545 * t1263;
  t6592 = q__p[5] * t400;
  t5874 = (((t732 * t6585 + t6587 / 2.0) - t6590) + t370 / 2.0) - t6592 / 4.0;
  t5875 = 2.0 * t5616;
  t5899 = (t5875 + t5691) + t5731;
  t2173 = t400 * t1170;
  t5927 = t732 * t2173;
  t5946 = 8.0 * t5927;
  t5948 = 4.0 * t6570;
  t3197 = 2.0 * t6592;
  t6615 = -t1278 + t3197;
  t5949 = t6615 * t290;
  t5950 = 4.0 * t142;
  t2887 = t114 * t400;
  t5558 = 4.0 * t2887 * t4754;
  t2115 = t400 * q__p[1];
  t6628 = 4.0 * t2115 * t12 * t267;
  t3169 = t991 * t2173;
  t370 = t150 * t114;
  t6632 = t991 - t4;
  t142 = t6632 * t400;
  t5778 = (-4.0 * t1263 * t370 - 4.0 * t3169) + 4.0 * t142;
  t2121 = t114 * param->s__l7y;
  t6638 = t2121 * param->m__l7;
  t4 = 8.0 * t6638 * (t6523 * param->s__l7x);
  t5760 = t4 * t396;
  t6643 = t606 * t114;
  t6644 = t6643 * t1263;
  t6092 = 2.0 * t6644;
  t6083 = (t6092 + t2115) * 2.0 * t12;
  t2123 = t446 * t76;
  t2168 = t6632 * t114;
  t6664_tmp = 4.0 * param->s__l7y;
  t6664 = ((t6664_tmp * t2168 * t851_tmp + t940 * t2115) - 4.0 * t3356 * t1263) *
    t290;
  t2205 = t400 * t6523;
  t6669 = 4.0 * t2205 * t714;
  t6670 = t2776 * t76;
  t6671 = 2.0 * t6670;
  t2973 = (-t371 + t6592) * t440;
  t6679 = ((-t6671 - t2973) * t114 + t606 * t2635) * 2.0 * t12;
  t6682 = t5502 * param->s__l7y;
  t6683 = t18 * t106;
  t3356 = t787 * t5;
  t6689 = t5779 * t3356;
  t6695 = (-2.0 * t396 * t2115 - 8.0 * t2168 * t76) + 8.0 * t6689;
  t6698 = 4.0 * t2205 * t396;
  t6699 = t433 * t76;
  t6700 = 2.0 * t6699;
  t2168 = t400 * t42;
  t6705 = (t606 * t2168 - t6700) * (2.0 * t12);
  t6717 = ((t1170 * t991 * t2168 - t42 * t142) + t370 * t76) * t290;
  t6722 = t4 * t714;
  t6723 = t606 * t290;
  t6725 = 2.0 * t6723 * t3356;
  t6726 = t2115 * t446;
  t6727 = t400 * q__p[4];
  t6728 = t6727 * t42;
  t6729 = t6728 + t257;
  t2971 = t440 * t6729;
  t6733 = ((t6725 + t6726) - t2971) * 2.0 * t12;
  t2205 = q__p[0] * param->m__l7;
  t6738 = (t940 - 1.0) * param->s__l7y;
  t6739 = (t940 + 1.0) * t267;
  t6740 = t6738 * t6739;
  t6741 = t2205 * param->s__l7x * t6740;
  t6744 = t732 * t2168 * t940;
  t6745 = t6569 * t1226;
  t6746 = t6745 / 2.0;
  t6747 = t1038 * t76;
  t278 = t6744 + t6746;
  t6748 = t278 - t6747;
  t6752 = t49 * t76;
  t2410 = 2.0 * t6752;
  t6754 = t6560 * t4291;
  t6755 = (t2410 + t6754) + t717;
  t6764 = t644 * t76;
  t6766 = t6560 * t2776;
  t6767 = t6728 / 2.0;
  t6770 = t551 * t76;
  t6778 = t6569 * t1620;
  t6779 = t545 * t76;
  t6781 = t6592 * t42;
  t6782 = t6781 / 2.0;
  t6783 = (((t6819 * t6568_tmp + t46) + t6778) - 2.0 * t6779) - t6782;
  t6797 = t6560 * t638;
  t6807 = t400 * t106;
  t3230 = t1260 * param->m__l7;
  t370 = param->s__l7y * t20_tmp;
  t5869 = t370 * t1170;
  t6817 = t3230 * t5869;
  t6818 = t2115 * t12;
  t6819 = t25 * t6818;
  t4 = t26 * t20_tmp;
  t6821 = t1260 * t4;
  t6822 = (t6817 + t6819) - t6821;
  t6825 = t732 * t16;
  t6828 = 4.0 * t6825 * t6560 * t1170;
  t142 = q__p[3] * t16;
  t2400 = t2887 * t142;
  t6833 = t545 - q__p[4] / 2.0;
  t6834 = t20_tmp * t6833;
  t6837 = 4.0 * t26 * t6834 - 2.0 * t2400;
  t6839 = t465 * t400;
  t6841 = 4.0 * t732 * t6839;
  t6844 = 4.0 * t6817;
  t6848 = 4.0 * t551 * param->m__l7 * t370 * t940;
  t6849 = 2.0 * t6819;
  t6852 = t370 * t12;
  t6853 = t2205 * t6852;
  t4641 = t25 * t2115;
  t6856 = t4641 * t290;
  t6861 = 2.0 * t2399 * t4;
  t2205 = t6560 * t471;
  t6868 = t2887 * t295 * t16;
  t6870 = t20_tmp * t2849;
  t6873 = (-2.0 * t26 * t6870 - 4.0 * t6825 * t2205) + 2.0 * t6868;
  t2389 = t330 * t16;
  t6877 = 2.0 * t2389 * t2205;
  t6880 = t400 * t16;
  t6882 = 2.0 * t6880 * t5491;
  t6883 = q__p[0] * t16;
  t6884 = t2635 * t12;
  t6887 = t433 * t4;
  t6889 = 4.0 * t6883 * t6884 + 2.0 * t6887;
  t6892 = 2.0 * t2598 * t6884;
  t6895 = t20_tmp * t12;
  t6896 = t26 * t6895;
  t6897 = t11 * t6896;
  t6902 = t805 * t4;
  t6903 = 2.0 * t6902;
  t6904 = (-2.0 * t16 * t1990 * t400 + 4.0 * t6897) - t6903;
  t6906 = t787 * t370;
  t6908 = 2.0 * t6525 * t6906;
  t6911 = t6883 * t2173;
  t6912 = t338 * t114;
  t6913 = t6912 * t6896;
  t6914 = t6883 * t400;
  t6918 = t991 * t543;
  t6919 = t20_tmp * t1170;
  t6920 = t26 * t6919;
  t6921 = t6918 * t6920;
  t6922 = 4.0 * t6921;
  t6926 = t295 * t114;
  t6931_tmp = t991 * t290;
  t6932 = t6931_tmp * t6906;
  t6933 = 4.0 * t6932;
  t6936 = 2.0 * t6911;
  t6943 = 2.0 * t6914;
  t6947 = t42 * t288;
  t6949 = t12 * t16;
  t2540 = t6949 * param->s__l7x;
  t2547 = t465 * param->s__l7x;
  t2554 = t724 * t290;
  t2849 = t15 * t940;
  t2598 = t142 * param->s__l7x;
  t6961 = 4.0 * t2598;
  t6963 = t15 * t551 - t6961;
  t6967 = ((t12 * t6963 - 8.0 * t514 * t2547) + 8.0 * t94 * t991) + 2.0 * t2554 *
    t2849;
  t6972 = (t2849 * t197 + 4.0 * t2540) * q__p[1];
  t6975 = (t940 - 1.0) * t225;
  t6976 = (t940 + 1.0) * t20_tmp;
  t6977 = t6976 * t267;
  t6983 = (t714 * t94 - t791 * t15 / 4.0) * q__p[1];
  t6987 = 2.0 * t225 * t6919;
  t2849 = t290 * t16;
  t6989 = t2849 * param->s__l7x;
  t6992 = t295 * t94;
  t6996 = ((-t20_tmp * t359 - 8.0 * t1055 * t6989) + 4.0 * t6992) * t940;
  t6998 = q__p[3] * t42;
  t3210 = t6998 * t20_tmp;
  t2645 = t3210 / 4.0;
  t7004 = (t94 * t551 + t2645) * (4.0 * t440) * t12;
  t7005 = t225 * t20_tmp;
  t7010 = t732 * t54;
  t7013 = t2168 * t16;
  t7015 = t251 / 2.0 + t7013;
  t5947 = t7015 * q__p[0];
  t2893 = t2698 * t76;
  t2205 = t6569 * t42;
  t7023 = t947 * t67;
  t7026 = (((t2205 / 2.0 + -t2893) * t16 + t5947 * t940) + t7023 / 4.0) * t12;
  t2646 = t54 * t5;
  t2173 = t330 * t76;
  t7039 = (((2.0 * t2173 + t6797) * t16 + 2.0 * t2149 * t2646) + t1038 * t251 /
           2.0) * t940;
  t2149 = t5947 * t4243;
  t7044 = t4291 * t6896;
  t7047 = (-4.0 * t290 * t5947 + 4.0 * t2149) - 4.0 * t7044;
  t7049 = t991 * t1226;
  t7051 = 4.0 * t7049 * t6920;
  t7055 = (-8.0 * t94 * t543 + param->l__2) + param->l__3;
  t7060 = t551 * t114;
  t7063 = 4.0 * t6766;
  t7064 = 2.0 * t6728;
  t7065 = ((8.0 * t7060 * t76 - t412) + t7063) - t7064;
  t5828 = t6998 * t5843;
  t7068 = t168_tmp * t290;
  t7069 = t1038 * t7068;
  t7070 = ((((-t5828 - t7069) + t1484) + t452) + t495) + t428;
  t7075 = t100 * t370;
  t7077 = 4.0 * t11 * t7075;
  t7080 = 4.0 * t2149;
  t7081 = t991 * param->m__l7;
  t2149 = param->s__l7x * t20_tmp;
  t7083 = t2149 * t12;
  t7085 = 2.0 * t7081 * t7083;
  t7087 = -2.0 * t2893 + t2205;
  t7095 = t370 * t114;
  t7105 = t25 * param->s__l7y;
  t7111 = ((t514 * t7105 - t338 * t6895 / 4.0) - t732 * t169_tmp) * param->m__l7;
  t2820 = param->s__l7x * t267;
  t7115 = t18 * t6919;
  t7117 = 2.0 * t6931_tmp * t7115;
  t7122 = 4.0 * t12 * t5947 + 2.0 * t6912 * t7075;
  t7124 = 8.0 * t2893;
  t7126 = 2.0 * t2205 + t7124;
  t7128 = q__p[4] * param->m__l7;
  t7129_tmp = param->s__l7y * t695;
  t7130 = t7128 * t7129_tmp;
  t2893 = t18 * t20_tmp;
  t7136 = 2.0 * t6931_tmp * t2893;
  t7139 = q__p[0] * param->s__l7y;
  t2205 = t25 * param->s__l7x;
  t7146 = (-8.0 * t2205 + t124) * (2.0 * t7139) * param->m__l7 * t1170;
  t7149 = 4.0 * t6918 * t100 * t6852;
  t7150 = 8.0 * t2173;
  t7151 = t7064 + t412;
  t7153 = 2.0 * t6797;
  t7156 = t15 * t114;
  t7161 = (-t2244_tmp * t290 + t295 * t7156) + t7784;
  t7166 = t665 * t114;
  t2173 = t94 * param->s__l7y;
  t7170 = t27 * t5843;
  t7173 = t147 * t20_tmp;
  t7181 = -4.0 * t2205 + t124;
  t2205 = t114 * param->s__l7x;
  t7192 = t1038 * t27;
  t7194 = t330 * param->s__l7x;
  t7196 = (t49 * t2205 + t7192 / 2.0) + t7194 / 2.0;
  t7201 = t1038 * t2205;
  t7202 = t359 * param->s__l7y;
  t7203 = (t27 * t49 - t7201) + t7202;
  t7207 = t20_tmp * t288;
  t7443 = t1260 * t5843;
  t7684 = t1170 * t1260;
  t7216 = ((t7684 * t5843 + 4.0 * t169_tmp * t189) - t7443) * param->m__l7;
  t7220 = 8.0 * t5779 * t2646;
  t7221 = t3230 * t6852;
  t7222 = 2.0 * t7221;
  t7228 = t142 * t5;
  t7229 = t7228 / 2.0;
  t3230 = t20_tmp * t290;
  t7231 = t1038 * t3230;
  t7232 = ((t7231 - t530) - t555) - t266;
  t7236 = t27 * t20_tmp;
  t7241 = t991 * t2173;
  t7248 = 2.0 * t1346 * t7115;
  t5779 = 4.0 * t732 * (t440 * t7015);
  t7252 = t5779 * t12;
  t7255 = 2.0 * t2887 * t6998 * t16;
  t7263 = t2887 * t42;
  t7265 = q__p[1] * param->m__l7;
  t7266 = t7265 * t5;
  t7268 = t606 * t7263 - 2.0 * t7266;
  t7278 = t225 * param->m__l7 * t5869;
  t5869 = t7015 * t290;
  t7281 = t433 * t5869 * t12;
  t7282 = t225 * t4;
  t7288 = 4.0 * t11 * t5869 * t1170;
  t7294 = param->s__l7x * t940;
  t7297 = t2887 * q__p[3];
  t7298 = t446 * t16;
  t5869 = t7297 * t7298;
  t7300 = t132 * t949;
  t7311 = t5779 * t290;
  t7314 = 2.0 * t7278;
  t7316 = -4.0 * t6989 + t949;
  t7325 = t1038 * t20_tmp - t817 * t290;
  t7334 = -2.0 * t6726 + 2.0 * t2971;
  t7337 = 4.0 * t6723 * t76;
  t7340 = t6473 * t290;
  t7344 = t941 * t290;
  t7347 = (t3623 * t440 - t7340) * t114 - (t7344 + t3210) * t440;
  t7352 = 2.0 * t7282;
  t7355 = t189 * t42;
  t2971 = t2893 * t267;
  t7360 = t991 * t42;
  t7361 = t7360 * t7115;
  t7362 = 4.0 * t7361;
  t7365 = 4.0 * t6914 * t471 * t940;
  t7367 = t6998 * t2893;
  t7369 = 2.0 * t6569 * t2849 - 2.0 * t7367;
  t7371 = t7360 * t2893;
  t7372 = 4.0 * t7371;
  t7376 = t12 * t42;
  t7379 = (t465 * t6585 + t2893 * t7376) * q__p[1];
  t7386 = t446 * param->m__l7;
  t7387 = t2149 * t940;
  t5947 = t400 * t12;
  t7392 = (t465 * t5947 - t7386 * t7387) * q__p[1];
  t7395 = 4.0 * t6911;
  t7396 = t991 * t446;
  t7397 = t18 * t6895;
  t7398 = t7396 * t7397;
  t7402 = t295 * t42;
  t7405 = (-2.0 * t16 * t6569 + 2.0 * t2893 * t7402) - 4.0 * t7398;
  t7407 = t400 * q__p[3];
  t5779 = t7407 * t16;
  t7409 = t551 * t42;
  t7414 = (t2893 * t7409 + t5779) * (2.0 * t440) * t12;
  t7417 = (t940 - 1.0) * param->s__l7x;
  t7420 = t1226 * param->s__l7x;
  t7421 = t1038 * t7420;
  t7425 = (-t7421 / 2.0 + t49 * param->s__l7y) + t763 / 2.0;
  t7430 = t330 * t429;
  t7431 = (t49 * t7420 + t832) + t7430;
  t7437 = 2.0 * t6817;
  t7440 = (4.0 * t6819 + -t7437) + 2.0 * t6821;
  t7443 *= t12;
  t7444 = t1619 * param->s__l7y;
  t7447 = t429 * t940;
  t7450 = t2149 * t114;
  t7452 = t7231 + t266;
  t7231 = (4.0 * t160 + param->l__4) + param->l__5;
  t7463 = param->s__l7x * t7231;
  t7465 = t991 * t7463 * t12;
  t7467 = 2.0 * t6998 * t2173;
  t6819 = t2115 * t114;
  t7478 = 2.0 * t42 * t606 * t76 + t6819;
  t7480 = t419 * t1130;
  t7494 = ((t1170 * t15 * t732 + t12 * t338 * t7231) - t15 * t732) *
    param->m__l7;
  t7500 = 2.0 * t6931_tmp * t18 * t7231 * t1170;
  t6821 = 2.0 * t7402 * t2173;
  t7402 = t290 * param->s__l7x;
  t7518 = 4.0 * t5748 * t7115;
  t7519 = t2887 * t2849;
  t7521 = t18 * t695;
  t7524 = (2.0 * t7519 + t7521) * q__p[0] * t791;
  t7532 = t2887 * t290;
  t7537 = (-2.0 * t606 * t7532 + 4.0 * t6670) + 2.0 * t2973;
  t7539 = t665 * t42;
  t7542 = t419 * t867;
  t7543 = t3623 * param->s__l7x;
  t7552 = 2.0 * t5748 * t2893;
  t7555 = t100 * t67;
  t3623 = t7555 / 2.0 + t6880;
  t7558 = (t940 + 1.0) * t3623;
  t7565 = t330 * t42 * t76;
  t2973 = t6560 * q__p[1];
  t7194 = (t7192 + t7194) * t854;
  t7463 = ((t732 * param->m__l7 * t7463 * t940 + (2.0 * t7565 + t2973) * t16) +
           t7194 / 2.0) * t12;
  t7202 = t7201 - t7202;
  t7586 = (((-2.0 * t2698 * t1263 + t6569) * t16 + q__p[0] * t3623 * t940) -
           t854 * t7202 / 2.0) * t940;
  t2698 = t114 * t7231;
  t7596 = ((t7684 * t2698 - t1260 * t2698) - t638 * t6895) * param->m__l7;
  t7361 *= 2.0;
  t2698 = t2205 * t695;
  t7607 = (2.0 * t446 * t67 + t2698) * param->m__l7 + 4.0 * t2635 * t16;
  t7614 = (8.0 * t6590 - t1278) + t3197;
  t7616 = t6569 * t290;
  t7617 = 4.0 * t7616;
  t7201 = param->s__l7x * t168_tmp;
  t7625 = t763 * t7068;
  t7626 = t31 * t20_tmp;
  t7627 = t7625 - t7626;
  t7634 = 2.0 * t7371;
  t7371 = t27 * t695;
  t7645 = ((-4.0 * t1620 * t2173 - t68 * t7402) + t7371) * 2.0 * q__p[0] *
    param->m__l7 * t1170;
  t6897 *= 2.0;
  t7651 = 2.0 * t6727;
  t7060 = ((4.0 * t338 * t6560 + 8.0 * t1263 * t7060) - t1066) - t7651;
  t7654 = t196 * t7068;
  t7655 = t57 * t20_tmp;
  t7656 = t7654 + t7655;
  t7658 = t7069 - t52;
  t7666 = t6998 - t6055;
  t7669_tmp = -t12 * t440;
  t7669 = t7669_tmp * t7666 + t225;
  t7676 = (t6880 + t7555) * q__p[0];
  t7677 = t7676 * t1170;
  t6921 *= 2.0;
  t7684 = t7201 * t114;
  t7686 = (t446 * t7129_tmp - 4.0 * t1226 * t2173) - t7684;
  t7689 = t429 * t20_tmp;
  t7565 *= 4.0;
  t7651 = -t1066 - t7651;
  t7698 = 2.0 * t2973;
  t7701 = t57 * t3230;
  t178 *= param->s__l7y;
  t1066 = -t178 + t128;
  t7708 = t290 * t680 - t7784;
  t6932 *= 2.0;
  t7160 = (t543 * t7521 + t6880) * (2.0 * q__p[0]) * t1170;
  t7398 *= 2.0;
  t7726 = -t6615 * t290;
  t6569 *= 2.0;
  t7733 = -param->s__l7x * t2244_tmp + t7542;
  t7738 = t31 * t3230;
  t7739 = t763 * t168_tmp;
  t7747 = t31 * t124;
  t7748 = t34 * t168_tmp;
  t7752 = t57 * t168_tmp;
  t7755 = (t7747 + t7748) * t114 - (t132 * t124 + t7752) * t42;
  t7759 = t27 * t168_tmp;
  t7761 = (t949 * t7402 - t7759) * q__p[0];
  t7772 = t91 * t1170;
  t7773 = t1260 * t7772;
  t7774 = t189 * t2121;
  t7775 = t1260 * t91;
  t7776 = (t7773 + t7774) - t7775;
  t7784 = t805 * param->s__l7y;
  t6834 = ((2.0 * t16 * t6834 - t7784) * t12 + -2.0 * t514 * t598 *
           param->s__l7y) + 2.0 * t991 * t2121;
  t7791 = 2.0 * t7773;
  t7792 = t91 * t940;
  t7794 = 2.0 * t551 * t7792;
  t7797 = t6883 * t6895;
  t7799 = t338 * t2121;
  t7801 = (2.0 * t7797 - t7799) * t940;
  t7802 = t2399 * t91;
  t7805 = t543 * param->s__l7y;
  t6870 = ((-t16 * t6870 + t295 * t2121) - 2.0 * t1055 * t7805) * t940;
  t7812 = t6525 * t7805;
  t7817 = t290 * param->s__l7y;
  t7824 = (2.0 * t724 * t7817 + t91 * t433) * t940 + t2399 * t7817;
  t7826 = t91 * t12;
  t7829 = t805 * t91;
  t7832 = ((2.0 * t11 * t7826 + -param->s__l7y * t1990) - t7829) * t940;
  t7833 = t25 * t20_tmp;
  t6525 *= t7833;
  t7837 = t514 * param->s__l7y;
  t7838 = t6912 * t7826;
  t6919 *= 2.0 * t6931_tmp * t25;
  t7849 = ((param->s__l7y * t2848 - t295 * t7833) - 2.0 * t832) * t12;
  t7851 = 2.0 * t6931_tmp * t7833;
  t7858 = (-t16 * t5843 * t634 + param->s__l7y * t665) * t12;
  t7862 = t54 * t20_tmp;
  t7863 = t4933 * param->s__l7x;
  t7867 = 4.0 * t3169;
  t7387 *= 4.0 * t724 * t446 * t54;
  t7873 = -t7409 * t92 - t7407;
  t7874 = 2.0 * t7873;
  t7876 = t991 * t400;
  t7877 = 4.0 * t7876;
  t7885 = (-t940 * t18 * t20_tmp * t249 * t197 + t5947) * q__p[1];
  t6585 = (t6113 * t92 + t6585) * q__p[1];
  t680 = t225 * t16;
  t7899 = t680 * t7115;
  t7900 = 4.0 * t7899;
  t7904 = t2149 * t16;
  t6884 = (tmpreturn_tmp * t359 * t7904 - 4.0 * t991 * t6884) + 2.0 * t290 *
    t7407;
  t2399 = t6998 * param->m__l7 * t7904;
  t7616 = 2.0 * t440 * (-t2399 + t7616) * t12;
  t7918 = 2.0 * t680 * t2893;
  t7922 = 2.0 * t27 + t255;
  t7923 = t7922 * q__p[0];
  t7924 = t18 * t940;
  t680 = t7201 * t16;
  t7928 = t947 * t680;
  t7930 = (((2.0 * t7923 * t7924 + t5691) + t5731) + t7928) * t12;
  t6568 = (((-param->m__l7 * t1038 * t680 + t6568) + t6570) - t5762) * t940;
  t7943 = (-t290 * t7923 + t4243 * t7923) - 2.0 * t4291 * t7826;
  t7948 = t54 * t2149 * t1170;
  t7950 = 4.0 * t7049 * t7948;
  t7951 = t16 * t695;
  t7532 = (t18 * t7951 + 2.0 * t7532) * q__p[0];
  t7956 = t12 * t940;
  t6587 *= 2.0;
  t6590 *= 4.0;
  t947 = ((-2.0 * t1270 + param->I__l7xx) - param->I__l7yy) - param->I__l7zz;
  t7966 = q__p[5] * t947;
  t7049 = 4.0 * t7049 * t92;
  t7976 = 2.0 * t7923 * param->m__l7 * t7402 * t1170;
  t7977 = t991 * t16;
  t7978 = t7977 * t6896;
  t7994 = t338 * t16 * t6896;
  t8000 = 2.0 * t991 * t2849 * t6920;
  t8006 = (t12 * t7923 + t2947 * t6912) * tmpreturn_tmp * t7294;
  t8007 = param->s__l7x * t695;
  t6113 = t8007 * t16;
  t8014 = 2.0 * t6931_tmp * t118;
  t8017 = t290 * param->m__l7;
  t4291 = t8017 * t6113;
  t8023 = (2.0 * t2887 + t4291) * (2.0 * q__p[0]) * t1170;
  t8027 = 4.0 * t991 * t1620 * t54 * t7083;
  t6570 *= 2.0;
  t8032 = t371 - t7966;
  t8036 = t429 * t5843;
  t8050 = 2.0 * q__p[0] * (t4291 + t2887);
  t8056 = t1038 * t429;
  t8060 = ((t49 * t2121 - t8056 / 2.0) + t912 / 2.0) * t12;
  t8064 = t1038 * t2121;
  t8065 = t359 * param->s__l7x;
  t8066 = (t49 * t429 + t8064) + t8065;
  t8073 = t1260 * t25;
  t8074 = t8073 * t6920;
  t8077 = (2.0 * t118 * t1346 - 2.0 * t6818) - 2.0 * t8074;
  t8079 = 2.0 * t3169;
  t8080 = t1260 * t7826;
  t8081 = t433 * param->s__l7y;
  t4291 = ((2.0 * t60 + param->I__l7xx) - param->I__l7yy) + param->I__l7zz;
  t680 = q__p[3] * t4291;
  t7876 *= 2.0;
  t8074 *= 2.0;
  t3169 = t7923 * t114;
  t8104 = t791 * param->s__l7x;
  t8105 = t3169 * t8104;
  t8111 = t429 * param->s__l7y;
  t8112 = t805 * t8111;
  t8119 = q__p[1] * t947;
  t8128 = t338 * t12;
  t8132 = (t7922 * t114 * t8128 / 2.0 + t225 * t7772) - t225 * t91;
  t8137 = t440 * param->s__l7x;
  t7923 = 2.0 * t7923 * t787 * t8137 * t4243;
  t8141 = t6825 * t6896;
  t8146 = t34 * t949;
  t6825 = t6926 * t8111;
  t8111 = t3169 * t8137 * t290;
  t7899 *= 2.0;
  t8163 = t787 * t6113;
  t8167 = 2.0 * q__p[0] * (t8163 + t2635) * t791;
  t8182 = t290 * t947;
  t3169 = t91 * t267;
  t8198 = t6998 * t91;
  t7772 = ((2.0 * t49 * t471 * param->s__l7x + 2.0 * t7360 * t7772) +
           (param->s__l7x * t551 + t8198) * t12) - 2.0 * t991 * t2947;
  t8207 = t7376 * t91;
  t8209 = (t2492 * t7402 - t8207) * q__p[1];
  t8212 = q__p[0] * param->s__l7x;
  t7792 = (t446 * t7792 + t8104) * q__p[1];
  t8219 = 2.0 * t514 * param->s__l7x;
  t6931 = ((2.0 * t6931_tmp * t8207 + -t2947 * t295) - t196) * t940;
  t8207 = (t2947 * t551 - t31) * t440 * t12;
  t8231 = param->m__l7 * t106;
  t8234 = t1226 * param->s__l7y;
  t8235 = t1038 * t8234;
  t8240 = ((t8235 / 2.0 + t49 * param->s__l7x) + t196 / 2.0) * t12;
  t8244 = t330 * t27;
  t8245 = t1038 * param->s__l7x;
  t8246 = (t49 * t8234 + t8244) - t8245;
  t7773 = ((t7773 - 2.0 * t7774) - t7775) * param->m__l7;
  t6689 *= 4.0;
  t8259 = t8073 * t6896;
  t2492 = t805 * t5;
  t8273 = t2205 * param->s__l7y;
  t7775 = t991 * t8273;
  t7115 *= 2.0 * t1260 * t16;
  t8073 = t26 * t255;
  t8284 = t8073 + t2168;
  t8285 = t8284 * q__p[0];
  t8287 = 2.0 * t8285 * t791;
  t8296 = t50 * t1130;
  t8300 = t42 * t4291;
  t8309 = t732 * t249 * t6920;
  t8311 = t8284 * q__p[1] * t471;
  t8312 = t5748 * t118;
  t8317 = 2.0 * t8285 * t5796;
  t8328 = t42 * t947;
  t8329 = t295 * t8328;
  t8333 = 2.0 * t8285 * t197;
  t8336 = 4.0 * t8309;
  t8337 = t543 * param->s__l7x;
  t8342_tmp = t7139 * t440;
  t8342 = (-2.0 * t8337 + t7951) * t8342_tmp * t12;
  t8347 = t295 * t8273;
  t8354 = t50 * t867;
  t8361 = t4291 * t290;
  t8364 = q__p[4] * t4291 * t42;
  t8365 = t8364 + t257;
  t8369 = 2.0 * t8312;
  t8373 = t867 * t16;
  t1130 = tmpreturn_tmp_7 + t8373;
  t8385 = (t8056 - t912) * t854 * t16;
  t8388 = (((t8285 * t2238 - t8385 / 2.0) + t6746) - t6747) * t12;
  t8391 = t1130 * q__p[0];
  t8064 += t8065;
  t7924 = (((t16 * t8064 * t854 + t7924 * t8391) + t717) + t6754) * t940;
  t912 = t638 * t16;
  t8065 = (2.0 * t543 * t8285 - 2.0 * t5908 * t8285) + 2.0 * t6896 * t912;
  t6920 *= 2.0 * t991 * t249;
  t5908 = t2121 * t695;
  t8417 = t7402 * param->s__l7y;
  t8285 = (-2.0 * t7402 * t867 + t5908) * t16 - 4.0 * t8417;
  t8436 = 2.0 * t6766;
  t8439 = 4.0 * t6770;
  t8443 = 2.0 * t7360 * t118;
  t6754 = t429 * t695;
  t8455 = ((t543 * t67 + t6754) * param->m__l7 * t16 + t2887 * t446) * 2.0 *
    q__p[0] * t1170;
  t7397 *= 2.0 * t991 * t25;
  t6778 *= 2.0;
  t6779 *= 4.0;
  t6746 = t7966 * t42;
  t8373 = (t8373 + param->s__l7y) * q__p[0];
  t8373 = (t1170 * t8373 - t7838) - t8373;
  t7948 *= 2.0 * t6918;
  t8486 = t67 * t114;
  t7263 += (t446 * t8007 + t8486) * param->m__l7 * t16;
  t8507 = t947 * t114;
  t8510 = (t6746 - t230) * t290;
  t8511 = 2.0 * t6747;
  t6918 = 2.0 * t6918 * t92;
  t8523_tmp = t7139 * param->m__l7;
  t8523 = (t543 * t7951 - param->s__l7x) * t8523_tmp * t1170;
  t8524 = t54 * t6852;
  t7396 = 2.0 * t7396 * t8524;
  t8528 = -param->s__l7y * t2244_tmp - t8354;
  t8533 = t196 * t168_tmp;
  t8548 = t57 * t124;
  t8549 = t132 * t168_tmp;
  t8555 = (t8548 - t8549) * t114 - (t124 * t34 - t1583) * t42;
  t2244 = t7201 * t42;
  t8561 = (t949 * t7817 + t2244) * q__p[0];
  tmpreturn_tmp_9 = 2.0 * t54 * t20_tmp;
  t2244_tmp = -2.0 * param->m__l7;
  tmpreturn_tmp_a = -t1038 * t290;
  tmpreturn_tmp_b = t12 * q__p[0];
  t7122 *= t940;
  tmpreturn_tmp_16 = 8.0 * param->m__l7;
  tmpreturn_tmp_17 = t940 * (4.0 * t6853 - 2.0 * t6856);
  t6873 *= t940;
  tmpreturn_tmp_18 = t12 * (-4.0 * t16 * t6543 * t400 - 2.0 * t4 * t6926);
  tmpreturn_tmp_19 = (-2.0 * t787 * t634 * t370 + 2.0 * t6560 * t142) * t12;
  t7405 *= t940;
  t7537 *= t16;
  tmpreturn_tmp_1a = 2.0 * t724 * param->m__l7;
  t7060 *= t16;
  t6884 *= t940;
  tmpreturn_tmp_1b = param->s__l7y * t114;
  tmpreturn[42] = (((((((((((((((((((((((((((((((((((((((((((t7051 -
    tmpreturn_tmp_1a * param->s__l7y * t7055 * t940) + (t16 * t7065 - 2.0 * t26 *
    t7070) * t12) - t7077) * t346 + t7047 * t267) + t7080) + ((t7087 * t16 +
    t7023 / 2.0) * 4.0 * t290 + -t7085) * t940) - (param->s__l7x * t440 * t967 -
    t638 * t7095) * 2.0 * param->m__l7 * t12) * t241 + ((-8.0 * t346 * t7026 +
    8.0 * t6581 * t7010) + 4.0 * t7039) * t288) + 8.0 * t7111 * t2820) + (((t16 *
    t7126 - 2.0 * t7130) * t12 + (t7122 + t7117)) - t7136) * t346) + t7146) +
    ((((t290 * t7151 - t7150) - t7153) * t16 + t7149) - 2.0 * t26 * t7161) *
    t940) - ((((4.0 * t7166 * t2173 - t6723 * t7170) + (-t1080 * t57 - t7173) *
    t290) + t817 * t440 * param->s__l7x) * t12 + t7139 * t7181) * 2.0 *
    param->m__l7) * t105 + (((((((((8.0 * t10 * t2540 + t346 * t6967) - t6972) *
    t241 + t20_tmp * t4933 * t6947) + t6975 * t6977) - 4.0 * t6983 * t346) -
    t6987) + t6996) - t7004) + t7005) * (-2.0 * t26) * t106) - ((2.0 * t12 *
    t346 * t7196 + param->s__l7y * t225 * t5769) + t940 * t7203) * 2.0 *
    param->m__l7 * t7207) + ((((((((t7232 * param->s__l7x * t114 / 4.0 + -t7229)
    - t551 * t7236 / 4.0) * t12 + t7241) * tmpreturn_tmp_16 + (2.0 * t42 *
    (-t7222 + t4641) * t940 + -t7220)) * t346 + 2.0 * t7216 * t2820) + t7248) +
    ((t27 * t1990 + t551 * t2205) * (2.0 * t275) + (t7252 - t7255)) * t940) +
    (t1393 * t146 * t2121 + t16 * t7268) * (2.0 * t12)) * t241) + ((4.0 * t7278
    + 4.0 * t7281) - 4.0 * t7282) * t267) + ((((-2.0 * t169_tmp * t338 + t732 *
    t6895) * 2.0 * param->m__l7 * t7294 + -t7288) + (-2.0 * t5869 - (-2.0 * t42 *
    t6543 * t370 + t7300) * tmpreturn_tmp) * t12) + t7311) * t346) - t7314) +
    (t8342_tmp * t7316 * t12 - (t114 * t7325 - 2.0 * t169_tmp * t295) *
    param->s__l7x) * tmpreturn_tmp * t940) + ((t114 * t7334 - t7337) * t16 + 2.0
    * t26 * t7347) * t12) + t7352) * t38 + ((((((((((((((((((t12 * t6837 - t6828)
    + t6841) * t346 + 4.0 * t6822 * t267) + t6844) + t6848) - t6849) * t241 +
    -8.0 * t26 * t20_tmp * t5496 * t288) + (tmpreturn_tmp_17 + t6861) * t346) +
    t6873) - t6877) * t105 + 2.0 * t5502 * t16 * t6807) + t6882) + (((t940 *
    t6889 + t6892) * t346 + t6904 * t940) + t6908) * t241) + ((-4.0 * t6911 +
    4.0 * t6913) + 4.0 * t6914) * t267) + ((tmpreturn_tmp_18 - t6922) + t6933) *
    t346) + t6936) + tmpreturn_tmp_19) - t6943) * t39) + ((((((((((((t12 * t7369
    - t7362) + t7365) + t7372) * t346 + 4.0 * t7355 * t2971) - 2.0 * t7379) *
    t241 + t6882) + 2.0 * t1127 * t16 * t6556) + 2.0 * t7392 * t346) - t7395) +
    t7405) - t7414) + t6943) * t106) + ((((((((((((((-2.0 * t2400 -
    (param->s__l7y * t7452 + t7409 * t7450) * 2.0 * param->m__l7) * t12 +
    (-t6828 - tmpreturn_tmp_2 * (t7443 + t7444) * t7447)) + t6841) * t346 +
    t7440 * t267) - t7437) - ((t7465 - t7467) - (t7421 - t763) * t3230) *
    tmpreturn_tmp * t940) - ((-t7480 + t6377) * t146 + t7478 * t16) * 2.0 * t12)
    * t241 + ((-2.0 * t12 * t346 * t7425 + t5748 * t6739 * t7417) + t940 * t7431)
    * (-2.0 * t275) * t288) - 2.0 * t7494 * t2820) + (((-2.0 * t6853 - 2.0 *
    t6856) * t940 + t7500) - (((t2910 * t7450 - t6821) + t968) * t12 + t991 *
    t7402 * t7231) * tmpreturn_tmp) * t346) + t7518) + ((t359 * t7450 + t67 *
    t6458) * 2.0 * param->m__l7 + (-2.0 * t7524 + 2.0 * t6868)) * t940) + (t7537
    - ((-t7539 * t7450 - t147 * t7068) + (-t7542 + t7543) * t440) *
    tmpreturn_tmp) * t12) - t7552) * t105) + ((-4.0 * t1127 * t267 * t7558 - 4.0
    * t346 * t7463) - 4.0 * t7586) * t288) + ((((((((t114 * t7614 - t7617) * t16
    - (((tmpreturn_tmp_a * t7201 - t7542) + t7543) * t114 + t7627 * t42) *
    tmpreturn_tmp) * t12 + ((tmpreturn_tmp_8 * t7607 - 2.0 * t6887) * t940 +
    t7361)) - t7634) * t346 + 2.0 * t7596 * t2820) - t7645) + ((t27 * t7658 +
    t114 * t7656) * 2.0 * param->m__l7 + (t7060 + -t6897)) * t940) +
    tmpreturn_tmp_7 * t7669 * t973) * t241) + ((2.0 * t7677 - 2.0 * t6913) - 2.0
    * t7676) * t267) + (((((t290 * t7651 + t7565) + t7698) * t16 - ((t695 *
    t1066 - t7701) * t114 + t7708 * param->s__l7y * t42) * 2.0 * param->m__l7) *
    t12 + (t6921 - (tmpreturn_tmp_b * t7686 - t338 * t7689) * tmpreturn_tmp *
           t940)) - t6932) * t346) + t7160) + ((((t7726 - t5950) * t114 + t6569)
    * t16 + t7398) - ((t1038 * t7201 + t290 * t7733) * t114 - (-t7738 + t7739) *
                      t42) * tmpreturn_tmp) * t940) - (t7669_tmp * t7755 + t7761)
    * 2.0 * param->m__l7) * t2 / 2.0 + ((((((((((((((((((((((((4.0 * t5616 +
    t5691) + t5731) * (4.0 * t12) * t346 + 4.0 * t6557) + 4.0 * t5763) * t288 +
    ((-4.0 * t940 * t290 * t5899 + 8.0 * t12 * t346 * t5874) - 8.0 * t100 *
    t1260 * t6581) * t241) + 4.0 * t6557) + ((-t5875 + t5691) - t5729) * 4.0 *
    t12 * t346) - t5946) + ((-t5948 + t5949) + t5950) * t940) + t5558) * t105 +
    8.0 * t400 * t6529 * t106) + (((t346 * t5778 + t6628) - t5760) - t6083) *
    t241) - 8.0 * t189 * t497 * t2123) - 2.0 * t6664 * t346) - t6669) - t6679) *
    t38 + ((((((((t5502 * t106 - 2.0 * t114 * t6529 * t105) + t5491) + (2.0 *
    t5492 * t1446 - t3120) * t241) - 2.0 * t4928 * t267) - 2.0 * t6543 * t12 *
    t346) + t514) + t797) - q__p[0]) * -4.0 * param->s__l7y * t2643) - 4.0 *
    t6682 * t6683) + (((((((t346 * t6695 - 8.0 * t6510 * t3356) - t6698) - t6705)
    * t241 - 4.0 * t2115 * t42 * t471 * t267) + 4.0 * t6717 * t346) + t6722) +
                      t6733) * t105) + ((-8.0 * t12 * t346 * t6748 + 4.0 * t940 *
    t6755) + 8.0 * t6741) * t288) + ((((((t6766 - t6767) - t420_tmp) * t114 +
    4.0 * t6764) + 2.0 * t6770) * 4.0 * t12 * t346 + 4.0 * t1127 * t2887 * (t940
    + 1.0) * t42 * t1040) + 4.0 * t940 * t6783) * t241) - 4.0 * t6741) +
    (((-t6782 + t46) * t290 + t278) - t6747) * (4.0 * t12) * t346) - (((-t290 *
    t6729 + t6797) * t114 + t2410) + t717) * (2.0 * t940)) * t3 / 2.0) +
    ((((((((((((((((2.0 * t267 * t7776 + t346 * t6834) - t7774) + t7791) + t7794)
    * t241 + -4.0 * t16 * t5496 * t7207) + (t7801 + t7802) * t346) + t6870) -
             t7812) * t105 + t6682 * t106) + param->s__l7y * t4933 * t288) +
          ((t346 * t7824 + t7832) + t6525) * t241) + ((-2.0 * t7837 + 2.0 *
    t7838) + 2.0 * t7139) * t267) + ((-t6919 + t7849) + t7851) * t346) + t7837)
      + t7858) - t7139) * t18 * t39) + ((((((((((((((((((((((((((t2244_tmp * t94
    * t7070 - t371) - t6587) + t6590) + t7966) * t12 + (t7950 - 2.0 * t7532 *
    t7956)) - t7049) * t346 + 2.0 * t18 * t7943 * t267) + t7976) + (((t7928 +
    t5691) + t5731) * 2.0 * t290 + 2.0 * t7978) * t940) + (t440 * t968 + t638 *
    t7450) * (2.0 * t16) * param->m__l7 * t12) * t241 + ((-2.0 * t346 * t7930 -
    2.0 * t6557) - 2.0 * t6568) * t288) + ((-2.0 * t5927 + 2.0 * t7994) + 2.0 *
    t6568_tmp) * t267) + ((((-2.0 * t7128 * t6113 - 2.0 * t5691) + 2.0 * t5729) *
    t12 + (-t8000 + t8006)) + t8014) * t346) + t8023) + ((((-2.0 * t16 * t18 *
    t7161 + t290 * t8032) - t5762) + t8027) + t6570) * t940) + ((((t5957 - t5959)
    * t290 + t6723 * t8036) + t4914 * t440) * tmpreturn_tmp * t16 + 2.0 * t598 *
    t7407) * t12) - t8050) * t105 + ((((((((((((t12 * t7874 - t7867) - t7387) +
    t7877) * t346 + t6628) - 2.0 * t7885) * t241 + -2.0 * t7862 * t7863 * t6947)
    - 2.0 * t225 * t54 * t7417 * t6977) - 2.0 * t6585 * t346) + t7900) + t6884)
    - t7616) - t7918) * t106) - ((param->s__l7x * t225 * t5769 + t940 * t8066) -
    2.0 * t346 * t8060) * tmpreturn_tmp_9 * t288) + ((((((((tmpreturn_tmp_1b *
    t7232 + t551 * t7689) * -2.0 * param->m__l7 * t16 + t680) * t12 + (t8079 -
    (t8080 - t8081 / 2.0) * tmpreturn_tmp_2 * t7447)) - t7876) * t346 + t8077 *
    t267) - t8074) + (((t1990 * t429 - t551 * t2121) * t20_tmp * t16 + t8105) -
                      t8112) * tmpreturn_tmp * t940) + ((t6378 * t6377 * t16 +
    t6644) + t8119 / 2.0) * 2.0 * t12) * t241) + 4.0 * t18 * t8132 * t267) +
    ((((2.0 * t20_tmp * t429 * t6543 + t8146) * t16 - t6825) * t12 + t8111) *
     tmpreturn_tmp + ((t338 * t4291 - 2.0 * t8141) * t940 + -t7923)) * t346) -
    t7899) + ((tmpreturn_tmp * t16 * t2121 * t7325 - t295 * t4291) + t8167) *
    t940) + ((tmpreturn_tmp * t7347 * t94 + (t440 * t8032 - t6671) * t114) +
             t606 * t8182) * t12) + t7918) * t38 / 2.0) + (((((((((t346 * t7772
    - 2.0 * t7355 * t3169) - t8209) * t241 + t7863 * t288) + t8212 * t5769) +
    t7792 * t346) - t8219) + t6931) + t8207) + t8212) * param->s__l7y * t8231) +
    (((((((((((((((-t7452 * param->s__l7x / 2.0 + t7409 * t7095 / 2.0) * t16 -
    t2492 / 2.0) * t12 + t7775) * tmpreturn_tmp_2 + ((4.0 * t8259 + t8119) * t42
    * t940 + -t6689)) * t346 + -2.0 * t7773 * t2820) - t7115) + ((t8287 - 2.0 *
    t8017 * t20_tmp * (t8235 + t196) * t16) - t6998 * t947) * t940) + (((t8296 +
    t1394) * param->m__l7 * t465 - t6699) + t606 * t8300 / 2.0) * 2.0 * t12) *
           t241 + ((t940 * t8246 + t5748 * t6740) + 2.0 * t346 * t8240) *
           tmpreturn_tmp_9 * t288) + ((2.0 * t8309 + 2.0 * t8311) - 2.0 * t8312)
          * t267) + ((((param->s__l7x * t967 - t2910 * t7095) * -2.0 *
                       param->m__l7 * t16 - t8329) * t12 + (-t8317 -
    tmpreturn_tmp * (t7797 + t7799) * t7294)) + t8333) * t346) - t8336) +
       (((-t359 * t7095 + t6458 * t7201) * t16 + t8342) + t8347) * 2.0 *
       param->m__l7 * t940) + (((((-t7539 * t7095 - t987 * t7068) + (t8354 +
    t2578) * t440) * tmpreturn_tmp * t16 - t6725) - t638 * t8361) + t8365 * t440)
      * t12) + t8369) * t105 / 2.0) + ((t2244_tmp * q__p[0] * (t940 + 1.0) *
    (t940 - 1.0) * t2820 * t1130 + 4.0 * t346 * t8388) - 2.0 * t7924) * t288 /
                        2.0) + (((((((((((tmpreturn_tmp_a * t67 + t2578) + t8354)
    * t114 - t7656 * t42) * tmpreturn_tmp * t16 + ((-t8436 + t8364) + t257) *
    t114) - t8439) * t12 + ((tmpreturn_tmp_b * t8285 - t7904 * t433) *
    tmpreturn_tmp * t940 + -t6920)) + t8443) * t346 + t8065 * t267) - t8455) +
    ((((((t429 * t7658 - t114 * t7627) * tmpreturn_tmp * t16 + -t7397) - t6778)
       + t6779) + t6746) - t230) * t940) + 2.0 * t16 * t7669 * t7521) * t241 /
                       2.0) + param->m__l7 * t8373 * t2820) + (((((((-t723 *
    t695 - t7738) * t114 + t7708 * param->s__l7x * t42) * t2244_tmp * t16 - t359
    * t8507) + t8510) + t8511) * t12 + ((tmpreturn_tmp_8 * t7263 - 2.0 * t118 *
    t2776) * t940 + t7948)) - t6918) * t346 / 2.0) - t8523) + (((((t1038 * t67 +
    t290 * t8528) * t114 + (t7701 + t8533) * t42) * tmpreturn_tmp * t16 + -t7396)
    + (t1038 * t8300 + t290 * -t8365) * t114) + t717) * t940 / 2.0) + (t7669_tmp
    * t8555 + t8561) * t16 * param->m__l7;
  t2578 = t589 * t106;
  t967 = (((((((((t2578 - t1185) + t586) + t725) + t484) + t489) + t491) + t496)
           + t504) - t505) + t2052;
  t497 = (((((t1369 * t38 - t1077) + t1378) + t1382) + t1384) - 2.0 * t645) *
    t106;
  t5959 = t1260 * t1230 * t940;
  t4928 = -4.0 * t672 * t39;
  t4933 = ((-2.0 * t61 + t3823) + t227) * t38;
  t672 = 2.0 * t2122;
  t5491 = t734 * t39;
  t5492 = ((((((((-2.0 * t330 * t248 + t127) - t140) - t144) + t145) + t152) +
             t154) + t643) - t744) * t38;
  t6378 = t1239 + t751_tmp;
  t734 = q__p[0] * t589;
  t6458 = t734 * t940;
  t5502 = -t38 * t789;
  t5748 = (t290 * t808 - 2.0 * t626) * t38;
  t5957 = 2.0 * t4324;
  t825 *= 2.0;
  t789 = t825 * t39;
  t6377 = (((((((t341 + t1850) + t660) - t354) + t276) - t356) * t114 + t335) *
           t290 - 4.0 * t840) * t38;
  t6510 = t3522 * t106;
  t2410 = ((tmpreturn_tmp_c + t4858) + t2415) * t114 - t174;
  t4858 = t209 / 2.0;
  tmpreturn_tmp_b = t42 * (-t194 / 2.0);
  t2422 = (((tmpreturn_tmp_b + t2422) + t2426) + t4858) * t114;
  t2402 = (((((-t228 + t2436) + t2440) + t2402) + t2441) + t684) + t243 / 2.0;
  t2426 = ((-t269 / 2.0 - t17) + t712) * t2;
  t2436 = t1839_tmp / 2.0;
  t278 = t1108 / 2.0;
  t209 = q__p[0] / 2.0;
  t2440 = (t514 + t278) - t209;
  t808 = t1182 * q__p[0];
  t744 = t589 * t940;
  t1077 = q__p[0] * t386;
  t269 = t420_tmp / 2.0;
  t6529 = ((-t481 * t38 - t2660) + t668) * q__p[0];
  t1382 = 4.0 * t411 * t39;
  t6543 = (((t4679 - t4681) + t3726) + t801) * q__p[0];
  t1289 = -t1289 * t42;
  t1185 = -t143 * param->m__l6;
  t143 = -t667 * t2;
  t667 = t290 * t1154;
  t968 = t4186 * q__p[0];
  t4186 = q__p[0] * t1230;
  t1384 = 4.0 * t3950;
  t1393 = 4.0 * t3965;
  t1369 = 2.0 * t1121;
  t1394 = 2.0 * t1123;
  t3950 = (((((-t4082 * t38 + t1239) + t2936) + t751_tmp) - t896) - t897) *
    q__p[0];
  t1850 = -2.0 * t4110 * param->m__l7;
  t1990 = -2.0 * t4113 * param->m__l6;
  t2122 = 2.0 * t4116;
  t2052 = 2.0 * t1059;
  t2660 = 2.0 * t1063;
  t1059 = t967 * q__p[0];
  t1063 = t3823 + t4413;
  t1123 = 2.0 * t2949;
  t840 = 2.0 * t2950;
  t896 = t1154 * q__p[0];
  t3113 *= t39;
  t897 = ((-t4345 - t4346) + t565) + t567;
  t3965 = t897 * q__p[0];
  t567 = t1337 - t1412;
  t1337 = t814 - t937;
  t1412 = (((((((((((((((((t688_tmp + t784) + t890) + t503) - t824) - t880) +
                      (t886_tmp + t885) * param->m__l4) + t889 * param->m__l3) +
                    t3326) - t3327) + t3328) + t3329) + t3330) - t3331) - t1663)
             + t413) + t1534) + t878) + t886;
  t725 = t114 * t39;
  t712 = (((-2.0 * t294 * t38 * t543 + t291 * t725) + t3916) + t957) * q__p[0];
  t885 = ((t38 * t6449 + t4024 * t440) + t3423) * q__p[0];
  t1045 = -t1045 * t2;
  t957 = (((((((((((((t4073 + t1663) + t880) + t824) + t878) + t784) - t3329) +
                t3330) + t1534) + t3331) + t3093) - t886) - t890) - t413) *
    q__p[3];
  tmpreturn_tmp_c = (((t1858 + t1861) + t1862) + t392) + t395;
  tmpreturn_tmp_9 = (-2.0 * t482 + 2.0 * t823) * t39;
  tmpreturn_tmp_a = (4.0 * t1689 - 4.0 * t542) * t39;
  tmpreturn[1] = (((((((((((((((((((((((((((((((((((((((((-t8 + t143) - t28) -
    t32) + t669) * t39 + t690 * t38) - t8) - t3019) - t97) + t715) + t716) -
    t101) + t669) * t106 + ((((((-t2423 * t42 + t188) * t2 + -t2421 * t3) -
    tmpreturn_tmp_b) - t4858) * t114 + ((((-t2407 - t122) * t39 + t667 * t49) +
    ((t533 + t4860) - t174 / 2.0) * t38) + t538)) + t221 / 2.0) * t105) + t968 *
    t940) + t2003) + (((((((-t552 - t228 / 2.0) + t554 * t3) + ((-t233 + t2437)
    - t2438) * t2) + t1141) + t2441) - t684) - t385 / 2.0) * t38) + t570) - t263
    / 2.0) - t8) + ((t572 / 2.0 - t666) + t22) * t2) + t576_tmp / 2.0) - t28) -
    t32) + t2458) + t669) + t282 / 2.0) - t579) * (4.0 * t440) * t12 +
    ((((((((((((((((((((((t24 - t347 / 2.0) * t2 + tmpreturn_tmp_3) + t1322) -
    t354 / 2.0) + t1511) - t3806) * t290 - t383) * t38 + ((t290 * -t822 + t331) *
    t39 + t732 * t744)) + ((((((((-t3819 * t42 - t380) * t2 + (-t2509 * t3 +
    -t366)) - tmpreturn_tmp_d) + t392 / 2.0) + t3826) + (-q__p[5] * t3828 +
    t3827) * param->m__l6) - t3832) - t3833) * t290) + t407) * t105 + ((((2.0 *
    t808 * t940 + t293 / 2.0) + (-t296 - t453) * t38) + t310 / 2.0) + t906) *
    t106) + t1077 * t940) + t417 / 2.0) + (((((((((t183 / 2.0 + -t426) - t431 /
    2.0) * t2 + (t418 / 2.0 + t420_tmp) * t3) + t435 / 2.0) + t438 / 2.0) - t269)
    - t442 / 2.0) * t114 - t449) * t290 + t304) * t38) + (((((((t466 / 2.0 +
    t2411) + t469 / 2.0) + t2415) * t42 + (t456 - 2.0 * t463)) - t473 / 2.0) -
    t475 / 2.0) * t114 + t517 / 2.0) * t290) + t525) * (-4.0 * t440) * t12 - 4.0
    * t290 * t2440 * t2578) + (((((((((((((((-4.0 * t304 * t543 + t1041) -
    ((t601_tmp + t377) + t53) * 4.0 * param->m__l7 * t697) + t1314) + 2.0 *
    t1608) - t5286) * t38 + t1382) + 4.0 * t316 * t543) + t457) - ((-t20_tmp *
    q__p[4] / 2.0 + t694) + t709) * 4.0 * param->s__l7x * t323_tmp) + t5303) -
    t1330) - t5304) - t5305) * t940 + 8.0 * t6529 * t1170) - 4.0 * t6529) * t105)
        - 4.0 * t6543 * t1170) + (((((((((((t3715 + t347) * t2 + -t3714) + t2277)
    + t354) - t276) + t356) * 2.0 * t114 + 4.0 * t617 * t290) * t38 +
    tmpreturn_tmp_9) - 2.0 * t625 * t290) + (((((((((t771 + t5071) * t2 + t767)
    + t1289) + t5077) - t749) + t1185) + t3941) + t1297) + t720) * t114) - t4631)
       * t940) + 2.0 * t6543) * t241 + ((((((((((((((((t38 * t2410 + t221) +
    t337) + t2422) * t105 + t6510) + t2397) + t2402 * t38) - t263) - t9) + t2426)
    + t2436) - t715) - t716) - t2458) + t35) + t282) * (-4.0 * t12 * t440) - 8.0
    * t1240 * t2440) * t288)) - 2.0 * t714 * t3895 * t106) + (((((((((((((-t1384
    - t3664) + 4.0 * t1096) - t2593) - 2.0 * t1100) * t38 + tmpreturn_tmp_a) +
    t1393) - 2.0 * t1118) + 2.0 * t1116) + 2.0 * t1119) + t1369) + t1394) * t940
    + 4.0 * t4186 * t1170) - 2.0 * t4186) * t105) + 4.0 * t3950 * t1170) +
    ((((((((((t42 * t4583 - t1072) * t2 + t1069) + ((2.0 * t4015 + 2.0 *
    t420_tmp) + 2.0 * t1733) * t42) + t1850) + t1990) + t4496) - t2122) * t290 +
       (-2.0 * t114 * t1718 + t6429) * t38) + ((((((2.0 * t1051 + t4121) * t2 +
    t3592) - t387 * t42) + 2.0 * t1057) - t2052) - t2660) * t114) + 2.0 * t1761)
    * t940) - 2.0 * t3950) * t346 / 2.0 + ((((((((((((((((((((((((((2.0 * t5959
    + t4928) + t4933) + t672) + t4426) + t262) * t105 + t497) + ((-t1233 + t1239)
    + t751_tmp) * (2.0 * t1260) * t940) + t5491) + t5492) + 2.0 * q__p[2] *
    t6378 * t290) + t2169) + t653) + t657) + t659) - t770) - t773) + t775) +
    t777) * t241 + -t967 * t204 * t288) + ((((-t6458 - t785) + t5502) + t792) -
    t793) * t106) + ((((2.0 * t1183 * t49 + t290 * t815) + t2235) + t5748) +
                     t5957) * t105) + t4191 * t940) + t789) + t6377) +
    ((((tmpreturn_tmp_c + t1865) - t402) - t404) * t114 + t848) * t290) + t893) *
    -t12 * t267) + (t1059 * t12 - (((((((((((((((t1853 * t38 + t1858) + t1861) +
    t1862) + t1865) + t3001) - t367) + t392) + t395) - t402) - t404) * t105 +
    t1876 * t38) + t1250) + t1884) + t3017) + t517) * t440) * t940 * t288) +
                       (((((((((((((((((((t2410 * t290 + t1374 / 2.0) + t972 /
    2.0) - t974 / 2.0) + t976 / 2.0) * t38 + t3113 / 2.0) + (t2422 + t221) *
    t290) - t1043) + (tmpreturn_tmp_1 / 2.0 + t1395 / 2.0) * t2) +
    tmpreturn_tmp_6 / 2.0) + t1401 / 2.0) - t1403 / 2.0) + t1406 / 2.0) * t940 +
    t896 * t1170) - t896 / 2.0) * t105 + t714 * t6510) + t3965 * t1170) +
    ((((((((((((((((-t263 - t9) + t2426) + t2436) - t715) - t716) + t35) + t282)
             - t2458) * t290 + ((((((-t3951 + t1429) - t3956) + t1431 / 2.0) *
    t114 + t2402 * t290) - t1105 / 2.0) * t38 + t567 * t39)) - tmpreturn_tmp_e /
           2.0) - t1132 / 2.0) - t1134 / 2.0) + t1136 / 2.0) + t1138 / 2.0) +
      t1140 / 2.0) + t1142 / 2.0) * t940) - t3965 / 2.0) * (4.0 * t440) +
                        (((((((((((((((4.0 * t39 * t671 + t38 * t1063) + t4426)
    + t4427) - 4.0 * t5959) * t105 + t497) - ((t290 * t6378 - t38 * t6356) +
    t858) * 4.0 * q__p[0] * t940) - tmpreturn_tmp_f) - t4824 * t38) + t2170) +
    2.0 * t2945) - 2.0 * t2948) + t1123) + t840) + t2185) + t4497) * t12) * t241
                       / 2.0) + ((((((((((((((((((t1798 - t3268) + t586) +
    param->I__l7xx) - t111) - param->I__l3yy) + t1767_tmp) + t1774) + t1780) +
    t1782) + t1787) - t1788) + t1791) + ((((((((((((t1794 + param->I__l4xx) -
    param->I__l6yy) - param->I__l7zz) - param->I__l5xx) + param->I__l5yy) +
    param->I__l6zz) - param->I__l2xx) + param->I__l2yy) + param->I__l3zz) -
    param->I__l4zz) + t108) - t588)) * 2.0 * q__p[0] * t940 + (((((((-t38 *
    t4517 - t3217) + t605) * 8.0 * q__p[0] * t940 + 2.0 * t291 * t805 * t39) +
    ((-t2241 + t4714) * t290 - t4589) * t38) + 2.0 * t1337 * t290) + t4599) *
    t105 + ((((t38 * t1546 + t4564) - 2.0 * t785) - 2.0 * t793) - 4.0 * t6458) *
    t106)) + t789) + (t4613 - t2036) * t38) + (t2576 + t4748) * t290) + 2.0 *
    q__p[2] * t1412) * t12 / 2.0) + (((((-t1460 * t38 + t1456) + t1117) + t309) *
    t940 + 4.0 * t1260 * t1182 * t1170) - 2.0 * t1260 * t1182) * t440 * t106) +
                    (((((((((((((((t994 / 2.0 - t3344) + t324) - t3345) - t3346)
    * t39 + (((t915 / 2.0 + -t361) * t290 + t336) + t211) * t38) + (t407 / 2.0 +
    t921 / 2.0) * t290) - t366) + t4620 / 2.0) + t4623 / 2.0) - t3933 / 2.0) -
    t3936 * param->m__l6 / 2.0) + t1492 / 2.0) - t3940 / 4.0) * t940 + t712 *
                      t1170) - t712 / 2.0) * (2.0 * t440) * t105) + 2.0 * t885 *
                   t1170) + (((((((((((((-t938 + t1045) + t946) + t948) + t1054)
    * t290 - (tmpreturn_tmp_g + t1733) * t114) * t38 + ((((-t1520 * t42 + t1519)
    - t4032) + t980) + t981) * t290) + (((((t145 + t4087) + t1714) + t201) * t42
    + (t456 - 2.0 * t4050)) + t4060) * t114) - t1544) + 2.0 * t4065) + t4067) +
    t4071) + t4078) + t957) * t440 * t940) - t885;
  t188 = -t258 + t260;
  t2593 = t188 * q__p[4];
  t3714 = ((((t71 - param->I__l6xx) + param->I__l6yy) - param->I__l7yy) +
           param->I__l7zz) * q__p[5];
  t3715 = ((t471_tmp - t3233) - t152) - t154;
  t53 = t3715 * t42;
  t296 = -t188 * q__p[4];
  t71 = t761 + t259;
  tmpreturn[8] = (((((((((((((((((((((((((((((((((((((((t467 + t2593) - t3714) *
    t290 + tmpreturn_tmp_h) - t408) * t105 + t319) - t417) + t455) + ((((t364 +
    t53) + t473) + t475) * t114 - t517) * t290) - t526) * t241 + t289) + t107) +
    t541) + t549) + t564) + t571) - t263) - t9) + t881) + t576_tmp) - t29) +
    t101) - t33) + t35) - t580) + t282) * t267 + ((((((((((((((((((((((t4928 +
    t4933) + t672) + t4426) + t262) * t105 + t497) + t5491) + t5492) - 2.0 *
    t3506 * t290) + t2169) + t653) + t657) + t659) - t770) + t775) +
    (((((((-t203 + param->I__l7xx) + t207) - param->I__l5xx) + param->I__l5yy) -
    param->I__l6yy) + param->I__l6zz) - param->I__l7zz) * q__p[4]) * t241 +
    -q__p[2] * t967 * t288) + (((-t785 + t5502) + t792) - t793) * t106) +
    (((((t815_tmp + t53) + t473) + t475) * t290 + (t2235 + t5748)) + t5957) *
    t105) + t789) + t6377) + (((tmpreturn_tmp_c + t296) + t3714) * t114 + t848) *
    t290) + t893) * t440 * t346) + t1839) + ((((((((((((((tmpreturn_tmp_i + t296)
    + t3714) * t290 + (((t1854 - t383) + t915) * t38 + (t1845 + t331) * t39)) +
    t407) + t921) * t105 + (((2.0 * t38 * t4996 + t293) + t310) + t906) * t106)
    + t417) + (((((t1877 - t938) + t1045) + t946) + t948) + t1054) * t38) +
    (((((((t1882_tmp + t3233) + t152) + t154) * t42 + t464) - t473) - t475) *
     t114 + t517) * t290) - t4032) - t100 * t5101 * param->s__l7y * t2) + ((-t16
    * t18 * t5101 - t1023) - t974) * t42) + t981) + t980) * t241) +
    (((((((-t1374 - t972) + t974) - t976) * t290 + t174) * t38 + 2.0 * t122 *
       t39) + (((((-t1048 * t71 + q__p[2] * -t188) + t1044) + t1397) + t1399) -
               t1401) * t290) - t221) * t105) + t1087) + (((t1433 + t1105) *
    t290 + t228) - t2227) * t38) + (((((((((-t1048 * t217 - q__p[2] * t474) +
    t1447) + t5103) - t5105) * t114 + t1132) + t1134) - t1136) - (((t855 + t856)
    + t506) + t566) * t695 * q__p[3]) - t1140) * t290) + t263) + t9) + t5344) +
                     t28) + t32) - t35) + t579) - t282;
  t3806 = 2.0 * t1038 * t2578;
  t3819 = t1183 * t1038;
  t3823 = 2.0 * t3486 * t440;
  t3826 = ((((((((((((((((((((t1853_tmp + t3004) + t660) - t2311) + t276) - t356)
    * t38 + t3001) - t367) + t1858) + t3010) + t1862) + t2357) + t395) + t1865)
                 - t402) - t404) * t105 + t1250) + t3017) + ((tmpreturn_tmp_j -
    t442) * t114 - t450) * t38) + (((tmpreturn_tmp_k + t1882) - t2284) - t475) *
            t114) + t517) * t440;
  t3827 = 8.0 * t499 * t106;
  t3832 = 4.0 * t4360 + 8.0 * t1189;
  t3833 = 4.0 * t4365;
  t3895 = 4.0 * t1039 * q__p[1];
  t526 = t4370 * t724 - t676;
  t3936 = 4.0 * t724 * t4379;
  t3951 = 4.0 * t1126;
  t3956 = 8.0 * t724 * t1182 * t440;
  t310 = 8.0 * t1596;
  t552 = t799 * t1740;
  t471_tmp = t724 * t360;
  t792 = t471_tmp * t42;
  t1544 = -4.0 * t5171 + 8.0 * t792;
  t793 = t609 * t290;
  t4015 = 4.0 * t793;
  t4024 = 4.0 * q__p[0] * t308 * t1740;
  t289 = t303 * t204;
  t263 = t289 * t543;
  t228 = t5973 * t940;
  t4067 = t228 / 2.0;
  t815_tmp = t2010 + t4067;
  t364 = ((((t815_tmp + t1648) + t608) + t613) + t618) * 4.0 * param->m__l7 *
    t697;
  t541 = t228 + t1484;
  t5957 = ((t541 + t452) + t495) + t428;
  t383 = 2.0 * t26 * t5957 * t16;
  t517 = t541 + t428;
  t407 = 2.0 * t77 * t517;
  t337 = 2.0 * t5973 * t214 * t940;
  t408 = (((t337 + t5300) + t5301) + t3235) * t42;
  t293 = 2.0 * t217 * t228;
  t361 = -q__p[0] * t245 - t248 * t433;
  t4050 = 4.0 * t361;
  t4060 = 4.0 * t772 * t290;
  t4065 = 4.0 * t724 * t524;
  t3664 = t1724 * t290;
  t2277 = t204 * t448;
  t1116 = t51 + t4067;
  t455 = (((t1116 + t1648) + t618) * t6664_tmp * param->m__l7 + t771) * t2;
  t324 = param->s__l7x * t517;
  t309 = 2.0 * t324 * t54;
  t4346 = t695 * t940;
  t4071 = t71 * q__p[0] * t4346;
  t4078 = 2.0 * t4071;
  t71 = t204 * t695;
  t4087 = t290 * t3522 * t440;
  t4121 = 2.0 * t3113;
  t3950 = (t1035 - t1371) * t290;
  t4933 = q__p[0] * t20_tmp * t940;
  t387 = t4933 + t965;
  t2936 = t387 + t966;
  t449 = t2936 * param->s__l7y;
  t580 = t449 * t323_tmp;
  t463 = param->s__l7x * t2936;
  t659 = t463 * t54;
  t5491 = 2.0 * t659;
  t467 = t93 * q__p[0] * t78 * t940;
  t3965 = (t1079 + t1387) * t290;
  t367 = t42 * t204;
  t1648 = t76 * t367 * t3;
  t770 = 4.0 * t1648;
  t1371 = t204 * t14;
  t1387 = t1371 * t16;
  t761 = -t1387 + t942;
  t207 = q__p[0] * t168_tmp * t940;
  t5492 = (t207 + t1022) + t1048;
  t5502 = param->s__l7y * t5492;
  t6429 = t5502 * param->m__l7;
  t456 = t80 * q__p[0];
  t417 = t456 * t940;
  t466 = ((-t946 + t417) + t948) + t952;
  t6449 = t5492 * param->s__l7x;
  t785 = t6449 * t54;
  t469 = 2.0 * t188 * q__p[0] * t940;
  t4116 = 2.0 * t433 * t589;
  t4113 = t984 * t290;
  t497 = ((((((-t1417 * t3 - t575) - t1416) + t1423) + t1424) + t230) + t562) *
    t290;
  t554 = 2.0 * t367 * t108;
  t562 = t169_tmp * t367;
  t533 = (t562 + t207 / 2.0) + t1092;
  t893 = (t533 + t1093) * (4.0 * t18) * t2;
  t915 = 2.0 * t204 * t72 * t42;
  t938 = 2.0 * t5492 * t171;
  t4110 = ((((((((-t2 * t3681 - t102) + t1269) - t1436) - t1437) + t1443) - t29)
            - t33) + t4222) * t290;
  t1269 = t387 - t966;
  t984 = param->m__l7 * t1269;
  t972 = t984 * t697;
  t464 = t5492 * t214;
  t572 = t464 * t42;
  t575 = t26 * t1269 * t16;
  t1436 = q__p[0] * t474 * t940;
  t1437 = t386 * q__p[1];
  t4186 = 2.0 * t1437;
  t2578 *= 2.0 * t724;
  t319 = t245 * t732;
  t366 = t69 + t319;
  t4345 = 4.0 * t366;
  t4533 *= 4.0;
  t402 = t200 * t1740;
  t474 = 4.0 * t402;
  t579 = 8.0 * t3397;
  t4537 = -t579 - 4.0 * t4537;
  t4583 = 4.0 * t4550;
  t4589 = 2.0 * t724 * t108;
  t4599 = 4.0 * t868 * t12 * q__p[0] * t698;
  t4613 = 4.0 * t724 * t490;
  t490 = (((((((((((((((t876_tmp + t334) - t505) - t508) + param->I__l7yy) +
                    t876) - param->I__l7zz) + t879) - param->I__l6yy) +
                param->I__l6xx) - param->I__l5xx) + t891) + param->I__l3xx) -
            param->I__l3yy) + param->I__l4yy) - param->I__l4zz) + param->I__l5zz;
  t4623 = 2.0 * q__p[0] * t490 * t12;
  t4748 = q__p[1] * param->m__l3 * t578;
  t4824 = 4.0 * t4748;
  t5300 = t1038 * t589;
  t450 = t724 * t248;
  t549 = t450 - t677;
  t5171 = 4.0 * t549;
  t980 = t261 * t12;
  t404 = t1260 * t980;
  t4996 = 4.0 * t404;
  t1443 = 4.0 * t1689 - 4.0 * t56;
  t570 = (-t207 + t1047) + t1048;
  t625 = 2.0 * t1436;
  t334 = t471_tmp * t290;
  t426 = 8.0 * t334;
  t435 = t724 * t550 * t290;
  t5103 = -4.0 * t435 - 8.0 * t2917;
  t5105 = 4.0 * t724 * t4185;
  t5071 = 2.0 * t4459 * t3;
  t5077 = 4.0 * t3303 * t7265 * t2;
  t4858 = 4.0 * t6473 * t1133;
  t5286 = 4.0 * t724 * t1540;
  t5303 = 2.0 * t490 * q__p[1];
  t617 = t984 * t94;
  t666 = -t18 * t71 - t183;
  t377 = 2.0 * t666;
  t952 = t26 * t71 * t16;
  t1047 = t77 * t228;
  t1416 = (((t854 + t855) + t566) + t856) + t506;
  t296 = 2.0 * t5973 * t1416 * t940;
  t380 = t1387 + t942;
  t671 = 2.0 * t380;
  t490 = t289 * t290;
  t1458 = -4.0 * t490 - 4.0 * t1458;
  t855 = t315 * t204;
  t876 = t855 * t290;
  t984 = 4.0 * t876;
  t879 = t1724 * t543;
  t1322 = t56 * t1226;
  t578 = 4.0 * t1322;
  t942 = t541 + t52;
  t6377 = t942 * param->s__l7y;
  t6378 = param->s__l7x * t942;
  t881 = 4.0 * t319;
  t942 = param->s__l7y * t204;
  t876_tmp = t18 * t942;
  t541 = t876_tmp * t3;
  t564 = (((((-t2 * t671 + 2.0 * t1054) + t4000) + t717) + 2.0 * t417) - 4.0 *
          t541) * t290;
  t387 = t979 * q__p[0];
  t3017 = t1029 - t337;
  t1417 = (((t3017 + t6427) + t4594) + t806) * t42;
  t889 = 2.0 * t217 * t71;
  t588 = -t4540 * t39;
  t891 = 4.0 * t724 * t294;
  t53 = t509 - t891;
  t1540 = t53 * t38;
  t4928 = q__p[0] * t1412 * t12;
  tmpreturn_tmp_1 = t39 * (-t310 - 4.0 * t552);
  tmpreturn_tmp_6 = t39 * (4.0 * t729 + -t426);
  tmpreturn_tmp_e = t39 * (t5571 - 4.0 * t3115);
  tmpreturn_tmp_h = 4.0 * t526 * t38;
  tmpreturn_tmp_i = t4537 * t39;
  tmpreturn_tmp_3 = (8.0 * t724 * t839 - 4.0 * t3412) * t38;
  tmpreturn_tmp_c = t38 * (-t995 - t881);
  tmpreturn_tmp_f = (-2.0 * t3664 + 2.0 * t823) * t39;
  tmpreturn[15] = ((((((((((((((((((((((((((((((((((((-4.0 * t263 + t1041) -
    t364) + t1314) + t383) - t407) * t38 + ((((t38 * t1544 + tmpreturn_tmp_1) +
    t4015) - t4024) * t440 + t1382)) + 4.0 * t523 * t3887) + t457) - t1187) +
    t408) - t573) - t293) - t5304) - t5305) * t105 + (-2.0 * t415 * t589 - t3956)
    * t106) + ((t38 * t4050 - t4060) - t4065) * t440) + tmpreturn_tmp_f) + (4.0 *
    t290 * t2277 + 2.0 * t3721) * t38) - 2.0 * t204 * t516 * t290) +
    (((((((((t767 + t455) + t1289) + t309) + t4078) - t749) + t1185) + t3941) +
      t1297) + t720) * t114) - 2.0 * t281 * t71) * t346 + (((((((t38 * t3832 +
    tmpreturn_tmp_e) - t3833) - t3895) * t105 + -t3827) + tmpreturn_tmp_h) +
    t3936) - t3951) * t267) + (4.0 * t4087 + 4.0 * t499) * t106) +
    (((((((((((((((2.0 * t580 + t3950) + t5491) + 2.0 * t467) - t3584) + t3585) *
    t38 + t4121) + t3965) - t770) + (2.0 * t42 * t761 + 2.0 * t6429) * t2) + 2.0
          * t466 * t42) + 2.0 * t785) + t469) - t3601) + t3602) * t440 + t4116) *
    t105) + (((((((((((((((-t554 + t893) - t915) + t938) * t114 + t497) - t3675)
    * t38 + (-4.0 * t120 * t523 + t4113) * t39) + t4110) + (((((-2.0 * t972 -
    2.0 * t572) + 2.0 * t575) + 2.0 * t1436) + 2.0 * t1121) + 2.0 * t1451) *
    t114) - t3696) - t3697) + 2.0 * t566 * q__p[0] * t522 * t940) + t2413) +
               t3699) + t3701) + t3700) * t440) + t4186) * t241 / 2.0 +
    ((((((-4.0 * t1230 * t204 + 4.0 * t3819) * t105 + -t3806) - t3823) + 4.0 *
       t204 * t1363) * t346 + 2.0 * t724 * t967 * t267) - 2.0 * t3826) * t288 /
    2.0) + (((((((((((t38 * t4345 + t4533) - t474) * t105 + t2578) +
                   tmpreturn_tmp_i) + tmpreturn_tmp_3) + t4583) + t4589) - t4599)
              - t4613) - t4623) - t4824) * t267 / 2.0) + ((((((((((((((((((t533
    - t1093) * tmpreturn_tmp_2 * t697 + (-t1384 - t554)) - t915) - 2.0 * t171 *
    t570) * t38 + (((t38 * t5171 + t706) + t4996) * t440 + t1443 * t39)) + t1393)
    - 2.0 * t463 * t323_tmp) + 2.0 * t570 * t214 * t42) + 2.0 * t449 * t54) +
    t625) + t1369) + t1394) * t105 + (-2.0 * t5300 - 2.0 * t3896) * t106) +
    (((((((t38 * t5103 + tmpreturn_tmp_6) + t5105) - t5071) + t5077) + t4858) -
      t5286) + t5303) * t440) + (((((t943 - t337) + t6427) + t4594) + t806) *
    t290 - ((((t2 * t26 * t1269 + t1023) + t467) + t617) + t974) * (2.0 * t114))
    * t38) + (((((((((2.0 * t952 - 2.0 * t1047) + 2.0 * t420_tmp) + 2.0 * t1733)
                   * t42 + ((t42 * t377 - t1072) * t2 + t1069)) + t296) + t1850)
                + t1990) + t4496) - t2122) * t290) + (((((((2.0 * t26 * t570 +
    t42 * t671) * t2 + t770) + (((-2.0 * t946 - 2.0 * t417) - 2.0 * t948) - 2.0 *
    t1054) * t42) + t126 * t570 * t54) - t469) - t2052) - t2660) * t114) - 2.0 *
    t204 * -t898) * t346 / 2.0) + ((((t38 * t1458 + t3881) + t3891) + t984) *
    t440 - 2.0 * t724 * t589) * t106 / 2.0) + (((((((((((((((((2.0 * t879 - t321)
    + t325) - t326) - t327) * t39 + (((-t578 + t3910) * t290 + t1258) + t70) *
    t38) + (2.0 * t114 * t204 * t308 + 2.0 * t921) * t290) - t1277) + 2.0 *
    t6377 * t323_tmp) + 2.0 * t6378 * t54) + t4078) - t3934) + t4626) + t3941) -
    t3940) * t440 + tmpreturn_tmp_c) - t996) + t474) * t105 / 2.0) +
                       ((((((((((((((-t4033 - tmpreturn_tmp_l * t1269 * t2) +
    (((-2.0 * t617 - 2.0 * t467) - 2.0 * t974) - 2.0 * t1023) * t42) + 2.0 *
    t387 * t940) + 2.0 * t979 * q__p[2]) + t4044) * t290 + (t564 - (((((t2 *
    t666 + t1733) - t4010) + t420_tmp) + t952) - t1047) * (2.0 * t114)) * t38) +
    (((t457 - t762) + t1417) + t889) * t114) - t1017) + t758) + 2.0 * q__p[0] *
    t1158 * t940) + t4068) + t4072) + (((2.0 * t522 * param->m__l4 + 2.0 * t1152)
    * param->l__2 + 2.0 * t1155) + 2.0 * t1157) * q__p[2]) + 2.0 * t957) * t440 /
                       2.0) + t588 / 2.0) + t1540 / 2.0) - t4550) + t4928) +
    t4748;
  t898 = t346 * t120;
  t2311 = 8.0 * t724 * t898 * t39;
  t770 = t1014 * t204;
  t2357 = 4.0 * t3530 * t4266 - 4.0 * t770;
  t2397 = 4.0 * t724 * t220 * t346;
  t2407 = 4.0 * t855 * t114;
  t2411 = 4.0 * t724 * t877 * t346;
  t570 = (t346 + 1.0) * (t346 - 1.0);
  t2415 = t3530 * t471;
  t2421 = 4.0 * t2554 * t294 * t346;
  t715 = t12 * t693;
  t2423 = 2.0 * t715 * t1260 * t346;
  t921 = t56 * t290;
  t2437 = 8.0 * t921;
  t1990 = t724 * t3611;
  t3701 = 2.0 * t614;
  t3611 = -4.0 * t1990 + t3701;
  t1155 = t204 * t173;
  t2438 = 4.0 * t1155 * t290;
  t3115 = 2.0 * t918;
  t1157 = t220 * t204;
  t3584 = 4.0 * t1157 * t290;
  t3585 = t724 * t291;
  t3601 = 4.0 * t2695 * t724 - t2586;
  t981 = t1232 * t415;
  t3602 = 4.0 * t981;
  t3001 = 4.0 * t204 * t877 * t290;
  t3522 = (t228 + t452) + t495;
  t617 = t3522 + t1484;
  t666 = t617 * param->s__l7y;
  t3004 = (t346 + 1.0) * t290;
  t979 = t1014 * t338;
  t3010 = 4.0 * t979;
  t1092 = t724 * t226;
  t1093 = 2.0 * t1092;
  t671 = t699 * t346;
  t773 = t7139 * t6895;
  t815 = t147 * t695;
  t449 = (t773 + t815) * param->m__l7 * t2;
  t3675 = 2.0 * t449;
  t716 = q__p[0] * t95 * t12;
  t3019 = 2.0 * t716;
  t1044 = t696 * t171;
  t3696 = 2.0 * t1044;
  t3697 = 4.0 * t704 * t543;
  t1158 = 2.0 * t3588 * t12;
  t918 = t724 * t42;
  t3699 = 4.0 * t918 * t299;
  t3700 = 2.0 * t724 * t1235;
  t690 = t456 * t12;
  t5748 = (-t256 + t258) - t260;
  t3721 = 2.0 * q__p[0] * t5748 * t12;
  t3881 = 2.0 * t217 * t696;
  t1235 = 2.0 * t471_tmp;
  t3891 = 2.0 * t570 * (t730 - t1235) * t39;
  t3233 = 4.0 * t2695 * q__p[1];
  t3217 = 2.0 * t4266 * t732;
  t3268 = t3233 + t3217;
  t858 = q__p[1] * t4273 * t290;
  t4010 = t12 * t568 * q__p[0];
  t456 = t8212 * t6895;
  t463 = t987 * t695;
  t6510 = t456 + t463;
  t5959 = t141_tmp + t219;
  t4620 = param->s__l4y * q__p[0];
  t4044 = (param->s__l4x * q__p[1] * t695 + t12 * t522 * t4620) * (2.0 *
    param->m__l4);
  t3344 = t3882 * t1199;
  t568 = t294 * t204;
  t3345 = 4.0 * t3887 * t1199;
  t6427 = t204 * t693;
  t777 = t724 * t120;
  t469 = 4.0 * t777;
  t3346 = t2763 - t469;
  t4266 = -2.0 * q__p[0] * t4266 - t2778;
  t533 = 2.0 * t952;
  t1733 = 2.0 * t1047;
  t1121 = t676 * t290;
  t730 = -2.0 * t1232 * t724 + 2.0 * t1121;
  t259 = (t151 - t259) * q__p[0] * t4346;
  t952 = 2.0 * t259;
  t4000 = 2.0 * t281 * t228;
  t2426 = (((((((((((((t4494 + t4073) + t3093) - t3329) + t3330) + t3331) +
                  t1663) - t413) + t1534) + t878) + t880) - t886) - t890) + t784)
    + t824;
  t2778 = t670 * t346 * t39;
  t3423 = 4.0 * t2778;
  t3113 = 4.0 * t724 * t3882 * t267;
  t4411 *= t346;
  t2763 = t724 * t3882;
  t3326 = 4.0 * t2763;
  t1596 = 4.0 * t471 * t200;
  t3327 = t1596 * t267;
  t4425 *= t346;
  t1269 = t724 * t148 * t290;
  t2122 = 2.0 * t1269;
  t2052 = -t2122 - t802;
  t151 = t114 * t346;
  t2660 = 2.0 * t113 * t151;
  t1436 = t724 * t114 * t3355;
  t2402 = 4.0 * t1436;
  t2422 = t2402 - t811;
  t4860 *= 4.0;
  t113 = t715 * t1346;
  t2440 = 2.0 * t113;
  t2413 = -2.0 * t2763 - 2.0 * t615;
  t2410 = (-t156 - t47) * t3;
  t4185 = ((t557 - t1419) + t1420) * t2;
  t3681 = 2.0 * t4893;
  t2586 = t76 * q__p[0] * t3 * t12;
  t1420 = t14 * q__p[0];
  t715 = t6949 * t1420 * t2;
  t4626 = 2.0 * t4918;
  t4921 = 2.0 * t4921 * t42;
  t6543 = -t773 + t815;
  t4459 = 2.0 * t100 * t6543 * t2;
  t3486 = -2.0 * t716 + 2.0 * t1044;
  t3506 = 2.0 * t387 * t12;
  t3592 = 2.0 * t696 * t1416;
  tmpreturn_tmp_j = (4.0 * t668 * t724 + t3115) * t346;
  tmpreturn_tmp_k = t267 * (-t3010 - t1093);
  tmpreturn_tmp_d = (t3697 - t1158) * t267;
  tmpreturn_tmp_g = (2.0 * t690 - 2.0 * t833) * t42;
  tmpreturn_tmp_l = (((t2244_tmp * t2 * t6510 + 2.0 * t12 * q__p[0] * t5959) +
                      2.0 * t1582 * q__p[1] * t695) - 2.0 * t216 * t724) * t114;
  tmpreturn_tmp_b = (4.0 * t1232 * t346 * t724 + 4.0 * t2277) * t38;
  t1767_tmp = (2.0 * t220 * t724 + 2.0 * t800 * t543) * t346;
  t886_tmp = (-2.0 * t113 + 2.0 * t609) * t267;
  t1511 = (2.0 * t1126 * t290 - 2.0 * t877 * t724) * t346;
  t1853_tmp = (((-4.0 * t2586 - 2.0 * t715) + 2.0 * t690) + t834) * t290;
  t1882_tmp = (-2.0 * t1871 * t724 - 2.0 * t772) * t267 / 2.0;
  t217 = -2.0 * param->s__l7x;
  tmpreturn[22] = (((((((((((((((((((((((((((((((((((((((((((((t2421 + t1026) -
    t1027) - t1028) + t1029) + t1031) + t1032) + t1033) * t38 + -2.0 * t112 *
    (t2415 - q__p[4]) * t39) - t2423) + t1069) + t1074) + t1076) + t781) * t106
    + ((((((((t346 * t3611 - t4413) + t4797) - t2438) * t38 + (-t2437 - t860) *
    t39) + tmpreturn_tmp_j) + t3584) + t4807) - t4427) * t105) + (((-2.0 * t3585
    - t1179) * t346 + t2143) - t1603) * t39) + (((((((((-param->m__l7 * t4449 +
    t346 * t3601) + t1028) - t127) + t2155) - t3235) + t4447) - t4452) - t337) -
    t3602) * t38) + (2.0 * t290 * t4273 * t724 + 2.0 * t780) * t346) - t3001) -
    t2170) - 2.0 * t429 * t617 * param->m__l7 * t2) + (2.0 * t54 * t666 - 2.0 *
    t77 * t71) * t42) + t296) + (((-4.0 * param->l__6 * t530 - 2.0 * q__p[4] *
    (param->s__l7z * param->s__l7z)) - 2.0 * q__p[4] * (param->l__6 *
    param->l__6)) + 2.0 * t1738) * param->m__l7) - tmpreturn_tmp_0) + t4496) -
    t2185) - t4497) * t440 - 2.0 * t3004 * (t346 - 1.0) * t4653 * t106) +
    (((((((((((((tmpreturn_tmp_k - 2.0 * t914 * t671) + t3010) + t3675) + t3019)
    + t3696) * t38 + tmpreturn_tmp_d) + 2.0 * t4526 * q__p[3] * t695 * t346) -
    t3697) - t3699) - t3700) + tmpreturn_tmp_g) - t3721) + t3881) * t105) -
    t3891) + (((2.0 * t941 * t671 + t267 * t3268) - t3233) - t3217) * t38) +
    (2.0 * t858 - 2.0 * t4010) * t267) - 2.0 * t4772 * t695 * t346) - 2.0 * t858)
    + tmpreturn_tmp_l) + t4044) * t241 / 2.0 + (((((((((t38 * t2357 + t2311) -
    t2397) + t2407) * t105 + -t1452) - t842) + tmpreturn_tmp_b) + t2411) + 2.0 *
    t204 * t4273) * t440 + 4.0 * t570 * t4231 * q__p[1]) * t288 / 2.0) +
    ((((((((((((((((((-t2 * t377 - t533) + t1733) + t2241) - t257) + t1709) -
    t3024) * t290 + t4266 * t346) + 4.0 * t770) * t38 + (t3346 * t346 - t4572) *
              t39) + t1767_tmp) + ((((-t2268 + t457) - t762) + t1417) + t889) *
            t290) - t2407) * t105 + ((((((-4.0 * t3344 + 4.0 * t786) - 4.0 *
    t568) * t38 + t842) + t3345) - t4564) + 2.0 * t6427) * t106) + 2.0 * t332 *
         t725) + (t730 * t346 - (t335 / 2.0 + t2702) * (4.0 * t290)) * t38) +
       t1511) + (((((((((((t217 * t54 * t617 - 2.0 * t323_tmp * t666) + t952) +
    t3934) + t3938) + t3940) - t3941) * t114 + t4629) + t4630) + t4000) + t4631)
                 - t4632) * t290) + 2.0 * t204 * t2426) * t440 / 2.0) +
    ((((((t3113 + t4411) - t3326) * t38 + t3423) - t3327) + t4425) + t1596) *
    t106 / 2.0) + (((((((((2.0 * t4857 - t4860) * t346 + t2422 * t267) - t2402)
                        + t811) * t38 + (((t2052 * t267 + t2122) + t2660) + t802)
                       * t39) + t886_tmp) + (2.0 * t4874 + 2.0 * t4876) * t346)
                    + t2440) - t818) * t105 / 2.0) - 2.0 * t2778) + (((((((((2.0
    * t4888 + t2410) + t4185) + t1345) - t1423) + t230) + t3681) * t346 + t2413 *
    t267) + t1853_tmp) + t837) * t38 / 2.0) + t1882_tmp) + (((((-2.0 * t4913 -
    t4626) + t4921) + t29) + t33) - t102) * t346 / 2.0) + (((t3486 * t42 + t4459)
    + t3506) - t3592) * t290 / 2.0) + t772;
  t815 = (((((((-t38 * t4503 - tmpreturn_tmp_4) - t2195) - t2198) * t106 + t1178
             * t105 * t114) + t1181) + t312) + t313) + t314;
  t2198 = t991 * t346;
  t2268 = 2.0 * t729 * t725;
  t1738 = t226 * t204;
  t2195 = t204 * t261;
  t3355 = 2.0 * t2195 * t440;
  t1416 = 2.0 * t2189 * t114;
  t1417 = 4.0 * t523 * t1012 * t39;
  t2665 *= 2.0 * t523;
  t2778 = 2.0 * t704;
  t6557 = q__p[0] * t106;
  t2763 = 8.0 * t319 + t995;
  t3329 = 8.0 * t402;
  t6529 = -t53 * t38;
  t3331 = 2.0 * t338 * t565;
  t773 = t12 * t2625;
  t71 = 2.0 * t773 * q__p[0];
  t6458 = t56 * t39;
  t319 = -8.0 * t677 + 2.0 * t450;
  t402 = 8.0 * t705 + 2.0 * t404;
  t858 = 2.0 * t334;
  t404 = 2.0 * t440 * (-t858 + t729) * t39;
  t450 = -2.0 * t435 - t1681;
  t6556 = t12 * t220;
  t704 = t724 - t665;
  t387 = 2.0 * t704 * t112 * t39;
  t1393 = param->m__l7 * t204;
  t4888 = t1393 * t3;
  t943 = t8417 * t4888;
  t4631 = t301 * t415;
  t4874 = t204 * t80;
  t113 = t4874 * t290;
  t3330 = 4.0 * t113;
  t1087 = 4.0 * t447 * q__p[3];
  t957 = (((4.0 * t4631 + 4.0 * t7367) * t2 + 8.0 * t943) - t3330) - t1087;
  t77 = t20_tmp * t204;
  t53 = t446 * t77;
  t4526 = t313 + t314;
  t1134 = t204 * t4526 * t290;
  t4564 = 4.0 * t1134;
  t4572 = (((((((t199 + t203) + t1177) + param->I__l5xx) - param->I__l5yy) +
             param->I__l6yy) - param->I__l6zz) - param->I__l7xx) +
    param->I__l7zz;
  t1136 = ((t1017 - t6664_tmp * (-t53 + t2598) * t323_tmp) + t4564) - 2.0 *
    q__p[3] * t4572;
  t1181 = t5 * t5585 * param->m__l7;
  t1057 = 8.0 * t1181;
  t4857 = t2149 * t204;
  t313 = t7386 * t4857;
  t834 = t301 * q__p[3];
  t712 = 4.0 * t313 - 4.0 * t834;
  t435 = 4.0 * t141_tmp * t204 * t446;
  t885 = 4.0 * t6284;
  t203 = t290 * t14;
  t889 = 2.0 * t203 * t204 * t3;
  t4913 = t204 * t16;
  t1177 = t7402 * t4913;
  t1118 = t6664_tmp * (t1177 + t3210) * t323_tmp;
  t334 = 2.0 * t204 * t4572 * t290;
  t1250 = t4526 * q__p[3];
  t1119 = 4.0 * t1250;
  t557 = 2.0 * t113;
  t113 = t7817 * t42;
  t770 = 2.0 * t12 * t2108 * q__p[0];
  t570 = 4.0 * t4355 + -t4357;
  t666 = 2.0 * t4365;
  t671 = 2.0 * t526;
  t1140 = t980 * t114;
  t716 = 2.0 * t1260 * t1140;
  t199 = t204 * t39;
  t1044 = t291 * t199;
  t4653 = 2.0 * t1044;
  t1043 = -2.0 * t552 - t1597;
  t4772 = 4.0 * t411;
  t1045 = 4.0 * t792 - t5172;
  t1096 = 2.0 * t773 * t732 + 2.0 * t793;
  t773 = t823 * t39;
  t1100 = 2.0 * t361;
  t1132 = (((((((((t4505 + t3093) + t1663) - t413) + t1534) + t878) + t880) -
             t886) - t890) + t784) + t824;
  t1051 = t1132 * t204 * t290;
  t1233 = 2.0 * t338 * t2819;
  t1374 = ((((t9 + t5344) + t28) + t32) - t35) * t290;
  t1330 = t338 * t2842;
  tmpreturn_tmp_0 = t402 * t440;
  tmpreturn_tmp_4 = (2.0 * t1738 * t440 - t4362) * t38;
  t402 = (2.0 * t4360 + t4362) * t38;
  t617 = t1096 * t440;
  t786 = (-2.0 * t598 * t1155 + 2.0 * t676) * t38;
  t1096 = (2.0 * t6556 * t114 * t1260 - 2.0 * t2189) * t440;
  t1839_tmp = (-2.0 * t261 * t290 * t433 + 2.0 * t12 * t200) * t440;
  tmpreturn[29] = ((((((((((((((((((((((((((((((((t319 * t440 + t554) - t893) +
    t915) - t938) * t38 + 4.0 * t6458) + tmpreturn_tmp_0) + 2.0 * t972) + 2.0 *
    t572) - 2.0 * t575) - t625) - t1369) - 2.0 * t1451) * t105 + 4.0 * t1178 *
    q__p[1] * t592) + t404) + (((((t580 + t659) + t467) - t974) + t976) * 2.0 *
    t114 + t450 * t440) * t38) + t1096) + (((((((t42 * t761 + t6429) * t2 + -2.0
    * t1648) + t466 * t42) + t785) - -t188 * q__p[0] * t940) - t1403) + t1406) *
    (2.0 * t114)) * t346 + (((((((t2763 * t38 - t3329) + t996) * t105 + -4.0 *
    t3325 * t6557) + t1747) + t6529) + t3331) + t71) * t267) + ((((t957 * t440 +
    t891) * t38 + -t387) + t1136 * t440) + t71) * t106) + (((((((((((((((t712 *
    t2 - t1057) - t435) + t885) * t114 - t341) + t5208) + t353) + t596) - t1273)
    + t1274) * t440 - t881) - t995) * t38 + ((((t879 + t320) - t821) + t63) +
    t73) * 2.0 * t440 * t39) + (((((((((((((t889 - t1118) - t334) - t1119) *
    t114 + t767) + t455) + t1289) + t309) - t952) - t749) + t1185) + t3941) +
    t1297) + t720) * t440) + t474) - t996) * t105) + ((-t1303 * t440 + t4538) +
    t4539) * t39) + ((((((((((-t1041 + t364) - t1314) - t383) + t407) * t114 -
    4.0 * t943) + (-2.0 * t4631 - 4.0 * t7367) * t2) + t557) + t1087) * t440 +
                      t509) - t891) * t38) + (((((((((((-t5299 * param->m__l7 -
    t3235) - t5301) - t337) * t42 + t2145) + t573) + t293) + t5304) + t5305) *
    t114 - 2.0 * t113 * t1393 * t116) - 2.0 * t1134) - t5310) * t440) - t3331) +
    t770) * t241 / 2.0 + (((((((2.0 * t815 * q__p[1] * t267 + 2.0 * t815 * t12 *
    t2198) - t4354) + (((tmpreturn_tmp_4 + t2268) + t3355) - t1416) * t105) -
    t1417) + t786) + t2665) - t2778) * t288 / 2.0) + (((((((t570 * t39 + t402) +
    t1416) - t666) * t105 + t4354) + t671 * t38) + t716) + t2778) * t267 / 2.0)
                       + ((((((((((((((((((((((((((t957 * t114 + t1045 * t440) +
    t1314) + t1041) - t364) + t383) - t407) * t38 + ((t1043 * t440 + t4772) +
    t1347) * t39) + t617) + t1136 * t114) + t457) - (-t8548 / 2.0 + t3226 *
    param->s__l7x) * 4.0 * param->m__l7 * t2) - 2.0 * t695 * t1582 * t295) +
    t408) - t573) - t293) - t5304) - t5305) * t105 + ((((((((((-t712 * t2 +
    t1057) + t435) - t885) + 4.0 * t1091) * t38 + -t4653) - t4693) - t889) +
    t1118) + t334) + t1119) * t106) + 2.0 * t773) + ((((((((((2.0 * t31 * t290 *
    t973 + t593) + t344) * t2 + -t341) + 2.0 * t914 * t171 * t290) + t353) +
    t596) - t1273) + t1274) * t114 + t1100 * t440) + t753) * t38) + t1839_tmp) +
    ((((((((((2.0 * t2659 * t295 - t952) + t1297) + t767) + t720) - t749) +
         t3941) + t1289) + t1185) + t455) + t309) * t114) + t889) - (t3210 / 2.0
    + t1177) * 4.0 * param->s__l7y * t323_tmp) - 2.0 * t1051) - 2.0 * t1250) *
                       t346 / 2.0) + ((t2711 * t290 * q__p[1] + t38 * t4855 *
    t440) + t2250 * t440) * t695 * t105) + 2.0 * t3100) + ((2.0 * t5363 + 2.0 *
    t2483) * t440 - t1233) * t38 / 2.0) + (2.0 * t5370 - 2.0 * t1374) * t440 /
                   2.0) - t1330;
  t188 = t595 * t106;
  t761 = t1049 * t204;
  t8417 = t440 * t105;
  t592 = t761 * t8417;
  t466 = t3185 * t290;
  t552 = t5546 * t471;
  t5363 = 2.0 * t1210;
  t914 = (t552 - t5363) * t440;
  t572 = 4.0 * t415 * t1012;
  t973 = t572 * t106;
  t893 = t1049 * q__p[4];
  t976 = -t2143 - 2.0 * t893;
  t1403 = 4.0 * t466;
  t1406 = 4.0 * t471_tmp;
  t2819 = t2911 * t2554;
  t1451 = 4.0 * t2819;
  t1597 = 8.0 * t595;
  t116 = t1055 - q__p[3];
  t2143 = 4.0 * t5626 + 8.0 * t777;
  t2659 = 2.0 * t893 * t114;
  t792 = t5694 * t114;
  t2711 = (t792 - t798) * 2.0 * t290 * t440;
  t2819 *= 2.0;
  t309 = ((t105 * t1232 - t106 * t5658) + t112 * t42) - t2266;
  t798 = t791 * t346;
  t3938 = q__p[1] * t106;
  t793 = 2.0 * t5658 * t3938;
  t3100 = t204 * t5710 * t440;
  t5710 = t204 * t440;
  t3226 = 2.0 * t1014 * t5710;
  t3093 = t5860 * q__p[1];
  t364 = 2.0 * t3093;
  t785 = t226 * t106;
  t915 = t2911 * t724;
  t383 = 4.0 * t915 + -t310;
  t455 = t290 * t214;
  t407 = 2.0 * t455 * t6473;
  t408 = -t5571 - 4.0 * t5572;
  t455 = 2.0 * t724 * t455 * t168_tmp;
  t580 = 2.0 * t1990 + 2.0 * t614;
  t659 = t761 * t446;
  t792 = 2.0 * t792 - t4772;
  t554 = 2.0 * t981;
  t614 = -param->m__l7 * t5764;
  t439 += t1510 + t389;
  t389 = 2.0 * t439 * param->s__l6y * param->m__l6;
  t957 = 2.0 * t5935 * q__p[1];
  t1134 = -t426 - 4.0 * t3185;
  t1510 = t114 * t214;
  t1136 = (t1510 * t290 * t724 - q__p[1] * t699) * 2.0 * t168_tmp;
  t1057 = t5658 * t1055;
  t712 = t415 * t226;
  t885 = 2.0 * t761 * t1620;
  t1118 = t579 - 4.0 * t5547;
  t1119 = (t1510 * t338 + t724 * t699) * 2.0 * t168_tmp;
  t1510 = ((t4933 + t3575) + t3576) - t966;
  t974 += ((param->s__l7x * t1510 * t54 + param->s__l7y * t1510 * t323_tmp) +
           t1023) + t467;
  t1608 = 2.0 * t376 * t699;
  t1714 = 4.0 * t568;
  t1774 = (((-2.0 * t2586 - t715) + t690) - t833) * 2.0 * t290;
  t1782 = 2.0 * t290 * (t733 + t893) * t42;
  t1787 = 2.0 * t42 * (t858 + t3185);
  t5172 = t42 * t105;
  t2003 = ((((t106 * -t120 + t5172 * t1014) + t117) - t118) - t119) + t216;
  t833 = 2.0 * t188;
  t1794 = t6137 * t204 * t440;
  t1798 = t1014 * t638;
  t1862 = 2.0 * t523 * t6245;
  t1865 = t6300 * q__p[1];
  t1871 = 2.0 * t1865;
  t3940 = t303 * t42;
  t1882 = 2.0 * t338 * t2892;
  t1854 = 2.0 * t466;
  t1861 = (t1882 + t1854) + t1406;
  t1648 = -t361 * t42;
  t5572 = t1038 * t106;
  t1884 = (2.0 * t2892 * t2554 + 2.0 * t552) - t1179;
  t4354 = t526 * t42 * t440;
  t3934 = 2.0 * t724 * t3940;
  t1023 = (tmpreturn_tmp * t324 + 2.0 * t183) * t2;
  t1510 = tmpreturn_tmp_7 * t517 * t54;
  t439 = 2.0 * t439 * param->m__l6 * param->s__l6x;
  t1179 = q__p[4] * t6268;
  t4360 = t214 * t204;
  t4362 = 2.0 * t6356 * t42 * q__p[1];
  t4355 = t42 * t549;
  t4357 = (t290 * t99 * t724 + t214 * q__p[1]) * (2.0 * t168_tmp) * t42;
  t4538 = t724 * t1012;
  t4539 = t3882 * t367;
  t3412 = 2.0 * t42 * t366 * t440;
  t5305 = t543 * t56;
  t4693 = 2.0 * t5305;
  t3397 = 2.0 * t6290;
  t5626 = ((t214 * t724 - t6273 * t433) * (2.0 * t168_tmp) * t42 - 2.0 * t5626)
    - t469;
  t2169 = 2.0 * t6488;
  t4231 = ((param->s__l6y * t12 * q__p[0] * t78 + param->s__l6x * q__p[1] * t695)
           * param->m__l6 + ((t456 - t463) * param->m__l7 * t16 + t449)) * 2.0 *
    t290 * t42;
  t4273 = t6335 * t2554;
  t4540 = (-t127 + t600) - t1029;
  t449 = t4540 + t337;
  t234 = 2.0 * t234 * t699;
  t2436 = (t310 - 2.0 * t915) * t42;
  t2441 = (-2.0 * t659 + 2.0 * t227) * t440;
  t4452 = (2.0 * t5694 + -t1301) * t42;
  t688_tmp = t976 * t440;
  t4033 = (2.0 * t1398 - 2.0 * t921) * t440;
  tmpreturn[36] = ((((((((((((((((((((((((((t408 * t42 + t455) * t440 - 2.0 *
    t941 * t699) * t105 + -4.0 * t1038 * t785) + t580 * t440) - t578) + 2.0 *
    t464 * t114) + t3910) * t346 + ((((t383 * t42 + t407) * t105 + 4.0 * t724 *
    t785) + 2.0 * t979) - t1093) * t267) + (t2441 - t1093) * t106) +
    ((((((((((t792 * t42 - t1029) + t554) + t614) - t389) - t127) - t806) + t600)
    + t337) * t440 + t2436) - t407) * t105) + (-2.0 * t659 - 2.0 * t2266 * (t415
    - t5928)) * t440) - t957) * t241 + (((((-2.0 * t309 * q__p[1] * t267 - 2.0 *
    t309 * q__p[0] * t798) - t793) + (2.0 * t3100 + 2.0 * t615) * t105) + t3226)
    - t364) * t288) + (((t2413 * t105 + t1134 * t42) + t793) + t1136) * t267) +
    ((((((((((t730 * t440 - t234) - t885) + t229) + 2.0 * t5842) * t105 + ((2.0 *
    t1057 - 2.0 * t2903) - 2.0 * t712) * t106) + (t1118 * t42 - t1119) * t440) +
        t4452) + 2.0 * t974 * t290) + (((t449 + t614) - t389) - t806) * t114) +
     t1608) * t346) + (((t1714 - t5805) + t5809) * t440 + t1774) * t105) +
    (((((((t2 * t377 + t533) - t1733) + t257) - t1709) + t3024) * t290 + -t1782)
     - (((((-t2 * t380 + t1054) + t417) + t946) + t948) - 2.0 * t541) * (2.0 *
    t114)) * t440) + t1787) * t38 / 2.0 + (((((((((((-4.0 * t1012 * (t106 + 1.0)
    * t346 * t724 - (t106 + 1.0) * 4.0 * t120 * t10) + 4.0 * t188) - 4.0 * t592)
    + 4.0 * t595) * t288 + (((((t466 + t1235) * -4.0 * t105 * t267 + (-4.0 *
    t105 * t914 - 2.0 * t761 * t114) * t346) + t973) + ((t688_tmp + t1403) +
    t1406) * t105) + t572) * t241) + ((-4.0 * t188 - t1451) + t1597) * t267) +
    ((((4.0 * t105 * t56 * t543 - 4.0 * t116 * t106 * t120) + t2143 * t440) -
      t2659) - t123) * t346) + 2.0 * t592) - t2711) + t2819) - t802) * t39 / 2.0)
    + (((((-2.0 * t2003 * q__p[1] * t267 - 2.0 * t724 * t2003 * t440 * t346) -
          t833) + (2.0 * t1794 + 2.0 * t1798) * t105) - t1862) + t1871) * t288 /
    2.0) + ((((((((((((((2.0 * t263 + t1709) + t1023) - t1510) + t1733) - t257)
                    - t439) * t42 + t733) - 2.0 * t1179) * t440 - t1882) - t1854)
               - t1235) * t105 + (((((((2.0 * t42 * t4856 + t1884 * t440) * t105
    + -4.0 * t3940 * t5572) - 2.0 * t4354) + (2.0 * t114 * t699 * t5492 - 2.0 *
    t1105) * t42) - 2.0 * t523 * t6268) * t346 + ((4.0 * t106 * t3940 * t724 +
    t105 * t1861) - 2.0 * t1648) * t267) + (t4033 - t3934) * t106)) + (((t4360 *
    t290 - t6452) * 2.0 * t168_tmp * t42 - 2.0 * t921) + 2.0 * t6349) * t440) +
            t4362) * t241 / 2.0) + ((((2.0 * t105 * t4355 + t2819) + t833) +
    t4357) - t802) * t267 / 2.0) + ((((((((((2.0 * t168_tmp * t4855 + 2.0 * t336)
    + 2.0 * t6274) * t42 + -t3412) - t4693) - t3397) * t105 + ((2.0 * t4538 -
    2.0 * t4539) - 2.0 * t122) * t106) + t5626 * t440) + (((((((t1709 + t1023) -
    t1510) + t1733) - t257) - t439) * t114 + t564) - t2169) * t42) - 2.0 * t1179
    * t114) + t529) * t346 / 2.0) + (((2.0 * t1048 * t699 + 2.0 * t5690) * t42 -
    2.0 * t204 * t688) * t440 - t4231) * t105 / 2.0) + (((((t449 + t4054) -
    t4594) - t806) * t290 + 2.0 * t114 * t974) * t42 + 2.0 * t290 * (t6370 -
    t411)) * t440 / 2.0) - t4273) + t595;
  t1105 = t3530 * t791;
  t833 = (t1105 + t10) - q__p[1];
  t974 = 4.0 * t76 * (t106 + 1.0) * t833 * t39;
  t389 = t2887 * t10;
  t1023 = t11 * t5947 * t346;
  t439 = t942 * t440;
  t614 = t851_tmp * t439;
  t1510 = (((t389 + t1023) - 2.0 * t614) - t6819) * (4.0 * t105) * t38;
  t6349 = t3938 * t76;
  t1179 = 4.0 * t2887 * t367 * t440;
  t3910 = 8.0 * t7266;
  t4054 = q__p[0] * t267;
  t5370 = t204 * t106;
  t3575 = t197 * t5370;
  t3576 = t197 * t204;
  t4856 = q__p[0] * t400;
  t6370 = t4856 * t1503;
  t1503 = t4856 * t12;
  t6452 = t6560 * t3938;
  t5764 = q__p[0] * t105;
  t941 = t1226 * param->m__l7;
  t5571 = t5 * t204;
  t417 = t941 * t5571;
  t6356 = 4.0 * t417;
  t6137 = t704 * t400;
  t4413 = t400 * t204;
  t1853 = t4413 * t543;
  t188 = (-4.0 * t1853 - t1278) + t3197;
  t517 = 8.0 * t6670;
  t464 = 2.0 * t6137;
  t526 = -2.0 * t4413 * t42 + t7124;
  t324 = 4.0 * t197 * param->m__l7 * t5 * t5370;
  t946 = t787 * param->s__l7x;
  t361 = param->s__l7y * t704;
  t5935 = t7151 * t114;
  t976 = t8017 * t5571;
  t366 = 8.0 * t976;
  t377 = t2887 * t2776;
  t380 = 4.0 * t377;
  t5547 = t204 * t105;
  t541 = 2.0 * t1055;
  t549 = 8.0 * t1038 * t543 * t1263;
  t564 = t6615 * t114;
  t467 = t4413 * t290;
  t310 = 2.0 * t467;
  t6245 = t4856 * t42;
  t6300 = param->s__l7y * t116 * t106;
  t1054 = t8017 * param->s__l7x;
  t579 = t942 * t114;
  t4496 = t1054 * t579;
  t426 = ((4.0 * t4496 + t7063) - t7064) - t412;
  t761 = 4.0 * t7266;
  t7063 = t6880 * t3938;
  t6670 = 2.0 * t7063;
  t5694 = t77 * t105;
  t5546 = t146 * param->s__l7y * t5694;
  t456 = 4.0 * t5546;
  t463 = t6880 * q__p[1];
  t466 = 2.0 * t463;
  t6560 = (-4.0 * t105 * t114 * t94 + t106 * t15) + t15;
  t5860 = 2.0 * t638 * param->m__l7 * t370 * t106;
  t793 = 4.0 * t204 * t7015 * t440;
  t469 = 8.0 * t433 * t16 * t76;
  t533 = t2205 * t5710;
  t552 = t638 * param->s__l7y;
  t7015 = ((-t105 * t941 * t2149 + t106 * t6880) + t1194 * t16) - t7555;
  t1194 = t433 * t429;
  t893 = 2.0 * t946 * t7231 * t204 * t440;
  t915 = t3623 * q__p[1];
  t938 = 4.0 * t915;
  t1138 = t732 * t5947 * t16;
  t1250 = t338 * t4;
  t972 = t1138 + t1250;
  t572 = (t4641 - t7221) * t440;
  t5658 = t370 * t204;
  t575 = t415 * t106;
  t625 = 2.0 * t6839 * t575;
  t5301 = t7128 * t370;
  t980 = 2.0 * t1138;
  t981 = 4.0 * t1250;
  t4594 = t2115 * t7298;
  t1877 = t724 * t7156;
  t4449 = t1877 - t7340 / 2.0;
  t2586 = -4.0 * t4449 * t26 + 4.0 * t4594;
  t889 = t724 * t169_tmp;
  t1185 = t338 * t5843;
  t1990 = (t1185 / 4.0 + t889) * param->m__l7;
  t1788 = t471 * t16;
  t4494 = t638 * t5843;
  t5299 = t724 * t7068;
  t2235 = 2.0 * t4494 + t5299;
  t715 = 4.0 * t6245 * t1788 + 2.0 * t2235 * t26;
  t3941 = (-4.0 * t7444 + t7443) * t18 * t440;
  t777 = t4413 * t249;
  t858 = -t6961 + t53;
  t943 = t858 * t440;
  t1087 = 4.0 * t724 * t94;
  t3024 = (-8.0 * t4496 + t7064) + t412;
  t690 = -t5828 + t228;
  t7221 = (((t690 + t1484) + t452) + t495) + t428;
  t1484 = 4.0 * t4594;
  t2250 = t1877 - t7340;
  t4594 = 2.0 * t26 * t2250;
  t7555 = t817 * param->s__l7x;
  t889 = (t1185 / 2.0 + t889) * 2.0 * param->s__l7x;
  t2284 = t20_tmp * t106;
  t7124 = t18 * t2284;
  t1250 *= 2.0;
  t1138 = 4.0 * t1138 - t1250;
  t2145 = t338 * t68;
  t5805 = t724 * t15;
  t1142 = (-4.0 * t160 * t6912 - t2145) + t5805;
  t1239 = -4.0 * t4641 - t7222;
  t5344 = t169_tmp * t204;
  t5809 = t5299 * t114;
  t7222 = t638 * t20_tmp;
  t1240 = ((4.0 * t169_tmp * t1226 * t2554 + t5809) + t7222) * param->s__l7x *
    t440;
  t1397 = -2.0 * t4413 * t2849 + 2.0 * t7367;
  t1399 = 2.0 * t918 * t2893;
  t3588 = t446 * param->s__l7x;
  t1761 = t77 * t114;
  t6473 = t3588 * t1761;
  t1401 = -t6615 * t114;
  t1433 = 4.0 * t467;
  t6581 = t5957 * param->s__l7x;
  t1447 = t249 * t5;
  t4855 = ((-4.0 * t1447 * t6912 + t42 * t6510) - t338 * t7684) * tmpreturn_tmp;
  t1395 = t2554 * t6906;
  t3887 = t4856 * t6949;
  t1398 = -4.0 * t4 * t6912 - 4.0 * t3887;
  t1429 = 2.0 * t5779;
  t5310 = t1005 * t4;
  t1431 = 2.0 * t5310;
  t1452 = (t16 * t6727 - t6902) * 2.0 * t290 * t440;
  t1456 = 2.0 * t1395;
  t1460 = (-4.0 * t169_tmp * t433 + t724 * t3230) * param->m__l7;
  t6839 = param->s__l7x * t105;
  t1492 = 4.0 * t6568_tmp * t7376 * t2849;
  t815 = 2.0 * t7222 + t5809;
  t1519 = tmpreturn_tmp_7 * t815 * param->m__l7;
  t1520 = t5805 * t440 / 4.0;
  t1718 = (t338 * t20_tmp / 4.0 + t724 * t7105) * 4.0 * param->s__l7x * t440;
  t6628 = t113 * t1761;
  t5928 = -t2145 / 2.0 + t5805;
  t1761 = tmpreturn_tmp_2 * param->s__l7y * t5928 - 4.0 * t7298 * t6819;
  t976 *= 4.0;
  t6644 = (t114 * t5957 - t3210) - t7344;
  t1780 = 2.0 * t338 * t26 * t695;
  t1788 = (t1788 * t6568_tmp + t370 * t7265) * 2.0 * t42;
  t1791 = ((4.0 * t160 * t2554 + t4494) + t5299) * param->m__l7;
  t7684 = -t168_tmp * t638 + t7443;
  t1839 = t7684 * param->s__l7y * param->m__l7;
  t1845 = t3887 * t440;
  t1877 = ((-4.0 * t160 * t338 + t1877) - t7340) * tmpreturn_tmp * t8137;
  t1853 *= 2.0;
  t1876 = (-t1853 - t1278) + t3197;
  t4503 = t724 * t867 + t1185;
  t1185 = tmpreturn_tmp_m * t4503 + 2.0 * t3887;
  t6682 = t249 * param->s__l7x;
  t1369 = (t180 + t6727) * 2.0 * t290 + -t6356;
  t1382 = 2.0 * t787 * t6543 * t290;
  t6699 = t3938 * param->s__l7y;
  t4365 = t465 * t5694;
  t180 = param->s__l7x * t39;
  t1384 = t249 * param->m__l7;
  t6723 = (t106 * t1384 * t2149 + t105 * t2887) + t429 * t7862;
  t6729 = 2.0 * t912 * t7124;
  t1393 = t1393 * param->s__l7x * t7922 * t440;
  t1394 = t2121 * t5710;
  t1850 = t638 * param->s__l7x;
  t7128 = t1226 * t16;
  t5304 = t370 * t105;
  t6739 = (t5 * t106 - param->s__l7x * t1130) + t7128 * t5304;
  t6740 = 2.0 * t6349;
  t867 = param->s__l7x * t204;
  t3197 = t867 * t440;
  t6727 = t433 * t27;
  t4641 = 2.0 * t523 * t8284 * t440;
  t3303 = 2.0 * (t1130 * param->m__l7) * t147;
  t7367 = t338 * t91;
  t3887 = t724 * t2121;
  t7340 = t7367 + t3887;
  t4073 = (t8080 - t8081) * t440;
  t7444 = t942 * t106;
  t7265 = t197 * t7444;
  t6274 = t85 * t16;
  t7784 = (t6274 + t7784) * t440;
  t7105 = 2.0 * t7367;
  t8284 = t338 * t27;
  t6615 = t4449 * t16 - t8284;
  t6912 *= t118;
  t7443 = 2.0 * t6912;
  t7298 = 2.0 * t1503;
  t7344 = (2.0 * t113 * t724 + t2235 * t16) * param->s__l7x * t440;
  t6906 = -2.0 * t8259 + 2.0 * t2115;
  t7862 = t27 * t204;
  t8259 = t7386 * t2149 * t4913;
  t7407 += t8259;
  t7922 = 2.0 * t7407;
  t4505 = t2250 * t16;
  t2250 = (t4505 - 2.0 * t8284) * tmpreturn_tmp * param->s__l7x;
  t2235 = t724 * t4291;
  t6741 = t724 * t249;
  t6746 = t26 * t2284;
  t2284 = -t7367 / 2.0 + t3887;
  t2145 = (-t2145 + t5805) * t26 * t16;
  t5805 = 2.0 * t377;
  t8080 = (2.0 * t8081 + t8080) * (2.0 * t18) * t440;
  t7064 = t7376 * t290;
  t7376 = -2.0 * t26 * (t5809 + t7222) * t16 - 2.0 * t6568_tmp * t7064;
  t8081 = (t204 * t7402 + t8198) * t440;
  t2947 *= t724;
  t8198 = (-t7367 + t3887) * param->s__l7x;
  t5957 *= param->s__l7y;
  t8486 = (t6543 * t42 + t338 * t8486) * tmpreturn_tmp * t16;
  t5809 = t2554 * t7833;
  t6335 = t942 * t105;
  t6543 = t724 * param->s__l7y;
  t7833 = (2.0 * t338 * t7833 + 2.0 * t6543) * t440;
  t7367 = t1005 * t91;
  t7829 = (t7829 - t45) * t290 * t440;
  t7222 = 2.0 * t118 * t2554 - 2.0 * t6819;
  t815 = 2.0 * t2554 * t8234 + t815 * t16;
  t4449 = t20_tmp * t440;
  t8284 = t6741 * t18 * t4449;
  t5842 = t370 * t16;
  t5928 = (t5928 * t16 - t338 * t8234) * tmpreturn_tmp_2 * t8137;
  t7805 = (t16 * t20_tmp * q__p[1] + t724 * t7805) * param->s__l7x * t42;
  t7064 = 2.0 * t26 * (t4494 + t5299) * t16 + 2.0 * t4856 * t7064;
  t7684 = t7684 * t16 - t987;
  t8137 *= t724;
  t6961 = t53 * t16;
  t4494 = 2.0 * t4505 * t26 - 2.0 * t6726;
  t4496 *= 2.0;
  t5299 = (t4503 * t16 + t6543) * param->s__l7x * t440;
  t4503 = t724 * t446 * t947;
  t4505 = (t114 * t2849 * t6510 - t999) * param->m__l7;
  t449 = t2244_tmp * param->s__l7x;
  t4067 = (t106 + 1.0) * 2.0;
  t6543 = 8.0 * param->s__l7x;
  t4068 = 4.0 * t26 * param->s__l7x;
  t6510 = (2.0 * t2400 + 2.0 * t5301) * t440;
  t1876 *= t16;
  t188 *= t440;
  t4072 = ((t6781 - t230) * 2.0 * t290 + -2.0 * t2887 * t367) * t440;
  t3328 = (t2244_tmp * t5842 * t338 - 2.0 * t732 * t5947) * t440;
  t4537 = t4494 * t440;
  tmpreturn[43] = (((((((((((((((((((((((((((((((((t449 * t2936 + t715 * t440) *
    t105 + 16.0 * t5572 * t2646) + 2.0 * t3941) + 2.0 * t114 * (t777 + t6429)) *
    t346 + ((-16.0 * t6557 * t12 * t2646 + t6543 * t1990) + t105 * t2586) * t267)
    + (t943 + t1087) * 2.0 * param->s__l7y * t8231) + (((tmpreturn_tmp_m * t7221
    + t3024 * t16) * t440 - t1484) + t4594) * t105) + (((t5658 * t446 + t7555 *
    t114) + 2.0 * t7228) * t440 - t889) * 2.0 * param->m__l7) * t38 + (((((-4.0 *
    t105 * t572 + 2.0 * t5658 * t787) * t346 + 4.0 * t105 * t972 * t267) - t625)
    + ((t6510 - t980) - t981) * t105) - 2.0 * t465 * t467) * t39) + ((t449 *
    t1142 + t105 * t1138) + 4.0 * t7124 * t918) * t267) + (((t1239 * t440 -
    ((2.0 * t5344 * t429 - t7480) + t6449) * 2.0 * param->m__l7) * t105 + -4.0 *
    t2910 * t7124) - (t7129_tmp * t7666 - t1240) * tmpreturn_tmp) * t346) +
    (t1397 * t440 - t1399) * t106) + ((((t6473 + t7748) * 2.0 * param->m__l7 +
    2.0 * t2400) * t440 - t980) + t1250) * t105) + (((t415 * t67 - t7626) * t42
    + (-t7542 + t6581) * t114) * tmpreturn_tmp + (t1401 + t1433) * t16) * t440)
    + t4855) * t241 + (((((((((((t4067 * t346 * t5947 * t7977 + t4067 * t267 *
    q__p[1] * t6880) - t6670) + t456) - t466) * t39 + ((((-2.0 * t26 * q__p[1] *
    t6560 * t267 - 2.0 * t8523_tmp * t791 * t6560 * t346) + t5860) + (t793 -
    t469) * t105) + 2.0 * t275 * (t533 + t552)) * t38) + 2.0 * q__p[1] * t7015 *
    t267) + 2.0 * t991 * t12 * t7015 * t346) - t6670) - 2.0 * t275 * (t439 -
    t1194) * t105) + t893) + t938) * t288) + (((((((((-2.0 * t105 * t415 * t25 *
    t400 + 2.0 * t116 * t16 * t6807) + t1398 * t440) + t1429) + t1431) * t346 +
    ((t6670 - 4.0 * t463) + 4.0 * t1395) * t267) - 2.0 * t5546) - t1452) + t466)
    - t1456) * t39) + ((((((((((((-4.0 * t2173 * t805 - t7555) + t1718) + t6628)
    + t8548) * tmpreturn_tmp * t105 + ((-t1520 + t1177) + t2645) * (8.0 * t26) *
    t106) + t1761 * t440) + (t5935 - t976) * t16) + 2.0 * t6644 * param->s__l7y *
    param->m__l7) * t346 + (((-2.0 * t1460 * t6839 - t5860) + t1492) + t1519) *
    t267) + ((-2.0 * t777 + 2.0 * t7130) * t440 - t1780) * t105) + ((t2848 *
    t7236 + t7300) * 2.0 * param->m__l7 + 2.0 * t5869) * t440) - t1788) * t38) +
    (((-2.0 * t6839 * t1791 + 2.0 * t7063) + 2.0 * t463) - 2.0 * t1839) * t267)
    + (((((t1876 + -t1877) - ((-t6998 * t7450 + t6581) - t7542) * tmpreturn_tmp)
         * t105 + ((2.0 * t1845 - 2.0 * t5779) - 2.0 * t313) * t106) + t1185 *
        t440) + tmpreturn_tmp * t7755) * t346) + ((((-2.0 * t6682 * t295 + t4933)
    + t965) + t966) * t440 + 2.0 * t2554 * t6682) * (2.0 * t26) * t105) +
    ((((t128 * t695 - t7480) - t7701) * t114 + t6377 * t446) * tmpreturn_tmp +
     t1369 * t16) * t440) - t466) - t1382) * t2 / 2.0 +
    (((((((((((((((((((((-8.0 * t105 * t290 * q__p[1] * t1263 - 8.0 * t6370) +
    4.0 * t1503) * t267 + (((-8.0 * t5764 * t791 * t2123 + 8.0 * t6452) - t6356)
    - 4.0 * t2973) * t346) + 4.0 * t6137 * t106) + (t188 + t517) * t105) - t464)
    * t38 + ((((-2.0 * t105 * t4054 * t114 * t12 + t704 * t105 * t114) + 2.0 *
    t8417 * t114 * t1199) + t3575) + t3576) * (4.0 * t26) * param->s__l7x * t39)
    + (-2.0 * t5764 * t12 * t76 + t6726) * (4.0 * t114) * t267) + (4.0 * t11 *
    t471 * t2168 + t105 * t526) * t346) + t324) + 4.0 * t946 * t361 * t105) +
              (t5935 - t366) * t440) - t380) * t241 + (((((((t106 - 2.0) * -4.0 *
    t5 * t346 * t146 * t724 - t6664_tmp * (t106 - 2.0) * t4464 * t267) - t974) +
    t1510) + 4.0 * t6349) + t1179) - t3910) * t288) + ((((((-t116 * t106 + t5547
    * t543) + t541) - q__p[3]) * t346 + (2.0 * q__p[1] + -t3938) * t267) + t607)
    - q__p[1]) * t4068 * t39) + ((((((4.0 * t105 * t116 * t114 * t400 + 4.0 *
    t4413 * t4246) + t549) + t564) - t310) * t346 + (t105 * t2115 - 2.0 * t1263 *
    t2554) * (4.0 * t114) * t267) + (t704 * t543 + t105 * t5710) * (4.0 * t26) *
    param->s__l7x * t42) * t38) + ((-4.0 * t105 * t6245 * t471 - 4.0 * t6349) -
    4.0 * t7266) * t267) + ((t105 * t426 - 4.0 * t6300 * t18) - 4.0 * t1055 *
    t76) * t346) + 2.0 * t6137 * t446 * t105) + t4072) + t761) * t3 / 2.0) +
    ((((((((((((t106 + 1.0) * t987 * t267 / 2.0 + t1055 * param->s__l7y * (t106
    + 1.0) * t346 / 2.0) - t6699 / 2.0) + t4365) - t987 / 2.0) * 4.0 *
           param->m__l7 * t180 + ((((-2.0 * q__p[1] * t6723 * t267 - 2.0 * t991 *
    t6723 * t12 * t346) + t6729) + (2.0 * t1393 + 2.0 * t6819) * t105) - (t1394
    - t1850) * 2.0 * t16 * t275) * t38) + tmpreturn_tmp * t6739 * t10) + 2.0 *
         t7081 * t6739 * t12 * t346) - t6740) - (t3197 + t6727) * 2.0 * t16 *
       t275 * t105) - t4641) + t3303) * t288 / 2.0) + ((((((((((((((((((t169_tmp
    * t2936 + t7344) * 2.0 * param->m__l7 * t105 + -4.0 * t6452) + t6906 * t440)
    + (t16 * t5492 + t7862) * 2.0 * t114 * t18) * t346 + (((-4.0 * t105 * t6615 *
    t18 + 4.0 * t6370) - t7443) - t7298) * t267) + (t7922 * t440 - t7298) * t106)
    + ((((tmpreturn_tmp * t7221 * t94 + t1853) + t371) - t7966) * t440 + t2250) *
    t105) + ((t4857 * t446 - t114 * t4914) * tmpreturn_tmp * t16 - t680) * t440)
    + t7443) + t2235) * t38 + (((((2.0 * t105 * t4073 + t77 * t25) * t346 + 2.0 *
    t105 * t7340 * t267) - t7265) + ((t7784 - t7105) - t3887) * t105) - t197 *
    t942) * 2.0 * param->m__l7 * t180) + (((4.0 * t105 * t2284 * t18 - 4.0 *
    t6741 * t6746) + 2.0 * t2145) - t5805) * t267) + (((((tmpreturn_tmp * (t8296
    + t5502) * t16 + -t8080) + t367 * t4291) * t105 + 4.0 * t1038 * t249 * t6746)
    + t7376 * t440) - 2.0 * t54 * param->s__l7x * t7666 * t695) * t346) -
    tmpreturn_tmp_7 * (t8081 - t2947) * t8231) - (((t6628 - t8549) * t16 - t2492)
    * t440 + t8198) * 2.0 * param->m__l7 * t105) + ((((t8354 + t5957) * t114 -
    (t415 * t7201 + t7655) * t42) * t2244_tmp * t16 + -t8365 * t114) + t976) *
    t440) + t8486) + t5805) * t241 / 2.0) - (((((((((t6335 * t543 - t6300) +
    t7833) - t7367) - t57) * t346 + ((-t6699 - 2.0 * t5809) + 2.0 * t987) * t267)
    + t4365) - t7829) + t5809) - t987) * t18 * t39) + (((((((((((t6473 + t7747)
    + t4914) * 2.0 * param->m__l7 * t16 + t3328) + 2.0 * t7297) * t105 + ((-2.0 *
    t8284 + 2.0 * t2399) - 2.0 * t467) * t106) + t5928) + 2.0 * t6644 *
    param->m__l7 * t94) + t8032 * t114) + t415 * t947) * t346 + ((2.0 * t815 *
    t18 + t105 * t7222) - t6729) * t267) - ((((-t1048 * t16 + t7862) * t440 +
    t338 * t7951) * param->s__l7x * t105 + ((-t2848 * t7689 + t8146) * t16 -
    t6825) * t440) + t7805) * tmpreturn_tmp) * t38 / 2.0) + ((t105 * t7064 - 2.0
    * t7684 * t18) + t6740) * t267 / 2.0) + ((((((((-t6998 * t7095 + t5957) +
    t8354) * 2.0 * param->m__l7 * t16 + t4537) - t4496) + t8364) + t257) * t105
    + ((t8137 + t6961) - t31) * 2.0 * param->s__l7y * t8231) - (t16 * t8555 -
    t5299) * tmpreturn_tmp) * t346 / 2.0) + ((t5491 + t8329) * t440 - t4503) *
                    t105 / 2.0) + (((((-t45 * t695 - t7738) - t8296) * t114 +
    t6378 * t446) * tmpreturn_tmp * t16 + t367 * t8507) - t8510) * t440 / 2.0) +
    t4505;
  t7297 = 4.0 * t991 * t1183 * t1170;
  t7300 = t4607 * t39;
  t965 = t303 * t440 * t732;
  t7450 = 4.0 * t965;
  t966 = t991 * t605;
  t7480 = 4.0 * t966;
  t7689 = t799 * t440;
  t1048 = 4.0 * t4538;
  t1183 = 2.0 * t2472 * t791;
  t2472 = 2.0 * t991 * t6556;
  t2848 = 2.0 * t991 * t1232 * t12;
  t734 *= t2497;
  t2497 = t639 * t189;
  t2097 *= t189;
  t4464 = t338 * t6556;
  t7747 = t1077 * t1170;
  t1232 = -t1232 * t8128 - t179;
  t3786 = t1260 * t3786 * t1170;
  t4607 = 4.0 * t481 * q__p[1];
  t3634 = 4.0 * t3634 * q__p[1];
  t6726 = t991 * t639;
  t6807 = t1260 * t930;
  t2119 *= t991;
  t4370 *= t991;
  t930 = t481 * t12;
  t7081 = 2.0 * t4754 * t112 * t725;
  t2702 *= 2.0;
  t7130 = t589 * t12;
  t7748 = t896 * t4243;
  t4243 = t1014 * t189;
  t7095 = t605 * t189;
  t968 *= t1170;
  t729 *= t12;
  t7755 = t732 * t639;
  t7228 = t695 * t522 * param->m__l4;
  t7266 = param->l__2 + param->s__l3z;
  t7236 = t1152 * t7266;
  t7266 *= t895;
  t2936 = (tmpreturn_tmp_n - t751_tmp) + t7266;
  t895 = 2.0 * t7748;
  t1008 *= 2.0;
  t1013 = 4.0 * t1013 * t2776;
  t1152 = 4.0 * t7755;
  tmpreturn[2] = (((((((((((((((((((((((((((((((((((((-t87 / 2.0 - t17 / 4.0) -
    t22 / 4.0) * t2 + -t8 / 2.0) - t97 / 2.0) + t28 / 4.0) + t32 / 4.0) - t2458)
    + t35 / 4.0) * t290 + ((((((-t43 / 4.0 - t46) * t3 + t2957 / 2.0) + t750 /
    4.0) + t81 / 2.0) * t290 - t1103) * t38 + -t1338 / 2.0)) + t561) * 8.0 * t12
    + 2.0 * t290 * t589 * t150) * t106 + ((((((((t1093 + t4607) * t38 + t1158) -
    t3634) * t940 + -4.0 * t3786) + ((t1362 + t3568) * t12 - 8.0 * t6726) * t39)
    + ((t1373 - t3574) * t12 - 4.0 * t6807) * t38) + (t1389 + t3591) * t12) +
    4.0 * t2119) * t105) + 4.0 * t1329 * t5796) + ((((-t1406 + t731) * t39 +
    -t3268 * t38) + 2.0 * t4010) + 2.0 * t3730 * q__p[1]) * t940) - 4.0 * t4880 *
    t205) + ((t1426 + t1348) * t12 - 4.0 * t4370) * t38) + (t3686 + t3687) * t12)
    - 4.0 * t1260 * t877 * t440) * t346 + ((((((((((-8.0 * t2497 - 4.0 * t3796) *
    t39 + 4.0 * t734) + (-4.0 * t2097 + 8.0 * t342) * t38) + 4.0 * t4464) - 4.0 *
    t3838) * t105 + 8.0 * t808 * t1569 * t106) + 4.0 * t7747) + 4.0 * t1232 *
    t38) - 4.0 * t4379 * t189) - 4.0 * t3866) * t267) + ((2.0 * t116 * t290 *
    t744 - 4.0 * t1170 * t808) + 4.0 * t1182 * t4754) * t106) +
    (((((((((((((((((-t1258 - t1259) + t2307) + t2309) + t596) - t1273) + t1274)
    * t290 + 4.0 * t991 * t930) - t913) * t38 + 4.0 * t332 * t39) - 4.0 * t3635 *
    t724) + ((((((((t1277 + t767) + t2350) + t1289) - t2358) - t1292) + (-t1293
    + t2362) * param->m__l6) + t1297) + t1298) * t290) - t920) * t940 + -2.0 *
    t734) + t7081) + ((-t807 + t871) * -2.0 * t440 * t12 - t3040) * t38) - 2.0 *
      t1337 * t440 * t12) + t3839) * t105) - 2.0 * t7747) +
    ((((((((tmpreturn_tmp_o + t1316) * t114 + t1319) * t290 + -4.0 * t991 *
    t2695 * t12) + t933) * t38 + ((2.0 * t799 * t4830 + -t1303 * t290) + t927) *
        t39) + 2.0 * t3731 * t791) + ((((((tmpreturn_tmp_p - t1327) - t1033) *
    t42 + tmpreturn_tmp_q) + t573) + t1331) * t114 - t1334) * t290) - 2.0 * t59)
    * t940) + 2.0 * t823 * t791 * t39) + (-2.0 * t440 * (t2702 + t335) * t12 +
    2.0 * t179) * t38) - (-t114 * t406 + t848) * 2.0 * t440 * t12) + t3875) *
    t241 / 2.0 + (((((((((((((((((((-t1277 + t1281) + t3469) + t1290) + t2358) +
    t1292) + t1296) - t1297) - t1298) * t12 + (((4.0 * t5118 * t940 + -t7297) -
    4.0 * t7300) + (t12 * t3466 - t7450) * t38)) + t7480) * t105 + (t6514_tmp +
    t6512) * 2.0 * t589 * t106) + 2.0 * t3538 * t4349) - 4.0 * t3652 * t940) +
                       (t12 * t1303 - 2.0 * t7689) * t39) + (4.0 * t991 * t448 +
    t12 * t3491) * t38) + (t3494 + t1334) * t12) - 2.0 * q__p[0] * t516 * t440) *
                   t346 + -2.0 * t967 * t12 * t10) - (((((((((((((((((((t1048 +
    t115) - t123) * t39 + ((t1183 + t1822) - t175) * t38) - t2472) + t1825) +
    t222) * t105 + t1819) + t661) + (((((((t2848 - t229) + t1829) + t1831) +
    t1141) + t239) + t46) + t243) * t38) + 2.0 * t3503 * t791) - t264) - t265) -
    tmpreturn_tmp_r) - t3545) - t28) - t101) - t32) + t284) + t283) * (2.0 *
    t940)) * t288 / 2.0) + ((((((((((-4.0 * t4243 + 4.0 * t4171) * t38 + -4.0 *
    t7748) + 4.0 * t7095) + 4.0 * t4180) * t105 + -2.0 * t7130 * t3938) - 4.0 *
    t968) + (4.0 * t729 - 8.0 * t7755) * t39) + (-8.0 * t12 * t2917 - 4.0 *
    t4210) * t38) + 2.0 * t892 * q__p[1] * t12) + 4.0 * t4216) * t267 / 2.0) +
    (((((((((((((((((-4.0 * t5052 - t341) + t5208) + t353) + t596) - t1273) +
    t1274) * t12 - t7450) * t38 + (((((2.0 * t12 * t3918 + -t2052 * t39) +
    -t2422 * t38) - t818) * t940 + -t7297) + 2.0 * t7300)) + ((((((((-4.0 *
    t5067 + t767) + t5226) + t1289) + t888) - t749) + t5231) + t1297) + t720) *
             t12) + t7480) * t105 + ((2.0 * t12 * t1182 * t714 + t1170 * t3560)
    - t3560) * (2.0 * q__p[0]) * t106) - 2.0 * t4191 * t4349) + ((((t74 + t7228)
    + t7236) * (2.0 * q__p[0]) * t12 + (2.0 * t12 * t3993 + 2.0 * t4082 * q__p[1])
    * t38) + 2.0 * t2936 * q__p[1]) * t940) + (((8.0 * t1496 - t1301) - t1302) *
    t12 + 4.0 * t7689) * t39) + (((4.0 * t545 * t550 + t114 * -t3408) + t1319) *
    t12 - 8.0 * t991 * t839) * t38) + (((t114 * t5480 - 4.0 * t3172 * t338) +
    t3444) + t4048) * t12) + 2.0 * q__p[0] * t892 * t440) * t346 / 2.0) +
                        (((((-t1678 - t1721) * t38 + t1676) - t1684) + t649) *
    2.0 * t12 + t1006 * t940) * t106 / 2.0) + ((((((((((((((t1048 - t1008) +
    t1359) - t123) * t39 + (((t1183 + t1013) + t1035) - t175) * t38) - t2472) -
    2.0 * t1039 * t545) - t1082) + t1079) + t222) * t940 + t895) + 4.0 * t791 *
    t670 * t4608) + (((t3949 - t227 / 2.0) * -4.0 * t440 * t290 + 4.0 * t677) *
                     t12 - t253) * t38) + ((t262 / 2.0 + t3964) * (4.0 * t440) *
    t290 - 4.0 * t705) * t12) - t512) * t105 / 2.0) + t968) +
                     ((((((((((((((((((2.0 * t12 * t991 * t4082 + t1423) + t1424)
    - t236) - 2.0 * t2009) - t229) + t230) - t4204) + t4207) * t38 + 2.0 * t991 *
    t2936 * t12) - 2.0 * t440 * t524 * t338) - ((t2842 + t7228) + t7236) * 2.0 *
    q__p[1] * t440) - t264) - t265) + t4220) + t4222) + t283) - t102) + t284) *
                     t940 / 2.0) + (2.0 * t12 * t1707 + t1152) * t39 / 2.0) +
                   ((tmpreturn_tmp_s * t440 + t1681) * t12 + t1736) * t38 / 2.0)
                  + (tmpreturn_tmp_5 * t440 - 2.0 * q__p[1] * t1412) * t12 / 2.0)
    - t4216;
  t1082 = t1329 * t940;
  t115 = 2.0 * t18 * t228 + 2.0 * t183;
  t516 = t115 * t2;
  t1039 = t8523_tmp * t4346 * t16;
  t524 = 2.0 * t1039;
  t97 = 2.0 * t193;
  t589 = ((t3017 - t427) + t1032) + t806;
  t649 = t589 * t42;
  t43 = t228 + t52;
  t74 = t43 * param->s__l7y;
  t677 = t74 * t323_tmp;
  t43 *= param->s__l7x;
  t705 = t43 * t54;
  t731 = 2.0 * t3947;
  t807 = 2.0 * t340;
  t59 = 2.0 * t5726;
  t74 *= t54;
  t1258 = (t1116 + t618) * 4.0 * param->s__l7y * param->m__l7;
  t848 = t228 + t428;
  t1259 = 2.0 * t848 * param->s__l7x * t54;
  t839 = -t5230 * param->m__l6;
  t87 = 2.0 * t3883;
  t1277 = (((t1041 - (((t815_tmp + t608) + t613) + t618) * tmpreturn_tmp_2 *
             t697) + t1314) + (t3522 + t428) * 2.0 * param->s__l7y * t54) - 2.0 *
    param->s__l6x * t848 * param->m__l6;
  t1298 = ((((((t337 + t3431) + t3432) + t3235) * t42 + tmpreturn_tmp_t) - t573)
           - t293) - t1331;
  tmpreturn_tmp_5 = 4.0 * t732 * (t315 * t940);
  tmpreturn_tmp_o = -2.0 * t677 - 2.0 * t705;
  tmpreturn[9] = (((((((((((((((((((((((((((((((((((((((((4.0 * t2238 * t290 *
    t179 + t1733) + t516) - t524) - t97) + t2241) + t1709) * t38 + ((((-t38 *
    t1544 - tmpreturn_tmp_1) - t4015) + t4024) * t440 - 2.0 * t414 * t725)) -
    tmpreturn_tmp_5 * t290) - 2.0 * t814) + t457) - t762) + t649) + t293) * t105
    + ((((2.0 * t49 * t4679 + t3956) + (-4.0 * t4982 + 4.0 * t335) * t38) + 2.0 *
    t49 * t308 * t290) - t1339) * t106) + ((-t38 * t4050 + t4060) + t4065) *
    t440) + 2.0 * t5398 * t39) + ((-4.0 * t2983 * t714 - t501) - t753) * t38) +
    2.0 * t49 * t3726) + ((tmpreturn_tmp_o - 2.0 * t4071) + 2.0 * t306) * t114)
    + t4629) + t4630) + t4000) - t4632) * t241 + ((((4.0 * t1230 * t49 - 4.0 *
    t3819) * t105 + t3806) + t3823) - 4.0 * t1082) * t288) + (2.0 * t5300 - 2.0 *
    t3896) * t106) + ((((((-t38 * t5171 - t706) - t4996) * t440 + (4.0 * t1689 +
    4.0 * t3944) * t39) + (t290 * t1063 + t731) * t38) + (t4426 + t4427) * t290)
                      - t807) * t105) + (((((((-t38 * t5103 - tmpreturn_tmp_6) -
    t5105) + t5071) - t5077) - t4858) + t5286) - t5303) * t440) + 2.0 * t2904 *
    t39) + ((((((-t2155 + t127) - t4447) - t1028) + t337) + t1666) * t290 + t59)
    * t38) + (((((((2.0 * t43 * t969 + t2170) + (-2.0 * t74 + 2.0 * t1047) * t42)
                  - t296) + t1123) + t840) + t2185) + t4497) * t290) + (t877 +
    t7266) * (2.0 * q__p[0]) * t940) * t346 / 2.0 + ((((((((((((((((((-t38 *
    t3832 - tmpreturn_tmp_e) + t3833) + t3895) * t105 + t3827) - tmpreturn_tmp_h)
    - t3936) + t3951) * t241 + -2.0 * t1059 * t12 * t288) - t2578) + ((-t38 *
    t4345 - t4533) + t474) * t105) - tmpreturn_tmp_i) - tmpreturn_tmp_3) - t4583)
    - t4589) + t4599) + t4613) + t4623) + t4824) * t267 / 2.0) - t3826 * t288) +
    ((((((((t3950 - t3573) * t38 + t4121) + t3965) - t3590) * t440 - t4116) *
       t105 + (4.0 * t4087 - 4.0 * t499) * t106) + ((((t4113 + t3657) * t39 +
    (t497 + t3663) * t38) + t4110) - t3679) * t440) - t4186) * t241 / 2.0) +
                        (-2.0 * t940 * t1182 * t197 + t7130) * q__p[0] * t106) +
                       ((((((((((((((((((((t3908 + t341) + t977) + t660) - t596)
    + t1273) - t1274) * t38 + ((((-t3903 - t321) + t325) - t326) - t327) * t39)
    - 2.0 * t49 * t3916) + t1281) + (t1284 - t1258) * t2) + t1290) - t1259) -
    t4078) + t749) + t839) - t1297) - t720) * t440 - tmpreturn_tmp_c) + t996) -
                        t474) * t105 / 2.0) + ((((((((((t114 * t1277 - t87) -
    t1319) * t38 + t1304) - 2.0 * t3866 * t714) + t1298 * t114) - t1017) + 4.0 *
    t18 * q__p[3] * t868 * t2) + 4.0 * t1551) - 2.0 * q__p[0] * (t7228 + t7236) *
    t940) - 2.0 * q__p[3] * t4842) * t440 / 2.0) + t1747 / 2.0) + t6529 / 2.0) +
                   t4550) - t4928) - t4748;
  t308 = t434 * t114;
  t136 *= t114;
  t414 = q__p[3] * t72;
  t706 = t376 * t171;
  t814 = 2.0 * t706;
  t181 = -t181 * t114 * t3;
  t969 = t185 * t114 * t42;
  t3431 = t4572 * q__p[4];
  t1182 = t3431 * t114;
  t1230 = t5959 * q__p[3];
  t1274 = 2.0 * t2255;
  t1290 = (t114 * t6998 - q__p[6]) * (t5 * param->m__l7) * t3;
  t1297 = 2.0 * t6278;
  t1304 = t268 * param->s__l7y;
  t1319 = t57 * t6467;
  t848 = 2.0 * t6285;
  t892 = t5748 * q__p[3] * t114;
  t185 = q__p[6] * t42;
  t268 = 2.0 * t4203;
  tmpreturn[16] = ((((((((((((((((((((((((((((((((2.0 * t7666 * t14 * t3 -
    (((t6033 / 2.0 + t6034) * param->s__l7x * t42 - t136) + t6060) *
    tmpreturn_tmp_2 * t2) + (2.0 * t6039 + 2.0 * t414) * t42) + (((-t145 + t149)
    - t152) - t154) * t114) - t814) * t38 + ((((t5629 - 2.0 * t5525) *
    tmpreturn_tmp * t697 + -t5628) - t308) + 4.0 * t1755) * t39) - t181) + (2.0 *
    t18 * (t5629 + t5525) + t969) * t2) + (t114 * t194 + t2169) * t42) + t1182)
    - 2.0 * t1230) * t105 + t107) + t40) + (((((((((t233 + t6903) + t58) + t235)
    * t2 + t232) + t750) + t1274) - t239) - t46) - t243) * t38) - 4.0 * t1290) +
    ((((-t1297 + t1304) * t42 + 2.0 * t1319) + t270) - t22) * t2) + (((t848 +
    t274) + t276) + t277) * t42) - 2.0 * t892) + t28) - t283) + t101) + t32) -
    t284) * t288 + (((((((((((((((((((((((4.0 * t5 * param->m__l7 * (t805 - t185)
    * t3 + ((t344 + t1297) + t347) * t2) + t353) - t848) + t354) - t276) + t356)
    * t38 + t328 * t39) + t373) + (((t6903 - t58) + t235) * t42 + t381) * t2) +
    (((t1274 - t239) + t46) + t385) * t42) + 2.0 * t805 * t314) - t392) - t395)
    + t2593) - t3714) * t105 + t1178 * q__p[3] * t106) + (t2939_tmp - t414) *
    t39) + (((((t5633_tmp * t42 - (t183 - t431) * t114) * t2 + t422 * t114 * t3)
              + (-t308 + t5635) * t42) + ((-t438 + t420_tmp) + t442) * t114) -
            t2169) * t38) + (-t42 * t6055 + q__p[3]) * (2.0 * t14) * t3) -
                       (((t85 / 4.0 - t266 / 4.0) * t114 + t6034) *
                        param->s__l7x + (-t136 + t6060) * t42) * 4.0 *
                       param->m__l7 * t2) + (t114 * t3715 - t814) * t42) + (t473
    + t475) * t114) - (((((((((((((t496 + t504) - t505) - t508) + param->I__l7yy)
    - param->I__l7xx) + t511) + param->I__l6xx) - param->I__l5yy) -
    param->I__l6zz) + t515) - param->I__l4xx) + param->I__l4yy) + param->I__l5zz)
                    * q__p[3]) * t290 * t241) + t1819) + ((((((((((((t429 *
    t6035 - 2.0 * t136) + t6060) * 2.0 * param->m__l7 * t2 + -(t6998 - 2.0 *
    t6055) * t14 * t3) + (-t6040 - t414) * t42) + (((t145 + t643) + t152) + t154)
    * t114) + t706) * t38 + (((t5628 - t5633) + t308) - t5635) * t39) + t181) +
    (-t969 - (t5629 + t6497) * 2.0 * param->m__l7 * param->s__l7x) * t2) + (t114
    * -t194 - t6488) * t42) - t1182) + t1230) * t105) + (((((((-t6902 - t58) -
    t235) * t2 + -t268) - t2255) + t239) + t46) + t243) * t38) + 2.0 * t1290) +
                       (((t6278 - t1304) * t42 - t1319) - t17) * t2) + (((-t6285
    - t274) - t276) - t277) * t42) + t892) + t282) - t101) + t35;
  t233 = t724 * t346;
  t17 = t233 - t1038;
  t228 = 2.0 * t17 * t628 * t106;
  t2957 = 8.0 * t6458;
  t235 = -4.0 * t114 * t17;
  t2936 = t235 * t623 + 4.0 * t1155;
  t3172 = 4.0 * t721 * t17 * t114;
  t3408 = 4.0 * t1157;
  t40 = t17 * t112;
  t136 = t40 * t39;
  t3444 = 2.0 * t136;
  t194 = t204 * t650 * t114;
  t232 = t17 * t448;
  t3573 = t204 * t662 * t114;
  t3590 = 4.0 * t3573;
  t356 = t14 * t17;
  t3657 = t356 * t3;
  t3663 = 4.0 * t3657;
  t448 = t17 * param->m__l7;
  t3679 = 8.0 * t487 * t448 * t2;
  t3432 = t17 * t168_tmp;
  t487 = t3432 * t1133;
  t3726 = 4.0 * t487;
  t340 = t878_tmp - (t78 + param->s__l6x) * ((-param->d__5 + param->s__l6z) +
    param->s__l6x);
  t3883 = t340 * param->m__l6;
  t877 = ((((((((((((t496 + t3883) - t505) - t508) + param->I__l7yy) -
                 param->I__l7xx) + t511) + param->I__l6xx) + t515) -
             param->I__l4xx) + param->I__l4yy) - param->I__l5yy) +
          param->I__l5zz) - param->I__l6zz;
  t3466 = 2.0 * t12 * t877 * t3530;
  t3469 = 2.0 * t877 * q__p[1] * t440;
  t3866 = t751_tmp * t204;
  t3491 = 4.0 * t3866;
  t2241 = t367 * t639;
  t878_tmp = t1055 + t1199;
  t750 = t878_tmp - q__p[3];
  t499 = t623 * t750;
  t3494 = 2.0 * t6427 * t290;
  t2170 = t17 * t120;
  t3896 = 8.0 * t2170 * t290;
  t497 = t750 * t114;
  t2155 = 2.0 * t497 * t112;
  t2238 = t17 * t173;
  t3903 = 4.0 * t114 * t623 * t204 + 4.0 * t2238;
  t2458 = t42 * t750;
  t2185 = t220 * t17;
  t3916 = t235 * t650 + 4.0 * t2277;
  t3503 = t1371 * t3;
  t504 = t204 * t168_tmp;
  t3944 = (((((((t2863 - t1609) + t154) * t38 + t645) + t653) + t657) +
            t2863_tmp) + t735) * t290 * t106;
  t4203 = t2746 * t114;
  t3538 = 2.0 * t1155;
  t734 = t2754 * t114;
  t3545 = 2.0 * t1157;
  t2863 = t750 * t120;
  t1819 = 2.0 * t40;
  t3560 = 2.0 * t194;
  t3568 = 4.0 * t232;
  t3574 = t627 * t1151 * t346;
  t3591 = t4620 * t440 * t1151 * t12;
  t627 = param->s__l7x * t17;
  t3635 = 2.0 * t627 * t868 * param->m__l7 * t2;
  t3947 = 2.0 * t487;
  t3652 = t4842 * t12 * t3530;
  tmpreturn_tmp_1 = (4.0 * t114 * t721 * t204 - 4.0 * t2185) * t290;
  tmpreturn_tmp_6 = ((((((4.0 * t114 * t17 * t662 - 4.0 * t1133 * t504) - 8.0 *
    t867 * t4332) - 4.0 * t233 * t751_tmp) - 2.0 * t877 * t204) + 4.0 * t3503) +
                     t4742) * t290;
  tmpreturn_tmp_e = (-4.0 * t194 - 4.0 * t232) * t38;
  tmpreturn[23] = ((((((((((((((((((((((((4.0 * t2458 * t360 + t3903 * t290) -
    t2652) * t38 + (t3896 - t2155) * t39) + tmpreturn_tmp_1) - 2.0 * t693 * t750
    * t114) + t2681) * t105 + ((((4.0 * t2241 - 4.0 * t499) * t38 + -t4653) -
    t3494) - 4.0 * t721 * t750) * t106) + (-2.0 * t3664 - 2.0 * t823) * t39) +
    ((t3916 * t290 + 2.0 * t499) + t501) * t38) + tmpreturn_tmp_6) + t2576) -
    2.0 * t764 * t750) * t241 / 2.0 + (((((((((((((t2936 * t38 + t2957) - t3172)
    - t3408) * t105 + t228) + t3444) + tmpreturn_tmp_e) + t3590) - t3663) +
    t3679) + t3726) + t3466) - t3469) - t3491) * t288 / 2.0) + t3944) +
    (((((-2.0 * t750 * t650 + t4203) * t290 - t3538) * t38 + (-4.0 * t1689 - 4.0
    * t56) * t39) + (2.0 * t750 * t662 + t734) * t290) + t3545) * t105 / 2.0) +
    ((-4.0 * t114 * t2863 - t1603) * t290 - t1819) * t39 / 2.0) + ((((((-2.0 *
    t114 * t750 * t173 + t1028) - t127) + t4447) - t1666) * t290 + t3560) +
    t3568) * t38 / 2.0) + ((((((((2.0 * t114 * t750 * t220 + 2.0 * t3574) + 2.0 *
    t3591) - 2.0 * t2945) + 2.0 * t2948) - 2.0 * t2949) - 2.0 * t2950) - 2.0 *
    t2956) - 2.0 * t775) * t290 / 2.0) - t3573) + t3657) - t3635) - t3947) +
                    t3652) - t4844) + t3866;
  t2277 = t112 * t750;
  t2307 = t17 * t303;
  t823 = t2307 * t241;
  t868 = t294 * t750;
  t2904 = t17 * t315;
  t643 = t2904 * t241;
  t2309 = t2625 * t750;
  t775 = t241 * t114;
  t4447 = t42 * t241;
  t2983 = t303 * t750;
  t2350 = t17 * t2625;
  t2358 = t315 * t750;
  t2578 = t17 * t226;
  t2593 = t204 * t2625;
  t2576 = t2593 * t114;
  t3235 = t17 * t261;
  t2362 = t204 * t241;
  tmpreturn[30] = ((((((((((((((((((((((((((((((4.0 * t2170 * t4447 - 4.0 *
    t2983) * t114 + 2.0 * t1738 * t241) - t341) + t5208) + t353) + t596) - t1273)
    + t5054) * t38 + ((((-2.0 * t40 * t775 + t321) - t325) + t326) + t327) * t39)
    + (2.0 * t2350 * t241 + 4.0 * t2358) * t114) + 2.0 * t2195 * t241) + t767) +
    t5226) + t5228) + t888) - t749) + t5231) + t5083) + param->I__l7yy * q__p[5])
    - q__p[5] * param->I__l7xx) + ((t404_tmp - param->I__l6zz) - param->I__l7zz)
    * q__p[5]) + t5086) * t290 + ((((2.0 * t1322 - t2578) * t38 + -t2713) +
    t2576) - t3235) * 2.0 * (t241 - 1.0) * (t241 + 1.0)) * t105 / 2.0 + (((((4.0
    * t823 + 4.0 * t868) * t38 + -2.0 * t2277 * t39) - 4.0 * t643) + 2.0 * t2309)
    * t290 + (t241 + 1.0) * 4.0 * t386_tmp * (t241 - 1.0) * t204) * t106 / 2.0)
                        + (((((((((((-2.0 * t241 * t1155 - t1314) - t558) -
    t1041) + t1186) + t752) * t114 - 2.0 * t823) - 4.0 * t868) * t38 + (-4.0 *
    t120 * (t2362 + q__p[4]) * t114 + 2.0 * t2277) * t39) + (((((2.0 * t241 *
    t1157 + t1331) + t573) + t1187) - t457) + t5479) * t114) + 2.0 * t643) + 2.0
    * t2108 * t750) * t290 / 2.0) + (4.0 * t114 * t2170 * (t241 + 1.0) * (t241 -
    1.0) - 4.0 * t241 * t670) * t39 / 2.0) + (((2.0 * t114 * t17 * (t241 + 1.0) *
    (t241 - 1.0) * t173 - 2.0 * t241 * t2227) - 2.0 * t288 * t289) + 2.0 * t289)
                      * t38 / 2.0) - (t241 + 1.0) * t17 * (t241 - 1.0) * t220 *
                     t114) + t855 * t288) + t5374 * t241 / 2.0) - t855;
  t117 = (((t112 * t38 * t42 + t117) - t118) - t119) + t4227;
  t1551 = t117 * t204;
  t1292 = t117 * t290;
  t2695 = t17 * t241;
  t117 = -t120 * t204;
  t1293 = 4.0 * t117 * t39;
  t670 = t1724 * t42;
  t1301 = -2.0 * t750 * t248 + 2.0 * t670;
  t1302 = 2.0 * t3882 * t2458;
  t1303 = 2.0 * t117;
  t1316 = 4.0 * t136;
  t823 = -t120 * t17;
  t321 = t6638 * t77 * t2;
  t1322 = 2.0 * t321;
  t2917 = t95 * t204;
  t325 = t2917 * t114;
  t1327 = 2.0 * t325;
  t327 = t3432 * t722;
  t1334 = 2.0 * t327;
  t1338 = ((-8.0 * t823 * t42 - t1322) - t1327) + t1334;
  t1348 = 4.0 * t8273 * t4888;
  t868 = 2.0 * t4913 * t5584 - 2.0 * t3432 * t18;
  t1362 = t868 * t2;
  t1373 = 2.0 * t4874 * t114;
  t1389 = 2.0 * t3432 * -t171;
  t1424 = ((t1348 + t1362) - t1373) + t1389;
  t1426 = 4.0 * t1044;
  t1496 = 8.0 * t290 * -t120 * t367;
  t117 = t17 * t20_tmp;
  t3882 = t95 * t17;
  t1676 = t504 * t722;
  t1678 = (-2.0 * t117 * t2 * t6638 - 2.0 * t114 * t3882) - 2.0 * t1676;
  t2842 = 2.0 * t2983;
  t1684 = 4.0 * t8273 * t448 * t3;
  t3686 = t16 * t17;
  t1829 = 2.0 * t504 * t18 + 2.0 * t3686 * t5584;
  t353 = t1829 * t2;
  t3687 = t80 * t17;
  t1721 = 2.0 * t3687 * t114;
  t1822 = 2.0 * t504 * -t171;
  t1707 = t226 * t750;
  t1831 = 2.0 * t3664;
  t2009 = t750 * t20_tmp;
  t1359 = t2009 * t114;
  t643 = (t1359 + t187) * 4.0 * param->s__l7x * t323_tmp;
  t1603 = t141_tmp * t750 * t114;
  t1825 = 4.0 * t1603;
  t434 *= 2.0;
  t1609 = ((t5524 - t643) + t1825) + t434;
  t2776 = t497 * t108;
  t653 = 2.0 * t2776;
  t1681 = t169_tmp * t497;
  t657 = (t1681 - t85) * 4.0 * param->s__l7x * t323_tmp;
  t1151 = 2.0 * t72 * t750 * t114;
  t1724 = ((t653 - t657) + t1151) - t5598;
  t2652 = 4.0 * t823;
  t72 = -t868 * t2;
  t2681 = 2.0 * t6268 * t17;
  t2945 = 2.0 * t670;
  t670 = t823 * t290;
  t2950 = ((-t1348 + t72) + t1373) - t1389;
  t2956 = (-2.0 * t321 - 2.0 * t325) + 2.0 * t327;
  t2746 = 2.0 * t670;
  t2754 = t688 * t750 * t114;
  t4766 = (-q__p[5] * t722 + t4766) + t4854;
  t4854 = t204 * t722;
  tmpreturn_tmp_h = ((((4.0 * t670 + t653) - t657) + t1151) - t5598) * t39;
  tmpreturn_tmp_i = ((((-2.0 * t40 * t290 + t643) - t1825) - t434) - t5524) *
    t42;
  tmpreturn[37] = (((((((((((((((((t1684 + t353) - t1721) - t1822) * t290 + 2.0 *
    t1707) * t42 + (((t1678 * t290 + t1496) - t2842) * t38 + t1426)) - t1831) *
    t241 + (((t1338 * t38 + t1424 * t42) + t1819) - t1316) * t288) + (t1609 *
    t290 + t1819) * t39) + (((((t1724 * t290 + t2652) * t42 + t5833) + t1322) +
    t1327) - t1334) * t38) + ((((t6263 - t1348) + t72) + t1373) - t1389) * t42)
    + ((((t1359 / 2.0 + t187) * 4.0 * param->s__l7x * t323_tmp + -t5524) - 2.0 *
        t1603) - t6197) * t290) - t2681) * t105 / 2.0 + (((((-2.0 * t1551 * t288
    - 2.0 * t1292 * t2695) + t1301 * t38) - t1293) - t1302) + t1303) * t106 /
                       2.0) + (((((((-t2945 + t1684) + t353) - t1721) - t1822) *
    t38 + t1293) + -t1678 * t42) - t1303) * t288 / 2.0) + (((((((((((t2956 *
    t290 + t1029) + t1032) + t127) + t806) - t600) - t427) * t42 +
    (((tmpreturn_tmp_i + t2950 * t290) - t4714) * t38 + tmpreturn_tmp_h)) -
    t2746) - t6368) + 2.0 * t2754) + t6372) * t241 / 2.0) - ((-t6026 + t49) +
    q__p[2]) * t168_tmp * t4751) - (t114 * t4766 * t290 + t4854) * t168_tmp *
                   t42) + t6459;
  t308 = t1371 * t114;
  t657 = t1263 * t17;
  t187 = 2.0 * t657;
  t72 = (t308 - t187) * 4.0 * t105 * t38;
  t3730 = t18 * t7444;
  t3731 = 4.0 * t3730;
  t499 = t356 * t1226;
  t434 = 4.0 * t499;
  t325 = 8.0 * t876_tmp;
  t327 = t290 * t17;
  t3796 = t327 * t106;
  t353 = t356 * t114;
  t670 = t100 * t5571;
  t823 = (t353 / 2.0 + t670) * t290;
  t868 = t5 * t750;
  t4227 = param->s__l7y * t17;
  t4332 = t1054 * t4227 * t106;
  t4714 = t14 * t750;
  t892 = t1371 * t1226;
  t913 = t18 * t4227;
  t643 = -4.0 * t892 + 8.0 * t913;
  t653 = 4.0 * t308;
  t657 *= 4.0;
  t3838 = t4714 * t290;
  t1151 = t543 * param->m__l7;
  t418 = 2.0 * t114 * (t418 - t257) * t290;
  t499 *= 2.0;
  t487 = 4.0 * t876_tmp;
  t3839 = 2.0 * t301 * t5370;
  t1689 = t100 * param->s__l7y;
  t431 = 8.0 * t18 * t579;
  t438 = t356 * t42;
  t877 = 4.0 * t438 + t431;
  t448 = 2.0 * t26 * t3432;
  t40 = t114 * t627 + t7862;
  t706 = t4227 * t114;
  t181 = t851_tmp * t706;
  t194 = -8.0 * t181 + 4.0 * t1371;
  t232 = 2.0 * t854 * t40;
  t3875 = 2.0 * t301 * t3796;
  t233 = t8017 * param->s__l7y;
  t235 = t301 * t327;
  t243 = t370 * t750;
  t270 = t787 * t243;
  t274 = t17 * t106;
  t276 = t18 * t706;
  t277 = t1371 * t42;
  t282 = t26 * t504;
  t848 = t867 * t114;
  t373 = -t17 * t27 + t848;
  t283 = t373 * param->m__l7 * t3230;
  t344 = t4714 * t25;
  t347 = t344 + t5301;
  t854 = t17 * t114;
  t354 = (t854 * t429 + t942) * t20_tmp * t290;
  t356 = 8.0 * t417 + 4.0 * t356;
  t373 = 2.0 * t168_tmp * t373 * param->m__l7;
  t3918 = t497 + t185;
  t381 = t26 * t117;
  t392 = t750 * t290;
  t395 = 4.0 * t392 * t94 + t15 * t204;
  t422 = -t1305 + t412;
  t1305 = t15 * t497;
  t3949 = ((t1305 + t452) + t495) + t428;
  t431 = -t431 - 2.0 * t438;
  t438 = param->s__l7y * t750;
  t4751 = t438 * t16;
  t442 = t5843 * t17;
  t933 = t2009 * t290;
  t473 = t851_tmp * t933;
  t475 = 2.0 * t941 * t4857;
  t185 = 4.0 * t114 * -t2509 * t16;
  t181 = 4.0 * t181 - 2.0 * t1371;
  t136 = 2.0 * t18 * t3432 * t16;
  t308 *= 2.0;
  t414 = (-t136 + t308) - t657;
  t706 = t204 * t429 - t706;
  t814 = (t27 * t523 + t627) * t20_tmp;
  t969 = t706 * t168_tmp * t54;
  t1182 = 2.0 * t969;
  t1544 = t7817 * t17;
  t1230 = t750 * t16;
  t1274 = t5843 * t1230;
  t1290 = t18 * t504 * t16;
  t920 = t17 * t429 + t579;
  t1297 = t16 * t920 * t3230;
  t3964 = t2121 * t750;
  t1304 = -t6274 + t3964;
  t1319 = (-t854 * t27 + t867) * (2.0 * t54) * t20_tmp * t290;
  t892 = (-2.0 * t920 * t168_tmp * t54 + 2.0 * t892) - 4.0 * t913;
  t3530 = q__p[5] * -t947;
  t913 = t91 * t17;
  t920 = 2.0 * t4857 * t1384 + 2.0 * t3838;
  t3993 = t787 * t16;
  t927 = 2.0 * t3993 * t370 * t17;
  t933 = -t933 * t249 + t867;
  t1006 = t7128 * t5658;
  t2509 = t42 * t17;
  t1296 = t4291 * t114;
  t1035 = t2509 * t1296 / 2.0;
  tmpreturn_tmp_3 = 2.0 * t275 * (t429 * t523 - t4227);
  tmpreturn_tmp_c = 2.0 * t275 * t40;
  tmpreturn_tmp_p = t194 * t16;
  tmpreturn_tmp_q = t422 * t16;
  tmpreturn_tmp_s = t431 * t16;
  tmpreturn_tmp_t = t181 * t16;
  tmpreturn_tmp_n = t643 * t290;
  tmpreturn_tmp_r = t892 * t290;
  tmpreturn[44] = (((((((((((((((((((((((((((((4.0 * t276 - 2.0 * t277) * t16 +
    t282) * 2.0 * t290 * t105 + -2.0 * t7386 * t370 * t274) + 2.0 * t283) - 2.0 *
    t347 * t42) * t38 + ((((4.0 * t5694 * t233 - t3875) - 2.0 * t235) + 2.0 *
    t270) - t1419) * t39) - t3875) - (2.0 * t868 * t249 + t354) * 2.0 *
    param->m__l7 * t105) + (t356 * t16 + t373) * t290) + t218 * t16) - 2.0 *
    t3918 * param->s__l7y * t275) * t241 + (((((((-4.0 * t105 * t117 * t26 -
    t3839) - 2.0 * t1387) * t39 + ((-2.0 * t1689 * t77 * t106 + (t877 * t16 -
    t448) * t105) - tmpreturn_tmp_c) * t38) - t3839) - tmpreturn_tmp_3 * t105) +
    tmpreturn_tmp_p) - t232) * t288) + ((t5547 * t301 + t347 * t290) + t381) *
    (2.0 * t105) * t39) + (((((tmpreturn_tmp_m * t3949 + tmpreturn_tmp_q) * t290
    + tmpreturn_tmp_s) + t448) * t105 + 2.0 * t26 * t395 * t106) + ((t114 * t817
    - 2.0 * t4751) * t290 + t442) * 2.0 * param->m__l7 * param->s__l7x) * t38) +
    (-2.0 * t473 + 2.0 * t1387) * t106) + ((2.0 * t344 + 2.0 * t6281) * t290 +
    t475) * t105) + ((-t114 * t7733 + t2009 * t429) * tmpreturn_tmp + t185) *
    t290) + tmpreturn_tmp_t) + t232) * t2 / 2.0 + ((((((((((((((((t3796 + t327)
    + q__p[4]) * (-4.0 * t26) * param->s__l7x * t39 + (-8.0 * t105 * t823 - 4.0 *
    t941 * t868) * t38) - 4.0 * t4332) + 2.0 * t4714 * t5172) + tmpreturn_tmp_n)
    + t156) + t47) * t241 + (((((t106 + 1.0) * -4.0 * t204 * t39 * t76 - t72) -
    t3731) + t434) + t325) * t288) + 4.0 * t26 * t105 * (t750 * t543 + t5547) *
    param->s__l7x * t39) + ((((-t158 * t290 + t653) - t657) * t105 + -4.0 *
    t4714 * t4246) + 2.0 * t3838) * t38) + t3731) + 4.0 * t1151 * t5 * t750 *
    t105) - t418) - t499) - t487) * t3 / 2.0) + ((((((((-2.0 * t105 * t17 * t91
    + t7444) + t942) * 2.0 * param->m__l7 * t180 + ((-2.0 * t5370 * t1384 *
    t2149 - 2.0 * t706 * t16 * t275) + t105 * t414) * t38) + 2.0 * t3730) + 2.0 *
    t54 * t814 * t105) - t1182) - t499) - t487) * t288 / 2.0) + (((((((((((t7817
    * t274 / 2.0 + t2849 * t5694) + t1544 / 2.0) + t1274 / 2.0) + t45 / 2.0) *
    4.0 * param->m__l7 * t180 + ((-2.0 * t446 * t54 * t2149 * t274 + ((t1290 +
    t353) + 2.0 * t670) * (2.0 * t290) * t105) - (-param->s__l7x * t1304 * t42 +
    t1297) * 2.0 * param->m__l7) * t38) + 2.0 * t4332) + (-t2458 * -t947 - t1319)
    * t105) + tmpreturn_tmp_r) - 2.0 * t3918 * param->m__l7 * t7904) - t3530 *
    t42) - t230) * t241 / 2.0) - ((t1304 * t290 + t6335) - t913) * param->m__l7 *
    t6839 * t39) + ((((((((tmpreturn_tmp * t3949 * t94 + t3530) + t371) * t290 +
    t136) - t308) + t187) * t105 + t920 * t106) + (t750 * t4291 - 2.0 * t3993 *
    t4914) * t290) - t927) * t38 / 2.0) - t26 * t933 * t106) + ((t16 * t266 -
    t3964) * param->s__l7x * t290 - t1006) * param->m__l7 * t105) + ((-t114 *
    t8528 + t2009 * t27) * -2.0 * param->m__l7 * t16 - t114 * t8365) * t290 /
                     2.0) + t969) - t1035) + t876_tmp;
  t1419 = q__p[0] * t4229;
  t817 = ((((((((((((t148_tmp + t3883) - t505) - t508) + param->I__l7yy) + t511)
                - param->I__l7xx) + t515) - param->I__l4xx) + param->I__l4yy) -
            param->I__l5yy) + param->I__l5zz) + param->I__l6xx) - param->I__l6zz;
  t1197 = (((((((((((((((-t340 * param->m__l6 + param->I__l4xx) - param->I__l4yy)
                       + param->I__l5yy) - param->I__l5zz) - param->I__l6xx) +
                    param->I__l6zz) + param->I__l7xx) - param->I__l7yy) + t1195)
                + t1197) + t1202) + t1204) - t489) - t491) + t505) + t508;
  t3730 = q__p[2] * t1197;
  t1204 = q__p[1] * t1197;
  t3731 = t1204 * t440;
  t3796 = t1260 * t628;
  t1202 = 2.0 * t114 * t1680;
  t4332 = (((((-t9 + t576) - t98) + t28) + t32) + t35) - t102;
  t4246 = 2.0 * t114 * t4332;
  t1195 = t148 * t39;
  t3838 = 2.0 * t193 * t42;
  t4914 = 2.0 * q__p[4] * t1132;
  t40 = 2.0 * t440 * t214 * t696;
  t3839 = (param->l__5 * q__p[4] * t78 + param->l__4 * t240) + t899;
  t240 = t304 * t440;
  t98 = t12 * t386_tmp;
  t3875 = t1419 * t1170;
  t3918 = t386 * t290;
  t340 = (tmpreturn_tmp_u - t4920 / 2.0) * (4.0 * t114) * t290;
  t78 = t1038 * t695;
  t669 += (((t544 - t8) + t143) - t28) - t32;
  tmpreturn_tmp_u = param->m__l6 * (2.0 * t3839);
  tmpreturn_tmp_m = (((t1806 + t2013) + t1141) + t239) - t46;
  tmpreturn[3] = ((((((((((((((((((((((((((((((-t4395 - t127) + t140) + t144) -
    t145) + t149) - t152) - t154) * t38 + t958) + t960) + t182) + t191) + t195)
    - t735) * 2.0 * t12 * t346 + 2.0 * t3796 * t5769) + (t940 * t4670 - t4971) *
    2.0 * t204) * t106 + (((((((((((((((-t290 * t4711 - t1314) - t558) - t1041)
    + t1186) + t752) * t38 + (2.0 * t598 * t1101 * t12 + 8.0 * t120 * t6833 *
    t39)) - tmpreturn_tmp_v) - t457) + t1187) + t5479) + t573) + t1331) * t940 +
    ((((((((-t290 * t4409 + t1202) * t38 + (-t963 + t860) * t39) -
    tmpreturn_tmp_w) - t4246) * t12 + (-2.0 * t991 * t1154 * t1170 - 8.0 * t1260
    * t12 * t4229 * t940)) + 2.0 * t991 * t1154) * t346 + ((4.0 * t1170 * t732 *
    t633 + 2.0 * t12 * t1154 * q__p[1]) - 4.0 * t732 * t633) * t267) + ((t481 *
    t38 - t668) - t4676 / 2.0) * (4.0 * q__p[0]) * t1170)) + (((2.0 * t606 *
    t1195 + (-t5956 - t3701) * t38) + 2.0 * t606 * t4297) - t3115) * t12) - 2.0 *
    t5973 * t4752) * t105) + ((2.0 * t1170 * t817 * t1260 + 2.0 * t12 * q__p[1] *
    t897) - 2.0 * t817 * t1260) * t267) + ((((((((((((((-t290 * t4445 + t1029) +
    t1032) + t127) + t806) - t600) - t427) * t38 + t964) + ((-t4458 - 2.0 *
    t3731) + t4476) * t290) + t1069) - t847) + t3838) - t4914) * t12 + (-2.0 *
    t991 * t897 * t1170 - ((t38 * t4372 + t4379) + t4384) * 8.0 * q__p[0] *
    t7956)) + 2.0 * t991 * t897) * t346) + ((((((((((((((((t516_tmp + t3883) -
    t505) - t508) + param->I__l7yy) + t511) - param->I__l7xx) + t515) -
    param->I__l4xx) + param->I__l4yy) - param->I__l5yy) + param->I__l5zz) +
    param->I__l6xx) - param->I__l6zz) * t290 + t801) + t4679) - t4681) * 2.0 *
    q__p[0] * t1170) + (((((((tmpreturn_tmp_x - t5054) * t114 + -t290 * t4733) +
    t40) * t38 + (2.0 * t991 * t386 * t12 - tmpreturn_tmp_9)) + ((t4739 - t4742)
    - 2.0 * t3730) * t290) + ((((((((tmpreturn_tmp_u + t1281) - t720) + t1021) -
    t888) + t749) + t5076) - t5083) - t5086) * t114) + 2.0 * t440 * t4382 * t696)
    * t940) + (((((2.0 * t796 + 2.0 * t240) * t38 + 4.0 * t360 * t894) - 2.0 *
                 t609 * t114) + 2.0 * t525 * t440) - 2.0 * q__p[1] *
               param->m__l4 * param->s__l4y * t522) * t12) - 2.0 * t4775 * t695)
    * t241 / 2.0 + ((((((-4.0 * t139 * (t940 - 1.0) * t4229 * t267 - ((((2.0 *
    t940 * t732 * t386_tmp + t4320) + t4323) - t4324) - t955) * 4.0 * t12 * t346)
                        - ((((t940 * t1419 + t4421) + t4657) + t4658) - t707) *
                        4.0 * t940) * t105 + -4.0 * t5496 * t628 * t106) - 4.0 *
                      t1329 * t5769) - (((((q__p[0] * t817 * t940 + t4327) +
    t4330) + t4331) - t4335) - t3730 / 2.0) * 4.0 * t12 * t346) + (((((-2.0 *
    t4444 * t38 - 2.0 * t1082) - t3731) + t4661) - t4836) + t4846) * 2.0 * t940)
    * t288 / 2.0) + (((((2.0 * t1170 * t386_tmp * t197 + t940 * t12 * t628) -
                        2.0 * t386_tmp * t197) * (2.0 * q__p[0]) * t346 + -4.0 *
                       t338 * t98 * t267) + ((((t1034 * t290 + t5727) * t38 +
    -2.0 * t828) + (t1079_tmp + t781) * t290) - 2.0 * t831) * t940) + ((((t1680 *
    t440 + 2.0 * t1121) * t38 + 2.0 * t810) - 2.0 * t338 * t315) - t440 * t4332)
                     * 2.0 * t12) * t106 / 2.0) + (((((((((t38 * t4517 - t4528)
    - t605) * (4.0 * q__p[0]) * t7956 + -2.0 * t11 * t4670 * t1170) + (((t38 *
    t5458 + t1124) + t5481) - t956) * t12) + 2.0 * t598 * t3796) * t346 + ((2.0 *
    t12 * t4670 * t433 - 2.0 * t1419) + 2.0 * t3875) * t267) + 2.0 * t3875) +
    (((((((t4797 - t1110) * t290 - 4.0 * t4407) + t4800) * t38 + (-2.0 * t991 *
    t667 * t12 - tmpreturn_tmp_a)) + (2.0 * t1038 * t4676 + t4807) * t290) + 4.0
      * t4421) - t4810) * t940) - (((((t226 * t606 - 2.0 * t1189) * t290 + 2.0 *
    t598 * t4859) * t38 + t634 * t114 * t586) + (t261 * t606 + t1081) * t290) -
    t598 * t4875) * (2.0 * t12)) * t105 / 2.0) + ((2.0 * t1170 * t1329 + 2.0 *
    t471 * t1437) - 2.0 * t1329) * t267 / 2.0) +
                     (((((((((((((((((((((t148_tmp_tmp + t1128) + t484) + t489)
    + t491) + t496) + t3883) - t505) - t508) + param->I__l7yy) + t511) -
    param->I__l7xx) + t515) - param->I__l4xx) + param->I__l4yy) - param->I__l5yy)
    + param->I__l5zz) + param->I__l6xx) - param->I__l6zz) * (2.0 * t724) * t940
                        + -2.0 * t991 * t3918 * t1170) + (((((((((((((t1859 -
    t1145) * t2 + t1858) + tmpreturn_tmp_y) - t1160) + t1164) + t3839 *
    param->m__l6) - t5082) - t5085) - t1175) * (2.0 * t114) * t290 + (((t340 +
    t4614) - t970) * t38 + t789)) + t4635) - t4640) - 2.0 * t1523 * q__p[2]) *
                       t12) + 2.0 * t991 * t3918) * t346 / 2.0) + (((t4782 +
    t4783) + t622) - t751_tmp) * q__p[0] * t1170) + (((((((((t4540 + t427) -
    t1032) - t806) * t290 + t1004) * t38 + -2.0 * t991 * t290 * t897 * t12) +
    (((((-2.0 * t114 * t5191 * t696 - 2.0 * t78 * t281) + t1378) - t3838) +
      t4914) + t847) * t290) + t4836) - 2.0 * q__p[1] * t2426 * t440) - t4846) *
                   t940 / 2.0) + (((((2.0 * t598 * t679 - 2.0 * t676) * t290 -
    (tmpreturn_tmp_m - t4893) * (2.0 * t440)) * t38 + 4.0 * t440 * t669 * t39) +
    ((-2.0 * t1139 * t566 * t440 - 2.0 * t565 * t606) - 2.0 * t1126) * t290) +
    ((((-t4918 + t4922) + t28) + t32) - t101) * (2.0 * t440)) * t12 / 2.0) -
    (((((((t214 * t38 + t1133) + t4380) + t4381) - t506) - t566) + t851) - t856)
    * q__p[0] * t124;
  t144 = (t346 - 1.0) * q__p[1];
  t8 = t446 * t267;
  t149 = t304 * t346;
  t154 = t1204 * t290;
  t140 = -t2413 * t267;
  tmpreturn[10] = ((((((((((((((((((((((((((((((((((((-t2421 + t1026) - t1027) -
    t1028) + t1029) + t1031) + t1032) + t1033) * t38 + (t2415 + q__p[4]) * 2.0 *
    t112 * t39) + t2423) + t1069) + t1074) + t1076) + t781) * t440 + 2.0 * t112 *
    (t346 - 1.0) * q__p[1] * t3004 * t39) + ((-4.0 * t8 * t595 - 4.0 * t149) +
    4.0 * t640) * t38) + 2.0 * t800 * t1040) + 4.0 * t316 * t346) - 2.0 * t800 *
    t290) * t106 + ((((((((((((((((-t346 * t3611 - t1202) + t2438) * t38 +
    (t2437 - t860) * t39) - tmpreturn_tmp_j) - t3584) + t4246) * t440 + 2.0 *
    t346 * q__p[2] * t1195) + (((((-4.0 * t359 * t360 * t346 - tmpreturn_tmp_k)
    - t3010) - t3675) - t3019) - t3696) * t38) - tmpreturn_tmp_d) + 2.0 * t330 *
    t693 * t346) + t3697) + t3699) + t3700) - tmpreturn_tmp_g) + t3721) - t3881)
    * t105) + ((((((((((((((((-t346 * t3601 - t1029) - t1032) - t127) - t806) +
    t600) + t427) + t337) + t3602) * t38 + 2.0 * t346 * (t3585 + t5363) * t39) +
    (-2.0 * t1197 * q__p[0] * t471 - 2.0 * t780) * t346) + t3001) + t1378) +
    (t115 * t42 + t1072) * t2) + ((-2.0 * t1039 + 2.0 * t1047) - 2.0 * t193) *
    t42) - t296) + t4914) * t440) + t3891) + (((-t3268 * t267 + 2.0 * t149) +
    t3233) + t3217) * t38) + (-2.0 * t154 + 2.0 * t4010) * t267) + 2.0 * t525 *
    t346) + 2.0 * t154) - tmpreturn_tmp_l) - t4044) * t241 / 2.0 + (((((((-t38 *
    t2357 - t2311) + t2397) - t2407) * t440 - 4.0 * t144 * (t346 + 1.0) * t4229)
    * t105 + 2.0 * t440 * t628 * t5370) + (((-2.0 * t1197 * t204 -
    tmpreturn_tmp_b) + t842) - t2411) * t440) - 4.0 * t144 * t1363 * (t346 + 1.0))
    * t288 / 2.0) + (((((((((4.0 * t3344 + 4.0 * t726) * t38 + -2.0 * t799 *
    t374) - t3345) - t746) * t440 + t3423) + ((-t3113 + t4411) + t3326) * t38) +
                       t3327) + t4425) - t1596) * t106 / 2.0) + (((((((((((4.0 *
    t290 * t411 + -t3346 * t346) * t39 + ((-t4266 * t346 + t1277 * t290) - 4.0 *
    t5864) * t38) - t1767_tmp) + t1298 * t290) + tmpreturn_tmp_5) * t440 +
    (((-t2052 * t267 - t2122) + t2660) - t802) * t39) + ((((-t534 - t4860) *
    t346 + -t2422 * t267) + t2402) - t811) * t38) - t886_tmp) + (-2.0 * t538 +
    2.0 * t4876) * t346) - t2440) + t818) * t105 / 2.0) + (((((((((((((((((t771
    + t1258) * t2 + t767) + t5228) + t1259) - t952) - t749) - tmpreturn_tmp_u) +
    t5083) + t5086) + t720) * t114 - t4000) * t290 + ((((-t730 * t346 - t340) +
    t970) * t38 + -t825 * t39) - t1511)) + 2.0 * t3503) - (t1022 * t42 + t5344) *
    (4.0 * t18) * t2) - t1019) - 2.0 * t4642 * q__p[0] * t940) + 2.0 * q__p[2] *
    t4842) * t440 / 2.0) + 2.0 * t346 * t669 * t39) + (((((((((t553 + t2410) +
    t4185) + t1345) - t1423) + t230) + t3681) * t346 + t140) - t1853_tmp) - t837)
                      * t38 / 2.0) - t1882_tmp) + (((((-t571 - t4626) + t4921) +
    t29) + t33) - t102) * t346 / 2.0) + (((-t3486 * t42 - t4459) - t3506) +
    t3592) * t290 / 2.0) - t772;
  t149 = t623 * t878_tmp;
  t193 = t112 * t878_tmp;
  t144 = t878_tmp * t120;
  t154 = (-t4889 - t4890) + t757;
  tmpreturn[17] = ((((((((((((((((((((((((((((((((-t3903 * t290 - 4.0 * t144 *
    t1226) - t1314) - t558) - t1041) + t1186) + t752) * t38 + ((2.0 * t114 *
    t193 - t4772) - t3896) * t39) - tmpreturn_tmp_1) + 2.0 * t693 * t878_tmp *
    t114) - t457) + t1187) + t5479) + t573) + t1331) * t105 + ((((-4.0 * t2241 +
    4.0 * t149) * t38 + t4653) + t3494) + 4.0 * t878_tmp * t721) * t106) -
    tmpreturn_tmp_f) + (((((((2.0 * t154 * t93 + t1273) + t660) - t596) + t977)
    + t341) * t114 + -t3916 * t290) - 2.0 * t149) * t38) - tmpreturn_tmp_6) +
    (((((((((2.0 * param->m__l6 * param->s__l6x * t154 + 2.0 * t239) - 2.0 * t46)
    * t42 + (t1281 + t1021)) - t888) + t749) + ((-2.0 * param->l__4 * t757 - 2.0
    * param->l__5 * t757) + 2.0 * t899) * param->m__l6) - t5083) - t5086) - t720)
    * t114) + 2.0 * t764 * t878_tmp) * t241 / 2.0 + (((((((((((((-t2936 * t38 -
    t2957) + t3172) + t3408) * t105 + -t228) - t3444) - tmpreturn_tmp_e) - t3590)
    + t3663) - t3679) - t3726) - t3466) + t3469) + t3491) * t288 / 2.0) + t3944)
    + (((((2.0 * t878_tmp * t650 + t4203) * t290 + t3538) * t38 + -t1443 * t39)
        + (-2.0 * t878_tmp * t662 + t734) * t290) - t3545) * t105 / 2.0) + (4.0 *
    t114 * t878_tmp * t639 + t1819) * t39 / 2.0) + ((((((((2.0 * t114 * t878_tmp
    * t173 - t1029) - t127) + t675) - t806) + t600) + t427) * t290 - t3560) -
    t3568) * t38 / 2.0) + ((((((-2.0 * t114 * t878_tmp * t220 - 2.0 * t3574) -
    2.0 * t3591) + t1378) + t847) + t849) + t859) * t290 / 2.0) + t3573) - t3657)
                      + t3635) + t3947) - t3652) + t4844) - t3866;
  tmpreturn[24] = ((((((((((((t155 * t38 + t3431) + t182) + t191) + t195) - t645)
    * t114 * t105 + t107) + t661) + (tmpreturn_tmp_m - t385) * t38) + t345) +
                     t576_tmp) - t28) - t32) + t101;
  t101 = -t17 * t241 + t415;
  t173 = t112 * t101;
  t565 = 2.0 * t173 * t39;
  t191 = param->m__l7 * t750;
  t515 = t5 * t191 * t3;
  t566 = 8.0 * t515;
  t93 = t301 * t750;
  t605 = (-4.0 * t117 * t241 * t851_tmp + 4.0 * t313) + 4.0 * t93;
  t609 = 4.0 * t141_tmp * t17 * t4447;
  t634 = 4.0 * t80 * t750;
  t155 = t101 * t14;
  t695 = t155 * t3;
  t669 = 2.0 * t695;
  t46 = t2458 * t20_tmp;
  t751_tmp = -(t94 * t2695) + t1177;
  t586 = (t751_tmp - t46) * t6664_tmp * t323_tmp;
  t1026 = 2.0 * t4572 * t17 * t241;
  t1027 = t4526 * t750;
  t1028 = 4.0 * t1027;
  t102 = t2362 + t327;
  t107 = t102 + q__p[4];
  t489 = t101 * param->s__l7y * t18 * t3;
  t1031 = 8.0 * t489;
  t1033 = t14 * t241;
  t856 = (4.0 * t191 * t20_tmp * t429 + 4.0 * t3686 * t1033) - 4.0 * t4631;
  t496 = t3687 * t241;
  t955 = 4.0 * t496;
  t956 = 4.0 * t447 * t750;
  t1069 = t163 * t204 * t241;
  t167 -= t172;
  t1072 = 2.0 * t167 * t204 * t241;
  t1074 = 2.0 * t167 * t17 * t290;
  t167 = t20_tmp * t241;
  t172 = t77 * t241;
  t447 = t117 * t290;
  t1204 = ((-t216 + t118) + t119) + t219;
  t1034 = 2.0 * t204 * t1204 * t241;
  t1281 = 2.0 * t17 * t1204 * t290;
  t1126 = t26 * t172;
  t1133 = t26 * t447;
  t1139 = 2.0 * t2917 * t241;
  t1378 = 2.0 * t3882 * t290;
  t1345 = t204 * -t252 * t241;
  t1423 = t17 * -t252 * t290;
  t1806 = ((t254 + t256) - t258) + t260;
  t661 = 2.0 * t204 * t1806 * t241;
  t1197 = 2.0 * t17 * t1806 * t290;
  t1141 = (t751_tmp - t46 / 2.0) * tmpreturn_tmp_7 * t323_tmp;
  t1202 = t17 * t1132 * t241;
  tmpreturn_tmp_1 = ((((2.0 * t4714 * t3 - ((t750 * t94 - t2509 * t167) + t53) *
                        t6664_tmp * t323_tmp) + 4.0 * t17 * t4526 * t241) -
                      t4564) - 2.0 * t750 * t4572) * t114;
  tmpreturn[31] = ((((((((((((((((((((((((((((t17 * t163 * t290 + t1069) + t608)
    + t613) + t618) + t2010) * 4.0 * param->m__l7 * t697 + (((((t856 * t2 +
    t3330) - t1031) - t955) - t956) * t114 - 2.0 * t157 * t107 * t3)) - t1072) -
    t1074) - t1314) - t558) + t752) * t38 + (-4.0 * t120 * t107 + t2155) * t39)
    + tmpreturn_tmp_1) - t457) + (((((-t172 / 2.0 - t447 / 2.0) + t694) - t700)
    - t701) + t709) * 4.0 * param->m__l7 * t697) + t1034) + t1281) + t5479) +
    t573) + t1331) * t105 / 2.0 + ((((((((((t605 * t2 - t435) + t566) + t609) -
    t634) * t38 + t565) + t669) - t586) + t1026) - t334) + t1028) * t106 / 2.0)
    - t773) + (((((((((((-2.0 * t1126 - 2.0 * t1133) + t89) - t593) * t2 + t341)
                     - t1139) - t1378) + t660) - t596) + t1273) - t5054) * t114
               + t2842) * t38 / 2.0) + (((((((((((((4.0 * t2509 * t290 * t76 +
    4.0 * t241 * t76 * t367) + t1278) + t479) * t3 + (((2.0 * t1345 + 2.0 *
    t1423) + t1284) - t513) * t2) - t661) - t1197) + t5076) - t888) + t749) +
    t839) - t5083) - t5086) - t720) * t114 / 2.0) - t695) + t1141) - t1202) +
                   t1051) - t1027;
  t182 = -t120 * t101;
  t256 = t182 * t105;
  t1680 = 4.0 * t256;
  t191 = -2.0 * t112 * t107 + t1680;
  t195 = t750 * -t120;
  t220 = 4.0 * t195 * (t105 + 1.0) * (t105 - 1.0);
  t239 = -2.0 * t105 * t173 - t5710_tmp * t107;
  t385 = 2.0 * t1707 * t105;
  t149 = 2.0 * t4854 * t168_tmp * t241;
  t154 = 2.0 * t17 * t722 * t7068;
  t214 = 2.0 * t750 * (t105 + 1.0) * (t105 - 1.0) * t112 * t42;
  t281 = 2.0 * t226 * t101 * t106;
  t173 = param->s__l7x * t750;
  t576 = ((t4227 * t167 + t173 * t168_tmp) - t3230 * t942) * tmpreturn_tmp * t2;
  t315 = 2.0 * t3882 * t241;
  t525 = 2.0 * t2917 * t290;
  t254 = t750 * t168_tmp;
  t538 = 2.0 * t254 * -t171;
  t553 = t2983 * t105;
  t571 = t504 * t241;
  t340 = t3432 * t290;
  t640 = t504 * -t171 * t241;
  t89 = t3432 * -t171 * t290;
  t660 = 2.0 * t256;
  t484 = 2.0 * t101 * t303 * t106;
  t489 *= 4.0;
  t491 = 2.0 * t301 * t101 * t2;
  t496 *= 2.0;
  t505 = 2.0 * t750 * t722 * t168_tmp;
  t506 = t195 * t106;
  t508 = t6290 * t105;
  tmpreturn[38] = (((((((((((((((((((((-param->m__l7 * t5826 + t239 * t42) +
    t1029) + t127) + t385) + t149) + t154) + t806) - t600) + t5831) * t114 +
    t214) + t281) + t234 * t105) + t576) + t315) - t525) - t538) * t38 / 2.0 +
                       (t114 * t191 - t220) * t39 / 2.0) + (((((((((((-2.0 *
    t571 * t18 - 2.0 * t340 * t18) - 2.0 * t183) - 2.0 * t6253) * t2 + (2.0 *
    t553 - t1709)) + 2.0 * t640) + 2.0 * t89) + t6259) + t257) + t6261) * t42 -
    t660) + 2.0 * t107 * t6268) * t114 / 2.0) + ((((((-2.0 * t105 * t4766 *
    t168_tmp - t557) + t484) + t489) + t491) + t496) + t505) * t42 / 2.0) + t506)
                   + t508) - t195;
  t183 = (t302 / 2.0 + t299) - t76 / 2.0;
  t234 = t750 * t183;
  t1314 = t101 * param->s__l7x;
  t511 = t2009 * t16;
  t299 = 2.0 * t155;
  t302 = ((4.0 * t695 - (t1314 * t16 - t46 / 4.0) * (8.0 * t26) * t2) + 2.0 *
          t851_tmp * t511) - t299;
  t256 = 4.0 * t515;
  t258 = 2.0 * t1314 * t275 * t42 + 2.0 * t93;
  t515 = t20_tmp * t101;
  t260 = (t515 * t249 + t173) * 2.0 * param->s__l7y * param->m__l7;
  t119 = 4.0 * t2776;
  t216 = 4.0 * t2205 * t4751;
  t219 = t101 * t42;
  t851 = (((t172 + t447) + t530) + t555) + t266;
  t266 = 2.0 * t4714 * t114;
  t1273 = t26 * t1314 * t114;
  t2013 = t14 * t107;
  t522 = 2.0 * t2013 * t42;
  t172 = (-4.0 * t1273 - t522) + t412;
  t345 = t107 * param->s__l7x;
  t1331 = t26 * t345 * t42;
  t1284 = 4.0 * t1331;
  t447 = (-2.0 * t114 * t155 + t479) + t1284;
  t571 += t340;
  t155 = ((t571 + t452) + t495) + t428;
  t428 = 2.0 * t1273;
  t1273 = -2.0 * t107 * t787 * t370 - 2.0 * t93;
  t1278 = (t107 * t16 * t5843 - t438) * tmpreturn_tmp * param->s__l7x;
  t479 += t1284;
  t1284 = t522 - t412;
  t1314 *= 4.0 * t26;
  t1419 = t114 * t155 + t46;
  t1331 *= 2.0;
  t93 = t101 * -t947;
  tmpreturn_tmp_6 = t1273 * t2;
  tmpreturn_tmp_e = t447 * t16;
  tmpreturn[45] = (((((((((((((((-t114 * t219 * t370 + param->s__l7x * t851) -
    t216) * 2.0 * param->m__l7 * t2 + t119) - (param->s__l7y * t851 + t515 *
    t7420) * 2.0 * param->m__l7 * t16) - t266) * t38 + -4.0 * t183 * t114 * t101
    * t39) + t172 * t3) + (((param->s__l7x * t155 + t1359 * t429) - t7542) *
    tmpreturn_tmp + tmpreturn_tmp_e) * t2) - ((param->s__l7y * t155 + t1359 *
    t27) + t8354) * tmpreturn_tmp * t16) + t428) - t4291 * t107 * t42) - t257) *
                     t105 / 2.0 + ((((4.0 * t234 * t39 + t302 * t38) + t258 * t2)
    + t256) - t260) * t106 / 2.0) + ((tmpreturn_tmp_6 - t256) - t1278) * t39 /
                    2.0) + ((((((t114 * t1284 + t1314) * t16 - 2.0 * t26 * t1419)
    * t2 + (t114 * t479 - t299) * t3) - tmpreturn_tmp * t1419 * t94) + (-t1331 -
    t3530) * t114) + t93) * t38 / 2.0) - (t6055 + t2458) * param->m__l7 *
    t168_tmp * (t1262 + t94);
  t495 = (t940 - 1.0) * t386_tmp * t139 * t288;
  t155 = q__p[1] * t288;
  t851 = t155 * t440;
  t530 = t440 * t1178 * t514;
  t555 = t225 * t1012;
  t558 = t440 * t2625;
  t573 = t558 * q__p[0];
  t1419 = t386_tmp * t204;
  t593 = t1600 * t1170;
  t600 = t7360 * t741;
  t452 = t1178 * q__p[0];
  t608 = t114 * t1178;
  t1859 = 2.0 * t519;
  t1858 = 2.0 * t306;
  t174 *= t290;
  t519 = t221 * t290;
  t221 = t987 * t1080;
  t618 = 2.0 * t2139 * t1260 * t1170;
  t623 = q__p[3] * t2217;
  t596 = 2.0 * t623;
  t679 = 2.0 * t5690 + 2.0 * t679;
  t613 = 2.0 * t2483;
  t628 = 2.0 * t262 * t290 - 2.0 * t707;
  t262 = t147 * t1080;
  t707 = 2.0 * t2227;
  t1080 = t2108 * q__p[2];
  tmpreturn[4] = (((((((((((((((((((((((((((((((((((4.0 * t1269 - 4.0 * t595) *
    t39 + (-8.0 * t1436 - t811) * t38) - 4.0 * t3198 * t12) + t818) * t940 + 8.0
    * t1600 * t598 * t1170) + ((((t994 - t320) + t821) - t63) - t73) * 2.0 * t12
    * t39) + (((-t114 * t1216 + t70) - t1222) * t12 - 8.0 * t965) * t38) +
    ((((-t1489 * t114 + t1859) - t1858) + t326) - t2923) * t12) + 8.0 * t966) *
    t241 + ((((-2.0 * t896 * t940 - t1971) + (t231 - t532) * t38) + t2190) -
    t537) * -2.0 * t12 * t288) - 2.0 * t3786) + (((-t1093 + t4607) * t38 - t1158)
    - t3634) * t940) + ((4.0 * t122 * t290 + t1002) * t12 - 4.0 * t6726) * t39)
    + (((2.0 * t174 + -t1015) - 2.0 * t532) * t12 - 2.0 * t6807) * t38) + ((-2.0
    * t2190 - 2.0 * t519) - 2.0 * t537) * t12) + 2.0 * t2119) * t346 +
    ((((((((((-8.0 * t4243 + t253) * t38 + -t895) + 8.0 * t7095) + t512) * t241
    + -2.0 * t1601 * (t940 - 1.0) * t452 * t288) - 2.0 * t608 * t514) + (-4.0 *
    t2497 - t297) * t39) + (-2.0 * t2097 + t3040) * t38) + 2.0 * t4464) + 2.0 *
    t2191 * q__p[0]) * t267) - ((((t608 * t49 - t352) + tmpreturn_tmp_z * t38) +
    t1541) + t919) * (2.0 * t940) * t288) + ((((((((((((-t1183 + t1013) - t534)
    + t175) * t38 + ((-t1048 - t1008) + t123) * t39) + t2472) + 2.0 * t1038 *
    t2050) - t539) + (-t221 + t7626) * 2.0 * param->m__l7 * t2) + 2.0 * t696 *
    t1582 * t440) - 2.0 * t1204 * q__p[3]) * t940 + -t895) + 4.0 * t1089) * t241)
    + (((2.0 * t360 * t38 * t42 - t1195) + t2191) + t2031) * 4.0 * q__p[0] *
    t1170) + ((((((8.0 * q__p[0] * t791 * t2057 + t1546 * t114) - 4.0 * t211 *
    t290) * t38 + (-2.0 * t331 + 2.0 * t332) * t39) - 8.0 * t440 * t2101 * t724)
               - tmpreturn_tmp_10) + 2.0 * t406 * t290) * t940) + t7081) +
    ((t1030 * t114 - t871 / 2.0) * (4.0 * t440) * t12 - 4.0 * t342) * t38) +
    (t114 * t2110 + t937) * 2.0 * t440 * t12) - t3323) * t105 / 2.0 +
    ((((((((((((((((-4.0 * t530 - 8.0 * t98 * t644) - 4.0 * t112 * t6632 * t39)
    + (-4.0 * t12 * t1030 + 8.0 * t555) * t38) + (t41 - t3438) * t12) + 4.0 *
    t573) * t241 + -4.0 * t98 * t851) - 2.0 * t1616) * t346 + ((4.0 * t1178 *
    t241 * t189 - 4.0 * t495) - 4.0 * t2707_tmp) * t267) - 4.0 * t1419 * t940 *
            t288) - 2.0 * t2735 * t241) + 8.0 * t593) + ((((((-8.0 * t600 +
    t2414) + t305) * t38 + 4.0 * t291 * t6523 * t39) - 4.0 * t558 * t2554) +
    t1826) - t317) * t940) + 2.0 * t1411 * q__p[2] * t471 * t39) + (-4.0 * t12 *
    t1099 * t440 - 4.0 * t179) * t38) - 2.0 * t440 * (t1639 + t1020) * t12) +
     t206) * t106 / 2.0) + ((((((((((2.0 * t729 - t1152) * t39 + -t618) + (-4.0 *
    t294 * t189 - t1736) * t38) - 2.0 * t2189 * t12) + 2.0 * t500 * t543) * t241
    + 2.0 * t495) + 2.0 * t593) + 2.0 * t1232 * t38) - 2.0 * t622 * t8128) + 2.0
    * t200) * t267 / 2.0) + (((((((((((((((4.0 * t12 * t2147 - t837) * t38 - 4.0
    * t2154 * t12) - t863) * t940 + 2.0 * t530) + (2.0 * t360 * t8128 + t799) *
    2.0 * t440 * t39) + (((2.0 * t349 - 2.0 * t871) * t114 + t2152) * t12 - 4.0 *
    t555) * t38) + (((-2.0 * t358 + 2.0 * t937) * t114 - t1117) + t596) * t12) -
    2.0 * t573) * t241 + ((((2.0 * t2139 * t49 - 2.0 * t330 * t1309) + (-t2129 +
    t1103) * t38) + t2135) - t561) * 2.0 * t12 * t288) + 2.0 * t11 * t667 *
    t1170) + (((2.0 * t550 * t724 * t38 + 4.0 * t724 * t738) - 2.0 * t500 *
               t1740) + (t290 * t2217 + t2353) * (2.0 * q__p[1])) * t940) + 4.0 *
    t12 * -t567 * t39) + (((t114 * t679 + t1104) - t613) * t12 - 2.0 * t4370) *
    t38) + ((t114 * t628 + t2237) - t2239) * t12) - 2.0 * t991 * t622 * t290) *
    t346 / 2.0) + ((((t1600 * t940 + t271) + (t932 + t304) * t38) - t2137) -
                   t316) * t940 * t288) + (((((((((((((((((2.0 * t61 - (t262 -
    t7655) * 2.0 * param->m__l7 * t2) - 2.0 * t696 * t171 * t440) + 2.0 * t599) *
    t114 + -t2848) - t236) - t707) * t38 + t372) - 2.0 * t991 * t1140) +
    ((((-2.0 * q__p[3] * -t252 * t2 - 4.0 * t42 * t5585 * t76) + 2.0 * q__p[3] *
       t1806) - t1147) - t672) * t114) + t343) + t265) + t2469) + t29) + t33) -
    t284) * t940 + -t618) - ((((((((((((t589_tmp_tmp + t398) + t886) - t1663) +
    t413) + t1534) + t878) - t880) + t503) + t890) + t784) - t824) + t401) * 2.0
    * q__p[1] * t12) * t241 / 2.0) - ((((t38 * t2359 - t312) - t314) + t521) +
    t2496) * 2.0 * q__p[0] * t1170) + ((((((-2.0 * t303 * t6027 + 4.0 * t600) *
    t38 + -2.0 * t1476 * t1260 * t39) + 2.0 * t440 * t2354 * t724) - 2.0 * t1580
    * t290 * t1226) - 2.0 * t623 * t290) + t906) * t940 / 2.0) - (t114 * -t822 +
    t482) * t440 * t12 * t39) + (((t2702 - 2.0 * t1018) + t335) * (-2.0 * t440) *
    t12 + 2.0 * t2485) * t38 / 2.0) + ((t114 * t406 - t1080 * t290) + t365) *
                  t440 * t12) - t2641;
  t171 = -t984 + t3438;
  t252 = t2593 * t290;
  t112 = t1420 * t940 * t3;
  t109 *= t76 * t49;
  tmpreturn[11] = (((((((((((((((((((((((((-t319 * t440 - t731) * t38 + -4.0 *
    t49 * t1309) - tmpreturn_tmp_0) + t807) * t346 + ((-t2763 * t38 + t3329) -
    t996) * t267) - ((((t879 - t320) + t821) - t63) - t73) * (2.0 * t440) * t39)
    + ((((4.0 * t2241 - 4.0 * t335) * t114 - t70) * t440 + t881) + t995) * t38)
    + (((((2.0 * t252 + t1339) * t114 - 2.0 * t677) - 2.0 * t705) + t952) +
       t1858) * t440) - t474) + t996) * t241 + (((((-2.0 * t452 * t1354 * t346 -
    tmpreturn_tmp_4) - 2.0 * t3324 * t433) - t2268) - t3355) + t1416) * t288) +
    (((-t570 * t39 - t402) - t1416) + t666) * t267) + (((((((((((((-t1045 * t440
    + t114 * -t1458) + t1733) + t516) - t524) - t97) + t1709) * t38 + (-t1043 *
    t440 - t1347) * t39) - t617) + t171 * t114) + t457) - t762) + t649) + t293) *
    t346) - 4.0 * t665 * t639 * t39) + (-t174 + t532) * 2.0 * t440 * t38) + (2.0
    * t519 + 2.0 * t537) * t440) - 2.0 * t3437 * t338) * t105 / 2.0 + (((((((4.0
    * t3325 * t4054 - 4.0 * t1038 * t1178 * t346) + t387) + (-t1458 * t440 -
    t891) * t38) + t171 * t440) - t71) * t241 + -4.0 * t833 * t386_tmp * t288) -
    ((((((2.0 * t1091 + 2.0 * t2241) - 2.0 * t335) * t38 + (2.0 * t708 * t346 -
    t1044)) - 2.0 * t1257) + t252) + t1020) * 2.0 * t346) * t106 / 2.0) +
    (((((2.0 * t2198 * t98 - t786) + 2.0 * t708 * t267) + t1417) - t2665) +
     t2778) * t288 / 2.0) + (((((((((((-t115 * t2 - t1733) + t524) + t97) -
    t1709) * t114 - 2.0 * t490) * t440 - t509) + t891) * t38 + ((((((-t450 *
    t440 - t59) * t38 + -t404) - t1096) - 2.0 * t732 * t940 * t261) * t346 +
    (((t588 + t1540) - t3331) - t71) * t267) + t1747)) + (((((-t589 * t42 + t762)
    - t457) - t293) * t114 + 2.0 * t876) - t596) * t440) + t3331) - t770) * t241
                        / 2.0) + ((-t671 * t38 - t2778) - t716) * t267 / 2.0) +
                      ((((((((-t1100 * t440 + 4.0 * t1018) - t501) - t753) * t38
    + (t114 * t328 - 2.0 * t482) * t39) - t1839_tmp) + ((tmpreturn_tmp_o + 2.0 *
    t259) + 2.0 * t306) * t114) + (((2.0 * t1132 * t940 * q__p[0] - 2.0 * t1080)
    - 2.0 * t112) + 4.0 * t109) * t290) + t1020) * t346 / 2.0) - 2.0 * t440 *
                     -t567 * t39) + ((-t114 * t679 + t613) * t440 + t1233) * t38
                    / 2.0) + (-t114 * t628 - 2.0 * t1374) * t440 / 2.0) + t1330;
  t73 = 2.0 * t2578;
  t261 = 2.0 * t2576;
  t320 = 2.0 * t3235;
  t171 = t2238 * t114;
  t328 = t2185 * t114;
  tmpreturn[18] = ((((((((((((((((((-4.0 * t2170 * t1226 - 2.0 * t1738) * t290 +
    t175) * t38 + (2.0 * t854 * t291 + t123) * t39) + (-2.0 * t114 * t2350 - 2.0
    * t2195) * t290) - t222) * t241 + ((((-t578 + t73) * t38 + 2.0 * t2713) -
    t261) + t320) * t288) + (-2.0 * t204 * t148 + t329) * t39) + (((4.0 * t114 *
    t2983 - 4.0 * t211) * t290 + t578) - t73) * t38) + (((-4.0 * t114 * t2358 -
    t1859) + t1858) - t326) * t290) + t261) - t320) * t105 / 2.0 + (((((-4.0 *
    t1419 * t288 - 4.0 * t633 * t2695) + 2.0 * t2277 * t205) + (-4.0 * t2863 *
    t446 + 4.0 * t289) * t38) - 2.0 * t2309 * t290) - 4.0 * t855) * t106 / 2.0)
                        + ((((-2.0 * t171 + 2.0 * t289) * t38 + -4.0 * t854 *
    t1309) + 2.0 * t328) - 2.0 * t855) * t288 / 2.0) + (((((((((((((4.0 * t5305
    - t265) + t1070) - t350) - t351) + t284) * t39 + (((2.0 * t114 * t1155 + 2.0
    * t2307) * t290 + t229) - t707) * t38) + (-2.0 * t114 * t1157 - 2.0 * t2904)
    * t290) + t264) + t265) + t2469) + t29) + t33) - t284) * t241 / 2.0) + (4.0 *
    t120 * t854 - 2.0 * t193 * t290) * t39 / 2.0) + (((2.0 * t114 * t871 + 4.0 *
    t144 * t42) * t290 + 2.0 * t171) - 2.0 * t289) * t38 / 2.0) + (((((-2.0 *
    t2108 * t440 * t724 - 2.0 * t1132 * q__p[3]) - 2.0 * t114 * t937) - 2.0 *
    t2385 * t346) + t1017) - t758) * t290 / 2.0) - t328) + t855;
  tmpreturn_tmp_0 = -4.0 * param->m__l7;
  tmpreturn[25] = ((((((((((((((((((((((((-t856 * t2 - t3330) + t1031) + t955) +
    t956) * t114 + ((2.0 * t203 * t2509 + 2.0 * t1033 * t367) - t412) * t3) +
    ((tmpreturn_tmp_0 * t627 * t163 * t290 - 4.0 * t1069 * t18) - t166) * t2) +
    t1072) + t1074) + t97) * t38 + (4.0 * t120 * t102 - t2155) * t39) -
    tmpreturn_tmp_1) - t457) + ((t867 * t167 / 2.0 + t627 * t3230 / 2.0) + t6057
    * t42) * 4.0 * param->m__l7 * t2) - t1034) - t1281) - (((t145 - t82) + t152)
    + t201) * 2.0 * t42) * t105 / 2.0 + ((((((((((-t605 * t2 + t435) - t566) -
    t609) + t634) * t38 + -t565) - t669) + t586) - t1026) + t334) - t1028) *
    t106 / 2.0) - t773) + (((((((2.0 * t1126 + 2.0 * t1133) + 2.0 * t24) * t2 +
    t341) + t1139) + t1378) + 4.0 * t246) * t114 - t2842) * t38 / 2.0) +
                       (((((((2.0 * t275 * t34 - 2.0 * t1345) - 2.0 * t1423) *
    t2 + -4.0 * t76 * t42 * t102 * t3) + t661) + t1197) + t326) - t1858) * t114 /
                       2.0) + t695) - t1141) + t1202) - t1051) + t1027;
  t222 = t400 * q__p[6];
  t145 = t222 * t16;
  t64 = -t64 * t65 * param->m__l7;
  t152 = ((((t64 + param->I__l7yy) + t1173) - param->I__l6yy) - param->I__l7zz)
    + param->I__l6xx;
  tmpreturn[32] = ((((((((t6592 * t3 - (-2.0 * t51 + t52) * t26 * t2) - t63) +
                        t152 * q__p[5]) * t42 * t38 + (((((t145 + t23) * t2 +
    -t9) - t29) - t33) + t35) * t39) + t9) + (-t145 - t22) * t2) + t28) + t32) -
    t35;
  t33 = t107 * t20_tmp;
  t51 = t141_tmp * t107;
  t64 = (((((((((t1049_tmp + t64) + t1173) + param->I__l6xx) - param->I__l6yy) +
             param->I__l7yy) - param->I__l7zz) * (-2.0 * t101) * t105 - 2.0 *
           t750 * t400 * t5867) + 4.0 * t18 * (-t1681 + t33) * t2) - 2.0 * t750 *
         t152 * t114) - 4.0 * t51;
  t65 = 2.0 * t400 * t107 * t3;
  t32 = t107 * param->s__l7y;
  t35 = t32 * t16;
  t145 = (t1359 + t35) * 4.0 * param->s__l7x * t323_tmp;
  t152 = 2.0 * t152 * t107;
  t163 = ((t2 * t6880 - t300) + t76) + t79;
  t300 = -t750 * t105;
  t79 = t101 * t114;
  t222 = 2.0 * t222 * t3;
  t264 = t515 * t114;
  t265 = 2.0 * t133;
  t284 = 2.0 * t101 * t95 * t114;
  t291 = t101 * t688;
  t24 = param->m__l7 * t107;
  t73 = t2149 * t24 * t2;
  tmpreturn[39] = (((((((((((t385 - t222) - ((t264 + t265) - t21) *
    tmpreturn_tmp * t1262) - t284) + t1029) - t427) + t1032) + t806) * t42 / 2.0
                      + ((((((t1680 + t65) + t145) - t1825) + t152) * t42 +
    ((t300 + t79) - q__p[5]) * (2.0 * t163)) * t38 / 2.0 + t64 * t39 / 2.0)) +
                     t291 * t105) - t73) + t2754) + t51;
  t329 = t105 * t101 + t497;
  t22 = t329 * param->m__l7;
  t1029 = t854 * t241;
  t1032 = t523 * t290;
  t341 = ((t300 - t1029) + t1032) - q__p[5];
  t21 = t341 * t14;
  t95 = -4.0 * t22 * t38 * t5 - 2.0 * t21;
  t350 = (t38 + 1.0) * param->m__l7;
  t133 = 4.0 * t350 * param->s__l7y * t345 * (t38 - 1.0);
  t326 = t329 * t14;
  t300 = -2.0 * t33 * t26 - 2.0 * t326 * t16;
  t9 = t2013 * t16;
  t22 *= t370;
  t23 = -t9 + t22;
  t28 = (-param->s__l7y * t329 + t33 * t16) * t18 * t38;
  t29 = ((t1270 - t890) + t784) + t824;
  t32 = (t329 * t16 * t20_tmp + t32) * param->s__l7x;
  tmpreturn[46] = ((((t300 * t38 - (t217 * t341 * t16 + t52) * tmpreturn_tmp *
                      param->s__l7y) * t42 + (t38 + 1.0) * 2.0 * t23 * (t38 -
    1.0)) * t2 / 2.0 + (t95 * t42 - t133) * t3 / 2.0) + ((2.0 * t341 * t29 - 2.0
    * t28) - 2.0 * t63) * t42 / 2.0) + t350 * t32 * (t38 - 1.0);
  t350 = (t940 - 1.0) * t120;
  t457 = t350 * t139 * t106;
  t320 = t1012 * t3938 / 2.0;
  t171 = t189 * t106;
  t328 = -t2856 * t290;
  t252 = t56 * t106;
  t63 = 2.0 * t5864;
  t316 = -t5761 * t290;
  t317 = (((t866 + t890) - t784) + t824) * q__p[6];
  t360 = (((-t5922 * t2 + t2444) - t2452) + t2457) * t290;
  t329 = 4.0 * t5 * q__p[4] * t5868;
  t532 = t301 * t1005;
  t351 = -2.0 * t275 * t57 - 2.0 * t532;
  t261 = 2.0 * t81 * t114;
  t599 *= 2.0;
  t294 = 2.0 * t2518;
  t539 = t132 * t311;
  t312 = t215 * t805;
  t866 = t1049 * t106;
  t304 = 2.0 * t539;
  t805 = 2.0 * t192;
  t305 = 2.0 * t317 * t290;
  t598 = (t697 - t169_tmp) * t20_tmp;
  t622 = t31 * t114 * t311;
  t314 = q__p[4] * t688;
  t697 = 2.0 * t314;
  t331 = 4.0 * t1181;
  t1173 = -2.0 * t5310 + 2.0 * t834;
  t365 = 2.0 * t96 * t114;
  t537 = 2.0 * t6284;
  t521 = (-t376 * t114 / 2.0 + t48) * 4.0 * param->s__l7x * t323_tmp;
  t534 = 2.0 * t376 * t6386;
  t85 = (t85 / 2.0 + t1799) * (4.0 * t18) * t2;
  t550 = t5526 * q__p[3];
  t811 = 2.0 * t550 * t114;
  t174 = t440 * t688;
  t586 = t6279 * t598 * t290;
  t821 = t314 * t114;
  tmpreturn_tmp_1 = 2.0 * t1127 * (t940 + 1.0);
  tmpreturn_tmp_z = -t2348 * t2;
  tmpreturn_tmp_4 = (-t331 + -t1173 * t2) + t365;
  tmpreturn[5] = ((((((((((((((((((((((((((((((((((4.0 * t724 * t1567 * t940 +
    t2453) + ((-t42 * t1739 + t316) + 2.0 * t317) * t12) - t2085) * t105 +
    (((-t12 * t1326 + t1271) - t1578) - t1368) * t106) - t2364) + (-4.0 * t2369
    - (t110 * t42 + t215) * (2.0 * t114) * q__p[1]) * t940) + (((((t351 * t2 +
    t360) - t329) + t261) - t599) - t2434) * t12) + t992) * t241 + (((((((-t106 *
    t510 * t3185 + t105 * t2038) + t63) - t2279) + t2280) + t2289) - t6148) +
    t6149_tmp) * (2.0 * t12) * t288) + 2.0 * t1764 * t106) + (((((t2036 + t3018)
    + t3252) - t294) * t12 + (-t2449 - tmpreturn_tmp_11)) + t740) * t105) +
    t2843) + (tmpreturn_tmp_8 * t2864 - 2.0 * q__p[1] * t2914) * t940) +
    ((((-2.0 * t539 + 2.0 * t312) + 2.0 * t192) * t290 + (t2231 + t2881) * t42)
    + 2.0 * t1038 * t2266) * t12) - t2912) * t346 + ((((((((((-t105 * t2248 -
    4.0 * t785 * t189) + t362) + 2.0 * t416) - 2.0 * t2352) * t241 +
    tmpreturn_tmp_1 * t309 * t288) - 2.0 * t6975 * (t940 + 1.0) * t1049 * t106)
    - t2347 * t105) + t2748) - t2794) - t2808) * t267) + (((((((t105 * t2853 -
    t866 * t367) + tmpreturn_tmp_z) - t2644) - t2294) + t2315) - t2335) + t2351)
    * (2.0 * t940) * t288) + ((((((((((t1664 + t2093) + t6341) - t40) * t940 +
    -t1462) + (t2099 + t240) * 2.0 * t12) * t105 + 2.0 * t1763 * t106) - t2473)
    + (((((-t42 * t2661 + 2.0 * t312) - t304) + t805) - t2475) + t6175) * t940)
    + 4.0 * t685 * t330 * t12) + t2716) * t241) + (((-t3229 * t940 + t1863) +
    t3236) - t2032) * t106) + ((((2.0 * t6643 * t1640 * t42 - 2.0 * t1121) -
    ((((t6902 + t58) * t2 + t268) + t2255) - t81) * (2.0 * t440)) * t12 +
    (((((t328 - t486) * t42 + t2163) - t305) - t1004) * t940 + -t2162)) + t2265)
    * t105) - t2913) + (((((((((((t262 + t7655) * 2.0 * param->m__l7 + 2.0 *
    t532) * t2 + t329) - t261) - 2.0 * t696 * t2715) + t599) * t290 + -2.0 *
    t2938) - t2444) + t2448) + t2452) - t2457) * t940) + (-t2939 * t42 -
    (((t3292 - (t34 * t25 - t376 / 2.0) * (2.0 * t18) * t2) + t1283 * t114) -
     t3310) * (2.0 * t440)) * t12) + t3314) * t38 / 2.0 + (((((((((((((((((8.0 *
    t120 * t1586 * t471 * t106 + ((-t12 * t3193 - t1629) + t3204) * t105) -
    tmpreturn_tmp_12) + t2900) * t241 + ((t105 * t1049 * t1586 - t320) - t6310) *
    -8.0 * t12 * t288) + 4.0 * t1012 * t171) + (-t940 * t3430 + t2223) * t105) -
    t3369) + (t328 - t1163) * t12) + t1213) * t346 + (((((((2.0 * t423 + t601) -
    t1535) * 4.0 * t105 * t241 + 4.0 * t350 * q__p[0] * (t940 + 1.0) * (t106 +
    1.0) * t288) + 4.0 * t457) - t1352) + t3301) + t3307) * t267) + ((t1038 *
    t105 * t1049 + t252) + t56) * 4.0 * t940 * t288) + (((((4.0 * t601 + 4.0 *
    t3203) - 4.0 * t423) * t105 + -4.0 * t788 * t714 * t106) - tmpreturn_tmp_13)
    + t3183) * t241) - (((t797 / 2.0 + t514) + t278) - t209) * (8.0 * t120) *
    t106) + (((-t2230 + t2880) - t2692) * t940 - t2707) * t105) + t1214) -
    tmpreturn_tmp_14) - t458) * t39 / 2.0) + ((((((((-t105 * t6162 - 4.0 * t3940
    * t171) + 2.0 * t6328) * t241 + tmpreturn_tmp_1 * t2003 * t288) - 2.0 * t457)
    - 2.0 * t6222 * t105) - 2.0 * t6411) - 2.0 * t6414) + 2.0 * t6410) * t267 /
    2.0) + (((((((((((((((((((2.0 * t598 * t6279 + t2662) * t42 - t2506) - 2.0 *
    t622) + t6193) + t697) * t12 + (4.0 * t225 * t930 * t940 + t6164)) - t1003) *
    t105 + (((-t12 * t3402 + t3319) - t3372) - t3425) * t106) - t6331) +
                     (((((((((((-t2892 + t108) - t111) + t60) + t6194) - t878) +
    t880) + t886) + t890) - t784) + t824) * 2.0 * t433 + t6334) * t940) +
                    ((((((t1173 * t2 + t331) - t365) - t537) + t2383) * t42 -
                      t6347) - t6350) * t12) + t6353) * t241 +
                  (((((((((tmpreturn_tmp_z / 2.0 + t2303) - t2335 / 2.0) + t2351
    / 2.0) * t42 + -t6139) - t2304 / 2.0) * t105 + t320) + t6306) + t6309) +
                   t6310) * (-4.0 * t12) * t288) + 2.0 * t6109 * t106) + (((((((
    -2.0 * t2316 - 2.0 * t2319) * t2 + -t2444) + t2452) + t2457) * t42 + 2.0 *
    q__p[2] * t6268) * t12 + (t6227 - tmpreturn_tmp_15)) - t6247) * t105) +
               t6421) + (t12 * t2259 - t1060 * q__p[1]) * (2.0 * t42) * t940) +
             ((((((t127 - t521) - t534) + t1666) * t290 - t2254) * t42 +
               (((-t1432 + t85) - t811) - t6372) * t290) + t486) * t12) - t6445)
    * t346 / 2.0) + ((((t105 * t6152 - t252) - t542) + t6315) + t6316) * t940 *
                        t288) + (((((((((((((t316 + t127) - t521) - t534) +
    t1666) * t42 + -t6363) + t6366) - t1432) + t85) - t811) - t6372) * t940 +
    (((((((t360 - t1110) * t42 + -t6205) - t6209) * t940 + -t6159) - (t606 *
    t6244 - t1210) * 2.0 * t12) * t105 + 2.0 * t6099 * t106) + t6359)) - 2.0 *
    t330 * t174 * t12) - t6402) * t241 / 2.0) + (((-t6119 * t940 + t1214) +
    t6125) - t6126) * t106 / 2.0) + ((((2.0 * t69 - ((((-t6278 + t5301) * t2 +
    -t6277) + t6285) + t96) * 2.0 * t440) * t42 + 2.0 * t440 * (t544 - t6290)) *
    t12 + (((((-2.0 * t586 - 2.0 * t626) * t42 + t1120) + ((2.0 * t622 - 2.0 *
    t1757) - 2.0 * t314) * t290) + 2.0 * t1038 * t688) * t940 + -t6252)) + t6296)
                     * t105 / 2.0) - t875) + (((((((tmpreturn_tmp_4 - t40) +
    t537) * t290 - t3018) - t3252) - t294) * t42 + -2.0 * t6451) + 2.0 * t6459) *
                   t940 / 2.0) + ((((-t114 * t132 * t311 + t114 * t275 * t48) +
    t6488) * 2.0 * t440 * t42 + 2.0 * t433 * t688 * t290) - ((-t31 * t311 + t821)
    + t1755) * (2.0 * t440)) * t12 / 2.0) - t6301;
  t81 = t120 * t833;
  t96 = t81 * t106;
  t34 = t750 * t106;
  t7 = 4.0 * t7 * t1667;
  t108 = q__p[4] * t303;
  t120 = t43 * t323_tmp;
  t111 = q__p[4] * t226;
  tmpreturn[12] = (((((((((((((((((((((((((((((-t792 * t42 - t554) - t127) + t7)
    - t1666) - t337) * t440 + (((-t408 * t42 - t455) * t440 + t453) * t346 +
    (-t383 * t42 - t407) * t267)) - t2436) + t407) * t105 + (((4.0 * t1038 *
    t226 * t346 - t2441) - 4.0 * t1644 * t724) + t1093) * t106) + (-2.0 * t979 +
    2.0 * t1092) * t267) + (-t580 * t440 - (t940 * t168_tmp * t1137 - 2.0 * t568)
    * (2.0 * t114)) * t346) + (((-2.0 * t114 * t108 + 2.0 * t504 * t6273) + 2.0 *
    t659) + 2.0 * t227) * t440) + t957) * t241 + ((((((((2.0 * t11 * t1308 *
    t346 + 2.0 * t1644 * t433) - 2.0 * t3100) - 2.0 * t615) * t105 + -2.0 * t833
    * t42 * t866) - 2.0 * t3093 * t267) - 2.0 * t791 * t3294 * t346) - t3226) +
    t364) * t288) + (((-t1049 * t346 * t638 - t1057) + t712) + t2903) * 2.0 *
    t346 * t106) + ((((((-t730 * t440 + t885) + 2.0 * t108) - t229) * t346 +
                      t140) + (-t1714 + t294) * t440) - t1774) * t105) + (-t1134
    * t42 - t1136) * t267) + (((((-t1118 * t42 + t1119) * t440 - t4452) - 2.0 *
    t49 * t248) + (((-t127 + t7) - t337) - t1666) * t114) - t1608) * t346) +
    (((((-2.0 * t312 + 2.0 * t120) - 2.0 * t74) + 2.0 * t1047) * t290 + t1782) +
     t63) * t440) - t1787) * t38 / 2.0 + (((((((((((((((8.0 * t471_tmp + t1403) *
    t267 + 4.0 * t914 * t346) - t688_tmp) - t1403) - t1406) * t105 + -t973) +
    (-2.0 * t1012 * t290 + t346 * t2911) * 2.0 * t204) * t241 + ((4.0 * t96 +
    4.0 * t592) + 4.0 * t81) * t288) + 4.0 * t898 * t34) - (2.0 * t151 * t639 +
    t1457) * (2.0 * t204) * t105) + (t1451 - t1597) * t267) + ((-t2143 * t440 +
    t2659) + t123) * t346) + t2711) - t2819) + t802) * t39 / 2.0) + ((((((((2.0 *
    t12 * t1014 * t346 * t7360 + 2.0 * t1226 * t267 * t676) - 2.0 * t1794) - 2.0
    * t1798) * t105 + -2.0 * t96) + 2.0 * t1865 * t267) + 2.0 * t791 * t6301 *
    t346) + t1862) - t1871) * t288 / 2.0) + ((((((((((((((-2.0 * t263 - 2.0 *
    t120) + 2.0 * t74) - 2.0 * t1047) * t42 - t733) - t697) * t440 + ((-t1884 *
    t440 - 2.0 * t226 * t359) * t346 + -t1861 * t267)) + t1882) + t1854) + t1235)
    * t105 + (((-4.0 * t225 * t245 * t267 + 4.0 * t510 * t346 * t676) - t4033) +
              t3934) * t106) + 2.0 * t1648 * t267) + (2.0 * t4354 - ((((-t940 *
    q__p[0] * t5526 + t49 * t2892) - t112) + 2.0 * t109) + t6240) * (2.0 * t114))
    * t346) + ((((-2.0 * t4360 * t7068 + 2.0 * t114 * t111) + 2.0 * t335) * t42
                + 2.0 * t921) + t6350) * t440) - t4362) * t241 / 2.0) + (((-t346
    * t595 - t4538) + t4539) + t122) * t346 * t106) + (((((((-2.0 * t336 - 2.0 *
    t111) * t42 + t3412) + t4693) - t3397) * t346 + -2.0 * t4355 * t267) +
    ((((2.0 * t940 * q__p[0] * t688 + 2.0 * t1022 * t42 * t699) - 2.0 * q__p[2] *
       t5526) - t939) + t1668) * t440) + t4231) * t105 / 2.0) + ((-t4357 - t2819)
    + t802) * t267 / 2.0) + (((((((-2.0 * t120 + 2.0 * t74) - 2.0 * t1047) *
    t114 + -t87) + t2169) * t42 + -t5626 * t440) - 2.0 * t821) - t529) * t346 /
                     2.0) + ((((((-2.0 * t376 * t99 - t127) + t7) - t1666) -
    t337) * t290 - t59) * t42 + (t4772_tmp * t6268 + t411) * 2.0 * t290) * t440 /
                    2.0) + t4273) - t595;
  t122 = -t1829 * t2;
  tmpreturn[19] = (((((((((((((((((((2.0 * t878_tmp * t303 + -t1678 * t290) -
    t1496) * t38 + -t1426) + ((((-t1684 + t122) + t1721) + t1822) * t290 - 2.0 *
    t878_tmp * t226) * t42) + t1831) * t105 + 2.0 * t1292 * t274) -
    tmpreturn_tmp_h) + ((((-2.0 * q__p[3] * t68 * t722 + t1424 * t290) -
    tmpreturn_tmp_i) - t304) + t805) * t38) + ((((-t2956 * t290 + t127) - t521)
    - t534) + t1666) * t42) + t2746) - t1432) + t85) + ((-2.0 * t688 * t346 *
    q__p[1] - 2.0 * t174 * t724) - 2.0 * t550) * t114) - t6372) * t241 / 2.0 +
                       ((((((((-t1338 * t38 + t2950 * t42) - t1819) + t1316) *
    t105 + 2.0 * t1551 * t106) - t1293) + ((((t2945 - t1684) + t122) + t1721) +
    t1822) * t38) + t1678 * t42) + t1303) * t288 / 2.0) + (((-t1301 * t38 +
    t1293) + t1302) - t1303) * t106 / 2.0) + (((((((((-t1724 * t290 - t2652) *
    t42 - t305) - t1322) - t1327) + t1334) * t38 + (-t1609 * t290 - t1819) * t39)
    + ((((-2.0 * t586 + t1348) + t1362) - t1373) + t1389) * t42) + ((-2.0 * t946
    * t2009 * t2 + 2.0 * t1603) - 2.0 * t314) * t290) + t2681) * t105 / 2.0) +
                    ((((-t351 * t2 + t329) - t261) + t599) * t290 + 2.0 * t504 *
                     t699) * t38 / 2.0) + ((tmpreturn_tmp_4 + t537) * t290 + 2.0
    * t1676) * t42 / 2.0) + t6459;
  t122 = t102 * param->s__l7y;
  tmpreturn[26] = ((((((((((((((((((-t239 * t42 + t127) - t385) - t149) - t154)
    - t7) + t1666) * t114 - t214) - t281) - 2.0 * t108 * t105) - t576) - t315) +
    t525) + t538) * t38 / 2.0 + (-t114 * t191 + t220) * t39 / 2.0) +
                      (((((((((((t571 + t52) * (2.0 * t18) * t2 + -2.0 * t553) -
    2.0 * t640) - 2.0 * t89) - 2.0 * t192) * t42 + t660) - 2.0 * t102 * t14 * t3)
    + 4.0 * t122 * t16 * t698) - 2.0 * t204 * t5526 * t241) - 2.0 * t17 * t5526 *
                        t290) + t697) * t114 / 2.0) + ((((((2.0 * t105 * t111 +
    t557) - t484) - t489) - t491) - t496) - t505) * t42 / 2.0) - t506) + t508) +
    t195;
  tmpreturn[33] = (((((((((((2.0 * t750 * t163 - 4.0 * t182 * t42) * t105 +
    (((-t65 - t145) + t1825) - t152) * t42) + 4.0 * t18 * t101 * t2121 * t3) + (
    -2.0 * t79 * t6880 - 2.0 * t184) * t2) - 2.0 * t80 * t101 * t114) + t805) *
                       t38 / 2.0 + -t64 * t39 / 2.0) + (-2.0 * t1707 * t42 - 2.0
    * t291) * t105 / 2.0) + (((2.0 * t26 * (t264 - t265) * t2 + -t222) + t284) +
    q__p[6] * t4291) * t42 / 2.0) + t73) - t2754) - t51;
  tmpreturn[40] = -t6290;
  t52 = t341 * param->m__l7;
  t80 = t52 * t5;
  t127 = (-2.0 * t326 * t38 + t522) + 4.0 * t80;
  t192 = param->s__l7x * t38;
  t11 = -2.0 * param->s__l7y;
  t123 = ((t11 * t105 * t101 * t16 - 2.0 * t1681) + t33) * param->m__l7 * t192;
  t226 = ((t105 * t515 + t1359) + 2.0 * t35) * param->m__l7 * t429;
  t303 = (-t1029 + t1032) - q__p[5];
  tmpreturn_tmp_1 = ((-2.0 * t105 * t101 * t86 + 2.0 * t5842 * t24) - 2.0 * t497
                     * t86) * t38 / 2.0;
  tmpreturn_tmp_h = ((tmpreturn_tmp * t5304 * t101 * t16 + 2.0 * t107 * t86) +
                     2.0 * t511 * t6638) * t42 / 2.0;
  tmpreturn[47] = (((((((-2.0 * t105 * t1230 * t14 + 2.0 * t14 * t16 * t303) -
                        2.0 * t123) - 2.0 * t226) - 2.0 * t184) * t2 / 2.0 +
                     t127 * t3 / 2.0) + tmpreturn_tmp_1) + tmpreturn_tmp_h) + ((
    -param->s__l7x * t303 + t105 * t173) + t62) * t26;
  t595 = t1818 * t288;
  t101 = t851 / 2.0 + t1573 * t241;
  t615 = (((((((t101 + t1038 / 2.0) * (2.0 * t12) * t346 + (t288 + 1.0) * q__p[0]
               * t5769) + t595) - t150 * t241 * t440 * t290) - t1085) - t797) -
          t1108) + q__p[0];
  t639 = t241 * q__p[1];
  t676 = (((t150 * t290 / 2.0 + t6514 * t241) * t346 + -t10 * t241 * t12) + t639
          * t12 / 2.0) + (t6524 + t6526) * t290;
  t699 = t5691 / 2.0;
  t722 = t615 * param->s__l7y;
  t62 = t2168 * t290;
  t107 = t16 * t106;
  t733 = (t940 - 1.0) * t4856;
  t802 = 2.0 * t733 * t16 * (t940 + 1.0) * t288;
  t542 = 2.0 * t6818 * t465 * t288;
  t184 = t16 * t940;
  t544 = 2.0 * t4413 * t184 * t288;
  t696 = t6976 * t288;
  t1012 = t1569 * t288;
  t1049 = t5828 + t7069;
  t303 = (t7738 + t7739) * param->m__l7;
  t1110 = param->s__l7x * t241;
  t7 = t57 * t7068;
  t697 = t424 * param->s__l7y;
  t336 = -t697 - t50;
  t110 = t940 * param->m__l7;
  t63 = t196 * t3230;
  t81 = t63 - t7752;
  t805 = t1038 * t7156;
  t33 = t295 * t168_tmp;
  t35 = t763 * t3230;
  t51 = t1022 * t290 + t78;
  t24 = (t1038 * t124 + t1022) * t42;
  t64 = t204 * t288;
  t124 = 2.0 * (t249 * t18) * t1127;
  t1029 = t124 * t696;
  t14 = q__p[5] * t4291;
  t1022 = -t7701 + t8533;
  t96 = -t371 + t14;
  t1032 = t54 * t288;
  t108 = q__p[3] * t947;
  t111 = t31 * t7068;
  t120 = (-t763 * t20_tmp - t111) * t114;
  t145 = t424 * param->s__l7x;
  t132 = -t145 + t419;
  t152 = t184 * param->m__l7;
  t163 = -t35 - t1583;
  t424 = q__p[1] * t4291;
  t411 = t295 * t8300;
  t215 = q__p[4] * t947 * t42;
  t453 = t215 + t257;
  t184 = t14 * t42;
  t529 = -t42 * t163;
  tmpreturn_tmp_i = 2.0 * t110 * t20_tmp;
  tmpreturn_tmp_z = 2.0 * t152 * t20_tmp;
  tmpreturn_tmp_4 = tmpreturn_tmp * t288;
  tmpreturn_tmp_5 = 2.0 * t8017 * t168_tmp;
  tmpreturn_tmp_f = (t20_tmp * t196 - t7) * t114;
  tmpreturn_tmp_j = (-t184 + t230) * t290;
  tmpreturn[6] = (((((((((((((((((((((((((((((((((((((((((((((t12 * t7055 *
    t7139 + t7173) * 2.0 * param->m__l7 * t940 + -t7051) + (-t16 * t7065 - 2.0 *
    t1049 * t26) * t12) + t7077) * t241 + 8.0 * t7026 * t288) - t7117) - t7122)
    + (-t16 * t7126 - 2.0 * t303) * t12) + t7136) * t346 + ((-8.0 * t1012 * t5 *
    t7010 - t6543 * t7111) - t241 * t7047) * t267) - 4.0 * t7039 * t288) +
    ((((t7085 - 4.0 * t290 * t7087 * t16) - ((t7625 + t221) + t7626) * 2.0 *
    param->m__l7) * t940 + -t7080) - 2.0 * t7044) * t241) - t7146) + ((((-t7151 *
    t290 + t7150) + t7153) * t16 + -t7149) + 2.0 * t6926 * t7075) * t940) +
    (-t1740 * t440 * t6963 + q__p[0] * t7181) * 2.0 * param->s__l7y *
    param->m__l7) * t105 + (((((((((t15 * t288 * t189 * t440 + t241 * t6967) -
    4.0 * t6983) * t346 + ((t20_tmp * t225 * t1569 + 8.0 * t639 * t2540) + t696 *
    t6975) * t267) + t396 * t77 * t288) - t6972 * t241) - t6987) + t6996) -
    t7004) + t7005) * 2.0 * param->s__l7y * t8231) + ((((2.0 * t225 * t26 *
    t1569 * t7207 - 2.0 * t1110 * t7216) - 4.0 * t7278) - 4.0 * t7281) + 4.0 *
    t7282) * t267) + ((((((((4.0 * t678 * t6896 - (t7013 + t251) * 2.0 * q__p[1]
    * t114) * t940 + t7220) - ((t3230 * t7202 / 4.0 + -t7229) * t12 + t7241) *
    tmpreturn_tmp_16) * t241 + 4.0 * t6895 * param->m__l7 * t7196 * t288) +
    t7288) - ((-2.0 * t6989 + t949) * param->s__l7y * q__p[1] + t732 * t7083) *
    2.0 * param->m__l7 * t940) + (2.0 * t5869 - ((t336 * t290 / 2.0 + t7192) *
    t20_tmp + tmpreturn_tmp_f / 2.0) * 4.0 * param->m__l7) * t12) - t7311) *
    t346) + tmpreturn_tmp_i * t7203 * t288) + ((((-t7252 + t7255) - (((t1038 *
    t113 - t697) - t50) * t20_tmp + t81 * t114) * 2.0 * param->m__l7) * t940 +
    -t7248) - 2.0 * t6949 * t7268) * t241) + t7314) - (q__p[0] * t791 * t7316 +
    2.0 * t6992) * tmpreturn_tmp_7 * t110) + ((-t114 * t7334 + t7337) * t16 +
    2.0 * t7539 * t4) * t12) - t7352) * t38 + ((((((((((((((((8.0 * t6852 *
    param->m__l7 * t1586 * t288 + ((-t12 * t6837 + t6828) - t6841) * t241) -
    tmpreturn_tmp_17) - t6861) * t346 + -4.0 * t6822 * t241 * t267) - 4.0 * t375
    * t26 * t7207) + ((-t6844 - t6848) + t6849) * t241) - t6873) + t6877) * t105
    + -2.0 * t400 * t615 * t107) + (((-t802 + t7395) - 4.0 * t6913) - 4.0 *
    t6914) * t267) + (((((-t940 * t6889 - t6892) * t241 + -t542) + t6922) -
    tmpreturn_tmp_18) - t6933) * t346) - t544) + (-t6904 * t940 - t6908) * t241)
    - t6936) - tmpreturn_tmp_19) + t6943) * t39) + ((((((((((((-t12 * t7369 +
    t7362) - t7365) - t7372) * t241 + -t542) - 2.0 * t7392) * t346 + ((-2.0 *
    t4856 * t16 * (t940 + 1.0) * (t940 - 1.0) - 4.0 * t167 * t18 * t7355) - t802)
    * t267) - t544) + 2.0 * t7379 * t241) + t7395) - t7405) + t7414) - t6943) *
    t106) + (((((((((((((((((2.0 * t160 + param->l__4) + param->l__5) * q__p[1] /
    2.0 + t1346 * t15 * t12) * tmpreturn_tmp_2 * t7294 + t6828) + ((((t1038 *
    t7817 + t551 * t7420) - t45) - t1353) * (2.0 * t275) + 2.0 * t2400) * t12) -
    t6841) * t241 + -4.0 * t6895 * param->m__l7 * t7425 * t288) - t7500) +
    ((t7519 + t7521) * 2.0 * q__p[1] + 2.0 * t6853) * t940) + (((-2.0 * t160 *
    t295 + t805) - t33) * t12 + t6931_tmp * t7231) * (2.0 * t18)) * t346 + ((2.0
    * t696 * t732 * t100 * t7417 + t126 * t7494) - t241 * t7440) * t267) +
    tmpreturn_tmp_i * t7431 * t288) + ((((((-t545 * t8036 + t35) - t1583) +
    t7465) - t7467) * 2.0 * param->m__l7 * t940 + 2.0 * t6817) + 2.0 * t7478 *
    t12 * t16) * t241) - t7518) + ((2.0 * t7524 - 2.0 * t6868) - ((-t290 * t723
    + t832) + t7430) * (2.0 * t275)) * t940) + (-2.0 * t100 * t2149 * t7166 -
    t7537) * t12) + t7552) * t105) + ((((4.0 * t288 * t1127 * t7558 - 2.0 *
    t1110 * t7596) + 2.0 * t6913) + 2.0 * t7676) - 2.0 * t7677) * t267) +
    (((((((((-t114 * t7614 + t7617) * t16 - tmpreturn_tmp_5 * t7202) * t12 +
    (2.0 * t724 * t7607 * t940 + -t7361)) + t7634) * t241 + 4.0 * t7463 * t288)
    - t6921) + tmpreturn_tmp_1a * t7686 * t940) + (((-t290 * t7651 - t7565) -
    t7698) * t16 - 2.0 * t7194) * t12) + t6932) * t346) + 4.0 * t7586 * t288) +
    ((((t6897 - t7060) - (param->s__l7x * t114 * t51 + t545 * t7759) * 2.0 *
       param->m__l7) * t940 + t7645) - ((-t606 * t2121 + t1850) * t20_tmp * t12
    + t225 * t7129_tmp) * 2.0 * param->m__l7) * t241) - t7160) + ((((t5949 +
    t5950) * t114 - t6569) * t16 + -t7398) - 2.0 * t24 * t26) * t940) +
    (((param->s__l7y * t338 - t723 * t440) * -t20_tmp * t114 - t510 * t81) * t12
     + t7761) * tmpreturn_tmp) * t2 / 2.0 + ((((((((((((((((((((-2.0 * t241 *
    t290 * t42 * t76 + t288 * t2887) + t2887) * (-4.0 * t1127) * (t940 + 1.0) *
    t267 - ((((((t5875 + t699) + t5729) * t288 + t5874 * t241) - t5616) + t699)
    - t5729 / 2.0) * 8.0 * t12 * t346) - 4.0 * t5763 * t288) + 4.0 * t290 *
    t5899 * t940 * t241) + t5946) + ((t5948 + t7726) - t5950) * t940) - t5558) *
    t105 + -8.0 * t400 * t676 * t106) - (t241 * t400 - 2.0 * t1620 * t76) * (4.0
    * t189) * t267) + (-t241 * t5778 + 2.0 * t6664) * t346) + (t5760 + t6083) *
    t241) + t6669) + t6679) * t38 + ((((((((t101 - t1038) + t3208) * 2.0 * t12 *
    t346 + ((t615 * t106 - 2.0 * t676 * t114 * t105) + (t288 - 2.0) * q__p[0] *
    t5769)) + t595) - t3120 * t241) + t514) + t797) - q__p[0]) * t4068 * t39) +
    4.0 * t722 * t6683) + (((((2.0 * t775 * t76 + t62) * 4.0 * t12 * t10 +
    (-t241 * t6695 - 4.0 * t6717) * t346) + (t6698 + t6705) * t241) - t6722) -
    t6733) * t105) - ((tmpreturn_tmp_4 * t5 + t241 * t543 * t2168) - t76) * (4.0
    * q__p[0]) * t5769) + (((((((((-t6766 / 2.0 + t6728 / 4.0) + t269) * t114 +
    -2.0 * t6764) - t6770) * t241 + t6748 * t288) - t6744 / 2.0) - t6745 / 4.0)
    + (t6781 / 4.0 - t684) * t290) + t6747 / 2.0) * (8.0 * t12) * t346) -
    ((((t6767 + t420_tmp) * t290 - t6797 / 2.0) * t114 + ((t6755 * t288 + t6783 *
    t241) - t6752)) - t948) * (4.0 * t940)) * t3 / 2.0) - ((((((((((((((((-4.0 *
    t16 * t288 * t1586 * t6895 + t241 * t6834) + t7801) + t7802) * t346 + 2.0 *
    t7776 * t241 * t267) + 2.0 * t375 * t91 * t288) + ((t7791 + t7794) - t7774) *
    t241) + t6870) - t7812) * t105 + t722 * t106) + (((t1012 * t7139 + 2.0 *
    t7139) - 2.0 * t7837) + 2.0 * t7838) * t267) + ((((param->s__l7y * t155 *
    t791 + t241 * t7824) - t6919) + t7849) + t7851) * t346) + t940 *
    param->s__l7y * t64) + (t7832 + t6525) * t241) + t7837) + t7858) - t7139) *
    param->m__l7 * t180) + (((((((((((((((((((((((((((t2244_tmp * t1049 * t94 -
    t14) + t371) + t6587) - t6590) * t12 + ((2.0 * t12 * t7532 - 2.0 * t1619 *
    t4) * t940 + -t7950)) + t7049) * t241 + 2.0 * t7930 * t288) + t8000) - t8006)
    + ((t2244_tmp * t16 * t1022 + 2.0 * t5691) - 2.0 * t5729) * t12) - t8014) *
    t346 + ((((t2244_tmp * t1110 * t7943 + 2.0 * t733 * t288 * t1601) + 2.0 *
    t5927) - 2.0 * t6568_tmp) - 2.0 * t7994) * t267) + 2.0 * t6568 * t288) +
    ((((-2.0 * t7978 - ((t7654 + t262) - t7655) * tmpreturn_tmp * t16) - (t5691
    + t5731) * 2.0 * t290) * t940 + -t7976) - 2.0 * t189 * t1226 * t92) * t241)
    - t8023) + ((((2.0 * t295 * t1226 * t92 + t96 * t290) + t5762) - t8027) -
    t6570) * t940) + 2.0 * t7873 * t440 * t1740) + t8050) * t105 + (((((((((2.0 *
    t189 * t510 * t54 * t2149 * t288 + (((-t12 * t7874 + t7867) + t7387) - t7877)
    * t241) + 2.0 * t6585) * t346 + ((t124 * t6976 - 4.0 * t639 * t5947) + t1029)
    * t267) + 2.0 * t249 * t110 * t2149 * t64) + 2.0 * t7885 * t241) - t7900) -
    t6884) + t7616) + t7918) * t106) + ((tmpreturn_tmp_0 * param->s__l7x * t8132
    - t241 * t8077) + t1029) * t267) + ((((((((t678 * t7826 - (t27 + t255) *
    q__p[1] * t114 / 2.0) * (4.0 * t18) * t940 + -t8079) + (2.0 * t16 * t20_tmp *
    t8017 * t8064 - t108) * t12) + t7876) * t241 + -4.0 * t8060 * t20_tmp *
    t1032) + t7923) + (2.0 * t8141 - (t8182 / 2.0 + t8163) * 2.0 * q__p[1]) *
    t940) - ((((t132 * t290 / 2.0 + t8056) * 2.0 * t20_tmp + t120) * t16 - t6825)
             * t12 + t8111) * tmpreturn_tmp) * t346) + tmpreturn_tmp_z * t8066 *
    t288) + ((t8074 - (((((t1038 * t3588 - t145) + t419) * t20_tmp + t163 * t114)
                        * t16 + t8105) - t8112) * 2.0 * param->m__l7 * t940) -
             (t6092 + t424) * t12) * t241) + t7899) + (t295 * t947 - t8167) *
    t940) + (((t96 * t440 + t6671) * t114 + 2.0 * t7539 * t92) - t606 * t8361) *
    t12) - t7918) * t38 / 2.0) - (((((((((-2.0 * t241 * t7355 * t91 + t1012 *
    t8212) + t1569 * t8212) * t267 + ((t155 * t8104 + t241 * t7772) + t7792) *
    t346) + t7294 * t64) - t8209 * t241) - t8219) + t6931) + t8207) + t8212) *
    t26 * t106) + (((((((((((((((-4.0 * t1260 * t1226 * t8524 - (2.0 * t8073 +
    t8300) * q__p[1]) * t940 + t6689) - (((((t1038 * t7402 - t551 * t8234) -
    t128) + t178) * -t20_tmp * t16 / 2.0 - t2492 / 2.0) * t12 + t7775) * 4.0 *
    param->m__l7) * t241 + -4.0 * t8240 * t20_tmp * t1032) + t8317) - ((t7951 -
    t8337) * t987 + -t6883 * t7083) * tmpreturn_tmp * t940) + (t11 * (t805 - t33)
    * t54 + t411) * t12) - t8333) * t346 + ((((-2.0 * t1384 * t696 * t732 *
    t6738 + 2.0 * t1110 * t7773) - 2.0 * t8309) - 2.0 * t8311) + 2.0 * t8312) *
    t267) - tmpreturn_tmp_z * t8246 * t288) + ((((((t545 * t7170 + t63) + t7752)
    * tmpreturn_tmp * t16 + -t8287) + t6998 * t4291) * t940 + t7115) - (t606 *
    t8328 - t6700) * t12) * t241) + t8336) - ((((-t290 * t1066 - t8244) + t8245)
    * t20_tmp * t16 + t8342) + t8347) * tmpreturn_tmp * t940) + (((2.0 * t118 *
    t1226 * t665 - t453 * t440) + t638 * t8182) + t6725) * t12) - t8369) * t105 /
                        2.0) + ((tmpreturn_tmp_4 * (t940 + 1.0) * t7417 * t8391
    - 2.0 * t18 * t8373) - t241 * t8065) * t267 / 2.0) +
                      (((((((((tmpreturn_tmp_5 * t8064 * t16 + ((t8436 - t215) -
    t257) * t114) + t8439) * t12 + (t6920 - tmpreturn_tmp_1a * t8285 * t940)) -
    t8443) * t241 + -4.0 * t8388 * t288) - t7948) + 2.0 * t7263 * t12 * t49) +
                        (((t1296 * t359 + tmpreturn_tmp_j) - 2.0 * t8385) -
    t8511) * t12) + t6918) * t346 / 2.0) + t7924 * t288) +
                    ((((((((tmpreturn_tmp_1b * t51 - t545 * t2244) *
    tmpreturn_tmp * t16 + t7397) + t6778) - t6779) - t184) + t230) * t940 +
                      t8455) - ((t606 * t2205 + t552) * -t20_tmp * t12 + t225 *
    t8007) * 2.0 * param->m__l7 * t16) * t241 / 2.0) + t8523) + (((t7396 - 2.0 *
    t24 * t170) + (-t1038 * t8328 + t453 * t290) * t114) - t717) * t940 / 2.0) -
    (((param->s__l7x * t338 - t440 * t1066) * t20_tmp * t114 - t529 * t440) *
     t12 + t8561) * t54;
  t295 = param->s__l7y * t833;
  t359 = t295 * t106;
  t33 = t18 * t359;
  t543 = t267 * param->m__l7 * t999;
  t551 = t798 * t18 * t7139;
  t606 = t4054 * t12;
  t948 = ((t606 - t1199 * t440) - t724 / 2.0) + t665 / 2.0;
  t1038 = 4.0 * t5947 * t4054;
  t545 = t433 * t267;
  t698 = -t7151 * t114;
  t85 = t400 * t346;
  t595 = t400 * t833;
  t107 *= 2.0 * t595;
  t639 = t20_tmp * t346;
  t676 = t18 * t639;
  t699 = t346 * param->s__l7y;
  t722 = t49 * t949 - t3210;
  t733 = param->m__l7 * t690;
  t50 = t20_tmp * t723 * t114;
  t802 = t440 * t346;
  t118 = t67 * t16;
  t35 = t940 * q__p[0];
  t542 = t35 * t947 + q__p[2] * t4291;
  t160 = t20_tmp * t1066;
  t92 = t160 * t114;
  tmpreturn[13] = ((((((((((((((((((((((((((((((((((((2.0 * t49 * t2893 + -t715 *
    t440) * t346 + -t2586 * t267) + (-t3024 * t16 - 2.0 * t690 * t26) * t440) +
    t1484) - t4594) * t105 + (((-8.0 * t4054 * t2540 + 8.0 * t1199 * t2547) +
    t943) + t1087) * (-2.0 * t26) * t106) - 8.0 * t1990 * t2820) + (-2.0 * t3941
    - (t49 * t251 + t777) * 2.0 * t114) * t346) - ((2.0 * t2598 + t53) *
    param->s__l7y * t440 - t889) * tmpreturn_tmp) * t38 + ((((((-4.0 * t972 *
    t267 + 4.0 * t572 * t346) - t6510) + t980) + t981) * t105 + t625) + (-t787 *
    t346 * t370 + t465 * t2635) * (2.0 * t204)) * t39) + (((4.0 * t676 * t2910 +
    -t1397 * t440) - 4.0 * t2971 * t918) + t1399) * t106) + ((((((2.0 * t562 +
    t207) * (2.0 * t18) + -t1239 * t440) * t346 + -t1138 * t267) + (-2.0 * t2400
    - ((t848 * t446 - t45) - t1353) * (2.0 * t275)) * t440) + t980) - t1250) *
    t105) + 2.0 * t18 * t1142 * t267) - (-t330 * t370 + t1240) * tmpreturn_tmp *
    t346) + ((t564 - t1433) * t16 - (t446 * t204 * t67 + t49 * t2698) *
    tmpreturn_tmp) * t440) - t4855) * t241 + ((((((((((((-8.0 * t1105 * t25 *
    t76 - 8.0 * t545 * t2646) - t793) + t469) * t105 + 2.0 * t1689 * t20_tmp *
    t833 * t106) - (((-param->s__l7y * t267 * t638 - t27 * t346 * t1055) + t533)
    + t552) * (2.0 * t275)) * t38 + ((-2.0 * t16 * t595 - t456) - t107) * t39) -
    t107) + (((param->s__l7x * t1226 * t346 * t1055 + t429 * t267 * t433) + t439)
    - t1194) * (2.0 * t275) * t105) + 4.0 * t915 * t267) + 4.0 * t724 * t3623 *
    t440 * t346) - t893) - t938) * t288) + (((((((t25 * t346 * t2635 + t146 *
    t370) * (2.0 * t204) * t105 + -2.0 * t85 * t1230 * t106) + (4.0 * t463 - 4.0
    * t1395) * t267) + ((-t1398 * t440 - t1429) - t1431) * t346) + t1452) - t466)
    + t1456) * t39) + ((((((((2.0 * t1460 * t2820 - (param->s__l7y * t858 * t114
    + t1718) * 2.0 * param->m__l7 * t346) + (2.0 * t777 + 2.0 * t303) * t440) +
    t1780) * t105 + (((-t638 * t639 / 4.0 - t1520) + t1177) + t2645) * (-8.0 *
    t699 * param->m__l7) * t106) + (-t1492 - t1519) * t267) + (((t698 + t976) *
    t16 + -t1761 * t440) - 2.0 * t722 * param->s__l7y * param->m__l7) * t346) +
    ((tmpreturn_tmp_f + t336 * t3230) * tmpreturn_tmp + -2.0 * t5869) * t440) +
                       t1788) * t38) - (((t16 * t346 * t2115 - t313) + t1845) -
    t5779) * (2.0 * t346) * t106) + ((((t126 * t733 - t1876) + t1877) * t346 +
    2.0 * t1791 * t2820) - (((t49 * t370 - t111) - t6821) * t440 + 2.0 * t2554 *
    t1447) * 2.0 * param->m__l7) * t105) + (-2.0 * t463 + 2.0 * t1839) * t267) +
    (-t1185 * t440 - (t81 * t42 - t50) * 2.0 * param->m__l7) * t346) + (-t1369 *
    t16 - (t644 * t7371 - t68 * t196) * tmpreturn_tmp) * t440) + t466) + t1382) *
    t2 / 2.0 + (((((((((((((((((((((((8.0 * t290 * t10 * t1263 + 8.0 * t1105 *
    t2123) - t188) - t517) * t105 + 8.0 * t400 * t948 * t106) - t1038) + (4.0 *
    t2973 + 4.0 * t417) * t346) + t464) * t38 + ((tmpreturn_tmp_1c * t948 +
    t3575) + t3576) * -4.0 * param->s__l7y * t2643) - t324) + ((-4.0 * t704 * t5
    * t787 - t526 * t346) + 8.0 * t606 * t3356) * t105) - 4.0 * t62 * t545) -
    4.0 * t5947 * t225 * t197 * t151) + (t698 + t366) * t440) + t380) * t241 +
                        ((((((t974 - t1510) + 4.0 * t33) - 8.0 * t543) - 8.0 *
    t551) - t1179) + t3910) * t288) - (((((-t346 * t750 * t106 + t1446 * t523 *
    t105) + 2.0 * t10) + (t541 - q__p[3]) * t346) + t607) - q__p[1]) * 4.0 *
                       param->s__l7y * t2643) + ((((((-4.0 * t151 * t116 * t400
    - 4.0 * t389) - 4.0 * t614) * t105 + -4.0 * t85 * t575) + 8.0 * t724 * t1040
    * t1226 * t76) + ((-t549 + t1401) + t310) * t346) - 4.0 * t1620 * t18 * t361)
                      * t38) + 4.0 * t346 * param->m__l7 * param->s__l7x * t438 *
                     t106) + ((-2.0 * t704 * t290 * t2168 + 4.0 * t1503 * t8) -
    t426 * t346) * t105) + 4.0 * t543) + 4.0 * t551) - t4072) - t761) * t3 / 2.0)
    + ((((((((((((2.0 * t389 + 2.0 * t1023) - 2.0 * t1393) - 2.0 * t6819) * t105
               + 2.0 * t1384 * t2149 * t833 * t106) + (((t429 * t346 * t1055 +
    t638 * t2820) + t1394) - t1850) * (2.0 * t275 * t16)) * t38 + ((t359 / 2.0 +
    t4365) + t295 / 2.0) * -4.0 * param->m__l7 * t180) - 2.0 * t33) + (((-t27 *
    t267 * t433 - t699 * t1226 * t1055) + t3197) + t6727) * (2.0 * t20_tmp) *
           t54 * t105) + t3303 * t267) + 2.0 * t724 * t1130 * t18 * t802) +
        t4641) - t3303) * t288 / 2.0) + (((((((((((((((((((-2.0 * t733 * t94 -
    t1853) + t14) - t371) * t440 + (4.0 * t18 * t6615 * t267 - (t5842 * t49 +
    t7344) * tmpreturn_tmp * t346)) - t2250) * t105 + (((4.0 * t802 * t2115 +
    -t7922 * t440) + t7298) - t1038) * t106) + (2.0 * t6912 + 2.0 * t1503) *
    t267) + (-t6906 * t440 - (t49 * t255 + t7862) * 2.0 * param->m__l7 * t2205) *
    t346) + (-2.0 * t8259 + t108) * t440) - t7443) - t2235) * t38 + ((((((2.0 *
    t7340 * t267 + 2.0 * t4073 * t346) - t3887) + t7784) - t7105) * t105 +
    -t7265) + (-param->s__l7y * t197 + t639 * t25) * t204) * t2244_tmp * t180) +
    (((-2.0 * t346 * t2910 * t91 + 2.0 * t3169 * t918) + t8081) - t2947) * (2.0 *
    t26) * t106) + (((((t579 * t446 + t128) - t178) * t20_tmp * t16 - t2492) *
                     t440 + t8198) * tmpreturn_tmp + (((t8080 - 2.0 * t49 *
    param->m__l7 * t118) - (t35 * t4291 + q__p[2] * t947) * t42) * t346 +
    tmpreturn_tmp_0 * t2284 * t2820)) * t105) + (-2.0 * t2145 + 2.0 * t377) *
    t267) + (2.0 * t2389 * t2893 + -t7376 * t440) * t346) + (((-t446 * t204 *
    t7201 + t49 * t5908) * tmpreturn_tmp * t16 + t453 * t114) - t976) * t440) -
    t8486) - t5805) * t241 / 2.0) + (((((((t4449 * t16 + t1446 * t2121) * t204 *
    t105 + -t699 * t34) + (-2.0 * t5809 + 2.0 * t987) * t267) + ((t7833 - t7367)
    - t57) * t346) - t7829) + t5809) - t987) * t18 * t39) + (((((((-2.0 * t114 *
    t7407 - t3328) * t346 + -t7222 * t267) + ((t16 * t1022 + t429 * t942) * t440
    + t338 * t6113) * tmpreturn_tmp) * t105 + (((t676 * t912 + t467) + t8284) -
    t2399) * (2.0 * t346) * t106) - 2.0 * t815 * param->m__l7 * t2820) +
    (((t2244_tmp * t722 * t94 + t114 * t96) - t542 * t290) - t5928) * t346) +
    (((t132 * t3230 + t120) * t16 - t6825) * t440 + t7805) * 2.0 * param->m__l7)
                        * t38 / 2.0) - (((param->s__l7x * t1199 + t8137) + t6961)
    - t31) * (t699 * param->m__l7) * t106) + (((((((-2.0 * t16 * t690 * t26 -
    t4537) + t4496) - t215) - t257) * t346 + -t7064 * t267) + ((t49 * t2149 + t7)
    * -2.0 * param->m__l7 * t16 - t411) * t440) + t4503) * t105 / 2.0) + t7684 *
                     param->m__l7 * t2820) - (t5299 - (t92 + t529) * t16) *
                    param->m__l7 * t346) + (((t763 * t68 + t644 * t6754) *
    t2244_tmp * t16 - t542 * t42 * t114) - tmpreturn_tmp_j) * t440 / 2.0) -
    t4505;
  t91 = t876_tmp * t39;
  t128 = t750 * t38;
  t251 = t203 * t128;
  t18 = t370 * t38;
  t301 += t18 * t100 + t301 * t39;
  t255 = t117 * t39;
  t330 = t1387 * t39;
  t267 = q__p[3] * param->m__l7;
  t440 = (-t20_tmp * t249 * t38 + param->s__l7y * t39) + param->s__l7y;
  t338 = 2.0 * t91;
  t638 = t20_tmp * t878_tmp * t16;
  t249 = q__p[4] * -t947;
  tmpreturn[20] = (((((((((((((((((((((((((((4.0 * t277 - 8.0 * t276) * t16 -
    2.0 * t282) * t290 - 2.0 * t267 * t2149) * t38 + -4.0 * t233 * t77 * t39) -
    ((-2.0 * t1230 * t27 + t376) * param->s__l7x + -t354) * tmpreturn_tmp) *
    t105 + 2.0 * t290 * t301 * t274) + ((2.0 * t235 + 2.0 * t58) - 2.0 * t270) *
    t39) + (((t15 * t45 + t57 * t68) + t432) * 2.0 * param->m__l7 + (2.0 * t157 *
    t497 * t16 + -2.0 * t283)) * t38) + (-t356 * t16 - t373) * t290) + -t218 *
    t16) + 2.0 * t787 * t370 * t878_tmp) * t241 + ((((((((-t877 * t16 + t448) *
    t38 + 4.0 * t26 * t255) + tmpreturn_tmp_3) * t105 + 2.0 * t301 * t204 * t106)
    + 2.0 * t330) + tmpreturn_tmp_c * t38) - tmpreturn_tmp_p) + t232) * t288) +
    (((-2.0 * t395 * t26 * t38 + 2.0 * t473) - 2.0 * t330) - 2.0 * t1387) * t106)
    + ((((((-2.0 * t941 * t243 - tmpreturn_tmp_q) * t290 - tmpreturn_tmp_s) -
          t448) * t38 + (-2.0 * t347 * t290 - 2.0 * t381) * t39) + (2.0 * t275 *
    t723 - 2.0 * t344) * t290) - t475) * t105) - (-2.0 * t392 * t169_tmp + t442)
    * tmpreturn_tmp * t192) + (-2.0 * t878_tmp * t100 * t2149 - t185) * t290) -
    tmpreturn_tmp_t) - t232) * t2 / 2.0 + (((((((((((((4.0 * t1054 *
    param->s__l7y * (t39 + 1.0) * t274 + (-2.0 * t750 * t157 + 8.0 * t823 * t38)
    * t105) + 4.0 * t26 * (t327 + q__p[4]) * param->s__l7x * t39) + 4.0 * t941 *
    t5 * t128) - tmpreturn_tmp_n) - t156) - t47) * t241 + ((((4.0 * t106 * (t39
    + 1.0) * t204 * t76 + t72) - t434) - t325) + 4.0 * t91) * t288) + ((-4.0 *
    t91 + 4.0 * t251) - 4.0 * t876_tmp) * t106) + ((-4.0 * t1151 * t5 * t750 *
    t39 + ((t158 * t290 - t653) + t657) * t38) - 4.0 * t1151 * t868) * t105) -
    2.0 * t251) + t418) + t499) + t487) * t3 / 2.0) + ((((((((-t414 * t38 - 2.0 *
    t814 * t54) + 4.0 * t255 * t170) * t105 + -2.0 * t440 * param->m__l7 * t867 *
    t106) - t338) + 2.0 * t20_tmp * t706 * t54 * t38) + t1182) + t499) + t487) *
    t288 / 2.0) + ((((((((((((((-2.0 * t1290 - 4.0 * t670) - 2.0 * t353) * t290
    + 2.0 * t142 * t4) * t38 + -4.0 * t2849 * param->m__l7 * t2149 * t199) +
    t1319) + 2.0 * t267 * t118) + ((t12 * -t947 * t991 + -t947 * t346 * q__p[1])
    + t680) * t42) * t105 + -2.0 * t290 * t440 * param->m__l7 * t627 * t106) -
                        ((t1544 + t1274) + t45) * tmpreturn_tmp * t180) +
                       ((((t31 * t68 - t20_tmp * t419) + t130) * t16 + t1297) -
                        t1226 * t868) * tmpreturn_tmp * t38) - tmpreturn_tmp_r)
                     + 2.0 * t946 * t638) - t184) + t230) * t241 / 2.0) + ((2.0 *
    t933 * t26 + -t920 * t38) + t338) * t106 / 2.0) + (((((((-2.0 * t941 * t1230
    * t2149 + t14) - t371) * t290 - t136) - t187) + t308) * t38 + (-t1304 * t290
    + t913) * -2.0 * param->m__l7 * t180) + ((t438 * t2205 + t16 * t160) * t290
    + t1006) * 2.0 * param->m__l7) * t105 / 2.0) + (((-t12 * t991 * t4291 -
    q__p[3] * -t947) - t424 * t346) * t290 + t927) * t38 / 2.0) + (2.0 * t1689 *
    t638 - (t249 * t42 - t257) * t114) * t290 / 2.0) - t969) + t1035) - t876_tmp;
  t5 = t168_tmp * t102;
  t45 = t114 * t5 + t46;
  t5 += t1305;
  tmpreturn[27] = ((((((((((((-t119 - ((param->s__l7x * t102 - t79 * t27) *
    t20_tmp + -t216) * 2.0 * param->m__l7 * t2) + (t219 * t2205 + t122) * (2.0 *
    t20_tmp) * t54) + t266) * t105 + -t302 * t106) + (-t114 * t479 + t299) * t3)
    + ((-t114 * t1284 - t1314) * t16 + 2.0 * t45 * param->s__l7y * param->m__l7)
    * t2) + 2.0 * t45 * param->m__l7 * t94) + (t1331 - t14) * t114) - t93) * t38
                     / 2.0 + ((((4.0 * t105 * t183 * t79 - 4.0 * t106 * t234) -
    tmpreturn_tmp_6) + t256) + t1278) * t39 / 2.0) + ((-t258 * t2 - t256) + t260)
                    * t106 / 2.0) + ((((((t449 * t5 - tmpreturn_tmp_e) * t2 +
    -t172 * t3) + 2.0 * t26 * t5 * t16) - t428) + ((t17 * t290 * t4291 + t241 *
    t204 * t4291) - t249) * t42) + t257) * t105 / 2.0) + ((t254 * t27 - t50) *
    t2 + (t254 * t429 - t92) * t16) * param->m__l7;
  tmpreturn[34] = (((((((-t300 * t38 - 4.0 * t52 * t2173) * t42 - 2.0 * t23 *
                        t39) + tmpreturn_tmp * q__p[5] * t2149 * t38) - 2.0 * t9)
                     + 2.0 * t22) * t2 / 2.0 + (-t95 * t42 + t133) * t3 / 2.0) +
                   ((((2.0 * t105 * t750 * t29 + 2.0 * t854 * t29 * t241) - 2.0 *
                      t29 * t290 * t523) - 2.0 * q__p[5] * t86) + 2.0 * t28) *
                   t42 / 2.0) - ((t16 * t18 * q__p[5] + t32 * t39) - t32) *
    param->m__l7;
  tmpreturn[41] = (((((-2.0 * t21 * t16 + 2.0 * t123) + 2.0 * t226) * t2 / 2.0 +
                     -t127 * t3 / 2.0) - tmpreturn_tmp_1) - tmpreturn_tmp_h) +
    t80;
  tmpreturn[48] = 0.0;
}

// Function for MATLAB Function: '<S4>/Friction Observer discrete'
void controller_ballcatcherModelClass::mldivide(const real_T A[49], real_T B_0[7])
{
  real_T b_A[49];
  int8_T ipiv[7];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T kAcol;
  memcpy(&b_A[0], &A[0], 49U * sizeof(real_T));
  for (kAcol = 0; kAcol < 7; kAcol++) {
    ipiv[kAcol] = (int8_T)(1 + kAcol);
  }

  for (j = 0; j < 6; j++) {
    kAcol = j << 3;
    iy = 0;
    ix = kAcol;
    smax = std::abs(b_A[kAcol]);
    for (k = 2; k <= 7 - j; k++) {
      ix++;
      s = std::abs(b_A[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_A[kAcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 7; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 7;
          iy += 7;
        }
      }

      iy = (kAcol - j) + 7;
      for (ix = kAcol + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[kAcol];
      }
    }

    iy = kAcol + 8;
    ix = kAcol + 7;
    for (k = 0; k <= 5 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = kAcol + 1;
        d = (iy - j) + 6;
        for (ijA = iy; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 7;
      iy += 7;
    }
  }

  for (j = 0; j < 6; j++) {
    if (j + 1 != ipiv[j]) {
      smax = B_0[j];
      kAcol = ipiv[j] - 1;
      B_0[j] = B_0[kAcol];
      B_0[kAcol] = smax;
    }
  }

  for (j = 0; j < 7; j++) {
    kAcol = 7 * j;
    if (B_0[j] != 0.0) {
      for (iy = j + 1; iy + 1 < 8; iy++) {
        B_0[iy] -= b_A[iy + kAcol] * B_0[j];
      }
    }
  }

  for (j = 6; j >= 0; j--) {
    kAcol = 7 * j;
    if (B_0[j] != 0.0) {
      B_0[j] /= b_A[j + kAcol];
      for (iy = 0; iy < j; iy++) {
        B_0[iy] -= b_A[iy + kAcol] * B_0[j];
      }
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
void controller_ballcatcherModelClass::mldivide_ln(const real_T A[36], real_T
  B_2[6])
{
  real_T b_A[36];
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T k;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T kAcol;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  for (kAcol = 0; kAcol < 6; kAcol++) {
    ipiv[kAcol] = (int8_T)(1 + kAcol);
  }

  for (j = 0; j < 5; j++) {
    kAcol = j * 7;
    iy = 0;
    ix = kAcol;
    smax = std::abs(b_A[kAcol]);
    for (k = 2; k <= 6 - j; k++) {
      ix++;
      s = std::abs(b_A[ix]);
      if (s > smax) {
        iy = k - 1;
        smax = s;
      }
    }

    if (b_A[kAcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 6; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (kAcol - j) + 6;
      for (ix = kAcol + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[kAcol];
      }
    }

    iy = kAcol + 7;
    ix = kAcol + 6;
    for (k = 0; k <= 4 - j; k++) {
      smax = b_A[ix];
      if (b_A[ix] != 0.0) {
        c_ix = kAcol + 1;
        d = (iy - j) + 5;
        for (ijA = iy; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * -smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 5; j++) {
    if (j + 1 != ipiv[j]) {
      smax = B_2[j];
      kAcol = ipiv[j] - 1;
      B_2[j] = B_2[kAcol];
      B_2[kAcol] = smax;
    }
  }

  for (j = 0; j < 6; j++) {
    kAcol = 6 * j;
    if (B_2[j] != 0.0) {
      for (iy = j + 1; iy + 1 < 7; iy++) {
        B_2[iy] -= b_A[iy + kAcol] * B_2[j];
      }
    }
  }

  for (j = 5; j >= 0; j--) {
    kAcol = 6 * j;
    if (B_2[j] != 0.0) {
      B_2[j] /= b_A[j + kAcol];
      for (iy = 0; iy < j; iy++) {
        B_2[iy] -= b_A[iy + kAcol] * B_2[j];
      }
    }
  }
}

// Function for MATLAB Function: '<Root>/MATLAB Function'
real_T controller_ballcatcherModelClass::polyval(const real_T p_data[], const
  int32_T p_size[2], real_T x)
{
  real_T y;
  int32_T k;
  if (p_size[1] != 0) {
    y = p_data[0];
    for (k = 0; k <= p_size[1] - 2; k++) {
      y = x * y + p_data[k + 1];
    }
  }

  return y;
}

// Model step function for TID0
void controller_ballcatcherModelClass::step0() // Sample time: [0.000125s, 0.0s] 
{
  real_T alpha[7];
  real_T V[7];
  real_T m[12];
  real_T t5;
  real_T t7;
  real_T t9;
  real_T t11;
  real_T t12;
  real_T t14;
  real_T t17;
  real_T t19;
  real_T t20;
  real_T t27;
  real_T t28;
  real_T t29;
  real_T t33;
  real_T t36;
  real_T t37;
  real_T t41;
  real_T t45;
  real_T t50;
  real_T t55;
  real_T t58;
  real_T t76;
  real_T t78;
  real_T t87;
  real_T t91;
  real_T t94;
  real_T t108;
  real_T d[49];
  real_T b_m[7];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const real_T v[7] = { 2.1666148000000005, 2.1666148000000005,
    0.9781167999999999, 0.81509733333333323, 0.36774199999999996,
    0.13539657142857142, 0.13539657142857142 };

  static const uint16_T x[7] = { 60000U, 60000U, 40000U, 40000U, 40000U, 20000U,
    20000U };

  static const int8_T c[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const uint8_T e[49] = { 160U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 160U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 160U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 160U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 100U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 160U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 160U };

  static const real_T f[49] = { 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.4709679999999998, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.473888, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.473888 };

  static const uint16_T g[49] = { 60000U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 60000U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 40000U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 40000U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 40000U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 20000U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 20000U };

  static const int16_T h[49] = { 320, 0, 0, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0, 0,
    0, 176, 0, 0, 0, 0, 0, 0, 0, 176, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 0, 0,
    0, 40, 0, 0, 0, 0, 0, 0, 0, 40 };

  static const real_T i[7] = { 2.9670597283903604, 2.0943951023931953,
    2.9670597283903604, 2.0943951023931953, 2.9670597283903604,
    2.0943951023931953, 3.0543261909900763 };

  static const real_T k[7] = { -2.9670597283903604, -2.0943951023931953,
    -2.9670597283903604, -2.0943951023931953, -2.9670597283903604,
    -2.0943951023931953, -3.0543261909900763 };

  real_T qf[7];
  real_T coeffs[6];
  real_T pd_data[5];
  real_T pdd_data[4];
  int32_T l_data[21];
  boolean_T p;
  boolean_T b_p;
  int32_T n;
  int32_T nlead0;
  int32_T ny;
  static const int8_T m_0[6] = { 1, 0, 0, 0, 0, 0 };

  static const int8_T o[6] = { 0, 1, 0, 0, 0, 0 };

  static const int8_T q[6] = { 0, 0, 1, 0, 0, 0 };

  static const real_T b_0[7] = { -4.0, -4.0, -4.0, -5.0, -3.0, -2.5, -2.5 };

  static const real_T c_0[7] = { -0.015, -0.015, -0.015, -0.02, -0.01, -0.01,
    -0.01 };

  real_T b_data[7];
  real_T r_data[7];
  real_T c_data[7];
  int8_T e_data[7];
  static const real_T v_0[49] = { 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 10.833074000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.890584, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.4709679999999998, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.473888, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.473888 };

  real_T rtb_TmpSignalConversionAtSFunctionInport4_h[3];
  real_T rtb_tau_slow[7];
  real_T rtb_Subtract[7];
  real_T rtb_tau_p_slow[7];
  real_T rtb_theta_slow[7];
  real_T rtb_q[7];
  real_T rtb_q_d[21];
  real_T rtb_TmpSignalConversionAtSFunctionInport7[31];
  real_T rtb_robot_model_H[16];
  real_T rtb_T0[16];
  real_T rtb_Tf[16];
  sYAUkIU1G7S9rEYvehBuTuE expl_temp;
  sYAUkIU1G7S9rEYvehBuTuE expl_temp_0;
  int16_T expl_temp_tmp[49];
  uint16_T expl_temp_tmp_0[49];
  uint8_T expl_temp_tmp_1[49];
  int8_T expl_temp_tmp_2[9];
  int32_T k_0;
  real_T tmp[49];
  real_T tmp_0[49];
  real_T m_1[36];
  real_T tmp_1[49];
  int32_T pd_size[2];
  int32_T pdd_size[2];
  real_T pd_p[3];
  real_T t33_tmp;
  real_T t18_tmp;
  real_T t7_tmp;
  real_T t9_tmp;
  real_T t14_tmp;
  real_T t16_tmp;
  real_T t22_tmp;
  real_T t24_tmp;
  boolean_T exitg1;

  // Update the flag to indicate when data transfers from
  //   Sample time: [0.000125s, 0.0s] to Sample time: [0.008s, 0.0s]
  ((&rtM)->Timing.RateInteraction.TID0_1)++;
  if (((&rtM)->Timing.RateInteraction.TID0_1) > 63) {
    (&rtM)->Timing.RateInteraction.TID0_1 = 0;
  }

  for (k_0 = 0; k_0 < 7; k_0++) {
    // Sum: '<S11>/Subtract' incorporates:
    //   Constant: '<S11>/Constant'
    //   Inport: '<Root>/fast_sensor_torque'

    rtb_Subtract[k_0] = rtU.fast_sensor_torque[k_0] -
      rtConstP.Constant_Value[k_0];

    // MATLAB Function: '<S11>/f_tau_slow'
    alpha[k_0] = 0.85463599915323341;
  }

  // MATLAB Function: '<S11>/f_tau_slow'
  if (!rtDW.x_not_empty_j) {
    rtDW.x_not_empty_j = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_l[k_0] = 6.87928231319208 * rtb_Subtract[k_0];
      rtb_tau_slow[k_0] = rtb_Subtract[k_0];
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtb_tau_slow[k_0] = 0.14536400084676659 * rtDW.x_l[k_0];
      rtDW.x_l[k_0] = 0.85463599915323341 * rtDW.x_l[k_0] + rtb_Subtract[k_0];
    }
  }

  // MATLAB Function: '<S11>/f_tau_p_slow'
  if (!rtDW.x_not_empty_k) {
    rtDW.x_not_empty_k = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_k[k_0] = -1162.9120067741328 * rtb_Subtract[k_0];
      rtb_tau_p_slow[k_0] = 0.0;
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtb_tau_p_slow[k_0] = 1162.9120067741328 * rtb_Subtract[k_0] +
        rtDW.x_k[k_0];
      rtDW.x_k[k_0] = 0.85463599915323341 * rtDW.x_k[k_0] + -169.04554193743007 *
        rtb_Subtract[k_0];
    }
  }

  // End of MATLAB Function: '<S11>/f_tau_p_slow'

  // MATLAB Function: '<S11>/f_theta_slow' incorporates:
  //   Inport: '<Root>/fast_sensor_position'

  for (k_0 = 0; k_0 < 7; k_0++) {
    alpha[k_0] = 0.85463599915323341;
  }

  if (!rtDW.x_not_empty) {
    rtDW.x_not_empty = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x[k_0] = 6.87928231319208 * rtU.fast_sensor_position[k_0];
      rtb_theta_slow[k_0] = rtU.fast_sensor_position[k_0];
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtb_theta_slow[k_0] = 0.14536400084676659 * rtDW.x[k_0];
      rtDW.x[k_0] = 0.85463599915323341 * rtDW.x[k_0] +
        rtU.fast_sensor_position[k_0];
    }
  }

  // End of MATLAB Function: '<S11>/f_theta_slow'

  // MATLAB Function: '<S11>/f_theta_p_slow' incorporates:
  //   Inport: '<Root>/fast_sensor_position'

  if (!rtDW.x_not_empty_l) {
    rtDW.x_not_empty_l = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_n[k_0] = -1162.9120067741328 * rtU.fast_sensor_position[k_0];
      alpha[k_0] = 0.0;
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      alpha[k_0] = 1162.9120067741328 * rtU.fast_sensor_position[k_0] +
        rtDW.x_n[k_0];
      rtDW.x_n[k_0] = 0.85463599915323341 * rtDW.x_n[k_0] + -169.04554193743007 *
        rtU.fast_sensor_position[k_0];
    }
  }

  // End of MATLAB Function: '<S11>/f_theta_p_slow'

  // MATLAB Function: '<Root>/Robot Model'
  for (k_0 = 0; k_0 < 7; k_0++) {
    rtb_theta_slow[k_0] -= rtb_tau_slow[k_0] / (real_T)x[k_0];
    alpha[k_0] -= rtb_tau_p_slow[k_0] / (real_T)x[k_0];
  }

  t7 = std::cos(rtb_theta_slow[4]);
  t9 = std::cos(rtb_theta_slow[5]);
  t5 = t7 * t9;
  t7_tmp = std::cos(rtb_theta_slow[3]);
  t9_tmp = std::sin(rtb_theta_slow[3]);
  t14 = std::sin(rtb_theta_slow[5]);
  t11 = t9_tmp * t14;
  t12 = t5 * t7_tmp + t11;
  t14_tmp = std::cos(rtb_theta_slow[2]);
  t16_tmp = std::sin(rtb_theta_slow[2]);
  t17 = t9 * t16_tmp;
  t18_tmp = std::sin(rtb_theta_slow[4]);
  t19 = t17 * t18_tmp;
  t20 = t12 * t14_tmp - t19;
  t22_tmp = std::cos(rtb_theta_slow[1]);
  t24_tmp = std::sin(rtb_theta_slow[1]);
  t27 = t14 * t7_tmp - t5 * t9_tmp;
  t28 = t24_tmp * t27;
  t29 = t20 * t22_tmp - t28;
  t33 = std::cos(rtb_theta_slow[6]);
  t33_tmp = std::sin(rtb_theta_slow[6]);
  t36 = t7 * t16_tmp;
  t91 = t14_tmp * t18_tmp;
  t37 = t91 * t7_tmp + t36;
  t41 = t18_tmp * t24_tmp * t9_tmp + t22_tmp * t37;
  t45 = std::cos(rtb_theta_slow[0]);
  t50 = t91 * t9 + t12 * t16_tmp;
  t5 = t16_tmp * t18_tmp;
  t76 = t14_tmp * t7;
  t55 = t76 - t5 * t7_tmp;
  t58 = std::sin(rtb_theta_slow[0]);
  m[0] = (t29 * t33 - t33_tmp * t41) * t45 - (t33 * t50 + t33_tmp * t55) * t58;
  t12 = -t12 * t14_tmp + t19;
  t19 = (t22_tmp * t12 + t28) * t33_tmp - t33 * t41;
  t28 = t33 * t55 - t33_tmp * t50;
  m[3] = t45 * t19 - t58 * t28;
  t76 = t76 * t7_tmp - t5;
  t78 = t7 * t24_tmp;
  t87 = (-t14_tmp * t22_tmp * t9_tmp + t24_tmp * t7_tmp) * t9 + (t22_tmp * t76 +
    t78 * t9_tmp) * t14;
  t91 += t36 * t7_tmp;
  t94 = t14 * t91 - t17 * t9_tmp;
  m[6] = t45 * t87 - t58 * t94;
  t17 = 0.15200000000000002 * t14;
  t36 = (t9 * 0.15200000000000002 + 0.2125) + 0.1875;
  t108 = t36 * t7_tmp;
  t78 = ((-t36 * t14_tmp * t22_tmp + t78 * t17) * t9_tmp + t22_tmp *
         0.15200000000000002 * t76 * t14) + ((t108 + 0.2325) + 0.1875) * t24_tmp;
  t91 = -t36 * t16_tmp * t9_tmp + t91 * t17;
  m[9] = t78 * t45 - t91 * t58;
  m[1] = (t29 * t58 + t45 * t50) * t33 - (t41 * t58 - t45 * t55) * t33_tmp;
  m[4] = t45 * t28 + t58 * t19;
  m[7] = t45 * t94 + t58 * t87;
  m[10] = t78 * t58 + t91 * t45;
  m[2] = (-t18_tmp * t22_tmp * t9_tmp + t24_tmp * t37) * t33_tmp + (-t27 *
    t22_tmp + t24_tmp * t12) * t33;
  m[5] = (t20 * t33_tmp + t33 * t37) * t24_tmp - (t18_tmp * t33 * t9_tmp + -t27 *
    t33_tmp) * t22_tmp;
  m[8] = (t14_tmp * t9 * t9_tmp - t14 * t76) * t24_tmp + (t11 * t7 + t9 * t7_tmp)
    * t22_tmp;
  t12 = t7 * t14;
  m[11] = (((((t12 * t9_tmp * 0.15200000000000002 + 0.2325) + 0.1875) + t108) *
            t22_tmp + ((-t12 * t7_tmp * 0.15200000000000002 + t36 * t9_tmp) *
                       t14_tmp + t5 * t17) * t24_tmp) + 0.1525) + 0.2075;
  for (nlead0 = 0; nlead0 < 4; nlead0++) {
    k_0 = nlead0 << 2;
    rtb_robot_model_H[k_0] = m[3 * nlead0];
    rtb_robot_model_H[1 + k_0] = m[3 * nlead0 + 1];
    rtb_robot_model_H[2 + k_0] = m[3 * nlead0 + 2];
    rtb_robot_model_H[3 + k_0] = b[nlead0];
  }

  for (k_0 = 0; k_0 < 7; k_0++) {
    expl_temp.q_limit_lower[k_0] = k[k_0];
    expl_temp.q_limit_upper[k_0] = i[k_0];
  }

  expl_temp.K__7 = 20000.0;
  expl_temp.K__6 = 20000.0;
  expl_temp.K__5 = 40000.0;
  expl_temp.K__4 = 40000.0;
  expl_temp.K__3 = 40000.0;
  expl_temp.K__2 = 60000.0;
  expl_temp.K__1 = 60000.0;
  expl_temp.I__r7zz = 1.851125E-5;
  expl_temp.I__r7yy = 1.5E-5;
  expl_temp.I__r7xx = 1.5E-5;
  expl_temp.I__r6zz = 1.851125E-5;
  expl_temp.I__r6yy = 1.5E-5;
  expl_temp.I__r6xx = 1.5E-5;
  expl_temp.I__r5zz = 0.0001470968;
  expl_temp.I__r5yy = 7.5E-5;
  expl_temp.I__r5xx = 7.5E-5;
  expl_temp.I__r4zz = 0.0001910384375;
  expl_temp.I__r4yy = 0.000129;
  expl_temp.I__r4xx = 0.000129;
  expl_temp.I__r3zz = 0.0001910384375;
  expl_temp.I__r3yy = 0.000129;
  expl_temp.I__r3xx = 0.000129;
  expl_temp.I__r2zz = 0.00042316695312500003;
  expl_temp.I__r2yy = 0.000185;
  expl_temp.I__r2xx = 0.000185;
  expl_temp.I__r1zz = 0.00042316695312500003;
  expl_temp.I__r1yy = 0.000185;
  expl_temp.I__r1xx = 0.000185;
  for (nlead0 = 0; nlead0 < 49; nlead0++) {
    expl_temp.tau_max[nlead0] = h[nlead0];
    expl_temp.K[nlead0] = g[nlead0];
    expl_temp.B[nlead0] = f[nlead0];
    expl_temp.N[nlead0] = e[nlead0];
    expl_temp_tmp[nlead0] = h[nlead0];
    expl_temp_tmp_0[nlead0] = g[nlead0];
    expl_temp_tmp_1[nlead0] = e[nlead0];
  }

  expl_temp.n__7 = 160.0;
  expl_temp.n__6 = 160.0;
  expl_temp.n__5 = 100.0;
  expl_temp.n__4 = 160.0;
  expl_temp.n__3 = 160.0;
  expl_temp.n__2 = 160.0;
  expl_temp.n__1 = 160.0;
  expl_temp.I__l7zz = 0.001105;
  expl_temp.I__l7yy = 0.000888;
  expl_temp.I__l7xx = 0.000884;
  expl_temp.I__l6zz = 0.00606797638550296;
  expl_temp.I__l6yy = 0.00477633755783711;
  expl_temp.I__l6xx = 0.00732758787216765;
  expl_temp.I__l5zz = 0.00571863785412578;
  expl_temp.I__l5yy = 0.0116859337751969;
  expl_temp.I__l5xx = 0.0138359953358589;
  expl_temp.I__l4zz = 0.0466529007761679;
  expl_temp.I__l4yy = 0.00964726804146909;
  expl_temp.I__l4xx = 0.0472789668341968;
  expl_temp.I__l3zz = 0.0554482283748983;
  expl_temp.I__l3yy = 0.0228661554143474;
  expl_temp.I__l3xx = 0.0230152941318817;
  expl_temp.I__l2zz = 0.0873510892661361;
  expl_temp.I__l2yy = 0.0164110968055191;
  expl_temp.I__l2xx = 0.0824701683534692;
  expl_temp.I__l1zz = 0.0200625854402119;
  expl_temp.I__l1yy = 0.0711085586914514;
  expl_temp.I__l1xx = 0.0690761441316632;
  expl_temp.s__l7z = 0.018862000000000004;
  expl_temp.s__l7y = -9.3E-5;
  expl_temp.s__l7x = 0.0019040000000000003;
  expl_temp.s__l6z = 0.042269;
  expl_temp.s__l6y = -0.016982;
  expl_temp.s__l6x = -0.000363;
  expl_temp.s__l5z = 0.062938;
  expl_temp.s__l5y = -0.014468;
  expl_temp.s__l5x = -5.7E-5;
  expl_temp.s__l4z = 0.022478;
  expl_temp.s__l4y = 0.098639;
  expl_temp.s__l4x = -0.000203;
  expl_temp.s__l3z = 0.087283;
  expl_temp.s__l3y = 0.01601;
  expl_temp.s__l3x = -0.000208;
  expl_temp.s__l2z = 0.017804;
  expl_temp.s__l2y = -0.06472;
  expl_temp.s__l2x = -1.2E-5;
  expl_temp.s__l1z = 0.102503;
  expl_temp.s__l1y = -0.01439;
  expl_temp.s__l1x = 0.0;
  expl_temp.m__l7 = 0.863;
  expl_temp.m__l6 = 2.32;
  expl_temp.m__l5 = 1.889;
  expl_temp.m__l4 = 5.283;
  expl_temp.m__l3 = 2.8;
  expl_temp.m__l2 = 8.807;
  expl_temp.m__l1 = 6.495;
  expl_temp.d__5 = 0.062;
  expl_temp.d__3 = 0.011;
  expl_temp.d__1 = 0.013;
  expl_temp.l__7 = 0.0724;
  expl_temp.l__6 = 0.0796;
  expl_temp.l__5 = 0.1875;
  expl_temp.l__4 = 0.2125;
  expl_temp.l__3 = 0.1875;
  expl_temp.l__2 = 0.2325;
  expl_temp.l__1 = 0.2075;
  expl_temp.l__0 = 0.1525;
  expl_temp.beta = 0.0;
  expl_temp.g = 9.81;
  expl_temp.n = 7.0;
  expl_temp.p_0[0] = 0.0;
  expl_temp.p_0[1] = 0.0;
  expl_temp.p_0[2] = 0.0;
  for (nlead0 = 0; nlead0 < 9; nlead0++) {
    expl_temp.R_0[nlead0] = c[nlead0];
    expl_temp_tmp_2[nlead0] = c[nlead0];
  }

  expl_temp.hanging = false;
  memset(&d[0], 0, 49U * sizeof(real_T));
  for (k_0 = 0; k_0 < 7; k_0++) {
    d[k_0 + 7 * k_0] = v[k_0];
    expl_temp_0.q_limit_lower[k_0] = k[k_0];
    expl_temp_0.q_limit_upper[k_0] = i[k_0];
  }

  expl_temp_0.K__7 = 20000.0;
  expl_temp_0.K__6 = 20000.0;
  expl_temp_0.K__5 = 40000.0;
  expl_temp_0.K__4 = 40000.0;
  expl_temp_0.K__3 = 40000.0;
  expl_temp_0.K__2 = 60000.0;
  expl_temp_0.K__1 = 60000.0;
  expl_temp_0.I__r7zz = 1.851125E-5;
  expl_temp_0.I__r7yy = 1.5E-5;
  expl_temp_0.I__r7xx = 1.5E-5;
  expl_temp_0.I__r6zz = 1.851125E-5;
  expl_temp_0.I__r6yy = 1.5E-5;
  expl_temp_0.I__r6xx = 1.5E-5;
  expl_temp_0.I__r5zz = 0.0001470968;
  expl_temp_0.I__r5yy = 7.5E-5;
  expl_temp_0.I__r5xx = 7.5E-5;
  expl_temp_0.I__r4zz = 0.0001910384375;
  expl_temp_0.I__r4yy = 0.000129;
  expl_temp_0.I__r4xx = 0.000129;
  expl_temp_0.I__r3zz = 0.0001910384375;
  expl_temp_0.I__r3yy = 0.000129;
  expl_temp_0.I__r3xx = 0.000129;
  expl_temp_0.I__r2zz = 0.00042316695312500003;
  expl_temp_0.I__r2yy = 0.000185;
  expl_temp_0.I__r2xx = 0.000185;
  expl_temp_0.I__r1zz = 0.00042316695312500003;
  expl_temp_0.I__r1yy = 0.000185;
  expl_temp_0.I__r1xx = 0.000185;
  for (nlead0 = 0; nlead0 < 49; nlead0++) {
    expl_temp_0.tau_max[nlead0] = expl_temp_tmp[nlead0];
    expl_temp_0.K[nlead0] = expl_temp_tmp_0[nlead0];
    expl_temp_0.B[nlead0] = f[nlead0];
    expl_temp_0.N[nlead0] = expl_temp_tmp_1[nlead0];
  }

  expl_temp_0.n__7 = 160.0;
  expl_temp_0.n__6 = 160.0;
  expl_temp_0.n__5 = 100.0;
  expl_temp_0.n__4 = 160.0;
  expl_temp_0.n__3 = 160.0;
  expl_temp_0.n__2 = 160.0;
  expl_temp_0.n__1 = 160.0;
  expl_temp_0.I__l7zz = 0.001105;
  expl_temp_0.I__l7yy = 0.000888;
  expl_temp_0.I__l7xx = 0.000884;
  expl_temp_0.I__l6zz = 0.00606797638550296;
  expl_temp_0.I__l6yy = 0.00477633755783711;
  expl_temp_0.I__l6xx = 0.00732758787216765;
  expl_temp_0.I__l5zz = 0.00571863785412578;
  expl_temp_0.I__l5yy = 0.0116859337751969;
  expl_temp_0.I__l5xx = 0.0138359953358589;
  expl_temp_0.I__l4zz = 0.0466529007761679;
  expl_temp_0.I__l4yy = 0.00964726804146909;
  expl_temp_0.I__l4xx = 0.0472789668341968;
  expl_temp_0.I__l3zz = 0.0554482283748983;
  expl_temp_0.I__l3yy = 0.0228661554143474;
  expl_temp_0.I__l3xx = 0.0230152941318817;
  expl_temp_0.I__l2zz = 0.0873510892661361;
  expl_temp_0.I__l2yy = 0.0164110968055191;
  expl_temp_0.I__l2xx = 0.0824701683534692;
  expl_temp_0.I__l1zz = 0.0200625854402119;
  expl_temp_0.I__l1yy = 0.0711085586914514;
  expl_temp_0.I__l1xx = 0.0690761441316632;
  expl_temp_0.s__l7z = 0.018862000000000004;
  expl_temp_0.s__l7y = -9.3E-5;
  expl_temp_0.s__l7x = 0.0019040000000000003;
  expl_temp_0.s__l6z = 0.042269;
  expl_temp_0.s__l6y = -0.016982;
  expl_temp_0.s__l6x = -0.000363;
  expl_temp_0.s__l5z = 0.062938;
  expl_temp_0.s__l5y = -0.014468;
  expl_temp_0.s__l5x = -5.7E-5;
  expl_temp_0.s__l4z = 0.022478;
  expl_temp_0.s__l4y = 0.098639;
  expl_temp_0.s__l4x = -0.000203;
  expl_temp_0.s__l3z = 0.087283;
  expl_temp_0.s__l3y = 0.01601;
  expl_temp_0.s__l3x = -0.000208;
  expl_temp_0.s__l2z = 0.017804;
  expl_temp_0.s__l2y = -0.06472;
  expl_temp_0.s__l2x = -1.2E-5;
  expl_temp_0.s__l1z = 0.102503;
  expl_temp_0.s__l1y = -0.01439;
  expl_temp_0.s__l1x = 0.0;
  expl_temp_0.m__l7 = 0.863;
  expl_temp_0.m__l6 = 2.32;
  expl_temp_0.m__l5 = 1.889;
  expl_temp_0.m__l4 = 5.283;
  expl_temp_0.m__l3 = 2.8;
  expl_temp_0.m__l2 = 8.807;
  expl_temp_0.m__l1 = 6.495;
  expl_temp_0.d__5 = 0.062;
  expl_temp_0.d__3 = 0.011;
  expl_temp_0.d__1 = 0.013;
  expl_temp_0.l__7 = 0.0724;
  expl_temp_0.l__6 = 0.0796;
  expl_temp_0.l__5 = 0.1875;
  expl_temp_0.l__4 = 0.2125;
  expl_temp_0.l__3 = 0.1875;
  expl_temp_0.l__2 = 0.2325;
  expl_temp_0.l__1 = 0.2075;
  expl_temp_0.l__0 = 0.1525;
  expl_temp_0.beta = 0.0;
  expl_temp_0.g = 9.81;
  expl_temp_0.n = 7.0;
  expl_temp_0.p_0[0] = 0.0;
  expl_temp_0.p_0[1] = 0.0;
  expl_temp_0.p_0[2] = 0.0;
  for (nlead0 = 0; nlead0 < 9; nlead0++) {
    expl_temp_0.R_0[nlead0] = expl_temp_tmp_2[nlead0];
  }

  expl_temp_0.hanging = false;
  b_m[0] = 0.0;
  t11 = 0.0019040000000000003 * t33 * 0.863;
  t20 = -9.3E-5 * t33_tmp * 0.863;
  t91 = (0.00084215999999999989 - t11) + t20;
  t29 = t91 * t9;
  t78 = (-0.12437094600000001 * t14 + t29) - -0.00010767300000000001;
  t27 = -8.0258999999999992E-5 * t33;
  t33 = 0.0019040000000000003 * t33_tmp * 0.863;
  t45 = ((-0.045775919999999991 + t27) + t33) + -0.027330052;
  t50 = (t78 * t7 + t45 * t18_tmp) - -0.001072449;
  t41 = 0.12437094600000001 * t9;
  t37 = t91 * t14;
  t5 = ((((t41 + t37) + 0.3452) + 0.92799999999999994) + 0.5203023819999999) +
    0.521109837;
  t55 = t5 * t9_tmp;
  t58 = (t50 * t7_tmp + 0.0005824) + t55;
  t12 = t45 * t16_tmp;
  t19 = 0.12437094600000001 * t14;
  t28 = (t9 * -t91 + -0.00010767300000000001) + t19;
  t76 = t16_tmp * t28;
  t87 = t5 * t7_tmp;
  t17 = ((0.045775919999999991 - t27) - t33) - -0.027330052;
  t36 = (t7 * t28 + t18_tmp * t17) + -0.001072449;
  b_m[1] = (((((t7 * t12 + 0.00010568400000000001) + t18_tmp * t76) + t58 *
              t14_tmp) + t16_tmp * -0.015810274000000013) * t22_tmp - (((((((t36
    * t9_tmp + t87) + 0.36246) + 0.9744) + 0.79338000000000009) +
    2.2188600000000003) + 0.89539240000000009) - -0.56998904000000006) * t24_tmp)
    * 9.81;
  t5 = t7 * t45;
  b_m[2] = (((t5 * t14_tmp + t18_tmp * t14_tmp * t28) - t58 * t16_tmp) + t14_tmp
            * -0.015810274000000013) * t24_tmp * 9.81;
  b_m[3] = ((-t50 * t9_tmp + t87) * t14_tmp * t24_tmp + (t7_tmp * t36 - t55) *
            t22_tmp) * 9.81;
  b_m[4] = ((((-t78 * t18_tmp + t5) * t7_tmp * t14_tmp - t12 * t18_tmp) + t76 *
             t7) * t24_tmp + (t7 * t17 - t18_tmp * t28) * t9_tmp * t22_tmp) *
    9.81;
  t29 += -t19;
  t91 = -t14 * -t91 + t41;
  b_m[5] = ((((t9 * -0.12437094600000001 - t37) * t7 * t7_tmp + t29 * t9_tmp) *
             t14_tmp + t16_tmp * t91 * t18_tmp) * t24_tmp + (t91 * t7 * t9_tmp +
             t29 * t7_tmp) * t22_tmp) * 9.81;
  t91 = t33 + t27;
  t11 += -t20;
  t14 *= t91;
  t5 = t11 * t18_tmp;
  b_m[6] = (((((t9 * t91 * t7 + t5) * t7_tmp + t14 * t9_tmp) * t14_tmp + t11 *
              t16_tmp * t7) + t16_tmp * -t91 * t9 * t18_tmp) * t24_tmp + ((t9 *
              -t91 * t7 - t5) * t9_tmp + t14 * t7_tmp) * t22_tmp) * 9.81;

  // DigitalClock: '<Root>/Digital Clock1'
  t7 = (((&rtM)->Timing.clockTick0) * 0.000125);

  // RateTransition: '<Root>/TmpRTBAtDigital ClockOutport1'
  if ((&rtM)->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.TmpRTBAtDigitalClockOutport1 =
      rtDW.TmpRTBAtDigitalClockOutport1_Buffer0;
  }

  // End of RateTransition: '<Root>/TmpRTBAtDigital ClockOutport1'

  // SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
  //   Chart: '<Root>/Chart'
  //   MATLAB Function: '<Root>/Parabola'

  rtb_TmpSignalConversionAtSFunctionInport4_h[0] = 0.0;
  rtb_TmpSignalConversionAtSFunctionInport4_h[1] = 0.0;

  // MATLAB Function: '<Root>/Parabola'
  t11 = 0.0;
  if (rtDW.throw_pers != 0.0) {
    t11 = rtDW.TmpRTBAtDigitalClockOutport1 - rtDW.t_throw_start;

    // SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
    //   Chart: '<Root>/Chart'

    rtb_TmpSignalConversionAtSFunctionInport4_h[0] = -2.6 * t11 + 2.4;
    rtb_TmpSignalConversionAtSFunctionInport4_h[1] = 3.0 * t11 + -2.4;
    t11 = (3.5 * t11 + 1.0) - t11 * t11 * 4.905;
    if (t11 < 0.7) {
      rtDW.throw_pers = 0.0;
    }
  }

  // SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
  //   Chart: '<Root>/Chart'
  //   MATLAB Function: '<Root>/Parabola'

  rtb_TmpSignalConversionAtSFunctionInport4_h[2] = t11;

  // Chart: '<Root>/Chart'
  if (rtDW.temporalCounter_i1 < 65535U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c9_controller_ballcatcher == 0U) {
    rtDW.is_active_c9_controller_ballcatcher = 1U;
    rtDW.is_c9_controller_ballcatcher = IN_INIT;
    rtDW.use_pred = 0.0;
    rtDW.t_catch_predict[0] = 0.0;
    rtDW.t_catch_predict[1] = 0.0;
    rtDW.p0[0] = 0.0;
    rtDW.pd[0] = 0.0;
    rtDW.p0[1] = 0.0;
    rtDW.pd[1] = 0.0;
    rtDW.p0[2] = 1.332;
    rtDW.pd[2] = 1.332;
  } else {
    switch (rtDW.is_c9_controller_ballcatcher) {
     case IN_CATCH:
      rtDW.state = 2.0;
      if (rtDW.TmpRTBAtDigitalClockOutport1 > rtDW.t_catch_predict[1]) {
        rtDW.use_pred = 0.0;
        rtDW.is_c9_controller_ballcatcher = IN_NO_VALID_BALL_VALUE;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.state = 3.0;
      } else {
        // Outputs for Function Call SubSystem: '<S1>/estimate_parabola'
        estimate_parabola(rtDW.TmpRTBAtDigitalClockOutport1, rtDW.t_start,
                          rtb_TmpSignalConversionAtSFunctionInport4_h, 0.0,
                          rtDW.pd, pd_p, &rtDW.use_pred, rtDW.t_catch_predict,
                          &rtDW.estimate_parabola_j);

        // End of Outputs for SubSystem: '<S1>/estimate_parabola'
      }
      break;

     case IN_GO_TO_HAND_OVER:
      rtDW.state = 4.0;
      if (rtDW.temporalCounter_i1 >= 24000U) {
        rtDW.is_c9_controller_ballcatcher = IN_GO_TO_START_FROM_CATCH;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.state = 5.0;
        rtDW.t_catch_predict[0] = rtDW.TmpRTBAtDigitalClockOutport1;
        rtDW.t_catch_predict[1] = rtDW.TmpRTBAtDigitalClockOutport1 + 3.0;
        rtDW.p0[0] = 0.5;
        rtDW.pd[0] = 0.4;
        rtDW.p0[1] = 0.0;
        rtDW.pd[1] = 0.0;
        rtDW.p0[2] = 0.68;
        rtDW.pd[2] = 0.8;
      }
      break;

     case IN_GO_TO_START_FROM_CATCH:
      rtDW.state = 5.0;
      if (rtDW.temporalCounter_i1 >= 24000U) {
        rtDW.is_c9_controller_ballcatcher = IN_READY;
        rtDW.state = 1.0;
        rtDW.p0[0] = 0.4;
        rtDW.pd[0] = 0.4;
        rtDW.p0[1] = 0.0;
        rtDW.pd[1] = 0.0;
        rtDW.p0[2] = 0.8;
        rtDW.pd[2] = 0.8;
      }
      break;

     case IN_GO_TO_START_FROM_NO_CATCH:
      rtDW.state = 6.0;
      if (rtDW.temporalCounter_i1 >= 24000U) {
        rtDW.is_c9_controller_ballcatcher = IN_READY;
        rtDW.state = 1.0;
        rtDW.p0[0] = 0.4;
        rtDW.pd[0] = 0.4;
        rtDW.p0[1] = 0.0;
        rtDW.pd[1] = 0.0;
        rtDW.p0[2] = 0.8;
        rtDW.pd[2] = 0.8;
      }
      break;

     case IN_INIT:
      break;

     case IN_INIT_GOTO_START:
      if (rtDW.temporalCounter_i1 >= 40000U) {
        rtDW.is_c9_controller_ballcatcher = IN_READY;
        rtDW.state = 1.0;
        rtDW.p0[0] = 0.4;
        rtDW.pd[0] = 0.4;
        rtDW.p0[1] = 0.0;
        rtDW.pd[1] = 0.0;
        rtDW.p0[2] = 0.8;
        rtDW.pd[2] = 0.8;
      }
      break;

     case IN_NO_VALID_BALL_VALUE:
      rtDW.state = 3.0;
      if (rtDW.temporalCounter_i1 >= 8000U) {
        rtDW.is_c9_controller_ballcatcher = IN_GO_TO_HAND_OVER;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.state = 4.0;
        rtDW.t_catch_predict[0] = rtDW.TmpRTBAtDigitalClockOutport1;
        rtDW.t_catch_predict[1] = rtDW.TmpRTBAtDigitalClockOutport1 + 3.0;
        rtDW.p0[0] = rtDW.pd[0];
        rtDW.pd[0] = 0.5;
        rtDW.p0[1] = rtDW.pd[1];
        rtDW.pd[1] = 0.0;
        rtDW.p0[2] = rtDW.pd[2];
        rtDW.pd[2] = 0.68;
      }
      break;

     default:
      rtDW.state = 1.0;
      if (isBallValueValid(rtb_TmpSignalConversionAtSFunctionInport4_h)) {
        rtDW.is_c9_controller_ballcatcher = IN_CATCH;
        rtDW.state = 2.0;
        rtDW.t_start = rtDW.TmpRTBAtDigitalClockOutport1;

        // Outputs for Function Call SubSystem: '<S1>/estimate_parabola'
        estimate_parabola(rtDW.TmpRTBAtDigitalClockOutport1,
                          rtDW.TmpRTBAtDigitalClockOutport1,
                          rtb_TmpSignalConversionAtSFunctionInport4_h, 1.0,
                          rtDW.pd, pd_p, &rtDW.use_pred, rtDW.t_catch_predict,
                          &rtDW.estimate_parabola_j);

        // End of Outputs for SubSystem: '<S1>/estimate_parabola'
      }
      break;
    }
  }

  // MATLAB Function: '<Root>/Trajectoy Generator'
  t9 = rtDW.pd[0];
  t14 = rtDW.pd[1];
  t11 = rtDW.pd[2];
  t20 = std::sqrt(rtDW.pd[0] * rtDW.pd[0] + rtDW.pd[1] * rtDW.pd[1]);
  if (t20 > 0.7) {
    t9 = rtDW.pd[0] / t20 * 0.7;
    t14 = rtDW.pd[1] / t20 * 0.7;
  } else {
    if ((rtDW.state == 2.0) && (rtDW.use_pred == 0.0)) {
      t9 = rtDW.p0[0];
      t14 = rtDW.p0[1];
      t11 = rtDW.p0[2];
    }
  }

  rtb_TmpSignalConversionAtSFunctionInport4_h[0] = rtDW.p0[0];
  rtb_TmpSignalConversionAtSFunctionInport4_h[1] = rtDW.p0[1];
  rtb_TmpSignalConversionAtSFunctionInport4_h[2] = rtDW.p0[2];
  trvec2tform(rtb_TmpSignalConversionAtSFunctionInport4_h, rtb_T0);
  rtb_TmpSignalConversionAtSFunctionInport4_h[0] = t9;
  rtb_TmpSignalConversionAtSFunctionInport4_h[1] = t14;
  rtb_TmpSignalConversionAtSFunctionInport4_h[2] = t11;
  trvec2tform(rtb_TmpSignalConversionAtSFunctionInport4_h, rtb_Tf);

  // End of MATLAB Function: '<Root>/Trajectoy Generator'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLAB Function: '<Root>/Robot Model'

  p = false;
  b_p = true;
  k_0 = 0;
  exitg1 = false;
  while ((!exitg1) && (k_0 < 16)) {
    if (!(rtb_T0[k_0] == rtConstP.pooled1.T_candle[k_0])) {
      b_p = false;
      exitg1 = true;
    } else {
      k_0++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (p) {
    for (k_0 = 0; k_0 < 7; k_0++) {
      V[k_0] = 0.0;
    }
  } else {
    inverse_kinematics_analytic(rtb_T0, &rtConstP.MATLABFunction_param_robot, &p,
      V);
  }

  p = false;
  b_p = true;
  k_0 = 0;
  exitg1 = false;
  while ((!exitg1) && (k_0 < 16)) {
    if (!(rtb_Tf[k_0] == rtConstP.pooled1.T_candle[k_0])) {
      b_p = false;
      exitg1 = true;
    } else {
      k_0++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (p) {
    for (k_0 = 0; k_0 < 7; k_0++) {
      qf[k_0] = 0.0;
    }
  } else {
    inverse_kinematics_analytic(rtb_Tf, &rtConstP.MATLABFunction_param_robot, &p,
      qf);
  }

  for (k_0 = 0; k_0 < 7; k_0++) {
    rtb_q[k_0] = 0.0;
    rtb_tau_slow[k_0] = 0.0;
    rtb_tau_p_slow[k_0] = 0.0;
  }

  memset(&rtb_q_d[0], 0, 21U * sizeof(real_T));
  if ((t7 >= rtDW.t_catch_predict[0]) && (t7 <= rtDW.t_catch_predict[1])) {
    t9 = rtDW.t_catch_predict[1] - rtDW.t_catch_predict[0];
    t7 -= rtDW.t_catch_predict[0];
    for (k_0 = 0; k_0 < 7; k_0++) {
      coeffs[0] = V[k_0];
      coeffs[1] = qf[k_0];
      coeffs[2] = 0.0;
      coeffs[3] = 0.0;
      coeffs[4] = 0.0;
      coeffs[5] = 0.0;
      m_1[1] = 1.0;
      m_1[7] = t9;
      t7_tmp = t9 * t9 / 2.0;
      m_1[13] = t7_tmp;
      t9_tmp = rt_powd_snf(t9, 3.0) / 6.0;
      m_1[19] = t9_tmp;
      t14_tmp = rt_powd_snf(t9, 4.0) / 24.0;
      m_1[25] = t14_tmp;
      m_1[31] = rt_powd_snf(t9, 5.0) / 120.0;
      m_1[3] = 0.0;
      m_1[9] = 1.0;
      m_1[15] = t9;
      m_1[21] = t7_tmp;
      m_1[27] = t9_tmp;
      m_1[33] = t14_tmp;
      for (nlead0 = 0; nlead0 < 6; nlead0++) {
        m_1[6 * nlead0] = m_0[nlead0];
        m_1[2 + 6 * nlead0] = o[nlead0];
        m_1[4 + 6 * nlead0] = q[nlead0];
      }

      m_1[5] = 0.0;
      m_1[11] = 0.0;
      m_1[17] = 1.0;
      m_1[23] = t9;
      m_1[29] = t7_tmp;
      m_1[35] = t9_tmp;
      mldivide_ln(m_1, coeffs);
      t14 = coeffs[0];
      coeffs[0] = coeffs[5];
      coeffs[5] = t14;
      t14 = coeffs[1];
      coeffs[1] = coeffs[4];
      coeffs[4] = t14;
      t14 = coeffs[2];
      coeffs[2] = coeffs[3];
      coeffs[0] /= 120.0;
      coeffs[1] /= 24.0;
      coeffs[2] /= 6.0;
      coeffs[3] = t14 / 2.0;
      t14 = coeffs[0];
      for (nlead0 = 0; nlead0 < 5; nlead0++) {
        t14 = t7 * t14 + coeffs[nlead0 + 1];
      }

      rtb_q[k_0] = t14;
      nlead0 = 0;
      n = 0;
      while ((n < 4) && (coeffs[n] == 0.0)) {
        nlead0++;
        n++;
      }

      pd_size[0] = 1;
      pd_size[1] = 5 - nlead0;
      for (n = 0; n <= 4 - nlead0; n++) {
        pd_data[n] = coeffs[n + nlead0];
      }

      n = pd_size[1] - 2;
      for (ny = 0; ny <= n; ny++) {
        pd_data[ny] *= (real_T)((n - ny) + 1) + 1.0;
      }

      if (rtIsInf(coeffs[5]) || rtIsNaN(coeffs[5])) {
        pd_data[pd_size[1] - 1] = (rtNaN);
      }

      rtb_tau_slow[k_0] = polyval(pd_data, pd_size, t7);
      if (pd_size[1] < 2) {
        nlead0 = 1;
      } else {
        nlead0 = pd_size[1] - 1;
      }

      pdd_size[0] = 1;
      pdd_size[1] = nlead0;
      switch (pd_size[1]) {
       case 0:
        pdd_data[0] = 0.0;
        break;

       case 1:
        pdd_data[0] = 0.0;
        break;

       default:
        n = 0;
        ny = 0;
        while ((ny <= nlead0 - 2) && (pd_data[ny] == 0.0)) {
          n++;
          ny++;
        }

        ny = nlead0 - n;
        pdd_size[0] = 1;
        pdd_size[1] = ny;
        for (nlead0 = 0; nlead0 < ny; nlead0++) {
          pdd_data[nlead0] = pd_data[nlead0 + n];
        }
        break;
      }

      n = pdd_size[1] - 2;
      for (ny = 0; ny <= n; ny++) {
        pdd_data[ny] *= (real_T)((n - ny) + 1) + 1.0;
      }

      if (pd_size[1] != 0) {
        t7_tmp = pd_data[pd_size[1] - 1];
        if (rtIsInf(t7_tmp) || rtIsNaN(t7_tmp)) {
          pdd_data[pdd_size[1] - 1] = (rtNaN);
        }
      }

      rtb_tau_p_slow[k_0] = polyval(pdd_data, pdd_size, t7);
      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        l_data[nlead0] = 14 + nlead0;
      }

      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        rtb_q_d[l_data[nlead0]] = rtb_tau_p_slow[nlead0];
      }

      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        l_data[nlead0] = 7 + nlead0;
      }

      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        rtb_q_d[l_data[nlead0]] = rtb_tau_slow[nlead0];
      }

      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        l_data[nlead0] = nlead0;
      }

      for (nlead0 = 0; nlead0 < 7; nlead0++) {
        rtb_q_d[l_data[nlead0]] = rtb_q[nlead0];
      }
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtb_q_d[k_0] = rtb_theta_slow[k_0];
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // Outputs for Enabled SubSystem: '<S8>/Joint-based E//A Linearization' incorporates:
  //   EnablePort: '<S22>/Enable'

  if (!rtDW.JointbasedEALinearization_MODE) {
    // SystemReset for MATLAB Function: '<S22>/Joint-based E//A Linearization'
    rtDW.e_I_not_empty = false;
    rtDW.JointbasedEALinearization_MODE = true;
  }

  // MATLAB Function: '<S22>/Joint-based E//A Linearization' incorporates:
  //   Inport: '<Root>/motion_enabled'
  //   MATLAB Function: '<Root>/Robot Model'

  if ((!(rtU.motion_enabled != 0.0)) || (!rtDW.e_I_not_empty)) {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.e_I[k_0] = 0.0;
    }

    rtDW.e_I_not_empty = true;
  }

  for (k_0 = 0; k_0 < 7; k_0++) {
    V[k_0] = rtb_theta_slow[k_0] - rtb_q_d[k_0];
  }

  // End of Outputs for SubSystem: '<S8>/Joint-based E//A Linearization'

  // MATLAB Function: '<Root>/Robot Model'
  iiwa_reduced_inertia_matrix(rtb_theta_slow, &expl_temp, tmp);
  iiwa_reduced_coriolis_matrix(rtb_theta_slow, alpha, &expl_temp_0, tmp_0);
  for (nlead0 = 0; nlead0 < 49; nlead0++) {
    tmp_1[nlead0] = tmp[nlead0] + d[nlead0];
  }

  // Outputs for Enabled SubSystem: '<S8>/Joint-based E//A Linearization' incorporates:
  //   EnablePort: '<S22>/Enable'

  // MATLAB Function: '<S22>/Joint-based E//A Linearization' incorporates:
  //   MATLAB Function: '<Root>/Robot Model'

  for (nlead0 = 0; nlead0 < 7; nlead0++) {
    qf[nlead0] = ((rtb_q_d[14 + nlead0] - (alpha[nlead0] - rtb_q_d[7 + nlead0]) *
                   20.0) - 100.0 * V[nlead0]) - 0.0 * rtDW.e_I[nlead0];
  }

  for (nlead0 = 0; nlead0 < 7; nlead0++) {
    rtb_theta_slow[nlead0] = 0.0;
    t7_tmp = 0.0;
    for (k_0 = 0; k_0 < 7; k_0++) {
      n = 7 * k_0 + nlead0;
      t7_tmp += tmp_0[n] * alpha[k_0];
      rtb_theta_slow[nlead0] += tmp_1[n] * qf[k_0];
    }

    rtDW.tau_d[nlead0] = (t7_tmp + b_m[nlead0]) + rtb_theta_slow[nlead0];
    rtDW.e_I[nlead0] += V[nlead0] * 0.000125;
  }

  // End of Outputs for SubSystem: '<S8>/Joint-based E//A Linearization'

  // Outputs for Enabled SubSystem: '<S8>/Gravitation compensation q-based' incorporates:
  //   EnablePort: '<S21>/Enable'

  if (rtDW.Gravitationcompensationqbased_MODE) {
    rtDW.Gravitationcompensationqbased_MODE = false;
  }

  // End of Outputs for SubSystem: '<S8>/Gravitation compensation q-based'
  for (k_0 = 0; k_0 < 7; k_0++) {
    // MATLAB Function: '<S8>/Controller Selector'
    rtb_theta_slow[k_0] = rtDW.tau_d[k_0];

    // MATLAB Function: '<S11>/f_tau'
    alpha[k_0] = std::exp(-0.000125 / rtConstP.pooled5[k_0]);
  }

  // MATLAB Function: '<S11>/f_tau'
  if (!rtDW.x_not_empty_c) {
    rtDW.x_not_empty_c = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_mn[k_0] = 1.0 / (1.0 - alpha[k_0]) * rtb_Subtract[k_0];
      b_m[k_0] = rtb_Subtract[k_0];
    }
  } else {
    for (nlead0 = 0; nlead0 < 7; nlead0++) {
      b_m[nlead0] = (1.0 - alpha[nlead0]) * rtDW.x_mn[nlead0];
      rtDW.x_mn[nlead0] = alpha[nlead0] * rtDW.x_mn[nlead0] +
        rtb_Subtract[nlead0];
    }
  }

  // MATLAB Function: '<S11>/f_tau_p'
  for (k_0 = 0; k_0 < 7; k_0++) {
    V[k_0] = (1.0 - std::exp(-0.000125 / rtConstP.pooled5[k_0])) * 8000.0;
  }

  if (!rtDW.x_not_empty_km) {
    rtDW.x_not_empty_km = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_m[k_0] = -V[k_0] * rtb_Subtract[k_0];
      alpha[k_0] = 0.0;
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      alpha[k_0] = V[k_0] * rtb_Subtract[k_0] + rtDW.x_m[k_0];
      t7 = std::exp(-0.000125 / rtConstP.pooled5[k_0]);
      rtDW.x_m[k_0] = (t7 - 1.0) * V[k_0] * rtb_Subtract[k_0] + t7 *
        rtDW.x_m[k_0];
    }
  }

  // End of MATLAB Function: '<S11>/f_tau_p'

  // MATLAB Function: '<S11>/f_theta_p' incorporates:
  //   Inport: '<Root>/fast_sensor_position'

  for (k_0 = 0; k_0 < 7; k_0++) {
    V[k_0] = (1.0 - std::exp(-0.000125 / rtConstP.pooled5[k_0])) * 8000.0;
  }

  if (!rtDW.x_not_empty_e) {
    rtDW.x_not_empty_e = true;
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_j[k_0] = -V[k_0] * rtU.fast_sensor_position[k_0];
      rtb_Subtract[k_0] = 0.0;
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtb_Subtract[k_0] = V[k_0] * rtU.fast_sensor_position[k_0] + rtDW.x_j[k_0];
      t7 = std::exp(-0.000125 / rtConstP.pooled5[k_0]);
      rtDW.x_j[k_0] = (t7 - 1.0) * V[k_0] * rtU.fast_sensor_position[k_0] + t7 *
        rtDW.x_j[k_0];
    }
  }

  // End of MATLAB Function: '<S11>/f_theta_p'

  // Outputs for Enabled SubSystem: '<Root>/Friction Compensation' incorporates:
  //   EnablePort: '<S4>/Enable'

  for (k_0 = 0; k_0 < 7; k_0++) {
    // SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport7' incorporates:
    //   Constant: '<S4>/E'
    //   Constant: '<S4>/tau_c_minus'
    //   Constant: '<S4>/tau_c_plus'
    //   Constant: '<S4>/tau_v'
    //   MATLAB Function: '<S4>/Friction Observer discrete'

    rtb_TmpSignalConversionAtSFunctionInport7[k_0] =
      rtConstP.tau_c_plus_Value[k_0];
    rtb_TmpSignalConversionAtSFunctionInport7[k_0 + 7] =
      rtConstP.tau_c_minus_Value[k_0];
    rtb_TmpSignalConversionAtSFunctionInport7[k_0 + 14] = rtConstP.E_Value[k_0];
    rtb_TmpSignalConversionAtSFunctionInport7[k_0 + 21] =
      rtConstP.tau_v_Value[k_0];
  }

  // SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport7' incorporates:
  //   Constant: '<S4>/subtract_model'
  //   Constant: '<S4>/use_q_p'
  //   Constant: '<S4>/use_theta_p_hat'
  //   MATLAB Function: '<S4>/Friction Observer discrete'

  rtb_TmpSignalConversionAtSFunctionInport7[28] = 0.0;
  rtb_TmpSignalConversionAtSFunctionInport7[29] = 0.0;
  rtb_TmpSignalConversionAtSFunctionInport7[30] = 0.0;

  // MATLAB Function: '<S4>/Friction Observer discrete' incorporates:
  //   Constant: '<S4>/L'
  //   Inport: '<Root>/fast_sensor_motor_torque_feedback'
  //   Inport: '<Root>/motion_enabled'

  if (rtU.motion_enabled != 0.0) {
    nlead0 = 0;
    for (k_0 = 0; k_0 < 7; k_0++) {
      qf[k_0] = 0.0;
      if (rtb_Subtract[k_0] >= 0.0) {
        nlead0++;
      }

      V[k_0] = rtb_Subtract[k_0];
    }

    n = nlead0;
    nlead0 = 0;
    for (k_0 = 0; k_0 < 7; k_0++) {
      if (V[k_0] >= 0.0) {
        e_data[nlead0] = (int8_T)(k_0 + 1);
        nlead0++;
      }
    }

    for (nlead0 = 0; nlead0 < n; nlead0++) {
      r_data[nlead0] = rtb_TmpSignalConversionAtSFunctionInport7[e_data[nlead0]
        + 13] * V[e_data[nlead0] - 1];
    }

    if (0 <= n - 1) {
      memcpy(&b_data[0], &r_data[0], n * sizeof(real_T));
    }

    for (k_0 = 0; k_0 < n; k_0++) {
      b_data[k_0] = std::tanh(b_data[k_0]);
    }

    nlead0 = 0;
    for (k_0 = 0; k_0 < 7; k_0++) {
      if (V[k_0] >= 0.0) {
        c_data[nlead0] = rtb_TmpSignalConversionAtSFunctionInport7[k_0] *
          b_data[nlead0];
        nlead0++;
      }
    }

    nlead0 = 0;
    for (k_0 = 0; k_0 < 7; k_0++) {
      if (V[k_0] >= 0.0) {
        qf[k_0] = c_data[nlead0];
        nlead0++;
      }
    }

    for (k_0 = 0; k_0 < 7; k_0++) {
      t7 = v_0[7 * k_0 + k_0] * -rtConstP.L_Value[k_0] * (rtb_Subtract[k_0] -
        rtDW.x_theta_p_hat[k_0]);
      qf[k_0] = (rtU.fast_sensor_motor_torque_feedback[k_0] - b_m[k_0]) - t7;
      V[k_0] = t7;
    }

    mldivide(v_0, qf);
    for (nlead0 = 0; nlead0 < 7; nlead0++) {
      rtDW.x_theta_p_hat[nlead0] += 0.000125 * qf[nlead0];
    }
  } else {
    for (k_0 = 0; k_0 < 7; k_0++) {
      rtDW.x_theta_p_hat[k_0] = 0.0;
      V[k_0] = 0.0;
    }
  }

  for (k_0 = 0; k_0 < 7; k_0++) {
    // Sum: '<S4>/Add2'
    rtDW.Add2[k_0] = V[k_0];

    // Outport: '<Root>/fast_control_motor_torque' incorporates:
    //   MATLAB Function: '<Root>/Singular Perturbation Controller'
    //   Sum: '<Root>/Add'

    rtY.fast_control_motor_torque[k_0] = (((b_m[k_0] - rtb_theta_slow[k_0]) *
      b_0[k_0] + c_0[k_0] * alpha[k_0]) + rtb_theta_slow[k_0]) + rtDW.Add2[k_0];
  }

  // End of Outputs for SubSystem: '<Root>/Friction Compensation'

  // MATLAB Function: '<Root>/Robot Pose Logger' incorporates:
  //   Inport: '<Root>/sensor_mft_application_button'

  if (!rtDW.last_application_button_not_empty) {
    rtDW.last_application_button = rtU.sensor_mft_application_button;
    rtDW.last_application_button_not_empty = true;
  }

  if ((rtDW.last_application_button != rtU.sensor_mft_application_button) &&
      (rtU.sensor_mft_application_button != 0.0)) {
    printf("[%.10f,%.10f,%.10f,%.10f;%.10f,%.10f,%.10f,%.10f;%.10f,%.10f,%.10f,%.10f],...",
           rtb_robot_model_H[0], rtb_robot_model_H[4], rtb_robot_model_H[8],
           rtb_robot_model_H[12], rtb_robot_model_H[1], rtb_robot_model_H[5],
           rtb_robot_model_H[9], rtb_robot_model_H[13], rtb_robot_model_H[2],
           rtb_robot_model_H[6], rtb_robot_model_H[10], rtb_robot_model_H[14]);
    fflush(stdout);
  }

  rtDW.last_application_button = rtU.sensor_mft_application_button;

  // End of MATLAB Function: '<Root>/Robot Pose Logger'

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.000125, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  (&rtM)->Timing.clockTick0++;
}

// Model step function for TID1
void controller_ballcatcherModelClass::step1() // Sample time: [0.008s, 0.0s]
{
  real_T rtb_DigitalClock;

  // DigitalClock: '<Root>/Digital Clock'
  rtb_DigitalClock = (((&rtM)->Timing.clockTick1) * 0.008);

  // Update for RateTransition: '<Root>/TmpRTBAtDigital ClockOutport1'
  rtDW.TmpRTBAtDigitalClockOutport1_Buffer0 = rtb_DigitalClock;

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.008, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  (&rtM)->Timing.clockTick1++;
}

// Model step function for TID2
void controller_ballcatcherModelClass::step2() // Sample time: [0.01s, 0.0s]
{
  // (no output/update code required)
}

// Model initialize function
void controller_ballcatcherModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // ConstCode for Outport: '<Root>/fast_control_motor_enable' incorporates:
  //   Constant: '<Root>/Constant10'
  //   Constant: '<Root>/Constant22'
  //   Constant: '<Root>/Constant23'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'

  rtY.fast_control_motor_enable[0] = 1.0;
  rtY.fast_control_motor_enable[1] = 1.0;
  rtY.fast_control_motor_enable[2] = 1.0;
  rtY.fast_control_motor_enable[3] = 1.0;
  rtY.fast_control_motor_enable[4] = 1.0;
  rtY.fast_control_motor_enable[5] = 1.0;
  rtY.fast_control_motor_enable[6] = 1.0;
}

// Constructor
controller_ballcatcherModelClass::controller_ballcatcherModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
controller_ballcatcherModelClass::~controller_ballcatcherModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * controller_ballcatcherModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
