/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
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
#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */
#include <touchgfx/hal/OSWrappers.hpp>
#include "stm32f7xx.h"
extern "C" {
#include "TargetDisplay.h"
}

using namespace touchgfx;


void TouchGFXHAL::initialize()
{
	DISP_Init();
}


uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    return 0;
}

void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
}


void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    frameBufferAllocator->markBlockReadyForTransfer();
   // if (!DISP_IsTransmittingData())
  //  {
      touchgfx::Rect r;
      const uint8_t* pixels = frameBufferAllocator->getBlockForTransfer(r);
      DISP_TransmitData((uint8_t*)pixels, r.x, r.y, r.width, r.height);
  //  }
}


void TouchGFXHAL::configureInterrupts()
{
}

void TouchGFXHAL::enableInterrupts()
{
}

void TouchGFXHAL::disableInterrupts()
{
}


void TouchGFXHAL::enableLCDControllerInterrupt()
{
}

void TouchGFXHAL::endFrame()
{
    while(DISP_IsTransmittingData())
    {
    }
}

bool TouchGFXHAL::blockCopy(void* RESTRICT dest, const void* RESTRICT src, uint32_t numBytes)
{
	if(src>=(void*)SPI_FLASH_START_ADDR && src<(void*)SPI_FLASH_STOP_ADDR)
	{
		FLASH_copyData((uint32_t)src, (uint8_t *)dest, numBytes,  128);

		return true;
	}
	else
	{
		return HAL::blockCopy(dest, src, numBytes);
	}
}

static volatile bool blockIsTransferred = false;

namespace touchgfx
{
	void FrameBufferAllocatorWaitOnTransfer()
	{
	  while(!blockIsTransferred);
	}

	void FrameBufferAllocatorSignalBlockDrawn()
	{
		blockIsTransferred = false;
		return;
	}

	void startNewTransfer()
	{
		FrameBufferAllocator* fba = HAL::getInstance()->getFrameBufferAllocator();
		fba->freeBlockAfterTransfer();
		blockIsTransferred = true;

		if (fba->hasBlockReadyForTransfer())
		{
			touchgfx::Rect r;
			const uint8_t* pixels = fba->getBlockForTransfer(r);
			DISP_TransmitData((uint8_t*)pixels, r.x, r.y, r.width, r.height);
		}
	}
}

void touchgfx_signalTransmitComplete()
{
    touchgfx::startNewTransfer();
}

void touchgfx_signalVSync(void)
{
    HAL::getInstance()->vSync();
    touchgfx::OSWrappers::signalVSync();
}

/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
