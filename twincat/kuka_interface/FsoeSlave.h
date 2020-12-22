#pragma once

#include "TcDef.h"
#include "TcInterfaces.h"
#include "kuka_interfaceServices.h"
#include "FsoeState.h"
#include "MFTSensor.h"
#include "FsoeSlaveError.h"
#include "LEDState.h"

#define FSOESLAVE_HANDLE_ERROR_FLAG(name,fsoe_slave_error,errorflag,acknowledgeflag) \
  if((errorflag) && !(acknowledgeflag)) { \
    trace->Log(tlError, "%2d FsoeSlave::updateIOs(): Motion prevented by \"" name "\".", connection_id); \
  } \
  else if(!(errorflag) && (acknowledgeflag)) { \
    trace->Log(tlError, "%2d FsoeSlave::updateIOs(): \"" name "\" cleared.", connection_id); \
  } \
  if((errorflag) && sensor_error==FsoeSlaveError::NONE) { \
    sensor_error=(fsoe_slave_error); \
  } \
  (acknowledgeflag)=(errorflag)

#define FSOESLAVE_SEQUENCE_NUMBER_INITIAL 1
#define FSOESLAVE_SESSION_ID 0x1234
#define FSOESLAVE_CYCLE_DIVIDER (8*4) //Ticks; Communication with MFT has to be processed at a lower rate, compared to PDS

class FsoeSlave {
  private:
    static USHORT crcTable1[256];
    static USHORT crcTable2[256];
    static USHORT parameter[27];

    MFT_FSoE_Inputs *input;
    MFT_FSoE_Outputs *output;
    unsigned char *NSR_INDICATOR;
    unsigned char *NSR_INPUT;
    CTcTrace *trace;
    USHORT connection_id;
    USHORT slave_address;
    int state_variable;
    USHORT sequence_number_master;
    USHORT sequence_number_slave;
    USHORT last_crc_slave;
    USHORT last_crc_master;
    FsoeState state;
    bool communication_toggle_bit;
    USHORT cycle_divider;
    MFTSensor sensor_buffer;
    FsoeSlaveError last_error;
    FsoeSlaveError sensor_error;

    void setState(FsoeState state);
    bool checkCrc();
    void statemachine();
    void updateIOs(MFTSensor *io);
    void generateCrc();
    void increaseSequenceNumber(USHORT *seqNo);
    bool doCrc(bool generate, FSoE_Packet *packet, USHORT receivedCrc, USHORT oldCrc, USHORT *seqNo);
    bool hasValidInput();
    void setLastError(FsoeSlaveError error);
    
  public:
    FsoeSlave(CTcTrace *trace, USHORT connection_id, USHORT slave_address, MFT_FSoE_Inputs *input_buffer, MFT_FSoE_Outputs *output_buffer, unsigned char *NSR_INDICATOR, unsigned char *NSR_INPUT);
    void ReadSensor(MFTSensor *io);
    FsoeSlaveError getLastError();
    FsoeSlaveError getSensorError();
    void reset();
    bool canEnableMotion();
    void setLEDState(LEDState led_state);
};
