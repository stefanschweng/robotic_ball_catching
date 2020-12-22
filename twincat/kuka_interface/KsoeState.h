#pragma once

enum class KsoeState {
  NONE=0x00,
  RESET=0x6a,
  SESSION=0x78,
  CONNECTION=0x64,
  PARAMETER=0x52,
  PROCESS_DATA=0x36
};

inline const char* toString(KsoeState state) {
  switch(state) {
    case KsoeState::NONE: return "NONE";
    case KsoeState::RESET: return "RESET";
    case KsoeState::SESSION: return "SESSION";
    case KsoeState::CONNECTION: return "CONNECTION";
    case KsoeState::PARAMETER: return "PARAMETER";
    case KsoeState::PROCESS_DATA: return "PROCESS_DATA";
    default: return "(unknown)";
  }
}
