/*
 * pwr.h
 *
 *  Created on: Apr 24, 2020
 *      Author: Jovan
 */

#ifndef PWR_H
#define PWR_H

#include "stm32f7xx_hal.h"

#define PWR_DC_DETECT_PORT				GPIOE
#define PWR_DC_DETECT_PIN				GPIO_PIN_12  //low when external DC present
#define PWR_PS_STAT_PORT				GPIOH
#define PWR_PS_STAT_PIN					GPIO_PIN_9	//high when charging
#define PWR_BAT_ADC_CHANNEL				ADC_CHANNEL_10
#define PWR_BAT_SAMPLETIME				ADC_SAMPLETIME_480CYCLES
#define PWR_BAT_AVG_SAMPLES				255
#define PWR_BAT_V_DIVIDER_RATIO_x10		2.1f
#define PWR_VREF_mV						2048
#define PWR_RESOLUTION					4096


void PWR_Init(ADC_HandleTypeDef adc_handle);
uint16_t PWR_ReadADC(uint32_t ch, uint32_t sample_time, uint8_t n_times);
void PWR_GetBatteryVoltage(int16_t *bat_dp_front, uint16_t *bat_dp_back);

uint8_t PWR_GetDCDetect(void);
uint8_t PWR_GetPSStat(void);

#endif /* POWER_PWR_H_ */
