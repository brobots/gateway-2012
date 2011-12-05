#ifndef TSensorTypes__H_
#define TSensorTypes__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Sensor Types
//
//////////////////////////////////////////////////////////////////////////////////////////////

typedef enumWord TSensorTypes
{
	// *********************   Do not change the order of the first few sensors. It is known to the NXT-G software.  ****************

  sensorNone													= 0,   // RCX returns RAW value. NXT turns off sensor.

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorRawValue											= 0,   // RCX returns RAW value. NXT turns off sensor.
#endif

  sensorTouch 												= 1,   // Legacy sensors common to RCX and NXT bricks

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorTemperature										= 2,   // Legacy sensors common to RCX and NXT bricks
#endif

  sensorReflection										= 3,   // Legacy sensors common to RCX and NXT bricks
  sensorRotation											= 4,   // Legacy sensors common to RCX and NXT bricks

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorLightActive 									= 5,   // NXT bricks only
  sensorLightInactive 								= 6,   // NXT bricks only
  sensorSoundDB 											= 7,   // NXT bricks only [Microphone Sensor]
  sensorSoundDBA											= 8,   // NXT bricks only
  sensorCustom												= 9,   // NXT bricks only

	sensorI2CCustom 										= 10,  // Low Speed I2C devices. Same index as NXT-G
	sensorI2CCustom9V 									= 11,  // Low Speed I2C devices with 9V. Same index as NXT-G
  sensorHighSpeed 										= 12,

  // New LEGO Color Sensor

	sensorCOLORFULL                     = 13, // Color "lamp" mode -- i.e. output selected color
  sensorCOLORRED                      = 14, // Color "lamp" mode -- i.e. output selected color
  sensorCOLORGREEN                    = 15, // Color "lamp" mode -- i.e. output selected color
  sensorCOLORBLUE                     = 16, // Color "lamp" mode -- i.e. output selected color
  sensorCOLORNONE                     = 17, // Ambient light mode.
  sensorCOLOREXIT                     = 18, // For internal use when going from color or Lamp to no_sensor

#endif

	// *********************   Do not change the above order. It is known to the NXT-G software.  ****************

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
	//
	// New NXT types
	//
  sensorI2CCustomFast									= 19, // I2C
  sensorI2CCustomFast9V								= 20, // I2C
  sensorI2CCustomFastSkipStates9V			= 21,	// I2C
  sensorI2CCustomFastSkipStates				= 22, // I2C

	sensorActiveRawValue								= 23,  // New RCX type added for 'active powered' third party sensors

	sensorAnalogActive 									= 24,   // NXT bricks only
  sensorAnalogInactive 								= 25,   // NXT bricks only
  sensorI2CMuxController 							= 26,
  sensorI2CMuxControllerFast 					= 27,

  sensorI2CHiTechnicColor							= 28,    // I2C
  sensorI2CHiTechnicGyro 							= 29,
  sensorI2CHiTechnicAccel							= 30,    // I2C
  sensorI2CHiTechnicCompass						= 31,    // I2C
  sensorHiTechnicTouchMux							= 32,    // Not I2C

  sensorI2CMindsensorsCompass					= 33,    // I2C
  sensorI2CMindsensorsAccel						= 34,    // I2C
  sensorI2CMindsensorsDist 						= 35,    // I2C
  sensorI2CodatexRFID									= 36,    // I2C
  sensorHiTechnicIRSeeker600 					= 37,    // I2C
  sensorHiTechnicIRSeeker1200					= 38,    // I2C
  sensorI2CMindsensorsLineFollow 			= 39,    // I2C

	sensorSONAR													= 40, // cm results
  #define sensorSONAR9V sensorSONAR
	sensorI2CLegoTempC									= 41,    // I2C
  sensorI2CLegoTempF 									= 42,    // I2C
  sensorHiTechnicMagnetic							= 43,    // Same as analaog light sensor
#endif

	sensorDigitalIn 										= 44,  // New NXT & VEX type

#if !defined(NXT) || defined(_WINDOWS)

	sensorSONAR_cm                      = 45, // cm results (centimeter)
  sensorGyro 													= 46,
	sensorAccelerometer									= 47,
	sensorQuadEncoder										= 48,
	sensorPotentiometer									= 49,
	sensorLineFollower 									= 50,  // VEX line following sensor
  sensorDigitalOut 										= 51,  // Sets up a digital I/O pin as output
#endif

#if !(defined(NXT) || defined(VEX)) || defined(_WINDOWS)
	sensorSONAR_inch                    = 52, // inch results (inches)
	sensorSONAR_mm                      = 53, // cm results (millimeter)
	sensorSONAR_raw                     = 54, // cm results (millimeter)
	sensorQuadEncoderSecondPort					= 55,  // Internal -- used for second port on quadrature sensors.
	sensorSONARSecondPort								= 56,  // Internal -- used for second port on SONAR sensors.
#endif

#if defined(AVRCPU) || defined(PIC32) || defined(STM8CPU) || defined(_WINDOWS)
  sensorMotorPWMCtrlPin								= 57,  // I/O Pin is used by Motor Drivers for H-Bridge
  sensorMotorDirCtrlPin								= 58,  // I/O Pin is used by Motor Drivers for H-Bridge
  sensorServoCtrlPin									= 59,  // I/O Pin is used by Motor Drivers for Servos
  sensorUARTCtrlPin										= 60,  // I/O Pin is used by UART
  sensorI2CCtrlPin										= 61,  // 
  sensorSPICtrlPin										= 62,  // 
  sensorAudioSpeaker									= 63,  // 

	sensorInternalButton								= 64,  // I/O Pin is used for a integrated button
  sensorStatusLED											= 65,  // I/O Pin is used for a status LED display
  sensorBatteryMonitor								= 66,  // Analog I/O Pin is used for a status LED display
#endif

#if defined(VEX2) ||  defined(_WINDOWS)
	sensorQuadEncoderOnI2CPort					= 67, // Quadrature Encoder connected to I2C Port
	sensorLineFollowArrayOnI2CPort			= 68, // Array of line following sensors connected to I2C Port
	sensorSpare1OnI2CPort								= 69, // Spare Type 1 connected to I2C Port
	sensorSpare2OnI2CPort								= 70, // Spare Type 2 connected to I2C Port
	sensorSpare3OnI2CPort								= 71, // Spare Type 3 connected to I2C Port
	sensorSpare4OnI2CPort								= 72, // Spare Type 4 connected to I2C Port
#endif

  sensorVirtualCompass								= 73,  
	sensorLEDtoVCC											= 74,
	sensorDigitalHighImpedance 					= 75,  // Sets up a digital I/O pin as high impedance

} TSensorTypes;

//#define kLastBuiltinNxtSensor ((TSensorTypes)(sensorHighSpeed - 1))

#endif

