/*
 * pwr.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */


#include "pwr.h"

static ADC_HandleTypeDef hadc;

void PWR_Init(ADC_HandleTypeDef adc_handle)
{
	hadc=adc_handle;
}

uint16_t PWR_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times)
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

void PWR_GetBatteryVoltage(int16_t *bat_dp_front, uint16_t *bat_dp_back)
{
	int32_t adc_value=PWR_ReadADC(PWR_BAT_ADC_CHANNEL,PWR_BAT_SAMPLETIME,PWR_BAT_AVG_SAMPLES);

	float x=(float)adc_value*PWR_VREF_mV/PWR_RESOLUTION;
	x*=PWR_BAT_V_DIVIDER_RATIO_x10;

	*bat_dp_front=(int16_t)((uint16_t)x/1000);
	*bat_dp_back=(uint16_t)((uint16_t)x%1000);
}

uint8_t PWR_GetDCDetect(void)
{
	if(HAL_GPIO_ReadPin(PWR_DC_DETECT_PORT,PWR_DC_DETECT_PIN)==GPIO_PIN_RESET)
		return 0;
	else
		return 1;
}

uint8_t PWR_GetPSStat(void)
{
	if(HAL_GPIO_ReadPin(PWR_PS_STAT_PORT,PWR_PS_STAT_PIN)==GPIO_PIN_RESET)
		return 0;
	else
		return 1;
}
