/*
NatNetTypes defines the public, common data structures and types
used when working with NatNetServer and NatNetClient objects.

version 3.0.0.0
*/

#pragma once

// model limits
#define MAX_MODELS                  200     // maximum number of MarkerSets 
#define MAX_RIGIDBODIES             1000    // maximum number of RigidBodies
#define MAX_NAMELENGTH              256     // maximum length for strings
#define MAX_MARKERS                 200     // maximum number of markers per MarkerSet
#define MAX_RBMARKERS               20      // maximum number of markers per RigidBody
#define MAX_SKELETONS               100     // maximum number of skeletons
#define MAX_SKELRIGIDBODIES         200     // maximum number of RididBodies per Skeleton
#define MAX_LABELED_MARKERS         1000    // maximum number of labeled markers per frame
#define MAX_UNLABELED_MARKERS       1000    // maximum number of unlabeled (other) markers per frame

#define MAX_FORCEPLATES             8       // maximum number of force plates
#define MAX_DEVICES                 32      // maximum number of peripheral devices
#define MAX_ANALOG_CHANNELS         32      // maximum number of data channels (signals) per analog/force plate device
#define MAX_ANALOG_SUBFRAMES        30      // maximum number of analog/force plate frames per mocap frame

#define MAX_PACKETSIZE              32  // max size of packet (actual packet size is dynamic). This limit is actually not used, it just defines the buffer size for Tx packets


// Client/server message ids
#define NAT_CONNECT                 0
#define NAT_SERVERINFO              1
#define NAT_REQUEST                 2
#define NAT_RESPONSE                3
#define NAT_REQUEST_MODELDEF        4
#define NAT_MODELDEF                5
#define NAT_REQUEST_FRAMEOFDATA     6
#define NAT_FRAMEOFDATA             7
#define NAT_MESSAGESTRING           8
#define NAT_DISCONNECT              9
#define NAT_KEEPALIVE               10
#define NAT_DISCONNECTBYTIMEOUT     11
#define NAT_ECHOREQUEST             12
#define NAT_ECHORESPONSE            13
#define NAT_DISCOVERY               14
#define NAT_UNRECOGNIZED_REQUEST    100


#define UNDEFINED                    999999.9999


// NatNet uses to set reporting level of messages.
// Clients use to set level of messages to receive.
typedef enum Verbosity
{
    Verbosity_None = 0,
    Verbosity_Debug,
    Verbosity_Info,
    Verbosity_Warning,
    Verbosity_Error,
} Verbosity;


// NatNet error reporting codes
typedef enum ErrorCode
{
    ErrorCode_OK = 0,
    ErrorCode_Internal,
    ErrorCode_External,
    ErrorCode_Network,
    ErrorCode_Other,
    ErrorCode_InvalidArgument,
    ErrorCode_InvalidOperation
} ErrorCode;


// NatNet connection types
typedef enum ConnectionType
{
    ConnectionType_Multicast = 0,
    ConnectionType_Unicast
} ConnectionType;


// NatNet data types
typedef enum DataDescriptors
{
    Descriptor_MarkerSet = 0,
    Descriptor_RigidBody,
    Descriptor_Skeleton,
    Descriptor_ForcePlate,
    Descriptor_Device
} DataDescriptors;


typedef float MarkerData[3];                // posX, posY, posZ


#pragma pack(push, 1)

// sender
typedef struct sSender
{
    char szName[MAX_NAMELENGTH];            // host app's name
    UINT8 Version[4];                     // host app's version [major.minor.build.revision]
    UINT8 NatNetVersion[4];               // host app's NatNet version [major.minor.build.revision]
} sSender;


typedef struct sSender_Server
{
    sSender Common;

    UINT64 HighResClockFrequency;         // host's high resolution clock frequency (ticks per second)
    UINT16 DataPort;
    bool IsMulticast;
    UINT8 MulticastGroupAddress[4];
} sSender_Server;


// packet
// note : only used by clients who are depacketizing NatNet packets directly
typedef struct sPacket
{
    UINT16 iMessage;                      // message ID (e.g. NAT_FRAMEOFDATA)
    UINT16 nDataBytes;                    // Num bytes in payload
    union
    {
        UINT8         cData[MAX_PACKETSIZE];
        char            szData[MAX_PACKETSIZE];
        UINT32        lData[MAX_PACKETSIZE/sizeof(UINT32)];
        float           fData[MAX_PACKETSIZE/sizeof(float)];
        sSender         Sender;
        sSender_Server  SenderServer;
    } Data;                                 // payload - statically allocated for convenience.  Actual packet size is determined by  nDataBytes
} sPacket;

#pragma pack(pop)


// Mocap server application description
typedef struct sServerDescription
{
    bool HostPresent;                       // host is present and accounted for
    char szHostComputerName[MAX_NAMELENGTH];// host computer name
    UINT8 HostComputerAddress[4];         // host IP address
    char szHostApp[MAX_NAMELENGTH];         // name of host app 
    UINT8 HostAppVersion[4];              // version of host app
    UINT8 NatNetVersion[4];               // host app's version of NatNet

    // Clock and connection info is only provided by NatNet 3.0+ servers.
    UINT64 HighResClockFrequency;         // host's high resolution clock frequency (ticks per second)

    bool bConnectionInfoValid;              // If the server predates NatNet 3.0, this will be false, and the other Connection* fields invalid.
    UINT16 ConnectionDataPort;            // The data port this server is configured to use.
    bool ConnectionMulticast;               // Whether this server is streaming in multicast. If false, connect in unicast instead.
    UINT8 ConnectionMulticastAddress[4];  // The multicast group address to use for a multicast connection.
} sServerDescription;


// Marker
#pragma pack(push,2)
typedef struct sMarker
{
    INT16 MarkerID;                             // Unique identifier:
                                            // For active markers, this is the Active ID. For passive markers, this is the PointCloud assigned ID.
                                            // For legacy assets that are created prior to 2.0, this is both AssetID (High-bit) and Member ID (Lo-bit)
    INT16 ModelID;

    float x;                                // x position
    float y;                                // y position
    float z;                                // z position
    float size;                             // marker size
    INT16 params;                         // host defined parameters
    float residual;                         // marker error residual, in mm/ray
} sMarker;
#pragma pack(pop)

// MarkerSet Definition
typedef struct sMarkerSetDescription
{
    char szName[MAX_NAMELENGTH];            // MarkerSet name
    INT32 nMarkers;                       // # of markers in MarkerSet
    char** szMarkerNames;                   // array of marker names
} sMarkerSetDescription;


// MarkerSet Data (single frame of one MarkerSet)
typedef struct sMarkerSetData
{
    char szName[MAX_NAMELENGTH];            // MarkerSet name
    INT32 nMarkers;                       // # of markers in MarkerSet
    MarkerData* Markers;                    // Array of marker data ( [nMarkers][3] )
} sMarkerSetData;


// Rigid Body Definition
typedef struct sRigidBodyDescription
{
    char szName[MAX_NAMELENGTH];            // RigidBody name
    INT32 ID;                             // RigidBody identifier: Streaming ID value for rigid body assets, and Bone index value for skeleton rigid bodies.
    INT32 parentID;                       // ID of parent Rigid Body (in case hierarchy exists; otherwise -1)
    float offsetx, offsety, offsetz;        // offset position relative to parent
    INT32 nMarkers;                       // Number of markers associated with this rigid body
    MarkerData* MarkerPositions;            // Array of marker locations ( [nMarkers][3] )
    INT32* MarkerRequiredLabels;          // Array of expected marker active labels - 0 if not specified. ( [nMarkers] )
} sRigidBodyDescription;


// Rigid Body Data (single frame of one rigid body)
#pragma pack(push,2)
typedef struct sRigidBodyData
{
    INT32 ID;                             // RigidBody identifier: 
                                            // For rigid body assets, this is the Streaming ID value. 
                                            // For skeleton assets, this combines both skeleton ID (High-bit) and Bone ID (Low-bit).

    float x, y, z;                          // Position
    float qx, qy, qz, qw;                   // Orientation
    float MeanError;                        // Mean measure-to-solve deviation
    INT16 params;                         // Host defined tracking flags

#if defined(__cplusplus)
    sRigidBodyData()
        : ID( 0 )
        , params( 0 )
    {
    }
#endif
} sRigidBodyData;
#pragma pack(pop)

// Skeleton Description
typedef struct sSkeletonDescription
{
    char szName[MAX_NAMELENGTH];                            // Skeleton name
    INT32 skeletonID;                                     // Skeleton unqiue identifier
    INT32 nRigidBodies;                                   // # of rigid bodies (bones) in skeleton
    sRigidBodyDescription RigidBodies[MAX_SKELRIGIDBODIES]; // array of rigid body (bone) descriptions 
} sSkeletonDescription;


// Skeleton Data
#pragma pack(push,2)
typedef struct sSkeletonData
{
    INT32 skeletonID;                                     // Skeleton unique identifier
    INT32 nRigidBodies;                                   // # of rigid bodies
    sRigidBodyData* RigidBodyData;                          // Array of RigidBody data
} sSkeletonData;
#pragma pack(pop)

// FrocePlate description
typedef struct sForcePlateDescription
{
    INT32 ID;                                     // used for order, and for identification in the data stream
    char strSerialNo[128];                          // for unique plate identification
    float fWidth;                                   // plate physical width (manufacturer supplied)
    float fLength;                                  // plate physical length (manufacturer supplied)
    float fOriginX, fOriginY, fOriginZ;             // electrical center offset (from electrical center to geometric center-top of force plate) (manufacturer supplied)
    float fCalMat[12][12];                          // force plate calibration matrix (for raw analog voltage channel type only)
    float fCorners[4][3];                           // plate corners, in world (aka Mocap System) coordinates, clockwise from plate +x,+y (refer to C3D spec for details)
    INT32 iPlateType;                             // force plate 'type' (refer to C3D spec for details) 
    INT32 iChannelDataType;                       // 0=Calibrated force data, 1=Raw analog voltages
    INT32 nChannels;                              // # of channels (signals)
    char szChannelNames[MAX_ANALOG_CHANNELS][MAX_NAMELENGTH];   // channel names
} sForcePlateDescription;

// Peripheral Device description (e.g. NIDAQ)
typedef struct sDeviceDescription
{
    INT32 ID;                                     // used for order, and for identification in the data stream
    char strName[128];                              // device name as appears in Motive
    char strSerialNo[128];                          // for unique device identification
    INT32 iDeviceType;                            // device 'type' code 
    INT32 iChannelDataType;                       // channel data type code
    INT32 nChannels;                              // # of currently enabled/active channels (signals)
    char szChannelNames[MAX_ANALOG_CHANNELS][MAX_NAMELENGTH];   // channel names
} sDeviceDescription;

// Tracked Object data description.  
// A Mocap Server application (e.g. Arena or TrackingTools) may contain multiple
// tracked "objects (e.g. RigidBody, MarkerSet).  Each object will have its
// own DataDescription.
typedef struct sDataDescription
{
    INT32 type;
    union
    {
        sMarkerSetDescription*  MarkerSetDescription;
        sRigidBodyDescription*  RigidBodyDescription;
        sSkeletonDescription*   SkeletonDescription;
        sForcePlateDescription* ForcePlateDescription;
        sDeviceDescription*     DeviceDescription;
    } Data;
} sDataDescription;


// All data descriptions for current session (as defined by host app)
typedef struct sDataDescriptions
{
    INT32 nDataDescriptions;
    sDataDescription arrDataDescriptions[MAX_MODELS];
} sDataDescriptions;

#pragma pack(push,2)
typedef struct sAnalogChannelData
{
    INT32 nFrames;                                // # of analog frames of data in this channel data packet (typically # of subframes per mocap frame)
    float Values[MAX_ANALOG_SUBFRAMES];             // values
} sAnalogChannelData;

typedef struct sForcePlateData
{
    INT32 ID;                                         // ForcePlate ID (from data description)
    INT32 nChannels;                                  // # of channels (signals) for this force plate
    sAnalogChannelData ChannelData[MAX_ANALOG_CHANNELS];// Channel (signal) data (e.g. Fx[], Fy[], Fz[])
    INT16 params;                                     // Host defined flags
} sForcePlateData;

typedef struct sDeviceData
{
    INT32 ID;                                         // Device ID (from data description)
    INT32 nChannels;                                  // # of active channels (signals) for this device
    sAnalogChannelData ChannelData[MAX_ANALOG_CHANNELS];// Channel (signal) data (e.g. ai0, ai1, ai2)
    INT16 params;                                     // Host defined flags
} sDeviceData;

// Single frame of data (for all tracked objects)
typedef struct sFrameOfMocapData
{
    INT32 iFrame;                                 // host defined frame number

    INT32 nMarkerSets;                            // # of marker sets in this frame of data
    sMarkerSetData MocapData[MAX_MODELS];           // MarkerSet data

    INT32 nOtherMarkers;                          // # of undefined markers
    MarkerData* OtherMarkers;                       // undefined marker data

    INT32 nRigidBodies;                           // # of rigid bodies
    sRigidBodyData RigidBodies[MAX_RIGIDBODIES];    // Rigid body data

    INT32 nSkeletons;                             // # of Skeletons
    sSkeletonData Skeletons[MAX_SKELETONS];         // Skeleton data

    INT32 nLabeledMarkers;                        // # of Labeled Markers
    sMarker LabeledMarkers[MAX_LABELED_MARKERS];    // Labeled Marker data (labeled markers not associated with a "MarkerSet")

    INT32 nForcePlates;                           // # of force plates
    sForcePlateData ForcePlates[MAX_FORCEPLATES];   // Force plate data

    INT32 nDevices;                               // # of devices
    sDeviceData Devices[MAX_DEVICES];               // Device data

    UINT32 Timecode;                              // SMPTE timecode (if available)
    UINT32 TimecodeSubframe;                      // timecode sub-frame data
    double fTimestamp;                              // timestamp since software start ( software timestamp )
    UINT64 CameraMidExposureTimestamp;            // Given in host's high resolution ticks (from e.g. QueryPerformanceCounter).
    UINT64 CameraDataReceivedTimestamp;           // Given in host's high resolution ticks (from e.g. QueryPerformanceCounter).
    UINT64 TransmitTimestamp;                     // Given in host's high resolution ticks (from e.g. QueryPerformanceCounter).
    INT16 params;                                 // host defined parameters
} sFrameOfMocapData;
#pragma pack(pop)

typedef struct sNatNetClientConnectParams
{
    ConnectionType connectionType;
    UINT16 serverCommandPort;
    UINT16 serverDataPort;
    const char* serverAddress;
    const char* localAddress;
    const char* multicastAddress;

#if defined(__cplusplus)
    sNatNetClientConnectParams()
        : connectionType( ConnectionType_Multicast )
        , serverCommandPort( 0 )
        , serverDataPort( 0 )
        , serverAddress( NULL )
        , localAddress( NULL )
        , multicastAddress( NULL )
    {
    }
#endif
} sNatNetClientConnectParams;
