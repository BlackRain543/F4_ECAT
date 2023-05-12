/*
 * glob_variables.cpp
 *
 *  Created on: Jul 25, 2022
 *      Author: x9355
 */
#include "port/var_port.h"

/* RS485 */
Port::UartCom		uart2rs485(H_UART_RS485);
Port::GPIO			rs485_dir_gpio(H_GPIOx_RS485_DIR, H_GPIO_PIN_RS485_DIR);

/* ET1100 */
Port::SPIComm		et1100_spi(H_SPI_ET1100);
Port::CS			et1100_cs(H_GPIOx_ET1100_SPI_NSS, H_GPIO_PIN_ET1100_SPI_NSS, 0);
Port::EXIT			spi2_irq(H_GPIOx_SPI2_IRQ, H_GPIO_PIN_SPI2_IRQ, EXTI9_5_IRQn);
Port::EXIT			sync0_exitGpio(H_GPIOx_SYNC0, H_GPIO_PIN_SYNC0, EXTI0_IRQn);
Port::EXIT			sync1_exitGpio(H_GPIOx_SYNC1, H_GPIO_PIN_SYNC1, EXTI1_IRQn);
Port::TIM			ethercat_tim(H_TIM2);
Port::GPIO			eeprom_loaded_gpio(H_GPIOx_EEPROM_LOADED, H_GPIO_PIN_EEPROM_LOADED);


Port::GPIO			led0_gpio(H_GPIOx_LED0, H_GPIO_PIN_LED0);
Port::GPIO			led1_gpio(H_GPIOx_LED1, H_GPIO_PIN_LED1);
Port::GPIO			led2_gpio(H_GPIOx_LED2, H_GPIO_PIN_LED2);
Port::GPIO			led3_gpio(H_GPIOx_LED3, H_GPIO_PIN_LED3);
Port::GPIO			led4_gpio(H_GPIOx_LED4, H_GPIO_PIN_LED4);
Port::GPIO			led5_gpio(H_GPIOx_LED5, H_GPIO_PIN_LED5);
Port::GPIO			led6_gpio(H_GPIOx_LED6, H_GPIO_PIN_LED6);
Port::GPIO			led7_gpio(H_GPIOx_LED7, H_GPIO_PIN_LED7);

Port::CANComm		can2PC(H_CAN_Com2PC, CAN_RX_FIFO1);

Port::GPIO			in0_gpio(H_GPIOx_IN0, H_GPIO_PIN_IN0);
Port::GPIO			in1_gpio(H_GPIOx_IN1, H_GPIO_PIN_IN1);
Port::GPIO			in2_gpio(H_GPIOx_IN2, H_GPIO_PIN_IN2);
Port::GPIO			in3_gpio(H_GPIOx_IN3, H_GPIO_PIN_IN3);
Port::GPIO			in4_gpio(H_GPIOx_IN4, H_GPIO_PIN_IN4);
Port::GPIO			in5_gpio(H_GPIOx_IN5, H_GPIO_PIN_IN5);
Port::GPIO			in6_gpio(H_GPIOx_IN6, H_GPIO_PIN_IN6);
Port::GPIO			in7_gpio(H_GPIOx_IN7, H_GPIO_PIN_IN7);



ET1100 et1100(et1100_spi, et1100_cs, spi2_irq, sync0_exitGpio, sync1_exitGpio, ethercat_tim, eeprom_loaded_gpio);
