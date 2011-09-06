#if !defined(_BaudRates__H_)
#define _BaudRates__H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	//baudRate1200,
	//baudRate2400,
	baudRate4800				= 0,
	baudRate9600				= 1,
	baudRate19200				= 2,
	baudRate38400				= 3,
	baudRate57600				= 4,
	baudRate115200			= 5,
	baudRate200000			= 6,
	baudRate230400			= 7,
	baudRate250000			= 8,
	baudRateUndefined
} TBaudRate;

typedef enum 
{
  parityNone,
  parityEven,
  parityOdd
} TParityType;


#ifdef __cplusplus
};
#endif


#endif
