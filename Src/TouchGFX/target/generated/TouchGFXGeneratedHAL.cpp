/**
  ******************************************************************************
  * File Name          : TouchGFXGeneratedHAL.cpp
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

#include <TouchGFXGeneratedHAL.hpp>
#include "stm32f7xx.h"

void TouchGFXGeneratedHAL::initialize()
{
    HAL::initialize();

    registerEventListener(*(touchgfx::Application::getInstance()));

    // Partial framebuffers strategy
    setFrameBufferAllocator(&blockAllocator);
    setFrameRefreshStrategy(HAL::REFRESH_STRATEGY_PARTIAL_FRAMEBUFFER);

}

void TouchGFXGeneratedHAL::configureInterrupts()
{
}

void TouchGFXGeneratedHAL::enableInterrupts()
{
}

void TouchGFXGeneratedHAL::disableInterrupts()
{
}

void TouchGFXGeneratedHAL::enableLCDControllerInterrupt()
{
}

void TouchGFXGeneratedHAL::endFrame()
{
    // We must guard the next frame until we're done transferring all blocks over our display interface
    // through either a semaphore if user is running an OS or a simple variable if not

    while(isTransmittingData())
    { }
}

uint16_t* TouchGFXGeneratedHAL::getTFTFrameBuffer() const
{
    //getTFTFrameBuffer() not used for selected Frame Buffer Strategy
    return 0;
}

void TouchGFXGeneratedHAL::setTFTFrameBuffer(uint16_t* adr)
{
    //setTFTFrameBuffer() not used for selected display interface
}

void TouchGFXGeneratedHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    HAL::flushFrameBuffer(rect);

    // Once flushFrameBuffer() is called by the framework a block is already for transfer
    // Mark it ready for transfer and transmit it if user defined method isTransmittingData() does not return false
    // If data is not being transmitted, transfer the data with user defined method transmitFrameBufferBlock().
    frameBufferAllocator->markBlockReadyForTransfer();
    if (!isTransmittingData())
    {
        touchgfx::Rect r;
        const uint8_t* pixels = frameBufferAllocator->getBlockForTransfer(r);
        transmitFrameBufferBlock((uint8_t*)pixels, r.x, r.y, r.width, r.height);
    }
}

/* ******************************************************
 * Functions required by Partial Frame Buffer Strategy
 * ******************************************************
 *
 *  *  uint8_t isTransmittingData() must return whether or not data is currently being transmitted, over e.g. SPI.
 *  *  void transmitFrameBufferBlock(uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h) will be called
 *       when the framework wants to send a block. The user must then transfer
 *       the data represented by the arguments.
 *
 *  A user must call touchgfx::startNewTransfer(); once transmitFrameBufferBlock() has succesfully sent a block.
 *  E.g. if using DMA to transfer the block, this could be called in the "Transfer Completed" interrupt handler.
 *
 */
extern "C" void transmitFrameBufferBlock(uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
extern "C" uint8_t isTransmittingData();

// Block Allocator for Partial Framebuffer strategy
ManyBlockAllocator<384000, /* block size */
                   2, /* number of blocks */
                   2  /* bytes per pixel */
                   > blockAllocator;

// Used by Partial Framebuffer strategy to indicate that a new block is ready for transfer.
static volatile bool readyForTransfer = false;

namespace touchgfx
{
/**
 * This functino is called by FrameBufferAllocator if no block is
 * available.
 */
void FrameBufferAllocatorWaitOnTransfer()
{
  while(!readyForTransfer);
}

/**
 * Called by FrameBufferAllocator when a block is drawn and
 * therefore ready for transfer. The LCD driver should use this
 * method to start a transfer.
 */
void FrameBufferAllocatorSignalBlockDrawn()
{
    readyForTransfer = false;
    return;
}

// A user must call touchgfx::startNewTransfer(); once transmitFrameBufferBlock() has succesfully sent a block.
void startNewTransfer()
{
    FrameBufferAllocator* fba = HAL::getInstance()->getFrameBufferAllocator();
    fba->freeBlockAfterTransfer();
    readyForTransfer = true;

    if (fba->hasBlockReadyForTransfer())
    {
        touchgfx::Rect r;
        const uint8_t* pixels = fba->getBlockForTransfer(r);
        transmitFrameBufferBlock((uint8_t*)pixels, r.x, r.y, r.width, r.height);
    }
}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
