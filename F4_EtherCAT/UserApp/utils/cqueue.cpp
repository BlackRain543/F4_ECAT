/*
 * cqueue.cpp
 *
 *  Created on: Jan 16, 2023
 *      Author: LimX Drive
 */

#include "utils/cqueue.h"

static inline uint32_t IsNotPowerOfTwo(uint32_t number)
{
	return (number & (number-1));
}

CQueueNS::CQueue::CQueue(uint32_t totalLen, uint8_t *pBuffer_)
:InitResult(ERROR),readIdx(0),writeIdx(0),mask(0),pBuffer(NULL),IsDeleteNeeded(0),ndtrLast(totalLen)
{
	if(IsNotPowerOfTwo(totalLen))
	{}
	else
	{
		if(pBuffer_ == NULL)
		{
			pBuffer = new uint8_t [totalLen];
			IsDeleteNeeded = 1;
		}
		else
		{
			pBuffer = pBuffer_;
		}
		if(pBuffer != NULL)
		{
			mask = totalLen - 1;
			InitResult = SUCCESS;
		}
	}
}


CQueueNS::CQueue::~CQueue()
{
	Reset();
	if(IsDeleteNeeded)
	{
		delete []pBuffer;
	}
	pBuffer = NULL;
}

void CQueueNS::CQueue::Reset()
{
	readIdx = 0;
	writeIdx = 0;
}

void CQueueNS::CQueue::CopyIn(uint8_t pData[], uint32_t len,uint32_t offset)
{
	offset = min(offset,UnusedLength());
	len = min(len,UnusedLength()-offset);

	uint32_t writeOffset 	= mask & (writeIdx + offset);
	uint32_t backSpace 		= TotalLength() - writeOffset;
	uint32_t dataToBackLen  = min(backSpace,len);
	uint32_t dataToHeadLen 	= len - dataToBackLen;

	memcpy(pBuffer + writeOffset, 	pData, 					dataToBackLen);
	memcpy(pBuffer, 				pData + dataToBackLen,	dataToHeadLen);
}

CQueueNS::CQueueStatus CQueueNS::CQueue::In(uint8_t pData[], uint32_t len,uint32_t offset)
{
	uint32_t totalLen = len + offset;
	CQueueStatus status = (totalLen > UnusedLength())?(CQUEUE_OPERATE_FULL_ERROR):(CQUEUE_OPERATE_SUCCESS);
	CopyIn(pData,len,offset);
	writeIdx += min(totalLen,UnusedLength());
	return status;
}

CQueueNS::CQueueStatus CQueueNS::CQueue::EntirelyIn(uint8_t pData[], uint32_t len,uint32_t offset)
{
	uint32_t totalLen = len + offset;
	CQueueStatus status = (totalLen > UnusedLength())?(CQUEUE_OPERATE_FULL_ERROR):(CQUEUE_OPERATE_SUCCESS);
	if(CQUEUE_OPERATE_SUCCESS == status)
	{
		CopyIn(pData,len,offset);
		writeIdx += min(totalLen,UnusedLength());
	}
	return status;
}

void CQueueNS::CQueue::CopyOut(uint8_t pData[], uint32_t len,uint32_t offset)
{
	offset = min(offset,UsedLength());
	len = min(len,UsedLength()-offset);

	uint32_t readOffset 	 = mask & (readIdx+offset);
	uint32_t backSpace 		 = TotalLength() - readOffset;
	uint32_t dataFromBackLen = min(backSpace,len);
	uint32_t dataFromHeadLen = len - dataFromBackLen;

	memcpy(pData, pBuffer + readOffset, dataFromBackLen);
	memcpy(pData + dataFromBackLen,	pBuffer, dataFromHeadLen);
}

CQueueNS::CQueueStatus CQueueNS::CQueue::Out(uint8_t pData[], uint32_t len,uint32_t offset)
{
	uint32_t totalLen = len + offset;
	CQueueStatus status = (totalLen > UsedLength())?(CQUEUE_OPERATE_EMPTY_ERROR):(CQUEUE_OPERATE_SUCCESS);
	CopyOut(pData,len,offset);
	readIdx += min(totalLen,UsedLength());
	return status;
}

CQueueNS::CQueueStatus CQueueNS::CQueue::RemoveFromFront(uint32_t len)
{
	CQueueStatus status = (len > UsedLength())?(CQUEUE_OPERATE_EMPTY_ERROR):(CQUEUE_OPERATE_SUCCESS);
	len = min(len,UsedLength());
	readIdx += len;
	return status;
}

void CQueueNS::CQueue::UpdateDataRecvIDLE(uint32_t ndtrNow)
{
	__disable_irq();
	if(ndtrLast >= ndtrNow)
	{
		writeIdx += (ndtrLast - ndtrNow);
	}
	else
	{
		writeIdx += (ndtrLast + TotalLength() - ndtrNow);
	}
	if(UsedLength() > TotalLength())
	{
		readIdx =writeIdx - TotalLength();
	}

	ndtrLast = ndtrNow;
	__enable_irq();
}

void CQueueNS::CQueue::UpdateDataRecvDmaTC(uint32_t ndtrNow)
{
	__disable_irq();
	if(ndtrLast >= ndtrNow)
	{
		writeIdx += (ndtrLast - ndtrNow);
	}
	else
	{
		writeIdx += (ndtrLast + TotalLength() - ndtrNow);
	}
	if(UsedLength() > TotalLength())
	{
		readIdx =writeIdx - TotalLength();
	}

	ndtrLast = ndtrNow;
	__enable_irq();
}

/*

CQueueNS::CQueueCdma::CQueueCdma(uint32_t totalLen, uint8_t *pBuffer_)
:InitResult(ERROR),readIdx(0),writeIdx(0),mask(0),pBuffer(NULL),IsDeleteNeeded(0),ndtrLast(totalLen)
{
	if(IsNotPowerOfTwo(totalLen))
	{}
	else
	{
		if(pBuffer_ == NULL)
		{
			pBuffer = new uint8_t [totalLen];
			IsDeleteNeeded = 1;
		}
		else
		{
			pBuffer = pBuffer_;
		}
		if(pBuffer != NULL)
		{
			mask = totalLen - 1;
			InitResult = SUCCESS;
		}
	}
}


CQueueNS::CQueueCdma::~CQueueCdma()
{
	Reset();
	if(IsDeleteNeeded)
	{
		delete []pBuffer;
	}
	pBuffer = NULL;
}

void CQueueNS::CQueueCdma::UpdateDataRecvIDLE(uint32_t ndtrNow)
{
	__disable_irq();
	if(ndtrLast >= ndtrNow)
	{
		writeIdx += (ndtrLast - ndtrNow);
	}
	else
	{
		writeIdx += (ndtrLast + TotalLength() - ndtrNow);
	}
	if(UsedLength() > TotalLength())
	{
		readIdx =writeIdx - TotalLength();
	}

	ndtrLast = ndtrNow;
	__enable_irq();
}

void CQueueNS::CQueueCdma::UpdateDataRecvDmaTC(uint32_t ndtrNow)
{
	__disable_irq();
	if(ndtrLast >= ndtrNow)
	{
		writeIdx += (ndtrLast - ndtrNow);
	}
	else
	{
		writeIdx += (ndtrLast + TotalLength() - ndtrNow);
	}
	if(UsedLength() > TotalLength())
	{
		readIdx =writeIdx - TotalLength();
	}

	ndtrLast = ndtrNow;
	__enable_irq();
}


void CQueueNS::CQueueCdma::CopyOut(uint8_t pData[], uint32_t len,uint32_t offset)
{
	offset = min(offset,UsedLength());
	len = min(len,UsedLength()-offset);

	uint32_t readOffset 	 = mask & (readIdx+offset);
	uint32_t backSpace 		 = TotalLength() - readOffset;
	uint32_t dataFromBackLen = min(backSpace,len);
	uint32_t dataFromHeadLen = len - dataFromBackLen;

	memcpy(pData, pBuffer + readOffset, dataFromBackLen);
	memcpy(pData + dataFromBackLen,	pBuffer, dataFromHeadLen);
}

CQueueNS::CQueueStatus CQueueNS::CQueueCdma::Out(uint8_t pData[], uint32_t len,uint32_t offset)
{
	uint32_t totalLen = len + offset;
	CQueueStatus status = (totalLen > UsedLength())?(CQUEUE_OPERATE_EMPTY_ERROR):(CQUEUE_OPERATE_SUCCESS);
	CopyOut(pData,len,offset);
	readIdx += min(totalLen,UsedLength());
	return status;
}

CQueueNS::CQueueStatus CQueueNS::CQueueCdma::RemoveFromFront(uint32_t len)
{
	CQueueStatus status = (len > UsedLength())?(CQUEUE_OPERATE_EMPTY_ERROR):(CQUEUE_OPERATE_SUCCESS);
	len = min(len,UsedLength());
	readIdx += len;
	return status;
}
*/

