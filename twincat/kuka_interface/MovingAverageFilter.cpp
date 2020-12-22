///////////////////////////////////////////////////////////////////////////////
// MovingAverageFilter.cpp
#include "TcPch.h"
#pragma hdrstop

#include "MovingAverageFilter.h"

MovingAverageFilter::MovingAverageFilter() {
  reset();
}

void MovingAverageFilter::reset() {
  memset(buffer, 0, MOVINGAVERAGEFILTER_SIZE*sizeof(double));
  k=0;
  is_initialized=false;
}

double MovingAverageFilter::updateAndOutput(double u) {
  double y=0.0;

  if(is_initialized) {
    buffer[k]=u;
    k=(k+1)%MOVINGAVERAGEFILTER_SIZE;
    for(int i=0;i<MOVINGAVERAGEFILTER_SIZE;i++) {
      y+=buffer[i];
    }
    y=y/(double)MOVINGAVERAGEFILTER_SIZE;
  }
  else {
    for(int i=0;i<MOVINGAVERAGEFILTER_SIZE;i++) {
      buffer[i]=u;
    }
    k=0;
    is_initialized=true;
  }
  return y;
}
