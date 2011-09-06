#ifndef MainIncludes__H_
#define MainIncludes__H_

#include "loadBuildOptions.h"
#include "CompilerTypedefs.h" 
#include "OpcodeDefinitions.h"
#include "VMtypedefs.h"

#if defined(NXT) || defined(TETRIX)
  #include "nxtFileIODefs.h"
#endif

#if defined(hasStringSupport)

  #include "GraphicLCD.h"
  #include "stringOpcodes.h"

#elif defined(bHasLCDGraphicsDisplay) || defined(hasDebugStreamSupport)

  #include "GraphicLCD.h"

#endif

#endif //#ifndef MainIncludes__H_
