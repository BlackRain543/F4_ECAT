#ifndef __CQUEUE_H
#define __CQUEUE_H

//call c in c++
#ifdef __cplusplus
extern "C" {
#endif

	#include "stdint.h"
	#include "string.h"

#ifdef __cplusplus
}
#endif

#include "port/typedef_port.h"
#include "port/math_port.h"

namespace CQueueNS
{

	#define CQUEUE_DEFAULT_LENGTH  64

	typedef enum
	{
		CQUEUE_OPERATE_SUCCESS 		= 0x00,
		CQUEUE_OPERATE_FULL_ERROR 	= 0x01,
		CQUEUE_OPERATE_EMPTY_ERROR 	= 0x02,
		CQUEUE_OPERATE_FAIL 		= 0x03,
	}CQueueStatus;

	class CQueue
	{
		public:
			CQueue(uint32_t totalLen = CQUEUE_DEFAULT_LENGTH, uint8_t *pBuffer_ = NULL);
			~CQueue();

			void 				Reset();
			inline uint32_t 	TotalLength() 	{return (mask + 1);}
			inline uint32_t 	UsedLength()	{return (writeIdx - readIdx);}
			inline uint32_t 	UnusedLength()	{return (TotalLength() - UsedLength());}

			inline uint8_t 		IsEmpty()		{return (UsedLength() == 0);}
			inline uint8_t 		IsFull()		{return (UnusedLength() == 0);}

			void CopyIn(uint8_t pData[], 		uint32_t len = 1,uint32_t offset = 0);
			CQueueStatus In(uint8_t pData[], 	uint32_t len = 1,uint32_t offset = 0);
			CQueueStatus EntirelyIn(uint8_t pData[], uint32_t len = 1,uint32_t offset = 0);

			void CopyOut(uint8_t pData[], 		uint32_t len = 1,uint32_t offset = 0);
			CQueueStatus Out(uint8_t pData[], 	uint32_t len = 1,uint32_t offset = 0);
			CQueueStatus RemoveFromFront(		uint32_t len = 1);

			// The functions below can only be used when dma is used
			inline void SetWriteIdxNow(uint32_t idx)		{writeIdx = idx;}
			void UpdateDataRecvIDLE(uint32_t ndtrNow);
			void UpdateDataRecvDmaTC(uint32_t ndtrNow);


			ErrorStatus		InitResult;

			uint32_t 		readIdx;
			uint32_t 		writeIdx;
			uint32_t 		mask;
			uint8_t  	  	*pBuffer;
			uint8_t			IsDeleteNeeded;
			uint32_t 		ndtrLast;
	};

/*
class CQueueCdma{
public:
	CQueueCdma(uint32_t totalLen = CQUEUE_DEFAULT_LENGTH, uint8_t *pBuffer_ = NULL);
	~CQueueCdma();

	inline void			Reset()			{readIdx = writeIdx;}
	inline uint32_t 	TotalLength() 	{return (mask + 1);}
	inline uint32_t 	UsedLength()	{return (writeIdx - readIdx);}
	inline uint32_t 	UnusedLength()	{return (TotalLength() - UsedLength());}

	inline uint8_t 	IsEmpty()			{return (UsedLength() == 0);}
	inline uint8_t 	IsFull()			{return (UnusedLength() == 0);}

	inline void SetWriteIdxNow(uint32_t idx)		{writeIdx = idx;}
	void UpdateDataRecvIDLE(uint32_t ndtrNow);
	void UpdateDataRecvDmaTC(uint32_t ndtrNow);

	void CopyOut(uint8_t pData[], uint32_t len = 1,uint32_t offset = 0);
	CQueueStatus Out(uint8_t pData[], uint32_t len = 1,uint32_t offset = 0);

	CQueueStatus RemoveFromFront(uint32_t len = 1);
	ErrorStatus		InitResult;
	uint32_t 		ndtrLast;
	uint32_t 		readIdx;
	uint32_t 		writeIdx;
	uint32_t 		mask;
	uint8_t  	  	*pBuffer;
	uint8_t			IsDeleteNeeded;

};*/

	extern CQueue msgInCQueue;
}



#endif
