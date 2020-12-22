

    /*
  * rt_nonfinite.h
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


  #ifndef RTW_HEADER_rt_nonfinite_h_
  #define RTW_HEADER_rt_nonfinite_h_
  

    

  
#include <stddef.h>
  #include "rtwtypes.h"



  

  

  

  

  

  

  

  

  

  

  

  

  

  

          #ifdef __cplusplus
      extern "C" {
      #endif
 
  


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
  
  
        #ifdef __cplusplus
      } /* extern "C" */
      #endif
 


  

  

  

  

  

    #endif /* RTW_HEADER_rt_nonfinite_h_ */
