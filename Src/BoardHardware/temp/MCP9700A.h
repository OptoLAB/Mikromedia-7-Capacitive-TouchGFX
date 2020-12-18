/*
 * temp.h
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */

#ifndef MCP9700A_H
#define MCP9700A_H

#include "stm32f7xx_hal.h"

#define MCP9700A_ADC_CHANNEL	ADC_CHANNEL_15
#define MCP9700A_SAMPLETIME		ADC_SAMPLETIME_480CYCLES
#define MCP9700A_AVG_SAMPLES	100
#define MCP9700A_VREF_mV		2048
#define MCP9700A_RESOLUTION		4096
#define MCP9700A_OFFSET_mV		500		//Voffset=500 mV
#define MCP9700A_OFFSET_T		0		//at 0 degree celsius
#define MCP9700A_INV_SLOPE_mV	100		//Slope=10 mV/T

void MCP9700A_Init(ADC_HandleTypeDef adc_handle);
uint16_t MCP9700A_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times);
void MCP9700A_GetTemperature(int16_t *temp_dp_front, uint16_t *temp_dp_back);

#endif /* TEMP_MCP9700A_H_ */
