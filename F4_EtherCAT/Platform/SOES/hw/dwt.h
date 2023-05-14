#ifndef __DWT_H__
#define __DWT_H__

#include "stm32f4xx.h"

#define MAX_FREQ_TICKS_PER_US   160

typedef struct stopwatch_t
{
    uint32_t start;
} stopwatch_t;

uint32_t dwt_init(void);

// works with 1 tick resolution for up to 25.5 seconds measurements at 168 MHz
void stopwatch_start(stopwatch_t *);

uint32_t stopwatch_now_us(stopwatch_t *);


#endif // __DELAY_H__
