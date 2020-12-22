#pragma once

#include"KsoeSlaveParameters.h"
#include"FsoeSlaveParameters.h"
#include"Robot.h"

struct RobotParameters {
  const char *name;
  AmsNetId netid;
  KsoeSlaveParameters ksoe_slave_parameters[ROBOT_NUM_SLAVE];
  FsoeSlaveParameters fsoe_slave_parameters;
  unsigned char *NSR_INDICATOR;
  unsigned char *NSR_INPUT;
  Axis axis[ROBOT_NUM_AXIS];
};
