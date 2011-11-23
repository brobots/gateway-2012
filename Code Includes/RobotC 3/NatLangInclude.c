/*----------------------------------*\
|*	- Natural Language Switcher -	*|
|*                                  *|
|*	This file chooses which Natural	*|
|*	Language library to use.		*|
\*-----------------------------4246-*/

#pragma systemFile            	// eliminates warning for "unreferenced" functions

// Choose Virtual World or Physical Robot:
#if (_TARGET == "VirtWorld")
	// Virtual World:  Now check which platform type:
	#if defined(NXT)
		#include "NatLang_NXT_VW.c"

	#elif defined(VEX2)
		#include "NatLang_CORTEX_VW.c"

	#else
		#warning "Natural Language is not supported for this platform type (VIRTUAL WORLDS).  Please select either CORTEX or NXT"

	#endif

#elif (_TARGET == "Robot")
	// Physical Robot:  Now check which platform type:
	#if defined(NXT)
		#include "NatLang_NXT.c"

	#elif defined(TETRIX)
		#include "NatLang_TETRIX.c"

	#elif defined(VEX2)
		#include "NatLang_CORTEX.c"

	#elif defined(VEX)
		#include "NatLang_PIC.c"

	#else
		#warning "Natural Language is not supported for this platform type.  Please select either NXT, TETRIX, CORTEX, or VEX PIC"

	#endif

#else
	#warning "Natural Language is not supported for this debug target.  Please select either Physical Robot or Virtual World"
#endif
