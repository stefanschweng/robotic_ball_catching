#pragma once

#include"KsoeSlave.h"

#define DIFFERENCEFILTER_T_a KSOESLAVE_FILTER_T_a

class DifferenceFilter {
  private:
  double x;
  bool is_initialized;

  public:
  DifferenceFilter();

  double updateAndOutput(double u);
  void reset();
};
