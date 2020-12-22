///////////////////////////////////////////////////////////////////////////////
// DT1.cpp
#include "TcPch.h"
#pragma hdrstop
#include "DT1.h"

DT1::DT1(double f_0) {
  if(f_0>0 && isfinite_(f_0)) {
    //DT1 filter with cutoff frequency
    //The amplification is chosen such that the ramp response reflects the
    //correct velocity as output.
    this->T_1=1/(2*PI*f_0);
    this->V=(1/DT1_T_a)*(1-exp_(-DT1_T_a/this->T_1));
  }
  else {
    //DT1 filter with infinite cutoff frequency becomes a Difference Filter
    //x_{k+1}=u_k
    //y_k=1/T_a*(u_k-x_k)
    this->T_1=0;
    this->V=0;
  }
}

double DT1::updateAndOutput(double u) {
  double y;
  if(is_initialized) {
    if(T_1>0) {
      y=x+V*u;
      x=exp_(-DT1_T_a/T_1)*x+(exp_(-DT1_T_a/T_1)-1)*V*u;
    }
    else {
      y=(u-x)/DT1_T_a;
      x=u;
    }
  }
  else {
    //Initialize the filter
    if(T_1>0) {
      x=-V*u;
    }
    else {
      x=u;
    }
    //Output stays zero after being initialized
    y=0.0;
    is_initialized=true;
  }
  return y;
}

void DT1::reset() {
  is_initialized=false;
}
