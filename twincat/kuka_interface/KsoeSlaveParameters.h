#pragma once

#include "PDSParameters.h"

struct KsoeSlaveParameters {
  void *input_buffer;
  void *output_buffer;
  USHORT slave_address;
  USHORT connection_id;
  PDSParameters pds_parameters;
};
