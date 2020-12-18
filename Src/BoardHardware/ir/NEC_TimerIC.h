/*
 *   Author: Jovan
 */

#ifndef NEC_TIMERIC_H
#define NEC_TIMERIC_H

#include <stdint.h>
#include "stm32f7xx_hal.h"


void NEC_Init(TIM_HandleTypeDef htim,  uint32_t ch);
void NEC_StartCapture(void);
void NEC_StopCapture(void);
uint8_t NEC_Capture(void);
void NEC_Decode(void);
uint8_t NEC_GetCommand(void);
uint8_t NEC_GetAddress(void);
uint8_t NEC_GetStatus(void);
void NEC_ClearStatus(void);

#endif /* NEC_TIMERIC_H */
