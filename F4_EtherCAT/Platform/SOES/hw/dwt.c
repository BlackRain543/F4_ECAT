#include "dwt.h"

static uint32_t ticksPerUs = MAX_FREQ_TICKS_PER_US;  // max STM32F40x freq by default

uint32_t dwt_init(void)
{
	uint32_t c;

    /* Calculate ticks per us factor */
    ticksPerUs = (SystemCoreClock / 1000000);

    /* Enable TRC */
    CoreDebug->DEMCR &= ~0x01000000;
    CoreDebug->DEMCR |=  0x01000000;

    /* Enable counter */
    DWT->CTRL &= ~0x00000001;
    DWT->CTRL |=  0x00000001;

    /* Reset counter */
    DWT->CYCCNT = 0;

	/* Check if DWT has started */
	c = DWT->CYCCNT;

	/* 2 dummys */
	__ASM volatile ("NOP");
	__ASM volatile ("NOP");

	/* Return difference, if result is zero, DWT has not started */
	return (DWT->CYCCNT - c);
}

void stopwatch_start(stopwatch_t * stopwatch)
{
    stopwatch->start = DWT->CYCCNT;
}


uint32_t stopwatch_now_us(stopwatch_t * stopwatch)
{
    return (DWT->CYCCNT - stopwatch->start) / ticksPerUs;
}
