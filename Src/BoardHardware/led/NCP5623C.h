/*
 * NCP5623C.h
 *
 *  Created on: Apr 15, 2020
 *      Author: Jovan
 */

#ifndef NCP5623C_H
#define NCP5623C_H

#include "stm32f7xx_hal.h"

#define NCP5623C_ADDR           (0x39<<1)
#define NCP5623C_PWR     		0x20
#define NCP5623C_RED        	0x80
#define NCP5623C_GREEN      	0x60
#define NCP5623C_BLUE       	0x40

#define R_LED 0
#define G_LED 1
#define B_LED 2

#define NCP5623C_TIMEOUT		1000

void NCP5623C_Init (I2C_HandleTypeDef i2c_handle);
void NCP5623C_SetPower(uint8_t power);
void NCP5623C_SetLED(uint8_t led, uint8_t value);

#endif /* NCP5623C_H_ */
