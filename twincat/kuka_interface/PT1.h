#pragma once

class PT1;

#include"KsoeSlave.h"

#define PT1_T_a KSOESLAVE_FILTER_T_a

class PT1 {
  private:
    double alpha;
    double x;
    bool is_initialized;

  public:
    PT1(double f_0);

    double updateAndOutput(double u);
    void reset();
};
