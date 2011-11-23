#ifndef TMotorTypes__H_
#define TMotorTypes__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Motor Types
//
//////////////////////////////////////////////////////////////////////////////////////////////

typedef enum TMotorTypes
{
	tmotorNone												=  0,
	tmotorNormal											=  1,
	tmotorAudio												=  2,
	tmotorServoStandard								=  3,
	tmotorServoContinuousRotation			=  4,

	tmotorHBridgeSinglePWM						=  5,
	tmotorHBridgeDualPWM							=  6,

#if defined(_WINDOWS)
	//
	// Used Internally by ROBOTC IDE
	//
	tmotorInternalHBridgeSinglePWM		=  7,
	tmotorInternalHBridgeDualPWM			=  8,
	tmotorExternalHBridgeSinglePWM		=  9,
	tmotorExternalHBridgeDualPWM			= 10,
	
	tmotorVexFlashlight								= 11,


	// Following are obsolete types that preceded the use of boolean variables for 'reverse' and 'PID control'.
	// They are kept around for legacy purposes to support older versions of user programs that may use these values
	// in the "Motor and Sensoe Setup" menu.
	//
	tmotorNxtEncoderOpenLoop					= 12,  // No   PID speed control
	tmotorNxtEncoderClosedLoop				= 13,  // With PID speed control
	tmotorReversed										= 14,	 

	tmotor12VEncoderOpenLoop					= 15,  // No   PID speed control
	tmotor12VEncoderClosedLoop				= 16,  // With PID speed control
#endif



} TMotorTypes;

#endif //#ifndef TMotorTypes__H_

