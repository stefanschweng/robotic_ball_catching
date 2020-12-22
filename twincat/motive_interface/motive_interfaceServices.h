///////////////////////////////////////////////////////////////////////////////
// motive_interfaceServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_motive_interface = 0x3F000000;
#define SRVNAME_MOTIVE_INTERFACE "motive_interface"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_motive_interfaceCmotive_interface_module = {0x625c7edf,0xc996,0x4e32,{0xbc,0xf2,0x38,0x03,0x05,0x45,0xe4,0x7c}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_motive_interface_moduleMotiveAddress = 0x00000002;
const PTCID PID_motive_interface_moduleUdpProt = 0x00000001;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
#if !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)
#define _TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_
typedef ULONG ETYPE_VLAN_HEADER;
#endif // !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)

#if !defined(_TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_)
#define _TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_
typedef BYTE IPADDR[4];
#endif // !defined(_TC_TYPE_18071995_0000_0000_0000_00000000003E_INCLUDED_)

#if !defined(_TC_TYPE_FCFCDC6D_B77D_7912_7398_4BC5686850EF_INCLUDED_)
#define _TC_TYPE_FCFCDC6D_B77D_7912_7398_4BC5686850EF_INCLUDED_
typedef struct _RigidBody
{
	LONG ID;
	unsigned char reserved1[4];
	double x;
	double y;
	double z;
	double qx;
	double qy;
	double qz;
	double qw;
	double MeanError;
	double bTrackingValid;
} RigidBody, *PRigidBody;
#endif // !defined(_TC_TYPE_FCFCDC6D_B77D_7912_7398_4BC5686850EF_INCLUDED_)

#if !defined(_TC_TYPE_8FF1BB11_54EC_A46E_6B45_003256B9AD97_INCLUDED_)
#define _TC_TYPE_8FF1BB11_54EC_A46E_6B45_003256B9AD97_INCLUDED_
typedef struct _Marker
{
	SHORT MarkerID;
	SHORT ModelID;
	unsigned char reserved1[4];
	double x;
	double y;
	double z;
	double markerSize;
	double bOccluded;
	double bPCSolved;
	double bModelSolved;
	double residualError;
} Marker, *PMarker;
#endif // !defined(_TC_TYPE_8FF1BB11_54EC_A46E_6B45_003256B9AD97_INCLUDED_)

#pragma pack(push,1)
typedef struct _motive_interface_moduleOutput
{
	LONG FrameNumber;
	bool DataClock;
	double Timestamp;
	ULONGLONG CameraMidExposureTimestamp;
	LONG RigidBodyCount;
	RigidBody RigidBodyArray[5];
	LONG LabeledMarkerCount;
	Marker LabeledMarkerArray[20];
	LONG SingleMarkerCount;
	Marker SingleMarkerArray[20];
	double SingleMarkerMatrix[3][20];
} motive_interface_moduleOutput, *Pmotive_interface_moduleOutput;
#pragma pack(pop)

///</AutoGeneratedContent>



///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010095-0000-0000-e000-000000000064", ITcIoUdpProtocolRecv)
#endif // !defined(_TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_)

#if !defined(_TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010097-0000-0000-e000-000000000064", ITcIoUdpProtocol)
#endif // !defined(_TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_motive_interface_moduleOutput 1
///</AutoGeneratedContent>
