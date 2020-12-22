#pragma once

enum class FsoeSlaveError {
  NONE=0,
  WRONG_CRC,
  WRONG_COMMAND,
  UNKNOWN_STATE,
  BUTTON_PRESSED,
  BUTTON_PANIC
};

inline const char* toString(FsoeSlaveError error) {
  switch(error) {
    case FsoeSlaveError::NONE: return "NONE";
    case FsoeSlaveError::WRONG_CRC: return "WRONG_CRC";
    case FsoeSlaveError::WRONG_COMMAND: return "WRONG_COMMAND";
    case FsoeSlaveError::UNKNOWN_STATE: return "UNKNOWN_STATE";
    case FsoeSlaveError::BUTTON_PRESSED: return "BUTTON_PRESSED";
    case FsoeSlaveError::BUTTON_PANIC: return "BUTTON_PANIC";
    default: return "(unknown)";
  }
}
