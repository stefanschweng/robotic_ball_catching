#pragma once

enum class KsoeSlaveWarning {
  NONE=0,
  VELOCITY_LIMIT,
  MOTOR_TORQUE_LIMIT,
  SENSOR_TORQUE_LIMIT,
  POSITION_SOFT_LIMIT,
  INVALID_MOTOR_TORQUE
};

inline const char* toString(KsoeSlaveWarning error) {
  switch(error) {
    case KsoeSlaveWarning::NONE: return "NONE";
    case KsoeSlaveWarning::VELOCITY_LIMIT: return "VELOCITY_LIMIT";
    case KsoeSlaveWarning::MOTOR_TORQUE_LIMIT: return "MOTOR_TORQUE_LIMIT";
    case KsoeSlaveWarning::SENSOR_TORQUE_LIMIT: return "SENSOR_TORQUE_LIMIT";
    case KsoeSlaveWarning::POSITION_SOFT_LIMIT: return "POSITION_SOFT_LIMIT";
    case KsoeSlaveWarning::INVALID_MOTOR_TORQUE: return "INVALID_MOTOR_TORQUE";
    default: return "(unknown)";
  }
}
