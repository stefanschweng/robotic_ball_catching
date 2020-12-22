#pragma once

enum class MotionState {
  STOP=0,
  MOTION_ENABLE=1,
  MOTOR_CONTROL_1=2,
  MOTOR_CONTROL_2=3,
  MOTOR_CONTROL_3=4,
  ENGAGING_MOTION=5,
  MOTION=0x10+0,
  DISENGAGING_MOTION=0x10+1,
  MOTOR_CONTROL_3_STOPPING=0x10+2,
  MOTOR_CONTROL_2_STOPPING=0x10+3,
  MOTOR_CONTROL_1_STOPPING=0x10+4,
  MOTION_DISABLE=0x10+5,
};

inline const char* toString(MotionState state) {
  switch(state) {
    case MotionState::STOP: return "STOP";
    case MotionState::MOTION_ENABLE: return "MOTION_ENABLE";
    case MotionState::MOTOR_CONTROL_1: return "MOTOR_CONTROL_1";
    case MotionState::MOTOR_CONTROL_2: return "MOTOR_CONTROL_2";
    case MotionState::MOTOR_CONTROL_3: return "MOTOR_CONTROL_3";
    case MotionState::ENGAGING_MOTION: return "ENGAGING_MOTION";
    case MotionState::MOTION: return "MOTION";
    case MotionState::DISENGAGING_MOTION: return "DISENGAGING_MOTION";
    case MotionState::MOTOR_CONTROL_3_STOPPING: return "MOTOR_CONTROL_3_STOPPING";
    case MotionState::MOTOR_CONTROL_2_STOPPING: return "MOTOR_CONTROL_2_STOPPING";
    case MotionState::MOTOR_CONTROL_1_STOPPING: return "MOTOR_CONTROL_1_STOPPING";
    case MotionState::MOTION_DISABLE: return "MOTION_DISABLE";
    default: return "(unknown)";
  }
}
