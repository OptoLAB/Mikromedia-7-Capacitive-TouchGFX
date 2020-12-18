/*
 * CC3100.c
 *
 *  Created on: Dec 6, 2020
 *      Author: Jovan
 */




/*
 * cli_uart.c - CC3100-STM32F4 console UART implementation
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "usbd_cdc_if.h"
#include "stm32f7xx_hal.h"
#include "simplelink//include//simplelink.h"

#define ASCII_ENTER     0x0D

__IO uint8_t ReceBuf1[BuffSize];
__IO uint8_t ReceBuf2[BuffSize];
__IO uint8_t Count1_in = 0;
__IO uint8_t Count2_in = 0;

char Buff[256];
char Temp[512];

#include "stm32f7xx_hal.h"
#include "CC3100.h"

#define RTC_ASYNCH_PREDIV   0x7F
#define RTC_SYNCH_PREDIV    0x0130
#define PULSE1_VALUE        60000       /* 1s  */

P_EVENT_HANDLER     pIrqEventHandler = 0;
unsigned long g_ulTimerInts = 0;

static SPI_HandleTypeDef hspi;
static TIM_HandleTypeDef htim;
static IRQn_Type IRQn;


// This function inits the device
void CC3100_Init(SPI_HandleTypeDef spi_handle, TIM_HandleTypeDef timer_handle, IRQn_Type irq_line)
{
	hspi=spi_handle;
	htim=timer_handle;
	IRQn=irq_line;

	CLR_WIFI_RST;
    Delay( 3 );
    SET_WIFI_RST;
    Delay( 1500 );
}

// This function disables CC3100 device
void CC3100_Disable()
{
	CLR_WIFI_nHIB;
}

// This function enables CC3100 device
void CC3100_Enable()
{
	SET_WIFI_nHIB;
}

// This function enables IrQ pin
void CC3100_InterruptEnable()
{
	//CC3100_EnableEXTILine(TRUE);
}

// This function disables IrQ pin
void CC3100_InterruptDisable()
{
	//CC3100_EnableEXTILine(FALSE);
}

// EXTI Line in interrupt mode
void CC3100_EnableEXTILine(uint8_t en)
{
    if (TRUE == en)
    {
        // Initialization via Cube
        HAL_NVIC_EnableIRQ(IRQn);
    }
    else if(FALSE == en)
    {
        HAL_NVIC_DisableIRQ(IRQn);
    }
}

// Register interrupt handler
int CC3100_RegisterInterruptHandler(P_EVENT_HANDLER InterruptHdl , void* pValue)
{
    pIrqEventHandler = InterruptHdl;
    return 0;
}

// Get interrupt handler
P_EVENT_HANDLER CC3100_GetInterruptHandler(void)
{
    return pIrqEventHandler;
}

// Reset interrupt handler
void CC3100_ResetInterruptHandler(void)
{
	pIrqEventHandler(0);
}

// Start timer
void CC3100_StartTimer()
{
    //Start TIM Base
    HAL_TIM_Base_Start(&htim);
}

// Returns the time stamp value for the SL host driver, should not be used by the application
unsigned long CC3100_GetCurrentTimestamp()
{
    unsigned long timer_value = 0;

    //Verify timer has been started by checking that the control register was set
    if((TIM_CR1_CEN) != (((&htim)->Instance->CR1) & (TIM_CR1_CEN)))
    {
    	CC3100_StartTimer();
    }

    timer_value = __HAL_TIM_GET_COUNTER(&htim);
    return timer_value;
}

// Open spi communication port to be used for communicating with a SimpleLink device
Fd_t CC3100_SpiOpen(char *ifName, unsigned long flags)
{
	// Cube handles spi initializtion
	//SpiHandle=hspi3;

    // Set SPI CS
    SET_WIFI_CS;

    // Enable interrupt pin of CC3100
    // Cube handles EXTI initialization
    CC3100_InterruptEnable();

    // disable the nHIB line
    CC3100_Disable();

    Delay(50);
    return 0;
}

// Closes an opened spi communication port
int CC3100_SpiClose(Fd_t fd)
{
    // Disable Interrupt pin of CC3100
	// Cube handles EXTI initialization
    CC3100_InterruptDisable();

    // Deinitialize SPI
    // Cube handles SPI initialization

    return 0;
}

// Attempts to write up to len bytes to the SPI channel
int CC3100_SpiWrite(Fd_t fd, unsigned char *pBuff, int len)
{
	CLR_WIFI_CS;
    HAL_SPI_Transmit(&hspi, pBuff, len, WIFI_TIMEOUT_MAX);
    SET_WIFI_CS;

    return len;
}

// Attempts to read up to len bytes from SPI channel into a buffer starting at pBuff.
int CC3100_SpiRead(Fd_t fd, unsigned char *pBuff, int len)
{
	CLR_WIFI_CS;
    HAL_SPI_Receive(&hspi, pBuff, len, WIFI_TIMEOUT_MAX);
    SET_WIFI_CS;

    return len;
}


//command line (UART/CDC) interface configure
void CLI_Configure(void)
{
	//Initialize via Cube
}

//command line (UART/CDC) write data
void CLI_Write(unsigned char *pcFormat, ...)
{
    char *pcBuff = &Buff[0];
    char *pcTemp = &Temp[0];

    int iSize = 256;
    int iRet;

    memset(pcBuff, 0, 252);
    memset(pcTemp, 0, 512);

    va_list list;
    while(1)
    {
        va_start(list,pcFormat);
        iRet = vsnprintf(pcBuff,iSize,(char const *)pcFormat,list);
        va_end(list);
        if(iRet > -1 && iRet < iSize)
        {
          	while(CDC_Transmit_FS((uint8_t*)pcBuff, strlen((const char *)pcBuff))!=USBD_OK);
            break;
        }
        else
        {
            iSize*=2;
            pcBuff=pcTemp;
        }
    }
}

//command line (UART/CDC) read data
int CLI_Read(unsigned char *pBuff)
{
	// Not implemented
    return 0;
}

//command line (UART/CDC) write file
int fputc(int ch, FILE *f)
{
	// Not implemented
    return 0;
}



// Induce delay in ms
void Delay(unsigned long delay)
{
    HAL_Delay(delay);
}






