/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
extern "C" {
#include "TargetDisplay.h"
}

void STM32TouchController::init()
{
	TOUCH_Init();
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
	if(TOUCH_IsPressed())	//can be omitted -> controller continuously read touch data via i2c
	{
		TOUCH_Reset();		//can be omitted
		TOUCH_Data td=TOUCH_GetData();
		if(td.p>TP_MIN_PRESSURE)
		{
			x=td.x;
			y=td.y;
			return true;
		}
	}
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
