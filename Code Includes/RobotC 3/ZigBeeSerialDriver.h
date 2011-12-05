#if !defined(__ZigBeeSerialIOD__H_)
#define __ZigBeeSerialIOD__H_


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                          Low Level Platform Specific ZigBee Char Send/Receive Functions
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C"
{
#endif

extern bool startupZBSerialLink(void);
extern void shutdownZBSerialLink(void);

extern bool getZBChar(unsigned char *pChar);
extern void sendZBChar(unsigned char currChar);

extern void xmitZBPacketStart(void);
extern void xmitZBPacketEnd(void);

extern void xmitZBPacketRetransmit(void);
extern void xmitZBPacketTransmitFailed(void);

typedef enum TZBSendType
{
	sendTypeNormal,
	sendTypeRetransmit,
	sendTypeFailed
} TZBSendType;

extern void xmitZBPacketEndLowLevel(TZBSendType nSendType);

#ifdef __cplusplus
};
#endif

#endif //#if !defined(__ZigBeeSerialIOD__H_)
