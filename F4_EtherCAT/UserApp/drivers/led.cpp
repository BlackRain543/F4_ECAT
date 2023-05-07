#include "drivers/LED.h"

LED::LED::LED(Port::GPIO &gpio,
		uint32_t periodMask,
		uint8_t	polarity)
:gpio_(gpio),mode_(0),periodMask_(periodMask),polarity_(polarity)
{}

LED::LED::~LED(){}

void LED::LED::SetMode(uint8_t mode)
{
	mode_ = mode;
}

void LED::LED::TurnOn()
{
	if(polarity_)
	{
		gpio_.SetPin();
	}
	else
	{
		gpio_.ResetPin();
	}
}

void LED::LED::TurnOff()
{
	if(polarity_)
	{
		gpio_.ResetPin();
	}
	else
	{
		gpio_.SetPin();
	}
}

void LED::LED::Display()
{
	uint32_t sysTick 		= HAL_GetTick();
	uint8_t LedStateIndex   = (sysTick & periodMask_) >> UNIT_TIME_SHIFT_BITS;
	uint8_t	LedOnOFF      	= (mode_ >> LedStateIndex) & 0x01;

	if(LedOnOFF)
	{
		TurnOn();
	}
	else
	{
		TurnOff();
	}
}


