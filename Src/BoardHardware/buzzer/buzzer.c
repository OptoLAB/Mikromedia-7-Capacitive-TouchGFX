/*
 * buzzer.c
 *
 *  Created on: Apr 27, 2020
 *      Author: Jovan
 */

#include "buzzer.h"

static uint8_t buzzer_state=0;
static uint16_t buzzer_period=0;
static uint16_t buzzer_compare_period=0;
static uint16_t buzzer_counter=0;

void BUZZER_SetTimerCounterPeriod(uint16_t value)	//1us timer
{
	buzzer_period=value;
}

void BUZZER_SetTimerComparePeriod(uint16_t value)
{
	buzzer_compare_period=value;
}
void BUZZER_Stop(void)
{
	buzzer_state=0;
}
void BUZZER_Start(void)
{
	buzzer_counter=0;
	buzzer_state=1;
}
void BUZZER_Exec(void)
{
	if(buzzer_state)
	{
		if(buzzer_counter==0)CLR_BUZZER;
		if(buzzer_counter==buzzer_compare_period) SET_BUZZER;

		buzzer_counter++;
		if(buzzer_counter>=buzzer_period) buzzer_counter=0;
	}
}








