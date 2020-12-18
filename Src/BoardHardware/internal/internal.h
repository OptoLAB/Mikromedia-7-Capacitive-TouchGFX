/*
 * internal.h
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */

#ifndef INTERNAL_H
#define INTERNAL_H

#include "stm32f7xx_hal.h"

#define INTERNAL_TEMP_ADC_CHANNEL		ADC_CHANNEL_TEMPSENSOR
#define INTERNAL_TEMP_SAMPLETIME		ADC_SAMPLETIME_480CYCLES
#define INTERNAL_TEMP_AVG_SAMPLES		100
#define INTERNAL_VREF_mV				2048
#define INTERNAL_RESOLUTION				4096
#define INTERNAL_TEMP_OFFSET_mV			760		//Voffset=760 mV
#define INTERNAL_TEMP_OFFSET_T			25		//at 25 degree celsius
#define INTERNAL_TEMP_INV_SLOPE_mV		400		//Slope=2.5 mV/T
#define INTERNAL_DATE_TIME_FORMAT		RTC_FORMAT_BIN

typedef struct{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}RTC_time;

typedef struct{
	uint8_t days;
	uint8_t months;
	uint8_t years;
	uint8_t weekDay;
}RTC_date;


void INTERNAL_Init(ADC_HandleTypeDef adc_handle, RTC_HandleTypeDef rtc_hanle);
uint16_t INTERNAL_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times);
void INTERNAL_GetTemperature(int16_t *temp_dp_front, uint16_t *temp_dp_back);
RTC_time INTERNAL_GetTime(void);
void INTERNAL_SetTime(RTC_time time);
RTC_date INTERNAL_GetDate(void);
void INTERNAL_SetDate(RTC_date date);

#endif /* INTERNAL_INTERNAL_H_ */
