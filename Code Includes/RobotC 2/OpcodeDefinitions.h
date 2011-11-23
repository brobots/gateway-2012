#ifndef opcodeDefinitions__H_
#define opcodeDefinitions__H_

#ifdef __cplusplus
  extern "C" {
#endif


#include "TSensorTypes.h"
#include "TSounds.h"


//
// Do not change the order of the following enum declares. This info is known by assembler
// code and is hard coded.
//
typedef enum
{
  arithOffsetAddTo          = 0, // Must be consecutive opcodes
  arithOffsetMinusTo        = 1,
  arithOffsetTimesTo        = 2,
  arithOffsetDivideTo       = 3,
  arithOffsetAndTo          = 4,
  arithOffsetOrTo           = 5,
  arithOffsetBitComplement  = 6,
  arithOffsetModuloTo       = 7  // Don't change order. Used as bounds in 'for' statements
} TArithOffsets;


typedef enum
{
  sysFuncHogProcessor             			=  0,  // Hog all processor CPU time. No switching to other runnable tasks
  sysFuncFreeProcessor            			=  1,  // Release "Hog all processor CPU time"
  sysFuncSwitchContext            			=  2,  // Finish timeslice. Switch to other runnable tasks if available.
  sysFuncMemCpy                   			=  3,  // Standard "memcpy"  function
  sysFuncMemSet                   			=  4,  // Standard "memset"  function

#if !defined(VEX)
  sysFuncSetSuspendResumeTask     			=  5,  // Set task into suspended state or note
  sysFuncGetTaskState           				=  6,  // Get task state
#endif

#if defined(hasStringSupport) || defined(_WINDOWS)
  sysFuncStrCpy                   			=  7,  // Standard "strcpy"  function
  sysFuncStrNCpy                  			=  8,  // Standard "strncpy" function
  sysFuncStrCat                   			=  9,  // Standard "strcat"  function
  sysFuncStrNCat                  			= 10,  // Standard "strncat" function
  sysFuncStrCmp                   			= 11,  // Standard "strcmp"  function
  sysFuncStrNCmp                  			= 12,  // Standard "strncmp" function
  sysFuncStrLen                   			= 13,  // Standard "strlen"  function
  sysFuncStrIndex                 			= 14,  // String index function
  sysFuncStrSubstring             			= 15,  // String 'substring' function
  sysFuncStrDelete                			= 16,  // String 'delete substring' function
	sysFuncGetFileName										= 17,
  sysFuncStrTrim                  			= 18,  // Trim string function
  sysFuncStrNTrim                 			= 19,  // Standard "strncpy" function
#endif

#if defined(AVRCPU) || defined(_WINDOWS)
  sysFuncPollRoboCubScreen        			= 19,
#endif

#if defined(bAssociateMotorWithEncoder) || defined(_WINDOWS)
  sysFuncMapEncoderToMotor							= 20,  // Define mapping between motor and associated quadrature encoder
#endif

#if defined(bSmartMotorsWithEncoders) || defined(_WINDOWS)
  sysFuncMotorRampingParms        			= 21,
#endif

#if defined(bHasSensorBiasSettings) || defined(_WINDOWS)
	sysFuncSensorCalculationCycles        = 22,
#endif

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
	//sysFuncAddDatalogEnhanced       			= 23,
	sysFuncDefineSensorPortHubs     			= 24,
  sysFuncDrawNXTMenu              			= 25,
	sysFuncValidIcon                			= 26,
	sysFuncGetDate                  			= 27,
  sysFuncGetRawADValue            			= 28,
  sysFuncI2CGetSensorInfo         			= 29,  // Nxt only. Gets copy of I2C sensor handler block
	sysFuncI2CClearSensorInfo       			= 30,  // NXT Only. Clears I2C sensor handler block statistics
  sysFuncI2CSensorReply           			= 31,  // Nxt only. Gets copy of last I2C reply data from sensor
	sysFuncI2CSensorConfig          			= 32,  // NXT only. Configures data for I2C sensor background polling.
  sysFuncI2CGetDriverState        			= 33,  // NXT only. Gets the I2C driver state.
  sysFuncIOMapRead											= 34,  // Nxt only. Read IOMap.
  sysFuncIOMapWrite											= 35,  // Nxt only. Write IOMap.
  sysFuncGetStandardIconInfo						= 36,  // Nxt only. Get info on standard builtin ICONS
  sysFuncDisplayStandardIcon						= 37,  // Nxt only. Display one of the standard builtin ICONS
	sysFuncGetValidColorSensor						= 38,
	sysFuncGetColorSensorValues						= 39,
	sysFuncGetColorSensorCounts						= 40,
#endif

#if defined(hasCamera) || defined(_WINDOWS)
  //
  // Camera Sensor Control
  //
  sysFuncCameraFunctions          			= 41,
  sysFuncSetCameraConfig          			= 42,
  sysFuncGetCameraConfig          			= 43,
  sysFuncGetTrackingParms         			= 44,
#endif

#if defined(bHasSoundSupport)
	sysFuncPlaySound                			= 45,
	sysFuncClearSound                			= 46,
#endif

#if defined(bHasSoundFiles) || defined(_WINDOWS)
	sysFuncPlaySoundFileVariableName			= 47,
	sysFuncPlaySoundFileEmbeddedFileName	= 48,
#endif

  //Unused									           	= 49,


#if defined(hasUserSerialPorts) || defined(_WINDOWS)
	sysFuncConfigureSerialPort						= 50,  // Define configuration type of user accessible UART ports
	sysFuncSerialSetBaudRate							= 51,
	sysFuncSerialGetChar									= 52,
	sysFuncSerialSendChar									= 53,
	sysFuncSerialGetXmitComplete					= 54,
#endif


#if !defined(VEX)
	sysFuncGetTaskPriority								= 55,
	sysFuncSetTaskPriority								= 56,
  sysFuncStartTaskWithPriority					= 57,
	sysFuncCheckTransmitMsgVariableLength = 58,
	sysFuncCheckReceiveMsgVariableLength  = 59,
#endif

#if defined(hasAlphaNumericLCDDisplayViaUART) || defined(_WINDOWS)
	//
  // For Alphanumeric Displays LCD & Button Control
  //
  sysFuncLCDPutNextChar									= 60,  // Display a single char on the next LCD
  sysFuncLCDPutNextShort								= 61,  // Display a short 16-bit variable on the LCD
  sysFuncLCDPutNextConstString					= 62,  // Display a const char string (i.e. stored in opcode) on the LCD
  sysFuncLCDClearLCDLine								= 63,
	sysFuncLCDPutCenteredConstString			= 64,
	sysFuncLCDDisplayProgramName					= 65,
  sysFuncLCDPosition										= 66,
#if defined(hasStringSupport)
  sysFuncLCDPutNextString               = 67,
  sysFuncLCDPutCenteredString           = 68,
#endif
#endif

  //Unused								            	= 69,
  //Unused								            	= 70,

#if defined(hasOptionalUploadSupport)
	sysFuncBulkSysParmsRead             	= 71,
	sysFuncBulkSysParmsWrite             	= 72,
#endif

#if defined(bHasFlashFileSystem) || defined(_WINDOWS)
	sysFuncValidFileIndex									= 73,
	sysFuncEraseFlashSector								= 74,

	#if (!defined(VEX)) || defined(_WINDOWS)
		sysFuncGetFileType										= 75,
		sysFuncDeleteFile											= 76,
	#endif
#endif

#if (defined(hasDebugStreamSupport) && !defined(NXT) || defined(TETRIX)) || defined(_WINDOWS)
	sysFuncReadDebugStreamWithSize				= 77,
	sysFuncReadDebugStreamNoSize					= 78,
#endif

#if defined(hasJoystickMessageOpcodes) || defined(_WINDOWS)
  sysFuncGetJoysticks             			= 79,

	#if (!defined(VEX)) || defined(_WINDOWS)
	  sysFuncUploadJoysticks             	= 80,
	#endif
#endif

#if defined(bHasSemaphoreSupport) || defined(_WINDOWS)
	sysFuncSemaphoreInitialize            = 81,
	sysFuncSemaphoreLock									= 82,
	sysFuncSemaphoreUnlock								= 83,
#endif

#if defined(bAssociateMotorWithIOPins) || defined(_WINDOWS)
	sysFuncDefineMotorIOPins							= 84,
#endif
	
	syfFuncLast
} TSystemFunctions;


#define kDefaultTaskPriority 7              // Timeslice scheduler priority for tasks. 0 is lowest. 255 is highest

//////////////////////////////////////////////////////////////////////////////////////////
//
//                          Definition of Firmware Builtin Variable Parameters
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  //Unused                               =  0, // global variable <0..31>. Task variables <32..47>
  opcdSource100MsecTimer                 =  1, // timers <0..3>
  opcdSourceConstant                     =  2, // immediate
  //Unused                               =  3,
	opcdSourceRandom                       =  4, // random <return value is in 0 to argument, inclusive>

  opcdSourceMotorPower                   =  5, // New. Power levels -100 to +100 range
  opcdSourceIntrinsicIndirectGlobalAndType =  6, // Indirect access to any intrinsic array variable.
  opcdSourceIntrinsicIndirectGlobal      =  7, // Indirect access to any intrinsic array variable when index variable is large global.
#if defined(ARMCPU) || defined(_WINDOWS)
  opcdSourceCamera                       =  8,
#endif

#if defined(VEX) || defined(ARMCPU) || defined(Simulator) || defined(_WINDOWS)
	opcdSourceUnsignedGlobalByteVar        =  8, //
#endif

	opcdSourceSensor                       =  9, // sensors <0..2>
	opcdSourceSensorType                   = 10, // sensors <0..2>

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  opcdSourceSensorMode                   = 11, // output to sensor <0..2>
  opcdSourceSensorRaw                    = 12, // raw sensor value <0..2>
#endif

#if defined(bHasSensorBiasSettings) || defined(_WINDOWS)
  opcdSourceSensorBias                   = 11, // sensor bias
  opcdSourceSensorScale                  = 12, // output scale
  opcdSourceSensorFullCount              = 13, // output scale
#endif

  opcdSourceSensorBoolean                = 14, // boolean sensor value
  //opcdSourceMessage                			 = 15,
  //Unused                							 = 16,



#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  opcdSourceNxtMotorFloatDuringInactivePWM = 16,// 0..2. Individual control over motors for float vs brake during inactive PWM.
  // Not implemented yet. May never be -- possibly a spare value
#endif

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  opcdSourceEventType                    = 18, // 0-15. Type of event being detected
  opcdSourceEvent                        = 19, // 0-15. Type of sensor for event
  opcdSourceEventCounts                  = 20, // 0-15. Count of number of event occurrences
#endif
 	//Unused                               = 21,

  opcdSource1MsecTimer                   = 22, // 0-3. 1 millisecond timer. New -- Dick's add
  opcdSourceTaskEvents                   = 23, // 0-9. Bit mask showing which events alerted the task
  opcdSourceSystem                       = 24, // Contains many 'subvariables' to customize ROBOTC firmware
#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  opcdSourceEventState                   = 25, // 0-15. Low, normal, or high
#endif

  opcdSource10MsecTimer                  = 26, // 0-3.
#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  opcdSourceClickCounter                 = 27, // 0-15. Numb of clicks detected for event sensor
  opcdSourceUpperThreshold               = 28, // 0-15. Used for event generation
  opcdSourceLowerThreshold               = 29, // 0-15.
  opcdSourceHysteresis                   = 30, // 0-15
  opcdSourceDuration                     = 31, // 0-15, Blink time. Measured in 10 msec units. Minimum value is 5
#endif
	//Unused															 = 32,

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)

  opcdSourceServoType                    = 33, // Standard or continuous rotation servo
  opcdSourceServoTarget                  = 34, // Access to TETRIX Servos - Target Setting
	opcdSourceServoMinPos									 = 35,
	opcdSourceServoMaxPos									 = 36,
  opcdSourceMotorPWM										 = 37,
  opcdSourceServoPosition                = 38, // Access to TETRIX Servos
  opcdSourceServoRateOfChange            = 39, // Access to TETRIX Servos - Rate of Change per 10 Msec Setting
  opcdSourceNxtI2CBytesRead              = 40, // Number of I2C Message Bytes Ready
  opcdSourceNxtI2CMessagingStatus        = 41, // I2C Messaging Status
  opcdSourceNxtSensorSubType             = 42, // Subtype for custom sensors
#endif

	///////////////////////////////////////////////////////////////////////////////////
  //
  //                          Unique to NXT  or VEX
  //
  ///////////////////////////////////////////////////////////////////////////////////

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(_WINDOWS)
  opcdSourceIFIRadioControl              = 38, // Access to VEX RF Controller
#endif

#if defined(VEX) || defined(_WINDOWS)
  opcdSourceIfiInterruptPort             = 39,
#endif

  ///////////////////////////////////////////////////////////////////////////////////
  //
  //                    New Parm Types for ROBOTC
  //
  ///////////////////////////////////////////////////////////////////////////////////

  //
  // Keep "memory" parms in consecutive positions for efficient generation
  // of switch statements by H8 compiler. It will take less code (it stores values
  // only for min to max case labels and this will minimize the range.
  //
  opcdSourceGlobalVar                    = 43, // Global variables, indexed by word (16-bit) offset
  opcdSourceIndirectGlobal               = 44,
  opcdSourceGlobalSignedByteVar          = 45, // Global variables, indexed by byte (8-bit) offset
  opcdSourceIndexedGlobalSignedByteAndIndexVar = 46, // indirect global result of globalVar + constant   (index by 1-bytes)
  opcdSourceIndexedGlobalAndIndexVar     = 47, // indirect global result of globalVar + constant   (index by 2-bytes)
  opcdSourceIndexedGlobalLongAndIndexVar = 48, // indirect global result of globalVar*2 + constant (index by 4-bytes)

  opcdSourceStackVar                     = 49, // stack    variable <0..255>
  opcdSourceConstantVar                  = 50, // constant variable <0..255>. Static
  // end of consecutive "memory" parms

  opcdSourceFunctionReturnValue          = 51,
	opcdSourceGlobalUnsignedByteVar        = 52,

#if defined(bSmartMotorsWithEncoders) || defined(_WINDOWS)
  opcdSourceMotorRunState                = 53,  // Motor movement state (NXT)
  opcdSourceMotorEncoder								 = 54,  // Actual Encoder counts from smart motors (NXT)
  opcdSourceMotorTargetEncoder					 = 55,  // Target Encoder counts from smart motors (NXT)
	opcdSourceMotorRegulation              = 56,  // Motor regulation state (NXT)
#endif

#if defined(bMotorMirroring) || defined(_WINDOWS)
  opcdSourceMotorReflectDirection        = 57,  // 180 degree motor adjustment (rather than reversing wires)
#endif

  opcdSourceGlobalVarPointer             = 58, // Global variable contains a RAM pointer reference
  opcdSourceStackVarPointer              = 59, // Stack  variable contains a RAM pointer reference
  opcdSourceIndexedGlobalUnsignedByteAndIndexVar = 60, // indirect global result of globalVar + constant   (index by 1-bytes)
  opcdSourceExternMemoryRef              = 61, // Contains references to 'native' extern memory variables
  opcdSourceGlobalVarPointerPlusOffset   = 62, //20081231
  //
  // Placeholders. May not be implemented yet.
  //
 	//Unused                               = 63, //
  opcdSourceBad                          = 63 // Max value is 63 =    = 0x3F. Must be last entry

  //
  // Max value is 63 =    = 0x3F (6 bits to fit in filed of conditional branch instruction
  //
} TOpCodeSourceTypes;

#define opcdSourceMaskForConditionalBr  ((TOpCodeSourceTypes)(unsigned char) 0x3F) // Upper two bits are used to store the condition [<,==, !=, >] type
#define opcdSourceBadUndefined          ((TOpCodeSourceTypes)(unsigned char) 0xFF)
#define kNumbOfOpCodeParmTypes   64


#if defined(ARMCPU)
  typedef unsigned int TOpCodeSourceParmTypes;
#else
  typedef TOpCodeSourceTypes TOpCodeSourceParmTypes;
#endif


typedef enum
{
  //
  // Read only parameters to interrogate operating system
  //
	kSystemFirmwareVersion                      =  0,    // Do not change order. Want consistentcy across different versions
	kSystemPlatformType													=  1,    // Do not change order. Want consistentcy across different versions

  kSystemStartOfFlashFileHeader            		=  2,
  kSystemDebugTaskMode                        =  3,

#if !(defined(NXT) || defined(TETRIX))
  kSystemProgramNumb                          =  4,
#endif
	kSystemCurrentTask                          =  5,
#if defined(bHasStandardBatteryMonitoring) || defined(Simulator) || defined(_WINDOWS)
  kSystemImmediateBatteryLevel                =  6,
#endif

  //
  // Customize operating system behaviour
  //
  kSystemOpcodesPerTimeslice                  =   7,
  kSystemClockMinutes                         =   8,

#if (defined(hasAlphaNumericLCDDisplayViaUART) || defined(bHasRemoteButtons)) && !defined(NXT) || defined(Simulator) || defined(_WINDOWS)
  kSystemLCDBacklight                         =   9,
  kSystemLCDButtons                           =  10,
#endif


#if defined(hasAlphaNumericLCDDisplayViaUART) || defined(Simulator) || defined(_WINDOWS)
	kSystemLCDRefreshRate                       =  11,
#endif
#if defined(AVRCPU) || defined(Simulator) || defined(_WINDOWS)
  kSystemLCDRefreshCycles                     =  12,
#endif

  kSystemDefaultTaskStackSize                 =  13,

#if defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemFloatDuringInactiveMotorPWM          =  14,
#endif

#if defined(bHasFastSonarSensor) || defined(Simulator) || defined(_WINDOWS)
  kSystemFastSonarSensor                      = 15,
#endif

  kSystemSysTime                              =  16,
  kSystemTaskStackAddress                     =  17,   // start memory location of the array of task stacks
  kSystemPgmTime                              =  18,
  kSystemTaskSchedulingPriority               =  19,

#if defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemBTHasProgressSounds                  =  20,
  kSystemBluetoothBusy                        =  21,
  kSystemBluetoothDebug                       =  22,
#endif

#if defined(NXT) || defined(TETRIX) || defined(AVRCPU) || defined(Simulator) || defined(_WINDOWS)
  kSystemPowerDownDelay                       =  23,
#endif

#if defined(hasCamera)
  kSystemIsCameraTracking                     =  24,
#endif

#if defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemLowVoltageBatteryCountLimits         =  25,
#endif


  //
  // Sound Parameters
  //
#if defined(bHasSoundVolume) || defined(Simulator) || defined(_WINDOWS)
  kSystemVolume                               =  26,  // Volume control. Applies to PlayNote opcode only..Valid for a "session"
#endif
  kSystemBOOLSoundPlaying                     =  27,  // Bool variable to indicate if a sound is currently playing
  kSystemPlaySounds                           =  28,
  kSystemSoundQueueHasFreeEntries             =  29,  // Able to queue the next sound request

#if (!(defined(VEX))  && defined(useFloats)) || defined(Simulator) || defined(_WINDOWS)
	kSystemFloatConversionException							=  30,
#endif
  kSystemClearVariablesOnPgmStart							=  31,

#if  defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemVirtualMotorChanges                  =  32,
  kSystemVirtualSensorTypeChanges             =  33,
  kSystemVirtualSensorModeChanges             =  34,
#endif

#if (defined(bHasStandardBatteryMonitoring) && !defined(VEX2) && !defined(NXT) || defined(TETRIX)) || defined(Simulator) || defined(_WINDOWS)
  kSystemShutdownVoltage                      =  35,
#endif

#if defined(bHasLCDGraphicsDisplay) || defined(hasAlphaNumericLCDDisplayViaUART) || defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemRemoteButton                         =  36,
#endif

#if defined(bHasStandardBatteryMonitoring)
  kSystemAvgBatteryLevel                      =  37,
#endif

#if defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemNXTGMessagingCompatability           =  38,
#endif

#if defined(NXT) || defined(TETRIX) || defined(Simulator) || defined(_WINDOWS)
  kSystemNoPowerDownOnACAdaptor               =  39,
  kSystemUltrasonicFilterCount                =  40,
#endif

#if defined(VEX2) || defined(Simulator) || defined(_WINDOWS)
  kSystemCurrCortexProgramType            		=  41,
  kSystemNextCortexProgramType            		=  42,
#endif

	// unused                                   =  43,
  // ...
  // unused                                   =  55,

#if (defined(bHasSoundSupport) && defined(bHasSoundDriverOnOff)) || defined(Simulator) || defined(_WINDOWS)
  kSystemSoundDriverOnOff                     =  56,
#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(VEXPro) || defined(Simulator) || defined(_WINDOWS)
  kSystemIFIPWMOverride                       =  58,		// Behaviour when transmitter or USB Cable (VEX2) is not-connected
#endif

#if defined(VEX) || defined(_WINDOWS)
  kSystemIFIPwmOwner                          =  60,
  kSystemVEXAnalogChannelCount                =  61,
  kSystemIFIUserCmd                           =  62,

#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(VEXPro) || defined(Simulator) || defined(_WINDOWS)
  kSystemVEXRCReceiveState                    =  63,  //  Bit map of active transmitters
	kSystemIFIMasterVersion                     =  64,
	kSystemBackupBatteryLevel                   =  65,
	kSystemVEXNEXTActive                        =  66,
  kSystemIFISPIMsgCounts                      =  67,
  kSystemIFIRobotDisabled                     =  68,
#endif

#if defined(VEX) || defined(Simulator) || defined(_WINDOWS)
  kSystemVEXDurationAutonomous                =  69,
  kSystemVEXDurationUserControl               =  70,
#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(VEXPro) || defined(Simulator) || defined(_WINDOWS)
  kSystemIFIAutonomousMode                    =  71,
  kSystemIFIAutonomousModeBySlave             =  72,
#endif

#if defined(NXT) || defined(TETRIX) || defined(ARM) || defined(Simulator) || defined(_WINDOWS)
  kSystemDatalogSize                          =  58, // Number of entries in datalog
  kSystemUsedDatalogBytes                     =  59,
  kSystemAvgBackgroundTime                    =  60,
  kSystemAvgInterpreterTime                   =  61,
  kSystemBTCurrentStreamIndex                 =  62,
	kSystemBluetoothLastCmd                     =  63,
  kSystemBluetoothStatus                      =  64,
  kSystemNxtLCDStatusDisplay                  =  65,
  kSystemNxtAvailFlash                        =  66,  // Amount of unused flash (in 100s of bytes) in the NXT file system.
  kSystemNxtI2CRetries                        =  67,  // Number of attempts to be made to send a I2c sensor message
  kSystemNxtButtonTask                        =  68,  // This selects task to run when a button is pushed
  kSystemNxtExitClicks                        =  69,  // When 'nNxtButtonTask' is not -1, defines the number of 'exit' button clicks to terminate program
#endif

	kSystemSendVariableLengthTestMessage        = 73,
	kSystemReplyVariableLengthTestMessage       = 74,

#if defined(bHasLCDContrast) || defined(Simulator) || defined(_WINDOWS)
  kSystemLCDDefaultContrast                   =  75,  // Value stored in non-volatile memory and used on power up.
  kSystemLCDContrast													=  76,  // Contrast level for the LCD
#endif

#if defined(NXT) || defined(TETRIX) || defined(Simulator)  || defined(_WINDOWS)
  kSystemBTVisible                            =  79,  // A Boolean variable to indicate whether BT is enabled
  kSystemBTEnabled                            =  80,  // A Boolean variable to indicate whether BT is visible
  kSystemMotorBeingTraced                     =  81,
  kSystemNxtSynchMotors                       =  82,  // Bitmap of the syncrhonized motors on the NXT.
  kSystemNxtSynchSlaveSpeedRatio              =  83,  // Bitmap of the syncrhonized motors on the NXT.
  kSystemMaxRegulatedSpeedCountsPerSecondNxt  =  84,  // Used by NXT PID speed regulation on NXT motors.
  kSystemPidUpdateIntervalInMsecsNxt          =  85,  // Update interval used by NXT PID speed regulation on motors.
  kSystemPidUpdateIntervalInMsecs12V          =  86,  // Update interval used by NXT PID speed regulation on motors.
  kSystemNxtI2CCheckACKs                      =  87,  // Check all I2C ACKs or only first ACK in message
  kSystemBTSkipPasswordPrompt                 =  88,  // A Boolean variable to indicate whether BT should use default pswd without prompting
  kSystemBluetoothMode                        =  89,
  kSystemBluetoothCmdStatus                   =  90,  // Returns the status of the last bluetooth command
  kSystemFtcHubUpdateInterval                 =  91,  // Minimum update interval (in msec) for servo/motor controller
	kSystemFtcServoUseFastI2C                   =  92,  // Use ROBOTC fast I2C messaging for servo controller
	kSystemBatteryShutdownExternal              =  93,  // Low voltage battery shutdown threshold for servo controller
  kSystemMaxRegulatedSpeedCountsPerSecond12V  =  94,  // Used by NXT PID speed regulation on 12V motors.

  kSystemHS_Mode                              =  95,  // High Speed RS-485 Mode
	kSystemHS_Status                            =  96,  // High Speed RS-485 Status (R/O)
  kSystemBTOptimizePerformance								=  97,  // Optimize Bluetooth performance
  kSystemBTStreamSwitchDelay                  =  98,  // Delay when switching from DATA mode to CMD mode to allow buffers to fully transmit.
  kSystemAvgBatteryLevelExternal              =  99,  // External battery voltage for MUX controllers -- average value
  kSystemBatteryLevelExternal                 = 100,  // External battery voltage for MUX controllers -- immediate value
  kSystemNxtButtonTransition                  = 101,  // Reports button pressed transitions. Only report once
  kSystemVolumeDefault                        = 102,  // Volume control. Applies to PlayNote opcode only..Valid for a "session"
  kSystemPowerDownDelayDefault                = 103,
  kSystemTraceInternalBluetooth               = 104,  // Traces internal Bluetooth Activity
  kSystemTraceInternalHighSpeed               = 105,  // Traces internal High Speed Link Activity
  kSystemTraceInternalDirectCommands          = 106,  // Traces internal Fantom Direct Commands Activity
  kSystemTraceInternalOpcodeMessages          = 107,  // Traces internal VM Opcode Messages Activity
	kSystemColorSensorWhiteThreshold            = 108,  // R,G,B thresholds for detecting "white" color with LEGO color sensor
  kSystemNxtHideDataFile                      = 109,  // A Boolean variable to indicate whether DATA files should be hidden on the NXT GUI
  kSystemNxtRechargable                       = 110,  // A Boolean variable to indicate whether rechargeable battery is used on NXT
	kSystemSpare111															= 111,	// Causes compilation if changed. So easy to trap changes / additions to list.
#endif

#if defined(NXT) || defined(TETRIX) || defined(ARM) || defined(Simulator) || defined(_WINDOWS)
  kSystemNxtButtonPressed                     = 112,  // This contains the index of the currently pressed button  (0..3). No button is 0xFF.
  kSystemNxtMaxDataFileCount                  = 113,  // Maximum number of "dataNNNN.rdt" files on the NXT
  kSystemNxtMaxDataFileSize                   = 114,  // Maximum size (in K bytes) for all "dataNNNN.rdt" file storage on the NXT
#endif

	kSystemLastParmIndex                               // Gets the next sequential address
} TSystemParmTypes;

#define kSizeOfSystemParameters (kSystemLastParmIndex)  // total size for arrays

typedef enum
{
#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  kExternUiIOMAPAddress                       =  0,
  kExternBluetoothContactTableAddress         =  1,
  kExternBluetoothConnectionTableAddress      =  2,
  kExternSensorIOMAPAddress                   =  3,
  kExternMotorIOMAPAddress                    =  4,
  kExternBrickData                            =  5,
#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(_WINDOWS)
  kExternIFITxData                            =  6,
  kExternIFIRxData                            =  7,
#endif

#if defined(hasCamera) || defined(_WINDOWS)
	kExternCMUCAMTracking                       =  8,
#endif

  kExternLastExternIndex                  // Gets the next sequential address
} TSystemExternParms;


//////////////////////////////////////////////////////////////////////////////////////////
//
//                           Clear Command Flags
//
//////////////////////////////////////////////////////////////////////////////////////////

//
// Define individual bits that can be "OR-ed" together for the "clear All" opcode
//
typedef enum
{
  actOnTimers       = 0x01,   // Resets the internal timers to zero value
  actOnSensors      = 0x02,   // Sets the value of all sensors to zero (including NXT motor encoder values
  actOnVariables    = 0x04,   // Clears all variables to zero
  actOnTaskStack    = 0x08,   // Clears the task stacks to zero.
  actOnEvents       = 0x10,   // Undefines all events
  actOnBreakpoints  = 0x20,   // Undefines all breakpoints
  actOnMotors       = 0x40,   // Stop all motors
	actOnFlashFileResetProgram    = 0x0100,   // This will cause interpreter to reset the RAM pointers to program locations in flash
                              // it is not intended for user use and will screw up running programs and likely cause
                              // VM to crash if used. It is for internal ROBOTC IDE use only.
#if defined(bHasDatalog)
  actOnDatalog      = 0x80,   // Zeros the datalog size. (i.e. size 1)
#endif
  //actOnFRCRelays    = 0x80,   // Clears all the FRC Relays
  actOnNone         = 0x00    // Do nothing
} TClearCommandAction;

#if defined(NXT) || defined(TETRIX)
//////////////////////////////////////////////////////////////////////////////////////////
//
//                           NXT Misecellaneous Functions
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  miscMemSet            = 0,
  miscMemCpy            = 1,

} TMiscellaneousFunctions;

#endif


//////////////////////////////////////////////////////////////////////////////////////////
//
//                           NXT Trig Functions
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  //
  // Do not shift these constants. Some are known to Robolab.
  //
#if defined(hasTranscendentalSupport)
  mathSine                =  0,
  mathCosine              =  1,
  mathArcTan              =  2,

  mathSineDegrees         =  3,
  mathCosDegrees          =  4,
  mathSqrtWord            =  5,
  mathSqrtLong            =  6,
  mathSqrtFloat           =  7,

	mathAbsWord             =  8,
	#if defined(useLongs) || defined(_WINDOWS)
		mathAbsLong             =  9,
		mathAbsFloat            = 10,
	#endif

  mathSgnWord             = 11,
#endif

  mathSgnLong             = 12,
  mathSgnFloat            = 13,

  mathShiftLeftByte       = 15,
  mathShiftLeftWord       = 16,
#if defined(useLongs) || defined(_WINDOWS)
  mathShiftLeftLong       = 17,
#endif

	mathShiftRightByte      = 18,
  mathShiftRightWord      = 19,
#if defined(useLongs) || defined(_WINDOWS)
  mathShiftRightLong      = 20,
#endif

#if defined(hasTranscendentalSupport)
	mathXorByte             = 21,
  mathXorWord             = 22,
  mathXorLong             = 23,

	mathNegateByte          = 24,
  mathNegateWord          = 25,
	#if defined(useLongs) || defined(_WINDOWS)
		mathNegateLong          = 26,
	#endif
	//mathNegateFloat         = 27,
#endif


#if defined(hasTranscendentalSupport)
  mathExp                 = 14,

	mathArcSin              = 28,
  mathArcCos              = 29,
  mathDegreesToRadians    = 30,
  mathRadiansToDegrees    = 31,

  mathLog                 = 32,
  mathLog10               = 33,

	mathCeil								= 34,
	mathFloor								= 35,
#endif
  mathLast

} TTranscendentals;


//////////////////////////////////////////////////////////////////////////////////////////
//
//                              Definition of ROBOTC VM Opcodes
//
//////////////////////////////////////////////////////////////////////////////////////////

#if defined(_WINDOWS)
  #define opEnumType (ubyte)
#else
  #define opEnumType (sbyte) (ubyte)
#endif

typedef enum
{
  opcdNoop                         = opEnumType  0x00, // Could be reused
  opcdDebugGetStatus               = opEnumType  0x01,
#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(VEXPro) || defined(AVRCPU) || defined(Generic) || defined(Simulator) || defined(_WINDOWS)
  opcdDownloadJoysticks            = opEnumType  0x02,
#endif
  opcdDirectEvent                  = opEnumType  0x03,
  opcdGet4ByteValue                = opEnumType  0x04,
  opcdSetSourceValue               = opEnumType  0x05,
  opcdClearAllEvents               = opEnumType  0x06,
  opcdSaveNxtDatalog               = opEnumType  0x07, // Temporary placeholder to save NXT datalog to flash file

  opcdAddToSourceValue             = opEnumType  0x08, // Must be consecutive opcodes
  opcdMinusToSourceValue           = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetMinusTo),
  opcdTimesToSourceValue           = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetTimesTo),
  opcdDivideToSourceValue          = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetDivideTo),
  opcdAndToSourceValue             = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetAndTo),
  opcdOrToSourceValue              = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetOrTo),
  opcdBitComplementSourceValue     = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetBitComplement),
  opcdModuloToSourceValue          = opEnumType (opcdAddToSourceValue + (ubyte) arithOffsetModuloTo),  //0x0F

  opcdAlive                        = opEnumType  0x10,
  opcdSetSourceValueByteConst      = opEnumType  0x11,
  //Unused		                     = opEnumType  0x12,
  //Unused                         = opEnumType  0x13,
  opcdUploadDeviceMotors           = opEnumType  0x14,
  opcdUploadDeviceSensors					 = opEnumType  0x15,
  opcdDebugClearException          = opEnumType  0x16,
  opcdCallSub                      = opEnumType  0x17,

  opcdAddToLong                    = opEnumType  0x18, // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToLong                  = opEnumType (opcdAddToLong + (ubyte) arithOffsetMinusTo),
  opcdTimesToLong                  = opEnumType (opcdAddToLong + (ubyte) arithOffsetTimesTo),
  opcdDivideToLong                 = opEnumType (opcdAddToLong + (ubyte) arithOffsetDivideTo),
  opcdAndToLong                    = opEnumType (opcdAddToLong + (ubyte) arithOffsetAndTo),
  opcdOrToLong                     = opEnumType (opcdAddToLong + (ubyte) arithOffsetOrTo),
  opcdBitComplementLong            = opEnumType (opcdAddToLong + (ubyte) arithOffsetBitComplement),
  opcdModuloToLong                 = opEnumType (opcdAddToLong + (ubyte) arithOffsetModuloTo),  //0xDF

  opcdGetMemoryMap                 = opEnumType  0x20,

#if defined(bHasLCDGraphicsDisplay) || defined(_WINDOWS)
  opcdUploadPixelLCD               = opEnumType  0x21,
#endif

#if defined(hasAlphaNumericLCDDisplayViaUART) || defined(_WINDOWS)
  opcdUploadAlphaNumericLCD        = opEnumType  0x22,
#endif

	//Unused                         = opEnumType  0x23,
  //Unused                         = opEnumType  0x24,
  opcdMultiRobotNtwking            = opEnumType  0x25,
  opcdAssignLongOrFloat            = opEnumType  0x26,
  opcdBranchNear                   = opEnumType  0x27,

  opcdAssignLongConstantWord       = opEnumType  0x28,
  opcdAssignLongConstant           = opEnumType  0x29,
  opcdArrayBounds                  = opEnumType  0x2A,
  opcdAssignGlobalConstantByte     = opEnumType  0x2B, // cannot be used for message opcode. Conflict, and length wrong
  opcdAssignGlobalConstant         = opEnumType  0x2C, // cannot be used for message opcode. Conflict, and length wrong
  opcdAssignGlobalVariable         = opEnumType  0x2D, // cannot be used for message opcode. Conflict, and length wrong
  opcdMiscellaneousFunctions       = opEnumType  0x2E,
  //Unused                         = opEnumType  0x2F,

  opcdAddToGenericUnsignedByteValue		= opEnumType  0x30,
  opcdMinusToGenericUnsignedByteValue	= opEnumType (opcdAddToGenericUnsignedByteValue + (ubyte) arithOffsetMinusTo),
  opcdTimesToGenericUnsignedByteValue	= opEnumType (opcdAddToGenericUnsignedByteValue + (ubyte) arithOffsetTimesTo),
  opcdDivideToGenericUnsignedByteValue= opEnumType (opcdAddToGenericUnsignedByteValue + (ubyte) arithOffsetDivideTo),
  opcdTestAndBranchSignedByteVarFar= opEnumType  0x34,

  //Unused                         = opEnumType  0x35,
  opcdSetSourceValueShortVariable  = opEnumType  0x36,
  opcdTestAndBranchUnsignedByteVarFar= opEnumType  0x37,

  opcdAddToFloat                   = opEnumType  0x38, // Must be consecutive opcodes
  opcdMinusToFloat                 = opEnumType (opcdAddToFloat + (ubyte) arithOffsetMinusTo),
  opcdTimesToFloat                 = opEnumType (opcdAddToFloat + (ubyte) arithOffsetTimesTo),
  opcdDivideToFloat                = opEnumType (opcdAddToFloat + (ubyte) arithOffsetDivideTo),
  //Unused                         = opEnumType  0x3C,
  opcdTestAndBranchLongFar         = opEnumType  0x3D,
  opcdTestAndBranchIntFar       = opEnumType  0x3E, // Candidate for reuse
  opcdTestAndBranchFloatFar        = opEnumType  0x3F,

  //Unused                         = opEnumType  0x40,
  //Unused                         = opEnumType  0x41,
  //Unused                         = opEnumType  0x42,
  opcdWaitTimer10MSec              = opEnumType  0x43,
  //Unused                         = opEnumType  0x44,
  //Unused                         = opEnumType  0x45, // Note this is same as reply to opcdSendMessage(0xB2/0xB8)
  opcdUploadEventMap               = opEnumType  0x46,
  opcdWaitTimer1MSec               = opEnumType  0x47,

  opcdAddToGenericSignedByteValue		= opEnumType  0x48, // Must be consecutive opcodes
  opcdMinusToGenericSignedByteValue	= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetMinusTo),
  opcdTimesToGenericSignedByteValue	= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetTimesTo),
  opcdDivideToGenericSignedByteValue= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetDivideTo),
  opcdAndToGenericByteValue					= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetAndTo),
  opcdOrToGenericByteValue					= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetOrTo),
  opcdBitComplementGenericByteValue	= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetBitComplement),
  opcdModuloToGenericByteValue			= opEnumType (opcdAddToGenericSignedByteValue + (ubyte) arithOffsetModuloTo),  //0x4F

  opcdStopAllTasks                 = opEnumType  0x50,
  opcdPlaySound                    = opEnumType  0x51,
  //Unused                         = opEnumType  0x52,
  opcdSendI2CMsg                   = opEnumType  0x53,
  //Unused                         = opEnumType  0x54,
  opcdReadI2CMsg                   = opEnumType  0x55,// don't use 0x55 as an opcode that can be sent via message or it will screw up recognition of message headers
  //Unused                         = opEnumType  0x56,
  opcdTestAndBranchIntConstBigNear = opEnumType  0x57,

  opcdAddToGlobalConstant          = opEnumType  0x58,  // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToGlobalConstant        = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetMinusTo),
  opcdTimesToGlobalConstant        = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetTimesTo),
  opcdDivideToGlobalConstant       = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetDivideTo),
  opcdAndToGlobalConstant          = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetAndTo),
  opcdOrToGlobalConstant           = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetOrTo),
  opcdBitComplementGlobalConstant  = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetBitComplement),
  opcdModuloToGlobalConstant       = opEnumType (opcdAddToGlobalConstant + (ubyte) arithOffsetModuloTo),  //0x5F

#if defined(NXT) || defined(TETRIX) || defined(AVRCPU) || defined(Simulator) || defined(_WINDOWS)
  opcdPowerOff                     = opEnumType  0x60,
#endif
  //Unused                         = opEnumType  0x61,
#if defined(bHasDatalog) || defined(_WINDOWS)
  opcdDatalogNext                  = opEnumType  0x62,
#endif
  opcdGetDataBytesRAM							 = opEnumType  0x63,
  //Unused                         = opEnumType  0x64,
  //Unused                         = opEnumType  0x65,
  opcdAssert                       = opEnumType  0x66,
  opcdSystemFunctions              = opEnumType  0x67,


  opcdAddToLongConstant            = opEnumType  0x68,  // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToLongConstant          = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetMinusTo),
  opcdTimesToLongConstant          = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetTimesTo),
  opcdDivideToLongConstant         = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetDivideTo),
  opcdAndToLongConstant            = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetAndTo),
  opcdOrToLongConstant             = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetOrTo),
  opcdBitComplementLongConstant    = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetBitComplement),
  opcdModuloToLongConstant         = opEnumType (opcdAddToLongConstant + (ubyte) arithOffsetModuloTo),

  //Unused												 = opEnumType  0x70,
  opcdStartTask                    = opEnumType  0x71,
  opcdBranchFar                    = opEnumType  0x72,
  //Unused                         = opEnumType  0x73,
  //Unused                         = opEnumType  0x74,
  //Unused                         = opEnumType  0x75,
  opcdAssignLongConstantByte       = opEnumType  0x76,
  //Unused                         = opEnumType  0x77,

  //Unused                         = opEnumType  0x78,
  opcdTestAndBranchIntBigConstNear = opEnumType  0x79,
  //Unused                         = opEnumType  0x7A,
  //Unused                         = opEnumType  0x7B,
  //Unused                         = opEnumType  0x7C,
  opcdAssignRamVariableAddress     = opEnumType  0x7D,  // Store in "dest" operand the RAM address of "srce" operand
  opcdArrayBounds16Bits            = opEnumType  0x7E,
  opcdSwitch                       = opEnumType  0x7F,

  //Unused												 = opEnumType  0x80,
  opcdStopTask                     = opEnumType  0x81,
  //Unused												 = opEnumType  0x82,
  //Unused                         = opEnumType  0x83, // was 'opcdUploadGlobalVariables'
  //Unused                         = opEnumType  0x84,
  //Unused                         = opEnumType  0x85,
  //Unused												 = opEnumType  0x86,
  opcdUploadEvent                  = opEnumType  0x87,

  opcdSwitchByteCase               = opEnumType  0x88,
  //Unused												 = opEnumType  0x89,
  //Unused												 = opEnumType  0x8A,
  //Unused												 = opEnumType  0x8B,
  opcdFloatToLong                  = opEnumType  0x8C,
  opcdShortToLong                  = opEnumType  0x8D,
  //Unused												 = opEnumType  0x8E,
  //Unused												 = opEnumType  0x8F,

  //Unused                         = opEnumType  0x90,
  //Unused                         = opEnumType  0x91,
  //Unused                         = opEnumType  0x92,
  opcdSetEventDefinition           = opEnumType  0x93,
  //Unused                         = opEnumType  0x94,
  //opcdTestAndBranchFar             = opEnumType  0x95,
  //Unused												 = opEnumType  0x96,
  //Unused                         = opEnumType  0x97,

  //Unused                         = opEnumType  0x98, // Soon to be obsolete opcode. May still be used by Robolab!
  //Unused                         = opEnumType  0x99, // Soon to be obsolete opcode. May still be used by Robolab!
  opcdAssignSourceByteValue        = opEnumType  0x9A,
  opcdTestAndBranchStringFar       = opEnumType  0x9B,
  opcdSignalEvent                  = opEnumType  0x9C,
  opcdResetEvent                   = opEnumType  0x9D,
  opcdSwitchIndexTableNear         = opEnumType  0x9E,
  opcdSwitchIndexTableFar          = opEnumType  0x9F,

  opcdShortToByte                  = opEnumType  0xA0,   // Added 3/27/08
  //Unused                         = opEnumType  0xA1,
  //Unused                         = opEnumType  0xA2,
  opcdDrawOnGraphicsLCDDisplay     = opEnumType  0xA3,
  opcdUploadDatalog                = opEnumType  0xA4,
  //Unused                         = opEnumType  0xA5,
	//opcdSendMessageVariable          = opEnumType  0xA6,  // New opcode. Same as 'opcdSendMessage' but 3-byte variable and not 'short' 2-byte variable
  opcdUnsignedByteToShort          = opEnumType  0xA7,   // Added 3/27/08

  opcdTrinaryAdd                   = opEnumType  0xA8,
  opcdTrinaryMinus                 = opEnumType  0xA9,
  opcdTrinaryTimes                 = opEnumType  0xAA,
  opcdSignedByteToShort            = opEnumType  0xAB,   // Added 3/27/08
  opcdShortToFloat                 = opEnumType  0xAC,
  opcdLongToFloat                  = opEnumType  0xAD,
  opcdFloatToShort                 = opEnumType  0xAE,
  opcdLongToShort                  = opEnumType  0xAF,

  opcdExitEventCheck               = opEnumType  0xB0,
  //Unused                         = opEnumType  0xB1,
  //Unused                         = opEnumType  0xB2,
  //Unused                         = opEnumType  0xB3,
  opcdStartEventMonitorShort       = opEnumType  0xB4,
  opcdStartEventMonitorLong        = opEnumType  0xB5,
  opcdUploadTimers                 = opEnumType  0xB6,
  //Unused                         = opEnumType  0xB7,

  opcdAddToShortVar                = opEnumType  0xB8, // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToShortVar              = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetMinusTo),
  opcdTimesToShortVar              = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetTimesTo),
  opcdDivideToShortVar             = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetDivideTo),
  opcdAndToShortVar                = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetAndTo),
  opcdOrToShortVar                 = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetOrTo),
  opcdBitComplementShortVar        = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetBitComplement),
  opcdModuloToShortVar             = opEnumType (opcdAddToShortVar + (ubyte) arithOffsetModuloTo), //0xBF

  //Unused                         = opEnumType  0xC0,
  //Unused                         = opEnumType  0xC1,
  //Unused                         = opEnumType  0xC2,
  //opcdSendMessageWithParm          = opEnumType  0xC3, // New opcode -- allows message plus optional parm
  //Unused                         = opEnumType  0xC4,
  opcdPlayToneVarDurationVar       = opEnumType  0xC5,
  //Unused                         = opEnumType  0xC6, // was opcdSetNXTUserTextDisplay
  opcdClearAll                     = opEnumType  0xC7,

  opcdAddToGlobal                  = opEnumType  0xC8, // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToGlobal                = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetMinusTo),
  opcdTimesToGlobal                = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetTimesTo),
  opcdDivideToGlobal               = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetDivideTo),
  opcdAndToGlobal                  = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetAndTo),
  opcdOrToGlobal                   = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetOrTo),
  opcdBitComplementGlobal          = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetBitComplement),
  opcdModuloToGlobal               = opEnumType (opcdAddToGlobal + (ubyte) arithOffsetModuloTo),  //0xCF

  //Unused                         = opEnumType  0xD0, // Obsolete opcode (no longer used by Robolab)
  //Unused                         = opEnumType  0xD1, // Possible candidate for obsolescense
  //Unused                         = opEnumType  0xD2,
  opcdAssignSourceValue            = opEnumType  0xD3, // Duplicates 'opcdAssignSourceValueRobolab' but in range for a message
  opcdUploadGlobalVariablesBig     = opEnumType  0xD4,
  //Unused                         = opEnumType  0xD5,
  //Unused                         = opEnumType  0xD6,
  //Unused                         = opEnumType  0xD7,

  opcdAddToShortVarConstant        = opEnumType  0xD8, // Must be consecutive opcodes and op % 8 == 0
  opcdMinusToShortVarConstant      = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetMinusTo),
  opcdTimesToShortVarConstant      = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetTimesTo),
  opcdDivideToShortVarConstant     = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetDivideTo),
  opcdAndToShortVarConstant        = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetAndTo),
  opcdOrToShortVarConstant         = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetOrTo),
  opcdBitComplementShortVarConstant= opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetBitComplement),
  opcdModuloToShortVarConstant     = opEnumType (opcdAddToShortVarConstant + (ubyte) arithOffsetModuloTo), //0xDF

  //Unused                         = opEnumType  0xE0, // Obsolete opcode (no longer used by Robolab)
  //Unused                         = opEnumType  0xE1,
  opcdDebugSuspendResumeStep       = opEnumType  0xE2,
  opcdWriteDataBytesFlash					 = opEnumType  0xE3, // write flash memory
  opcdDebugSetBreakPoint           = opEnumType  0xE4,
  //Unused                         = opEnumType  0xE5, // store a variable to update in the display
  opcdGetDataBytesFlash						 = opEnumType  0xE6,
#if defined(hasTranscendentalSupport)
  opcdTranscendentalFunctions      = opEnumType  0xE7,
#endif
  opcdBreakpoint                   = opEnumType  0xE8,
  opcdPlayToneImmediate            = opEnumType  0xE9,
  //Unused                         = opEnumType  0xEA, // was opcdPlaySoundFile
  opcdBTLinkIO                     = opEnumType  0xEB,
  opcdNXTMessageIO                 = opEnumType  0xEC,
  opcdFileIO                       = opEnumType  0xED,
  opcdHSLinkIO                     = opEnumType  0xEE,
  opcdStringOps                    = opEnumType  0xEF,

  opcdAddToGenericParms            = opEnumType  0xF0, // Must be consecutive opcodes and op % 8     =    = 0
  opcdMinusToGenericParms          = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetMinusTo),
  opcdTimesToGenericParms          = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetTimesTo),
  opcdDivideToGenericParms         = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetDivideTo),
  opcdAndToGenericParms            = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetAndTo),
  opcdOrToGenericParms             = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetOrTo),
  opcdBitComplementGenericParms    = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetBitComplement),
  opcdModuloToGenericParms         = opEnumType (opcdAddToGenericParms + (ubyte) arithOffsetModuloTo), 

  //Unused                         = opEnumType  0xF8,
  //Unused                         = opEnumType  0xF9,
  //Unused                         = opEnumType  0xFA,
  //Unused                         = opEnumType  0xFB,
  opcdDebugSetProgramCounter       = opEnumType  0xFC,
  //Unused                         = opEnumType  0xFD,
  opcdReturn                       = opEnumType  0xFE,
  opcdErasedFlash                  = opEnumType  0xFF   // Erased flash is 0xFF. Catch this case.


#if defined(_WINDOWS)
  ,
  opcdBAD                          = 0x0100, // Not really used. Could be reallocated!!!

	//
	// Virtual opcodes thaqt are expanded into "system functions" or number type specific opcodes. They are not "real" opcodes
	// which must be in the range of 0..255
	//
	opcdAssign,
  opcdXorTo,
  opcdNegate,											// Unary Op
  opcdBitComplement,							// Unary Op
  opcdShiftLeftTo,
  opcdShiftRightTo,
  opcdAddTo,
  opcdMinusTo,
  opcdTimesTo,
  opcdDivideTo,
  opcdModuloTo,
  opcdAndTo,
  opcdOrTo,

	rcxFirst                         = 0,
  rcxLast                          = opcdOrTo // opcdBitComplement

#endif
} TVMOpcode;

#if !defined(_WINDOWS)
  //#define opcdBAD  ((TVMOpcode) 0x100) // May be something else

  #define rcxFirst ((TVMOpcode) 0)
  #define rcxLast  ((TVMOpcode) 0xFF)
#endif
//////////////////////////////////////////////////////////////////////////////////////////
//
//                              Definition of Serial Link Constants
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  UARTmsgIncludeNone        = 0x00,
  UARTmsgIncludePreample    = 0x01,
  UARTmsgIncludeComplements = 0x02,
  UARTmsgIncludeChecksum    = 0x04
} TUARTpreamble;

typedef enum
{
  kUARTdefaultSpeed  = 0x00, // 2400 38kHz, 50% duty cycle
  UART4800baud       = 0x01, // zero in bitfield is 2400 baud
  UART76KHz          = 0x02, // zero in bitfield is 38kHz
  UART25DutyCycle    = 0x04, // zero in bitfield is 50% duty cycle
  UARTSynchronous    = 0x08  // new add
} TUARTspeed;

typedef enum
{
  serialWaitForMessage      = 0,
  serialReceivingMessage    = 1,
  serialTransmitting        = 2,
  serialUnknown             = 3
} TSerialLinkStatus;




///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Sensor Modes
//
//////////////////////////////////////////////////////////////////////////////////////////////

typedef enum  // need the cast to 'opEnumType' (i.e. '(sbyte)') so Hitachi compiler will fit in a sbyte
{
  modeRaw           = opEnumType  (0 << 5), // 0x00
  modeBoolean       = opEnumType  (1 << 5), // 0x20
  modeEdgeCount     = opEnumType  (2 << 5), // 0x40
  modePulseCount    = opEnumType  (3 << 5), // 0x60
  modePercentage    = opEnumType  (4 << 5), // 0x80
  modeTemperatureC  = opEnumType  (5 << 5), // 0xA0
  modeTemperatureF  = opEnumType  (6 << 5), // 0xC0
  modeRotation      = opEnumType  (7 << 5), // 0xE0
  modeDummy         = opEnumType  0xFF
} TSensorModes;


//////////////////////////////////////////////////////////////////////////////////////////
//
//                              Definition of Event Constants
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  EST_SENSOR_1                = 0,
  EST_SENSOR_2,
  EST_SENSOR_3,
  EST_TIMER_1                 = 3,
  EST_TIMER_2,
  EST_TIMER_3,
  EST_TIMER_4,
  //EST_LAST_IR_MSG             = 7,
  //EST_COUNTER_1               = 8,
  //EST_COUNTER_2,
  //EST_COUNTER_3,
  EST_USER_EVENT_0            = 11,
  EST_USER_EVENT_1,
  EST_USER_EVENT_2,
  EST_USER_EVENT_3,
  EST_USER_EVENT_4            = 15,

  EST_VIRTUAL_MOTOR           = 16,// New.
  EST_VIRTUAL_SENSOR          = 17,
  EST_WAIT_FOR_MSG            = 18,
  EST_INFRARED_STATUS         = 19,

  EST_SENSORLastValid         = EST_INFRARED_STATUS,
  EST_SENSOR_UNUSED           = 20 // internal state. Indicates no eventType for this entry
} TEventSensorType;

#define kNumbOfEventSensorTypes (EST_SENSORLastValid + 1)

//
// Global "define" to disable / enable event handling
//

typedef enum
{
  eventTypePressed                  = 0,
  eventTypeReleased                 = 1,
  eventTypePeriod                   = 2,
  eventTypeTransition               = 3,

  eventType4                        = 4,   // Unused
  eventType5                        = 5,   // Unused
  eventType6                        = 6,   // Unused

  eventTypeVirtualMotorChange       = 4,   // New for virtual devices. Same as 'eventType4'
  eventTypeVirtualSensorDefinition  = 5,   // New for virtual devices. Same as 'eventType5'

  eventTypeExceedChangeRate         = 7,
  eventTypeEnterLow                 = 8,
  eventTypeEnterNormal              = 9,
  eventTypeEnterHigh                = 10,
  eventTypeClick                    = 11,
  eventTypeDoubleClick              = 12,
  eventTypeInfraredIdle             = 13,  // New
  eventTypeMailbox                  = 14,
  //unused 15
  eventTypeReset                    = 16 // this is reset command to clear
} TEventTypes;

typedef enum
{
  eventTypeMaskPressed            = (1), //(1 << eventTypePressed),
  eventTypeMaskReleased           = (1 << eventTypeReleased),
  eventTypeMaskPeriod             = (1 << eventTypePeriod),
  eventTypeMaskTransition         = (1 << eventTypeTransition),
  //unused 4
  //unused 5
  //unused 6
  eventTypeMaskExceedChangeRate   = (1 << eventTypeExceedChangeRate),
  eventTypeMaskEnterLow           = (1 << eventTypeEnterLow),
  eventTypeMaskEnterNormal        = (1 << eventTypeEnterNormal),
  eventTypeMaskEnterHigh          = (1 << eventTypeEnterHigh),
  eventTypeMaskClick              = (1 << eventTypeClick),
  eventTypeMaskDoubleClick        = (1 << eventTypeDoubleClick),
  //unused 13
  eventTypeMaskMailbox            = ((uword) 1 << eventTypeMailbox)
  //unused 15
} TEventTypeMasks;


typedef enum                  // constants are 'getValue' parameter. Do not change order
{
  eventStateBelowLowerThreshold,
  eventStateBetweenThresholds,
  eventStateAboveUpperThreshold,
  eventStateUndetermined,              // Not yet figured out or 'message' type
  //
  // For NQC Compatability
  //
  ES_BELOW_LOWER      = eventStateBelowLowerThreshold,
  ES_BETWEEN          = eventStateBetweenThresholds,
  ES_ABOVE_UPPER      = eventStateAboveUpperThreshold,
  ES_UNDETERMINED     = eventStateUndetermined
} TEventStates;


///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Display Types
//
//////////////////////////////////////////////////////////////////////////////////////////////



/*
typedef enum
{
  tInfraredAcceptAll       = 0,
  tInfraredAcceptUserOnly  = 1,     // Accept only user messages. Remainder are 'discarded'
  tInfraredDiscard         = 2,
  tInfraredLimitedDownload = 2
} TInfraredReceiveMode;
*/

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Exception Types
//
//////////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
  //
  // Don't mess with the numeric values without also changing the constants in assembler files.
  //
  exceptionNone                       = 0,
  exceptionSensorOutOfRange           = 1,
  exceptionMotorOutOfRange            = 2,
  exceptionTimerOutOfRange            = 3,
  exceptionEventOutOfRange            = 4,
  exceptionVariableOutOfRange         = 5,
  exceptionOutOfRange                 = 6,
  exceptionArrayOutOfRange            = 7,

  exceptionViewVariableOutofRange     = 8,

  exceptionStackOverflow              = 9,
  exceptionStackUnderflow             = 10,

  exceptionInvalidOpcode              = 11,

  exceptionReadOnlyParm               = 12,

  exceptionPCOutOfRange               = 13,

  exceptionShiftValueOutOfRange       = 14,

  exceptionInvalidSubroutine          = 15,
  exceptionInvalidSubroutineReturn    = 16,

  exceptionAssertFailure              = 17,
  exceptionParmOutOfRangeRead         = 18,
  exceptionSystemParmReadOutOfRange   = 19,
  exceptionValueOutOfRange            = 20,
  exceptionUartParmOutOfRange         = 21,
  exceptionSoundParmOutOfRange        = 22,
  exceptionTaskOutOfRange             = 23,
  exceptionInvalidLengthLongMessage   = 24,

  exceptionInvalidBreakpoint          = 25,
  exceptionWordReadOfLongParm         = 26,
  exceptionFloatNotSupported          = 27,
  exceptionLongNotSupported           = 28,
  exceptionBreakpoint                 = 29,
  exceptionSystemParmWriteOutOfRange  = 31,
  exceptionSystemParmExtOutOfRange    = 32,

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  exceptionBTRawModeError             = 33,
#endif
#if defined(ARMCPU) || defined(_WINDOWS)
  exceptionServoOutOfRange            = 34,
#endif

#if defined(ARMCPU) || defined(Simulator) || defined(_WINDOWS)
  exceptionFloatToShortOutOfRange     = 35,
  exceptionFloatToLongOutOfRange      = 36,
#endif

#if defined(bHasSemaphoreSupport) || defined(_WINDOWS)
  exceptionInvalidSemaphore						= 37,
#endif
  exceptionIllegalFloatCalculation    = 38,  // Float Calculation results in "NAN" (Not a Number) result
  exceptionInternalError              = 39,
  exceptionParmOutOfRangeWrite        = 40,  // Bad Opcode Source
  exceptionInvalidPConBranch          = 41,
  exceptionInvalidPConSubReturn       = 42,
  exceptionInvalidInternalQueues1     = 44,
  exceptionInvalidInternalQueues2     = 45,
  exceptionInvalidInternalQueues3     = 46,
  exceptionInvalidInternalQueues4     = 47,
  exceptionInvalidInternalQueues5     = 48,
  exceptionInvalidInternalQueues6     = 49,
  exceptionInvalidInternalQueues7     = 50,
  exceptionInvalidInternalQueues8     = 51,
  exceptionInvalidInternalQueues9     = 52,
  exceptionInvalidAnalogPort          = 53,
  exceptionInvalidEventListMap3       = 54,
  exceptionDatalogIndexError          = 55,
  exceptionDatalogRawNotImplemented   = 56,
  exceptionDatalogOverflow            = 57,
  exceptionInvalidDatalogSourceType   = 58,
  exceptionRealAddressOutOfRange      = 59,
  exceptionCannotUpdateSlaveSync      = 60,
  exceptionStringIndexOutOfRange      = 61,
  exceptionServoDisabled              = 62,
	exceptionMotorDisabled							= 63,
	exceptionInvalidSensorPortForMotor  = 64,
	exceptionInvalidSystemFunction			= 65,
	exceptionExecutionInstructionOutOfRange	= 66,

  exceptionUnknown                    = opEnumType 255
} TVMException;



#ifdef __cplusplus
  }
#endif

#endif
