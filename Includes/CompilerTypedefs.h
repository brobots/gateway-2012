#ifndef CompilerTypedefs__H_
#define CompilerTypedefs__H_

#if !defined(MainIncludes__H_) && !defined(_WINDOWS) && !defined(WIN32)
	#error "'CompilerTypedefs.h' should only be '#included' from 'mainIncludes.h' file"
#endif

#if defined(WIN32)
  #include "stddef.h"
#endif


#ifdef __cplusplus
  extern "C" {
#endif


#if !defined(bytesDeclared)
	#define bytesDeclared
	#define byteDeclareRequired
	typedef unsigned char ubyte;
	typedef   signed char sbyte;
#endif


#ifndef __cplusplus
#if defined(VEX) || defined(Arduino_Simulator) || defined(_WINDOWS) //|| defined(Simulator)
  	typedef unsigned char bool;
    #define false 0
    #define true 1
  #elif defined(ARMCPU) || defined(ArduinoMega) || defined(Arduino2009) || defined(Generic)
    #include "stdbool.h"
	#endif

  #if defined(byteDeclareRequired)
	  //typedef signed char sbyte;
  #endif
#endif


#if !defined(NULL)
  #define NULL 0
#endif


typedef signed short word;
typedef signed short sword;
typedef unsigned short uword;

typedef long word32;
typedef unsigned long ulong;
typedef unsigned long uword32;

#undef ubyte
#undef sbyte


#if defined(_WINDOWS) || defined(Simulator)

  #define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

  #define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

  typedef signed   int TSSmallValue;
  typedef unsigned int TUSmallValue;
  typedef signed   int TLargeValue; // 32-bits
  typedef unsigned int TULargeValue; // 32-bits

#elif  defined(ARM) || defined(NXT) || defined(SX256)

  #define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))


  //#define bytesToSWord(lowerByte, upperByte)  (((((TLargeValue) ( ((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))

  #define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)

  typedef signed   int TSSmallValue;
  typedef unsigned int TUSmallValue;
  typedef signed   int TLargeValue;  // 32-bits
  typedef unsigned int TULargeValue; // 32-bits

#elif  defined(VEX2) || defined(STM3210E)

  #define bytesToSWord(lowerByte, upperByte)  ((int) ((((int) (((sbyte) upperByte) << 8))) | (ubyte) lowerByte))


  //#define bytesToSWord(lowerByte, upperByte)  (((((TLargeValue) ( ((sbyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))
  //#define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((ubyte) pCurrOp->parmLow, (*(sbyte *) &pCurrOp->parmHigh))
  #define getLowHighParmSWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

  #define bytesToUWord(lowerByte, upperByte)  ((unsigned int) ((((unsigned int) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
  //#define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((ubyte) pCurrOp->parmLow, (ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) (*(sword *) &pCurrOp->parmLow)

  typedef signed   int TSSmallValue;
  typedef unsigned int TUSmallValue;
  typedef signed   int TLargeValue;  // 32-bits
  typedef unsigned int TULargeValue; // 32-bits


#elif defined(AVRCPU) || defined(Generic)

  #define bytesToUWordXXX(lowerByte, upperByte) \
  (__extension__({                \
      uint8_t __lowerByte = (uint8_t)(lowerByte); \
      uint8_t __upperByte = (uint8_t)(upperByte); \
      uint16_t __result;           \
      __asm__                     \
      (                           \
        "mov %A0, %1"   "\n\t"    \
        "mov %B0, %2"   "\n\t"    \
          : "=r" (__result)       \
          : "r" (__lowerByte),    \
            "r" (__upperByte)     \
      );                          \
      __result;                   \
  }))

  #define bytesToSWordXXX(lowerByte, upperByte) \
  (__extension__({                \
      uint8_t __lowerByte = (uint8_t)(lowerByte); \
      uint8_t __upperByte = (uint8_t)(upperByte); \
      int16_t __result;           \
      __asm__                     \
      (                           \
        "mov %A0, %1"   "\n\t"    \
        "mov %B0, %2"   "\n\t"    \
          : "=r" (__result)       \
          : "r" (__lowerByte),    \
            "r" (__upperByte)     \
      );                          \
      __result;                   \
  }))

  #define bytesToSWord(lowerByte, upperByte)  ((word) ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte)))

  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  #define bytesToUWord(lowerByte, upperByte)  ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))

  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  typedef sbyte TSSmallValue;
  typedef ubyte TUSmallValue;
  typedef word  TLargeValue;        //  16-bits
  typedef uword TULargeValue;       //  16-bits

#elif defined(VEX)

	//
  // Need to ensure that C18 PIC compiler doesn't do 'bytesToWord' in all 'sbyte' arithmetic. To do this, at least one of the
  // parameters must be cast as 'uword' because compiler only looks at size of expression factors and not size of result in
  // determining the precision of expression evaluation.
  //
  #define bytesToSWord(lowerByte, upperByte) ((word) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8))))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  #define bytesToUWord(lowerByte, upperByte) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8)))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  typedef sbyte TSSmallValue;
  typedef ubyte TUSmallValue;
  typedef word  TLargeValue;        //  16-bits
  typedef uword TULargeValue;       //  16-bits

#elif  defined(PIC24)

	//
  // Need to ensure that C30 PIC compiler doesn't do 'bytesToWord' in all 'sbyte' arithmetic. To do this, at least one of the
  // parameters must be cast as 'uword' because compiler only looks at size of expression factors and not size of result in
  // determining the precision of expression evaluation.
  //
  #define bytesToSWord(lowerByte, upperByte) ((word) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8))))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  #define bytesToUWord(lowerByte, upperByte) ((uword) ((ubyte) (lowerByte & (ubyte) 0xFF) | (((uword) upperByte) << 8)))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  typedef sbyte TSSmallValue;
  typedef ubyte TUSmallValue;
  typedef word  TLargeValue;          //  16-bits
  typedef uword TULargeValue;         //  16-bits


#else

	#error "Illegal Platform Type"

  // Possibly use "word" instead of use "uword"????
  #define bytesToSWord(lowerByte, upperByte)  ((word) ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte)))
  #define getHighLowParmSWord(parmHigh, parmLow) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmSWord(parmLow, parmHigh) bytesToSWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  #define bytesToUWord(lowerByte, upperByte)  ((uword) ((((uword) (((ubyte) upperByte) << 8))) | (ubyte) lowerByte))
  #define getHighLowParmUWord(parmHigh, parmLow) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)
  #define getLowHighParmUWord(parmLow, parmHigh) bytesToUWord((volatile ubyte) pCurrOp->parmLow, (volatile ubyte) pCurrOp->parmHigh)

  typedef sbyte TSSmallValue;
  typedef ubyte TUSmallValue;
  typedef word  TLargeValue;        //  16-bits
  typedef uword TULargeValue;       //  16-bits


#endif


//typedef TULargeValue TULargeValue;
typedef ubyte *pUbyte;
typedef uword *pUword;


#ifdef __cplusplus
  }
#endif

#endif
