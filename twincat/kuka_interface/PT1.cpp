///////////////////////////////////////////////////////////////////////////////
// PT1.cpp
#include "TcPch.h"
#pragma hdrstop
#include "PT1.h"

PT1::PT1(double f_0) {
  if(f_0>0 && isfinite_(f_0)) {
    //PT1 filter with cutoff frequency f_0
    double T_1=1/(2*PI*f_0);
    alpha=exp_(-PT1_T_a/T_1);
  }
  else {
    //PT1 filter with cutoff frequency infinity
    //This results in a unit delay.
    alpha=0;
  }
}

double PT1::updateAndOutput(double u) {
  double y;

  if(is_initialized) {
    y=(1-alpha)*x;
    x=alpha*x+u;
  }
  else {
    y=u;
    x=1/(1-alpha)*u;
    is_initialized=true;
  }
  return y;
}

void PT1::reset() {
  is_initialized=false;
}
