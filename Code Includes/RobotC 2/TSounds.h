#ifndef TSounds__H_
#define TSounds__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                              Sound Types
//
//////////////////////////////////////////////////////////////////////////////////////////////


typedef enumWord
{
  soundBlip             = 0,
  soundBeepBeep         = 1,
  soundDownwardTones    = 2,
  soundUpwardTones      = 3,
  soundLowBuzz          = 4,
  soundFastUpwardTones  = 5,
  soundShortBlip        = 6,
  soundException        = 7,
  soundLowBuzzShort     = 8,

#if !(defined(NXT) || defined(TETRIX))
  soundLast
#endif

} TSounds;


#endif
