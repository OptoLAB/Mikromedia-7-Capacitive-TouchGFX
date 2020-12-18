/*
 * NCP5623C.c
 *
 *  Created on: Apr 15, 2020
 *      Author: Jovan
 */
#include "NCP5623C.h"

static I2C_HandleTypeDef hi2c;



void NCP5623C_Init (I2C_HandleTypeDef i2c_handle)
{
	hi2c=i2c_handle;

	if(HAL_I2C_IsDeviceReady(&hi2c,NCP5623C_ADDR, 5, NCP5623C_TIMEOUT) == HAL_OK )
	{
		NCP5623C_SetPower(0x1F);
		NCP5623C_SetLED(R_LED, 0);
		NCP5623C_SetLED(G_LED, 0);
		NCP5623C_SetLED(B_LED, 0);
	}
}
void NCP5623C_SetPower(uint8_t power)
{
	uint8_t byte2write;

	byte2write=NCP5623C_PWR|(power&0x1F);

	HAL_I2C_Master_Transmit(&hi2c, NCP5623C_ADDR, &byte2write, 1, NCP5623C_TIMEOUT);
}

void NCP5623C_SetLED(uint8_t led, uint8_t value)
{
	uint8_t byte_2_write;

	switch (led)
	{
		case R_LED: byte_2_write=NCP5623C_RED|(value&0x1F);
			break;
		case G_LED: byte_2_write=NCP5623C_GREEN|(value&0x1F);
			break;
		case B_LED: byte_2_write=NCP5623C_BLUE|(value&0x1F);
			break;
	}
	HAL_I2C_Master_Transmit(&hi2c, NCP5623C_ADDR, &byte_2_write, 1, NCP5623C_TIMEOUT);
}

