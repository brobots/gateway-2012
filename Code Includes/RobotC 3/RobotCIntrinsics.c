////////////////////////////////////////////////////////////////////////////////////////////////
//
//                       Intrinsic Brick Instruction Implementations
//
// This file contains the detailed implementation code and definitions for
// RobotC intrinsics
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include "ProgramType.h"

typedef unsigned char ubyte;

//////////////////////////////////////////////////////////////////////////////////////////
//
// Definition to 'ROBOTC' compiler of unique built-in variables used by the byte-code interpreter
//
//////////////////////////////////////////////////////////////////////////////////////////

//
// Syntax Example,
//    'intrinsic variable'      -- Compiler directive to define an internal "intrinsic" variable "array".
//    'globalVar'               -- the variable name known to the compiler.
//    'opcdSourceVar'              -- the type of variable/parameter
//    'kNumbOfGlobalVariables'  -- the size of the 'array' for these variables. If this is not specified
//                                 then a non-array variable is being used. e.g. 'clock', or 'message'
//                                 and can be referred to by any value
//
//    Item can now be referenced in 'ROBOTC' code with 'globalVar[23]', 'globalVar[i]', ... format
//

//
//    Note: There is an internal compiler 'kludge' so than 'random' is referred to as 'random(int)'
//          using round instead of curly brackets. Can't declare random as a 'function' because
//          assignment is allowed to set the random seed. The trick is to let 'random' be a variable
//          but it is referenced with round instead of curly brackets.
//

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Task execution Control
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void hogCPU()             asm(opcdSystemFunctions, byte(sysFuncHogProcessor));
intrinsic void releaseCPU()         asm(opcdSystemFunctions, byte(sysFuncFreeProcessor));
intrinsic void abortTimeslice()     asm(opcdSystemFunctions, byte(sysFuncSwitchContext));

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                memset and memcpy
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void memcpy(void &pToBuffer, const void &pFromBuffer, const short nNumbOfBytes)
                      asm(opcdSystemFunctions, byte(sysFuncMemCpy),
                            variableRefRAM(pToBuffer),
                            variableRefRAM(pFromBuffer),
                            variable(nNumbOfBytes));

intrinsic void memmove(void &pToBuffer, const void &pFromBuffer, const short nNumbOfBytes)
                      asm(opcdSystemFunctions, byte(sysFuncMemMove),
                            variableRefRAM(pToBuffer),
                            variableRefRAM(pFromBuffer),
                            variable(nNumbOfBytes));

intrinsic void memset(void &pToBuffer, const short nValue, const short nNumbOfBytes)
                      asm(opcdSystemFunctions, byte(sysFuncMemSet),
                            variableRefRAM(pToBuffer),
                            variable(nValue),
                            variable(nNumbOfBytes));

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                "string" functions on byte arrays
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(hasStringSupport)

intrinsic void strcpy(void &pToBuffer, const void &pFromBuffer)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrCpy),
                          variableRefRAM(pToBuffer),
                          variableRefRAM(pFromBuffer));

intrinsic void strcpy(string &pToBuffer, const void &pFromBuffer)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNCpy),
                          variableRefRAM(pToBuffer),
                          variableRefRAM(pFromBuffer),
                          constantValue(20));

intrinsic void strncpy(byte &pToBuffer, const byte &pFromBuffer, const short nMaxBufferSize)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNCpy),
                          variableRefRAM(pToBuffer),
                          variableRefRAM(pFromBuffer),
                          variable(nMaxBufferSize));

intrinsic void strcat(string &sToString, const void &pFromBuffer)
                      asm(opcdSystemFunctions, byte(sysFuncStrNCat),
                            variableRefRAM(sToString),
                            variableRefRAM(pFromBuffer),
                            constantValue(20));   // 'string' variable is 20 bytes long

intrinsic void strcat(void &pToBuffer, const void &pFromBuffer)
                      asm(opcdSystemFunctions, byte(sysFuncStrCat),
                            variableRefRAM(pToBuffer),
                            variableRefRAM(pFromBuffer));

intrinsic void strncat(void &pToBuffer, const void &pFromBuffer, const short nMaxBufferSize)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNCat),
                          variableRefRAM(pToBuffer),
                          variableRefRAM(pFromBuffer),
                          variable(nMaxBufferSize));

intrinsic void strcatSingleChar(void &pToBuffer, const char cSingleChar)
                      asm(opcdSystemFunctions, byte(sysFuncStrCatSingleChar),
                            variableRefRAM(pToBuffer),
                            variable(cSingleChar));

intrinsic void strncatSingleChar(void &pToBuffer, const char cSingleChar, const short nMaxBufferSize)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNCatSingleChar),
                          variableRefRAM(pToBuffer),
                          variable(cSingleChar),
                          variable(nMaxBufferSize));

intrinsic short strcmp(void &pString1, const void &pString2)
                      asm(opcdSystemFunctions, byte(sysFuncStrCmp),
                            variableRefRAM(pString1),
                            variableRefRAM(pString2),
                            functionReturn);

intrinsic short strncmp(void &pString1, const void &pString2, const short nMaxBufferSize)
                      asm(opcdSystemFunctions, byte(sysFuncStrNCmp),
                            variableRefRAM(pString1),
                            variableRefRAM(pString2),
                            variable(nMaxBufferSize),
                            functionReturn);

intrinsic char strIndex(const string &sString, const int nIndex)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrIndex),
                          variableRefString(sString),
                          variable(nIndex),
                          functionReturn);


intrinsic void strTrim(string &sString)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNTrim),
                          variableRefString(sString),
													byte(opcdSourceConstant), byte(20), byte(0));

intrinsic void strTrim(char *pString)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrTrim),
                          variableRefByte(pString));

intrinsic void strTrimN(char *pString, const int nMaxBufferSize)
                      asm(opcdSystemFunctions,
                          byte(sysFuncStrNTrim),
                          variableRefByte(pString),
													variable(nMaxBufferSize));


#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                          Miscellaneous Variables and Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic word function(random,                             opcdSourceRandom,  0x08000);
#define srand(seed)                                         random[0] = seed
#define rand()                                              random[0x7FFF]

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  Program and Task Management Handling Opcodes
//
////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasStandardBatteryMonitoring)

  intrinsic word variableIndex(nImmediateBatteryLevel,				opcdSourceSystem, kSystemImmediateBatteryLevel);
  intrinsic word variableIndex(nAvgBatteryLevel,							opcdSourceSystem, kSystemAvgBatteryLevel);

#if defined(VEX2)
  intrinsic word variableIndex(BackupBatteryLevel,							opcdSourceSystem, kSystemBackupBatteryLevel);
#endif

	#if (defined(bHasSoftwareControlledPowerOnOff) && !defined(VEX2) && !defined(NXT))
		intrinsic word variableIndex(nShutdownVoltage,              opcdSourceSystem, kSystemShutdownVoltage);
	#endif


	#if defined(NXT) || defined(TETRIX)
		intrinsic bool variableIndex(bNxtRechargable,								opcdSourceSystem, kSystemNxtRechargable);
		intrinsic bool variableIndex(bNoPowerDownOnACAdaptor,				opcdSourceSystem, kSystemNoPowerDownOnACAdaptor);
		intrinsic word variableIndex(LowVoltageBatteryCountLimits,	opcdSourceSystem, kSystemLowVoltageBatteryCountLimits);
 #endif

#endif

#if defined(bHasSoftwareControlledPowerOnOff) || defined(Simulator)
	intrinsic word variableIndex(nPowerDownDelayMinutes,        opcdSourceSystem, kSystemPowerDownDelay);
	intrinsic word variableIndex(nPowerDownDelayMinutesDefault, opcdSourceSystem, kSystemPowerDownDelayDefault);
  intrinsic void powerOff()                                   asm(opcdSystemFunctions, byte(sysFuncPowerOFF));
#endif

#if defined(NXT) || defined(TETRIX)
 intrinsic word variableIndex(nDefaultStackSize,							opcdSourceSystem, kSystemDefaultTaskStackSize);
#endif



const int kLowPriority      = 0;    // lowestest priority
#undef kDefaultTaskPriority
const int kDefaultTaskPriority  = 7;    // default priority
const int kHighPriority     = 255;  // highest priority
intrinsic word variableIndex(nSchedulePriority,           opcdSourceSystem, kSystemTaskSchedulingPriority);

intrinsic const word variableIndex(version,               opcdSourceSystem, kSystemFirmwareVersion);

#if defined(VEX) || defined(VEX2)
intrinsic const word variableIndex(nVexMasterVersion,			opcdSourceSystem, kSystemIFIMasterVersion);
#endif


// Read only operating system parameters

intrinsic const word variableIndex(nCurrentTask,          opcdSourceSystem, kSystemCurrentTask)
intrinsic word variableIndex(nOpcodesPerTimeslice,        opcdSourceSystem, kSystemOpcodesPerTimeslice);

intrinsic const long variableIndex(pStartOfFlashFileHdr, opcdSourceSystem, kSystemStartOfFlashFileHeader);

#if defined(NXT) || defined(TETRIX)
	intrinsic void getFirmwareDate(string &sDate)						asm(opcdSystemFunctions, byte(sysFuncGetDate), variableRefString(sDate));
	intrinsic word variableIndex(nMaxDataFiles,							opcdSourceSystem, kSystemNxtMaxDataFileCount);
	intrinsic word variableIndex(nMaxDataFileSize,					opcdSourceSystem, kSystemNxtMaxDataFileSize);
	intrinsic word variableIndex(bHideDataFiles,						opcdSourceSystem, kSystemNxtHideDataFile);

	intrinsic word variableIndex(nNxtButtonTask,            opcdSourceSystem, kSystemNxtButtonTask);
	intrinsic word variableIndex(nNxtExitClicks,            opcdSourceSystem, kSystemNxtExitClicks);

	intrinsic TButtons variableIndex(nNxtButtonPressed,     opcdSourceSystem, kSystemNxtButtonPressed);
	intrinsic TButtons variableIndex(nNxtButtonTransition,  opcdSourceSystem, kSystemNxtButtonTransition);

	intrinsic word variableIndex(nI2CRetries,               opcdSourceSystem, kSystemNxtI2CRetries);
	intrinsic bool variableIndex(bI2CCheckAcks,             opcdSourceSystem, kSystemNxtI2CCheckACKs);
	intrinsic word variableIndex(nAvailFlash,               opcdSourceSystem, kSystemNxtAvailFlash);
#endif

#if defined(VEX)
  intrinsic ubyte variableIndex(nVEXDurationAutonomous,     opcdSourceSystem, kSystemVEXDurationAutonomous);
  intrinsic ubyte variableIndex(nVEXDurationUserControl,    opcdSourceSystem, kSystemVEXDurationUserControl);

  typedef enum
  {
    vrNoXmiters           = 0,    // No transmitters connected
    vrXmit1               = 1,    // Transmitter 1 connected
    vrXmit2               = 2,    // Transmitter 2 connected
    vrXmit1and2           = 3,    // Transmitter 1 & 2 connected
    vrNoCompetitionSwitch = 4,
    vrBit4                = 8,
  } TVexReceiverState;
  intrinsic const TVexReceiverState variableIndex(nVexRCReceiveState,   opcdSourceSystem, kSystemVEXRCReceiveState);

#elif defined(VEX2)

  typedef enum
  {
    vrNoXmiters           = 0,        // No transmitters connected
    vrXmit1               = 0x01,     //                          1 == Transmitter 1 connected
    vrXmit2               = 0x02,     //                          1 == Transmitter 2 connected
    vrBit2                = 0x04,     // Unused
    vrCompetitionSwitch   = 0x08,     // 0 == No Comp Switch      1 == Competition Switch attached.
		vrResetSlave					= 0x10,			// Unused
		vrGameController			= 0x20,     // 0 == Legacy75MHz,        1 == Game Controller
		vrAutonomousMode      = 0x40,     // 0 == Driver Control,     1 == Autonomous Mode
		vrDisabled      			= 0x80,     // 0 == Enabled             1 == Disabled.
  } TVexReceiverState;
  intrinsic const TVexReceiverState variableIndex(nVexRCReceiveState,   opcdSourceSystem, kSystemVEXRCReceiveState);
#endif

#if defined(VEX) || defined(VEX2)
  intrinsic const bool variableIndex(bVEXNETActive,   opcdSourceSystem, kSystemVEXNEXTActive);

  #define nVexPwmOwner        nIfiPwmOwner         // Backward compatibility with earlier VEX only
  #define nVexSPIMsgCounts    nIfiSPIMsgCounts     // Backward compatibility with earlier VEX only
  #define bVexAutonomousMode  bIfiAutonomousMode   // Backward compatibility with earlier VEX only

	intrinsic bool variableIndex(bIfiPwmOverride,											opcdSourceSystem, kSystemIFIPWMOverride);
	intrinsic const word variableIndex(nIfiSPIMsgCounts,							opcdSourceSystem, kSystemIFISPIMsgCounts);
  deprecated intrinsic const bool variableIndex(bIfiRobotDisabled,	opcdSourceSystem, kSystemIFIRobotDisabled);

#endif

#if defined(VEX)
  intrinsic word variableIndex(nIfiPwmOwner,                opcdSourceSystem, kSystemIFIPwmOwner);
  typedef enum
  {
  #if defined(VEX) || defined(VEX2)
    UserVEXBlackEye           = 0x01,  // Shuts off the EYE on VEX
  #endif
    UserAutonomous            = 0x02,  // Enables Autonomous Robot Operation
    UserPwmOverride           = 0x04,  // Enables User to control PWMs as well when transmitter is off
  #if defined(VEX) || defined(VEX2)
    UserLatchVEXAutonDuration = 0x08,  // when set 'nVEXDurationAutonomous'  is latched as autonomous interval data
    UserLatchVEXUserDuration  = 0x10,  // when set 'nVEXDurationUserControl' is latched as  the interval to terminate the match
  #endif
  } TUserCmds;
  intrinsic const TUserCmds variableIndex(nIfiUserCmd,							opcdSourceSystem, kSystemIFIUserCmd);
  intrinsic bool variableIndex(bIfiAutonomousMode,									opcdSourceSystem, kSystemIFIAutonomousMode);

#elif defined(VEX2)

  intrinsic const bool variableIndex(bIfiAutonomousMode,						opcdSourceSystem, kSystemIFIAutonomousMode);
  intrinsic bool variableIndex(bIfiAutonomousModeBySlave,						opcdSourceSystem, kSystemIFIAutonomousModeBySlave);
  intrinsic TProgramType variableIndex(nCurrCortexProgramType,		  opcdSourceSystem, kSystemCurrCortexProgramType);
  intrinsic TProgramType variableIndex(nNextCortexProgramType,		  opcdSourceSystem, kSystemNextCortexProgramType);
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//       Semaphore Support
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasSemaphoreSupport)

	typedef struct
	{
	  ubyte nOwningTask;
	  ubyte nLockCount;
	} TSemaphore;

  intrinsic void SemaphoreInitialize(TSemaphore &nSemaphore)
                asm(opcdSystemFunctions, byte(sysFuncSemaphoreInitialize), variable(nSemaphore));

  intrinsic void SemaphoreLock(TSemaphore &nSemaphore, const int waitTime = 0x7FFF)
                asm(opcdSystemFunctions, byte(sysFuncSemaphoreLock), variable(nSemaphore), variable(waitTime));

  intrinsic void SemaphoreUnlock(TSemaphore &nSemaphore)
                asm(opcdSystemFunctions, byte(sysFuncSemaphoreUnlock), variable(nSemaphore));

  #define getSemaphoreTaskOwner(nSemaphore) nSemaphore.nOwningTask

  #define bDoesTaskOwnSemaphore(nSemaphore) (nSemaphore.nOwningTask == nCurrentTask)

#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//       Interface to Optional IFI LCD Display and Buttons
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasFlashFileSystem)

	#if !defined(VEX) && !defined(NXT)
	  intrinsic int getStartupProgramIndex()
	                asm(opcdSystemFunctions, byte(sysFuncStartupProgramIndex), functionReturn);
	  intrinsic int getIdleTimeProgramIndex()
	                asm(opcdSystemFunctions, byte(sysFuncIdleTimeProgramIndex), functionReturn);
	#endif

	intrinsic int bValidFile(const int nFileIndex)
                asm(opcdSystemFunctions, byte(sysFuncValidFileIndex), variable(nFileIndex), functionReturn);

	#if !(defined(VEX))

		typedef enum word
		{
			ftNone              = 0,
			ftExecutable        = 1,

			ftSound             = 2,
			ftWAV								= 3,

			ftText              = 4,
			ftData              = 5,
			ftIcon              = 6,
			ftMIDI							= 7,
			ftLast
		} TFileExtensionTypes;

		intrinsic void deleteFile(const int nFileIndex)
		                asm(opcdSystemFunctions, byte(sysFuncDeleteFile), variable(nFileIndex));

		intrinsic TFileExtensionTypes getFileType(const int nFileIndex)
		                asm(opcdSystemFunctions, byte(sysFuncGetFileType), variable(nFileIndex), functionReturn);

		#if defined(hasStringSupport)
			intrinsic void getFileName(const int nFileIndex, string &sFileName)
											asm(opcdSystemFunctions, byte(sysFuncGetFileName), variable(nFileIndex), variableRefString(sFileName));
		#endif

  #endif

#endif

#if defined(hasUserSerialPorts)

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                       Optional User Control of Serial Port Two (VEX and ????)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef enum word
{
  uartOne     = 0,
  uartTwo     = 1,
  uartThree    = 2,
} TUARTs;

typedef enum word
{
	uartNotUsed					= 0,
	uartUserControl				= 1,
	uartVEXLCD					= 2,
	uartCMUCAM					= 3,
	uartSerialGPS				= 4,
	uartZigBee					= 5,
	uartIRobotCreate			= 6,
} TSerialPortMode;

intrinsic void configureSerialPort(const TUARTs nPort, TSerialPortMode nMode) asm(opcdSystemFunctions, byte(sysFuncConfigureSerialPort),
																																					variable(nPort),
																																					variable(nMode));

#include "BaudRates.h"

intrinsic void setBaudRate(const TUARTs nPort, TBaudRate nBaudRate)asm(opcdSystemFunctions, byte(sysFuncSerialSetBaudRate),
																																					variable(nPort),
																																					variable(nBaudRate));

intrinsic short getChar(const TUARTs nPort)                        asm(opcdSystemFunctions, byte(sysFuncSerialGetChar),
																																					variable(nPort),
																																					functionReturn);

intrinsic void sendChar(const TUARTs nPort, short nChar)           asm(opcdSystemFunctions, byte(sysFuncSerialSendChar),
																																					variable(nPort),
																																					variable(nChar));

intrinsic short bXmitComplete(const TUARTs nPort)                  asm(opcdSystemFunctions, byte(sysFuncSerialGetXmitComplete),
																																					variable(nPort),
																																					functionReturn);
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//       Interface to Optional IFI LCD Display and Buttons
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(hasLCDButtons) || defined(_WINDOWS)

	typedef enum
	{
		kButtonNone     = 0x00,
		kButtonLeft     = 0x01,
		kButtonCenter   = 0x02,
		kButtonRight    = 0x04,
		kButtonExit     = 0x08,
		kButtonExit2    = 0x10,
	} TControllerButtons;
	intrinsic const TControllerButtons variableIndex(nLCDButtons, opcdSourceSystem, kSystemLCDButtons);

#endif

#if defined(hasAlphaNumericLCDDisplayViaUART)

intrinsic word variableIndex(nLCDRefreshRate,             opcdSourceSystem, kSystemLCDRefreshRate);

#if defined(hasLCDBacklight)
	intrinsic bool variableIndex(bLCDBacklight,               opcdSourceSystem, kSystemLCDBacklight);
#endif

intrinsic void clearLCDLine(const int nLine)
                asm(opcdSystemFunctions, byte(sysFuncLCDClearLCDLine), variable(nLine));

intrinsic void displayLCDPos(const int nLine, const int nPos)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos));
intrinsic void setLCDPosition(const int nLine, const int nPos)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos));

intrinsic void displayFileName(const int nLine, const int nSlot)
                asm(opcdSystemFunctions, byte(sysFuncLCDDisplayProgramName), variable(nLine), variable(nSlot));

intrinsic void displayLCDChar(const int nLine, const int nPos, const int cChar)
                asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos),
								    opcdSystemFunctions, byte(sysFuncLCDPutNextChar), variable(cChar));
intrinsic void displayLCDNumber(const int nLine, const int nPos, const int nValue, const int nPrecision = -1)
                asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos),
								    opcdSystemFunctions, byte(sysFuncLCDPutNextShort), variable(nPrecision), variable(nValue));
intrinsic void displayLCDString(const int nLine, const int nPos, compileConst string sString)
							  asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos),
								    opcdSystemFunctions, byte(sysFuncLCDPutNextConstString), stringConstant(sString));

intrinsic void displayLCDCenteredString(const int nLine, compileConst string sString)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutCenteredConstString),
							      variable(nLine), stringConstant(sString));

intrinsic void displayNextLCDChar(const int cChar)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutNextChar), variable(cChar));
intrinsic void displayNextLCDNumber(const int nValue, const int nPrecision = 0x40)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutNextShort), variable(nPrecision), variable(nValue));
intrinsic void displayNextLCDString(compileConst string sString)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutNextConstString), stringConstant(sString));

#if defined(hasStringSupport)
intrinsic void displayLCDString(const int nLine, const int nPos, string sString)
							  asm(opcdSystemFunctions, byte(sysFuncLCDPosition), variable(nLine), variable(nPos),
								    opcdSystemFunctions, byte(sysFuncLCDPutNextString), variable(sString));

intrinsic void displayNextLCDString(string sString)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutNextString), variable(sString));

intrinsic void displayLCDCenteredString(const int nLine, string sString)
							 asm(opcdSystemFunctions, byte(sysFuncLCDPutCenteredString),
							      variable(nLine), variable(sString));
#endif

#endif //#if defined(hasAlphaNumericLCDDisplayViaUART)

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//       Interface to VEX RF Functions (standard VEX and Playstation Controller)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(VEX) || defined(VEX2)

	typedef enum word
	{
	//Channels                  Friendlier Name
		Ch1               = 0,    vexJSRightH       = 0,   // Channel 1
		Ch2               = 1,    vexJSRightV       = 1,   // Channel 2
		Ch3               = 2,    vexJSLeftV        = 2,   // Channel 3
		Ch4               = 3,    vexJSLeftH        = 3,   // Channel 4
		Ch5               = 4,    vexJSChannel5     = 4,   // Channel 5
		Ch6               = 5,    vexJSChannel6     = 5,   // Channel 6
		//
		// Second receiver / transmitter can also be (optionall) connected
		//
		Ch1Xmtr2          = 6,
		Ch2Xmtr2          = 7,
		Ch3Xmtr2          = 8,
		Ch4Xmtr2          = 9,
		Ch5Xmtr2          = 10,
		Ch6Xmtr2          = 11,

#if !defined(VEX)
		//
		// Button Bit Maps
		//
		//ButtonsXmtr1			= 12,
		//ButtonsXmtr2			= 13,

		Btn5D				= 14,
		Btn5U				= Btn5D +  1,
		Btn6D				= Btn5D +  2,
		Btn6U				= Btn5D +  3,

		Btn8D				= Btn5D +  4,
		Btn8L				= Btn5D +  5,
		Btn8U				= Btn5D +  6,
		Btn8R				= Btn5D +  7,

		Btn7D				= Btn5D +  8,
		Btn7L				= Btn5D +  9,
		Btn7U				= Btn5D + 10,
		Btn7R				= Btn5D + 11,

		Btn5DXmtr2				= 26,
		Btn5UXmtr2				= Btn5DXmtr2 +  1,
		Btn6DXmtr2				= Btn5DXmtr2 +  2,
		Btn6UXmtr2				= Btn5DXmtr2 +  3,

		Btn8DXmtr2				= Btn5DXmtr2 +  4,
		Btn8LXmtr2				= Btn5DXmtr2 +  5,
		Btn8UXmtr2				= Btn5DXmtr2 +  6,
		Btn8RXmtr2				= Btn5DXmtr2 +  7,

		Btn7DXmtr2				= Btn5DXmtr2 +  8,
		Btn7LXmtr2				= Btn5DXmtr2 +  9,
		Btn7UXmtr2				= Btn5DXmtr2 + 10,
		Btn7RXmtr2				= Btn5DXmtr2 + 11,

		AccelX       = 38,
		AccelY       = AccelX + 1,
		AccelZ       = AccelX + 2,

		AccelXXmtr2       = 41,
		AccelYXmtr2       = AccelXXmtr2 + 1,
		AccelZXmtr2       = AccelXXmtr2 + 2,
#endif
    kNumbOfVexRFIndices,
	} TVexJoysticks;

	const int kNumbOfVexRFJoysticks   = 14;   // deprecated

  typedef enum
	{
		btn5D             = 0x0001,    // Button Group 5, Up
		btn5U             = 0x0002,    // Button Group 5, Down
		btn6D             = 0x0004,    // Button Group 6, Up
		btn6U             = 0x0008,    // Button Group 6, Down

		btn7D             = 0x0100,    // Button Group 7, Down
		btn7L             = 0x0200,    // Button Group 7, Up
		btn7U             = 0x0400,    // Button Group 7, Left
		btn7R             = 0x0800,    // Button Group 7, Right

		btn8D             = 0x0010,    // Button Group 8, Down
		btn8L             = 0x0020,    // Button Group 8, Up
		btn8U             = 0x0040,    // Button Group 8, Left
		btn8R             = 0x0080     // Button Group 8, Right
	} TButtonMasks;

intrinsic const word variable(vexRT,     opcdSourceIFIRadioControl,        kNumbOfVexRFIndices, TVexJoysticks);
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  NXT LCD Display Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasLCDContrast)
  intrinsic short variableIndex(nLCDContrast,           opcdSourceSystem, kSystemLCDContrast);
	intrinsic short variableIndex(nLCDContrastDefault,    opcdSourceSystem, kSystemLCDDefaultContrast);
#endif

#if defined(bHasLCDGraphicsDisplay) || defined(NXT)

#if defined(NXT) || defined(TETRIX)
  intrinsic bool variableIndex(bNxtLCDStatusDisplay,    opcdSourceSystem, kSystemNxtLCDStatusDisplay);
#endif

#if defined(bHasRemoteButtons) || defined(_WINDOWS)
  intrinsic short variableIndex(nRemoteButton,					opcdSourceSystem, kSystemRemoteButton);
#endif

intrinsic void eraseDisplay()                       asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawEraseScreen));

intrinsic void nxtDisplayString(const int nLineNumber, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawStringVarArgs),
                                variable(nLineNumber),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayString(const int nLineNumber, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtDisplayTextLine(const int nLineNumber, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayTextLine(const int nLineNumber, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtDisplayBigTextLine(const int nLineNumber, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawBigTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayBigTextLine(const int nLineNumber, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawBigTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(sFormatString),
                                varArgList);

#define nxtDisplayClearTextLine(nLineNumber)     nxtDisplayTextLine(nLineNumber, "")

intrinsic void nxtDisplayCenteredTextLine(const int nLineNumber, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawCenteredTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayCenteredTextLine(const int nLineNumber, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawCenteredTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtDisplayCenteredBigTextLine(const int nLineNumber, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawCenteredBigTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayCenteredBigTextLine(const int nLineNumber, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawCenteredBigTextLineVarArgs),
                                variable(nLineNumber),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtDisplayStringAt(const int xPos, const int yPos, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawStringAtCoordVarArgs),
                                variable(xPos), variable(yPos),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayStringAt(const int xPos, const int yPos, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawStringAtCoordVarArgs),
                                variable(xPos), variable(yPos),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtDisplayBigStringAt(const int xPos, const int yPos, char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawBigStringAtCoordVarArgs),
                                variable(xPos), variable(yPos),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtDisplayBigStringAt(const int xPos, const int yPos, string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawBigStringAtCoordVarArgs),
                                variable(xPos), variable(yPos),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void nxtScrollText(char *pChar, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawScrollTextVarArgs),
                                variableRefString(pChar),
                                varArgList);

intrinsic void nxtScrollText(string sFormatString, ...)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawScrollTextVarArgs),
                                variableRefString(sFormatString),
                                varArgList);


intrinsic void nxtSetPixel(const int xPos, const int yPos)    asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawSetPixel), variable(xPos), variable(yPos));
intrinsic void nxtClearPixel(const int xPos, const int yPos)  asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawClearPixel), variable(xPos), variable(yPos));

intrinsic void nxtDrawLine(const int xPos, const int yPos, const int xPosTo, const int yPosTo)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawLine),  variable(xPos), variable(yPos), variable(xPosTo), variable(yPosTo));

intrinsic void nxtEraseLine(const int xPos, const int yPos, const int xPosTo, const int yPosTo)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawEraseLine),  variable(xPos), variable(yPos), variable(xPosTo), variable(yPosTo));

intrinsic void nxtInvertLine(const int xPos, const int yPos, const int xPosTo, const int yPosTo)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawInvertLine),  variable(xPos), variable(yPos), variable(xPosTo), variable(yPosTo));

intrinsic void nxtDisplayRICFile(const int nleft, const int nBottom, const string sFileName)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawRICFile),
                                        variable(nleft), variable(nBottom),
                                        variableRefFNExists(sFileName));

intrinsic void nxtDrawEllipse(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawEllipse),  variable(Left), variable(Top), variable(Right), variable(Bottom));

#define nxtDrawCircle(Left, Top, Diameter) nxtDrawEllipse(Left, Top, Left + Diameter - 1, Top - Diameter - 1)

intrinsic void nxtFillEllipse(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawFillEllipse),  variable(Left), variable(Top), variable(Right), variable(Bottom));
intrinsic void nxtEraseEllipse(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawEraseEllipse),  variable(Left), variable(Top), variable(Right), variable(Bottom));
intrinsic void drawInvertEllipse(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawInvertEllipse),  variable(Left), variable(Top), variable(Right), variable(Bottom));

intrinsic void nxtDrawRect(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawRect),  variable(Left), variable(Top), variable(Right), variable(Bottom));
intrinsic void drawInvertRect(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawInvertRect),  variable(Left), variable(Top), variable(Right), variable(Bottom));
intrinsic void nxtEraseRect(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawEraseRect), variable(Left), variable(Top), variable(Right), variable(Bottom));
intrinsic void nxtFillRect(const int Left, const int Top, const int Right, const int Bottom)
                asm(opcdDrawOnGraphicsLCDDisplay, byte(displayDrawFillRect), variable(Left), variable(Top), variable(Right), variable(Bottom));

#endif


#if defined(AVRCPU)
  intrinsic uword variableIndex(nLCDRefreshCycles, opcdSourceSystem,    kSystemLCDRefreshCycles);
#endif

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                         Timer Handling Opcodes and Variables
//
////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(NXT) || defined(TETRIX) || defined(VEX2) || defined(ARM) || defined(SX256)
	intrinsic const long variableIndex(nSysTime,     opcdSourceSystem,        kSystemSysTime);
	intrinsic const long variableIndex(nPgmTime,     opcdSourceSystem,        kSystemPgmTime);
#else
	intrinsic const word variableIndex(nSysTime,     opcdSourceSystem,        kSystemSysTime);
	intrinsic const word variableIndex(nPgmTime,     opcdSourceSystem,        kSystemPgmTime);
#endif

intrinsic word variableIndex(nClockMinutes,        opcdSourceSystem,        kSystemClockMinutes);

typedef enum word
{
  T1          = 0,
  T2          = 1,
  T3          = 2,
  T4          = 3
} TTimers;

#if defined(NXT) || defined(TETRIX)  || defined(VEX2) || defined(ARM)
	intrinsic long variable(time1,                   opcdSource1MsecTimer,    kNumbOfTimers, TTimers);  //   1 milli-second tick timer
	intrinsic long variable(time10,                  opcdSource10MsecTimer,   kNumbOfTimers, TTimers);  //  10 milli-second tick timer
	intrinsic long variable(time100,                 opcdSource100MsecTimer,  kNumbOfTimers, TTimers);  // 100 milli-second tick timer  intrinsic word variable(time1,                   opcdSource1MsecTimer,    kNumbOfTimers, TTimers);  //   1 milli-second tick timer
#else
	intrinsic word variable(time1,                   opcdSource1MsecTimer,    kNumbOfTimers, TTimers);  //   1 milli-second tick timer
	intrinsic word variable(time10,                  opcdSource10MsecTimer,   kNumbOfTimers, TTimers);  //  10 milli-second tick timer
	intrinsic word variable(time100,                 opcdSource100MsecTimer,  kNumbOfTimers, TTimers);  // 100 milli-second tick timer
#endif

intrinsic void ClearTimer(TTimers theTimer)								asm(opcdSystemFunctions, sysFuncClearTimer, variable(theTimer));
intrinsic void wait10Msec(const int nTenMSec)             asm(opcdWaitTimer10MSec, variable(nTenMSec));
intrinsic void wait1Msec(const int nMSec)                 asm(opcdWaitTimer1MSecShort, variable(nMSec));
intrinsic void wait1Msec(const long nMSec)                asm(opcdWaitTimer1MSecLong, variable(nMSec));

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                         Sound Handling Opcodes
//
////////////////////////////////////////////////////////////////////////////////////////////////

// Sound playback variables

#if defined(bHasSoundSupport)

  #if defined(bHasSoundVolume)
	  const int kMaxVolumeLevel = 4;
	  intrinsic word variableIndex(nVolume,                     opcdSourceSystem, kSystemVolume);
	#endif

	intrinsic const bool variableIndex(bSoundActive,          opcdSourceSystem, kSystemBOOLSoundPlaying);
	intrinsic word variableIndex(bPlaySounds,                 opcdSourceSystem, kSystemPlaySounds);
	intrinsic const bool variableIndex(bSoundQueueAvailable,  opcdSourceSystem, kSystemSoundQueueHasFreeEntries);

	#if defined(bHasSoundDriverOnOff)
	  intrinsic bool variableIndex(bHasSoundDriver,             opcdSourceSystem, kSystemSoundDriverOnOff);
	#endif

	intrinsic void PlayTone(const int frequency,  const int durationIn10MsecTicks)
	                asm(opcdPlayToneVarDurationVar, variable(frequency), variable(durationIn10MsecTicks));
	intrinsic void PlayImmediateTone(const int frequency, const int durationIn10MsecTicks)
	                asm(opcdPlayToneImmediate,  variable(frequency), variable(durationIn10MsecTicks));

	intrinsic void PlaySound(TSounds sound)                   asm(opcdSystemFunctions, byte(sysFuncPlaySound), variable(sound));
  intrinsic void ClearSounds()                              asm(opcdSystemFunctions, byte(sysFuncClearSound));
  #define MuteSound()                  bPlaySounds = false
  #define UnmuteSound()                bPlaySounds = true

  #if defined(bHasSoundFiles)
	  intrinsic void PlaySoundFile(const string &sFileName)     asm(opcdSystemFunctions, sysFuncPlaySoundFileVariableName, variableRefFNExists(sFileName));
	#endif

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                               Sensor Handling Opcodes and Variables
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if (1)

  // the actual 'enum' values for 'tSensors' are automatically defined internally by the ROBOTC compiler. Each platform
  // and circuit board type has its own set of "enum names" and it was becoming too hard to manage them in
  // this file. So they are automatically configured by the compiler which has better utilities for managing
  // differences between platform types.

  typedef enum tSensors;

#else

	#if defined(NXT) || defined(TETRIX)

		typedef enum
		{
		  S1    = 0,
		  S2    = 1,
		  S3    = 2,

		  S4    = 3,    // virtual sensors for external MUXes
		  S5,
		  S6
		} tSensors;

	#elif defined(VEX) || defined(STM3210E) || defined(VEXPro) || defined(Generic)

		typedef enum
		{
		  in1    =  0,
		  in2    =  1,
		  in3    =  2,
		  in4    =  3,
		  in5    =  4,
		  in6    =  5,
		  in7    =  6,
		  in8    =  7,
		  in9    =  8,
		  in10   =  9,
		  in11   = 10,
		  in12   = 11,
		  in13   = 12,
		  in14   = 13,
		  in15   = 14,
		  in16   = 15
		} tSensors;

	#elif defined(ArduinoSmallMemory)

		typedef enum
		{
		  //
		  // Analog I/O Ports: light, line follower, gyro, accelerometer,
		  //
		  anlg0     =  0,
		  anlg1     =  1,
		  anlg2     =  2,
		  anlg3     =  3,
		  anlg4     =  4,
		  anlg5     =  5,

		  dgtl0,
		  dgtl1,
		  dgtl2,
		  dgtl3,
		  dgtl4,
		  dgtl5,
		  dgtl6,
		  dgtl7,
		  dgtl8,
		  dgtl9,
		  dgtl10,
		  dgtl11,
		  dgtl12,
		  dgtl13,
		} tSensors;

	#elif defined(ArduinoMega)

		typedef enum
		{
		  //
		  // Analog I/O Ports, light, line follower, gyro, accelerometer,
		  //
		  anlg0     =  0,
		  anlg1     =  1,
		  anlg2     =  2,
		  anlg3     =  3,
		  anlg4     =  4,
		  anlg5     =  5,
		  anlg6     =  6,
		  anlg7     =  7,
		  anlg8     =  8,
		  anlg9     =  9,
		  anlg10    =  10,
		  anlg11    =  11,
		  anlg12    =  12,
		  anlg13    =  13,
		  anlg14    =  14,
		  anlg15    =  15,

		  dgtl0     =  16,
		  dgtl1     =  17,
		  dgtl2     =  18,
		  dgtl3     =  19,
		  dgtl4     =  20,
		  dgtl5     =  21,
		  dgtl6     =  22,
		  dgtl7     =  23,
		  dgtl8     =  24,
		  dgtl9     =  25,
		  dgtl10    =  26,
		  dgtl11    =  27,
		  dgtl12    =  28,
		  dgtl13    =  29,
		  dgtl14    =  30,
		  dgtl15    =  31,
		  dgtl16    =  32,
		  dgtl17    =  33,
		  dgtl18    =  34,
		  dgtl19    =  35,
		  dgtl20    =  36,
		  dgtl21    =  37,
		  dgtl22    =  38,
		  dgtl23    =  39,
		  dgtl24    =  40,
		  dgtl25    =  41,
		  dgtl26    =  42,
		  dgtl27    =  43,
		  dgtl28    =  44,
		  dgtl29    =  45,
		  dgtl30    =  46,
		  dgtl31    =  47,
		  dgtl32    =  48,
		  dgtl33    =  49,
		  dgtl34    =  50,
		  dgtl35    =  51,
		  dgtl36    =  52,
		  dgtl37    =  53,
		  dgtl38    =  54,
		  dgtl39    =  55,
		  dgtl40    =  56,
		  dgtl41    =  57,
		  dgtl42    =  58,
		  dgtl43    =  59,
		  dgtl44    =  60,
		  dgtl45    =  61,
		  dgtl46    =  62,
		  dgtl47    =  63,
		  dgtl48    =  64,
		  dgtl49    =  65,
		  dgtl50    =  66,
		  dgtl51    =  67,
		  dgtl52    =  68,
		  dgtl53    =  69,
		} tSensors;

	#elif defined(VEX2)

		typedef enum
		{
		  //
		  // Analog I/O Ports: light, line follower, gyro, accelerometer,
		  //
		  in1    =  0,
		  in2    =  1,
		  in3    =  2,
		  in4    =  3,
		  in5    =  4,
		  in6    =  5,
		  in7    =  6,
		  in8    =  7,

		  //
		  // Digital I/O Ports: Touch sensors, sonar, etc
		  //
		  dgtl1  = 8,
		  dgtl2  = 9,
		  dgtl3  = 10,
		  dgtl4  = 11,
		  dgtl5  = 12,
		  dgtl6  = 13,
		  dgtl7  = 14,
		  dgtl8  = 15,
		  dgtl9  = 16,
		  dgtl10 = 17,
		  dgtl11 = 18,
		  dgtl12 = 19,

		} tSensors;

	#else

	  typedef short tSensors;

	#endif

#endif

#if defined(NXT) || defined(TETRIX)
  //
	// LEGO RGB Color Sensor support
	//
  intrinsic short validColorSensor(const tSensors nPort)     asm(opcdSystemFunctions, sysFuncGetValidColorSensor, variable(nPort), functionReturn);

  //
	// Use for "sensorColorFull" sensors to copy the values for each of the four colors (none, R, G, B)
	// Input parameter is used to select "ADRaw", "Raw" (calibrated by sensor), and final per cent value
	//

	typedef enum
	{
	  BLACKCOLOR   = 1,
	  BLUECOLOR    = 2,
	  GREENCOLOR   = 3,
	  YELLOWCOLOR  = 4,
	  REDCOLOR     = 5,
	  WHITECOLOR   = 6
	} TColors;

  typedef enum
	{
		colorAtoD				= 0,
		colorRaw        = 1,
		colorValue      = 2
	} TColorDataType;

  intrinsic void getColorSensorData(const tSensors nPort, TColorDataType nDataType, short *pData)
                      asm(opcdSystemFunctions, sysFuncGetColorSensorValues, variable(nPort), variable(nDataType), variableRefRAM(pData));

	typedef struct
	{
		long nDisconnects;						// Incremented once when sensor detection (see nWaitForConnect) fails after sensor has
																	// been connected.
		long nSoftwareResets;         // Another pin on sensor indicates internal error condition. Incremented once per erro.
		long nCRCMismatch;            // 50 bytes are uploaded from sensor on startup. A CRC-code is used to detect errors.
																	// Peg count incremented once for each time failure is detected.
		long nWaitForConnect;					// Counts the number of times the sensor is not detected. There's an I/O pin on the
																	// sensor cable indicating whether sensor is working OK. This peg count is incremented
																	// every millisecond when not connected when it is supposed to be connected. Usually
																	// triggered by removing the sensor in mid-operation.
		long nReadCount;              // Not an error! A count of the number of times data is read from the sensor.
	} TColorPegCounts;

  intrinsic void getColorSensorPegCounts(const tSensors nPort, TColorPegCounts *pData)
                      asm(opcdSystemFunctions, sysFuncGetColorSensorCounts, variable(nPort), variableRefRAM(pData));


#endif

#if defined(NXT) || defined(TETRIX)
intrinsic short getSensorRawADValue(const tSensors nPort)     asm(opcdSystemFunctions, sysFuncGetRawADValue, variable(nPort), functionReturn);
#endif

#if (defined(bHasFastSonarSensor) && defined(includeSonarSensorSupport))
  intrinsic bool variableIndex(bFastSonarSensor,   opcdSourceSystem, kSystemFastSonarSensor);
#endif

intrinsic word variable(SensorValue,              opcdSourceSensor,         kNumbOfTotalSensors, tSensors);
intrinsic TSensorTypes variable(SensorType,       opcdSourceSensorType,     kNumbOfTotalSensors, tSensors);

#if defined(bHasSourceTypeSensorMode)
	intrinsic TSensorModes variable(SensorMode,       opcdSourceSensorMode,     kNumbOfTotalSensors, tSensors);
#endif

#if defined(bHasSourceTypeSensorRawValue)
	intrinsic word variable(SensorRaw,                opcdSourceSensorRaw,      kNumbOfTotalSensors, tSensors);
#endif

#if defined(NXT) || defined(TETRIX)
intrinsic word variable(SensorSubType,            opcdSourceNxtSensorSubType, kNumbOfTotalSensors, tSensors);
#endif

#if defined(bHasSensorBiasSettings)
intrinsic word variable(SensorBias,               opcdSourceSensorBias,     kNumbOfTotalSensors, tSensors);
intrinsic word variable(SensorScale,              opcdSourceSensorScale,    kNumbOfTotalSensors, tSensors);
intrinsic word variable(SensorFullCount,          opcdSourceSensorFullCount,kNumbOfTotalSensors, tSensors);
#endif

intrinsic const word variable(SensorBoolean,      opcdSourceSensorBoolean,  kNumbOfTotalSensors, tSensors);

#if defined(VEX)
intrinsic word variable(ifiInterruptPorts,           opcdSourceIfiInterruptPort, kNumbOfTotalSensors, tSensors);
#endif

#if defined(VEX)
intrinsic int variableIndex(nAnalogChannelCount,    opcdSourceSystem,           kSystemVEXAnalogChannelCount);
#endif


#if defined(NXT) || defined(TETRIX)
intrinsic word variableIndex(nVirtualSensorTypeChanges,   opcdSourceSystem, kSystemVirtualSensorTypeChanges);
intrinsic word variableIndex(nVirtualSensorModeChanges,   opcdSourceSystem, kSystemVirtualSensorModeChanges);
#endif


#define SetSensorType(nSensorX, nType) SensorType[nSensorX] = nType
#define SetSensorMode(nSensorX, nMode) SensorMode[nSensorX] = nMode

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                         Motor Handling Opcodes
//
////////////////////////////////////////////////////////////////////////////////////////////////

#if (1)

  // the actual 'enum' values for 'tMotor' are automatically defined by the ROBOTC compiler. Each platform
  // and circuit board type has its own set of "enum names" and it was becoming too hard to manage them in
  // this file. So they are automatically configured by the compiler which has better utilities for managing
  // differences between platform types.

  typedef enum tMotor;

#else

	// The old definitions are temporarily maintained here as well until the new implementation is confirmed
  // to be working well!

  #if defined(NXT) || defined(TETRIX)

		typedef enum
		{
		  motorA					= 0,
		  motorB					= 1,
		  motorC					= 2,
			//
			// HiTechnic Motor Controllers.
			//    - Each controller supports two motors
			//    = Up to four controllers per sensor port.
			//
			//motorD					=  3,
		  //motorE,

			mtr_S1_C1_1     =  3,
		  mtr_S1_C1_2,
		 	mtr_S1_C2_1,
		  mtr_S1_C2_2,
		  mtr_S1_C3_1,
		  mtr_S1_C3_2,
		  mtr_S1_C4_1,
		  mtr_S1_C4_2,

		  mtr_S2_C1_1,
		  mtr_S2_C1_2,
		 	mtr_S2_C2_1,
		  mtr_S2_C2_2,
		  mtr_S2_C3_1,
		  mtr_S2_C3_2,
		  mtr_S2_C4_1,
		  mtr_S2_C4_2,

		  mtr_S3_C1_1,
		  mtr_S3_C1_2,
		 	mtr_S3_C2_1,
		  mtr_S3_C2_2,
		  mtr_S3_C3_1,
		  mtr_S3_C3_2,
		  mtr_S3_C4_1,
		  mtr_S3_C4_2,

		  mtr_S4_C1_1,
		  mtr_S4_C1_2,
		 	mtr_S4_C2_1,
		  mtr_S4_C2_2,
		  mtr_S4_C3_1,
		  mtr_S4_C3_2,
		  mtr_S4_C4_1,
		  mtr_S4_C4_2,
		} tMotor;

	#elif defined(VEX) || defined(VEX2)

		typedef enum// Specifies a single motor
		{
		  port1         = 0,
		  port2         = 1,
		  port3         = 2,
		  port4         = 3,
		  port5         = 4,
		  port6         = 5,
		  port7         = 6,
		  port8         = 7,
		#if defined(VEX2) || defined(VEXPro)
		  port9         = 8,
		  port10        = 9,
		#endif
		} tMotor;

	#elif defined(AVRCPU) || defined(Generic)

		typedef enum// Specifies a single motor
		{
		  motor0        = 0,
		  motor1        = 1,
		  motor2        = 2,
		  motor3        = 3,
		  motor4        = 4,
		  motor5        = 5,
		} tMotor;

	#endif

#endif

intrinsic word variable(motor,                      opcdSourceMotorPower, kNumbOfTotalMotors, tMotor);
#define motorPowerSigned motor

#if defined(NXT) || defined(TETRIX)
intrinsic word variable(motorPWMLevel,              opcdSourceMotorPWM,   kNumbOfTotalMotors, tMotor);
#endif

#if defined(bMotorMirroring) || defined(_WINDOWS)
	intrinsic bool variable(bMotorReflected,            opcdSourceMotorReflectDirection, kNumbOfTotalMotors, tMotor);
	#define bMotorFlippedMode bMotorReflected
#endif

#if defined(bAssociateMotorWithEncoder)
	intrinsic void mapEncoderToMotor(compileConst tMotor nMotorIndex, compileConst tSensors nSensorIndex)
								 asm(opcdSystemFunctions, byte(sysFuncMapEncoderToMotor), byte(nMotorIndex), byte(nSensorIndex));
	intrinsic tSensors getEncoderForMotor(compileConst tMotor nMotorIndex)
								 asm(opcdSystemFunctions, byte(sysFuncGetEncoderForMotor), variable(nMotorIndex), functionReturn);
#endif

#if defined(bAssociateMotorWithEncoder) || defined(bSmartMotorsWithEncoders)
  intrinsic long variable(nMotorEncoder,                  opcdSourceMotorEncoder, kNumbOfTotalMotors, tMotor);
#endif

#if  defined(bHasFloatDuringInactivePWM)
	intrinsic bool variableIndex(bFloatDuringInactiveMotorPWM,opcdSourceSystem, kSystemFloatDuringInactiveMotorPWM);
#endif

#if defined(NXT) || defined(TETRIX)
intrinsic word variableIndex(nVirtualMotorChanges,        opcdSourceSystem, kSystemVirtualMotorChanges);
#endif

#if defined(TETRIX)

  typedef enum TServoIndex;

	const int kNumbOfServos = 4 * 6 * 6;

	intrinsic const short variable(ServoType,								  opcdSourceServoType,				    kNumbOfServos, TServoIndex);
	intrinsic const short variable(ServoValue,								opcdSourceServoPosition,				kNumbOfServos, TServoIndex);
	intrinsic short variable(servoChangeRate,							    opcdSourceServoRateOfChange,		kNumbOfServos, TServoIndex);
	intrinsic short variable(servoMinPos,											opcdSourceServoMinPos,					kNumbOfServos, TServoIndex);
	intrinsic short variable(servoMaxPos,											opcdSourceServoMaxPos,					kNumbOfServos, TServoIndex);

  intrinsic const short variableIndex(externalBattery,			opcdSourceSystem, kSystemBatteryLevelExternal);
  intrinsic const short variableIndex(externalBatteryAvg,		opcdSourceSystem, kSystemAvgBatteryLevelExternal);
  intrinsic word variableIndex(muxUpdateInterval,					  opcdSourceSystem, kSystemFtcHubUpdateInterval);
  intrinsic word variableIndex(muxLowBatteryShutdown,				opcdSourceSystem, kSystemBatteryShutdownExternal);
	intrinsic short variable(servo,									          opcdSourceServoTarget,					kNumbOfRealServos, TServoIndex);
  #define servoTarget  servo  // Retain for legacy purposes.
#endif


#if defined(bSmartMotorsWithEncoders)

typedef enum
{
  mtrNoReg,
  mtrSpeedReg,
  mtrSyncRegMaster,
  mtrSyncRegSlave,
  mtrEncoderReg
} TMotorRegulation;

typedef enum
{
  runStateIdle         = 0x00,  // published IOMAP value. do not change
  runStateRampUp       = 0x10,  // published IOMAP value. do not change
  runStateRunning      = 0x20,  // published IOMAP value. do not change
  runStateRampDown     = 0x40,  // published IOMAP value. do not change
  runStateHoldPosition = 0x01,   // Dick's add. Can be any value.
} TNxtRunState;

intrinsic long variable(nMotorEncoderTarget,            opcdSourceMotorTargetEncoder, kNumbOfTotalMotors, tMotor);
intrinsic TMotorRegulation variable(nMotorPIDSpeedCtrl, opcdSourceMotorRegulation, kNumbOfTotalMotors, tMotor);
intrinsic TNxtRunState variable(nMotorRunState,         opcdSourceMotorRunState, kNumbOfTotalMotors, tMotor);


intrinsic void changeSpeedRampingParms(short nMotorIndex,
																				short nMinimumRampStartUpSpeed,
																				short nRampStartupChangeRate,
																				short nMinimumRampDownSpeed,
																				short nRampDownChangeRate)
										asm(opcdSystemFunctions, sysFuncMotorRampingParms,
																				variable(nMotorIndex),
																				variable(nMinimumRampStartUpSpeed),
																				variable(nRampStartupChangeRate),
																				variable(nMinimumRampDownSpeed),
																				variable(nRampDownChangeRate));

#endif

#if defined(NXT) || defined(TETRIX)

	intrinsic word variableIndex(nMaxRegulatedSpeedNxt,     opcdSourceSystem, kSystemMaxRegulatedSpeedCountsPerSecondNxt);
	intrinsic word variableIndex(nMaxRegulatedSpeed12V,     opcdSourceSystem, kSystemMaxRegulatedSpeedCountsPerSecond12V);
	intrinsic word variableIndex(nPidUpdateInterval,				opcdSourceSystem, kSystemPidUpdateIntervalInMsecsNxt);
	#define nPidUpdateIntervalNxt nPidUpdateInterval
	intrinsic word variableIndex(nPidUpdateInterval12V,     opcdSourceSystem, kSystemPidUpdateIntervalInMsecs12V);
	intrinsic TSynchedMotors variableIndex(nSyncedMotors,   opcdSourceSystem, kSystemNxtSynchMotors);
	intrinsic word variableIndex(nSyncedTurnRatio,          opcdSourceSystem, kSystemNxtSynchSlaveSpeedRatio);



	intrinsic variableIndex(nMotorBeingTrace, opcdSourceSystem, kSystemMotorBeingTraced);

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            Memory Management and Procedure / Task Management Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic word variableIndex(programNumber,                   opcdSourceSystem, kSystemProgramNumb);
#define setProgramNumber(nNumber) programNumber = nNumber

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            Data Logging
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasDatalog)
intrinsic void AddToDatalog(const int data)                       asm(opcdDatalogNext, variable(data));
intrinsic void UploadDatalog(compileConst int nStart, compileConst int nSize)
                                      asm(opcdMsgUploadCommands, uploadDatalog, word(nStart), word(nSize));

intrinsic       word variableIndex(nDatalogSize,          opcdSourceSystem, kSystemDatalogSize);
intrinsic const word variableIndex(nUsedDatalogBytes,     opcdSourceSystem, kSystemUsedDatalogBytes);

#if defined(NXT) || defined(TETRIX)
intrinsic void AddToDatalog(const long data)                           asm(opcdDatalogNext, variable(data));
//intrinsic void AddToDatalog(const int nDataPtIndex, const int nDataValue)  asm(opcdSystemFunctions, byte(sysFuncAddDatalogEnhanced), variable(nDataPtIndex),  variable(nDataValue));
//intrinsic void AddToDatalog(const int nDataPtIndex, const long nDataValue) asm(opcdSystemFunctions, byte(sysFuncAddDatalogEnhanced), variable(nDataPtIndex),  variable(nDataValue));
intrinsic void SaveNxtDatalog()                                        asm(opcdSaveNxtDatalog);
#endif //#if defined(NXT) || defined(TETRIX)

#endif //#if defined(bHasDatalog)

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Procedure / Task Flow Control
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void callSub(compileConst int number)       asm(opcdCallSub, byte(number));
intrinsic void StartTask(void TaskID)									asm(opcdStartTask, taskNameConstant(TaskID));
intrinsic void StopTask(void TaskID)									asm(opcdStopTask,  taskNameConstant(TaskID));
intrinsic void StopAllTasks()                         asm(opcdStopAllTasks);

#if !defined(VEX)
	intrinsic void suspendTask(void TaskID)							asm(opcdSystemFunctions, byte(sysFuncSetSuspendResumeTask), taskNameVariable(TaskID), byte(opcdSourceConstant), word(1));
	intrinsic void resumeTask(void TaskID)							asm(opcdSystemFunctions, byte(sysFuncSetSuspendResumeTask), taskNameVariable(TaskID), byte(opcdSourceConstant), word(0));

  typedef enum word
  {
    taskStateUninitialized                    = 0,
    taskStateStopped                          = 1,
    taskStateRunning                          = 2,
    taskStateWaitingForTimer                  = 3,
    taskStateSuspendedWasRunning              = 4,
    taskStateSuspendedWasWaiting              = 5,
    taskStateBreakpointStop                   = 6,
    taskStateWaitingForSemaphore              = 7,
    taskStateSuspendedWasWaitingForSemaphore  = 8
  } TTaskStates;

  intrinsic void StartTask(void TaskID, const short nTaskPriority)
																											asm(opcdSystemFunctions, byte(sysFuncStartTaskWithPriority), taskNameVariable(TaskID), variable(nTaskPriority));
  intrinsic TTaskStates getTaskState(void TaskID)				    asm(opcdSystemFunctions, byte(sysFuncGetTaskState),    taskNameVariable(TaskID), functionReturn);
	intrinsic void setTaskPriority(void TaskID, const short nTaskPriority)
																											asm(opcdSystemFunctions, byte(sysFuncSetTaskPriority), taskNameVariable(TaskID), variable(nTaskPriority));
	intrinsic short getTaskPriority(void TaskID)				asm(opcdSystemFunctions, byte(sysFuncGetTaskPriority), taskNameVariable(TaskID), functionReturn);
#endif

intrinsic void clearAll(compileConst TClearCommandAction nCommandFlags)
                asm(opcdClearItems, byte(nCommandFlags & 0x00FF), byte((nCommandFlags >> 8) & 0x0FF));

#if defined(NXT) || defined(TETRIX) || defined(VEX2)
intrinsic void EndTimeSlice()                                 asm(opcdSystemFunctions, byte(sysFuncSwitchContext));
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(NXT) || defined(TETRIX) || defined(VEX2)
  intrinsic void alive()                                                asm(opcdAlive);
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                                  Debugging Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

intrinsic void setBreakpoint(compileConst ubyte breakNumb, compileConst ubyte memoryIndex, compileConst word nOffsetInSub)
                asm(opcdDebugSetBreakPoint, byte(breakNumb), byte(memoryIndex), word(nOffsetInSub));

intrinsic void assert()                                   asm(opcdAssert);

#if defined(_DEBUG)
#define ASSERT(assertVar) {if (!(assertVar)) assert();}
#else
#define ASSERT(assertVar) {}
#endif

#define VERIFY(assertVar) {if ((assertVar) == 0) else assert();}

#if defined(hasDebugStreamSupport)

	intrinsic void writeDebugStream(const string sFormatString, ...)
	                asm(opcdStringOps, strOpDebugStreamFormat, variableRefString(sFormatString),  varArgList);
	intrinsic void writeDebugStreamLine(const string sFormatString, ...)
	                asm(opcdStringOps, strOpDebugStreamFormatWithNewLine, variableRefString(sFormatString),  varArgList);
  //intrinsic void writeDebugStream(const string &sString) asm(opcdStringOps, byte(strOpDebugStream), variableRefString(sString));
  intrinsic short getAvailSpaceInDebugStream() asm(opcdStringOps, byte(strOpGetDebugStreamAvailableSpace), functionReturn);

#endif //#if defined(hasDebugStreamSupport)



intrinsic const word variableIndex(nDebugTaskMode,        opcdSourceSystem, kSystemDebugTaskMode);

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                Event Handling Variables and Opcodes
//
////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(bHasEvents)

intrinsic word variable(taskEvents,              opcdSourceTaskEvents,    kNumbOfTasks+1);

intrinsic word variable(EST_SENSOR,              opcdSourceEvent,         kNumbOfEvents);
intrinsic word variable(eventType,               opcdSourceEventType,     kNumbOfEvents);
intrinsic word variable(eventState,              opcdSourceEventState,    kNumbOfEvents);
intrinsic word variable(eventClicks,             opcdSourceClickCounter,  kNumbOfEvents);
intrinsic word variable(eventUpper,              opcdSourceUpperThreshold,kNumbOfEvents);
intrinsic word variable(eventLower,              opcdSourceLowerThreshold,kNumbOfEvents);
intrinsic word variable(eventHysteris,           opcdSourceHysteresis,    kNumbOfEvents);
intrinsic word variable(eventDuration,           opcdSourceDuration,      kNumbOfEvents);
intrinsic word variable(eventCounts,             opcdSourceEventCounts,   kNumbOfEvents);

intrinsic void DirectEvent(compileConst int nEventMask)          asm(opcdDirectEvent, variable(nEventMask));
intrinsic void SignalEvent(compileConst byte nEventNumber)       asm(opcdSignalEvent, byte(nEventNumber));
intrinsic void ResetEvent(compileConst byte nEventNumber)        asm(opcdResetEvent,  byte(nEventNumber));
intrinsic void ClearAllEvents()                           asm(opcdClearAllEvents);

#define EVENT_MASK(nEvent) (1 << nEvent)
#define nThisTaskEvents   taskEvents[10]

intrinsic void SetPriority(compileConst int nTaskNumber, compileConst int nPriority);

intrinsic void CalibrateEvent(compileConst byte nEventNumber, compileConst byte lowerThreshold, compileConst byte upperThreshold, compileConst byte hysteresis);

////intrinsic void SetEvent(compileConst byte nEvent, compileConst TEventSensorType nSensor, compileConst TEventTypes nType);

// Note use of 'overloads' in 'SetEvent' inline procs

///inline    void SetEvent(compileConst byte nEvent, compileConst TTimers          nTimer,  compileConst TEventTypes nType);
//inline    void SetEvent(compileConst byte nEvent, compileConst tSensors         nSensor, compileConst TEventTypes nType);
////inline    void SetEvent(compileConst byte nEvent, compileConst int              nSensor, compileConst TEventTypes nType);

intrinsic void DirectEvent(compileConst int nEventMask);
intrinsic void SignalEvent(compileConst int nEventNumber);
intrinsic void ResetEvent(compileConst int nEventNumber);
////inline void ClearEvent(compileConst int nEventNumber)          { SetEvent(nEventNumber, EST_SENSOR_UNUSED, eventTypeReset); }

//
// Several overloads for the single procedure. Allows users to easily set the 'TEventSensorType' for various types of variables
//
intrinsic void SetEvent(compileConst byte nEvent, compileConst TEventSensorType nSensor, compileConst TEventTypes nType)
                asm(opcdSetEventDefinition, byte(nEvent), byte(nSensor), byte(nType));

#endif //#if defined(bHasEvents)


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                         Message and Serial Link Handling Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#if (0) && (defined(NXT) || defined(TETRIX))

  intrinsic word variableIndex(message,          opcdSourceMessage,       0);
  intrinsic word variable(messageParm,           opcdSourceMessage,       3);

  #define bQueuedMsgAvailable()    (cCmdMessageGetSize() > 0)

  //intrinsic void sendMessageOld(const short nMessageID)           asm(opcdSendMessageShortVariable, shortVariable(nMessageID));
  intrinsic void sendMessage(const short nMessageID)              asm(opcdSendMessageVariable, variable(nMessageID));
  intrinsic void sendMessageWithParm(short nMessageID, short nParm1 = 0, short nParm2 = 0)
                  asm(opcdSendMessageWithParm, variable(nMessageID), variable(nParm1), variable(nParm2));
  #define ClearMessage()                             message = 0

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                              NXT I2C Messaging Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(NXT) || defined(TETRIX)

typedef enum
{
  NO_ERR                  =  0,
  STAT_COMM_PENDING       =  32,
  ERR_COMM_CHAN_NOT_READY = -32,  // Already defined but valid here. Specified channel/connection not configured or busy.
  ERR_COMM_BUS_ERR        = -35,
} TI2CStatus;


intrinsic word variable(nI2CBytesReady,     opcdSourceNxtI2CBytesRead,       kNumbOfRealSensors, tSensors);
intrinsic TI2CStatus variable(nI2CStatus,   opcdSourceNxtI2CMessagingStatus, kNumbOfRealSensors, tSensors);

intrinsic void sendI2CMsg(const tSensors nPort, const byte &sendMsg, const int nReplySize)
                asm(opcdSendI2CMsg, variable(nPort), variableRefByte(sendMsg), variable(nReplySize));
intrinsic void readI2CReply(const tSensors nPort, byte &replyBytes, const int nBytesToRead)
                asm(opcdReadI2CMsg, variable(nPort), variableRefByte(replyBytes), variable(nBytesToRead));

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            Transcendental / Trig / Math Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(VEX)

  #define abs(X) ((X < 0) ? -X : X)

#endif

#if defined(hasTranscendentalSupport)

intrinsic float sin(const float fRadians) asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(fRadians), byte(mathSine));
intrinsic float cos(const float fRadians) asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(fRadians), byte(mathCosine));
intrinsic float asin(const float Sine)    asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(Sine),     byte(mathArcSin));
intrinsic float acos(const float Cosine)  asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(Cosine),   byte(mathArcCos));
intrinsic float atan(const float Tangent) asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(Tangent),  byte(mathArcTan));
intrinsic float degreesToRadians(const int Degrees)  asm(opcdTranscendentalFunctions, functionReturn, variableRefWord(Degrees),   byte(mathDegreesToRadians));
intrinsic short radiansToDegrees(const float fRadians) asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(fRadians), byte(mathRadiansToDegrees));
intrinsic float sinDegrees(const float degrees)      asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(degrees),   byte(mathSineDegrees));
intrinsic float cosDegrees(const float degrees)      asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(degrees),   byte(mathCosDegrees));

intrinsic unsigned short abs(const short input) asm(opcdTranscendentalFunctions, functionReturn, variable(input),  byte(mathAbsWord));
intrinsic unsigned long  abs(const long input)  asm(opcdTranscendentalFunctions, functionReturn, variable(input),  byte(mathAbsLong));
intrinsic float abs(const float input)          asm(opcdTranscendentalFunctions, functionReturn, variable(input), byte(mathAbsFloat));

intrinsic float sqrt(const int input)           asm(opcdTranscendentalFunctions, functionReturn, variable(input),  byte(mathSqrtWord));
intrinsic float sqrt(const long input)          asm(opcdTranscendentalFunctions, functionReturn, variable(input),  byte(mathSqrtLong));
intrinsic float sqrt(const float input)         asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input), byte(mathSqrtFloat));

intrinsic short sgn(const int input)            asm(opcdTranscendentalFunctions, functionReturn, variable(input),   byte(mathSgnWord));
intrinsic short sgn(const long input)           asm(opcdTranscendentalFunctions, functionReturn, variable(input),  byte(mathSgnLong));
intrinsic short sgn(const float input)          asm(opcdTranscendentalFunctions, functionReturn, variable(input), byte(mathSgnFloat));

intrinsic float exp(const float input)          asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input),  byte(mathExp));
intrinsic float log(const float input)          asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input),  byte(mathLog));
intrinsic float log10(const float input)        asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input),  byte(mathLog10));

intrinsic float ceil(const float input)         asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input),  byte(mathCeil));
intrinsic float floor(const float input)        asm(opcdTranscendentalFunctions, functionReturn, variableRefFloat(input),  byte(mathFloor));

intrinsic float pow(const float base, const float exponent) asm(opcdSystemFunctions, byte(sysFuncPowerOf),
																								functionReturn, variableRefFloat(base),  variableRefFloat(exponent));

const float PI = 3.14159265358979323846264338327950288419716939937510;

intrinsic bool variableIndex(bFloatConversionErrors,							opcdSourceSystem, kSystemFloatConversionException);
intrinsic bool variableIndex(bClearVariablesOnPgmStart,           opcdSourceSystem, kSystemClearVariablesOnPgmStart);

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                     String Manipulation Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(hasStringSupport)

intrinsic void StringAssign(     string &sDest, const char   &nSrce) asm(opcdStringOps, strOpAssignString,variableRefString(sDest), variableRefByte(nSrce));
intrinsic void StringAssign(     string &sDest, const short  &nSrce) asm(opcdStringOps, strOpAssignByte,  variableRefString(sDest), variableRefWord(nSrce));
intrinsic void StringAssign(     string &sDest, const long   &nSrce) asm(opcdStringOps, strOpAssignShort, variableRefString(sDest), variableRefLong(nSrce));
intrinsic void StringAssign(     string &sDest, const float  &nSrce) asm(opcdStringOps, strOpAssignLong,  variableRefString(sDest), variableRefFloat(nSrce));
intrinsic void StringAssign(     string &sDest, const string &sSrce) asm(opcdStringOps, strOpAssignFloat, variableRefString(sDest), variableRefString(sSrce));

intrinsic void StringConcatenate(string &sDest, const string &sSrce) asm(opcdStringOps, strOpConcatenateString, variableRefString(sDest), variableRefString(sSrce));
intrinsic void StringConcatenate(string &sDest, const byte   &nSrce) asm(opcdStringOps, strOpConcatenateByte,   variableRefString(sDest), variableRefByte(nSrce));

intrinsic char StringGetChar(string &sSrce, const int nIndex) asm(opcdStringOps, strOpGetChar, functionReturn, variableRefString(sSrce), variable(nIndex));
intrinsic void StringGetAddress(string &sSrce) asm(opcdStringOps, strOpGetAddress,   variableRefString(sSrce), functionReturn);

//intrinsic byte  atoi(string &sSrce)		asm(opcdStringOps, strOp_atoi_char,  functionReturn, variableRefString(sSrce));
//intrinsic short atoi(string &sSrce)		asm(opcdStringOps, strOp_atoi_short, functionReturn, variableRefString(sSrce));
intrinsic long  atoi(string &sSrce)		asm(opcdStringOps, strOp_atoi_long,  functionReturn, variableRefString(sSrce));
intrinsic long  atoi(char *pzSrce)		asm(opcdStringOps, strOp_atoi_long,  functionReturn, variableRefString(pzSrce));

intrinsic float atof(string &sSrce)		asm(opcdStringOps, strOp_atof,       functionReturn, variableRefString(sSrce));
intrinsic float atof(char *pzSrce)		asm(opcdStringOps, strOp_atof,       functionReturn, variableRefString(pzSrce));


intrinsic void StringDelete(    string &sDest, const int nIndex, const int nSize)     asm(opcdStringOps, strOpDelete, variableRefString(sDest), variable(nIndex), variable(nSize));
intrinsic int StringFind(const string &sSrce, const string &sSearch)                  asm(opcdStringOps, strOpFind,   variableRefString(sSrce), functionReturn, variableRefString(sSearch));
intrinsic int strlen(const string &sString)                                           asm(opcdStringOps, strOpSize,   variableRefString(sString), functionReturn);

intrinsic void StringFromChars(string &sToString, const char &FromChars)              asm(opcdStringOps, strOpFromChars, variableRefString(sToString), variableRefRAM(FromChars));


intrinsic void snprintf(char *ppDest, const short nDestLength, const string sFormatString, ...)
                asm(opcdStringOps, strOpSNPRINTF,
                                variableRefByte(ppDest),
                                variable(nDestLength),
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void StringFormat(string &sDest, const string sFormatString, ...)
                asm(opcdStringOps, strOpSNPRINTF,  variableRefString(sDest),
                                byte(opcdSourceConstant), byte(20), byte(0),    // constant value 20
                                variableRefString(sFormatString),
                                varArgList);

intrinsic void sprintf(string &sString, const string sFormatString, ...)
                asm(opcdStringOps, strOpSPRINTF,
                                variableRefString(sString),
                                variableRefString(sFormatString),
                                varArgList);

#if defined(has_sscanf_Support)
intrinsic void sscanf(const string &sSource, const string &sFormatString, ...)
                asm(opcdStringOps, strOpSSCANF,
                                variableRefString(sSource),
                                variableRefString(sFormatString),
                                varArgList);
#endif

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                 NXT File I/O Opcodes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(NXT) || defined(TETRIX)


#define TFileHandle short

intrinsic void OpenRead(   TFileHandle &hFileHandle, TFileIOResult &nIoResult, const string &sFileName, word  &nFileSize) asm(opcdFileIO, ioOpenReadVariableFN,  variableRefWord(nIoResult), variableRefWord(hFileHandle), variableRefString(sFileName), variableRefWord(nFileSize));
intrinsic void OpenWrite(  TFileHandle &hFileHandle, TFileIOResult &nIoResult, const string &sFileName, word  &nFileSize) asm(opcdFileIO, ioOpenWriteVariableFN, variableRefWord(nIoResult), variableRefWord(hFileHandle), variableRefString(sFileName), variableRefWord(nFileSize));

intrinsic void Close(      TFileHandle hFileHandle, TFileIOResult &nIoResult)                asm(opcdFileIO, ioClose,            variableRefWord(nIoResult),  variable(hFileHandle));
intrinsic void CloseAllHandles(TFileIOResult &nIoResult)                                      asm(opcdFileIO, ioCloseAllFileHandles, variableRefWord(nIoResult));

intrinsic void Delete(const string &sFileName,    TFileIOResult &nIoResult)             asm(opcdFileIO, ioDelete,            variableRefWord(nIoResult), variableRefString(sFileName));

intrinsic void Rename(const string &sFileName, TFileIOResult &nIoResult, const string &sOriginalFileName) asm(opcdFileIO, ioRename,variableRefWord(nIoResult), variableRefString(sFileName), variableRefString(sOriginalFileName));

intrinsic void ReadByte(   const TFileHandle hFileHandle, TFileIOResult &nIoResult, byte  &nParm)   asm(opcdFileIO, ioReadByte,       variableRefWord(nIoResult), variableRefWord(hFileHandle), variableRefByte(nParm));
intrinsic void ReadShort(  const TFileHandle hFileHandle, TFileIOResult &nIoResult, word  &nParm)   asm(opcdFileIO, ioReadShort,      variableRefWord(nIoResult), variable(hFileHandle), variableRefWord(nParm));
intrinsic void ReadLong(   const TFileHandle hFileHandle, TFileIOResult &nIoResult, long  &nParm)   asm(opcdFileIO, ioReadLong,       variableRefWord(nIoResult), variable(hFileHandle), variableRefLong(nParm));
intrinsic void ReadFloat(  const TFileHandle hFileHandle, TFileIOResult &nIoResult, float &fParm)   asm(opcdFileIO, ioReadFloat,      variableRefWord(nIoResult), variable(hFileHandle), variableRefFloat(fParm));
// "ReadString" -- for future implementation

intrinsic void WriteByte(  const TFileHandle hFileHandle, TFileIOResult &nIoResult, const byte   nParm)  asm(opcdFileIO, ioWriteByte, variableRefWord(nIoResult), variable(hFileHandle), variableRefByte(nParm));
intrinsic void WriteShort( const TFileHandle hFileHandle, TFileIOResult &nIoResult, const word   nParm)  asm(opcdFileIO, ioWriteShort,variableRefWord(nIoResult), variable(hFileHandle), variableRefWord(nParm));
intrinsic void WriteLong(  const TFileHandle hFileHandle, TFileIOResult &nIoResult, const long   nParm)  asm(opcdFileIO, ioWriteLong, variableRefWord(nIoResult), variable(hFileHandle), variableRefLong(nParm));
intrinsic void WriteFloat( const TFileHandle hFileHandle, TFileIOResult &nIoResult, const float  fParm)  asm(opcdFileIO, ioWriteFloat,variableRefWord(nIoResult), variable(hFileHandle), variableRefFloat(fParm));
intrinsic void WriteString(const TFileHandle hFileHandle, TFileIOResult &nIoResult, compileConst string sParm)
                asm(opcdFileIO, ioWriteStringConst, variableRefWord(nIoResult), variable(hFileHandle), stringConstant(sParm));
intrinsic void WriteString(const TFileHandle hFileHandle, TFileIOResult &nIoResult, const string sParm)
                asm(opcdFileIO, ioWriteStringVar, variableRefWord(nIoResult), variable(hFileHandle), variableRefString(sParm));
intrinsic void WriteText(const TFileHandle &hFileHandle, TFileIOResult &nIoResult, const string sParm)
                asm(opcdFileIO, ioWriteText, variableRefWord(nIoResult), variable(hFileHandle), variableRefString(sParm));

intrinsic void FindFirstFile(TFileHandle &hFileHandle, TFileIOResult &nIoResult, const string sSearch, string &sFileName, short &nFilesize)
                asm(opcdFileIO, ioFindFirstFile,   variableRefWord(nIoResult), variableRefWord(hFileHandle), variableRefString(sSearch), variableRefString(sFileName), variableRefWord(nFilesize));
intrinsic void FindNextFile( const TFileHandle hFileHandle, TFileIOResult &nIoResult, string &sFileName, short &nFilesize)
                asm(opcdFileIO, ioFindNextFile,    variableRefWord(nIoResult), variable(hFileHandle), variableRefString(sFileName), variableRefWord(nFilesize));

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                      NXT Bluetooth Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#if defined(NXT) || defined(TETRIX)

//
// Interface between Bluecore commands and other modules
//
typedef enum
{
  SENDFILE          = 0,
  SEARCH            = 1,    // Internal use only!
  STOPSEARCH        = 2,    // Internal use only!
  CONNECT           = 3,
  DISCONNECT        = 4,
  DISCONNECTALL     = 5,
  REMOVEDEVICE      = 6,    //
  VISIBILITY        = 7,
  SETCMDMODE        = 8,    // Internal use only!
  OPENSTREAM        = 9,
  SENDDATA          = 10,   // Internal use only!
  FACTORYRESET      = 11,
  BTON              = 12,
  BTOFF             = 13,
  SETBTNAME         = 14,
  EXTREAD           = 15,   // Internal use only!
  PinReq            = 16,   // Internal use only!
  CONNECTREQ        = 17,   // Internal use only!
  //
  // Robolab/ROBOTC additions beyond standard firmware
  //
  //
  // Robolab/RobotC additions beyond standard firmware. Some of these generate immediate replies and some need to wait
  //
  IDLE              = 18,
  LinkQualityReq    = 19,     // Requests quality of link from Bluecore
  opSetRawDataMode  = 20,     // Sets Bluecore into Raw Data mode
  opSetDefaultPIN   = 21,     // Sets default Passcode. Immediate command. Bluecore interaction not required.
  opGetDefaultPIN   = 22,     // Retrieves default Passcode. Immediate command. Bluecore interaction not required.
  opSetSessionPIN   = 23,     // Sets session Passcode. Immediate command. Initialized to "default" passcode on power up
  opGetSessionPIN   = 24,     // Retrieves session Passcode. Immediate command. Bluecore interaction not required.
  opResetSessionPIN = 25,     // Resets session Passcode to default passcode.
  opGetFriendlyName = 26,     // Gets the Bluetooth "Friendly Name" String.
  opGetBTAddress    = 27,
  opGetMyContactInfo = 28,    // Gets info on selected "My Contacts" list.
} TBTCommands;


const int kSizeOfBtName              = 16 + 1;  // Add 1 for zero termination char
const int kSizeOfBrickName           =  8 + 1;  // Add 1 for zero termination char
const int kSizeOfClassOfDevice       =  4;
const int kSizeOfBtPincode           = 16;
const int kSizeOfBtAddr              =  6;   // NOTE, NXT firmware uses 7 bytes!!

typedef ubyte TBTAddress[kSizeOfBtAddr];

typedef enum
{
  BT_STATE_VISIBLE            = 0x01,         // RW - BT visible
  BT_STATE_CONNECTED          = 0x02,         // RW - BT connected to something
  BT_STATE_OFF                = 0x04,         // RW - BT power off
  BT_ERROR_ATTENTION          = 0x08,         // W  - BT error attention
  BT_STATE_PORT_OPEN          = 0x10,         // R  - BT Port open for receiving connection. New. Moved from IOMapComm
  BT_CONNECT_REQUEST          = 0x40,         // RW - BT get connect accept in progress
  BT_PIN_REQUEST              = 0x80          // RW - BT get pin code
} TBluetoothStateX;


intrinsic TBluetoothStateX  variableIndex(nBluetoothState,    opcdSourceSystem, kSystemBluetoothStatus);

intrinsic const bool     variableIndex(bBTBusy,               opcdSourceSystem, kSystemBluetoothBusy);
intrinsic const bool     variableIndex(bBTVisble,             opcdSourceSystem, kSystemBTVisible);
intrinsic const bool     variableIndex(bBTRawMode,            opcdSourceSystem, kSystemBluetoothMode);
intrinsic bool           variableIndex(bBTDebugTrace,         opcdSourceSystem, kSystemBluetoothDebug);
intrinsic bool           variableIndex(bBTSkipPswdPrompt,     opcdSourceSystem, kSystemBTSkipPasswordPrompt);
intrinsic bool           variableIndex(bBTHasProgressSounds,  opcdSourceSystem, kSystemBTHasProgressSounds);
intrinsic const TFileIOResult  variableIndex(nBluetoothCmdStatus,   opcdSourceSystem, kSystemBluetoothCmdStatus);
intrinsic bool           variableIndex(bBTOptimizePerformance,opcdSourceSystem, kSystemBTOptimizePerformance);
intrinsic uword          variableIndex(nBTStreamSwitchDelay,	opcdSourceSystem, kSystemBTStreamSwitchDelay);


intrinsic TBTCommands    variableIndex(nLastBTCommand,        opcdSourceSystem, kSystemBluetoothLastCmd);
intrinsic const short    variableIndex(nBTCurrentStreamIndex, opcdSourceSystem, kSystemBTCurrentStreamIndex);
//intrinsic const short    variable(nBTLinkQuality,             opcdSourceNxtLinkQuality, 4);


#define BTOpcdFcn(function)  opcdBTLinkIO, byte(function),  functionReturn            // NOTE, word result and not byte!!!!

intrinsic TFileIOResult btFactoryReset()                                        asm(BTOpcdFcn(FACTORYRESET));
intrinsic TFileIOResult setBluetoothRawDataMode()                               asm(BTOpcdFcn(opSetRawDataMode));

intrinsic TFileIOResult setBluetoothOn()                                        asm(BTOpcdFcn(BTON));
intrinsic TFileIOResult setBluetoothOff()                                       asm(BTOpcdFcn(BTOFF));
intrinsic TFileIOResult setBluetoothVisibility(const bool bBluetoothVisible)    asm(BTOpcdFcn(VISIBILITY), variable(bBluetoothVisible));
intrinsic TFileIOResult btRequestLinkQuality(const int nPort)                   asm(BTOpcdFcn(LinkQualityReq), variable(nPort));

intrinsic TFileIOResult btSearch()                                              asm(BTOpcdFcn(SEARCH));
intrinsic TFileIOResult btStopSearch()                                          asm(BTOpcdFcn(STOPSEARCH));

typedef enum
{
  btDeviceStatusSlotEmpty           = (ubyte) 0x00,
  btDeviceStatusFoundViaSearch      = (ubyte) 0x01, // A new device has been added to the table in the most recent BT search.
  btDeviceStatusPairedByBluecore    = (ubyte) 0x02, // The device is known to the internal device list in the Bluecore module.

  btDeviceStatusNameLookedUp        = (ubyte) 0x40, // At least one successful lookup of device name over BT since device powered on
  btDeviceStatusAWAY                = (ubyte) 0x80, // A known device did not respond to the last "Search" command. It may be powered off?

  //
  // Dick's add. Twmporary fields to hold search results
  //
  btDeviceStatusProcessedNameByUI   = (ubyte) 0x04, // Used during searching to indicate device has been processing
  btDeviceStatusProcessedByUI       = (ubyte) 0x08, // Used during searching to indicate device has been processing

} TBtDeviceStatus;

typedef ubyte tBTAddress[6];
typedef struct
{
  string            sFriendlyName;
  tBTAddress        nAddress;
  TBtDeviceStatus   nDeviceStatus;
} TMyContactsEntry;
//typedef TMyContactsEntry *pTMyContactsEntry;

const int kMaxMyContacts = 30;

intrinsic void btGetMyContactsEntry(const int nIndexInList, TMyContactsEntry &nInfo)
            asm(opcdBTLinkIO, byte(opGetMyContactInfo),  variable(nIndexInList), variableRefRAM(nInfo));
intrinsic TFileIOResult btConnect(const int nPort, string sFriendlyName)        asm(BTOpcdFcn(CONNECT), variable(nPort), variableRefString(sFriendlyName));
intrinsic TFileIOResult btDisconnect(const int nPort)                           asm(BTOpcdFcn(DISCONNECT), variable(nPort));
intrinsic TFileIOResult btDisconnectAll()                                       asm(BTOpcdFcn(DISCONNECTALL));
intrinsic TFileIOResult btRemoveDevice(string sFriendlyName)                    asm(BTOpcdFcn(REMOVEDEVICE), variableRefString(sFriendlyName));
intrinsic TFileIOResult setFriendlyName(string sFriendlyName)                   asm(BTOpcdFcn(SETBTNAME), variableRefString(sFriendlyName));

intrinsic TFileIOResult transferFile(const int nPort, const string &sFileName)     asm(BTOpcdFcn(SENDFILE), variable(nPort), variableRefString(sFileName));

intrinsic void setDefaultPIN(const string &passCode)                            asm(opcdBTLinkIO, byte(opSetDefaultPIN),  variableRefString(passCode));
intrinsic void getDefaultPIN(string &passCode)                                  asm(opcdBTLinkIO, byte(opGetDefaultPIN),  variableRefString(passCode));
intrinsic void setSessionPIN(const string &passCode)                            asm(opcdBTLinkIO, byte(opSetSessionPIN),  variableRefString(passCode));
intrinsic void getSessionPIN(string &passCode)                                  asm(opcdBTLinkIO, byte(opGetSessionPIN),  variableRefString(passCode));
intrinsic void resetSessionPIN()                                                asm(opcdBTLinkIO, byte(opResetSessionPIN));
intrinsic void getFriendlyName(string &sName)                                   asm(opcdBTLinkIO, byte(opGetFriendlyName), variableRefString(sName));

intrinsic void getBTAddress(TBTAddress &btAddr)                                 asm(opcdBTLinkIO, byte(opGetBTAddress), variableRefRAM(btAddr));
intrinsic TFileIOResult btSendMessage(const int nPort, const int nXmitLength, const byte &nXmitBuffer, const bool bWaitForReply)
                                                                                asm(BTOpcdFcn(SENDDATA),
                                                                                             variable(nPort),
                                                                                             variable(nXmitLength),
                                                                                             variableRefByte(nXmitBuffer),
                                                                                             variable(bWaitForReply));

///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                              NXT Bluetooth Messaging Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

//
// The NXT has ten message queues. Need to match the queue that we are polling on with the queue that
// has been selected in the "TETRIX Controller Station" program on the PC.
//
typedef enum word
{
	mailbox1    =  0,
	mailbox2    =  1,
	mailbox3    =  2,
	mailbox4    =  3,
	mailbox5    =  4,
	mailbox6    =  5,
	mailbox7    =  6,
	mailbox8    =  7,
	mailbox9    =  8,
	mailbox10   =  9,

	//
	// Internal queues
	//
	mailbox11   =  10,
	mailbox12   =  11,
	mailbox13   =  12,
	mailbox14   =  13,
	mailbox15   =  14,
	mailbox16   =  15,
	mailbox17   =  16,
	mailbox18   =  17,
	mailbox19   =  18,
	mailbox20   =  19,
} TMailboxIDs;


const int kDefaultBTQueue = mailbox1;

#define constZero()     byte(opcdSourceConstant), byte(0), byte(0)
#define nxtMsgOp(subType)  opcdNXTMessageIO, byte(subType), functionReturn

intrinsic short cCmdMessageGetSize(const TMailboxIDs nQueueID = kDefaultBTQueue)
    asm(nxtMsgOp(msgOpSizeForQueue),    variable(nQueueID));
intrinsic TFileIOResult cCmdBTCheckStatus(short nStream)    asm(nxtMsgOp(msgOpBluetoothStatus), variable(nStream));
intrinsic TFileIOResult cCmdBTPurgeRcvBuffer()              asm(nxtMsgOp(msgOpPurgeReadBuffer));

//
//   Bluettoth Messaging Functions
//
intrinsic TFileIOResult nxtWriteRawBluetooth(const short nStream, ubyte *pData, const short nLength)
    asm(nxtMsgOp(msgOpBluetoothWriteRawToPort),  constZero(),       variableRefByte(pData), variable(nLength),       variable(nStream));

intrinsic TFileIOResult nxtWriteRawBluetooth(ubyte *pData, const short nLength)
    asm(nxtMsgOp(msgOpBluetoothWriteRawNoPort),  constZero(),        variableRefByte(pData), variable(nLength),       constZero());

intrinsic short nxtReadRawBluetooth(ubyte &pData, const int nMaxBufferSize)
    asm(nxtMsgOp(msgOpBluetoothReadRaw),         constZero(),        variableRefByte(pData), variable(nMaxBufferSize), constZero());

intrinsic TFileIOResult cCmdMessageWriteToBluetooth(ubyte *pData, const short nLength, const TMailboxIDs nQueueID = kDefaultBTQueue)
    asm(nxtMsgOp(msgOpMessageWriteNoPort),       variable(nQueueID), variableRefByte(pData), variable(nLength),       constZero());

intrinsic TFileIOResult cCmdMessageWriteToBluetooth(const short nStream, ubyte *pData, const short nLength, const TMailboxIDs nQueueID = kDefaultBTQueue)
    asm(nxtMsgOp(msgOpMessageWriteToPort),       variable(nQueueID), variableRefByte(pData), variable(nLength),       variable(nStream));

intrinsic TFileIOResult cCmdMessageAddToQueue(const TMailboxIDs nQueueID, ubyte *pData, const short nLength)
    asm(nxtMsgOp(msgOpMessageAddQueue),          variable(nQueueID), variableRefByte(pData), variable(nLength),       constZero());

intrinsic TFileIOResult cCmdMessageRead(ubyte * pData, const short nLengthToRead, const TMailboxIDs nQueueID = kDefaultBTQueue)
    asm(nxtMsgOp(msgOpMessageReadFromQueue),     variable(nQueueID), variableRefByte(pData), variable(nLengthToRead), constZero());


    ///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                              NXT High Speed RS-485 Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////
//
intrinsic TFileIOResult nxtWriteRawHS(const ubyte &pData, const short nLength, const short nAddress = -1)
    asm(nxtMsgOp(msgOpHSWrite),                variableRefRAM(pData), variable(nLength), variable(nAddress));

intrinsic short nxtReadRawHS(ubyte &pData, const int nMaxBufferSize)
    asm(nxtMsgOp(msgOpHSRead),                 variableRefByte(pData), variable(nMaxBufferSize));

const long kDefaultBaudRate = 921600;
intrinsic TFileIOResult nxtSetHSBaudRate(const long nBaudRate = kDefaultBaudRate)
    asm(nxtMsgOp(msgOpHSBaudRate),             variableRefLong(nBaudRate));

intrinsic short nxtGetAvailHSBytes()
    asm(nxtMsgOp(msgOpHSReadAvailBytes));

#define nxtEnableHSPort()         SensorType[S4] = sensorHighSpeed
#define nxtDisableHSPort()        SensorType[S4] = sensorNone

intrinsic THiSpeed_Mode variableIndex(nxtHS_Mode,            opcdSourceSystem, kSystemHS_Mode);
intrinsic const THighSpeedState variableIndex(nxtHS_Status,  opcdSourceSystem, kSystemHS_Status);

#undef nxtMsgOp

#endif //#if defined(NXT) || defined(TETRIX)



///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  NXT IO Map Read/Write
//
// Generic I/O Map read/write
//
///////////////////////////////////////////////////////////////////////////////////////////////////////


#if defined(NXT) || defined(TETRIX)
intrinsic void nxtReadIOMap(const string &sIOMapName, short &nIoResult, byte &nBuffer, const int nOffset, const int nNumbOfBytes)

                asm(opcdSystemFunctions, byte(sysFuncIOMapRead),
                                          variableRefString(sIOMapName),
                                          variable(nIoResult),
                                          variableRefByte(nBuffer),
                                          variable(nOffset), variable(nNumbOfBytes));

intrinsic void nxtWriteIOMap(const string &sIOMapName, int &nIoResult, const byte &nBuffer, const int nOffset, const int nNumbOfBytes)

                asm(opcdSystemFunctions, byte(sysFuncIOMapWrite),
                                          variableRefString(sIOMapName),
                                          variable(nIoResult),
                                          variableRefByte(nBuffer),
                                          variable(nOffset), variable(nNumbOfBytes));

#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             Multi-Robot Messaging Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////



#if defined(bHasMultRobotNetworking)

typedef enumWord TNodeIndex
{
  //nDummyNode        = 0,
} TNodeIndex;


#define mrMsgOp(subType)  opcdMultiRobotNtwking, byte(subType), functionReturn

intrinsic word getMyNodeIndex()
    asm(mrMsgOp(ntwkingOpGetMyNodeIndex));

intrinsic bool bMsgAvailable()
    asm(mrMsgOp(ntwkingOpMessageAvail));

intrinsic TNtwkingStatus getNetworkingStartupFinished()
    asm(mrMsgOp(ntwkingOpStartupFinished));

intrinsic TNtwkingStatus getNetworkingStatus()
    asm(mrMsgOp(ntwkingOpStatus));

intrinsic TNtwkingStatus sendMessage(const TNodeIndex nNodeIndex, ubyte *pData, const short nLength)
    asm(mrMsgOp(ntwkingOpSendMessage),  variable(nNodeIndex), variableRefByte(pData), variable(nLength));

intrinsic TNtwkingStatus sendMessageWithWait(const TNodeIndex nNodeIndex, ubyte *pData, const short nLength)
    asm(mrMsgOp(ntwkingOpSendMessageWithWait),  variable(nNodeIndex), variableRefByte(pData), variable(nLength));

intrinsic TNtwkingStatus getMessage(TNodeIndex &nNodeIndex, ubyte *pData, const short nMaxLength,  short &nActualLength)
    asm(mrMsgOp(ntwkingOpGetMessage),  variableRefWord(nNodeIndex), variableRefByte(pData), variable(nMaxLength), variableRefWord(nActualLength));

intrinsic TNtwkingStatus resetNetworkDefinition()
    asm(mrMsgOp(ntwkingOpResetNetworkDefinition));


#endif // defined(bHasMultRobotNetworking)

#if defined(hasJoystickDownloadMessageOpcodes)

	typedef struct
	{
		short   joy1_x1;           // -128 to +127
		short   joy1_y1;           // -128 to +127
		short   joy1_x2;           // -128 to +127
		short   joy1_y2;           // -128 to +127
		short   joy1_Buttons;      // Bit map for 12-buttons
		short   joy1_TopHat;       // value -1 = not pressed, otherwise 0 to 7 for selected "octant".
	} TPCJoystick;

	intrinsic void getPCJoystickSettings(TPCJoystick &joystick)
		                      asm(opcdSystemFunctions, byte(sysFuncGetJoysticks),
		                            variableRefRAM(joystick));
#endif
