///////////////////////////////////////////////////////////////////////////////
// DifferenceFilter.cpp
#include "TcPch.h"
#pragma hdrstop
#include "DifferenceFilter.h"

DifferenceFilter::DifferenceFilter() {
}

double DifferenceFilter::updateAndOutput(double u) {
  double y=0.0;
  if(is_initialized) {
    y=(u-x)/DIFFERENCEFILTER_T_a;
    x=u;
  }
  else {
    x=u;
    is_initialized=true;
  }
  return y;
}

void DifferenceFilter::reset() {
  is_initialized=false;
}
