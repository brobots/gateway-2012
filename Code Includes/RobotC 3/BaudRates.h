#if !defined(_BaudRates__H_)
#define _BaudRates__H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TBaudRate
{
	baudRate1200				= 0,
	baudRate2400				= 1,
	baudRate4800				= 2,
	baudRate9600				= 3,
	baudRate14400				= 4,
	baudRate19200				= 5,
	baudRate28800				= 6,
	baudRate38400				= 7,
	baudRate57600				= 8,
	baudRate76800				= 9,
	baudRate100000			= 10,
	baudRate115200			= 11,
	baudRate200000			= 12,
	baudRate230400			= 13,
	baudRate250000			= 14,
	baudRateUndefined
} TBaudRate;

#define kArduinoBaudRate baudRate200000


typedef enum TParityType
{
  parityNone,
  parityEven,
  parityOdd
} TParityType;


#ifdef __cplusplus
};
#endif


#endif
