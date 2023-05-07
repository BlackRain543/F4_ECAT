/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "common_inc.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RS485_CTRL_Pin GPIO_PIN_13
#define RS485_CTRL_GPIO_Port GPIOC
#define SYNC0_Pin GPIO_PIN_0
#define SYNC0_GPIO_Port GPIOA
#define SYNC1_Pin GPIO_PIN_1
#define SYNC1_GPIO_Port GPIOA
#define LED7_Pin GPIO_PIN_4
#define LED7_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_5
#define LED6_GPIO_Port GPIOC
#define LED5_Pin GPIO_PIN_0
#define LED5_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_1
#define LED4_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_11
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_12
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOB
#define LED0_Pin GPIO_PIN_14
#define LED0_GPIO_Port GPIOB
#define IN7_Pin GPIO_PIN_15
#define IN7_GPIO_Port GPIOB
#define IN6_Pin GPIO_PIN_6
#define IN6_GPIO_Port GPIOC
#define IN7C7_Pin GPIO_PIN_7
#define IN7C7_GPIO_Port GPIOC
#define IN4_Pin GPIO_PIN_8
#define IN4_GPIO_Port GPIOC
#define IN3_Pin GPIO_PIN_9
#define IN3_GPIO_Port GPIOC
#define SPI2_IRQ_Pin GPIO_PIN_8
#define SPI2_IRQ_GPIO_Port GPIOA
#define SPI1_NSS_Pin GPIO_PIN_15
#define SPI1_NSS_GPIO_Port GPIOA
#define IN2_Pin GPIO_PIN_10
#define IN2_GPIO_Port GPIOC
#define IN1_Pin GPIO_PIN_11
#define IN1_GPIO_Port GPIOC
#define IN0_Pin GPIO_PIN_12
#define IN0_GPIO_Port GPIOC
#define EEPROM_LOADED_Pin GPIO_PIN_2
#define EEPROM_LOADED_GPIO_Port GPIOD
#define SPI2_NSS_Pin GPIO_PIN_8
#define SPI2_NSS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
