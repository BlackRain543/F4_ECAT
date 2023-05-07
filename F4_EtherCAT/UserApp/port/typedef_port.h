/*
 * typedef_port.h
 *
 *  Created on: Jul 19, 2022
 *      Author: x9355
 */

#ifndef PORT_TYPEDEF_PORT_H_
#define PORT_TYPEDEF_PORT_H_


#ifdef __cplusplus
extern "C"{
#endif

	#include "stdint.h"
	#include "stddef.h"
	#include "stm32f4xx.h"

	//#include "cmsis_os2.h"
	//#include "FreeRTOS.h"
	//#include "task.h"
	//#include "stm32h7xx_ll_utils.h"

#ifdef __cplusplus
};
#endif

typedef enum
{
  RESULT_SUCCESS = 0,
  RESULT_ERROR 	 = !RESULT_SUCCESS
}Result;

#define ErrorStatus ErrorStatus
#define SUCCESS 	SUCCESS
#define ERROR 		ERROR
#define msDelay 	HAL_Delay
#define msOsDelay 	osDelay



#endif /* PORT_TYPEDEF_PORT_H_ */
