#pragma once
#define MOVINGAVERAGEFILTER_SIZE 8

class MovingAverageFilter {
  public:
    MovingAverageFilter();

    double buffer[MOVINGAVERAGEFILTER_SIZE];
    bool is_initialized;
    int k;

    void reset();
    double updateAndOutput(double u);
};
