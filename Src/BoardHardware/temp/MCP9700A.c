/*
 * MCP9700A.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */
#include "MCP9700A.h"

static ADC_HandleTypeDef hadc;

void MCP9700A_Init(ADC_HandleTypeDef adc_handle)
{
	hadc=adc_handle;
}

uint16_t MCP9700A_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times)
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

void MCP9700A_GetTemperature(int16_t *temp_dp_front, uint16_t *temp_dp_back)
{
	int32_t adc_value=MCP9700A_ReadADC(MCP9700A_ADC_CHANNEL, MCP9700A_SAMPLETIME, MCP9700A_AVG_SAMPLES);

	 adc_value=(adc_value*MCP9700A_VREF_mV)/MCP9700A_RESOLUTION;
	 adc_value-=MCP9700A_OFFSET_mV;
	 adc_value*=MCP9700A_INV_SLOPE_mV;

	 *temp_dp_front=(int16_t)(adc_value/1000)+MCP9700A_OFFSET_T;
	 *temp_dp_back=(uint16_t)(adc_value%1000);

}
