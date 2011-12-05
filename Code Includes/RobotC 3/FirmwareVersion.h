#ifndef __FirmwareVersion_
#define __FirmwareVersion_

//
// 25 Sept 2011
//
#define kLastCompatibleVersion (903)

#define kFirmwareVersion  		(904)
#define pzFirmwareVersion			"0904" 											// Used in building default file name

#define kRobotCVersion				"3.04"

#define kLatestVEX_PIC_MasterFirmwareVersion					10

#define kLatestVEX_Cortex_MasterFirmwareVersion				((3 << 8) | (16 << 0))		// 3.16
#define kLatestVEX_GameController_FirmwareVersion			((3 << 8) | (16 << 0))		// 3.16


#if defined(_WINDOWS)
	#define sLatestVEX_Cortex_MasterFirmwareVersion			"WIFI_RC_2p0_V"    "3_16"    ".BIN"
	#define sLatestVEX_GameController_FirmwareVersion	  "WIFI_OI_2p0_V"    "3_16"    ".BIN"
#endif

#endif
