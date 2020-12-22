///////////////////////////////////////////////////////////////////////////////
// FsoeSlave.cpp
#include "TcPch.h"
#pragma hdrstop

#include "FsoeSlave.h"

USHORT FsoeSlave::crcTable1[256]={
  0x0000, 0x39B7, 0x736E, 0x4AD9, 0xE6DC, 0xDF6B, 0x95B2, 0xAC05,
  0xF40F, 0xCDB8, 0x8761, 0xBED6, 0x12D3, 0x2B64, 0x61BD, 0x580A,
  0xD1A9, 0xE81E, 0xA2C7, 0x9B70, 0x3775, 0x0EC2, 0x441B, 0x7DAC,
  0x25A6, 0x1C11, 0x56C8, 0x6F7F, 0xC37A, 0xFACD, 0xB014, 0x89A3,
  0x9AE5, 0xA352, 0xE98B, 0xD03C, 0x7C39, 0x458E, 0x0F57, 0x36E0,
  0x6EEA, 0x575D, 0x1D84, 0x2433, 0x8836, 0xB181, 0xFB58, 0xC2EF,
  0x4B4C, 0x72FB, 0x3822, 0x0195, 0xAD90, 0x9427, 0xDEFE, 0xE749,
  0xBF43, 0x86F4, 0xCC2D, 0xF59A, 0x599F, 0x6028, 0x2AF1, 0x1346,
  0x0C7D, 0x35CA, 0x7F13, 0x46A4, 0xEAA1, 0xD316, 0x99CF, 0xA078,
  0xF872, 0xC1C5, 0x8B1C, 0xB2AB, 0x1EAE, 0x2719, 0x6DC0, 0x5477,
  0xDDD4, 0xE463, 0xAEBA, 0x970D, 0x3B08, 0x02BF, 0x4866, 0x71D1,
  0x29DB, 0x106C, 0x5AB5, 0x6302, 0xCF07, 0xF6B0, 0xBC69, 0x85DE,
  0x9698, 0xAF2F, 0xE5F6, 0xDC41, 0x7044, 0x49F3, 0x032A, 0x3A9D,
  0x6297, 0x5B20, 0x11F9, 0x284E, 0x844B, 0xBDFC, 0xF725, 0xCE92,
  0x4731, 0x7E86, 0x345F, 0x0DE8, 0xA1ED, 0x985A, 0xD283, 0xEB34,
  0xB33E, 0x8A89, 0xC050, 0xF9E7, 0x55E2, 0x6C55, 0x268C, 0x1F3B,
  0x18FA, 0x214D, 0x6B94, 0x5223, 0xFE26, 0xC791, 0x8D48, 0xB4FF,
  0xECF5, 0xD542, 0x9F9B, 0xA62C, 0x0A29, 0x339E, 0x7947, 0x40F0,
  0xC953, 0xF0E4, 0xBA3D, 0x838A, 0x2F8F, 0x1638, 0x5CE1, 0x6556,
  0x3D5C, 0x04EB, 0x4E32, 0x7785, 0xDB80, 0xE237, 0xA8EE, 0x9159,
  0x821F, 0xBBA8, 0xF171, 0xC8C6, 0x64C3, 0x5D74, 0x17AD, 0x2E1A,
  0x7610, 0x4FA7, 0x057E, 0x3CC9, 0x90CC, 0xA97B, 0xE3A2, 0xDA15,
  0x53B6, 0x6A01, 0x20D8, 0x196F, 0xB56A, 0x8CDD, 0xC604, 0xFFB3,
  0xA7B9, 0x9E0E, 0xD4D7, 0xED60, 0x4165, 0x78D2, 0x320B, 0x0BBC,
  0x1487, 0x2D30, 0x67E9, 0x5E5E, 0xF25B, 0xCBEC, 0x8135, 0xB882,
  0xE088, 0xD93F, 0x93E6, 0xAA51, 0x0654, 0x3FE3, 0x753A, 0x4C8D,
  0xC52E, 0xFC99, 0xB640, 0x8FF7, 0x23F2, 0x1A45, 0x509C, 0x692B,
  0x3121, 0x0896, 0x424F, 0x7BF8, 0xD7FD, 0xEE4A, 0xA493, 0x9D24,
  0x8E62, 0xB7D5, 0xFD0C, 0xC4BB, 0x68BE, 0x5109, 0x1BD0, 0x2267,
  0x7A6D, 0x43DA, 0x0903, 0x30B4, 0x9CB1, 0xA506, 0xEFDF, 0xD668,
  0x5FCB, 0x667C, 0x2CA5, 0x1512, 0xB917, 0x80A0, 0xCA79, 0xF3CE,
  0xABC4, 0x9273, 0xD8AA, 0xE11D, 0x4D18, 0x74AF, 0x3E76, 0x07C1
};

USHORT FsoeSlave::crcTable2[256]={
  0x0000, 0x7648, 0xEC90, 0x9AD8, 0xE097, 0x96DF, 0x0C07, 0x7A4F,
  0xF899, 0x8ED1, 0x1409, 0x6241, 0x180E, 0x6E46, 0xF49E, 0x82D6,
  0xC885, 0xBECD, 0x2415, 0x525D, 0x2812, 0x5E5A, 0xC482, 0xB2CA,
  0x301C, 0x4654, 0xDC8C, 0xAAC4, 0xD08B, 0xA6C3, 0x3C1B, 0x4A53,
  0xA8BD, 0xDEF5, 0x442D, 0x3265, 0x482A, 0x3E62, 0xA4BA, 0xD2F2,
  0x5024, 0x266C, 0xBCB4, 0xCAFC, 0xB0B3, 0xC6FB, 0x5C23, 0x2A6B,
  0x6038, 0x1670, 0x8CA8, 0xFAE0, 0x80AF, 0xF6E7, 0x6C3F, 0x1A77,
  0x98A1, 0xEEE9, 0x7431, 0x0279, 0x7836, 0x0E7E, 0x94A6, 0xE2EE,
  0x68CD, 0x1E85, 0x845D, 0xF215, 0x885A, 0xFE12, 0x64CA, 0x1282,
  0x9054, 0xE61C, 0x7CC4, 0x0A8C, 0x70C3, 0x068B, 0x9C53, 0xEA1B,
  0xA048, 0xD600, 0x4CD8, 0x3A90, 0x40DF, 0x3697, 0xAC4F, 0xDA07,
  0x58D1, 0x2E99, 0xB441, 0xC209, 0xB846, 0xCE0E, 0x54D6, 0x229E,
  0xC070, 0xB638, 0x2CE0, 0x5AA8, 0x20E7, 0x56AF, 0xCC77, 0xBA3F,
  0x38E9, 0x4EA1, 0xD479, 0xA231, 0xD87E, 0xAE36, 0x34EE, 0x42A6,
  0x08F5, 0x7EBD, 0xE465, 0x922D, 0xE862, 0x9E2A, 0x04F2, 0x72BA,
  0xF06C, 0x8624, 0x1CFC, 0x6AB4, 0x10FB, 0x66B3, 0xFC6B, 0x8A23,
  0xD19A, 0xA7D2, 0x3D0A, 0x4B42, 0x310D, 0x4745, 0xDD9D, 0xABD5,
  0x2903, 0x5F4B, 0xC593, 0xB3DB, 0xC994, 0xBFDC, 0x2504, 0x534C,
  0x191F, 0x6F57, 0xF58F, 0x83C7, 0xF988, 0x8FC0, 0x1518, 0x6350,
  0xE186, 0x97CE, 0x0D16, 0x7B5E, 0x0111, 0x7759, 0xED81, 0x9BC9,
  0x7927, 0x0F6F, 0x95B7, 0xE3FF, 0x99B0, 0xEFF8, 0x7520, 0x0368,
  0x81BE, 0xF7F6, 0x6D2E, 0x1B66, 0x6129, 0x1761, 0x8DB9, 0xFBF1,
  0xB1A2, 0xC7EA, 0x5D32, 0x2B7A, 0x5135, 0x277D, 0xBDA5, 0xCBED,
  0x493B, 0x3F73, 0xA5AB, 0xD3E3, 0xA9AC, 0xDFE4, 0x453C, 0x3374,
  0xB957, 0xCF1F, 0x55C7, 0x238F, 0x59C0, 0x2F88, 0xB550, 0xC318,
  0x41CE, 0x3786, 0xAD5E, 0xDB16, 0xA159, 0xD711, 0x4DC9, 0x3B81,
  0x71D2, 0x079A, 0x9D42, 0xEB0A, 0x9145, 0xE70D, 0x7DD5, 0x0B9D,
  0x894B, 0xFF03, 0x65DB, 0x1393, 0x69DC, 0x1F94, 0x854C, 0xF304,
  0x11EA, 0x67A2, 0xFD7A, 0x8B32, 0xF17D, 0x8735, 0x1DED, 0x6BA5,
  0xE973, 0x9F3B, 0x05E3, 0x73AB, 0x09E4, 0x7FAC, 0xE574, 0x933C,
  0xD96F, 0xAF27, 0x35FF, 0x43B7, 0x39F8, 0x4FB0, 0xD568, 0xA320,
  0x21F6, 0x57BE, 0xCD66, 0xBB2E, 0xC161, 0xB729, 0x2DF1, 0x5BB9,
};

USHORT FsoeSlave::parameter[27]={
  0x0002, 0x0036, 0x0030, 0x0003, 0x0003,
  0x0001, 0xffff, 0x03e8, 0x012c, 0x012c,
  0x0032, 0x0031, 0x00c8, 0x00c7, 0x00c8,
  0x00c7, 0x012c, 0x012c, 0x012b, 0x012c,
  0x012b, 0x0032, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000
};

#define CRC_UPDATE(crc,data) \
  { USHORT tmp=crcTable1[HIBYTE(crc)]^crcTable2[data]; \
  crc=(USHORT)(((HIBYTE(tmp)^LOBYTE(crc))<<8)|LOBYTE(tmp)); }

void FsoeSlave::increaseSequenceNumber(USHORT *seqNo) {
  *seqNo=(*seqNo)+1;
  if((*seqNo)==0) *seqNo=1;
}

bool FsoeSlave::doCrc(bool generate, FSoE_Packet *packet, USHORT receivedCrc, USHORT oldCrc, USHORT *seqNo) {
  USHORT crc, crc_tmp;
  USHORT indexCrc;

  do {
    crc=0;
    CRC_UPDATE(crc, LOBYTE(receivedCrc));
    CRC_UPDATE(crc, HIBYTE(receivedCrc));
    CRC_UPDATE(crc, LOBYTE(packet->CONNECTION_ID));
    CRC_UPDATE(crc, HIBYTE(packet->CONNECTION_ID));
    CRC_UPDATE(crc, LOBYTE(*seqNo));
    CRC_UPDATE(crc, HIBYTE(*seqNo));
    CRC_UPDATE(crc, packet->FSOE_CMD);
    crc_tmp=crc;
    CRC_UPDATE(crc, LOBYTE(packet->DATA0));
    CRC_UPDATE(crc, HIBYTE(packet->DATA0));
    if(crc==oldCrc) {
      increaseSequenceNumber(seqNo);
    }
  } while(crc==oldCrc);

  if(generate) {
    packet->CRC0=crc;
  }
  else {
    if(crc!=packet->CRC0) {
      return false;
    }
  }
  for(indexCrc=1;indexCrc<=4;indexCrc++) {
    crc=crc_tmp;
    CRC_UPDATE(crc, LOBYTE(indexCrc));
    CRC_UPDATE(crc, HIBYTE(indexCrc));
    CRC_UPDATE(crc, *(((unsigned char*)&packet->DATA0)+indexCrc*4));
    CRC_UPDATE(crc, *(((unsigned char*)&packet->DATA0)+indexCrc*4+1));
    if(generate) {
      (&packet->CRC0)[indexCrc*2]=crc;
    }
    else {
      if(crc!=(&packet->CRC0)[indexCrc*2]) {
        return false;
      }
    }
  }
  return true;
}

FsoeSlave::FsoeSlave(CTcTrace *trace, USHORT connection_id, USHORT slave_address, MFT_FSoE_Inputs *input_buffer, MFT_FSoE_Outputs *output_buffer, unsigned char *NSR_INDICATOR, unsigned char *NSR_INPUT) {
  this->trace=trace;
  this->connection_id=connection_id;
  this->slave_address=slave_address;
  this->input=input_buffer;
  this->output=output_buffer;
  this->NSR_INDICATOR=NSR_INDICATOR;
  this->NSR_INPUT=NSR_INPUT;
  reset();
}

void FsoeSlave::reset() {
  trace->Log(tlVerbose, "%2d FsoeSlave::reset()", connection_id);
  memset((void*)output, 0, sizeof(MFT_FSoE_Outputs));
  output->FSOE_CMD=(unsigned char)FsoeState::RESET;
  state=FsoeState::RESET;
  sequence_number_master=FSOESLAVE_SEQUENCE_NUMBER_INITIAL;
  sequence_number_slave=FSOESLAVE_SEQUENCE_NUMBER_INITIAL;
  communication_toggle_bit=true;
  last_crc_slave=0;
  last_crc_master=0;
  state_variable=0;
  cycle_divider=0;
  sensor_buffer.enable_button_panic=false;
  sensor_buffer.enable_button_pressed=false;
  sensor_buffer.application_button_pressed=false;
  last_error=FsoeSlaveError::NONE;
  sensor_error=FsoeSlaveError::NONE;
}

void FsoeSlave::setState(FsoeState s) {
  trace->Log(tlInfo, "%2d FsoeSlave::setState(): %s (0x%02x) -> %s (0x%02x)", connection_id, toString(state), state, toString(s), s);
  this->state=s;
}

bool FsoeSlave::checkCrc() {
  return doCrc(false, (FSoE_Packet*)input, last_crc_master, last_crc_slave, &sequence_number_slave);
}

void FsoeSlave::statemachine() {
  FSoE_Packet* output_packet=(FSoE_Packet*)output;
  FSoE_Packet* input_packet=(FSoE_Packet*)input;
  int pos;

  if(input->FSOE_CMD!=output->FSOE_CMD) {
    trace->Log(tlError, "%2d FsoeSlave::statemachine(): Slave responded with wrong command 0x%02x or didn't update its response.", connection_id, input->FSOE_CMD);
    setLastError(FsoeSlaveError::WRONG_COMMAND);
  }
  else {
    switch(state) {
      case FsoeState::RESET:
        //Assumes, that the function reset() was called to arrive in this state. Therefore,
        //all outputs are reset to zero already.
        //Slave is in RESET-State: Go to SESSION-State.
        output->FSOE_CMD=(unsigned char)FsoeState::SESSION;
        output_packet->DATA0=FSOESLAVE_SESSION_ID;
        setState(FsoeState::SESSION);
        break;

      case FsoeState::SESSION:
        output_packet->FSOE_CMD=(unsigned char)FsoeState::CONNECTION;
        output_packet->DATA0=(USHORT)connection_id;
        output_packet->DATA1=(USHORT)slave_address;
        output_packet->CONNECTION_ID=(USHORT)connection_id;
        setState(FsoeState::CONNECTION);
        increaseSequenceNumber(&sequence_number_master);
        increaseSequenceNumber(&sequence_number_slave);
        break;

      case FsoeState::CONNECTION:
        //Directly go to the PARAMETER state and start sending parameters
        state_variable=0;
        setState(FsoeState::PARAMETER);
        //fall through
      case FsoeState::PARAMETER:
        output_packet->FSOE_CMD=(unsigned char)FsoeState::PARAMETER;
        pos=state_variable*5;
        for(int i=0;i<5;i++) {
          if((pos+i)<sizeof(parameter)/sizeof(USHORT)) {
            //Every second word is a data word
            (&output_packet->DATA0)[i*2]=parameter[pos+i];
          }
          else {
            (&output_packet->DATA0)[i*2]=0;
          }
        }
        pos+=5;
        if(pos>=sizeof(parameter)/sizeof(USHORT)) {
          setState(FsoeState::PROCESS_DATA);
        }
        else {
          state_variable++;
        }
        increaseSequenceNumber(&sequence_number_master);
        increaseSequenceNumber(&sequence_number_slave);
        break;

      case FsoeState::PROCESS_DATA:
        output->FSOE_CMD=(unsigned char)FsoeState::PROCESS_DATA;
        increaseSequenceNumber(&sequence_number_master);
        increaseSequenceNumber(&sequence_number_slave);
        break;

      default:
        trace->Log(tlError, "%2d FsoeSlave::statemachine(): Unknown State 0x%02x.", connection_id, state);
        setLastError(FsoeSlaveError::UNKNOWN_STATE);
        break;
    }
  }
}

void FsoeSlave::updateIOs(MFTSensor *io) {
  if(state==FsoeState::PROCESS_DATA) {
    //Check sensor error states
    sensor_error=FsoeSlaveError::NONE;
    FSOESLAVE_HANDLE_ERROR_FLAG("Button pressed", FsoeSlaveError::BUTTON_PRESSED,
      input->SIND_ERR_3, output->SIND_ERR_ACK_3);
    FSOESLAVE_HANDLE_ERROR_FLAG("Button panic", FsoeSlaveError::BUTTON_PRESSED,
      input->SIND_ERR_2, output->SIND_ERR_ACK_2);

    io->enable_button_pressed=input->SIND_INPUT_3;
    io->enable_button_panic=!input->SIND_INPUT_2;
    //Read bit NSR_APPSWITCH
    io->application_button_pressed=((*NSR_INPUT)&0x20)!=0;
  }
  else {
    io->enable_button_panic=false;
    io->enable_button_pressed=false;
    io->application_button_pressed=false;
  }
  sensor_buffer.enable_button_panic=io->enable_button_panic;
  sensor_buffer.enable_button_pressed=io->enable_button_pressed;
  sensor_buffer.application_button_pressed=io->application_button_pressed;
}

void FsoeSlave::generateCrc() {
  if(state!=FsoeState::RESET && state!=FsoeState::SESSION) {
    last_crc_slave=input->CRC0;
  }
  doCrc(true, (FSoE_Packet*)output, last_crc_slave, output->CRC0, &sequence_number_master);
  if(state!=FsoeState::RESET) {
    last_crc_master=output->CRC0;
  }
}

bool FsoeSlave::hasValidInput() {
  return input->FSOE_CMD!=(unsigned char)FsoeState::NONE;
}

void FsoeSlave::ReadSensor(MFTSensor *io) {
  if(!hasValidInput()) {
    io->enable_button_panic=false;
    io->enable_button_pressed=false;
    io->application_button_pressed=false;
    sensor_buffer.enable_button_panic=false;
    sensor_buffer.enable_button_pressed=false;
    sensor_buffer.application_button_pressed=false;
  }
  else {
    //By default, use the values from the buffer, until the next communication cycle occours.
    io->enable_button_panic=sensor_buffer.enable_button_panic;
    io->enable_button_pressed=sensor_buffer.enable_button_pressed;
    io->application_button_pressed=sensor_buffer.application_button_pressed;

    cycle_divider++;
    if(cycle_divider>=FSOESLAVE_CYCLE_DIVIDER) {
      cycle_divider=0;
      //Due to the structure of EtherCAT communication, the slave can only answer after the
      //second time a packet arrives. This is due to the fact, that the EtherCAT frame only
      //passes through the slave, allowing only to copy data from/to the frame. There is
      //no processing time availible. Therefore, the master sends its frame again after
      //one cycle and the slave then puts its updated response into the frame.
      //Therefore, the first answer from the slave must be ignored, since it does not
      //contain a response yet. The "communication_toggle_bit" is responsible for this.
      communication_toggle_bit=!communication_toggle_bit;
      if(!communication_toggle_bit) return;

      //trace->Log(tlVerbose, "%2d FsoeSlave::CycleUpdate(): M <- S, %02x %04x %04x, %04x, %04x", connection_id,
      //  input->FSOE_CMD, ((FSoE_Packet*)input)->DATA0, ((FSoE_Packet*)input)->CRC0, sequence_number_slave, last_crc_master);

      if(checkCrc()) {
        statemachine();
        updateIOs(io);
      }
      else {
        trace->Log(tlError, "%2d FsoeSlave::CycleUpdate(): Wrong CRC (sequence_number_master=0x%04x, sequence_number_slave=0x%04x).",
          connection_id, sequence_number_master, sequence_number_slave);
        setLastError(FsoeSlaveError::WRONG_CRC);
      }
      generateCrc();

      //trace->Log(tlVerbose, "%2d FsoeSlave::CycleUpdate(): M -> S, %02x %04x %04x, %04x, %04x", connection_id,
      //  output->FSOE_CMD, ((FSoE_Packet*)output)->DATA0, ((FSoE_Packet*)output)->CRC0, sequence_number_master, last_crc_slave);
    }
  }
}

FsoeSlaveError FsoeSlave::getLastError() {
  return last_error;
}

FsoeSlaveError FsoeSlave::getSensorError() {
  return sensor_error;
}

void FsoeSlave::setLastError(FsoeSlaveError error) {
  //If there was an error, immediately proceed to the reset state. This clears the
  //output buffer and issues the reset command to the slave.
  trace->Log(tlInfo, "%2d FsoeSlave::setLastError(): %s (%d) -> %s (%d)", connection_id, toString(last_error), (int)last_error, toString(error), (int)error);
  if(error!=FsoeSlaveError::NONE) {
    reset();
  }
  last_error=error;
}

bool FsoeSlave::canEnableMotion() {
  bool enable=true;
  if(last_error!=FsoeSlaveError::NONE) {
    trace->Log(tlError, "%2d FsoeSlave::canEnableMotion(): Cannot enable motion due to last error %s (%d)", connection_id, toString(last_error), (int)last_error);
    enable=false;
  }
  else if(sensor_error!=FsoeSlaveError::NONE) {
    trace->Log(tlError, "%2d FsoeSlave::canEnableMotion(): Cannot enable motion due to sensor error %s (%d)", connection_id, toString(sensor_error), (int)sensor_error);
    enable=false;
  }
  else if(state!=FsoeState::PROCESS_DATA) {
    trace->Log(tlError, "%2d FsoeSlave::canEnableMotion(): Cannot enable motion due to slave state %s (%d)", connection_id, toString(state), (int)state);
    enable=false;
  }
  return enable;
}

void FsoeSlave::setLEDState(LEDState led_state) {
  if(NSR_INDICATOR!=NULL) {
    *NSR_INDICATOR=(unsigned char)led_state;
  }
}
