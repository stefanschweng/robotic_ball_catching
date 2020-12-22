#pragma once

enum class FsoeState {
  NONE=0x00,
  RESET=0x2a,
  SESSION=0x4e,
  CONNECTION=0x64,
  PARAMETER=0x52,
  PROCESS_DATA=0x36
};

inline const char* toString(FsoeState state) {
  switch(state) {
    case FsoeState::NONE: return "NONE";
    case FsoeState::RESET: return "RESET";
    case FsoeState::SESSION: return "SESSION";
    case FsoeState::CONNECTION: return "CONNECTION";
    case FsoeState::PARAMETER: return "PARAMETER";
    case FsoeState::PROCESS_DATA: return "PROCESS_DATA";
    default: return "(unknown)";
  }
}
