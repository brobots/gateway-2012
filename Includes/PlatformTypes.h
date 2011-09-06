#if !defined(__PlatformTypes__H_)
#define __PlatformTypes__H_

typedef enum TPlatformType		// Do not change order, used in 'property page' window -- Comment may be obsolete!!!!!!
{
  platformNone,  
  platformNXT,
  platformVEX,
  platformVEX20,
	platformSTM3210E,

	platformVEXPro,
  platformArduinoDuemilanove,
  platformArduinoMega,		
  platformArduinoSpare,
  platformGeneric,

	platformWindows,						// Special -- used to build the internal "system define" tables. Not valid otherwise.
	platformSpare11,
	platformSpare12,
	platformSpare13,
	platformRoboCub,

	platformSpare15,
	platformSpare16,
	platformARM7,
	platformARM9,
	platformPIC24,

	platformTetrix,
	platformSX256,
	platformSpare22,
	platformSpare23,
	platformSpare24,

	platformSpare25,
	platformSpare26,
	platformSpare27,
	platformSpare28,
	platformSpare29,

	platformSpare30,
	platformUnspecified   //= 31,
};

const int kNumbOfPlatforms = 32;

#endif //#if !defined(__PlatformTypes__H_)