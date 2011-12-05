#if !defined(_FlashFIleSystemOffsets__H_)
#define _FlashFIleSystemOffsets__H_

#if !defined(kVTOCItemSize) && !defined(_WINDOWS) && !defined(NXT)
	#error "Include file screwup. 'LoadBuildOptions.h' must be included before 'FlashFileSystemOffsets.h'"
#endif

#if defined(kVTOCItemSize) || defined(_WINDOWS)

#include "stddef.h"


typedef struct
{
	unsigned long nCPUSpeed;	
	unsigned short nMicroSecPerInterruptTimes10;	
	unsigned char nStartupProgram;	
	unsigned char nIdleProgram;	
#if (1) || defined(bStoresRobotNameInPersistentData) || defined(_WINDOWS)
	#define kSizeOfRobotName 8
	unsigned char cRobotName[kSizeOfRobotName];			// Robot Name or Team Number (VEX Cortex)
#endif	
	unsigned long  nVTOCStart;											// Start of the VTOC array. Each entry contains information on one file.
} TFlashFilePersistentVariables;

typedef enum
{
	kOffsetCPUSpeed											= offsetof(TFlashFilePersistentVariables, nCPUSpeed),
	kOffsetMicroSecPerInterruptTimes10	= offsetof(TFlashFilePersistentVariables, nMicroSecPerInterruptTimes10),
	kOffsetStartupProgram								= offsetof(TFlashFilePersistentVariables, nStartupProgram),
	kOffsetIdleProgram									= offsetof(TFlashFilePersistentVariables, nIdleProgram),
#if (1) || defined(bStoresRobotNameInPersistentData) || defined(_WINDOWS)
	kOffsetRobotName										= offsetof(TFlashFilePersistentVariables, cRobotName),
#endif	
	kOffsetVTOCStartXX									= offsetof(TFlashFilePersistentVariables, nVTOCStart)			// Start of the VTOC array. Each entry contains information on one file.
} TFlashFilePersistentOffsets;

#define kOffsetVTOCStart							kOffsetVTOCStartXX			// Start of the VTOC array. Each entry contains information on one file.

#endif //#if defined(kVTOCItemSize) || defined(_WINDOWS)

#endif //if !defined(_FlashFileSystemOffsets__H_)
