#pragma once
#include"MFTSensor.h"
#include"Robot.h"

#define MOTIONENABLELOGIC_START_TIME 500*8 //Ticks
#define MOTIONENABLELOGIC_COOLDOWN_TIME 1000*8 //Ticks

class MotionEnableLogic {
  private:
  bool last_button_panic;
  bool last_button_pressed;
  bool last_motion_enabled;
  bool last_additional_enable;
  bool last_additional_disable;
  int motion_enable_timer;
  int motion_disable_timer;

  public:
  MotionEnableLogic();
  void enableOrDisableRobot(Robot* robot, MFTSensor* input_mft, bool additional_enable, bool additional_disable);
  ~MotionEnableLogic();
};
