#include "common_inc.h"

//#include "arm_math.h"



//LED::LED led0(led0_gpio);
//LED::LED led1(led1_gpio);
//LED::LED led2(led2_gpio);
//LED::LED led3(led3_gpio);

uint16_t adc1Data[2] = {};
uint16_t adc2Data[2] = {};

uint32_t dacData[2] = {1024,2048};

extern TIM_HandleTypeDef htim2;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern DAC_HandleTypeDef hdac;

void MainCpp()
{


	HAL_TIM_Base_Start_IT(&htim2);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc1Data, 1);
	HAL_ADC_Start_DMA(&hadc2, (uint32_t *)adc2Data, 1);

	HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, &dacData[0], 1, DAC_ALIGN_12B_R);
	HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_2, &dacData[1], 1, DAC_ALIGN_12B_R);

	MainEtherCAT();

//	led0.SetMode(LED::MODE_ONCE_FLASH);
//	led1.SetMode(LED::MODE_TWICE_FLASH);
//	led2.SetMode(LED::MODE_TRIPLE_FLASH);
//	led3.SetMode(LED::MODE_QUADRA_FLASH);
//
//
//	for(;;)
//	{

//		if(in0_gpio.ReadPin() == GPIO_PIN_SET)
//			led0.Display();
//		if(in1_gpio.ReadPin() == GPIO_PIN_SET)
//			led1.Display();
//		if(in2_gpio.ReadPin() == GPIO_PIN_SET)
//			led2.Display();
//		if(in3_gpio.ReadPin() == GPIO_PIN_SET)
//			led3.Display();


//		msDelay(1);
//	}


}
