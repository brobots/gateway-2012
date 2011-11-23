#if !defined(__ZigBeeNtwk__H_)
#define __ZigBeeNtwk__H_

#include <RobotFirmware/Includes/MainIncludes.h>
#include <RobotFirmware/Includes/pPgmByteDeclare.h>
#include <RobotFirmware/Includes/ZigBeeSerialDriver.h>

#include "stddef.h"

#ifdef __cplusplus
extern "C"
{
#endif


#if defined(bHasMultRobotNetworking) || defined(_WINDOWS)

#if !defined(bytesDeclared)
	#define bytesDeclared
	#define byteDeclareRequired
	typedef unsigned char	 ubyte;
	typedef   signed char  sbyte;
	typedef unsigned short uword;
	typedef   signed short sword;
#endif

//
// Functions to control the ZigBee Driver
//
extern void startZigBeeDriver(void);
extern void startZigBeeDriverWithChannel(ubyte nUartIndex, ubyte nChannel);
extern void stopZigBeeDriver(void);
extern void zigBeeOneMillisecondTick(void);

//
typedef ubyte TZigBeeSerialNumber[8];
typedef ubyte TZigBeeShortSerialNumber[2];


typedef unsigned char tChannelNumber;
typedef unsigned short tNetworkNumber;


typedef enum TZBCommandStatus   // Aligns with different enum in "RobotCIntrinsics.c". Keep these synchronized!!
{
	zbStatusSuccess							= 0,
	zbStatusWaitingForCommand		= 1,
	zbStatusCommandFailed				= 2,
} TZBCommandStatus;


extern TZBCommandStatus getNtwkingCommandStatus(void);
extern bool getNtwkingStartupFinished(void);
extern bool bZBStateMachineIdle(void);

extern bool bZBOutputBufferAvailable(void);
extern void sendNextBufferedZBMessage(void);
extern TZBCommandStatus sendZB_BufferedMessage(ubyte nToNodeIndex, const ubyte *pMessage, ubyte nMessageLength);
extern TZBCommandStatus sendZB_Message(ubyte nToNodeIndex, const ubyte *pMessage, ubyte nMessageLength);

extern uword GetReceiveMsgSizeFromQueuedMessages(void);
extern TZBCommandStatus getMultiRobotMsgFromQueuedMessages(uword *pFromNode, ubyte *pData, ubyte nBufferSize, ubyte *pActualBytes);

extern void addNodeToListInRobot(ubyte nNodeIndex, const TZigBeeSerialNumber *pSerialNumber);

extern void configureNetwork(uword nPanID, ubyte nChannel, ubyte nMyNodeIndex, ubyte nNumbOfNodes, TIntFlashPtr pNodeList);
extern void initializeZigBeeNodeTable(void);

extern void initializeZigBeeNodeTable(void);


enum
{
	kZigBeeDefaultNetworkID							= 0x3332,				// Default value after f/w download
	kZigBeeBroadcastPanID								= 0xFFFF,

	kBroadcastNodeIndex									= (ubyte) 0xFE, // Special Node index indicating broadcast command is being used

	kZigBeeDefaultChannelNumber					= 12,						// Valid channel range 12 - 26.

	kZigBeeDefaultSearchTimeInSeconds		= 2,
	kZigBeeDelayWhenSwitchingChannels		= 25,

	kZigBeeNoisyThreshold								= 60,						// Upper limit of Signal strength for "noisy" ZigBee "Energy Scan" results
	kZigBeeQuietThreshold								= 80,						// Lower limit of Signal strength for "quiet" ZigBee "Energy Scan" results
};

extern void setAckOnOff(bool bOn);
extern bool getAckOnOff(void);

//
// Functions to Send "Commands" ("Packets") via ZigBee API
//
extern ubyte zbGetMyNodeIndex(void);
extern bool bSameSerialNumber(const TZigBeeSerialNumber *pSerialNumber1, const TZigBeeSerialNumber *pSerialNumber2);


#if defined(_WINDOWS)

	#undef CLASS_DECLSPEC_ZBSerialPorts
	#ifdef _EXPORTING_ZBSerialPorts
		#define CLASS_DECLSPEC_ZBSerialPorts    __declspec(dllexport)
	#else
		#define CLASS_DECLSPEC_ZBSerialPorts    __declspec(dllimport)
	#endif

	extern CLASS_DECLSPEC_ZBSerialPorts int nCurrZigBeeComPort;
	extern CLASS_DECLSPEC_ZBSerialPorts void setCurrZBPort(int nIndex);

	#define kNumbOfZigBeePorts 3

	#if !defined(Simulator)
		extern void startFastZigBeeMessaging(void);
		extern void stopZigBeeFastMessaging(void);
	#endif

#else

	#define nCurrZigBeeComPort 0
	#define setCurrZBPort(nIndex)
  #define kNumbOfZigBeePorts 1

#endif

enum
{
	kZigBeePacketHeaderByte				= 0x7E,
};

typedef enum TXbeeAPIRcvMessageTypes
{
	// Rcv Commands from 802.15.4 module

	zbAPICmds_RcvPacket64Bits									= 0x80,
	zbAPICmds_RcvPacket16Bits									= 0x81,
	zbAPICmds_RcvSensorData64Bits							= 0x82,
	zbAPICmds_RcvSensorData16Bits							= 0x83,
	zbAPICmds_ATCommandResponse								= 0x88,
	zbAPICmds_XmitRequestResponse							= 0x89,
	zbAPICmds_RcvModemStatus									= 0x8A,
	zbAPIcmds_RemoteAtCommandResponse					= 0x97,
} TXbeeAPIRcvMessageTypes;

typedef enum TXbeeAPIXmitMessageTypes
{
	// Xmit Commands to XBee 802.15.4 module
	
	zbAPICmds_XmitRequest64Bits				= 0x00,
	zbAPICmds_XmitRequest16Bits				= 0x01,	

	zbAPICmds_ATCommand								= 0x08,	
	zbAPIcmds_QueueParameter					= 0x09,
	zbAPIcmds_RemoteAtCommand					= 0x17,	
} TXbeeAPIXmitMessageTypes;

typedef enum TZigBeeXmitStatus
{
	zbXmitStatusSuccess								= 0,
	zbXmitStatusNoACK									= 1, // All retries attempted and no ACK received.
	zbXmitStatusCCAFailure						= 2,
	zbXmitStatusPurged								= 3,
} TZigBeeXmitStatus;

typedef enum TZigBeeModemStatusType
{
	zbModemStatusHWReset										= 0,
	zbModemStatusWatchdogReset							= 1,
	zbModemStatusAssociated									= 2,
	zbModemStatusDisassociated							= 3,
	zbModemStatusSyncLost										= 4,
	zbModemStatusCoordinatorRealignment			= 5,
	zbModemStatusCoordinatorStarted					= 6,
} TZigBeeModemStatusType;

typedef enum TXBeeATErrorCodes
{
	zbATStatusSuccess												= 0,
	zbATStatusError													= 1,
	zbATStatusInvalidCommand								= 2,
	zbATStatusInvalidParameter							= 3,
	zbATStatusNoResponse										= 4,   // Applies to remote AT commands
	zbATStatusUndocumented									= 5,   // Applies to remote AT commands
} TXBeeATErrorCodes;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//														 AT COmmands Known/Used by ROBOTC Driver
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#define convertCommandToShort(firstByte, secondByte) ((((uword) (firstByte)) << 8) | ((ubyte) (secondByte)))

typedef enum TATCommands
{
	ATNodeDiscovery						= convertCommandToShort('N', 'D'),
	ATNodeDiscoveryTime				= convertCommandToShort('N', 'T'),
	ATNodeDiscoverOptions     = convertCommandToShort('N', 'O'),
	ATNodeIdentifier					= convertCommandToShort('N', 'I'),

	ATNodeSerialNumberHigh		= convertCommandToShort('S', 'H'),
	ATNodeSerialNumberLow			= convertCommandToShort('S', 'L'),
	ATDestinationLow					= convertCommandToShort('D', 'L'),
	ATDestinationHigh					= convertCommandToShort('D', 'H'),
	ATMacMode									= convertCommandToShort('M', 'M'),

	ATBaudRate								= convertCommandToShort('B', 'D'),
	ATParity									= convertCommandToShort('N', 'B'),

	ATApiEnabled							= convertCommandToShort('A', 'P'),

	ATAssociateEndDevice			= convertCommandToShort('A', '1'),
	ATCoordinatorEnable				= convertCommandToShort('C', 'E'),
	ATRandomDelay							= convertCommandToShort('R', 'N'),

	ATEnergyScan							= convertCommandToShort('E', 'D'),
	ATScanChannels						= convertCommandToShort('S', 'C'),

	ATErrorACK_Counts					= convertCommandToShort('E', 'A'),
	ATErrorCCA_Counts					= convertCommandToShort('E', 'C'),
	ATCCA_Threshold						= convertCommandToShort('C', 'A'),    // Do not transmit if CCA engergy assessment exceeds this threshold

	ATRSSI_Timer							= convertCommandToShort('R', 'P'),		// Duration in 100-msec that Rcv indicator LED remains on after receiving a packet
	ATPowerLevel							= convertCommandToShort('P', 'L'),
	ATXBeeRetries							= convertCommandToShort('R', 'R'),
	
	ATForceSoftwareReset			= convertCommandToShort('F', 'R'),
	ATRestoreDefaults					= convertCommandToShort('R', 'E'),
	ATApplyChanges						= convertCommandToShort('A', 'C'),		// Takes immediate effect
	ATWriteChanges						= convertCommandToShort('W', 'R'),		// Takes effect on reboot. Use sparingly to prevent EEPROM wearout.
	
	ATForceSample							= convertCommandToShort('I', 'S'),		//	Forces a read of all enabled DIO/ADC lines.
	ATIO_OutputEnabled				= convertCommandToShort('I', 'U'),		//	Enables / disables output of I/O sample packets
	ATIO_SamplesCount					= convertCommandToShort('I', 'T'),		//	(R/W) Number of DIO/ADC samples to collect before transmitting data.
	ATIO_DIOChangeDetect			= convertCommandToShort('I', 'C'),		//	(R/W) Bit map of which DIO fields to monitor for changes.
	ATIO_OutputLevels					= convertCommandToShort('I', 'O'),		//	(W/O) Bit map of which DIO output fields are set
	ATIO_SampleRate						= convertCommandToShort('I', 'R'),		//	(R/W) Sample rate for DIO/ADC pins.
	ATIO_PullUpResistor				= convertCommandToShort('P', 'R'),		//	(R/W) Bit map of enabled / disabled pullup resistors on DIO lines.
	ATIO_InputAddress					= convertCommandToShort('I', 'A'),		//	(W/O) Binds module to a special I/O address for accepting "I/O" commands
	
	ATIO_PWMConfiguration_0		= convertCommandToShort('P', '0'),		//	(R/W) PWM 0 Configuration
	ATIO_PWMConfiguration_1		= convertCommandToShort('P', '1'),		//	(R/W) PWM 1 Configuration
	ATIO_PWMOutputLevel_0			= convertCommandToShort('M', '0'),		//	(R/W) PWM 0 Output Level
	ATIO_PWMOutputLevel_1			= convertCommandToShort('M', '1'),		//	(R/W) PWM 1 Output Level

	ATPanID										= convertCommandToShort('I', 'D'),
	ATChannel									= convertCommandToShort('C', 'H'),
	ATPacketizationTimeout		= convertCommandToShort('R', 'O'),
	AT16BitSourceAddress			= convertCommandToShort('M', 'Y'),
	ATReceivedSignalStrength	= convertCommandToShort('D', 'B'),

	ATHardwareVersion					= convertCommandToShort('H', 'V'),
	ATSoftwareVersion					= convertCommandToShort('V', 'R'),

	ATMessageDummy						= convertCommandToShort('0', '0'),    // Dummy field for non-command messages
} TATCommands;

extern ubyte zbGetNextFrameIndex(void);
extern void sendZB_ATCmd_BasicMessage(TATCommands nCommand);
extern void sendATCommandWithOneByteParm(TATCommands nCommand, ubyte nParm, bool bQueuedChange);
extern void sendATCommandWithOneWordParm(TATCommands nCommand, uword nParm, bool bQueuedChange);
extern void sendATCommandWithFourByteParm(TATCommands nCommand, unsigned long nParm, bool bQueuedChange);
extern void sendATCommandWithVariableLengthParm(TATCommands nCommand, ubyte *pData, ubyte nLength, bool bQueuedChange);

extern void sendZB_RemoteATCmd_BasicMessage(ubyte nNodeIndex,			TATCommands nCommand);
extern void sendZB_RemoteATCmd_WithOneByteParm(ubyte nNodeIndex,  TATCommands nCommand, ubyte nParm, bool bQueuedChange);
extern void sendZB_RemoteATCmd_WithOneWordParm(ubyte nNodeIndex,	TATCommands nCommand, uword nParm, bool bQueuedChange);
extern void sendZB_RemoteATCmd_WithFourByteParm(ubyte nNodeIndex,	TATCommands nCommand, unsigned long nParm, bool bQueuedChange);
extern void sendZB_RemoteATCommandWithVariableLengthParm(ubyte nNodeIndex, TATCommands nCommand, ubyte *pData, ubyte nLength, bool bQueuedChange);

extern void zigBeeReceivePacketStateMachineModeAPI(void);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																			 Receive API Packet Formats
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TZBRcvState
{
	zbRcvStateStartOfPacket,
	zbRcvStatePacketLengthHighByte,
	zbRcvStatePacketLengthLowByte,
	zbRcvStatePacketData,
	sbRcvStateWaitForFirstChar,					// StateUsed in PC diagnostics only
} TZBRcvState;

typedef struct TResponseHeader
{
	ubyte					nDelimiter;			// 0x7E
	ubyte					nLengthHigh;
	ubyte					nLengthLow;
	ubyte					nReplyType;			// TXbeeAPIRcvMessageTypes butdeclare as 'ubyte' for packing/byte alignment considerations
	ubyte					nFrameID;
} TResponseHeader;

typedef struct TATCommand
{
	ubyte			nFirstByte;
	ubyte			nSecondByte;
} TATCommand;

typedef ubyte TReplyStatus;
typedef ubyte TShortAddress[2];


typedef struct TATReply
{
	TATCommand					nCommand;
	TReplyStatus				nStatus;
	// variable length command reply data follows here
} TATReply;

typedef struct TATReplyWithHeader
{
	TResponseHeader			nHeader;
	TATReply						nATReply;
} TATReplyWithHeader;

typedef struct TRemoteATReplyWithHeader
{
	TResponseHeader						nHeader;
	TZigBeeSerialNumber				nSerialNumber;
	TZigBeeShortSerialNumber	nShortSerialNumber;
	TATReply									nATReply;
} TRemoteATReplyWithHeader;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				ZigBee Received API Packet Types
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TTransmitStatusReply
{
	ubyte								nFrameID;
	ubyte								nXmitStatus;			// TZigBeeXmitStatus
	//ubyte							nChecksum;
} TTransmitStatusReply;

typedef struct TModemStatusMessage
{
	ubyte								nZigBeeModemStatusType;			// TZigBeeModemStatusType
} TModemStatusMessage;

#define kMaxNodeNameLength 20
typedef struct TNodeDiscoveryReply
{
	TATReply						nATReply;
	TShortAddress				nShortAddress;
	TZigBeeSerialNumber nSerialNumber;
	ubyte								nSignalStrength;
	ubyte								cFriendlyName[kMaxNodeNameLength]; // Actually variable length
	//ubyte							nChecksum;
} TNodeDiscoveryReply;


typedef struct TNodeIdentifierReply
{
	TATReply						nATReply;
	ubyte								nNodeName[kMaxNodeNameLength]; //Actually variable length field
	//ubyte							nChecksum;
} TNodeIdentifierReply;

typedef struct TSerialNumberReply
{
	TATReply						nATReply;
	ubyte								nValue[4];
	//ubyte							nChecksum;
} TSerialNumberReply;

typedef struct TBaudRateReply
{
	TATReply						nATReply;
	ubyte								nBaudRate[4];   // Actually variable length?
	//ubyte							nChecksum;
} TBaudRateReply;

typedef struct TGenericDataReply
{
	TATReply						nATReply;
	ubyte								nReplyData[1];   // Actually variable length?
	//ubyte							nChecksum;
} TGenericDataReply;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//																				ZigBee Node Table
//
// Table of ZigBee nodes discovered by "ND" command.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TZBPegType
{
	pegLocalMessages,
	pegRemoteMessages,
	pegSuccess,
	pegRetransmit,
	pegFailed,
	kNumbOfPegCountRegisters
} TZBPegType;

enum
{
#if defined(_WINDOWS)
	kSizeOfZigBeeNodeTable					= 120
#else
	kSizeOfZigBeeNodeTable					= 9
#endif
};

typedef char TZigBeeFriendlyName[8];

typedef struct TZigBeeNode
{
	//TShortAddress					ntwkAddress;
	TZigBeeSerialNumber		nSerialNumb;
	//TZigBeeFriendlyName		sFriendlyName;
} TZigBeeNode;

extern TZigBeeNode nodeTable[kSizeOfZigBeeNodeTable];

#if defined(_WINDOWS)
	extern void storeSerialNumberHigh(ubyte *pInfo);
	extern void storeSerialNumberLow(ubyte *pInfo);
#else
	#define storeSerialNumberHigh(pInfo)
	#define storeSerialNumberLow(pInfo)
#endif

#if defined(_WINDOWS) && !defined(Simulator)
	extern void processRcvEnergyScanCommandResponse(TATReply *pReply, ubyte nDataLength);
	extern void processRcvATCommandReply(int nNodeIndex, TATReply *pReply, ubyte nDataLength);
	extern void processRcvNodeDiscoveryCommandResponse(TNodeDiscoveryReply *pReply, ubyte nDataLength);
	extern void processRcvNodeIdentifierCommandResponse(TNodeIdentifierReply *pReply, ubyte nDataLength);

	typedef struct  TZBPegs
	{
		int pegMessages[kSizeOfZigBeeNodeTable];
		int pegSuccess[kSizeOfZigBeeNodeTable];
		int pegRetransmit[kSizeOfZigBeeNodeTable];
		int pegFailed[kSizeOfZigBeeNodeTable];
	} TZBPegs;

	extern TZBPegs zbPegs[3];
	extern void incrementZBMessagePeg(TZBPegType pegType, ubyte nToNode);
#else
	#define processRcvEnergyScanCommandResponse(pReply, nDataLength)
	#define processRcvATCommandReply(nNodeIndex, pReply, nDataLength)
	#define incrementZBMessagePeg(pegType, nToNode)
	#define  processRcvNodeDiscoveryCommandResponse(pReply, nDataLength);
	#define  processRcvNodeIdentifierCommandResponse(pReply, nDataLength);
#endif


typedef enum TZBStates
{
	//
	// States related to initialization and startup
	//
	zbStateNotEquipped,
	zbStateStartUp,
	zbStateStartUp_Delay1,
	zbStateStartUp_Delay2,
	zbStateStartUp_FailedToOpenFile,
	zbStateStartUp_00_SendGetSerialNumberHigh,				// Get serial number as first item retrieved. So that it's valid!
	zbStateStartUp_01_SendGetSerialNumberLow,
	zbStateStartUp_02_SendGetPowerLevel,
	zbStateStartUp_03_SendSetPacketizationTimeout,
	zbStateStartUp_04_Send16BitAddress,
	zbStateStartUp_05_SendSetChannel,
	zbStateStartUp_06_SendGetNodeName,
	zbStateStartUp_07_SendAssociateEndDeviceOff,
	zbStateStartUp_08_SendSetPanID,
	zbStateStartUp_09_SendSetCoordinatorDisable,
	zbStateStartUp_10_SendRandomDelay,
	zbStateStartUp_11_SendXBeeRetries,
	zbStateStartUp_12_SendNodeDiscoverOptions,
	zbStateStartUp_13_SendWriteChangesToNVM,
	zbStateStartUp_14,
	zbStateStartUp_15,
	zbStateStartUp_16,
	zbStateStartUp_17,
	zbStateStartUp_18,
	zbStateStartUp_19,

	// End of States related to initialization and startup
	///////////////////////////////////////////////////////////////////////////////////////

	//
	// These must be the last states for the state machine
	//
	zbStateIdleReadyForCommand,													// Must be first one
	zbStateIdleGuardTimeBetweenCommands,
	zbStateWaitingForCommandReply,
	zbStateWaitingForCommandRetransmitReply,
} TZBStates;


enum
{
		kMaxPacketLength							= 64 + 15,
};

typedef struct TControlParms
{
	bool bPacketReceived;
	TZBStates nZBState;

	// Parameters
	
	TZigBeeSerialNumber		mySerialNumber;
	uword nPanID;
	ubyte	nChannel;
	ubyte	nMyNodeIndex;

	// Internal State Variables
	
	ubyte nFrameID;
	uword nWaitForReplyTicksRemaining;
	ubyte nInterMsgInterval[3];
	ubyte nNextNodeToPoll;
	bool  bSendXmitReply;
	ubyte nXmitPacketChecksum;
	
	// Receive Message

	TZBRcvState nRcvState;
	ubyte nCurrByteIndexInPacket;

	ubyte partialReceivedPacket[kMaxPacketLength];
	ubyte receivedPacket[kMaxPacketLength];
	ubyte receivedMessage[kMaxPacketLength];
	ubyte nSizeReceivedMessage;
	ubyte nReceivedPacketChecksum;
	ubyte zbInterCharTimeoutCount;
	uword nPacketDataLength;

	TXbeeAPIXmitMessageTypes nLastCommandTypeSent;
	TATCommands nLastATCommandSent;
	TATCommands nLastATReplyRcvd;
	ubyte nMsgToNode;
	ubyte nLastFrameIDSent;
	ubyte nLastFrameIDRcvd;
	bool  bLastCommandFailed;

} TControlParms;


extern TControlParms zbPortData[kNumbOfZigBeePorts];


#if defined(_WINDOWS) || defined(Simulator)

	#undef CLASS_DECLSPEC_ZBPrint
	#ifdef _EXPORTING_ZBPrint
		#define CLASS_DECLSPEC_ZBPrint    __declspec(dllexport)
	#else
		#define CLASS_DECLSPEC_ZBPrint    __declspec(dllimport)
	#endif


	extern CLASS_DECLSPEC_ZBPrint void debugPrintZigBeePacketRcvViaNodeIndex(const int nNodeIndex, struct TResponseHeader *pReply);
	extern CLASS_DECLSPEC_ZBPrint void debugPrintZigBeePacketXmitViaNodeIndex(TZBSendType nSendType, const int nNodeIndex, unsigned char *pChar, unsigned char nNumbOfChar);

	extern CLASS_DECLSPEC_ZBPrint void debugPrintZigBeePacketRcvViaSerialNumber(const TZigBeeSerialNumber *pToSerialNumber, struct TResponseHeader *pReply);
	extern CLASS_DECLSPEC_ZBPrint void debugPrintZigBeePacketXmit(TZBSendType nSendType, const TZigBeeSerialNumber *pFromSerialNumber, unsigned char *pChar, unsigned char nNumbOfChar);

#else
	#define debugPrintZigBeePacketRcvViaSerialNumber(pToSerialNumber, pReply)
	#define debugPrintZigBeePacketXmit(nSendType, pFromSerialNumber, pChar, nNumbOfChar)
	#define debugPrintZigBeePacketRcv(pToSerialNumber, pReply)
#endif


#endif //#if defined(bHasMultRobotNetworking)

#ifdef __cplusplus
};
#endif

#endif
