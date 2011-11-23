#ifndef __FirmwareVersion_
#define __FirmwareVersion_

//
// 01 Feb 2011
//
#define kLastCompatibleVersion (831)

#define kFirmwareVersion  (831)
#define pzFirmwareVersion "0831"         // Used in building default file name
#define kProductVersion   "ROBOTC 2.32"


#define kLatestVEX_PIC_MasterFirmwareVersion					10
#define kLatestVEX_Cortex_MasterFirmwareVersion				(0x0200 | 71)			// 2.71
#define kLatestVEX_GameController_FirmwareVersion			(0x0200 | 31)			// 2.31


#if defined(_WINDOWS)
	#define sLatestVEX_Cortex_MasterFirmwareVersion			"WIFI_RC_2p0_V2_71"
	#define sLatestVEX_GameController_FirmwareVersion	  "WIFI_OI_2p0_V2_31"
#endif

#endif
