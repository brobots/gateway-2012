#if !defined(RobotCIncludes__H_)
#define RobotCIncludes__H_
const bool true  = (bool) 1;
const bool false = (bool) 0;

typedef unsigned char  ubyte;
typedef   signed char  sbyte;
typedef unsigned short uword; // unsigned variables are not supported. Everything is signed!! But allow definition


#ifndef INLINE
#define INLINE inline
#endif

#include "LoadBuildOptions.h"
#include "OpcodeDefinitions.h"

#if defined(NXT) || defined(TETRIX)
  #include "NxtFileIODefs.h"
  #include "NxtSynchMotors.h"
#endif


#if defined(hasStringSupport)
  #include "stringOpcodes.h"
#endif
#if defined(bHasLCDGraphicsDisplay) || defined(hasDebugStreamSupport)
  #include "GraphicLCD.h"
#endif

#include "RobotCIntrinsics.c"
#endif
