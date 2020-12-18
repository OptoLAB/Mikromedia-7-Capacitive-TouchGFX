/*
 * LTR329ALS.c
 *
 *  Created on: Apr 16, 2020
 *      Author: Jovan
 */

#include "LTR329ALS.h"

static I2C_HandleTypeDef hi2c;

uint8_t LTR329ALS_Init(I2C_HandleTypeDef i2c_handle)
{
	hi2c=i2c_handle;

	if(HAL_I2C_IsDeviceReady(&hi2c,LTR329ALS_ADDR, 5, LTR329ALS_TIMEOUT) == HAL_OK )
	{
		LTR329ALS_SetMode(LTR329ALS_MODE_ACT);
		LTR329ALS_SetGain(LTR329ALS_GAIN_x1);
	    LTR329ALS_SetIntegrationTime(LTR329ALS_INT_50ms);
		LTR329ALS_SetMeasurementTime(LTR329ALS_MEAS_500ms);
		return 1;
	}
	else
		return 0;
}

void LTR329ALS_Write(uint8_t reg_addr, uint8_t byte_2_write)
{
	uint8_t data[2];

    data[0] = reg_addr;
    data[1] = byte_2_write;

	HAL_I2C_Master_Transmit(&hi2c, LTR329ALS_ADDR, (uint8_t *)data, 2, LTR329ALS_TIMEOUT);
}

uint8_t LTR329ALS_Read(uint8_t reg_addr)
{
	uint8_t data;

	HAL_I2C_Mem_Read(&hi2c,LTR329ALS_ADDR, reg_addr,1,&data,1,LTR329ALS_TIMEOUT);

	return data;
}

void LTR329ALS_ReadMultiple(uint8_t reg_addr, uint8_t *buff, uint8_t num_of_bytes)
{
	HAL_I2C_Mem_Read(&hi2c,LTR329ALS_ADDR, reg_addr,1,buff,num_of_bytes,LTR329ALS_TIMEOUT);
}

void LTR329ALS_SetMode(uint8_t mode)
{
	uint8_t reg_data=LTR329ALS_Read(LTR329ALS_CONTR)&(LTR329ALS_MODE_RST);
	LTR329ALS_Write(LTR329ALS_CONTR,reg_data|mode);
}
void LTR329ALS_SoftReset(void)
{
	uint8_t reg_data=LTR329ALS_Read(LTR329ALS_CONTR)|(LTR329ALS_SOFT_RST);
	LTR329ALS_Write(LTR329ALS_CONTR,reg_data);
}
void LTR329ALS_SetGain(uint8_t gain)
{
	uint8_t reg_data=LTR329ALS_Read(LTR329ALS_CONTR)&(LTR329ALS_GAIN_RST);
	LTR329ALS_Write(LTR329ALS_CONTR,reg_data|gain);
}
void LTR329ALS_SetIntegrationTime(uint8_t int_time)
{
	uint8_t reg_data=LTR329ALS_Read(LTR329ALS_MEAS)&(LTR329ALS_INT_RST);
	LTR329ALS_Write(LTR329ALS_MEAS,reg_data|int_time);
}
void LTR329ALS_SetMeasurementTime(uint8_t meas_time)
{
	uint8_t reg_data=LTR329ALS_Read(LTR329ALS_MEAS)&(LTR329ALS_MEAS_RST);
	LTR329ALS_Write(LTR329ALS_MEAS,reg_data|meas_time);
}
void LTR329ALS_GetMeasurements(uint16_t *ch0, uint16_t *ch1)
{
	uint8_t buff[4];
	LTR329ALS_ReadMultiple(LTR329ALS_DATA_CH1_L, buff, 4);
	*ch1=(buff[1]<<8)|buff[0];
	*ch0=(buff[3]<<8)|buff[2];
}
