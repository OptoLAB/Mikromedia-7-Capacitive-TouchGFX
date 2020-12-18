/*
 * CC3100.h
 *
 *  Created on: Dec 6, 2020
 *      Author: Jovan
 */

#ifndef CC3100_H
#define CC3100_H

#include "stm32f7xx_hal.h"

#include <stdio.h>
#include <string.h>

//CC3100 port
#define WIFI_INT_PORT		GPIOJ
#define WIFI_INT_PIN		GPIO_PIN_9
#define WIFI_nHIB_PORT		GPIOI
#define WIFI_nHIB_PIN		GPIO_PIN_0
#define WIFI_CS_PORT		GPIOJ
#define WIFI_CS_PIN			GPIO_PIN_10
#define WIFI_RST_PORT		GPIOC
#define WIFI_RST_PIN		GPIO_PIN_9

//#define WIFI_MOSI_PORT   gpioPortC
//#define WIFI_MOSI_PIN    12
//#define WIFI_MISO_PORT   gpioPortC
//#define WIFI_MISO_PIN    11
//#define WIFI_CLK_PORT    gpioPortC
//#define WIFI_CLK_PIN     10

#define SET_WIFI_CS			WIFI_CS_PORT->BSRR = WIFI_CS_PIN
#define CLR_WIFI_CS 		WIFI_CS_PORT->BSRR = (uint32_t)WIFI_CS_PIN << 16
#define SET_WIFI_nHIB		WIFI_nHIB_PORT->BSRR = WIFI_nHIB_PIN
#define CLR_WIFI_nHIB		WIFI_nHIB_PORT->BSRR = (uint32_t)WIFI_nHIB_PIN << 16
#define SET_WIFI_RST		WIFI_RST_PORT->BSRR = WIFI_RST_PIN
#define CLR_WIFI_RST		WIFI_RST_PORT->BSRR = (uint32_t)WIFI_RST_PIN << 16

#define WIFI_TIMEOUT_MAX 0x1000

#define BuffSize    50

extern __IO uint8_t ReceBuf1[BuffSize]; // receive buffer
extern __IO uint8_t ReceBuf2[BuffSize]; // receive buffer
extern __IO uint8_t Count1_in;//
extern __IO uint8_t Count2_in;//

typedef unsigned int Fd_t;

typedef void (*P_EVENT_HANDLER)(void* pValue);

#define ACLOCK_FREQ                     108000000                       // set to 108 [MHz]
#define TIMER_PRESCALAR		        	54000                           // value between 0 and 0xFFFF
#define TIMER_CLK                       (ACLOCK_FREQ/TIMER_PRESCALAR)   // timer frequency [Hz] or ticks/sec

#define MILLISECONDS_TO_TICKS(ms)       ((TIMER_CLK * ms)/1000)         // input: number of ms, output: number of ticks at given timer frequency
#define TICKS_TO_MILLISECONDS(ticks)    ((ticks)/(TIMER_CLK/1000))      // input: number of ticks, output: number of ms at given timer frequency
#define MAX_TIMER_TICKS                 0xFFFF                          // timer max count value OR timer period

#define ENABLE 1
#define DISABLE 0

//Init
void CC3100_Init(SPI_HandleTypeDef spi_handle, TIM_HandleTypeDef timer_handle, IRQn_Type irq_line);
void CC3100_Enable(void);
void CC3100_Disable(void);
void CC3100_InterruptEnable(void);
void CC3100_InterruptDisable(void);
void CC3100_EnableEXTILine(uint8_t en);
//Timer
void CC3100_StartTimer();
unsigned long CC3100_GetCurrentTimestamp();
//Interrupt handler
int CC3100_RegisterInterruptHandler(P_EVENT_HANDLER InterruptHdl, void* pValue);
P_EVENT_HANDLER CC3100_GetInterruptHandler(void);
void CC3100_ResetInterruptHandler(void);
//SPI
Fd_t CC3100_SpiOpen(char *ifName, unsigned long flags);
int CC3100_SpiClose(Fd_t fd);
int CC3100_SpiWrite(Fd_t fd, unsigned char *pBuff, int len);
int CC3100_SpiRead(Fd_t fd, unsigned char *pBuff, int len);
//Command line interface
void CLI_Configure(void);
void CLI_Write(unsigned char *inBuff, ...);
int CLI_Read(unsigned char *pBuff);
int fputc(int ch, FILE *f);
// Delay function
void Delay(unsigned long delay);


#endif /* WIFI_CC3100_H_ */
