#pragma once

struct FsoeSlaveParameters {
  void *input_buffer;
  void *output_buffer;
  USHORT slave_address;
  USHORT connection_id;
};
