#ifndef TSensorTypes__H_
#define TSensorTypes__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Sensor Types
//
//////////////////////////////////////////////////////////////////////////////////////////////

typedef enumWord
{
#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorRawValue                    	= 0,   // RCX returns RAW value. NXT turns off sensor.
#endif

  sensorNone                        	= 0,   // RCX returns RAW value. NXT turns off sensor.
  sensorTouch                       	= 1,   // Legacy sensors common to RCX and NXT bricks
#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorTemperature					        	= 2,   // Legacy sensors common to RCX and NXT bricks
  sensorReflection                  	= 3,   // Legacy sensors common to RCX and NXT bricks
#endif

  sensorRotation                    	= 4,   // Legacy sensors common to RCX and NXT bricks

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
  sensorLightActive                 	= 5,   // NXT bricks only
  sensorLightInactive               	= 6,   // NXT bricks only
  sensorSoundDB                     	= 7,   // NXT bricks only [Microphone Sensor]
  sensorSoundDBA                    	= 8,   // NXT bricks only
  sensorCustom                      	= 9,   // NXT  bricks only
#endif

#if defined(NXT) || defined(TETRIX) || defined(_WINDOWS)
	sensorI2CCustom                   	= 10,  // Low Speed I2C devices. Same index as NXT-G
	sensorI2CCustom9V                 	= 11,  // Low Speed I2C devices with 9V. Same index as NXT-G
  sensorHighSpeed                   	= 12,

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
  sensorI2CCustomFast              		= 19, // I2C
  sensorI2CCustomFast9V              	= 20, // I2C
  sensorI2CCustomFastSkipStates9V    	= 21,	// I2C
  sensorI2CCustomFastSkipStates    		= 22, // I2C
	
	sensorActiveRawValue              	= 23,  // New RCX type added for 'active powered' third party sensors

	sensorAnalogActive                 	= 24,   // NXT bricks only
  sensorAnalogInactive               	= 25,   // NXT bricks only
  sensorI2CMuxController             	= 26,
  sensorI2CMuxControllerFast         	= 27,

  sensorI2CHiTechnicColor            	= 28,    // I2C
  sensorI2CHiTechnicGyro             	= 29,
  sensorI2CHiTechnicAccel            	= 30,    // I2C
  sensorI2CHiTechnicCompass          	= 31,    // I2C
  sensorHiTechnicTouchMux            	= 32,    // Not I2C

  sensorI2CMindsensorsCompass        	= 33,    // I2C
  sensorI2CMindsensorsAccel          	= 34,    // I2C
  sensorI2CMindsensorsDist           	= 35,    // I2C
  sensorI2CodatexRFID                	= 36,    // I2C
  sensorHiTechnicIRSeeker600         	= 37,    // I2C
  sensorHiTechnicIRSeeker1200        	= 38,    // I2C
  sensorI2CMindsensorsLineFollow     	= 39,    // I2C

	sensorSONAR                        	= 40, // cm results
  #define sensorSONAR9V sensorSONAR
	sensorI2CLegoTempC          				= 41,    // I2C
  sensorI2CLegoTempF           				= 42,    // I2C
  sensorHiTechnicMagnetic      				= 43,    // Same as analaog light sensor
#endif

	sensorDigitalIn                   	= 44,  // New NXT & VEX type

#if defined(VEX) || defined(VEX2) || defined(AVRCPU) || defined(STM8CPU) || defined(Generic) || defined(_WINDOWS)
	sensorSONAR_cm                      = 45, // cm results (centimeter)
  sensorGyro                       		= 46,
	sensorAccelerometer              		= 47,
	sensorQuadEncoder                		= 48,
	sensorPotentiometer              		= 49,
	sensorLineFollower               		= 50,  // VEX line following sensor
  sensorDigitalOut                 		= 51,  // Sets up a digital I/O pin as output
#endif

#if defined(VEX2) || defined(AVRCPU) || defined(STM8CPU) || defined(Generic) || defined(_WINDOWS)
	sensorSONAR_inch                    = 52, // inch results (inches)
	sensorSONAR_mm                      = 53, // cm results (millimeter)
	sensorSONAR_raw                     = 54, // cm results (millimeter)
	sensorQuadEncoderSecondPort      		= 55,  // Internal -- used for second port on quadrature sensors.
	sensorSONARSecondPort      					= 56,  // Internal -- used for second port on SONAR sensors.
#endif

#if defined(AVRCPU) || defined(STM8CPU) || defined(_WINDOWS)
  sensorMotorCtrlPin									= 57,  // I/O Pin is used by Motor Drivers for H-Bridge
  sensorServoCtrlPin									= 58,  // I/O Pin is used by Motor Drivers for Servos
  sensorUARTCtrlPin										= 59,  // I/O Pin is used by UART
#endif

  kNumbOfSensorTypes                 	= 60
} TSensorTypes;

//#define kLastBuiltinNxtSensor ((TSensorTypes)(sensorHighSpeed - 1))

#endif
