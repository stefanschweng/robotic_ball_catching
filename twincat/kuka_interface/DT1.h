#pragma once

class DT1;

#include"KsoeSlave.h"

#define DT1_T_a KSOESLAVE_FILTER_T_a

class DT1 {
  private:
    double T_1;
    double V;
    double x;
    bool is_initialized;

  public:
    DT1(double f_0);

    double updateAndOutput(double u);
    void reset();
};
