/*
 * internal.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */
#include "internal.h"

static ADC_HandleTypeDef hadc;
static RTC_HandleTypeDef htd;

void INTERNAL_Init(ADC_HandleTypeDef adc_handle, RTC_HandleTypeDef rtc_hanle)
{
	hadc=adc_handle;
	htd=rtc_hanle;
}

uint16_t INTERNAL_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times)
{
	  ADC_ChannelConfTypeDef sConfig = {0};
	  uint32_t adc_value=0;

	  sConfig.Channel = ch;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = sample_time;

	  HAL_ADC_ConfigChannel(&hadc, &sConfig);

	  for(int i=0; i<n_times;i++)
	  {
		  HAL_ADC_Start(&hadc);
		  HAL_ADC_PollForConversion(&hadc,1000);
		  adc_value+=HAL_ADC_GetValue(&hadc);
		  HAL_ADC_Stop(&hadc);
	  }
	  adc_value/=n_times;

	  return (uint16_t) adc_value;
}

void INTERNAL_GetTemperature(int16_t *int_temp_dp_front, uint16_t *int_temp_dp_back)
{
	int32_t adc_value=INTERNAL_ReadADC(INTERNAL_TEMP_ADC_CHANNEL, INTERNAL_TEMP_SAMPLETIME, INTERNAL_TEMP_AVG_SAMPLES);

	 adc_value=(adc_value*INTERNAL_VREF_mV)/INTERNAL_RESOLUTION;
	 adc_value-=INTERNAL_TEMP_OFFSET_mV;
	 adc_value*=INTERNAL_TEMP_INV_SLOPE_mV;

	 *int_temp_dp_front=(int16_t)(adc_value/1000)+INTERNAL_TEMP_OFFSET_T;
	 *int_temp_dp_back=(uint16_t)(adc_value%1000);
}

RTC_time INTERNAL_GetTime(void)
{
	RTC_TimeTypeDef ht;
	RTC_time time;

	HAL_RTC_GetTime(&htd, &ht, INTERNAL_DATE_TIME_FORMAT);

	time.hours=ht.Hours;
	time.minutes=ht.Minutes;
	time.seconds=ht.Seconds;

	return time;
}

void INTERNAL_SetTime(RTC_time time)
{
	RTC_TimeTypeDef ht;

	ht.Hours=time.hours;
	ht.Minutes=time.minutes;
	ht.Seconds=time.seconds;
	ht.DayLightSaving=0; //none
	ht.StoreOperation=0; //reset

	HAL_RTC_SetTime(&htd, &ht, INTERNAL_DATE_TIME_FORMAT);
}

RTC_date INTERNAL_GetDate(void)
{
	RTC_DateTypeDef hd;
	RTC_date date;

	HAL_RTC_GetDate(&htd, &hd, INTERNAL_DATE_TIME_FORMAT);

	date.days=hd.Date;
	date.months=hd.Month;
	date.years=hd.Year;
	date.weekDay=hd.WeekDay;

	return date;
}

void INTERNAL_SetDate(RTC_date date)
{
	RTC_DateTypeDef hd;

	hd.Date=date.days;
	hd.Month=date.months;
	hd.Year=date.years;
	hd.WeekDay=date.weekDay;

	HAL_RTC_SetDate(&htd, &hd, INTERNAL_DATE_TIME_FORMAT);
}

