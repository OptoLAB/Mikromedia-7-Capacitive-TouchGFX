/*
 * LTR329ALS.h
 *
 *  Created on: Apr 16, 2020
 *      Author: Jovan
 */

#ifndef LTR329ALS_H
#define LTR329ALS_H

#include "stm32f7xx_hal.h"

#define LTR329ALS_ADDR			(0x29<<1)

#define LTR329ALS_CONTR			0x80	// ALS operation mode control SW reset
#define LTR329ALS_MEAS			0x85	// ALS measurement rate in active mode
#define LTR329ALS_PART_ID		0x86	// Part number ID and revision ID
#define LTR329ALS_MANUFAC_ID	0x87	// Manufacturer ID
#define LTR329ALS_DATA_CH1_L	0x88	// ALS measurement CH1 data, lower byte
#define LTR329ALS_DATA_CH1_H	0x89	// ALS measurement CH1 data, upper byte
#define LTR329ALS_DATA_CH0_L	0x8A	// ALS measurement CH0 data, lower byte
#define LTR329ALS_DATA_CH0_H	0x8B	// ALS measurement CH0 data, upper byte
#define LTR329ALS_STATUS		0x8C	// ALS data status

#define LTR329ALS_MODE_ACT		(0x01)
#define LTR329ALS_MODE_STBY		(0x00)
#define LTR329ALS_MODE_RST		(~(0x01))

#define LTR329ALS_SOFT_RST		(0x01<<1)

#define LTR329ALS_GAIN_x1		(0x00<<2)
#define LTR329ALS_GAIN_x2		(0x01<<2)
#define LTR329ALS_GAIN_x4		(0x02<<2)
#define LTR329ALS_GAIN_x8		(0x03<<2)
#define LTR329ALS_GAIN_x48		(0x06<<2)
#define LTR329ALS_GAIN_x96		(0x07<<2)
#define LTR329ALS_GAIN_RST		(~(0x07<<2))

#define LTR329ALS_INT_50ms		(0x01<<3)
#define LTR329ALS_INT_100ms		(0x00<<3)	//default
#define LTR329ALS_INT_150ms		(0x04<<3)
#define LTR329ALS_INT_200ms		(0x02<<3)
#define LTR329ALS_INT_250ms		(0x05<<3)
#define LTR329ALS_INT_300ms		(0x06<<3)
#define LTR329ALS_INT_350ms		(0x07<<3)
#define LTR329ALS_INT_400ms		(0x03<<3)
#define LTR329ALS_INT_RST		(~(0x07<<3))

//LTR329ALS_INT<=LTR329ALS_MEAS

#define LTR329ALS_MEAS_50ms		(0x00)
#define LTR329ALS_MEAS_100ms	(0x01)
#define LTR329ALS_MEAS_200ms	(0x02)
#define LTR329ALS_MEAS_500ms	(0x03)		//default
#define LTR329ALS_MEAS_1000ms	(0x04)
#define LTR329ALS_MEAS_2000ms	(0x05)		//0x06//0x07
#define LTR329ALS_MEAS_RST		(~(0x07))

#define LTR329ALS_TIMEOUT       1000

uint8_t LTR329ALS_Init(I2C_HandleTypeDef i2c_handle);
void LTR329ALS_Write(uint8_t reg_addr, uint8_t byte_2_write);
uint8_t LTR329ALS_Read(uint8_t reg_addr);
void LTR329ALS_ReadMultiple(uint8_t reg_addr, uint8_t *buff, uint8_t num_of_bytes);
void LTR329ALS_SetMode(uint8_t mode);
void LTR329ALS_SoftReset(void);
void LTR329ALS_SetGain(uint8_t gain);
void LTR329ALS_SetIntegrationTime(uint8_t int_time);
void LTR329ALS_SetMeasurementTime(uint8_t meas_time);
void LTR329ALS_GetMeasurements(uint16_t *ch0, uint16_t *ch1);

#endif /* LTR329ALS_H_ */
