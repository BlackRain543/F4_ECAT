/*
 * glob_variables.h
 *
 *  Created on: Jul 25, 2022
 *      Author: x9355
 */

#ifndef PORT_VAR_PORT_H_
#define PORT_VAR_PORT_H_

#include "port/math_port.h"
#include "port/peripheral_port.hpp"
#include "port/typedef_port.h"

extern ADC_HandleTypeDef 		hadc1;
extern ADC_HandleTypeDef 		hadc2;

extern SPI_HandleTypeDef 		hspi1;
extern SPI_HandleTypeDef 		hspi2;

extern UART_HandleTypeDef 		huart1;
extern UART_HandleTypeDef 		huart2;

extern I2C_HandleTypeDef 		hi2c1;
extern CAN_HandleTypeDef  		hcan1;

extern DAC_HandleTypeDef 		hdac;
extern TIM_HandleTypeDef 		htim2;

/* --------------------------------- */
#define H_CAN_Com2PC			&hcan1

#define H_TIM2					&htim2

#define	H_UART_RS485			&huart1
#define H_GPIOx_RS485_DIR		GPIOC
#define H_GPIO_PIN_RS485_DIR	GPIO_PIN_13

#define H_DAC 					&hdac

#define H_ADC1 					&hadc1
#define H_ADC2 					&hadc2

#define ADC1_CHANNEL			0
#define ADC2_CHANNEL			1

#define H_SPI1 					&hspi1
#define H_SPI_ET1100 			&hspi2

/* SYNC */
#define	H_GPIOx_SYNC0					GPIOA
#define	H_GPIO_PIN_SYNC0				GPIO_PIN_0

#define	H_GPIOx_SYNC1					GPIOA
#define	H_GPIO_PIN_SYNC1				GPIO_PIN_1

#define	H_GPIOx_SPI2_IRQ				GPIOA
#define	H_GPIO_PIN_SPI2_IRQ				GPIO_PIN_8

#define	H_GPIOx_ET1100_SPI_NSS			GPIOB
#define	H_GPIO_PIN_ET1100_SPI_NSS		GPIO_PIN_8

/* LED */
#define	H_GPIOx_LED0					GPIOB
#define	H_GPIO_PIN_LED0					GPIO_PIN_14

#define H_GPIOx_LED1					GPIOB
#define H_GPIO_PIN_LED1					GPIO_PIN_13

#define	H_GPIOx_LED2					GPIOB
#define	H_GPIO_PIN_LED2					GPIO_PIN_12

#define H_GPIOx_LED3					GPIOB
#define H_GPIO_PIN_LED3					GPIO_PIN_11

#define	H_GPIOx_LED4					GPIOB
#define	H_GPIO_PIN_LED4					GPIO_PIN_1

#define H_GPIOx_LED5					GPIOB
#define H_GPIO_PIN_LED5					GPIO_PIN_0

#define	H_GPIOx_LED6					GPIOC
#define	H_GPIO_PIN_LED6					GPIO_PIN_5

#define H_GPIOx_LED7					GPIOC
#define H_GPIO_PIN_LED7					GPIO_PIN_4

#define	H_GPIOx_RS485_DIR				GPIOC
#define	H_GPIO_PIN_RS485_DIR			GPIO_PIN_13


#define	H_GPIOx_EEPROM_LOADED			GPIOD
#define	H_GPIO_PIN_EEPROM_LOADED		GPIO_PIN_2

/* INPUT */
#define	H_GPIOx_IN0						GPIOC
#define	H_GPIO_PIN_IN0					GPIO_PIN_12

#define H_GPIOx_IN1						GPIOC
#define H_GPIO_PIN_IN1					GPIO_PIN_11

#define	H_GPIOx_IN2						GPIOC
#define	H_GPIO_PIN_IN2					GPIO_PIN_10

#define H_GPIOx_IN3						GPIOC
#define H_GPIO_PIN_IN3					GPIO_PIN_9

#define	H_GPIOx_IN4						GPIOC
#define	H_GPIO_PIN_IN4					GPIO_PIN_8

#define H_GPIOx_IN5						GPIOC
#define H_GPIO_PIN_IN5					GPIO_PIN_7

#define	H_GPIOx_IN6						GPIOC
#define	H_GPIO_PIN_IN6					GPIO_PIN_6

#define H_GPIOx_IN7						GPIOB
#define H_GPIO_PIN_IN7					GPIO_PIN_15

/* [Xiaox] */
/** ========================================== Memory ========================================== **/
/* | STM32F405RGT6 | 12 sectors | 1024kB 	| */
/**
 * | sector 0 	| 0x08000000	|	16kb 	|
 * | sector 1 	| 0x08004000	|	16kb 	|
 * | sector 2 	| 0x08008000	|	16kb 	|
 * | sector 3 	| 0x0800C000	|	16kb 	|
 * | sector 4 	| 0x08010000	|	64kb 	|
 * | sector 5 	| 0x08020000	|	128kb 	|
 * | sector 6 	| 0x08040000	|	128kb 	|
 * | sector 7 	| 0x08060000	|	128kb 	|
 * | sector 8 	| 0x08080000	|	128kb 	|
 * | sector 9 	| 0x080A0000	|	128kb 	|
 * | sector 10 	| 0x080C0000	|	128kb 	|
 * | sector 11 	| 0x080E0000	|	128kb 	|
 */

/* EEPROM */
#define 	EEPROM_START_ADDRESS  			((uint32_t)0x08080000)
#define		EEPROM_SECTOR_SIZE				((uint32_t)0x00020000)			/* 128kb */

#define 	EEPROM_SECTOR0_ID               FLASH_SECTOR_8
#define 	EEPROM_SECTOR1_ID               FLASH_SECTOR_9
#define 	EEPROM_NB_OF_VAR             	((uint8_t)2)

/* RS485 */
extern Port::UartCom		uart2rs485;
extern Port::GPIO			rs485_dir_gpio;

/* ET1100 */
extern Port::SPIComm		et1100_spi;
extern Port::CS				et1100_cs;
extern Port::EXIT			spi2_irq;
extern Port::EXIT			sync0_exitGpio;
extern Port::EXIT			sync1_exitGpio;
extern Port::GPIO			eeprom_loaded_gpio;
extern Port::TIM			ethercat_tim;

extern Port::GPIO			led0_gpio;
extern Port::GPIO			led1_gpio;
extern Port::GPIO			led2_gpio;
extern Port::GPIO			led3_gpio;
extern Port::GPIO			led4_gpio;
extern Port::GPIO			led5_gpio;
extern Port::GPIO			led6_gpio;
extern Port::GPIO			led7_gpio;

extern Port::CANComm		can2PC;

extern Port::GPIO			in0_gpio;
extern Port::GPIO			in1_gpio;
extern Port::GPIO			in2_gpio;
extern Port::GPIO			in3_gpio;
extern Port::GPIO			in4_gpio;
extern Port::GPIO			in5_gpio;
extern Port::GPIO			in6_gpio;
extern Port::GPIO			in7_gpio;

#include "drivers/et1100.h"

extern ET1100 et1100;

#endif /* PORT_VAR_PORT_H_ */
