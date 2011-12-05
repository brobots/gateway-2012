#ifndef _stringOpcodes__H_
#define _stringOpcodes__H_

///////////////////////////////////////////////////////////////////////////////////////////////
//
//                               String Opcode Functions
//
///////////////////////////////////////////////////////////////////////////////////////////////

//
// String I/O Command Types
//
typedef enum TStringSubOps
{
	strOpAssignString														=  0,
	strOpAssignByte															=  1,				// Type Conversion -- byte	numeric variable/value to string
	strOpAssignShort														=  2,				// Type Conversion -- short numeric variable/value to string
	strOpAssignLong															=  3,				// Type Conversion -- long	numeric variable/value to string
	strOpAssignFloat														=  4,				// Type Conversion -- float numeric variable/value to string
	strOpFromChars															=  5,				// Type Conversion -- byte	array									 to string
	strOpToChars																=  6,				// Type Conversion -- string											 to byte array

	strOpConcatenateString											=  7,
	strOpConcatenateByte												=  8,

	strOpDelete																	=  9,
	strOpSubString															= 10,
	strOpFind																		= 11,
	strOpSize																		= 12,

	strOpSPRINTF																= 13,
	strOpSNPRINTF																= 14,

	strOpGetDebugStreamAvailableSpace						= 15,				// Debug stream support
	strOpDebugStreamFormat											= 16,				// Debug stream support
	strOpDebugStreamFormatWithNewLine						= 17,				// Debug stream support

	strOpGetChar						                    = 18,
	strOpGetAddress						                  = 19,

	strOp_atoi_long					                    = 20,
	strOp_atof    					                    = 21,

#if defined(has_sscanf_Support)
	strOpSSCANF																	= 22,			// Standard 'sscanf' function'
#endif

} TStringSubOps;

#define kStringSize 20

#endif
