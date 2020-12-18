/*
 * FXOS8700CQ.c
 *
 *  Created on: Apr 18, 2020
 *      Author: Jovan
 */

#include "FXOS8700CQ.h"

static I2C_HandleTypeDef hi2c;

uint8_t FXOS8700CQ_Init(I2C_HandleTypeDef i2c_handle)
{
	hi2c=i2c_handle;

	if(HAL_I2C_IsDeviceReady(&hi2c,FXOS8700CQ_ADDR, 5, FXOS8700CQ_TIMEOUT) == HAL_OK )
	{
		FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,0x00);		// standby
		FXOS8700CQ_Write(FXOS8700CQ_M_CTRL_REG1,0x1F); 		// auto calibration disabled
															// no one-shot magnetic reset
															// no one-shot magnetic measurement
															// 8x oversampling (for 200Hz) to reduce magnetometer noise
															// hybrid mode with accel and magnetometer active
		FXOS8700CQ_Write(FXOS8700CQ_M_CTRL_REG2,0x20); 		// hybrid autoinc mode - to map the magnetometer registers to follow the accelerometer registers
															// retain default min/max latching even though not used
															// enable magnetic reset each cycle
		FXOS8700CQ_Write(FXOS8700CQ_XYZ_DATA_CFG,0x01);		// HP filter off, +/-4g range
		FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,0x0D);		// active mode
															// low noise
															// 200 Hz

		return 1;
	}
	else
		return 0;
}

//=============================================================================
void FXOS8700CQ_Write(uint8_t reg_addr, uint8_t byte_2_write)
{
	uint8_t data[2];

    data[0] = reg_addr;
    data[1] = byte_2_write;

	HAL_I2C_Master_Transmit(&hi2c, FXOS8700CQ_ADDR, (uint8_t *)data, 2, FXOS8700CQ_TIMEOUT);
}

uint8_t FXOS8700CQ_Read(uint8_t reg_addr)
{
	uint8_t data;

	HAL_I2C_Mem_Read(&hi2c,FXOS8700CQ_ADDR, reg_addr,1,&data,1,FXOS8700CQ_TIMEOUT);

	return data;
}

void FXOS8700CQ_ReadMultiple(uint8_t reg_addr, uint8_t *buff, uint8_t num_of_bytes)
{
	HAL_I2C_Mem_Read(&hi2c,FXOS8700CQ_ADDR, reg_addr,1,buff,num_of_bytes,FXOS8700CQ_TIMEOUT);
}

void FXOS8700CQ_AccelGetXYZ(int16_t *x, int16_t *y, int16_t *z)
{
	uint8_t data[6];
	FXOS8700CQ_ReadMultiple(FXOS8700CQ_OUT_X_MSB, data, 6);

	*x=((int16_t)((data[0]<<8)|data[1]))>>2;	//14 bit value;
	*y=((int16_t)((data[2]<<8)|data[3]))>>2;	//14 bit value;
	*z=((int16_t)((data[4]<<8)|data[5]))>>2;	//14 bit value;
}

void FXOS8700CQ_AccelSetRange(uint8_t range)
{
	uint8_t reg_ctrl=FXOS8700CQ_Read(FXOS8700CQ_CTRL_REG1); //backup ctrl reg
	FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,0x00);

	uint8_t reg_data=FXOS8700CQ_Read(FXOS8700CQ_XYZ_DATA_CFG)&FXOS8700CQ_RANGE_RST;
	FXOS8700CQ_Write(FXOS8700CQ_XYZ_DATA_CFG,reg_data|range);

	FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,reg_ctrl);	//return ctrl reg
}
void FXOS8700CQ_AccelSetHPFilter(uint8_t filter)
{
	uint8_t reg_ctrl=FXOS8700CQ_Read(FXOS8700CQ_CTRL_REG1); //backup ctrl reg
	FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,0x00);

	uint8_t reg_data=FXOS8700CQ_Read(FXOS8700CQ_XYZ_DATA_CFG)&FXOS8700CQ_HPF_RST;
	FXOS8700CQ_Write(FXOS8700CQ_XYZ_DATA_CFG,reg_data|filter);

	FXOS8700CQ_Write(FXOS8700CQ_CTRL_REG1,reg_ctrl);	//return ctrl reg
}
void FXOS8700CQ_MagnetometerGetXYZ(int16_t *x, int16_t *y, int16_t *z)
{
	uint8_t data[6];
	FXOS8700CQ_ReadMultiple(FXOS8700CQ_M_OUT_X_MSB, data, 6);

	*x=(int16_t)(((int16_t)(data[0]<<8)|data[1])>>2);	//14 bit value;
	*y=(int16_t)(((int16_t)(data[2]<<8)|data[3])>>2);	//14 bit value;
	*z=(int16_t)(((int16_t)(data[4]<<8)|data[5])>>2);	//14 bit value;
}
