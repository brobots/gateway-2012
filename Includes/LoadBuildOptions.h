#ifndef LoadBuildOptions__H_
#define LoadBuildOptions__H_

#if !(defined(MainIncludes__H_) || defined(RobotCIncludes__H_)) && !defined(_WINDOWS)
	#error "'LoadBuildOptions.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//#define debugLowSpeed  1				// I2C Debug Trace Enabled
#define debugLowSpeed  0					// I2C Debug Trace Disabled

#define debugMotors  1						// Motor Debug Trace Enabled
//#define debugMotors  0					// Motor Debug Trace Disabled


#define kNumbOfBasicGlobalVariables	  ((uword) 32)

#if !(defined(ARM)  || defined(NXT) || defined(TETRIX) || \
      defined(ArduinoMega) || defined(RoboCub) || defined(Arduino2009) || defined(Generic) || \
			defined(Simulator) || defined(_WINDOWS) || \
			defined(STM8) || \
      defined(VEX2) || defined(VEX) || defined(VEXPro) || defined(STM3210E) || defined(SX256))
   #error("Platform type for compile is illegal")
#endif


#if !defined(enumWord)
  #if defined(ROBOTC) && !defined(enumWord)
    #define enumWord enum word
  #else
    #define enumWord enum
  #endif
#endif

//
// Flag to indicate whether platform supports LCD Display
//


//
// Flag to indicate whether user messages are supported (i.e. IR or bluetooth)
//
#if (0) && (defined(NXT))
  #define bUserMessagesAllowed
#else
  #undef  bUserMessagesAllowed
#endif


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             Toggles to Control Optional Features
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

//
// List of all Toggles
//

#undef  romtype
#undef  ramtype
#undef  neartype
#undef  no_init
#undef  genericParmArith
#undef  optionalExceptions
#undef  optionalBreakpoints
#undef  optionalDebugSupport
#define optionalSwitchOpcodes
#undef  hasOptionalUploadSupport
#undef  hasBulkUploadlupport
#undef  hasDeviceUploadSupport
#define optionalTrinaryOpcodes
#define optionalInfraredStatistics
#undef  kSystemClockSpeed

#undef  bMotorMirroring
#undef  bSmartMotorsWithEncoders
#undef  bAssociateMotorWithEncoder
#undef  bAssociateMotorWithIOPins

#undef  bHasSoundSupport
#undef  bHasSoundVolume
#undef  bHasSoundDriverOnOff
#undef  bHasSoundFiles

#undef  bHasFlashFileSystem
#undef  kMaxNumbofFlashFiles
#undef  useFloats
#undef  useLongs
#define bDebugAddressAlignment (0)
#undef  hasCamera
#undef  hasJoystickMessageOpcodes
#undef  hasHarvardArchitecture
#undef  hasStringSupport
#undef  hasDebugStreamSupport
#undef  kDebugStreamBufferSize
#undef  hasTranscendentalSupport
#undef  bHasDatalog
#undef  bSpareFlagXX

#undef  hasAlphaNumericLCDDisplayViaUART
#undef  hasStatusLEDs
#undef  bUseLookupBreakpointTableInRAM
#undef  nnRobotType
#undef  hasSpareOption3
#undef  hasSpareOption4
#undef  hasSpareOption5
#undef  hasSpareOption6
#undef  hasSpareOption7
#undef  hasSpareOption8
#undef  hasSpareOption9
#undef  kSizeOfXmitBufferUserUart
#undef  kRcvBufferSizeUserUart
#undef  bHasLCDGraphicsDisplay
#undef  bHasLCDContrast
#undef  bHasRemoteButtons

#undef  bHasStandardBatteryMonitoring

#undef  bHasFastSonarSensor
#undef  bHasSensorBiasSettings
#undef  sensorHandlerWorkBetweenOpcodes

#undef  bHasSystemTaskForUserProgramComplete			// Flags a "system task" event when user program has finised
#undef  kScreenWidth
#undef  kScreenHeight
#undef  bHasSemaphoreSupport
#undef  bHasMultRobotNetworking
#undef  kReceivedOpcodeSize
#undef  bGetClearVariablesOnPgmStart
#undef  spareOption9
#undef  spareOption10

#undef  kStartOfFileSystem
#undef  kStartOfBootloader
#undef  bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX

#undef  useFastMemoryHandlers
#undef  kSizeOfXmitBufferPC
#undef  kRcvBufferSizePC

#undef  kSizeOfXmitBufferPC
#undef  kRcvBufferSizePC

#undef  hasUserSerialPorts
#undef  numbOfUserSerialPorts

#undef  ARMCPU
#undef  AVRCPU
#undef  STM8CPU
#undef  Spare1CPU
#undef  Spare2CPU
#undef  Spare3CPU
#undef  useParmForCurrOpPtr

#if defined(NXT) || defined(TETRIX)

  #define romtype																												// NXT
  #define ramtype																												// NXT
  #define ramfunc __ramfunc																							// NXT
  #define neartype																											// NXT
  #define no_init __no_init																							// NXT
  //#undef inline																												// NXT

  #define bMotorMirroring																								// NXT
  #define bSmartMotorsWithEncoders																			// NXT
  #undef  bAssociateMotorWithEncoder																		// NXT
  #undef  bAssociateMotorWithIOPins 																		// NXT

  #define kNumbOfBreakpoints 16																					// NXT
  #define bUsesFlashStorage																							// NXT
  #define kFlashSectorSize   256																				// NXT
	#undef  kSystemClockSpeed																							// NXT
	#define genericParmArith																							// NXT
  #undef  bDebugAddressAlignment																				// NXT
  #define bDebugAddressAlignment (1)																		// NXT
  #define  optionalExceptions 																					// NXT
  #define  optionalBreakpoints 																					// NXT
  #define  optionalDebugSupport																					// NXT
  #define hasBulkUploadlupport																					// NXT
  #define hasOptionalUploadSupport																			// NXT
  #undef  hasDeviceUploadSupport																				// NXT
  //#undef  optionalTrinaryOpcodes																			// NXT
  #undef  optionalInfraredStatistics																		// NXT

  #define bHasSoundSupport																							// NXT
  #define bHasSoundVolume																								// NXT
  #undef  bHasSoundDriverOnOff																					// NXT
  #define bHasSoundFiles																								// NXT
  #define kSoundQueueSize 10																						// NXT

	#define useFloats																											// NXT
	#define useLongs																											// NXT
  //#undef  hasCamera																										// NXT
  #undef  hasJoystickMessageOpcodes																			// NXT
  #undef hasHarvardArchitecture    																			// NXT
  #define hasStringSupport																							// NXT
  #define hasDebugStreamSupport																					// NXT
	#define kDebugStreamBufferSize 4000																		// NXT
  #define hasTranscendentalSupport																			// NXT
  #define kRamBaseAddr 0																								// NXT
	#define bHasDatalog																										// NXT
  #undef  bSpareFlagXX																									// NXT

  #undef  hasAlphaNumericLCDDisplayViaUART															// NXT
	#undef  kSizeOfXmitBufferUserUart																			// NXT
  #undef  bUseLookupBreakpointTableInRAM																// NXT
  #define nnRobotType rbtTypeNXT																				// NXT
  #undef  hasSpareOption3																								// NXT
  #undef  hasSpareOption4																								// NXT
  #undef  hasSpareOption5																								// NXT
  #undef  hasSpareOption6																								// NXT
  #undef  hasSpareOption7																								// NXT
  #undef  hasSpareOption8																								// NXT
  #undef  hasSpareOption9																								// NXT
	#undef  kRcvBufferSizeUserUart																				// NXT
	#define bHasLCDGraphicsDisplay																				// NXT
	#define bHasLCDContrast																								// NXT
	#define bHasRemoteButtons																							// NXT

	#define bHasStandardBatteryMonitoring																	// NXT

	#undef  bHasFastSonarSensor																						// NXT
  #undef  bHasSensorBiasSettings																				// NXT
	#define sensorHandlerWorkBetweenOpcodes()															// NXT

	#define kNumbAnalogSensors 	 4																				// NXT
	#define kNumbDigitalSensors  4																				// NXT

	#undef  bHasSystemTaskForUserProgramComplete													// NXT
	#define kScreenWidth     100																					// NXT
	#define kScreenHeight     64																					// NXT
	#undef  bHasSemaphoreSupport																					// NXT
  #define kMaxBytesPerDataBytesUpload   59															// NXT
	#undef  bHasMultRobotNetworking																				// NXT
	#define kReceivedOpcodeSize           70															// NXT
	#undef bGetClearVariablesOnPgmStart																		// NXT
	#undef  spareOption9																									// NXT
	#undef  spareOption10																									// NXT

  #define kNumbOfTasks									(20)														// NXT
  #define kNumbOfGlobalVariables				(7500)													// NXT
  #define kNumbOfPrograms								(1)															// NXT
  #define kNumbOfTaskVariables					(16)														// NXT
  #define kNumbOfRealSensors            (4)															// NXT
  #define kNumbOfRealMotors             (3)															// NXT
  #define kNumbOfRealServos             ((ubyte) 4 * 4 * 8)							// NXT
  #define kNumbOfVirtualSensors         ((ubyte) 8)											// NXT
  #define kNumbOfVirtualMotors          ((ubyte) (4 * 4 * 2))						// NXT
  #define kTaskVariablesStart   				((uword) 96)										// NXT

  #undef  bHasFlashFileSystem																						// NXT
	#undef  kMaxNumbofFlashFiles																					// NXT
  #undef  kVTOCItemSize     																						// NXT

	#define bHasEvents																										// NXT
  #define kDefaultTaskStackSizeInEntries 30															// NXT

  #define kConstantPoolSize  3200  // Maximum size in bytes of constant pool// NXT
  #define kStartOfFileSystem 		File_System_Start_Needs_To_Be_Defined		// NXT
	#undef  kStartOfBootloader																						// NXT
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// NXT
	#undef  kSizeOfXmitBufferPC																						// NXT
	#undef  kRcvBufferSizePC																							// NXT

	#undef  hasUserSerialPorts																						// NXT
	#define numbOfUserSerialPorts    0																		// NXT

	#define ARMCPU																												// NXT
	#undef  AVRCPU																												// NXT
	#undef  STM8CPU																												// NXT
	#undef  Spare1CPU																											// NXT
	#undef  Spare2CPU																											// NXT
	#undef  Spare3CPU																											// NXT
  #define useParmForCurrOpPtr																						// NXT

#elif defined(VEX)

  #define romtype rom //far																							// VEX_PIC
  #define ramtype  ram																									// VEX_PIC
  #define neartype near																									// VEX_PIC
  #define ramfunc																												// VEX_PIC
  #define no_init																												// VEX_PIC
  //#undef inline																												// VEX_PIC

  #define bMotorMirroring																								// VEX_PIC
  #undef  bSmartMotorsWithEncoders																			// VEX_PIC
  #undef  bAssociateMotorWithEncoder																		// VEX_PIC
  #undef  bAssociateMotorWithIOPins 																		// VEX_PIC

  #define kNumbOfBreakpoints 6																					// VEX_PIC
  #define bUsesFlashStorage																							// VEX_PIC
  #define kFlashSectorSize   64																					// VEX_PIC
	#undef  kSystemClockSpeed																							// VEX_PIC
	#define genericParmArith																							// VEX_PIC
  #define  optionalExceptions 																					// VEX_PIC
  #define  optionalBreakpoints 																					// VEX_PIC
  #define  optionalDebugSupport																					// VEX_PIC
  #define hasBulkUploadlupport																					// VEX_PIC
  #define hasOptionalUploadSupport																			// VEX_PIC
  #define hasDeviceUploadSupport																				// VEX_PIC
  #undef  optionalTrinaryOpcodes 																				// VEX_PIC
  #undef  optionalInfraredStatistics																		// VEX_PIC

  #undef  bHasSoundSupport																							// VEX_PIC
  #undef  bHasSoundVolume																								// VEX_PIC
  #undef  bHasSoundDriverOnOff																					// VEX_PIC
  #undef  bHasSoundFiles																								// VEX_PIC
  #define kSoundQueueSize 5																							// VEX_PIC

	#undef  useFloats																											// VEX_PIC
  #define  useLongs																											// VEX_PIC
  #undef  hasCamera																											// VEX_PIC
  #undef  hasJoystickMessageOpcodes																			// VEX_PIC
  #define hasHarvardArchitecture																				// VEX_PIC
  #define kMaxTimeBetweenMessageChars 75 // 45													// VEX_PIC
  #undef  hasStringSupport																							// VEX_PIC
  #undef  hasDebugStreamSupport																					// VEX_PIC
	#undef  kDebugStreamBufferSize																				// VEX_PIC
  #undef  hasTranscendentalSupport																			// VEX_PIC
  #define kRamBaseAddr 0																								// VEX_PIC
	#undef  bHasDatalog																										// VEX_PIC
  #undef  bSpareFlagXX																									// VEX_PIC

  #define hasAlphaNumericLCDDisplayViaUART															// VEX_PIC
	#undef   hasStatusLEDs																								// VEX_PIC
  #undef  bUseLookupBreakpointTableInRAM																// VEX_PIC
  #define nnRobotType	rbtTypeVEX0_5																			// VEX_PIC
  #undef  hasSpareOption3																								// VEX_PIC
  #undef  hasSpareOption4																								// VEX_PIC
  #undef  hasSpareOption5																								// VEX_PIC
  #undef  hasSpareOption6																								// VEX_PIC
  #undef  hasSpareOption7																								// VEX_PIC
  #undef  hasSpareOption8																								// VEX_PIC
  #undef  hasSpareOption9																								// VEX_PIC
	#define kSizeOfXmitBufferUserUart 25																	// VEX_PIC
	#define kRcvBufferSizeUserUart    15																	// VEX_PIC
	#undef  bHasLCDGraphicsDisplay																				// VEX_PIC
	#undef  bHasLCDContrast																								// VEX_PIC
	#define bHasRemoteButtons																							// VEX_PIC

	#undef  bHasStandardBatteryMonitoring																	// VEX_PIC

	#undef  bHasFastSonarSensor																						// VEX_PIC
  #define bHasSensorBiasSettings																				// VEX_PIC
#if !defined(ROBOTC)
  extern void sensorHandlerWorkBetweenOpcodes(void);										// VEX_PIC
#endif

	#define kNumbAnalogSensors 	 8																				// VEX_PIC
	#define kNumbDigitalSensors  8																				// VEX_PIC

	#define bHasSystemTaskForUserProgramComplete													// VEX_PIC
	#undef  kScreenWidth																									// VEX_PIC
	#undef  kScreenHeight																									// VEX_PIC
	#undef  bHasSemaphoreSupport																					// VEX_PIC
  #define kMaxBytesPerDataBytesUpload   59															// VEX_PIC
	#undef  bHasMultRobotNetworking																				// VEX_PIC
	#define kReceivedOpcodeSize           70															// VEX_PIC
	#define bGetClearVariablesOnPgmStart()   false												// VEX_PIC
	#undef  spareOption9																									// VEX_PIC
	#undef  spareOption10																									// VEX_PIC

  #define kNumbOfTasks									(5)															// VEX_PIC
  #define kNumbOfGlobalVariables				(128)														// VEX_PIC
  #define kNumbOfPrograms								(16)														// VEX_PIC
  #define kNumbOfTaskVariables					(0)															// VEX_PIC
  #define kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors)// VEX_PIC
  #define kNumbOfRealMotors             (8)															// VEX_PIC
  #define kNumbOfRealServos             ((ubyte) 8)											// VEX_PIC
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// VEX_PIC
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// VEX_PIC
  #define kTaskVariablesStart   				((uword) 40)										// VEX_PIC

  #define bHasFlashFileSystem																						// VEX_PIC
	#define kMaxNumbofFlashFiles					16															// VEX_PIC
  #define kNumbOfFiles                  16															// VEX_PIC
  #define kVTOCItemSize									2																// VEX_PIC

  #undef  bHasEvents																										// VEX_PIC
  #define kDefaultTaskStackSizeInEntries 12															// VEX_PIC
  #undef  kConstantPoolSize																							// VEX_PIC
  #define kStartOfFileSystem 						0x00007000											// VEX_PIC
	#undef  kStartOfBootloader																						// VEX_PIC
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// VEX_PIC
	#define kSizeOfXmitBufferPC 	70																			// VEX_PIC
	#define kRcvBufferSizePC	 		20																			// VEX_PIC

	#define hasUserSerialPorts																						// VEX_PIC
	#define numbOfUserSerialPorts    1																		// VEX_PIC

	#undef  ARMCPU																												// VEX_PIC
	#undef  AVRCPU																												// VEX_PIC
	#undef  STM8CPU																												// VEX_PIC
	#undef  Spare1CPU																											// VEX_PIC
	#undef  Spare2CPU																											// VEX_PIC
	#undef  Spare3CPU																											// VEX_PIC
  #undef  useParmForCurrOpPtr																						// VEX_PIC

#elif defined(VEX2) || defined(STM3210E) || defined(VEXPro)

  #define romtype																												// VEX_CORTEX
  #define ramtype																												// VEX_CORTEX
  #define neartype																											// VEX_CORTEX
  #define ramfunc __ramfunc																							// VEX_CORTEX
  #define no_init __no_init																							// VEX_CORTEX
  //#undef inline																												// VEX_CORTEX

  #define bMotorMirroring																								// VEX_CORTEX
  #define bSmartMotorsWithEncoders																			// VEX_CORTEX
  #define bAssociateMotorWithEncoder																		// VEX_CORTEX
  #undef  bAssociateMotorWithIOPins 																		// VEX_CORTEX

  #define kNumbOfBreakpoints 16																					// VEX_CORTEX
  #define bUsesFlashStorage																							// VEX_CORTEX
  #define kFlashSectorSize   0x0800																			// VEX_CORTEX
	#undef  kSystemClockSpeed																							// VEX_CORTEX
	#define genericParmArith																							// VEX_CORTEX
  #define  optionalExceptions 																					// VEX_CORTEX
  #define  optionalBreakpoints 																					// VEX_CORTEX
  #define  optionalDebugSupport																					// VEX_CORTEX
  #define hasBulkUploadlupport																					// VEX_CORTEX
  #define hasOptionalUploadSupport																			// VEX_CORTEX
  #define hasDeviceUploadSupport																				// VEX_CORTEX
  //#undef  optionalTrinaryOpcodes     // to make more space						// VEX_CORTEX
  #undef  optionalInfraredStatistics																		// VEX_CORTEX

  #define bHasSoundSupport																							// VEX_CORTEX
  #define bHasSoundVolume																								// VEX_CORTEX
  #undef  bHasSoundDriverOnOff																					// VEX_CORTEX
  #define bHasSoundFiles																								// VEX_CORTEX
  #define kSoundQueueSize 10																						// VEX_CORTEX

	#define useFloats																											// VEX_CORTEX
	#define useLongs																											// VEX_CORTEX
  #define hasCamera																											// VEX_CORTEX
  #define hasJoystickMessageOpcodes																			// VEX_CORTEX
  #undef  hasHarvardArchitecture   																			// VEX_CORTEX
  #define kMaxTimeBetweenMessageChars 300																// VEX_CORTEX
  #define hasStringSupport																							// VEX_CORTEX
  #define hasDebugStreamSupport																					// VEX_CORTEX
	#define kDebugStreamBufferSize 2000																		// VEX_CORTEX
  #define hasTranscendentalSupport																			// VEX_CORTEX
  #define kRamBaseAddr 0x20000000																				// VEX_CORTEX
	#undef  bHasDatalog																										// VEX_CORTEX
  #undef  bSpareFlagXX																									// VEX_CORTEX

  #define hasAlphaNumericLCDDisplayViaUART															// VEX_CORTEX
  #undef   hasStatusLEDs																								// VEX_CORTEX
  #undef  bUseLookupBreakpointTableInRAM																// VEX_CORTEX
  #define nnRobotType	rbtTypeVEX2_0																			// VEX_CORTEX
  #undef  hasSpareOption3																								// VEX_CORTEX
  #undef  hasSpareOption4																								// VEX_CORTEX
  #undef  hasSpareOption5																								// VEX_CORTEX
  #undef  hasSpareOption6																								// VEX_CORTEX
  #undef  hasSpareOption7																								// VEX_CORTEX
  #undef  hasSpareOption8																								// VEX_CORTEX
  #undef  hasSpareOption9																								// VEX_CORTEX
	#define kSizeOfXmitBufferUserUart 35																	// VEX_CORTEX
	#define kRcvBufferSizeUserUart    40																	// VEX_CORTEX
	#undef  bHasLCDGraphicsDisplay																				// VEX_CORTEX
	#undef  bHasLCDContrast																								// VEX_CORTEX
	#define bHasRemoteButtons																							// VEX_CORTEX

	#define bHasStandardBatteryMonitoring																	// VEX_CORTEX

	#define bHasFastSonarSensor																						// VEX_CORTEX
	#define bHasSensorBiasSettings																				// VEX_CORTEX
	#define sensorHandlerWorkBetweenOpcodes()															// VEX_CORTEX

	#define kNumbAnalogSensors 	 8																				// VEX_CORTEX
	#define kNumbDigitalSensors 12																				// VEX_CORTEX

	#define bHasSystemTaskForUserProgramComplete													// VEX_CORTEX
	#undef  kScreenWidth																									// VEX_CORTEX
	#undef  kScreenHeight																									// VEX_CORTEX
	#undef  bHasSemaphoreSupport																					// VEX_CORTEX
  #define kMaxBytesPerDataBytesUpload   251															// VEX_CORTEX
	#define bHasMultRobotNetworking																				// VEX_CORTEX
	#define kReceivedOpcodeSize           262															// VEX_CORTEX
	#undef  bGetClearVariablesOnPgmStart																	// VEX_CORTEX
	#undef  spareOption9																									// VEX_CORTEX
	#undef  spareOption10																									// VEX_CORTEX

  #define kNumbOfTasks									(20)														// VEX_CORTEX
  #define kNumbOfGlobalVariables				(1000)													// VEX_CORTEX
  #define kNumbOfPrograms								(16)														// VEX_CORTEX
  #define kNumbOfTaskVariables					(0)															// VEX_CORTEX
  #define kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors)// VEX_CORTEX
  #define kNumbOfRealMotors             (10)														// VEX_CORTEX
  #define kNumbOfRealServos             ((ubyte) 10)										// VEX_CORTEX
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// VEX_CORTEX
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// VEX_CORTEX
  #define kTaskVariablesStart   				((uword) 40)										// VEX_CORTEX

  #define bHasFlashFileSystem																						// VEX_CORTEX
	#define kMaxNumbofFlashFiles					64															// VEX_CORTEX
  #define kVTOCItemSize									4																// VEX_CORTEX

  #undef  bHasEvents																										// VEX_CORTEX
  #define kDefaultTaskStackSizeInEntries 30															// VEX_CORTEX
  #define kConstantPoolSize  						3200        										// VEX_CORTEX
  #define kStartOfFileSystem 						0x08030000											// VEX_CORTEX
	#undef  kStartOfBootloader																						// VEX_CORTEX
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// VEX_CORTEX
	#define kSizeOfXmitBufferPC 					255	// to fit index in single byte	// VEX_CORTEX
	#define kRcvBufferSizePC	 						50															// VEX_CORTEX


	#define hasUserSerialPorts																						// VEX_CORTEX
	#define numbOfUserSerialPorts    2																		// VEX_CORTEX

	#define ARMCPU																												// VEX_CORTEX
	#undef  AVRCPU																												// VEX_CORTEX
	#undef  STM8CPU																												// VEX_CORTEX
	#undef  Spare1CPU																											// VEX_CORTEX
	#undef  Spare2CPU																											// VEX_CORTEX
	#undef  Spare3CPU																											// VEX_CORTEX
  #define useParmForCurrOpPtr																						// VEX_CORTEX

#elif defined(ArduinoMega) || defined(Generic)

	#define romtype   __attribute__((progmem))														// ArduinoMega
	#define ramtype																												// ArduinoMega
  #define neartype																											// ArduinoMega
  #define ramfunc																												// ArduinoMega
  #define no_init																												// ArduinoMega
  //#undef inline																												// ArduinoMega

  #define bMotorMirroring
  #define bSmartMotorsWithEncoders																			// ArduinoMega
  #define bAssociateMotorWithEncoder																		// ArduinoMega
  #define bAssociateMotorWithIOPins 																		// ArduinoMega

  #define kNumbOfBreakpoints 6																					// ArduinoMega
  #define bUsesFlashStorage																							// ArduinoMega
  #define kFlashSectorSize   256       				// 128 words (16-bits)		// ArduinoMega
	#define kSystemClockSpeed  16000000L																	// ArduinoMega
	#define genericParmArith																							// ArduinoMega
  #define  optionalExceptions 																					// ArduinoMega
  #define  optionalBreakpoints 																					// ArduinoMega
  #define  optionalDebugSupport																					// ArduinoMega
  #define hasBulkUploadlupport																					// ArduinoMega
  #define hasOptionalUploadSupport																			// ArduinoMega
  #define hasDeviceUploadSupport																				// ArduinoMega
  //#undef  optionalTrinaryOpcodes     // to make more space						// ArduinoMega
  #undef  optionalInfraredStatistics																		// ArduinoMega

  #define bHasSoundSupport																							// ArduinoMega
  #undef  bHasSoundVolume																								// ArduinoMega
  #undef  bHasSoundDriverOnOff																					// ArduinoMega
  #undef  bHasSoundFiles																								// ArduinoMega
  #define kSoundQueueSize 5																							// ArduinoMega


	#define useFloats																											// ArduinoMega
  #define useLongs																											// ArduinoMega
  #undef  hasCamera																											// ArduinoMega
  #undef  hasJoystickMessageOpcodes																			// ArduinoMega
  #define hasHarvardArchitecture																				// ArduinoMega
  #define kMaxTimeBetweenMessageChars 15																// ArduinoMega
  #define hasStringSupport																							// ArduinoMega
  #define hasDebugStreamSupport																					// ArduinoMega
	#define kDebugStreamBufferSize 300																		// ArduinoMega
  #define hasTranscendentalSupport																			// ArduinoMega
  #define kRamBaseAddr 0																								// ArduinoMega
	#undef  bHasDatalog																										// ArduinoMega
  #undef  bSpareFlagXX																									// ArduinoMega

  #undef  hasAlphaNumericLCDDisplayViaUART															// ArduinoMega
  #undef   hasStatusLEDs																								// ArduinoMega
  #undef  bUseLookupBreakpointTableInRAM																// ArduinoMega
  #define nnRobotType	rbtTypeArduino																		// ArduinoMega
  #undef  hasSpareOption3																								// ArduinoMega
  #undef  hasSpareOption4																								// ArduinoMega
  #undef  hasSpareOption5																								// ArduinoMega
  #undef  hasSpareOption6																								// ArduinoMega
  #undef  hasSpareOption7																								// ArduinoMega
  #undef  hasSpareOption8																								// ArduinoMega
  #undef  hasSpareOption9																								// ArduinoMega
	#define kSizeOfXmitBufferUserUart 25																	// ArduinoMega
	#define kRcvBufferSizeUserUart    30																	// ArduinoMega
	#define bHasLCDGraphicsDisplay																				// ArduinoMega
	#define bHasLCDContrast																								// ArduinoMega
	#undef  bHasRemoteButtons																							// ArduinoMega

	#undef  bHasStandardBatteryMonitoring

	#define bHasFastSonarSensor																						// ArduinoMega
  #define bHasSensorBiasSettings																				// ArduinoMega
	#define sensorHandlerWorkBetweenOpcodes()															// ArduinoMega

	#define kNumbAnalogSensors 	 8																				// ArduinoMega
	#define kNumbDigitalSensors  8																				// ArduinoMega

	#define bHasSystemTaskForUserProgramComplete													// ArduinoMega
	#define kScreenWidth    84																						// ArduinoMega
	#define kScreenHeight   48																						// ArduinoMega
	#undef  bHasSemaphoreSupport																					// ArduinoMega
  #define kMaxBytesPerDataBytesUpload   65															// ArduinoMega
	#define bHasMultRobotNetworking																				// ArduinoMega
	#define kReceivedOpcodeSize           70															// ArduinoMega
	#define bGetClearVariablesOnPgmStart()   true													// ArduinoMega
	#undef  spareOption9																									// ArduinoMega
	#undef  spareOption10																									// ArduinoMega

  #define kNumbOfTasks									(6)															// ArduinoMega
  #define kNumbOfGlobalVariables				(512)														// ArduinoMega
  #define kNumbOfPrograms								(16)														// ArduinoMega
  #define kNumbOfTaskVariables					(0)															// ArduinoMega
  #define kNumbOfRealSensors            (8)															// ArduinoMega
  #define kNumbOfRealMotors             (8)															// ArduinoMega
  #define kNumbOfRealServos             ((ubyte) 8)											// ArduinoMega
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoMega
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoMega
  #define kTaskVariablesStart   				((uword) 40)										// ArduinoMega

  #define bHasFlashFileSystem																						// ArduinoMega
	#define kMaxNumbofFlashFiles					16															// ArduinoMega
  #define kVTOCItemSize									4																// ArduinoMega

  #undef  bHasEvents																										// ArduinoMega
  #define kDefaultTaskStackSizeInEntries 16															// ArduinoMega
  #define kConstantPoolSize  						300															// ArduinoMega
  #define kStartOfFileSystem 						0x010000// Byte (and not word) address// ArduinoMega
	#define kStartOfBootloader						0x0001F800											// ArduinoMega
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoMega
	#define kSizeOfXmitBufferPC 	70																			// ArduinoMega
	#define kRcvBufferSizePC	 		25																			// ArduinoMega

	#undef  hasUserSerialPorts																						// ArduinoMega
	#define numbOfUserSerialPorts    0																		// ArduinoMega

	#undef  ARMCPU																												// ArduinoMega
	#define AVRCPU																												// ArduinoMega
	#undef  STM8CPU																												// ArduinoMega
	#undef  Spare1CPU																											// ArduinoMega
	#undef  Spare2CPU																											// ArduinoMega
	#undef  Spare3CPU																											// ArduinoMega
  #define useParmForCurrOpPtr																						// ArduinoMega

	#define ceilf     ceil																								// ArduinoMega
	#define floorf    floor																								// ArduinoMega

#elif defined(RoboCub)

	#define romtype   __attribute__((progmem))														// RoboCub
	#define ramtype																												// RoboCub
  #define neartype																											// RoboCub
  #define ramfunc																												// RoboCub
  #define no_init																												// RoboCub
  //#undef inline																												// RoboCub

  #define bMotorMirroring																								// RoboCub
  #define bSmartMotorsWithEncoders																			// RoboCub
  #define bAssociateMotorWithEncoder																		// RoboCub
  #define bAssociateMotorWithIOPins 																		// RoboCub

  #define kNumbOfBreakpoints 6																					// RoboCub
  #define bUsesFlashStorage																							// RoboCub
  #define kFlashSectorSize   256  // 128 words (16-bits)								// RoboCub
  #define kSystemClockSpeed  20000000L																	// RoboCub
	#define genericParmArith																							// RoboCub
  #define  optionalExceptions 																					// RoboCub
  #define  optionalBreakpoints 																					// RoboCub
  #define  optionalDebugSupport																					// RoboCub
  #define hasBulkUploadlupport																					// RoboCub
  #define hasOptionalUploadSupport																			// RoboCub
  #define hasDeviceUploadSupport																				// RoboCub
  //#undef  optionalTrinaryOpcodes 																			// RoboCub
  #undef  optionalInfraredStatistics																		// RoboCub

  #define bHasSoundSupport																							// RoboCub
  #undef	bHasSoundVolume																								// RoboCub
  #undef  bHasSoundDriverOnOff																					// RoboCub
  #undef  bHasSoundFiles																								// RoboCub
  #define kSoundQueueSize 5																							// RoboCub

	#define useFloats																											// RoboCub
  #define useLongs																											// RoboCub
  #undef  hasCamera																											// RoboCub
  #undef  hasJoystickMessageOpcodes																			// RoboCub
  #define hasHarvardArchitecture																				// RoboCub
  #define kMaxTimeBetweenMessageChars 15																// RoboCub
  #define hasStringSupport																							// RoboCub
  #define hasDebugStreamSupport																					// RoboCub
	#define kDebugStreamBufferSize 300																		// RoboCub
  #define hasTranscendentalSupport																			// RoboCub
  #define kRamBaseAddr 0																								// RoboCub
	#undef  bHasDatalog																										// RoboCub
  #undef  bSpareFlagXX																									// RoboCub

  #undef  hasAlphaNumericLCDDisplayViaUART															// RoboCub
  #define hasStatusLEDs																									// RoboCub
  #undef  bUseLookupBreakpointTableInRAM																// RoboCub
  #define nnRobotType	rbtTypeArduino																		// RoboCub
  #undef  hasSpareOption3																								// RoboCub
  #undef  hasSpareOption4																								// RoboCub
  #undef  hasSpareOption5																								// RoboCub
  #undef  hasSpareOption6																								// RoboCub
  #undef  hasSpareOption7																								// RoboCub
  #undef  hasSpareOption8																								// RoboCub
  #undef  hasSpareOption9																								// RoboCub
	#define kSizeOfXmitBufferUserUart 25																	// RoboCub
	#define kRcvBufferSizeUserUart    30																	// RoboCub
	#define bHasLCDGraphicsDisplay																				// RoboCub
	#define bHasLCDContrast																								// RoboCub
	#undef  bHasRemoteButtons																							// RoboCub

	#define bHasStandardBatteryMonitoring 																// RoboCub

	#define bHasFastSonarSensor																						// RoboCub
  #define bHasSensorBiasSettings																				// RoboCub
	#define sensorHandlerWorkBetweenOpcodes()															// RoboCub

	#define kNumbAnalogSensors 	 6																				// RoboCub
	#define kNumbDigitalSensors  2																				// RoboCub

	#define bHasSystemTaskForUserProgramComplete													// RoboCub
	#define kScreenWidth    84																						// RoboCub
	#define kScreenHeight   48																						// RoboCub
	#undef  bHasSemaphoreSupport																					// RoboCub
  #define kMaxBytesPerDataBytesUpload   65															// RoboCub
	#define bHasMultRobotNetworking																				// RoboCub
	#define kReceivedOpcodeSize           70															// RoboCub
	#define bGetClearVariablesOnPgmStart()   true													// RoboCub
	#undef  spareOption9																									// RoboCub
	#undef  spareOption10																									// RoboCub

  #define kNumbOfTasks									(6)															// RoboCub
  #define kNumbOfGlobalVariables				(512)														// RoboCub
  #define kNumbOfPrograms								(16)														// RoboCub
  #define kNumbOfTaskVariables					(0)															// RoboCub
  #define kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors) // RoboCub
  #define kNumbOfRealMotors             (8)															// RoboCub
  #define kNumbOfRealServos             ((ubyte) 8)											// RoboCub
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// RoboCub
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// RoboCub
  #define kTaskVariablesStart   				((uword) 40)										// RoboCub

  #define bHasFlashFileSystem																						// RoboCub
	#define kMaxNumbofFlashFiles					16															// RoboCub
  #define kVTOCItemSize									4																// RoboCub

  #undef  bHasEvents																										// RoboCub
  #define kDefaultTaskStackSizeInEntries 16															// RoboCub
  #define kConstantPoolSize  						300															// RoboCub
  #define kStartOfFileSystem 						0x010000	 // Byte (and not word) address	 // RoboCub																															// RoboCub
	#define kStartOfBootloader						0x0001F800											// RoboCub
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// RoboCub
	#define kSizeOfXmitBufferPC 	70																			// RoboCub
	#define kRcvBufferSizePC	 		25																			// RoboCub

	#undef  hasUserSerialPorts																						// RoboCub
	#define numbOfUserSerialPorts    0																		// RoboCub

	#undef  ARMCPU																												// RoboCub
	#define AVRCPU																												// RoboCub
	#undef  STM8CPU																												// RoboCub
	#undef  Spare1CPU																											// RoboCub
	#undef  Spare2CPU																											// RoboCub
	#undef  Spare3CPU																											// RoboCub
  #define useParmForCurrOpPtr																						// RoboCub

	#define ceilf     ceil																								// RoboCub
	#define floorf    floor																								// RoboCub

#elif defined(Arduino2009)

	#define romtype   __attribute__((progmem))														// Arduino2009
  #if !defined (__AVR_ATmega328P__)
	  //#error "Wrong or missing AVR type specified for 'Arduino2009' project compile"
	#endif																																// Arduino2009
	#define ramtype																												// Arduino2009
  #define neartype																											// Arduino2009
  #define ramfunc																												// Arduino2009
  #define no_init																												// Arduino2009
  //#undef inline																												// Arduino2009

  #define bMotorMirroring																								// Arduino2009
  #define bSmartMotorsWithEncoders																			// Arduino2009
  #define bAssociateMotorWithEncoder																		// Arduino2009
  #define bAssociateMotorWithIOPins 																		// Arduino2009

  #define kNumbOfBreakpoints 6																					// Arduino2009
  #define bUsesFlashStorage																							// Arduino2009
  #define kFlashSectorSize   128        // 64 words (16-bits)						// Arduino2009
	#define  kSystemClockSpeed  16000000L																	// Arduino2009
	#define genericParmArith																							// Arduino2009
  #define  optionalExceptions 																					// Arduino2009
  #define  optionalBreakpoints 																					// Arduino2009
  #define  optionalDebugSupport																					// Arduino2009
  #define hasBulkUploadlupport																					// Arduino2009
  #define hasOptionalUploadSupport																			// Arduino2009
  #define hasDeviceUploadSupport																				// Arduino2009
  //#undef  optionalTrinaryOpcodes     // to make more space						// Arduino2009
  #undef  optionalInfraredStatistics																		// Arduino2009

  #define bHasSoundSupport																							// Arduino2009
  #undef  bHasSoundVolume																								// Arduino2009
  #undef  bHasSoundDriverOnOff																					// Arduino2009
  #undef  bHasSoundFiles																								// Arduino2009
  #define kSoundQueueSize 5																							// Arduino2009

	#undef  useFloats																											// Arduino2009
	#undef  useLongs																											// Arduino2009
  #undef  hasCamera																											// Arduino2009
  #undef  hasJoystickMessageOpcodes																			// Arduino2009
  #define hasHarvardArchitecture																				// Arduino2009
  #define kMaxTimeBetweenMessageChars 15																// Arduino2009
  #undef  hasStringSupport																							// Arduino2009
  #undef  hasDebugStreamSupport																					// Arduino2009
	#undef  kDebugStreamBufferSize  																			// Arduino2009
  #undef  hasTranscendentalSupport 																			// Arduino2009
  #define kRamBaseAddr 0																								// Arduino2009
	#undef  bHasDatalog																										// Arduino2009
  #undef  bSpareFlagXX																									// Arduino2009

  #undef  hasAlphaNumericLCDDisplayViaUART															// Arduino2009
  #undef   hasStatusLEDs																								// Arduino2009
  #undef  bUseLookupBreakpointTableInRAM																// Arduino2009
  #define nnRobotType rbtTypeArduino																		// Arduino2009
  #undef  hasSpareOption3																								// Arduino2009
  #undef  hasSpareOption4																								// Arduino2009
  #undef  hasSpareOption5																								// Arduino2009
  #undef  hasSpareOption6																								// Arduino2009
  #undef  hasSpareOption7																								// Arduino2009
  #undef  hasSpareOption8																								// Arduino2009
  #undef  hasSpareOption9																								// Arduino2009
	#define kSizeOfXmitBufferUserUart 25																	// Arduino2009
	#define kRcvBufferSizeUserUart    30																	// Arduino2009
  #undef  bHasLCDGraphicsDisplay																				// Arduino2009
  #undef  bHasLCDContrast																								// Arduino2009
  #undef  bHasRemoteButtons																							// Arduino2009

	#undef  bHasStandardBatteryMonitoring																	// Arduino2009

	#define bHasFastSonarSensor																						// Arduino2009
  #define bHasSensorBiasSettings																				// Arduino2009
	#define sensorHandlerWorkBetweenOpcodes()															// Arduino2009

	#define kNumbAnalogSensors 	 6																				// Arduino2009
	#define kNumbDigitalSensors  14																				// Arduino2009

	#define bHasSystemTaskForUserProgramComplete													// Arduino2009
	#define kScreenWidth    84																						// Arduino2009
	#define kScreenHeight   48																						// Arduino2009
	#undef  bHasSemaphoreSupport																					// Arduino2009
  #define kMaxBytesPerDataBytesUpload   65															// Arduino2009
	#define bHasMultRobotNetworking																				// Arduino2009
	#define kReceivedOpcodeSize           70															// Arduino2009
	#define bGetClearVariablesOnPgmStart()   true													// Arduino2009
	#undef  spareOption9																									// Arduino2009
	#undef  spareOption10																									// Arduino2009

  #define kNumbOfTasks									(6)															// Arduino2009
  #define kNumbOfGlobalVariables				(128)														// Arduino2009
  #define kNumbOfPrograms								(16)														// Arduino2009
  #define kNumbOfTaskVariables					(0)															// Arduino2009
  #define kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors)	// Arduino2009
  #define kNumbOfRealMotors             (6)															// Arduino2009
  #define kNumbOfRealServos             ((ubyte) 0)											// Arduino2009
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// Arduino2009
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// Arduino2009
  #define kTaskVariablesStart   				((uword) 40)										// Arduino2009

  #define bHasFlashFileSystem																						// Arduino2009
	#define kMaxNumbofFlashFiles					16															// Arduino2009
  #define kVTOCItemSize									4																// Arduino2009

	#undef  bHasEvents																										// Arduino2009
  #define kDefaultTaskStackSizeInEntries 8															// Arduino2009
  #undef kConstantPoolSize  						//50     												// Arduino2009
  #define kStartOfFileSystem 						0x00006000											// Arduino2009
	#define kStartOfBootloader						0x00007800											// Arduino2009
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// Arduino2009
	#define kSizeOfXmitBufferPC 	70																			// Arduino2009
	#define kRcvBufferSizePC	 		25																			// Arduino2009

	#undef  hasUserSerialPorts																						// Arduino2009
	#define numbOfUserSerialPorts    0																		// Arduino2009

	#undef  ARMCPU																												// Arduino2009
	#define AVRCPU																												// Arduino2009
	#undef  STM8CPU																												// Arduino2009
	#undef  Spare1CPU																											// Arduino2009
	#undef  Spare2CPU																											// Arduino2009
	#undef  Spare3CPU																											// Arduino2009
  #define useParmForCurrOpPtr																						// Arduino2009

	#define ceilf     ceil																								// Arduino2009
	#define floorf    floor																								// Arduino2009

#elif defined(STM8)

	#define romtype  																											// STM8
	#define ramtype																												// STM8
  #define neartype	__near																							// STM8
  #define ramfunc																												// STM8
  #define no_init		__no_init																						// STM8
  //#undef inline																												// STM8

  #define bMotorMirroring																								// STM8
  #define bSmartMotorsWithEncoders																			// STM8
  #define bAssociateMotorWithEncoder																		// STM8
  #define bAssociateMotorWithIOPins 																		// STM8

  #define kNumbOfBreakpoints 6																					// STM8
  #define bUsesFlashStorage																							// STM8
  #define kFlashSectorSize   128        // 64 words (16-bits)						// STM8
	#define  kSystemClockSpeed  16000000L																	// STM8
	#define genericParmArith																							// STM8
  #define  optionalExceptions 																					// STM8
  #define  optionalBreakpoints 																					// STM8
  #define  optionalDebugSupport																					// STM8
  #define hasBulkUploadlupport																					// STM8
  #define hasOptionalUploadSupport																			// STM8
  #define hasDeviceUploadSupport																				// STM8
  //#undef  optionalTrinaryOpcodes     // to make more space						// STM8
  #undef  optionalInfraredStatistics																		// STM8

	#undef  bHasSoundSupport																							// STM8
  #undef  bHasSoundVolume																								// STM8
  #undef  bHasSoundDriverOnOff																					// STM8
  #undef  bHasSoundFiles																								// STM8
  #define kSoundQueueSize 5																							// STM8

	#undef  useFloats																											// STM8
	#undef  useLongs																											// STM8
  #undef  hasCamera																											// STM8
  #undef  hasJoystickMessageOpcodes																			// STM8
  #undef  hasHarvardArchitecture																				// STM8
  #define kMaxTimeBetweenMessageChars 15																// STM8
  #undef  hasStringSupport																							// STM8
  #undef  hasDebugStreamSupport																					// STM8
	#undef  kDebugStreamBufferSize  																			// STM8
  #undef  hasTranscendentalSupport 																			// STM8
  #define kRamBaseAddr 0																								// STM8
	#undef  bHasDatalog																										// STM8
  #undef  bSpareFlagXX																									// STM8

  #undef  hasAlphaNumericLCDDisplayViaUART															// STM8
  #undef   hasStatusLEDs																								// STM8
  #undef  bUseLookupBreakpointTableInRAM																// STM8
  #define nnRobotType rbtTypeSTM8																				// STM8
  #undef  hasSpareOption3																								// STM8
  #undef  hasSpareOption4																								// STM8
  #undef  hasSpareOption5																								// STM8
  #undef  hasSpareOption6																								// STM8
  #undef  hasSpareOption7																								// STM8
  #undef  hasSpareOption8																								// STM8
  #undef  hasSpareOption9																								// STM8
	//#define kSizeOfXmitBufferUserUart 25																	// STM8
	//#define kRcvBufferSizeUserUart    30																	// STM8
  #undef  bHasLCDGraphicsDisplay																				// STM8
  #undef  bHasLCDContrast																								// STM8
  #undef  bHasRemoteButtons																							// STM8

	#undef  bHasStandardBatteryMonitoring																	// STM8

	#define bHasFastSonarSensor																						// STM8
  #define bHasSensorBiasSettings																				// STM8
	#define sensorHandlerWorkBetweenOpcodes()															// STM8

	#define kNumbAnalogSensors 	 6																				// STM8
	#define kNumbDigitalSensors  7 																				// STM8

	#define bHasSystemTaskForUserProgramComplete													// STM8
	//#define kScreenWidth    84																						// STM8
	//#define kScreenHeight   48																						// STM8
	#undef  bHasSemaphoreSupport																					// STM8
  #define kMaxBytesPerDataBytesUpload   65															// STM8
	#define bHasMultRobotNetworking																				// STM8
	#define kReceivedOpcodeSize           70															// STM8
	#define bGetClearVariablesOnPgmStart()   true													// STM8
	#undef  spareOption9																									// STM8
	#undef  spareOption10																									// STM8

  #define kNumbOfTasks									(4)															// STM8
  #define kNumbOfGlobalVariables				(128)														// STM8
  #define kNumbOfPrograms								(16)														// STM8
  #define kNumbOfTaskVariables					(0)															// STM8
  #define kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors)	// STM8
  #define kNumbOfRealMotors             (6)															// STM8
  #define kNumbOfRealServos             ((ubyte) 0)											// STM8
  #define kNumbOfVirtualSensors         ((ubyte) 0)											// STM8
  #define kNumbOfVirtualMotors          ((ubyte) 0)											// STM8
  #define kTaskVariablesStart   				((uword) 40)										// STM8

  #define bHasFlashFileSystem																						// STM8
	#define kMaxNumbofFlashFiles					16															// STM8
  #define kVTOCItemSize									4																// STM8

	#undef  bHasEvents																										// STM8
  #define kDefaultTaskStackSizeInEntries 8															// STM8
  #undef kConstantPoolSize  						//50     												// STM8
  #define kStartOfFileSystem 						0x00006000											// STM8
	#define kStartOfBootloader						0x00007800											// STM8
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// STM8
	#define kSizeOfXmitBufferPC 	70																			// STM8
	#define kRcvBufferSizePC	 		25																			// STM8

	#undef  hasUserSerialPorts																						// STM8
	#define numbOfUserSerialPorts    0																		// STM8

	#undef  ARMCPU																												// STM8
	#undef  AVRCPU																												// STM8
	#define STM8CPU																												// STM8
	#undef  Spare1CPU																											// STM8
	#undef  Spare2CPU																											// STM8
	#undef  Spare3CPU																											// STM8
  #define useParmForCurrOpPtr																						// STM8

#elif defined(Simulator)

  #define 	romtype																											// Simulator
  #define		ramtype																											// Simulator
  #define		ramfunc																											// Simulator
  #define 	neartype																										// Simulator
  #define 	no_init																											// Simulator
#ifndef __cplusplus
	#define   inline																											// Simulator
#endif

  #define	 bMotorMirroring																							// Simulator
  #define  bSmartMotorsWithEncoders																			// Simulator
  #define  bAssociateMotorWithEncoder																		// Simulator
  #define  bAssociateMotorWithIOPins 																		// Simulator

  #define kNumbOfBreakpoints 16      // Must be the highest number available of any controller. Used by IDE
                                      // Windows cannot support > 16. They take up 16 bits in 32-bit mask word!
  #define kFlashSectorSize   512																				// Simulator
	#define kSystemClockSpeed  16000000L																	// Simulator
	#undef  bUsesFlashStorage																							// Simulator
	#define genericParmArith																							// Simulator
  #define  optionalExceptions 																					// Simulator
  #define  optionalBreakpoints 																					// Simulator
  #define  optionalDebugSupport																					// Simulator
  #define hasBulkUploadlupport																					// Simulator
  #define hasOptionalUploadSupport																			// Simulator
  #define hasDeviceUploadSupport																				// Simulator
  //#undef  optionalTrinaryOpcodes																			// Simulator

  #define bHasSoundSupport																							// Simulator
  #undef  bHasSoundVolume																								// Simulator
  #undef  bHasSoundDriverOnOff																					// Simulator
  #define bHasSoundFiles																								// Simulator
  #define kSoundQueueSize 10																						// Simulator

	#define useFloats																											// Simulator
	#define useLongs																											// Simulator
  #undef  hasCamera																											// Simulator
  #define hasJoystickMessageOpcodes																			// Simulator
  #undef  hasHarvardArchitecture																				// Simulator
  #define kMaxTimeBetweenMessageChars 25																// Simulator
  #define hasStringSupport																							// Simulator
  #define hasDebugStreamSupport																					// Simulator
	#define kDebugStreamBufferSize 2000																		// Simulator
  #define hasTranscendentalSupport																			// Simulator
  #define kRamBaseAddr 0																								// Simulator
	#undef  bHasDatalog																										// Simulator
  #undef  bSpareFlagXX																									// Simulator

  #define  hasAlphaNumericLCDDisplayViaUART															// Simulator
  #define  hasStatusLEDs																								// Simulator
  #define bUseLookupBreakpointTableInRAM																// Simulator
  #define nnRobotType	getEmulatorRobotType()														// Simulator
  #define hasSpareOption3																								// Simulator
  #define hasSpareOption4																								// Simulator
  #define hasSpareOption5																								// Simulator
  #define hasSpareOption6																								// Simulator
  #define hasSpareOption7																								// Simulator
  #define hasSpareOption8																								// Simulator
  #define hasSpareOption9																								// Simulator
	#define  kSizeOfXmitBufferUserUart							25										// Simulator
	#define kRcvBufferSizeUserUart									40										// Simulator
	#define bHasLCDGraphicsDisplay																				// Simulator
	#define bHasLCDContrast																								// Simulator
	#define bHasRemoteButtons																							// Simulator

	#define bHasStandardBatteryMonitoring																	// Simulator

	#define bHasFastSonarSensor																						// Simulator
  #define bHasSensorBiasSettings																				// Simulator
	extern void sensorHandlerWorkBetweenOpcodes(void);										// Simulator

	#define kNumbAnalogSensors 	 8																				// Simulator
	#define kNumbDigitalSensors  8																				// Simulator

	#undef  bHasSystemTaskForUserProgramComplete													// Simulator
	#define kScreenWidth      100																					// Simulator
	#define kScreenHeight			64																					// Simulator
	#undef  bHasSemaphoreSupport																					// Simulator
  #define kMaxBytesPerDataBytesUpload   251															// Simulator
	#undef  bHasMultRobotNetworking																				// Simulator
	#define kReceivedOpcodeSize           400															// Simulator
	#undef  bGetClearVariablesOnPgmStart																	// Simulator
	#undef  spareOption9																									// Simulator
	#undef  spareOption10																									// Simulator

  #define kNumbOfTasks									(20)														// Simulator
  #define kNumbOfGlobalVariables				(7500)													// Simulator
  #define kNumbOfPrograms								(1)															// Simulator
  #define kNumbOfTaskVariables					(16)														// Simulator
  #define kNumbOfRealSensors            (60) 														// Simulator
  #define kNumbOfRealMotors             (40) 														// Simulator
  #define kNumbOfRealServos             ((ubyte) 4 * (4 * 8)) 					// Simulator
  #define kNumbOfVirtualSensors         ((ubyte) 8)											// Simulator
  #define kNumbOfVirtualMotors          ((ubyte) 3)											// Simulator
  #define kTaskVariablesStart   				((uword) 96)										// Simulator

	#define bHasFlashFileSystem																						// Simulator
	#define kMaxNumbofFlashFiles					64															// Simulator
  #define kVTOCItemSize									4																// Simulator

  #undef  bHasEvents																										// Simulator
  #define kDefaultTaskStackSizeInEntries 30															// Simulator

  #define kConstantPoolSize  						3200 														// Simulator
  #define kStartOfFileSystem 						getStartOfFileSystem()					// Simulator
	#undef  kStartOfBootloader																						// Simulator
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// Simulator
	#define kSizeOfXmitBufferPC 					255	// to fit index in single byte	// Simulator
	#define kRcvBufferSizePC	 						255 // to fit index in single byte	// Simulator

	#define hasUserSerialPorts																						// Simulator
	#define numbOfUserSerialPorts					4																// Simulator

	#undef  ARMCPU																												// Simulator
	#undef  AVRCPU																												// Simulator
	#undef  STM8CPU																												// Simulator
	#undef  Spare1CPU																											// Simulator
	#undef  Spare2CPU																											// Simulator
	#undef  Spare3CPU																											// Simulator
  #define useParmForCurrOpPtr																						// Simulator

#elif defined(_WINDOWS)

  #define romtype																												// _WINDOWS
  #define ramtype																												// _WINDOWS
  #define ramfunc																												// _WINDOWS
  #define neartype																											// _WINDOWS
  #define no_init																												// _WINDOWS
  //#undef inline																												// _WINDOWS

  #define bMotorMirroring																								// _WINDOWS
  #define bSmartMotorsWithEncoders																			// _WINDOWS
  #undef  bAssociateMotorWithEncoder																		// _WINDOWS
  #undef  bAssociateMotorWithIOPins 																		// _WINDOWS

  #define kNumbOfBreakpoints 16      // Must be the highest number available of any controller. Used by IDE
                                      // Windows cannot support > 16. They take up 16 bits in 32-bit mask word!
  #define kFlashSectorSize   512																				// _WINDOWS
	#undef  kSystemClockSpeed																							// _WINDOWS
	#undef  bUsesFlashStorage																							// _WINDOWS
	#define genericParmArith																							// _WINDOWS
  #define  optionalExceptions 																					// _WINDOWS
  #define  optionalBreakpoints 																					// _WINDOWS
  #define  optionalDebugSupport																					// _WINDOWS
  #define hasBulkUploadlupport																					// _WINDOWS
  #define hasOptionalUploadSupport																			// _WINDOWS
  #define hasDeviceUploadSupport																				// _WINDOWS
  //#undef  optionalTrinaryOpcodes																			// _WINDOWS

  #define bHasSoundSupport																							// _WINDOWS
  #undef  bHasSoundVolume																								// _WINDOWS
  #undef  bHasSoundDriverOnOff																					// _WINDOWS
  #define bHasSoundFiles																								// _WINDOWS
  #define kSoundQueueSize 10																						// _WINDOWS

	#define useFloats																											// _WINDOWS
	#define useLongs																											// _WINDOWS
  #undef  hasCamera																											// _WINDOWS
  #define hasJoystickMessageOpcodes																			// _WINDOWS
  #undef  hasHarvardArchitecture																				// _WINDOWS
  #define kMaxTimeBetweenMessageChars 25																// _WINDOWS
  #undef  hasStringSupport																							// _WINDOWS
  #undef  hasDebugStreamSupport																					// _WINDOWS
	#undef  kDebugStreamBufferSize																				// _WINDOWS
  #define hasTranscendentalSupport																			// _WINDOWS
  #define kRamBaseAddr 0																								// _WINDOWS
	#define bHasDatalog																										// _WINDOWS
  #undef  bSpareFlagXX																									// _WINDOWS

  #define  hasAlphaNumericLCDDisplayViaUART															// _WINDOWS
	#define  hasStatusLEDs																								// _WINDOWS
  #define bUseLookupBreakpointTableInRAM																// _WINDOWS
  #undef  nnRobotType																										// _WINDOWS
  #define hasSpareOption3																								// _WINDOWS
  #define hasSpareOption4																								// _WINDOWS
  #define hasSpareOption5																								// _WINDOWS
  #define hasSpareOption6																								// _WINDOWS
  #define hasSpareOption7																								// _WINDOWS
  #define hasSpareOption8																								// _WINDOWS
  #define hasSpareOption9																								// _WINDOWS
	#undef  kSizeOfXmitBufferUserUart																			// _WINDOWS
	#undef  kRcvBufferSizeUserUart																				// _WINDOWS
	#define bHasLCDGraphicsDisplay																				// _WINDOWS
	#define bHasLCDContrast																								// _WINDOWS
	#define bHasRemoteButtons																							// _WINDOWS

	#undef  hasUserSerialPorts																						// _WINDOWS

	#define bHasStandardBatteryMonitoring																	// _WINDOWS

	#define bHasFastSonarSensor																						// _WINDOWS
  #undef  bHasSensorBiasSettings																				// _WINDOWS
	#define sensorHandlerWorkBetweenOpcodes()															// _WINDOWS

	#undef  bHasSystemTaskForUserProgramComplete													// _WINDOWS
	#undef  kScreenWidth																									// _WINDOWS
	#undef  kScreenHeight																									// _WINDOWS
	#undef  bHasSemaphoreSupport																					// _WINDOWS
  #define kMaxBytesPerDataBytesUpload   256															// _WINDOWS
	#undef  bHasMultRobotNetworking																				// _WINDOWS
	#define kReceivedOpcodeSize           70															// _WINDOWS
	#undef bGetClearVariablesOnPgmStart	   																// _WINDOWS
	#undef  spareOption9																									// _WINDOWS
	#undef  spareOption10																									// _WINDOWS

  #define kNumbOfTasks									(20)														// _WINDOWS
  #define kNumbOfGlobalVariables				(512)														// _WINDOWS
  #define kNumbOfPrograms								(5)															// _WINDOWS
  #define kNumbOfTaskVariables					(16)														// _WINDOWS
  #define kNumbOfRealSensors            (60) // Max value for any robot or will crash IDE// _WINDOWS
  #define kNumbOfRealMotors             (40) // Max value for any robot or will crash IDE// _WINDOWS
  #define kNumbOfRealServos             ((ubyte) 4 * (4 * 8)) // Max value for any robot or will crash IDE																												// _WINDOWS
  #define kNumbOfVirtualSensors         ((ubyte) 8)											// _WINDOWS
  #define kNumbOfVirtualMotors          ((ubyte) 3)											// _WINDOWS
  #define kTaskVariablesStart   				((uword) 96)										// _WINDOWS

  #undef  bHasFlashFileSystem																						// _WINDOWS
	#define kMaxNumbofFlashFiles					64															// _WINDOWS
  #define kVTOCItemSize									4																// _WINDOWS

	#define bHasEvents																										// _WINDOWS
  #define kDefaultTaskStackSizeInEntries 30															// _WINDOWS

  #define kConstantPoolSize  						3200														// _WINDOWS // Maximum size in bytes of constant pool -- duplicated above in NXT
  #define kStartOfFileSystem 						getStartOfFileSystem()					// _WINDOWS
	#undef  kStartOfBootloader																						// _WINDOWS
  #define bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// _WINDOWS
	#undef  kSizeOfXmitBufferPC																						// _WINDOWS
	#undef  kRcvBufferSizePC																							// _WINDOWS
	#undef  ARMCPU																												// _WINDOWS
	#undef  AVRCPU																												// _WINDOWS
	#undef  STM8CPU																												// _WINDOWS
	#undef  Spare1CPU																											// _WINDOWS
	#undef  Spare2CPU																											// _WINDOWS
	#undef  Spare3CPU																											// _WINDOWS
  #define useParmForCurrOpPtr																						// _WINDOWS

#endif

#if defined(hasHarvardArchitecture)
	#undef  useParmForCurrOpPtr
#endif
//
// Flag to indicate whether serial link communications can be customized. Only relevant to the RCX
// platform.
//
#undef  bSerialLinkCustomizable

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                      Handle dependencies between options
//
//    1. Some options always required for windows
//    2. Some options invalid without 100X firmware version
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

//
// Never support floats and longs without 100X firmware!
//
#if (bDebugAddressAlignment)
  #define validateWordAddress(pAddress) pAddress = (word *) ((unsigned int) pAddress & 0xFFFFFFFE)
  #define validateLongAddress(pAddress) pAddress = (long *) ((unsigned int) pAddress & 0xFFFFFFFC)
#else
  #define validateWordAddress(pAddress)
  #define validateLongAddress(pAddress)
#endif


#if defined(useFloats)
  #define useFloatsOrLongs
#else
  #if defined(useLongs)
    #define useFloatsOrLongs
  #else
    #undef  useFloatsOrLongs
  #endif
#endif


#if defined(bHasEvents)
  #define kNumbOfEvents									((ubyte) 16)
#else
  #undef  kNumbOfEvents
  #undef  kNumbOfVirtualSensors
  #undef  kNumbOfVirtualMotors

  #define kNumbOfEvents									((ubyte) 0)
  #define kNumbOfVirtualSensors         ((ubyte) 0)
  #define kNumbOfVirtualMotors          ((ubyte) 0)
#endif

#define kNumbOfTotalSensors           ((ubyte) (kNumbOfRealSensors + kNumbOfVirtualSensors))

#define kNumbOfTotalMotors            ((ubyte) (kNumbOfRealMotors + kNumbOfVirtualMotors))

#define kNumbOfTimers									((ubyte) 4)

#ifdef __cplusplus
}
#endif

#endif //#ifndef LoadBuildOptions__H_
