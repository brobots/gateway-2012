#ifndef LoadBuildOptions__H_
#define	LoadBuildOptions__H_

#if !(defined(MainIncludes__H_) || defined(RobotCIncludes__H_)) && !defined(_WINDOWS)
	#error "'LoadBuildOptions.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//#define	debugLowSpeed  1				// I2C Debug Trace Enabled
#define	debugLowSpeed  0					// I2C Debug Trace Disabled

//#define	debugMotors  1					// Motor Debug Trace Enabled
#define	debugMotors  0						// Motor Debug Trace Disabled


#define	kNumbOfBasicGlobalVariables		((uword) 32)

#if !(defined(ARM)  || defined(NXT) || defined(TETRIX) || \
      defined(ArduinoMega) || defined(ArduinoSmallMemory) || defined(RoboCub) || defined(Arduino) || defined(Generic) || \
			defined(Simulator) || defined(_WINDOWS) || \
			defined(STM8) || defined(CHIPKITMAX) || \
      defined(VEX2) || defined(VEX) || defined(VEXPro) || defined(STM3210E) || defined(SX256))
   #error("Platform type for compile is illegal")
#endif


#if !defined(enumWord)
  #if defined(ROBOTC) && !defined(enumWord)
    #define	enumWord enum word
  #else
    #define	enumWord enum
  #endif
#endif

//
// Flag to indicate whether platform supports LCD Display
//


//
// Flag to indicate whether user messages are supported (i.e. IR or bluetooth)
//
#if (0) && (defined(NXT))
  #define	bUserMessagesAllowed
#else
  #undef	bUserMessagesAllowed
#endif


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             Toggles to Control Optional Features
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

//
// List of all Toggles
//

#undef	romtype
#undef	ramtype
#undef	neartype
#undef	no_init
#undef	genericParmArith

// Conditional Compile Flags that have significant impact on features and size of firmware file

#undef	hasSupportForMessagingWithRobotcIDE
#undef	optionalExceptions
#undef	optionalBreakpoints
#undef	optionalDebugSupport
#define	optionalSwitchOpcodes
#undef	hasOptionalUploadSupport
#undef	hasBulkUploadlupport
#undef	hasDeviceUploadSupport
#undef	optionalTrinaryOpcodes

#undef	useFloats
#undef	useLongs

#undef	spareOption588
#undef	kSystemClockSpeed

#undef	bMotorMirroring
#undef	bMotorsWithEncoders
#undef	bSmartMotorsWithEncoders
#undef	bAssociateMotorWithEncoder
#undef	bAssociateMotorWithIOPins
#undef	bIncludeMotorTypeInUploadMessage
#undef	bSupportsSoftwareBasedMotorPWM

#undef	bHasSoundSupport
#undef	bHasSoundVolume
#undef	bHasSoundDriverOnOff
#undef	bHasSoundFiles

#undef	bHasZigBeeFeatureSpare0
#undef	bHasZigBeeFeatureSpare1
#undef	bHasZigBeeFeatureSpare2
#undef  kNumbOfZigBeeMessageBuffers

#undef	bSupportsInvokeBootloaderOpcode
#undef	bSupportsFlashWriteOpcodes

#undef	bHasFlashFileSystem
#undef	kMaxNumbofFlashFiles
#undef	kMaxNumbofFlashFiles
#undef	kVTOCItemSize
#undef	kSizeOfFlashMemoryPtr
#undef	kSizeOfRAMMemoryPtr

#define	bDebugAddressAlignment (0)
#undef	hasCamera
#undef	hasJoystickDownloadMessageOpcodes
#undef	hasJoystickUploadMessageOpcodes
#undef	hasHarvardArchitecture
#undef	hasStringSupport
#undef	has_sscanf_Support
#undef	hasDebugStreamSupport
#undef	kDebugStreamBufferSize
#undef	hasTranscendentalSupport
#undef	bHasDatalog
#undef	bHasMessageStatistics
#undef	bSpareFlagXX

#undef	hasAlphaNumericLCDDisplayViaUART
#undef	bHasLCDGraphicsDisplay
#undef	hasLCDBacklight
#undef	kScreenWidth
#undef	kScreenHeight
#undef	kFirstVisibleScreenRow
#undef	kLastVisibleScreenRow
#undef	hasLCDButtons
#undef	hasStatusLEDs
#undef	bHasLCDContrast
#undef	bHasRemoteButtons

#undef	bUseLookupBreakpointTableInRAM
#undef	bHasFloatDuringInactivePWM
#undef	nnRobotType
#undef	bHasServoSpecificSourceTypes
#undef	bHasSourceTypeSensorRawValue
#undef	bHasSourceTypeSensorMode
#undef	hasSpareOption7
#undef	hasSpareOption8
#undef	hasSpareOption9
#undef	kSizeOfXmitBufferUserUart
#undef	kRcvBufferSizeUserUart

#undef	kSizeOfTLargeValue

#undef	bHasStandardBatteryMonitoring
#undef	bHasSoftwareControlledPowerOnOff
#undef	getDefaultPowerDownDelayMinutes

// Flags to control level of sensor support

#undef	sensorHandlerWorkBetweenOpcodes
#undef	bSoftwareMustStartADCConversionCycle
#undef	useSimpleADCArrayLookup
#undef	includeSonarSensorSupport									// For minimal f/w size, this can be discarded
#undef	includeEncoderSensorSupport								// For minimal f/w size, this can be discarded
#undef	includeGyroAndAccelSupport								// For minimal f/w size, this can be discarded
#undef	bHasFastSonarSensor
#undef	bHasSensorBiasSettings

#undef	bHasSystemTaskForUserProgramComplete			// Flags a "system task" event when user program has finised
#undef	bHasSemaphoreSupport
#undef	kReceivedOpcodeSize
#undef	bGetClearVariablesOnPgmStart
#undef	spareOption9
#undef	spareOption10

#undef	bHasMultRobotNetworking
#undef  bSystemUARTSupportsZigBee
#undef	bHasZigBeeSupport
#undef	bHasZigBeeFeatureSpare1
#undef	bHasZigBeeFeatureSpare2
#undef  kNumbOfZigBeeMessageBuffers

#undef	kStartOfFileSystem
#undef	kStartOfBootloader
#undef	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX

#undef	useFastMemoryHandlers
#undef	kSizeOfXmitBufferPC
#undef	kRcvBufferSizePC

#undef	kSizeOfXmitBufferPC
#undef	kRcvBufferSizePC

#undef	hasUserSerialPorts
#undef	numbOfUserSerialPorts
#undef	flipUART0_And_UART1

#undef	ARMCPU
#undef	AVRCPU
#undef	STM8CPU
#undef	Spare1CPU
#undef	Spare2CPU
#undef	Spare3CPU
#undef	useParmForCurrOpPtr

#if defined(NXT) || defined(TETRIX)

  #define	romtype																												// NXT
  #define	ramtype																												// NXT
  #define	ramfunc __ramfunc																							// NXT
  #define	neartype																											// NXT
  #define	no_init __no_init																							// NXT
  //#undef inline																												// NXT

  #define	bMotorMirroring																								// NXT
  #define	bMotorsWithEncoders																						// NXT
  #define	bSmartMotorsWithEncoders																			// NXT
  #undef	bAssociateMotorWithEncoder																		// NXT
  #undef	bAssociateMotorWithIOPins 																		// NXT
  #define	 bIncludeMotorTypeInUploadMessage() false											// NXT
  #undef	 bSupportsSoftwareBasedMotorPWM																// NXT

  #define	kNumbOfBreakpoints 16																					// NXT
  #define	bUsesFlashStorage																							// NXT
  #define	kFlashSectorSize   256																				// NXT
	#undef	kSystemClockSpeed																							// NXT
	#define	genericParmArith																							// NXT
  #undef	bDebugAddressAlignment																				// NXT
  #define	bDebugAddressAlignment (1)																		// NXT

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// NXT
  #define	optionalExceptions 																						// NXT
  #define	optionalBreakpoints 																					// NXT
  #define	optionalDebugSupport																					// NXT
  #define	hasBulkUploadlupport																					// NXT
  #define	hasOptionalUploadSupport																			// NXT
  #undef	hasDeviceUploadSupport																				// NXT
  #define	optionalTrinaryOpcodes																				// NXT

	#define	useFloats																											// NXT
	#define	useLongs																											// NXT
	#define	hasJoystickDownloadMessageOpcodes															// NXT
	#undef	hasJoystickUploadMessageOpcodes																// NXT
  #define	hasStringSupport																							// NXT
  #define	has_sscanf_Support																						// NXT
  #define	hasTranscendentalSupport																			// NXT

  #undef	spareOption588																								// NXT

  #define	bHasSoundSupport																							// NXT
  #define	bHasSoundVolume																								// NXT
  #undef	bHasSoundDriverOnOff																					// NXT
  #define	bHasSoundFiles																								// NXT
  #define	kSoundQueueSize 10																						// NXT

  #undef	hasCamera																											// NXT
  #undef hasHarvardArchitecture																					// NXT
  #define	hasDebugStreamSupport																					// NXT
	#define	kDebugStreamBufferSize 4000																		// NXT
  #define	kRamBaseAddr 0																								// NXT
	#define	bHasDatalog																										// NXT
  #undef	bHasMessageStatistics																					// NXT
  #undef	bSpareFlagXX																									// NXT

  #undef	hasAlphaNumericLCDDisplayViaUART															// NXT
	#define	bHasLCDGraphicsDisplay																				// NXT
  #undef	hasLCDBacklight																								// NXT
	#define	kScreenWidth						 100																	// NXT
	#define	kScreenHeight							64																	// NXT
	#define	kFirstVisibleScreenRow()   0																	// NXT
	#define	kLastVisibleScreenRow()    0																	// NXT
  #define	hasLCDButtons																									// NXT
	#define	bHasLCDContrast																								// NXT
	#define	bHasRemoteButtons																							// NXT

	#undef	kSizeOfXmitBufferUserUart																			// NXT
  #undef	bUseLookupBreakpointTableInRAM																// NXT
  #define	bHasFloatDuringInactivePWM																		// NXT
  #define	nnRobotType	rbtTypeNXT																				// NXT
  #define	bHasServoSpecificSourceTypes																	// NXT
  #define	bHasSourceTypeSensorRawValue																	// NXT
  #define	bHasSourceTypeSensorMode																			// NXT
  #undef	hasSpareOption7																								// NXT
  #undef	hasSpareOption8																								// NXT
  #undef	hasSpareOption9																								// NXT
	#undef	kRcvBufferSizeUserUart																				// NXT

	#define	kSizeOfTLargeValue							4															// NXT

	#define	bHasStandardBatteryMonitoring																	// NXT
	#define	bHasSoftwareControlledPowerOnOff															// NXT
	#undef	getDefaultPowerDownDelayMinutes																// NXT

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// NXT
	#undef  bSoftwareMustStartADCConversionCycle													// NXT
	#undef	useSimpleADCArrayLookup																				// NXT
	#define	includeSonarSensorSupport																			// NXT  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// NXT  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// NXT  -- For minimal f/w size, this can be discarded
	#undef	bHasFastSonarSensor																						// NXT
  #undef	bHasSensorBiasSettings																				// NXT

	#define	kNumbAnalogSensors 	 4																				// NXT
	#define	kNumbDigitalSensors  4																				// NXT
	#define	kNumbSensorsOnI2CPorts  0																			// NXT
	#define	kMaxNumbofComplicatedSensors  4																// NXT
  #define	kNumbOfRealSensors            (4)															// NXT

	#undef	bHasSystemTaskForUserProgramComplete													// NXT
	#define	bHasSemaphoreSupport																					// NXT
  #define	kMaxBytesPerDataBytesUpload   59															// NXT
	#define	kReceivedOpcodeSize           70															// NXT
	#undef bGetClearVariablesOnPgmStart																		// NXT
	#undef	spareOption9																									// NXT
	#undef	spareOption10																									// NXT

	#undef	bHasMultRobotNetworking																				// NXT
	#undef	bSystemUARTSupportsZigBee																			// NXT
	#undef	bHasZigBeeFeatureSpare0																				// NXT
	#undef	bHasZigBeeFeatureSpare1																				// NXT
	#undef	bHasZigBeeFeatureSpare2																				// NXT
	#define kNumbOfZigBeeMessageBuffers		0																// NXT

	#define	kNumbOfTasks									(20)														// NXT
  #define	kNumbOfGlobalVariables				(7500)													// NXT
  #define	kNumbOfPrograms								(1)															// NXT
  #define	kNumbOfTaskVariables					(16)														// NXT
  #define	kNumbOfRealMotors             (3)															// NXT
  #define	kNumbOfRealServos             ((ubyte) 4 * 4 * 8)							// NXT
  #define	kNumbOfVirtualSensors         ((ubyte) 8)											// NXT
  #define	kNumbOfVirtualMotors          ((ubyte) (4 * 4 * 2))						// NXT
  #define	kTaskVariablesStart 					((uword) 96)										// NXT

	#undef	bSupportsInvokeBootloaderOpcode																// NXT

  #define	bSupportsFlashWriteOpcodes																		// NXT

  #undef	bHasFlashFileSystem																						// NXT
	#undef	kMaxNumbofFlashFiles																					// NXT
  #undef	kVTOCItemSize 																								// NXT
  #define	 kSizeOfFlashMemoryPtr 4 																			// NXT
  #define	 kSizeOfRAMMemoryPtr	 4 																			// NXT

	#define	bHasEvents																										// NXT
  #define	kDefaultTaskStackSizeInEntries 30															// NXT

  #define	kConstantPoolSize  3200  // Maximum size in bytes of constant pool// NXT
  #define	kStartOfFileSystem 		File_System_Start_Needs_To_Be_Defined		// NXT
	#undef	kStartOfBootloader																						// NXT
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// NXT
	#undef	kSizeOfXmitBufferPC																						// NXT
	#undef	kRcvBufferSizePC																							// NXT

	#undef	hasUserSerialPorts																						// NXT
	#define	numbOfUserSerialPorts    0																		// NXT
	#undef	flipUART0_And_UART1																						// NXT

	#define	ARMCPU																												// NXT
	#undef	AVRCPU																												// NXT
	#undef	STM8CPU																												// NXT
	#undef	Spare1CPU																											// NXT
	#undef	Spare2CPU																											// NXT
	#undef	Spare3CPU																											// NXT
  #define	useParmForCurrOpPtr																						// NXT

#elif defined(VEX)

  #define	romtype rom //far																							// VEX_PIC
  #define	ramtype  ram																									// VEX_PIC
  #define	neartype near																									// VEX_PIC
  #define	ramfunc																												// VEX_PIC
  #define	no_init																												// VEX_PIC
  //#undef inline																												// VEX_PIC

  #define	bMotorMirroring																								// VEX_PIC
  #undef	bMotorsWithEncoders																						// VEX_PIC
  #undef	bSmartMotorsWithEncoders																			// VEX_PIC
  #undef	bAssociateMotorWithEncoder																		// VEX_PIC
  #undef	bAssociateMotorWithIOPins 																		// VEX_PIC
  #define	 bIncludeMotorTypeInUploadMessage() false		 									// VEX_PIC
  #undef	 bSupportsSoftwareBasedMotorPWM						 										// VEX_PIC

  #define	kNumbOfBreakpoints 6																					// VEX_PIC
	#undef	kSystemClockSpeed																							// VEX_PIC
	#define	genericParmArith																							// VEX_PIC

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// VEX_PIC
  #define	optionalExceptions 																						// VEX_PIC
  #define	optionalBreakpoints 																					// VEX_PIC
  #define	optionalDebugSupport																					// VEX_PIC
  #define	hasBulkUploadlupport																					// VEX_PIC
  #define	hasOptionalUploadSupport																			// VEX_PIC
  #define	hasDeviceUploadSupport																				// VEX_PIC
  #undef	optionalTrinaryOpcodes 																				// VEX_PIC

	#undef	useFloats																											// VEX_PIC
  #define	 useLongs																											// VEX_PIC
  #undef	hasJoystickDownloadMessageOpcodes															// VEX_PIC
  #undef	hasJoystickUploadMessageOpcodes																// VEX_PIC
  #undef	hasStringSupport																							// VEX_PIC
  #undef	has_sscanf_Support																						// VEX_PIC
  #undef	hasTranscendentalSupport																			// VEX_PIC

  #undef	spareOption588																								// VEX_PIC

  #undef	bHasSoundSupport																							// VEX_PIC
  #undef	bHasSoundVolume																								// VEX_PIC
  #undef	bHasSoundDriverOnOff																					// VEX_PIC
  #undef	bHasSoundFiles																								// VEX_PIC
  #define	kSoundQueueSize 5																							// VEX_PIC

  #undef	hasCamera																											// VEX_PIC
  #define	hasHarvardArchitecture																				// VEX_PIC
  #define	kMaxTimeBetweenMessageChars 75 // 45													// VEX_PIC
  #undef	hasDebugStreamSupport																					// VEX_PIC
	#undef	kDebugStreamBufferSize																				// VEX_PIC
  #define	kRamBaseAddr 0																								// VEX_PIC
	#undef	bHasDatalog																										// VEX_PIC
  #undef	bHasMessageStatistics																					// VEX_PIC
  #undef	bSpareFlagXX																									// VEX_PIC

  #define	hasAlphaNumericLCDDisplayViaUART															// VEX_PIC
	#undef	bHasLCDGraphicsDisplay																				// VEX_PIC
  #define	hasLCDBacklight																								// VEX_PIC
	#undef	kScreenWidth																									// VEX_PIC
	#undef	kScreenHeight																									// VEX_PIC
	#undef	kFirstVisibleScreenRow																				// VEX_PIC
	#undef	kLastVisibleScreenRow																					// VEX_PIC
  #define	hasLCDButtons																									// VEX_PIC
	#undef	hasStatusLEDs																									// VEX_PIC
	#undef	bHasLCDContrast																								// VEX_PIC
	#define	bHasRemoteButtons																							// VEX_PIC

  #undef	bUseLookupBreakpointTableInRAM																// VEX_PIC
  #undef	bHasFloatDuringInactivePWM																		// VEX_PIC
  #define	nnRobotType	rbtTypeVEX0_5																			// VEX_PIC
  #undef	bHasServoSpecificSourceTypes																	// VEX_PIC
  #undef	bHasSourceTypeSensorRawValue																	// VEX_PIC
  #undef	bHasSourceTypeSensorMode																			// VEX_PIC
  #undef	hasSpareOption7																								// VEX_PIC
  #undef	hasSpareOption8																								// VEX_PIC
  #undef	hasSpareOption9																								// VEX_PIC
	#define	kSizeOfXmitBufferUserUart 25																	// VEX_PIC
	#define	kRcvBufferSizeUserUart    15																	// VEX_PIC

	#define	kSizeOfTLargeValue				 2																	// VEX_PIC

	#undef	bHasStandardBatteryMonitoring																	// VEX_PIC
	#undef	bHasSoftwareControlledPowerOnOff															// VEX_PIC
	#undef	getDefaultPowerDownDelayMinutes																// VEX_PIC

	// Flags to control level of sensor support

	extern void sensorHandlerWorkBetweenOpcodes(void);										// VEX_PIC
	#define bSoftwareMustStartADCConversionCycle													// VEX_PIC
	#undef	useSimpleADCArrayLookup																				// VEX_PIC
	#define	includeSonarSensorSupport																			// VEX_PIC  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// VEX_PIC  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// VEX_PIC  -- For minimal f/w size, this can be discarded
	#undef	bHasFastSonarSensor																						// VEX_PIC
  #define	bHasSensorBiasSettings																				// VEX_PIC

	#define	kNumbAnalogSensors 	 8																				// VEX_PIC
	#define	kNumbDigitalSensors  8																				// VEX_PIC
	#define	kNumbSensorsOnI2CPorts  0																			// VEX_PIC
	#define	kMaxNumbofComplicatedSensors  8																// VEX_PIC
  #define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts) // VEX_PIC

	#define	bHasSystemTaskForUserProgramComplete													// VEX_PIC
	#undef	bHasSemaphoreSupport																					// VEX_PIC
  #define	kMaxBytesPerDataBytesUpload   59															// VEX_PIC
	#define	kReceivedOpcodeSize           70															// VEX_PIC
	#define	bGetClearVariablesOnPgmStart()   false												// VEX_PIC
	#undef	spareOption9																									// VEX_PIC
	#undef	spareOption10																									// VEX_PIC

	#undef	bHasMultRobotNetworking																				// VEX_PIC
	#undef	bSystemUARTSupportsZigBee																			// VEX_PIC
	#undef	bHasZigBeeFeatureSpare0																				// VEX_PIC
	#undef	bHasZigBeeFeatureSpare1																				// VEX_PIC
	#undef	bHasZigBeeFeatureSpare2																				// VEX_PIC
	#define kNumbOfZigBeeMessageBuffers		0																// VEX_PIC

  #define	kNumbOfTasks									(5)															// VEX_PIC
  #define	kNumbOfGlobalVariables				(128)														// VEX_PIC
  #define	kNumbOfPrograms								(16)														// VEX_PIC
  #define	kNumbOfTaskVariables					(0)															// VEX_PIC
  #define	kNumbOfRealMotors             (8)															// VEX_PIC
  #define	kNumbOfRealServos             ((ubyte) 8)											// VEX_PIC
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// VEX_PIC
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// VEX_PIC
  #define	kTaskVariablesStart 					((uword) 40)										// VEX_PIC

	#undef	bSupportsInvokeBootloaderOpcode																// VEX_PIC
	#define	bSupportsFlashWriteOpcodes																		// VEX_PIC

  #define	bHasFlashFileSystem																						// VEX_PIC
  #define	bUsesFlashStorage																							// VEX_PIC
  #define	kFlashSectorSize							64															// VEX_PIC
	#define	kMaxNumbofFlashFiles					12															// VEX_PIC
  #define	kVTOCItemSize									2																// VEX_PIC
  #define	kSizeOfFlashMemoryPtr					2																// VEX_PIC
  #define	kSizeOfRAMMemoryPtr						2																// VEX_PIC

  #undef	bHasEvents																										// VEX_PIC
  #define	kDefaultTaskStackSizeInEntries 12															// VEX_PIC
  #undef	kConstantPoolSize																							// VEX_PIC
  #define	kStartOfFileSystem 						0x00007000											// VEX_PIC
	#undef	kStartOfBootloader																						// VEX_PIC
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// VEX_PIC
	#define	kSizeOfXmitBufferPC 	70																			// VEX_PIC
	#define	kRcvBufferSizePC	 		20																			// VEX_PIC

	#define	hasUserSerialPorts																						// VEX_PIC
	#define	numbOfUserSerialPorts    1																		// VEX_PIC
	#undef	flipUART0_And_UART1																						// VEX_PIC

	#undef	ARMCPU																												// VEX_PIC
	#undef	AVRCPU																												// VEX_PIC
	#undef	STM8CPU																												// VEX_PIC
	#undef	Spare1CPU																											// VEX_PIC
	#undef	Spare2CPU																											// VEX_PIC
	#undef	Spare3CPU																											// VEX_PIC
  #undef	useParmForCurrOpPtr																						// VEX_PIC

#elif defined(VEX2) || defined(VEXPro)

  #define	romtype																												// VEX_CORTEX
  #define	ramtype																												// VEX_CORTEX
  #define	neartype																											// VEX_CORTEX
  #define	ramfunc __ramfunc																							// VEX_CORTEX
  #define	no_init __no_init																							// VEX_CORTEX
  //#undef inline																												// VEX_CORTEX

  #define	bMotorMirroring																								// VEX_CORTEX
  #define	bMotorsWithEncoders																						// VEX_CORTEX
  #undef	bSmartMotorsWithEncoders																			// VEX_CORTEX
  #undef	bAssociateMotorWithEncoder																		// VEX_CORTEX
  #undef	bAssociateMotorWithIOPins 																		// VEX_CORTEX
  #define	 bIncludeMotorTypeInUploadMessage() false		 									// VEX_CORTEX
  #undef	 bSupportsSoftwareBasedMotorPWM						 										// VEX_CORTEX

  #define	kNumbOfBreakpoints 16																					// VEX_CORTEX
	#undef	kSystemClockSpeed																							// VEX_CORTEX
	#define	genericParmArith																							// VEX_CORTEX

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// VEX_CORTEX
  #define	optionalExceptions 																						// VEX_CORTEX
  #define	optionalBreakpoints 																					// VEX_CORTEX
  #define	optionalDebugSupport																					// VEX_CORTEX
  #define	hasBulkUploadlupport																					// VEX_CORTEX
  #define	hasOptionalUploadSupport																			// VEX_CORTEX
  #define	hasDeviceUploadSupport																				// VEX_CORTEX
  #define	optionalTrinaryOpcodes																				// VEX_CORTEX

	#define	useFloats																											// VEX_CORTEX
	#define	useLongs																											// VEX_CORTEX
  #define	hasJoystickDownloadMessageOpcodes															// VEX_CORTEX
  #define	hasJoystickUploadMessageOpcodes																// VEX_CORTEX
  #define	hasStringSupport																							// VEX_CORTEX
  #define	has_sscanf_Support																						// VEX_CORTEX
  #define	hasDebugStreamSupport																					// VEX_CORTEX

  #undef	spareOption588																								// VEX_CORTEX

  #define	bHasSoundSupport																							// VEX_CORTEX
  #define	bHasSoundVolume																								// VEX_CORTEX
  #undef	bHasSoundDriverOnOff																					// VEX_CORTEX
  #define	bHasSoundFiles																								// VEX_CORTEX
  #define	kSoundQueueSize 10																						// VEX_CORTEX

  #define	hasCamera																											// VEX_CORTEX
  #undef	hasHarvardArchitecture 																				// VEX_CORTEX
  #define	kMaxTimeBetweenMessageChars 275																// VEX_CORTEX
	#define	kDebugStreamBufferSize 2000																		// VEX_CORTEX
  #define	hasTranscendentalSupport																			// VEX_CORTEX
  #define	kRamBaseAddr 0x20000000																				// VEX_CORTEX
	#undef	bHasDatalog																										// VEX_CORTEX
  #define	bHasMessageStatistics																					// VEX_CORTEX
  #undef	bSpareFlagXX																									// VEX_CORTEX

  #define	hasAlphaNumericLCDDisplayViaUART															// VEX_CORTEX
	#undef	bHasLCDGraphicsDisplay																				// VEX_CORTEX
  #define	hasLCDBacklight																								// VEX_CORTEX
	#undef	kScreenWidth																									// VEX_CORTEX
	#undef	kScreenHeight																									// VEX_CORTEX
	#undef	kFirstVisibleScreenRow																				// VEX_CORTEX
	#undef	kLastVisibleScreenRow																					// VEX_CORTEX
  #define	hasLCDButtons																									// VEX_CORTEX
  #undef	hasStatusLEDs																									// VEX_CORTEX
	#undef	bHasLCDContrast																								// VEX_CORTEX
	#define	bHasRemoteButtons																							// VEX_CORTEX

	#undef	bUseLookupBreakpointTableInRAM																// VEX_CORTEX
  #undef	bHasFloatDuringInactivePWM																		// VEX_CORTEX
  #define	nnRobotType	rbtTypeVEX2_0																			// VEX_CORTEX
  #undef	bHasServoSpecificSourceTypes																	// VEX_CORTEX
  #undef	bHasSourceTypeSensorRawValue																	// VEX_CORTEX
  #undef	bHasSourceTypeSensorMode																			// VEX_CORTEX
  #undef	hasSpareOption7																								// VEX_CORTEX
  #undef	hasSpareOption8																								// VEX_CORTEX
  #undef	hasSpareOption9																								// VEX_CORTEX
	#define	kSizeOfXmitBufferUserUart 35																	// VEX_CORTEX
	#define	kRcvBufferSizeUserUart    40																	// VEX_CORTEX

	#define	kSizeOfTLargeValue				 4																	// VEX_CORTEX

	#define	bHasStandardBatteryMonitoring																	// VEX_CORTEX
	#undef	bHasSoftwareControlledPowerOnOff															// VEX_CORTEX
	#undef	getDefaultPowerDownDelayMinutes																// VEX_CORTEX

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// VEX_CORTEX
	#undef  bSoftwareMustStartADCConversionCycle													// VEX_CORTEX
	#undef	useSimpleADCArrayLookup																				// VEX_CORTEX
	#define	includeSonarSensorSupport																			// VEX_CORTEX  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// VEX_CORTEX  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// VEX_CORTEX  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// VEX_CORTEX
	#define	bHasSensorBiasSettings																				// VEX_CORTEX

	#define	kNumbAnalogSensors 	 8																				// VEX_CORTEX
	#define	kNumbDigitalSensors 12																				// VEX_CORTEX
	#define	kNumbSensorsOnI2CPorts 8																			// VEX_CORTEX
	#define	kMaxNumbofComplicatedSensors  12															// VEX_CORTEX
  #define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts) // VEX_CORTEX

	#define	bHasSystemTaskForUserProgramComplete													// VEX_CORTEX
	#define	bHasSemaphoreSupport																					// VEX_CORTEX
  #define	kMaxBytesPerDataBytesUpload   251															// VEX_CORTEX
	#define	kReceivedOpcodeSize           262															// VEX_CORTEX
	#undef	bGetClearVariablesOnPgmStart																	// VEX_CORTEX
	#undef	spareOption9																									// VEX_CORTEX
	#undef	spareOption10																									// VEX_CORTEX

	#define	bHasMultRobotNetworking																				// VEX_CORTEX
	#undef 	bSystemUARTSupportsZigBee																			// VEX_CORTEX
	#undef	bHasZigBeeFeatureSpare0																				// VEX_CORTEX
	#undef	bHasZigBeeFeatureSpare1																				// VEX_CORTEX
	#undef	bHasZigBeeFeatureSpare2																				// VEX_CORTEX
	#define kNumbOfZigBeeMessageBuffers		0																// VEX_CORTEX

	#define	kNumbOfTasks									(20)														// VEX_CORTEX
  #define	kNumbOfGlobalVariables				(1000)													// VEX_CORTEX
  #define	kNumbOfPrograms								(16)														// VEX_CORTEX
  #define	kNumbOfTaskVariables					(0)															// VEX_CORTEX
  #define	kNumbOfRealMotors             (10)														// VEX_CORTEX
  #define	kNumbOfRealServos             ((ubyte) 10)										// VEX_CORTEX
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// VEX_CORTEX
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// VEX_CORTEX
  #define	kTaskVariablesStart 					((uword) 40)										// VEX_CORTEX

	#undef	bSupportsInvokeBootloaderOpcode																// VEX_CORTEX
  #define	bSupportsFlashWriteOpcodes																		// VEX_CORTEX

  #define	bHasFlashFileSystem																						// VEX_CORTEX
  #define	bUsesFlashStorage																							// VEX_CORTEX
  #define	kFlashSectorSize							2048														// VEX_CORTEX
	#define	kMaxNumbofFlashFiles					60															// VEX_CORTEX
  #define	kVTOCItemSize									4																// VEX_CORTEX
  #define	kSizeOfFlashMemoryPtr					4																// VEX_CORTEX
  #define	kSizeOfRAMMemoryPtr						4																// VEX_CORTEX

  #undef	bHasEvents																										// VEX_CORTEX
  #define	kDefaultTaskStackSizeInEntries 30															// VEX_CORTEX
  #define	kConstantPoolSize							3200														// VEX_CORTEX
  #define	kStartOfFileSystem 						0x08030000											// VEX_CORTEX
	#undef	kStartOfBootloader																						// VEX_CORTEX
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// VEX_CORTEX
	#define	kSizeOfXmitBufferPC 					255	// to fit index in single byte	// VEX_CORTEX
	#define	kRcvBufferSizePC	 						50															// VEX_CORTEX

	#define	hasUserSerialPorts																						// VEX_CORTEX
	#define	numbOfUserSerialPorts    2																		// VEX_CORTEX
	#undef	flipUART0_And_UART1																						// VEX_CORTEX

	#define	ARMCPU																												// VEX_CORTEX
	#undef	AVRCPU																												// VEX_CORTEX
	#undef	STM8CPU																												// VEX_CORTEX
	#undef	Spare1CPU																											// VEX_CORTEX
	#undef	Spare2CPU																											// VEX_CORTEX
	#undef	Spare3CPU																											// VEX_CORTEX
  #define	useParmForCurrOpPtr																						// VEX_CORTEX

#elif defined(ArduinoMega) || defined(Generic)

	#define	romtype   __attribute__((progmem))														// ArduinoMega
	#define	ramtype																												// ArduinoMega
  #define	neartype																											// ArduinoMega
  #define	ramfunc																												// ArduinoMega
  #define	no_init																												// ArduinoMega
  //#undef inline																												// ArduinoMega

  #define	bMotorMirroring
  #define	bMotorsWithEncoders																						// ArduinoMega
  #define	bSmartMotorsWithEncoders																			// ArduinoMega
  #define	bAssociateMotorWithEncoder																		// ArduinoMega
  #define	bAssociateMotorWithIOPins 																		// ArduinoMega
  #define	bIncludeMotorTypeInUploadMessage() true		 										// ArduinoMega
	#undef	bSupportsSoftwareBasedMotorPWM					 											// ArduinoMega

  #define	kNumbOfBreakpoints 6																					// ArduinoMega
	#define	kSystemClockSpeed  F_CPU																			// ArduinoMega
	#define	genericParmArith																							// ArduinoMega

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// ArduinoMega
  #define	optionalExceptions 																						// ArduinoMega
  #define	optionalBreakpoints 																					// ArduinoMega
  #define	optionalDebugSupport																					// ArduinoMega
  #define	hasBulkUploadlupport																					// ArduinoMega
  #define	hasOptionalUploadSupport																			// ArduinoMega
  #define	hasDeviceUploadSupport																				// ArduinoMega
  #define	optionalTrinaryOpcodes																				// ArduinoMega

	#define	useFloats																											// ArduinoMega
  #define	useLongs																											// ArduinoMega
  #define	hasJoystickDownloadMessageOpcodes															// ArduinoMega
  #undef	hasJoystickUploadMessageOpcodes																// ArduinoMega
  #define	hasStringSupport																							// ArduinoMega
  #define	has_sscanf_Support																						// ArduinoMega
  #define	hasTranscendentalSupport																			// ArduinoMega

	#undef	spareOption588																								// ArduinoMega

  #undef	bHasSoundSupport																							// ArduinoMega
  #undef	bHasSoundVolume																								// ArduinoMega
  #undef	bHasSoundDriverOnOff																					// ArduinoMega
  #undef	bHasSoundFiles																								// ArduinoMega
  #define	kSoundQueueSize 5																							// ArduinoMega


  #undef	hasCamera																											// ArduinoMega
  #define	hasHarvardArchitecture																				// ArduinoMega
  #define	kMaxTimeBetweenMessageChars 15																// ArduinoMega
  #define	hasDebugStreamSupport																					// ArduinoMega
	#define	kDebugStreamBufferSize 300																		// ArduinoMega
  #define	kRamBaseAddr 0																								// ArduinoMega
	#undef	bHasDatalog																										// ArduinoMega
  #undef	bHasMessageStatistics																					// ArduinoMega
  #undef	bSpareFlagXX																									// ArduinoMega

  #undef	hasAlphaNumericLCDDisplayViaUART															// ArduinoMega
	#define	bHasLCDGraphicsDisplay																				// ArduinoMega
  #define	hasLCDBacklight																								// ArduinoMega
	#define	kScreenWidth							84																	// ArduinoMega
	#define	kScreenHeight							48																	// ArduinoMega
	#define	kFirstVisibleScreenRow()   0																	// ArduinoMega
	#define	kLastVisibleScreenRow()		47																	// ArduinoMega
  #undef	hasLCDButtons																									// ArduinoMega
  #undef	hasStatusLEDs																									// ArduinoMega
	#define	bHasLCDContrast																								// ArduinoMega
	#undef	bHasRemoteButtons																							// ArduinoMega

  #define	bUseLookupBreakpointTableInRAM																// ArduinoMega
  #undef	bHasFloatDuringInactivePWM																		// ArduinoMega
  #define	nnRobotType	rbtTypeArduino																		// ArduinoMega
  #undef	bHasServoSpecificSourceTypes																	// ArduinoMega
  #undef	bHasSourceTypeSensorRawValue																	// ArduinoMega
  #undef	bHasSourceTypeSensorMode																			// ArduinoMega
  #undef	hasSpareOption7																								// ArduinoMega
  #undef	hasSpareOption8																								// ArduinoMega
  #undef	hasSpareOption9																								// ArduinoMega
	#define	kSizeOfXmitBufferUserUart 25																	// ArduinoMega
	#define	kRcvBufferSizeUserUart    30																	// ArduinoMega

	#define	kSizeOfTLargeValue         4																	// ArduinoMega

	#undef	bHasStandardBatteryMonitoring																	// ArduinoMega
	#undef	bHasSoftwareControlledPowerOnOff															// ArduinoMega
	#undef	getDefaultPowerDownDelayMinutes																// ArduinoMega

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// ArduinoMega
	#define bSoftwareMustStartADCConversionCycle													// ArduinoMega
	#define	useSimpleADCArrayLookup																				// ArduinoMega
	#define	includeSonarSensorSupport																			// ArduinoMega  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// ArduinoMega  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// ArduinoMega  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// ArduinoMega
  #define	bHasSensorBiasSettings																				// ArduinoMega

	#define	kNumbAnalogSensors 	 16																				// ArduinoMega
	#define	kNumbDigitalSensors  53																				// ArduinoMega
	#define	kNumbSensorsOnI2CPorts  0																			// ArduinoMega
	#define	kMaxNumbofComplicatedSensors  12															// ArduinoMega
  #define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ArduinoMega

	#define	bHasSystemTaskForUserProgramComplete													// ArduinoMega
	#define	bHasSemaphoreSupport																					// ArduinoMega
  #define	kMaxBytesPerDataBytesUpload   65															// ArduinoMega
	#define	kReceivedOpcodeSize           70															// ArduinoMega
	#define	bGetClearVariablesOnPgmStart()   true													// ArduinoMega
	#undef	spareOption9																									// ArduinoMega
	#undef	spareOption10																									// ArduinoMega

	#undef	bHasMultRobotNetworking																				// ArduinoMega
	#undef	bSystemUARTSupportsZigBee																			// ArduinoMega
	#undef	bHasZigBeeFeatureSpare0																				// ArduinoMega
	#undef	bHasZigBeeFeatureSpare1																				// ArduinoMega
	#undef	bHasZigBeeFeatureSpare2																				// ArduinoMega
	#define kNumbOfZigBeeMessageBuffers		0																// ArduinoMega

  #define	kNumbOfTasks									(4)															// ArduinoMega
  #define	kNumbOfGlobalVariables				(512)														// ArduinoMega
  #define	kNumbOfPrograms								(16)														// ArduinoMega
  #define	kNumbOfTaskVariables					(0)															// ArduinoMega
  #define	kNumbOfRealMotors             (12)														// ArduinoMega
  #define	kNumbOfRealServos             ((ubyte) 9)											// ArduinoMega
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoMega
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoMega
  #define	kTaskVariablesStart 					((uword) 40)										// ArduinoMega

	#define	bSupportsInvokeBootloaderOpcode																// ArduinoMega
	#undef	bSupportsFlashWriteOpcodes																		// ArduinoMega

  #define	bHasFlashFileSystem																						// ArduinoMega
  #define	bUsesFlashStorage																							// ArduinoMega
  #define	kFlashSectorSize							256    // 128 words (16-bits)		// ArduinoMega
	#define	kMaxNumbofFlashFiles					16															// ArduinoMega
  #define	kVTOCItemSize									4																// ArduinoMega
  #define	kSizeOfFlashMemoryPtr					4																// ArduinoMega
  #define	kSizeOfRAMMemoryPtr						2																// ArduinoMega

  #undef	bHasEvents																										// ArduinoMega
  #define	kDefaultTaskStackSizeInEntries 16															// ArduinoMega
  #define	kConstantPoolSize							300															// ArduinoMega
  #define	kStartOfFileSystem 						0x00E000// Byte (and not word) address// ArduinoMega
	#define	kStartOfBootloader						0x0001F800											// ArduinoMega
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoMega
	#define	kSizeOfXmitBufferPC 	70																			// ArduinoMega
	#define	kRcvBufferSizePC	 		40																			// ArduinoMega

	#define	hasUserSerialPorts																						// ArduinoMega
	#define	numbOfUserSerialPorts    3																		// ArduinoMega
	#undef	flipUART0_And_UART1																						// ArduinoMega

	#undef	ARMCPU																												// ArduinoMega
	#define	AVRCPU																												// ArduinoMega
	#undef	STM8CPU																												// ArduinoMega
	#undef	Spare1CPU																											// ArduinoMega
	#undef	Spare2CPU																											// ArduinoMega
	#undef	Spare3CPU																											// ArduinoMega
  #define	useParmForCurrOpPtr																						// ArduinoMega

	#define	ceilf     ceil																								// ArduinoMega
	#define	floorf    floor																								// ArduinoMega

#elif defined(RoboCub)

	#define	romtype   __attribute__((progmem))														// RoboCub
	#define	ramtype																												// RoboCub
  #define	neartype																											// RoboCub
  #define	ramfunc																												// RoboCub
  #define	no_init																												// RoboCub
  //#undef inline																												// RoboCub

  #define	bMotorMirroring																								// RoboCub
  #define	bMotorsWithEncoders																						// RoboCub
  #define	bSmartMotorsWithEncoders																			// RoboCub
  #define	bAssociateMotorWithEncoder																		// RoboCub
  #define	bAssociateMotorWithIOPins 																		// RoboCub
  #define	bIncludeMotorTypeInUploadMessage() true		 										// RoboCub
  #define	bSupportsSoftwareBasedMotorPWM					 											// RoboCub

  #define	kNumbOfBreakpoints 6																					// RoboCub
  #define	kSystemClockSpeed  F_CPU																			// RoboCub
	#define	genericParmArith																							// RoboCub

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// RoboCub
  #define	optionalExceptions 																						// RoboCub
  #define	optionalBreakpoints 																					// RoboCub
  #define	optionalDebugSupport																					// RoboCub
  #define	hasBulkUploadlupport																					// RoboCub
  #define	hasOptionalUploadSupport																			// RoboCub
  #define	hasDeviceUploadSupport																				// RoboCub
  #define	optionalTrinaryOpcodes																				// RoboCub

	#define	useFloats																											// RoboCub
  #define	useLongs																											// RoboCub
  #undef	hasJoystickDownloadMessageOpcodes															// RoboCub
  #undef	hasJoystickUploadMessageOpcodes																// RoboCub
  #define	hasStringSupport																							// RoboCub
  #define	has_sscanf_Support																						// RoboCub
  #define	hasTranscendentalSupport																			// RoboCub

	#undef	spareOption588																								// RoboCub

  #define	bHasSoundSupport																							// RoboCub
  #undef	bHasSoundVolume																								// RoboCub
  #undef	bHasSoundDriverOnOff																					// RoboCub
  #undef	bHasSoundFiles																								// RoboCub
  #define	kSoundQueueSize 5																							// RoboCub

  #undef	hasCamera																											// RoboCub
  #define	hasHarvardArchitecture																				// RoboCub
  #define	kMaxTimeBetweenMessageChars 15																// RoboCub
  #define	hasDebugStreamSupport																					// RoboCub
	#define	kDebugStreamBufferSize 300																		// RoboCub
  #define	kRamBaseAddr 0																								// RoboCub
	#undef	bHasDatalog																										// RoboCub
  #undef	bHasMessageStatistics																					// RoboCub
  #undef	bSpareFlagXX																									// RoboCub

  #undef	hasAlphaNumericLCDDisplayViaUART															// RoboCub
	#define	bHasLCDGraphicsDisplay																				// RoboCub
	#define	hasLCDBacklight																								// RoboCub
#ifndef VERSION
	#define	kScreenWidth								84																// RoboCub
	#define	kScreenHeight								48																// RoboCub
	#define	kFirstVisibleScreenRow()		 0																// ArduinoMega
	#define	kLastVisibleScreenRow()			47																// ArduinoMega
#elif (VERSION == 2)
	#define	kScreenWidth								84																// RoboCub
	#define	kScreenHeight								48																// RoboCub
	#define	kFirstVisibleScreenRow()		 0																// RoboCub
	#define	kLastVisibleScreenRow()			47																// ArduinoMega
#elif (VERSION == 3)
	#define	kScreenWidth								84																// RoboCub
	#define	kScreenHeight	 							56																// RoboCub
	#define	kFirstVisibleScreenRow()		 4																// RoboCub
	#define	kLastVisibleScreenRow()			51																// ArduinoMega
#endif
	#define	hasLCDButtons																									// RoboCub
  #define	hasStatusLEDs																									// RoboCub
	#define	bHasLCDContrast																								// RoboCub
	#define	bHasRemoteButtons																							// RoboCub

  #define	bUseLookupBreakpointTableInRAM																// RoboCub
  #undef	bHasFloatDuringInactivePWM																		// RoboCub
  #define	nnRobotType	rbtTypeArduino																		// RoboCub
  #undef	bHasServoSpecificSourceTypes																	// RoboCub
  #undef	bHasSourceTypeSensorRawValue																	// RoboCub
  #undef	bHasSourceTypeSensorMode																			// RoboCub
  #undef	hasSpareOption7																								// RoboCub
  #undef	hasSpareOption8																								// RoboCub
  #undef	hasSpareOption9																								// RoboCub
	#define	kSizeOfXmitBufferUserUart 25																	// RoboCub
	#define	kRcvBufferSizeUserUart    30																	// RoboCub

	#define	kSizeOfTLargeValue				 4																	// RoboCub

	#define	bHasStandardBatteryMonitoring 																// RoboCub
	#define	bHasSoftwareControlledPowerOnOff															// RoboCub
	#define	getDefaultPowerDownDelayMinutes() 10													// RoboCub

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// RoboCub
	#define bSoftwareMustStartADCConversionCycle													// RoboCub
	#define	useSimpleADCArrayLookup																				// RoboCub
	#define	includeSonarSensorSupport																			// RoboCub  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// RoboCub  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// RoboCub  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// RoboCub
  #define	bHasSensorBiasSettings																				// RoboCub

	#define	kNumbAnalogSensors 	 8																				// RoboCub
	#define	kNumbDigitalSensors  14																				// RoboCub
	#define	kNumbSensorsOnI2CPorts  0																			// RoboCub
	#define	kMaxNumbofComplicatedSensors  8																// RoboCub
  #define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts) // RoboCub

	#define	bHasSystemTaskForUserProgramComplete													// RoboCub
	#define	bHasSemaphoreSupport																					// RoboCub
  #define	kMaxBytesPerDataBytesUpload   65															// RoboCub
	#define	kReceivedOpcodeSize           70															// RoboCub
	#define	bGetClearVariablesOnPgmStart()   true													// RoboCub
	#undef	spareOption9																									// RoboCub
	#undef	spareOption10																									// RoboCub

	#define	bHasMultRobotNetworking																				// RoboCub
	#undef	bSystemUARTSupportsZigBee																			// RoboCub
	#undef	bHasZigBeeFeatureSpare0																				// RoboCub
	#undef	bHasZigBeeFeatureSpare1																				// RoboCub
	#undef	bHasZigBeeFeatureSpare2																				// RoboCub
	#define kNumbOfZigBeeMessageBuffers		0																// RoboCub

	#define	kNumbOfTasks									(4)															// RoboCub
  #define	kNumbOfGlobalVariables				(256)														// RoboCub
  #define	kNumbOfPrograms								(16)														// RoboCub
  #define	kNumbOfTaskVariables					(0)															// RoboCub
  #define	kNumbOfRealMotors             (8)															// RoboCub
  #define	kNumbOfRealServos             ((ubyte) 8)											// RoboCub
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// RoboCub
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// RoboCub
  #define	kTaskVariablesStart 					((uword) 40)										// RoboCub

  #define	bSupportsInvokeBootloaderOpcode																// RoboCub
  #define	bSupportsFlashWriteOpcodes																		// RoboCub

  #define	bHasFlashFileSystem																						// RoboCub
  #define	bUsesFlashStorage																							// RoboCub
  #define	kFlashSectorSize							256  // 128 words (16-bits)			// RoboCub
	#define	kMaxNumbofFlashFiles					30															// RoboCub
  #define	kVTOCItemSize									4																// RoboCub
  #define	kSizeOfFlashMemoryPtr					4																// RoboCub
  #define	kSizeOfRAMMemoryPtr						2																// RoboCub

  #undef	bHasEvents																										// RoboCub
  #define	kDefaultTaskStackSizeInEntries 16															// RoboCub
  #define	kConstantPoolSize							300															// RoboCub
  #define	kStartOfFileSystem 						0x00E000	 // Byte (and not word) address	 // RoboCub
	#define	kStartOfBootloader						0x0001F800											// RoboCub
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// RoboCub
	#define	kSizeOfXmitBufferPC 	70																			// RoboCub
	#define	kRcvBufferSizePC	 		25																			// RoboCub

	#undef	hasUserSerialPorts																						// RoboCub
	#define	numbOfUserSerialPorts    0																		// RoboCub
	#define	flipUART0_And_UART1																						// RoboCub

	#undef	ARMCPU																												// RoboCub
	#define	AVRCPU																												// RoboCub
	#undef	STM8CPU																												// RoboCub
	#undef	Spare1CPU																											// RoboCub
	#undef	Spare2CPU																											// RoboCub
	#undef	Spare3CPU																											// RoboCub
  #define	useParmForCurrOpPtr																						// RoboCub

	#define	ceilf     ceil																								// RoboCub
	#define	floorf    floor																								// RoboCub

#elif defined(ArduinoSmallMemory)

	#define	romtype   __attribute__((progmem))														// ArduinoSmallMemory
  #if !defined(__AVR_ATmega328P__)
		//#error "Wrong or missing AVR type specified for 'Arduino2009' project compile"
	#endif																																// ArduinoSmallMemory
	#define	ramtype																												// ArduinoSmallMemory
  #define	neartype																											// ArduinoSmallMemory
  #define	ramfunc																												// ArduinoSmallMemory
  #define	no_init																												// ArduinoSmallMemory
  //#undef inline																												// ArduinoSmallMemory

  #define	bMotorMirroring																								// ArduinoSmallMemory
  #define	bMotorsWithEncoders																						// ArduinoSmallMemory
  #define	bSmartMotorsWithEncoders																			// ArduinoSmallMemory
  #define	bAssociateMotorWithEncoder																		// ArduinoSmallMemory
  #define	bAssociateMotorWithIOPins 																		// ArduinoSmallMemory
  #define	bIncludeMotorTypeInUploadMessage() true		 										// ArduinoSmallMemory
  #undef	bSupportsSoftwareBasedMotorPWM						 										// ArduinoSmallMemory

  #define	kNumbOfBreakpoints 6																					// ArduinoSmallMemory
	#define	kSystemClockSpeed  F_CPU																			// ArduinoSmallMemory
	#define	genericParmArith																							// ArduinoSmallMemory

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// ArduinoSmallMemory
	#define	optionalExceptions 																						// ArduinoSmallMemory
	#define	optionalBreakpoints 																					// ArduinoSmallMemory
	#define	optionalDebugSupport																					// ArduinoSmallMemory
	#define	hasBulkUploadlupport																					// ArduinoSmallMemory
	#define	hasOptionalUploadSupport																			// ArduinoSmallMemory
	#define	hasDeviceUploadSupport																				// ArduinoSmallMemory
  #define	optionalTrinaryOpcodes																				// ArduinoSmallMemory

	#undef	useFloats																											// ArduinoSmallMemory
	#undef	useLongs																											// ArduinoSmallMemory
  #undef	hasJoystickDownloadMessageOpcodes															// ArduinoSmallMemory
  #undef	hasJoystickUploadMessageOpcodes																// ArduinoSmallMemory
  #undef	hasStringSupport																							// ArduinoSmallMemory
  #undef	has_sscanf_Support																						// ArduinoSmallMemory
  #undef	hasTranscendentalSupport 																			// ArduinoSmallMemory

	#undef	spareOption588																								// ArduinoSmallMemory

	#define	bHasSoundSupport																							// ArduinoSmallMemory
  #undef	bHasSoundVolume																								// ArduinoSmallMemory
  #undef	bHasSoundDriverOnOff																					// ArduinoSmallMemory
  #undef	bHasSoundFiles																								// ArduinoSmallMemory
  #define	kSoundQueueSize 5																							// ArduinoSmallMemory

  #undef	hasCamera																											// ArduinoSmallMemory
  #define	hasHarvardArchitecture																				// ArduinoSmallMemory
  #define	kMaxTimeBetweenMessageChars 15																// ArduinoSmallMemory
  #undef	hasDebugStreamSupport																					// ArduinoSmallMemory
	#undef	kDebugStreamBufferSize																				// ArduinoSmallMemory
  #define	kRamBaseAddr 0																								// ArduinoSmallMemory
	#undef	bHasDatalog																										// ArduinoSmallMemory
  #undef	bHasMessageStatistics																					// ArduinoSmallMemory
  #undef	bSpareFlagXX																									// ArduinoSmallMemory

  #undef	hasAlphaNumericLCDDisplayViaUART															// ArduinoSmallMemory
  #undef	bHasLCDGraphicsDisplay																				// ArduinoSmallMemory
  #undef	hasLCDBacklight																								// ArduinoSmallMemory
	#undef	kScreenWidth																									// ArduinoSmallMemory
	#undef	kScreenHeight																									// ArduinoSmallMemory
	#undef	kFirstVisibleScreenRow																				// ArduinoSmallMemory
	#undef	kLastVisibleScreenRow																					// ArduinoSmallMemory
  #undef	hasLCDButtons																									// ArduinoSmallMemory
  #undef	hasStatusLEDs																									// ArduinoSmallMemory
  #undef	bHasLCDContrast																								// ArduinoSmallMemory
  #undef	bHasRemoteButtons																							// ArduinoSmallMemory

  #define	bUseLookupBreakpointTableInRAM																// ArduinoSmallMemory
  #undef	bHasFloatDuringInactivePWM																		// ArduinoSmallMemory
  #define	nnRobotType	rbtTypeArduino																		// ArduinoSmallMemory
  #undef	bHasServoSpecificSourceTypes																	// ArduinoSmallMemory
  #undef	bHasSourceTypeSensorRawValue																	// ArduinoSmallMemory
  #undef	bHasSourceTypeSensorMode																			// ArduinoSmallMemory
  #undef	hasSpareOption7																								// ArduinoSmallMemory
  #undef	hasSpareOption8																								// ArduinoSmallMemory
  #undef	hasSpareOption9																								// ArduinoSmallMemory
	#define	kSizeOfXmitBufferUserUart 25																	// ArduinoSmallMemory
	#define	kRcvBufferSizeUserUart    30																	// ArduinoSmallMemory

	#define	kSizeOfTLargeValue				 2																	// ArduinoSmallMemory

	#undef	bHasStandardBatteryMonitoring																	// ArduinoSmallMemory
	#undef	bHasSoftwareControlledPowerOnOff															// ArduinoSmallMemory
	#undef	getDefaultPowerDownDelayMinutes																	// ArduinoSmallMemory

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// ArduinoSmallMemory
	#define bSoftwareMustStartADCConversionCycle													// ArduinoSmallMemory
	#define	useSimpleADCArrayLookup																				// ArduinoSmallMemory
	#define	includeSonarSensorSupport																			// ArduinoSmallMemory  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// ArduinoSmallMemory  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// ArduinoSmallMemory  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// ArduinoSmallMemory
	#define	bHasSensorBiasSettings																				// ArduinoSmallMemory

	#define	kNumbAnalogSensors 	 6																				// ArduinoSmallMemory
	#define	kNumbDigitalSensors  14																				// ArduinoSmallMemory
	#define	kNumbSensorsOnI2CPorts  0																			// ArduinoSmallMemory
	#define	kMaxNumbofComplicatedSensors  6																// ArduinoSmallMemory
  #define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ArduinoSmallMemory

	#define	bHasSystemTaskForUserProgramComplete													// ArduinoSmallMemory
  #undef	bHasSemaphoreSupport																				  // ArduinoSmallMemory
  #define	kMaxBytesPerDataBytesUpload   65															// ArduinoSmallMemory
	#define	kReceivedOpcodeSize           70															// ArduinoSmallMemory
	#define	bGetClearVariablesOnPgmStart()   true													// ArduinoSmallMemory
	#undef	spareOption9																									// ArduinoSmallMemory
	#undef	spareOption10																									// ArduinoSmallMemory

	#define bHasMultRobotNetworking																				// ArduinoSmallMemory
	#define bSystemUARTSupportsZigBee																			// ArduinoSmallMemory
	#undef	bHasZigBeeFeatureSpare0																				// ArduinoSmallMemory
	#undef	bHasZigBeeFeatureSpare1																				// ArduinoSmallMemory
	#undef	bHasZigBeeFeatureSpare2																				// ArduinoSmallMemory
	#define kNumbOfZigBeeMessageBuffers		0																// ArduinoSmallMemory

  #define	kNumbOfTasks									(4)															// ArduinoSmallMemory
  #define	kNumbOfGlobalVariables				(128)														// ArduinoSmallMemory
  #define	kNumbOfPrograms								(16)														// ArduinoSmallMemory
  #define	kNumbOfTaskVariables					(0)															// ArduinoSmallMemory
  #define	kNumbOfRealMotors             (6)															// ArduinoSmallMemory
  #define	kNumbOfRealServos             ((ubyte) 0)											// ArduinoSmallMemory
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// ArduinoSmallMemory
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// ArduinoSmallMemory
  #define	kTaskVariablesStart 					((uword) 40)										// ArduinoSmallMemory

	#define	bSupportsInvokeBootloaderOpcode																// ArduinoSmallMemory
	#undef	bSupportsFlashWriteOpcodes																		// ArduinoSmallMemory

  #define	bHasFlashFileSystem																						// ArduinoSmallMemory
  #define	bUsesFlashStorage																							// ArduinoSmallMemory
  #define	kFlashSectorSize							128     // 64 words (16-bits)		// ArduinoSmallMemory
	#define	kMaxNumbofFlashFiles					12															// ArduinoSmallMemory
  #define	kVTOCItemSize									4																// ArduinoSmallMemory
  #define	kSizeOfFlashMemoryPtr					2																// ArduinoSmallMemory
  #define	kSizeOfRAMMemoryPtr						2																// ArduinoSmallMemory

	#undef	bHasEvents																										// ArduinoSmallMemory
  #define	kDefaultTaskStackSizeInEntries 8															// ArduinoSmallMemory
  #undef kConstantPoolSize							//50 														// ArduinoSmallMemory
  #define	kStartOfFileSystem 						0x00006000											// ArduinoSmallMemory
	#define	kStartOfBootloader						0x00007800											// ArduinoSmallMemory
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ArduinoSmallMemory
	#define	kSizeOfXmitBufferPC 	70																			// ArduinoSmallMemory
	#define	kRcvBufferSizePC	 		25																			// ArduinoSmallMemory

	#undef	hasUserSerialPorts																						// ArduinoSmallMemory
	#define	numbOfUserSerialPorts    0																		// ArduinoSmallMemory
	#undef	flipUART0_And_UART1																						// ArduinoSmallMemory

	#undef	ARMCPU																												// ArduinoSmallMemory
	#define	AVRCPU																												// ArduinoSmallMemory
	#undef	STM8CPU																												// ArduinoSmallMemory
	#undef	Spare1CPU																											// ArduinoSmallMemory
	#undef	Spare2CPU																											// ArduinoSmallMemory
	#undef	Spare3CPU																											// ArduinoSmallMemory
  #define	useParmForCurrOpPtr																						// ArduinoSmallMemory

	#define	ceilf     ceil																								// ArduinoSmallMemory
	#define	floorf    floor																								// ArduinoSmallMemory

#elif defined(CHIPKITMAX)

	#define	romtype																												// ChipkitMax
	#define	ramtype																												// ChipkitMax
  #define	neartype																											// ChipkitMax
  #define	ramfunc																												// ChipkitMax
  #define	no_init																												// ChipkitMax
  //#undef inline																												// ChipkitMax

  #define	bMotorMirroring
  #define	bMotorsWithEncoders																						// ChipkitMax
  #define	bSmartMotorsWithEncoders																			// ChipkitMax
  #define	bAssociateMotorWithEncoder																		// ChipkitMax
  #define	bAssociateMotorWithIOPins 																		// ChipkitMax
  #define	bIncludeMotorTypeInUploadMessage() true		 										// ChipkitMax
	#undef	bSupportsSoftwareBasedMotorPWM					 											// ChipkitMax

  #define	kNumbOfBreakpoints 6																					// ChipkitMax
	#define	kSystemClockSpeed  (80000000L)																// ChipkitMax
	#define	genericParmArith																							// ChipkitMax

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// ChipkitMax
  #define	optionalExceptions 																						// ChipkitMax
  #define	optionalBreakpoints 																					// ChipkitMax
  #define	optionalDebugSupport																					// ChipkitMax
  #define	hasBulkUploadlupport																					// ChipkitMax
  #define	hasOptionalUploadSupport																			// ChipkitMax
  #define	hasDeviceUploadSupport																				// ChipkitMax
  #define	optionalTrinaryOpcodes																				// ChipkitMax

	#define	useFloats																											// ChipkitMax
  #define	useLongs																											// ChipkitMax
  #define	hasJoystickDownloadMessageOpcodes															// ChipkitMax
  #undef	hasJoystickUploadMessageOpcodes																// ChipkitMax
  #define	hasStringSupport																							// ChipkitMax
  #define	has_sscanf_Support																						// ChipkitMax
  #define	hasTranscendentalSupport																			// ChipkitMax

	#undef	spareOption588																								// ChipkitMax

  #undef	bHasSoundSupport																							// ChipkitMax
  #undef	bHasSoundVolume																								// ChipkitMax
  #undef	bHasSoundDriverOnOff																					// ChipkitMax
  #undef	bHasSoundFiles																								// ChipkitMax
  #define	kSoundQueueSize 5																							// ChipkitMax


  #undef	hasCamera																											// ChipkitMax
  #define	hasHarvardArchitecture																				// ChipkitMax
  #define	kMaxTimeBetweenMessageChars 15																// ChipkitMax
  #define	hasDebugStreamSupport																					// ChipkitMax
	#define	kDebugStreamBufferSize 300																		// ChipkitMax
  #define	kRamBaseAddr 0																								// ChipkitMax
	#undef	bHasDatalog																										// ChipkitMax
  #undef	bHasMessageStatistics																					// ChipkitMax
  #undef	bSpareFlagXX																									// ChipkitMax

  #undef	hasAlphaNumericLCDDisplayViaUART															// ChipkitMax
	#undef	bHasLCDGraphicsDisplay																				// ChipkitMax
  #undef	hasLCDBacklight																								// ChipkitMax
	#define	kScreenWidth							84																	// ChipkitMax
	#define	kScreenHeight							48																	// ChipkitMax
	#define	kFirstVisibleScreenRow()   0																	// ChipkitMax
	#define	kLastVisibleScreenRow()		47																	// ChipkitMax
  #undef	hasLCDButtons																									// ChipkitMax
  #undef	hasStatusLEDs																									// ChipkitMax
	#undef	bHasLCDContrast																								// ChipkitMax
	#undef	bHasRemoteButtons																							// ChipkitMax

  #define	bUseLookupBreakpointTableInRAM																// ChipkitMax
  #undef	bHasFloatDuringInactivePWM																		// ChipkitMax
  #define	nnRobotType	rbtTypeArduino																		// ChipkitMax
  #undef	bHasServoSpecificSourceTypes																	// ChipkitMax
  #undef	bHasSourceTypeSensorRawValue																	// ChipkitMax
  #undef	bHasSourceTypeSensorMode																			// ChipkitMax
  #undef	hasSpareOption7																								// ChipkitMax
  #undef	hasSpareOption8																								// ChipkitMax
  #undef	hasSpareOption9																								// ChipkitMax
	#define	kSizeOfXmitBufferUserUart 25																	// ChipkitMax
	#define	kRcvBufferSizeUserUart    30																	// ChipkitMax

	#define	kSizeOfTLargeValue         4																	// ChipkitMax

	#undef	bHasStandardBatteryMonitoring																	// ChipkitMax
	#undef	bHasSoftwareControlledPowerOnOff															// ChipkitMax
	#undef	getDefaultPowerDownDelayMinutes																// ChipkitMax

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// ChipkitMax
	#define bSoftwareMustStartADCConversionCycle													// ChipkitMax
	#define	useSimpleADCArrayLookup																				// ChipkitMax
	#define	includeSonarSensorSupport																			// ChipkitMax  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// ChipkitMax  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// ChipkitMax  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// ChipkitMax
  #define	bHasSensorBiasSettings																				// ChipkitMax

	#define	kNumbAnalogSensors 	 16																				// ChipkitMax
	#define	kNumbDigitalSensors  53																				// ChipkitMax
	#define	kNumbSensorsOnI2CPorts  0																			// ChipkitMax
	#define	kMaxNumbofComplicatedSensors  12															// ChipkitMax
  #define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// ChipkitMax

	#define	bHasSystemTaskForUserProgramComplete													// ChipkitMax
	#define	bHasSemaphoreSupport																					// ChipkitMax
  #define	kMaxBytesPerDataBytesUpload   65															// ChipkitMax
	#define	kReceivedOpcodeSize           70															// ChipkitMax
	#define	bGetClearVariablesOnPgmStart()   true													// ChipkitMax
	#undef	spareOption9																									// ChipkitMax
	#undef	spareOption10																									// ChipkitMax

	#define	bHasMultRobotNetworking																				// ChipkitMax
	#define	bSystemUARTSupportsZigBee																			// ChipkitMax
	#undef	bHasZigBeeFeatureSpare0																				// ChipkitMax
	#undef	bHasZigBeeFeatureSpare1																				// ChipkitMax
	#undef	bHasZigBeeFeatureSpare2																				// ChipkitMax
	#define kNumbOfZigBeeMessageBuffers		0																// ChipkitMax

  #define	kNumbOfTasks									(10)														// ChipkitMax
  #define	kNumbOfGlobalVariables				(4096)													// ChipkitMax
  #define	kNumbOfPrograms								(16)														// ChipkitMax
  #define	kNumbOfTaskVariables					(0)															// ChipkitMax
  #define	kNumbOfRealMotors             (12)														// ChipkitMax
  #define	kNumbOfRealServos             ((ubyte) 9)											// ChipkitMax
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// ChipkitMax
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// ChipkitMax
  #define	kTaskVariablesStart 					((uword) 40)										// ChipkitMax

	#undef	bSupportsInvokeBootloaderOpcode																// ChipkitMax
	#undef	bSupportsFlashWriteOpcodes																		// ChipkitMax

  #define	bHasFlashFileSystem																						// ChipkitMax
  #define	bUsesFlashStorage																							// ChipkitMax
  #define	kFlashSectorSize							4096														// ChipkitMax
	#define	kMaxNumbofFlashFiles					64															// ChipkitMax
  #define	kVTOCItemSize									4																// ChipkitMax
  #define	kSizeOfFlashMemoryPtr					4																// ChipkitMax
  #define	kSizeOfRAMMemoryPtr						4																// ChipkitMax

  #undef	bHasEvents																										// ChipkitMax
  #define	kDefaultTaskStackSizeInEntries 16															// ChipkitMax
  #define	kConstantPoolSize							300															// ChipkitMax
  #define	kStartOfFileSystem 						0x9D030000											// ChipkitMax
	#define	kStartOfBootloader						0x9D07F000											// ChipkitMax
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// ChipkitMax
	#define	kSizeOfXmitBufferPC 	70																			// ChipkitMax
	#define	kRcvBufferSizePC	 		40																			// ChipkitMax

	#undef	hasUserSerialPorts																						// ChipkitMax
	#define	numbOfUserSerialPorts    0																		// ChipkitMax
	#undef	flipUART0_And_UART1																						// ChipkitMax

	#undef	ARMCPU																												// ChipkitMax
	#undef	AVRCPU																												// ChipkitMax
	#undef	STM8CPU																												// ChipkitMax
	#define	PIC32																													// ChipkitMax
	#undef	Spare1CPU																											// ChipkitMax
	#undef	Spare2CPU																											// ChipkitMax
	#undef	Spare3CPU																											// ChipkitMax
  #define	useParmForCurrOpPtr																						// ChipkitMax

//#define	ceilf     ceil																								// ChipkitMax
//#define	floorf    floor																								// ChipkitMax

#elif defined(STM8)

	#define	romtype																												// STM8
	#define	ramtype																												// STM8
  #define	neartype	__near																							// STM8
  #define	ramfunc																												// STM8
  #define	no_init		__no_init																						// STM8
  //#undef inline																												// STM8

  #define	bMotorMirroring																								// STM8
  #define	bMotorsWithEncoders																						// STM8
  #define	bSmartMotorsWithEncoders																			// STM8
  #define	bAssociateMotorWithEncoder																		// STM8
  #define	bAssociateMotorWithIOPins 																		// STM8
  #define	bIncludeMotorTypeInUploadMessage() true		 										// STM8
  #define	bSupportsSoftwareBasedMotorPWM					 											// STM8

  #define	kNumbOfBreakpoints 6																					// STM8
	#define	 kSystemClockSpeed  16000000L																	// STM8
	#define	genericParmArith																							// STM8

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// STM8
  #define	optionalExceptions 																						// STM8
  #define	optionalBreakpoints 																					// STM8
  #define	optionalDebugSupport																					// STM8
  #define	hasBulkUploadlupport																					// STM8
  #define	hasOptionalUploadSupport																			// STM8
  #define	hasDeviceUploadSupport																				// STM8
  #define	optionalTrinaryOpcodes																				// STM8

	#undef	useFloats																											// STM8
	#undef	useLongs																											// STM8
  #undef	hasJoystickDownloadMessageOpcodes															// STM8
  #undef	hasJoystickUploadMessageOpcodes																// STM8
  #undef	hasStringSupport																							// STM8
  #undef	has_sscanf_Support																						// STM8
  #undef	hasTranscendentalSupport 																			// STM8

	#undef	spareOption588																								// STM8

	#undef	bHasSoundSupport																							// STM8
  #undef	bHasSoundVolume																								// STM8
  #undef	bHasSoundDriverOnOff																					// STM8
  #undef	bHasSoundFiles																								// STM8
  #define	kSoundQueueSize 5																							// STM8

  #undef	hasCamera																											// STM8
  #undef	hasHarvardArchitecture																				// STM8
  #define	kMaxTimeBetweenMessageChars 15																// STM8
  #undef	hasDebugStreamSupport																					// STM8
	#undef	kDebugStreamBufferSize																				// STM8
  #define	kRamBaseAddr 0																								// STM8
	#undef	bHasDatalog																										// STM8
  #undef	bHasMessageStatistics																					// STM8
  #undef	bSpareFlagXX																									// STM8

  #undef	hasAlphaNumericLCDDisplayViaUART															// STM8
  #undef	bHasLCDGraphicsDisplay																				// STM8
  #undef	hasLCDBacklight																								// STM8
	#undef	kScreenWidth																									// STM8
	#undef	kScreenHeight																									// STM8
	#undef	kFirstVisibleScreenRow																				// STM8
	#undef	kLastVisibleScreenRow																					// STM8
  #undef	hasLCDButtons																									// STM8
  #undef	hasStatusLEDs																									// STM8
  #undef	bHasLCDContrast																								// STM8
  #undef	bHasRemoteButtons																							// STM8

  #undef	bUseLookupBreakpointTableInRAM																// STM8
  #undef	bHasFloatDuringInactivePWM																		// STM8
  #define	nnRobotType	rbtTypeArduino																		// STM8
  #undef	bHasServoSpecificSourceTypes																	// STM8
  #undef	bHasSourceTypeSensorRawValue																	// STM8
  #undef	bHasSourceTypeSensorMode																			// STM8
  #undef	hasSpareOption7																								// STM8
  #undef	hasSpareOption8																								// STM8
  #undef	hasSpareOption9																								// STM8
	//#define	kSizeOfXmitBufferUserUart 25																// STM8
	//#define	kRcvBufferSizeUserUart    30																// STM8

	#define	kSizeOfTLargeValue					 2																// STM8

	#undef	bHasStandardBatteryMonitoring																	// STM8
	#undef	bHasSoftwareControlledPowerOnOff															// STM8
	#undef	getDefaultPowerDownDelayMinutes																// STM8

	// Flags to control level of sensor support

	#define	sensorHandlerWorkBetweenOpcodes()															// STM8
	#define bSoftwareMustStartADCConversionCycle													// STM8
	#define	useSimpleADCArrayLookup																				// STM8
	#define	includeSonarSensorSupport																			// STM8  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// STM8  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// STM8  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// STM8
  #define	bHasSensorBiasSettings																				// STM8

	#define	kNumbAnalogSensors 	 6																				// STM8
	#define	kNumbDigitalSensors  7 																				// STM8
	#define	kNumbSensorsOnI2CPorts  4 																		// STM8
	#define	kMaxNumbofComplicatedSensors  6																// STM8
  #define	kNumbOfRealSensors   (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)	// STM8

	#define	bHasSystemTaskForUserProgramComplete													// STM8
	#define	bHasSemaphoreSupport																					// STM8
  #define	kMaxBytesPerDataBytesUpload   65															// STM8
	#define	kReceivedOpcodeSize           70															// STM8
	#define	bGetClearVariablesOnPgmStart()   true													// STM8
	#undef	spareOption9																									// STM8
	#undef	spareOption10																									// STM8

	#define	bHasMultRobotNetworking																				// STM8
	#define	bSystemUARTSupportsZigBee																			// STM8
	#undef	bHasZigBeeFeatureSpare0																				// STM8
	#undef	bHasZigBeeFeatureSpare1																				// STM8
	#undef	bHasZigBeeFeatureSpare2																				// STM8
	#define kNumbOfZigBeeMessageBuffers		0																// STM8

	#define	kNumbOfTasks									(4)															// STM8
  #define	kNumbOfGlobalVariables				(128)														// STM8
  #define	kNumbOfPrograms								(16)														// STM8
  #define	kNumbOfTaskVariables					(0)															// STM8
  #define	kNumbOfRealMotors             (6)															// STM8
  #define	kNumbOfRealServos             ((ubyte) 0)											// STM8
  #define	kNumbOfVirtualSensors         ((ubyte) 0)											// STM8
  #define	kNumbOfVirtualMotors          ((ubyte) 0)											// STM8
  #define	kTaskVariablesStart 					((uword) 40)										// STM8

  #define	bSupportsInvokeBootloaderOpcode																// STM8
  #undef	bSupportsFlashWriteOpcodes																		// STM8

  #define	bHasFlashFileSystem																						// STM8
  #define	bUsesFlashStorage																							// STM8
  #define	kFlashSectorSize							128     // 64 words (16-bits)		// STM8
	#define	kMaxNumbofFlashFiles					30															// STM8
  #define	kVTOCItemSize									4																// STM8
  #define	kSizeOfFlashMemoryPtr					2																// STM8
  #define	kSizeOfRAMMemoryPtr						2																// STM8

	#undef	bHasEvents																										// STM8
  #define	kDefaultTaskStackSizeInEntries 8															// STM8
  #undef kConstantPoolSize							//50 														// STM8
  #define	kStartOfFileSystem 						0x00006000											// STM8
	#define	kStartOfBootloader						0x00007800											// STM8
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// STM8
	#define	kSizeOfXmitBufferPC 	70																			// STM8
	#define	kRcvBufferSizePC	 		25																			// STM8

	#undef	hasUserSerialPorts																						// STM8
	#define	numbOfUserSerialPorts    0																		// STM8
	#undef	flipUART0_And_UART1																						// STM8

	#undef	ARMCPU																												// STM8
	#undef	AVRCPU																												// STM8
	#define	STM8CPU																												// STM8
	#undef	Spare1CPU																											// STM8
	#undef	Spare2CPU																											// STM8
	#undef	Spare3CPU																											// STM8
  #define	useParmForCurrOpPtr																						// STM8

#elif defined(Simulator) || defined(_WINDOWS)

  #define		romtype																											// Simulator or _WINDOWS
  #define		ramtype																											// Simulator or _WINDOWS
  #define		ramfunc																											// Simulator or _WINDOWS
  #define		neartype																										// Simulator or _WINDOWS
  #define		no_init																											// Simulator or _WINDOWS
#ifndef __cplusplus
	#define		inline																											// Simulator or _WINDOWS
#endif

  #define	 bMotorMirroring																							// Simulator
  #define	 bMotorsWithEncoders																					// Simulator
  #define	 bSmartMotorsWithEncoders																			// Simulator
  #define	 bAssociateMotorWithIOPins 																		// Simulator or _WINDOWS
#if defined(Simulator)
  #define	 bAssociateMotorWithEncoder																		// Simulator
#else
	#undef	bAssociateMotorWithEncoder																		// _WINDOWS
#endif
	extern unsigned char bIncludeMotorTypeInUploadMessage();		 					// Simulator or _WINDOWS
	#define bSupportsSoftwareBasedMotorPWM										 						// Simulator or _WINDOWS



  #define	kNumbOfBreakpoints 16      // Must be the highest number available of any controller. Used by IDE
                                      // Windows cannot support > 16. They take up 16 bits in 32-bit mask word!
	#define	kSystemClockSpeed  16000000L																	// Simulator or _WINDOWS
	#define	genericParmArith																							// Simulator or _WINDOWS

	// Conditional Compile Flags that have significant impact on features and size of firmware file

	#define	hasSupportForMessagingWithRobotcIDE														// Simulator or _WINDOWS
  #define	optionalExceptions 																						// Simulator or _WINDOWS
  #define	optionalBreakpoints 																					// Simulator or _WINDOWS
  #define	optionalDebugSupport																					// Simulator or _WINDOWS
  #define	hasBulkUploadlupport																					// Simulator or _WINDOWS
  #define	hasOptionalUploadSupport																			// Simulator or _WINDOWS
  #define	hasDeviceUploadSupport																				// Simulator or _WINDOWS
  #define	optionalTrinaryOpcodes																				// Simulator or _WINDOWS

	#define	useFloats																											// Simulator or _WINDOWS
	#define	useLongs																											// Simulator or _WINDOWS
  #define	hasJoystickDownloadMessageOpcodes															// Simulator or _WINDOWS
  #define	hasJoystickUploadMessageOpcodes																// Simulator or _WINDOWS
  #define	hasStringSupport																							// Simulator or _WINDOWS
  #define	has_sscanf_Support																						// Simulator or _WINDOWS
  #define	hasTranscendentalSupport																			// Simulator or _WINDOWS

	#define	bHasSoundSupport																							// Simulator or _WINDOWS
  #undef	bHasSoundVolume																								// Simulator or _WINDOWS
  #undef	bHasSoundDriverOnOff																					// Simulator or _WINDOWS
  #define	bHasSoundFiles																								// Simulator or _WINDOWS
  #define	kSoundQueueSize 10																						// Simulator or _WINDOWS


	#undef	hasCamera																											// Simulator or _WINDOWS
  #undef	hasHarvardArchitecture																				// Simulator or _WINDOWS
  #define	kMaxTimeBetweenMessageChars 25																// Simulator or _WINDOWS
  #define	hasDebugStreamSupport																					// Simulator or _WINDOWS
	#define	kDebugStreamBufferSize 2000																		// Simulator or _WINDOWS
  #define	kRamBaseAddr ((ubyte *) &VM_RAM.globalVariablesXX[0])					// Simulator or _WINDOWS
#if defined(Simulator)
  #undef	bHasDatalog																										// Simulator
#else
  #define	 bHasDatalog																									// _WINDOWS
#endif
  #define	bHasMessageStatistics																					// Simulator or _WINDOWS
  #undef	bSpareFlagXX																									// Simulator or _WINDOWS

	#define	hasAlphaNumericLCDDisplayViaUART															// Simulator or _WINDOWS
	#define	bHasLCDGraphicsDisplay																				// Simulator or _WINDOWS
	#define	hasLCDBacklight																								// Simulator or _WINDOWS
	#define	kScreenWidth								 100															// Simulator or _WINDOWS
	#define	kScreenHeight									64															// Simulator or _WINDOWS
	extern int kFirstVisibleScreenRow(void);															// Simulator or _WINDOWS
	extern int kLastVisibleScreenRow(void);																// Simulator or _WINDOWS
	#define	hasLCDButtons																									// Simulator or _WINDOWS
  #define	hasStatusLEDs																									// Simulator or _WINDOWS
	#define	bHasLCDContrast																								// Simulator or _WINDOWS
	#define	bHasRemoteButtons																							// Simulator or _WINDOWS

  #define	bUseLookupBreakpointTableInRAM																// Simulator or _WINDOWS
  #define	bHasFloatDuringInactivePWM																		// Simulator or _WINDOWS
	#define	nnRobotType	getEmulatorRobotType()														// Simulator or _WINDOWS
  #define	bHasServoSpecificSourceTypes																	// Simulator or _WINDOWS
  #define	bHasSourceTypeSensorRawValue																	// Simulator or _WINDOWS
  #define	bHasSourceTypeSensorMode																			// Simulator or _WINDOWS
  #define	hasSpareOption7																								// Simulator or _WINDOWS
  #define	hasSpareOption8																								// Simulator or _WINDOWS
  #define	hasSpareOption9																								// Simulator or _WINDOWS
	#define	 kSizeOfXmitBufferUserUart							25										// Simulator or _WINDOWS
	#define	kRcvBufferSizeUserUart									40										// Simulator or _WINDOWS

	#define	kSizeOfTLargeValue											 4										// Simulator or _WINDOWS

	#define	bHasStandardBatteryMonitoring																	// Simulator or _WINDOWS
	#define	bHasSoftwareControlledPowerOnOff															// Simulator or _WINDOWS
	extern int getDefaultPowerDownDelayMinutes(void);											// Simulator or _WINDOWS

	// Flags to control level of sensor support

	extern void sensorHandlerWorkBetweenOpcodes(void);										// Simulator or _WINDOWS
	#undef  bSoftwareMustStartADCConversionCycle													// Simulator or _WINDOWS
	#undef 	useSimpleADCArrayLookup																				// Simulator or _WINDOWS
	#define	includeSonarSensorSupport																			// Simulator  -- For minimal f/w size, this can be discarded
	#define	includeEncoderSensorSupport																		// Simulator  -- For minimal f/w size, this can be discarded
	#define	includeGyroAndAccelSupport																		// Simulator  -- For minimal f/w size, this can be discarded
	#define	bHasFastSonarSensor																						// Simulator or _WINDOWS
  #define	bHasSensorBiasSettings																				// Simulator or _WINDOWS

	#define	kNumbAnalogSensors 	 16																				// Simulator or _WINDOWS
	#define	kNumbDigitalSensors  70																				// Simulator or _WINDOWS
	#define	kNumbSensorsOnI2CPorts  12																		// Simulator or _WINDOWS
	#define	kMaxNumbofComplicatedSensors  70															// Simulator or _WINDOWS
  #define	kNumbOfRealSensors            (kNumbAnalogSensors+kNumbDigitalSensors+kNumbSensorsOnI2CPorts)// Max value for any robot or will crash IDE // Simulator or _WINDOWS

	#define	bHasSystemTaskForUserProgramComplete													// Simulator or _WINDOWS
	#define	bHasSemaphoreSupport																					// Simulator or _WINDOWS
  #define	kMaxBytesPerDataBytesUpload   300															// Simulator or _WINDOWS
	#define	kReceivedOpcodeSize           400															// Simulator or _WINDOWS
	#undef	bGetClearVariablesOnPgmStart																	// Simulator or _WINDOWS
	#undef	spareOption9																									// Simulator or _WINDOWS
	#undef	spareOption10																									// Simulator or _WINDOWS

	#define	bHasMultRobotNetworking																				// Simulator or _WINDOWS
	#define	bSystemUARTSupportsZigBee																			// Simulator or _WINDOWS
	#undef	bHasZigBeeFeatureSpare0																				// Simulator or _WINDOWS
	#undef	bHasZigBeeFeatureSpare1																				// Simulator or _WINDOWS
	#undef	bHasZigBeeFeatureSpare2																				// Simulator or _WINDOWS
	#define kNumbOfZigBeeMessageBuffers		0																// Simulator or _WINDOWS

  #define	kNumbOfTasks									(20)														// Simulator or _WINDOWS
  #define	kNumbOfGlobalVariables				(7500)													// Simulator or _WINDOWS
  #define	kNumbOfPrograms								(1)															// Simulator or _WINDOWS
  #define	kNumbOfTaskVariables					(16)														// Simulator or _WINDOWS
  #define	kNumbOfRealMotors             (40)// Max value for any robot or will crash IDE // Simulator or _WINDOWS
  #define	kNumbOfRealServos             ((unsigned char) 4 * (4 * 8))// Max value for any robot or will crash IDE // Simulator or _WINDOWS
  #define	kNumbOfVirtualSensors         ((unsigned char) 8)							// Simulator or _WINDOWS
  #define	kNumbOfVirtualMotors          ((unsigned char) 3)							// Simulator or _WINDOWS
  #define	kTaskVariablesStart 					((uword) 96)										// Simulator or _WINDOWS

	#undef	bSupportsInvokeBootloaderOpcode																// Simulator or _WINDOWS
	#define	bSupportsFlashWriteOpcodes																		// Simulator or _WINDOWS

	#define	bHasFlashFileSystem																						// Simulator or _WINDOWS
	#undef	bUsesFlashStorage																							// Simulator or _WINDOWS
  #define	kFlashSectorSize							2048														// Simulator or _WINDOWS
	#define	kMaxNumbofFlashFiles					60															// Simulator or _WINDOWS
  #define	kVTOCItemSize									4																// Simulator or _WINDOWS
  #define	kSizeOfFlashMemoryPtr					4																// Simulator or _WINDOWS
  #define	kSizeOfRAMMemoryPtr						4																// Simulator or _WINDOWS

#if defined(Simulator)
  #undef	bHasEvents																										// Simulator
#else
  #define	 bHasEvents																										// _WINDOWS
#endif
	#define	kDefaultTaskStackSizeInEntries 30															// Simulator or _WINDOWS

  #define	kConstantPoolSize							3200 														// Simulator or _WINDOWS
  #define	kStartOfFileSystem 						getStartOfFileSystem()					// Simulator or _WINDOWS
	#undef	kStartOfBootloader																						// Simulator or _WINDOWS
  #define	bSpareFieldXXXXXXXXXXXXXXXXXXXXXXX true												// Simulator or _WINDOWS
	#define	kSizeOfXmitBufferPC 					255	// to fit index in single byte	// Simulator or _WINDOWS
	#define	kRcvBufferSizePC	 						255 // to fit index in single byte	// Simulator or _WINDOWS

	#define	hasUserSerialPorts																						// Simulator or _WINDOWS
	#define	numbOfUserSerialPorts					4																// Simulator or _WINDOWS
	#undef	flipUART0_And_UART1																						// Simulator or _WINDOWS

	#undef	ARMCPU																												// Simulator or _WINDOWS
	#undef	AVRCPU																												// Simulator or _WINDOWS
	#undef	STM8CPU																												// Simulator or _WINDOWS
	#undef	Spare1CPU																											// Simulator or _WINDOWS
	#undef	Spare2CPU																											// Simulator or _WINDOWS
	#undef	Spare3CPU																											// Simulator or _WINDOWS
  #define	useParmForCurrOpPtr																						// Simulator or _WINDOWS

#endif


#if !defined (optionalDebugSupport)
	#if defined(optionalBreakpoints)
		#warning "Inconsistent macro definitions"
	#endif
	#undef	optionalBreakpoints
#endif

#if defined(hasHarvardArchitecture)
	#undef	useParmForCurrOpPtr
#endif
//
// Flag to indicate whether serial link communications can be customized. Only relevant to the RCX
// platform.
//
#undef	bSerialLinkCustomizable

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
  #define	validateWordAddress(pAddress) pAddress = (word *) ((unsigned int) pAddress & 0xFFFFFFFE)
  #define	validateLongAddress(pAddress) pAddress = (long *) ((unsigned int) pAddress & 0xFFFFFFFC)
#else
  #define	validateWordAddress(pAddress)
  #define	validateLongAddress(pAddress)
#endif


#if defined(useFloats)
  #define	useFloatsOrLongs
#elif defined(useLongs)
  #define	useFloatsOrLongs
#else
  #undef	useFloatsOrLongs
#endif


#if defined(bHasEvents)
  #define	kNumbOfEvents									((unsigned char) 16)
#else
  #undef	kNumbOfEvents
  #undef	kNumbOfVirtualSensors
  #undef	kNumbOfVirtualMotors

  #define	kNumbOfEvents									((ubyte) 0)
  #define	kNumbOfVirtualSensors         ((ubyte) 0)
  #define	kNumbOfVirtualMotors          ((ubyte) 0)
#endif

#define	kNumbOfTotalSensors           ((unsigned char) (kNumbOfRealSensors + kNumbOfVirtualSensors))

#define	kNumbOfTotalMotors            ((unsigned char) (kNumbOfRealMotors + kNumbOfVirtualMotors))

#define	kNumbOfTimers									((unsigned char) 4)

#ifdef __cplusplus
}
#endif

#endif //#ifndef LoadBuildOptions__H_

