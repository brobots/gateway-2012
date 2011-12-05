#ifndef MainIncludes__H_
#define MainIncludes__H_

#ifdef __cplusplus
	//#include "ForceWindowsLibraryOrder.h"
	extern "C" {
#endif

#include <RobotFirmware/Includes/loadBuildOptions.h>
#include <RobotFirmware/Includes/CompilerTypedefs.h> 
#include <RobotFirmware/Includes/OpcodeDefinitions.h>
#include <RobotFirmware/Includes/VMTypedefs.h>

#if defined(NXT) || defined(TETRIX)
  #include <RobotFirmware/Includes/NXTFileIODefs.h>
#endif

#if defined(hasStringSupport)

  #include <RobotFirmware/Includes/GraphicLCD.h>
  #include <RobotFirmware/Includes/stringOpcodes.h>

#elif defined(bHasLCDGraphicsDisplay) || defined(hasDebugStreamSupport)

  #include <RobotFirmware/Includes/GraphicLCD.h>

#endif

#ifdef __cplusplus
	};
#endif

#endif //#ifndef MainIncludes__H_
