/**
 * \addtogroup EL9800_HW EL9800 Platform (Serial ESC Access)
 * @{
 */

/**
\file el9800hw.h
\author EthercatSSC@beckhoff.com
\brief Defines to access the EL9800 specific periphery and ESC (via SPI)

\version 5.01

<br>Changes to version - :<br>
V5.01 : Start file change log
 */

#ifndef _EL9800HW_H_
#define _EL9800HW_H_


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include  "esc.h"

//#include <p24Hxxxx.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
//#include "system.h"

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/
#define ESC_RD                    0x02 /**< \brief Indicates a read access to ESC or EEPROM*/
#define ESC_WR                    0x04 /**< \brief Indicates a write access to ESC or EEPROM.*/

int MainEtherCAT(void);


#define BITBAND(addr, bitnum) 		((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_Addr(addr)  			*((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   	MEM_Addr(BITBAND(addr, bitnum))

#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414
#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814
#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14
#define GPIOE_ODR_Addr    (GPIOE_BASE+20) //0x40021014
#define GPIOF_ODR_Addr    (GPIOF_BASE+20) //0x40021414
#define GPIOG_ODR_Addr    (GPIOG_BASE+20) //0x40021814
#define GPIOH_ODR_Addr    (GPIOH_BASE+20) //0x40021C14
#define GPIOI_ODR_Addr    (GPIOI_BASE+20) //0x40022014

#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410
#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10
#define GPIOE_IDR_Addr    (GPIOE_BASE+16) //0x40021010
#define GPIOF_IDR_Addr    (GPIOF_BASE+16) //0x40021410
#define GPIOG_IDR_Addr    (GPIOG_BASE+16) //0x40021810
#define GPIOH_IDR_Addr    (GPIOH_BASE+16) //0x40021C10
#define GPIOI_IDR_Addr    (GPIOI_BASE+16) //0x40022010

#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)

#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)
#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)

#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)
#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)

/*---------------------------------------------
-    Microcontroller definitions
-----------------------------------------------*/

extern	uint16_t uhADCxConvertedValue;

#define SWITCH_1            PCin(12)				// PORTDbits.RD7 /**< \brief Access to switch 1 input*/
#define SWITCH_2            PCin(11)				// PORTDbits.RD6 /**< \brief Access to switch 2 input*/
#define SWITCH_3            PCin(10)				// PORTDbits.RD5 /**< \brief Access to switch 3 input*/
#define SWITCH_4            PCin(9)					// PORTDbits.RD4 /**< \brief Access to switch 4 input*/
#define SWITCH_5            PCin(8)					// PORTDbits.RD3 /**< \brief Access to switch 5 input*/
#define SWITCH_6            PCin(7)					// PORTDbits.RD2 /**< \brief Access to switch 6 input*/
#define SWITCH_7            PCin(6)					// PORTDbits.RD1 /**< \brief Access to switch 7 input*/
#define SWITCH_8            PBin(15)				// PORTDbits.RD0 /**< \brief Access to switch 8 input*/

#define LED_1               PBout(14)				// LATBbits.LATB8 /**< \brief Access to led 1 output*/
#define LED_2               PBout(13)				// LATBbits.LATB9 /**< \brief Access to led 2 output*/
#define LED_3               PBout(12)				// LATBbits.LATB10 /**< \brief Access to led 3 output*/
#define LED_4               PBout(11)				// LATBbits.LATB11 /**< \brief Access to led 4 output*/
#define LED_5               PBout(1)				// LATBbits.LATB12 /**< \brief Access to led 5 output*/
#define LED_6               PBout(0)				// LATBbits.LATB13 /**< \brief Access to led 6 output*/
#define LED_7               PCout(5)				// LATBbits.LATB14 /**< \brief Access to led 7 output*/
#define LED_8               PCout(4)				// LATBbits.LATB15 /**< \brief Access to led 8 output*/

/*---------------------------------------------
-    hardware timer settings
-----------------------------------------------*/

#define 	ECAT_TIMER_INC_P_MS  	 	2000 //72000   	//0x271 /**< \brief 625 ticks per ms*/



/*---------------------------------------------
-    Interrupt and Timer defines
-----------------------------------------------*/

#ifndef 	DISABLE_ESC_INT
#define    	DISABLE_ESC_INT()           	NVIC_DisableIRQ(EXTI9_5_IRQn)		// {(_INT1IE)=0;} /**< \brief Disable interrupt source INT1*/
#endif
#ifndef 	ENABLE_ESC_INT
#define    	ENABLE_ESC_INT()           		NVIC_EnableIRQ(EXTI9_5_IRQn)		// {(_INT1IE)=1;} /**< \brief Enable interrupt source INT1*/
#endif

#ifndef 	HW_GetTimer
#define 	HW_GetTimer()       			TIM2->CNT							//(SysTick->LOAD - 	SysTick->VAL) //			// ((UINT16)(TMR7)) /**< \brief Access to the hardware timer*/
#endif

#ifndef 	HW_ClearTimer
#define 	HW_ClearTimer()         		((TIM2->CNT)=0); 					//(SysTick->VAL = SysTick->LOAD)// //{(TMR7) = 0;} /**< \brief Clear the hardware timer*/
#endif


#define HW_EscReadByte(ByteValue,Address)			HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#define HW_EscReadWord(WordValue, Address) 			HW_EscRead(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC read access*/
#define HW_EscReadDWord(DWordValue, Address) 		HW_EscRead(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC read access*/
#define HW_EscReadMbxMem(pData,Address,Len) 		HW_EscRead(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default read function is used.*/

#define HW_EscReadByteIsr(ByteValue,Address)		HW_EscRead(((MEM_ADDR *)&(ByteValue)),((UINT16)(Address)),1)
#define HW_EscReadWordIsr(WordValue, Address) 		HW_EscReadIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC read access*/
#define HW_EscReadDWordIsr(DWordValue, Address) 	HW_EscReadIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC read access*/

#define HW_EscWriteByte(WordValue, Address) 		HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),1)
#define HW_EscWriteWord(WordValue, Address) 		HW_EscWrite(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief 16Bit ESC write access*/
#define HW_EscWriteDWord(DWordValue, Address) 		HW_EscWrite(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief 32Bit ESC write access*/
#define HW_EscWriteMbxMem(pData,Address,Len) 		HW_EscWrite(((MEM_ADDR *)(pData)),((UINT16)(Address)),(Len)) /**< \brief The mailbox data is stored in the local uC memory therefore the default write function is used.*/

#define HW_EscWriteWordIsr(WordValue, Address) 		HW_EscWriteIsr(((MEM_ADDR *)&(WordValue)),((UINT16)(Address)),2) /**< \brief Interrupt specific 16Bit ESC write access*/
#define HW_EscWriteDWordIsr(DWordValue, Address) 	HW_EscWriteIsr(((MEM_ADDR *)&(DWordValue)),((UINT16)(Address)),4) /**< \brief Interrupt specific 32Bit ESC write access*/

#endif //_EL9800HW_H_


#if _EL9800HW_
    #define PROTO
#else
    #define PROTO extern
#endif


/*-----------------------------------------------------------------------------------------
------
------    Global variables
------
-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------
------
------    Global functions
------
-----------------------------------------------------------------------------------------*/
PROTO UINT8 	HW_Init(void);
PROTO void 		HW_Release(void);
PROTO UINT16 	HW_GetALEventRegister(void);

PROTO UINT16 	HW_GetALEventRegister_Isr(void);

PROTO void 		HW_ResetALEventMask(UINT16 intMask);
PROTO void 		HW_SetALEventMask(UINT16 intMask);
PROTO void 		HW_SetLed(UINT8 RunLed,UINT8 ErrLed);

PROTO void 		HW_EscRead( MEM_ADDR * pData, UINT16 Address, UINT16 Len );
PROTO void 		HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void 		HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void 		HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len );

PROTO void 		HW_DisableSyncManChannel(UINT8 channel);
PROTO void 		HW_EnableSyncManChannel(UINT8 channel);
PROTO TSYNCMAN ESCMEM *HW_GetSyncMan(UINT8 channel);

/*---------------------------------------------
-    ESC Access macros
-----------------------------------------------*/
#if _EL9800HW_

#endif //#if _EL9800HW_
#undef    PROTO
/** @}*/
