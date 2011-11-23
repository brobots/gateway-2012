#ifndef _GraphcisLCD__H_
#define _GraphcisLCD__H_

#if !defined(enumWord)
  #if defined(ROBOTC) && !defined(enumWord)
    #define enumWord enum word
  #else
    #define enumWord enum
  #endif
#endif


typedef enum TGraphicDisplayCommands
{
  displayDrawEraseScreen                       =  0,
  displayDrawSetPixel                          =  1,
  displayDrawClearPixel                        =  2,
  displayDrawLine                              =  3,
  displayDrawInvertEllipse                     =  4,
  displayDrawInvertRect                        =  5,
  displayDrawRect                              =  6,
  displayDrawEraseRect                         =  7,
  displayDrawEllipse                           =  8,
  displayDrawCircle                            =  9,
  displayDrawFillEllipse                       = 10,
  displayDrawEraseEllipse                      = 11,
  displayDrawFillRect                          = 12,
  displayDrawRICFile                           = 13,
  displayDrawTextLineVarArgs                   = 14,
  displayDrawBigTextLineVarArgs                = 15,
  displayDrawCenteredTextLineVarArgs           = 16,
  displayDrawCenteredBigTextLineVarArgs        = 17,
  displayDrawStringVarArgs                     = 18,
  displayDrawStringAtCoordVarArgs              = 19,
  displayDrawBigStringAtCoordVarArgs           = 20,  // Use Big Font
  displayDrawScrollTextVarArgs                 = 21,
 	displayDrawEraseLine                         = 25,
	displayDrawInvertLine                        = 26,
	displayDrawRoundedRect                       = 27,  // Future
  displayDrawFillRoundedRect                   = 28,  // Future
  displayDrawEraseRoundedRect                  = 29   // Future
} TGraphicDisplayCommands;


#endif
