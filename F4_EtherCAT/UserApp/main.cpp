#include "common_inc.h"

//#include "arm_math.h"



LED::LED led0(led0_gpio);
LED::LED led1(led1_gpio);
LED::LED led2(led2_gpio);
LED::LED led3(led3_gpio);

void MainCpp()
{
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
//
//		msDelay(1);
//	}


}