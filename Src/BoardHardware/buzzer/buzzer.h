/*
 * buzzer.h
 *
 *  Created on: Apr 27, 2020
 *      Author: Jovan
 */

#ifndef BUZZER_H
#define BUZZER_H

#include "stm32f7xx_hal.h"

#define BUZZER_PORT		GPIOD
#define BUZZER_PIN		GPIO_PIN_4

#define SET_BUZZER     BUZZER_PORT->BSRR = BUZZER_PIN
#define CLR_BUZZER     BUZZER_PORT->BSRR = (uint32_t)BUZZER_PIN << 16

#define TONE_C 		76
#define TONE_C_ 	72
#define TONE_D 		68
#define TONE_D_ 	64
#define TONE_E 		61
#define TONE_F	 	57
#define TONE_F_ 	54
#define TONE_G	 	51
#define TONE_G_ 	48
#define TONE_A 		45
#define TONE_A_ 	43
#define TONE_H	 	41
#define TONE_Ch	 	38

void BUZZER_Stop(void);
void BUZZER_Start(void);
void BUZZER_SetTimerCounterPeriod(uint16_t value);	//1us timer
void BUZZER_SetTimerComparePeriod(uint16_t value);
void BUZZER_Exec(void);

#endif /* BUZZER_H_ */
