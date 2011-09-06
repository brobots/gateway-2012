#if !defined(MainIncludes__H_) && !defined(_WINDOWS)
	#error "'VMTypedefs.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#ifndef VMTypedefs__H_
#define VMTypedefs__H_

#ifdef __cplusplus
  extern "C" {
#endif


///////////////////////////////////////////////////////////////////////////////////////////////
//
//                       Intrinsic RCX Instruction Definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////

#if defined(ARMCPU)

	#pragma pack (push, 1)
	typedef struct
	{
		ubyte			  opCode;
		ubyte				msgBytes[15];
	} TShortMessageBuffer;
	#pragma pack (pop)

#else   // VEX. Byte packing!

	typedef struct TShortMessageBuffer
	{
#if defined(_WIN32) || defined(_WINDOWS) || defined(Simulator)
		ubyte   			opCode;
#else
		TVMOpcode			opCode;
#endif
		ubyte				  msgBytes[16];
	} TShortMessageBuffer;

#endif

typedef enum TTimerIndex
{
	timer1              = 0,
	timer2              = 1,
	timer3              = 2,
	timer4              = 3
} TTimerIndex;

typedef enum TMotorIndex
{
  motorA					= 0,
  motorB					= 1,
  motorC					= 2,

#if defined(NXT) || defined(_WINDOWS)
	//
	// HiTechnic Motor Controllers.
	//    - Each controller supports two motors
	//    = Up to four controllers per sensor port.
	//
	motorD					=  3,
  motorE,
  motorF,
  motorG,

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

#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(_WINDOWS)

  port1         = 0,
  port2         = 1,
  port3         = 2,
  port4         = 3,
  port5         = 4,
  port6         = 5,
  port7         = 6,
  port8         = 7,
#if defined(VEX2) || defined(_WINDOWS)
  port9         = 8,
	port10        = 9,
#endif
#endif
} TMotorIndex;


#if defined(NXT) || defined(_WINDOWS)

typedef enum TSensorPortHub
{
	muxNone									= 0,
	muxHiTMotor							= 1,
	muxHiTServo							= 2,
	muxHiTTouch							= 3,
	muxMndSnrServo					= 4,
	muxMndSnrMotor					= 5,
	muxLEGO485Nxt						= 6,  // Special -- not implemented yet.
} TSensorPortHub;

typedef enum TServoIndex
{
	//
	// HiTechnic and Mindsensor Servo Controllers.
	//    - Each controller supports two motors
	//    = Up to four controllers per sensor port.
	//
	srvo_S1_C1_1        =  0,
  srvo_S1_C1_2,
  srvo_S1_C1_3,
  srvo_S1_C1_4,
  srvo_S1_C1_5,
  srvo_S1_C1_6,
  srvo_S1_C1_7,   // Hitechnic supports six servos, Mindsensors supports 8
  srvo_S1_C1_8,

	servo1							=  8,
  servo2,
  servo3,
  servo4,
  servo5,
  servo6,
  servo7,   // Hitechnic supports six servos, Mindsensors supports 8
  servo8,

 	srvo_S1_C2_1			  =  8,
  srvo_S1_C2_2,
  srvo_S1_C2_3,
  srvo_S1_C2_4,
  srvo_S1_C2_5,
  srvo_S1_C2_6,
  srvo_S1_C2_7,
  srvo_S1_C2_8,

  srvo_S1_C3_1,
  srvo_S1_C3_2,
  srvo_S1_C3_3,
  srvo_S1_C3_4,
  srvo_S1_C3_5,
  srvo_S1_C3_6,
  srvo_S1_C3_7,
  srvo_S1_C3_8,

  srvo_S1_C4_1,
  srvo_S1_C4_2,
  srvo_S1_C4_3,
  srvo_S1_C4_4,
  srvo_S1_C4_5,
  srvo_S1_C4_6,
  srvo_S1_C4_7,
  srvo_S1_C4_8,

	srvo_S2_C1_1,
  srvo_S2_C1_2,
  srvo_S2_C1_3,
  srvo_S2_C1_4,
  srvo_S2_C1_5,
  srvo_S2_C1_6,
  srvo_S2_C1_7,
  srvo_S2_C1_8,
 	srvo_S2_C2_1,
  srvo_S2_C2_2,
  srvo_S2_C2_3,
  srvo_S2_C2_4,
  srvo_S2_C2_5,
  srvo_S2_C2_6,
  srvo_S2_C2_7,
  srvo_S2_C2_8,
  srvo_S2_C3_1,
  srvo_S2_C3_2,
  srvo_S2_C3_3,
  srvo_S2_C3_4,
  srvo_S2_C3_5,
  srvo_S2_C3_6,
  srvo_S2_C3_7,
  srvo_S2_C3_8,
  srvo_S2_C4_1,
  srvo_S2_C4_2,
  srvo_S2_C4_3,
  srvo_S2_C4_4,
  srvo_S2_C4_5,
  srvo_S2_C4_6,
  srvo_S2_C4_7,
  srvo_S2_C4_8,

	srvo_S3_C1_1,
  srvo_S3_C1_2,
  srvo_S3_C1_3,
  srvo_S3_C1_4,
  srvo_S3_C1_5,
  srvo_S3_C1_6,
  srvo_S3_C1_7,
  srvo_S3_C1_8,
 	srvo_S3_C2_1,
  srvo_S3_C2_2,
  srvo_S3_C2_3,
  srvo_S3_C2_4,
  srvo_S3_C2_5,
  srvo_S3_C2_6,
  srvo_S3_C2_7,
  srvo_S3_C2_8,
  srvo_S3_C3_1,
  srvo_S3_C3_2,
  srvo_S3_C3_3,
  srvo_S3_C3_4,
  srvo_S3_C3_5,
  srvo_S3_C3_6,
  srvo_S3_C3_7,
  srvo_S3_C3_8,
  srvo_S3_C4_1,
  srvo_S3_C4_2,
  srvo_S3_C4_3,
  srvo_S3_C4_4,
  srvo_S3_C4_5,
  srvo_S3_C4_6,
  srvo_S3_C4_7,
  srvo_S3_C4_8,


	srvo_S4_C1_1,
  srvo_S4_C1_2,
  srvo_S4_C1_3,
  srvo_S4_C1_4,
  srvo_S4_C1_5,
  srvo_S4_C1_6,
  srvo_S4_C1_7,
  srvo_S4_C1_8,
 	srvo_S4_C2_1,
  srvo_S4_C2_2,
  srvo_S4_C2_3,
  srvo_S4_C2_4,
  srvo_S4_C2_5,
  srvo_S4_C2_6,
  srvo_S4_C2_7,
  srvo_S4_C2_8,
  srvo_S4_C3_1,
  srvo_S4_C3_2,
  srvo_S4_C3_3,
  srvo_S4_C3_4,
  srvo_S4_C3_5,
  srvo_S4_C3_6,
  srvo_S4_C3_7,
  srvo_S4_C3_8,
  srvo_S4_C4_1,
  srvo_S4_C4_2,
  srvo_S4_C4_3,
  srvo_S4_C4_4,
  srvo_S4_C4_5,
  srvo_S4_C4_6,
  srvo_S4_C4_7,
  srvo_S4_C4_8,
} TServoIndex;

#endif

typedef enum
{
#if defined(NXT) ||defined(_WINDOWS)
  S1							= 0,
  S2							= 1,
  S3							= 2,
#endif

#if defined(NXT) || defined(_WINDOWS)
	S4							=  3,    // virtual sensors for external MUXes
#endif

#if defined(VEX) || defined(VEX2) || defined(STM3210E) || defined(AVRCPU) || defined(Generic) || defined(_WINDOWS)
  in1    					=  0,
  in2    					=  1,
  in3    					=  2,
  in4    					=  3,
  in5    					=  4,
  in6    					=  5,
  in7    					=  6,
  in8    					=  7,
#endif

#if defined(VEX) || defined(STM3210E) || defined(AVRCPU) || defined(Generic) || defined(_WINDOWS)
  in9    					=  8,
  in10   					=  9,
  in11   					= 10,
  in12   					= 11,
  in13   					= 12,
  in14   					= 13,
  in15   					= 14,
  in16   					= 15,
#endif

#if defined(VEX2)  || defined(Generic) || defined(_WINDOWS)
  dgtl1	 					=  8,
  dgtl2	 					=  9,
  dgtl3	 					= 10,
  dgtl4	 					= 11,
  dgtl5	 					= 12,
  dgtl6	 					= 13,
  dgtl7	 					= 14,
  dgtl8	 					= 15,
  dgtl9						= 16,
  dgtl10					= 17,
  dgtl11					= 18,
  dgtl12					= 19,
#endif
	lastSensor

} tSensors;



typedef enum
{
  sensor1   = (ubyte) 0,
  sensor2   = (ubyte) 1,
  sensor3   = (ubyte) 2
} TSensorIndexForEvents;


typedef struct TUByteArray
{
	ubyte ubytes[40];
} TUByteArray;

typedef struct TByteArray16
{
	ubyte ubytes[16];
} TByteArray16;

typedef struct TWordArray
{
	word words[40];
} TWordArray;

typedef struct TLongWord
{
	word upperWord;
	word lowerWord;
} TLongWord;

typedef enum
{
	rbtTypeBadValue					= 0,
	rbtTypeNXT							= 1,
	rbtTypeVEX0_5						= 2,
	rbtTypeVEX2_0						= 3,
	rbtTypeVEXPro						= 4,
	rbtTypeArduino					= 5,
	rbtTypeSTM8							= 6,
	rbtTypeSTM32						= 7,
	rbtTypeSTellarus				= 8
} TRobotTypes;

#if defined(Simulator)
	extern TRobotTypes getEmulatorRobotType();
#endif

#ifdef __cplusplus
	}
#endif

#endif //#ifndef VMTypedefs__H_
