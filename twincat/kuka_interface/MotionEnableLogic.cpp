///////////////////////////////////////////////////////////////////////////////
// MotionEnableLogic.cpp
#include "TcPch.h"
#pragma hdrstop
#include "MotionEnableLogic.h"

MotionEnableLogic::MotionEnableLogic() {
  last_button_panic=false;
  last_button_pressed=false;
  last_motion_enabled=false;
  last_additional_enable=false;
  last_additional_disable=false;
  motion_enable_timer=0;
  motion_disable_timer=0;
}

MotionEnableLogic::~MotionEnableLogic() {
}

void MotionEnableLogic::enableOrDisableRobot(Robot* robot, MFTSensor* input_mft, bool additional_enable, bool additional_disable) {
  bool motion_enable=false;
  bool motion_disable=false;
  bool mft_button_changed=(last_button_panic!=input_mft->enable_button_panic||last_button_pressed!=input_mft->enable_button_pressed);
  bool motion_enabled=robot->isMotionEnabled();

  //The motion disable timer has highest priority.
  if(motion_disable_timer>0) {
    motion_disable_timer--;
    motion_enable_timer=0;
  }
  else {
    motion_disable_timer=0;
    //If motion got disabled recently (for whatever reason), also start the cooldown timer
    //Direct feedthrough to motion_disable, when button is in panic position
    if((last_motion_enabled!=motion_enabled && !motion_enabled) || input_mft->enable_button_panic){
      motion_enable_timer=0;
      motion_disable_timer=MOTIONENABLELOGIC_COOLDOWN_TIME;
      motion_disable=true;
    }
    //Button was pushed in middle position
    else if(mft_button_changed&&!input_mft->enable_button_panic && input_mft->enable_button_pressed) {
      if(!motion_enabled) {
        //Start motion, when button was held in this position for START_TIME ticks.
        motion_enable_timer=MOTIONENABLELOGIC_START_TIME;
      }
      else if(motion_enabled) {
        //If button is pushed again, stop the motion immediately and lock it
        //for COOLDOWN_TIME ticks.
        motion_disable=true;
        motion_enable_timer=0;
        motion_disable_timer=MOTIONENABLELOGIC_COOLDOWN_TIME;
      }
    }
    //If button position was released or pushed to panic-state, cancel the start
    else if(!input_mft->enable_button_pressed||input_mft->enable_button_panic) {
      motion_enable_timer=0;
    }
    else if(motion_enable_timer>0) {
      motion_enable_timer--;
      if(motion_enable_timer<=0) {
        //If the timer was able to elapse, allow to enable the motion.
        motion_enable=true;
        motion_enable_timer=0;
      }
    }
  }
  //Superpose the additional enable and disable inputs
  if(last_additional_enable!=additional_enable && additional_enable) {
    motion_enable=true;
  }
  if(additional_disable) {
    motion_disable=true;
  }
  //Act according to the requested state change. Disabling has priority over enabling.
  if(motion_disable) {
    robot->performSoftStop();
  }
  else if(motion_enable) {
    robot->enableMotion();
  }

  /*
  //The motion disable timer has highest priority.
  if(motion_disable_timer>0) {
    motion_disable=true;
    motion_disable_timer=motion_disable_timer-1;
    motion_enable_timer=0;
  }
  else {
    motion_disable_timer=0;
    //If motion got disabled recently (for whatever reason), also start the cooldown timer
    if(last_motion_enabled!=motion_enabled && motion_enabled==0) {
      motion_enable_timer=0;
      motion_disable_timer=MOTIONENABLELOGIC_COOLDOWN_TIME;
    }

    //Direct feedthrough to motion_disable, when button is in panic position
    if(input_mft->button_panic) {
      motion_disable=true;
      motion_enable_timer=0;
      motion_disable_timer=MOTIONENABLELOGIC_COOLDOWN_TIME;
    }
    //Button was pushed in middle position
    else if(mft_button_changed && !input_mft->button_panic && input_mft->button_pressed) {
      if(motion_enabled==0) {
        //Start motion, when button was held in this position for START_TIME ticks.
        motion_enable_timer=MOTIONENABLELOGIC_START_TIME;
      }
      else if(motion_enabled==1) {
        //If button is pushed again, stop the motion immediately and lock it
        //for COOLDOWN_TIME ticks.
        motion_disable=true;
        motion_enable_timer=0;
        motion_disable_timer=MOTIONENABLELOGIC_COOLDOWN_TIME;
      }
    }
    else if(!input_mft->button_pressed || input_mft->button_panic) {
      //If button position was released or pushed to panic-state, cancel the start
      motion_enable_timer=0;
    }
    else if(motion_enable_timer>0) {
      motion_enable_timer=motion_enable_timer-1;
      if(motion_enable_timer<=0) {
        //If the timer was able to elapse, allow to enable the motion.
        motion_enable=true;
        motion_enable_timer=0;
      }
    }
  }
  //Superpose the additional enable and disable inputs
  if(last_additional_enable!=additional_enable && additional_enable) {
    motion_enable=true;
  }
  if(last_additional_disable!=additional_disable && additional_disable) {
    motion_disable=true;
  }
  //Act according to the requested state change. Disabling has priority over enabling.
  if(motion_disable) {
    robot->performSoftStop();
  }
  else if(motion_enable) {
    robot->enableMotion();
  }
  */

  last_button_pressed=input_mft->enable_button_pressed;
  last_button_panic=input_mft->enable_button_panic;
  last_additional_enable=additional_enable;
  last_additional_disable=additional_disable;
  last_motion_enabled=motion_enabled;
}
