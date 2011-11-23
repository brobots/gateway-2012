#ifndef SystemParameters__H_
#define SystemParameters__H_

#include <RobotFirmware/Includes/CompilerTypedefs.h>

#ifdef __cplusplus
  extern "C" {
#endif

extern   uword				nMaxOpcodesPerTimeSlice;
extern   TULargeValue nTimeOnClock;

#if  defined(bHasFloatDuringInactivePWM)
	extern bool bFloatDuringInactiveMotorPWM;
#endif

#if defined(NXT) || defined(TETRIX) || defined(Simulator)

	extern ubyte               nDefaultTaskStackSize;
	extern ubyte               nLCDRefreshRate;
	extern ubyte               nVirtualMotorChanges;
	extern ubyte               nVirtualSensorTypeChanges;
	extern ubyte               nVirtualSensorModeChanges;
	extern sbyte               nNxtButtonTask;
	extern ubyte               nNxtExitClicks;
	
#endif //#if defined(NXT)

#if defined(bHasSoundSupport)
  extern volatile bool bPlaySounds; // volatile to prevent compiler from 'bad' optimization
#endif


#if defined(VEX) || defined(VEX2) || defined(Simulator)
  extern volatile uword nIFISPIMsgCounts;
#endif

#if  defined(useFloats)
  extern bool bExceptionOnFloatConversionErrors;
#endif

#if !defined(bGetClearVariablesOnPgmStart)
  extern bool bGetClearVariablesOnPgmStart(void);
#endif

#if !defined(SetClearVariablesOnPgmStart)
	extern void SetClearVariablesOnPgmStart(TUSmallValue newValue);
#endif

#define kShutdownVoltageDefault 6300

extern TLargeValue getSystemParmValue(TUSmallValue index);
extern void setSystemParmValue(TUSmallValue parmIndex, TULargeValue newValue);

extern void getValueInitOneTime(void);


#if defined(ARMCPU) || defined(Simulator) // || defined(VEX)
	extern TULargeValue getSystemExternAddress(TULargeValue index);
#endif


#ifdef __cplusplus
	}
#endif

#endif //#ifndef SystemParameters__H_
