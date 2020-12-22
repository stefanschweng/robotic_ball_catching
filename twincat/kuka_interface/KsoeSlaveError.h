#pragma once

enum class KsoeSlaveError {
  NONE=0,
  WRONG_CRC,
  WRONG_COMMAND,
  WRONG_VMT_RESPONSE,
  UNKNOWN_STATE,
  MOTION_WATCHDOG,
  INVALID_TEMPERATURE,
  SLAVE_RESET,
  MOTOR_SAFE_TORQUE_OFF_INTERN,
  STATIC_SAFE_TORQUE_OFF,
  SAFE_OS_RUNTIME,
  POSITION_LIMIT_HARD,
  MOTOR_WARNING_LOW_VOLTAGE,
  HS_SBC,
  SBC
};

inline const char* toString(KsoeSlaveError error) {
  switch(error) {
    case KsoeSlaveError::NONE: return "NONE";
    case KsoeSlaveError::WRONG_CRC: return "WRONG_CRC";
    case KsoeSlaveError::WRONG_COMMAND: return "WRONG_COMMAND";
    case KsoeSlaveError::WRONG_VMT_RESPONSE: return "WRONG_VMT_RESPONSE";
    case KsoeSlaveError::UNKNOWN_STATE: return "UNKNOWN_STATE";
    case KsoeSlaveError::MOTION_WATCHDOG: return "MOTION_WATCHDOG";
    case KsoeSlaveError::INVALID_TEMPERATURE: return "INVALID_TEMPERATURE";
    case KsoeSlaveError::SLAVE_RESET: return "SLAVE_RESET";
    case KsoeSlaveError::MOTOR_SAFE_TORQUE_OFF_INTERN: return "MOTOR_SAFE_TORQUE_OFF_INTERN";
    case KsoeSlaveError::STATIC_SAFE_TORQUE_OFF: return "STATIC_SAFE_TORQUE_OFF";
    case KsoeSlaveError::SAFE_OS_RUNTIME: return "SAFE_OS_RUNTIME";
    case KsoeSlaveError::POSITION_LIMIT_HARD: return "POSITION_LIMIT_HARD";
    case KsoeSlaveError::MOTOR_WARNING_LOW_VOLTAGE: return "MOTOR_WARNING_LOW_VOLTAGE";
    case KsoeSlaveError::HS_SBC: return "HS_SBC";
    case KsoeSlaveError::SBC: return "SBC";
    default: return "(unknown)";
  }
}
