/*
 * SST26VF064B.c
 *
 *  Created on: Apr 20, 2020
 *      Author: Jovan
 */

#include "SST26VF064B.h"

//  Read status register macros
#define FLASH_BUSY              (SST26VF064B_GetStatus()&0x01)
#define FLASH_WEL               (SST26VF064B_GetStatus()&0x02)
#define FLASH_WSE               (SST26VF064B_GetStatus()&0x04)
#define FLASH_WSP               (SST26VF064B_GetStatus()&0x08)
#define FLASH_WPLD              (SST26VF064B_GetStatus()&0x10)

//  Timeout macros. Use it to configure watchdog.
#define SECTOR_ERASE_TIMEOUT            10000
#define BLOCK_ERASE_TIMEOUT             4000
#define CHIP_ERASE_TIMEOUT              2000
#define PAGE_WRITE_TIMEOUT              2000
#define FLASH_INIT_TIMEOUT              2000


static SPI_HandleTypeDef 	hspi;

static int flash_address_parse( uint32_t address, uint8_t * addr_array )
{
    if ((address<START_PAGE_ADDRESS)||(address>END_PAGE_ADDRESS)) return FLASH_ERROR;

    addr_array[0]=(uint8_t)((address&0x00FF0000)>>16);
    addr_array[1]=(uint8_t)((address&0x0000FF00)>>8);
    addr_array[2]=(uint8_t) (address&0x000000FF);

    return FLASH_OK;
}

static int flash_wait(uint32_t timeout)
{
    uint32_t cnt = 0;

    while (FLASH_BUSY)
    {
        HAL_Delay(1);

        cnt++;
        if(cnt>timeout) return FLASH_ERROR;
    }

    return FLASH_OK;
}



void SST26VF064B_WriteInstruction(uint8_t instruction)
{
	FLASH_CE_LOW;
	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&hspi, &instruction, 1, SST26VF064B_TIMEOUT);
	FLASH_CE_HIGH;
}


void SST26VF064B_SetConfig (uint8_t config)
{
    uint8_t data[3];

    data[0] = SST26VF064B_FLASH_WRSR;
    data[1] = 0;
    data[2] = config;

    SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);

    FLASH_CE_LOW;
	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&hspi, data, 3, SST26VF064B_TIMEOUT);
	FLASH_CE_HIGH;
}


uint8_t SST26VF064B_GetConfig(void)
{
	uint8_t w_data, r_data;
	w_data=SST26VF064B_FLASH_RDCR;

	FLASH_CE_LOW;
	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&hspi, &w_data, 1, SST26VF064B_TIMEOUT);
	while(__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_RXNE));
	HAL_SPI_Receive(&hspi, &r_data, 1, SST26VF064B_TIMEOUT);
	FLASH_CE_HIGH;

	return r_data;
}


uint8_t SST26VF064B_GetStatus(void)
{
	uint8_t w_data, r_data;
	w_data=SST26VF064B_FLASH_RDSR;

	FLASH_CE_LOW;
	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&hspi, &w_data, 1, SST26VF064B_TIMEOUT);
	while(__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_RXNE));
	HAL_SPI_Receive(&hspi, &r_data, 1, SST26VF064B_TIMEOUT);
	FLASH_CE_HIGH;

	return r_data;
}

FLASH_state SST26VF064B_Init(SPI_HandleTypeDef 	spi_handle)
{
	FLASH_state state;

	hspi=spi_handle;

	FLASH_CE_HIGH;
	HAL_Delay(10);

	SST26VF064B_WriteInstruction(SST26VF064B_FLASH_RSTEN);
	SST26VF064B_WriteInstruction(SST26VF064B_FLASH_RST);
	SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);
	SST26VF064B_WriteInstruction(SST26VF064B_FLASH_ULBPR);

	state=flash_wait(FLASH_INIT_TIMEOUT);

    return state;
}


FLASH_state SST26VF064B_SectorErase(uint32_t address)
{
    uint8_t     data[4];
    FLASH_state  state;

    data[0]=SST26VF064B_FLASH_SE;
    data[1]=0;
    data[2]=0;
    data[3]=0;

    state=flash_address_parse(address, &data[1]);
    if (state==FLASH_OK)
    {
        SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);

        FLASH_CE_LOW;
    	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
    	HAL_SPI_Transmit(&hspi, data, 4, SST26VF064B_TIMEOUT);
    	FLASH_CE_HIGH;

        state=flash_wait(SECTOR_ERASE_TIMEOUT);
    }

    return state;
}
FLASH_state SST26VF064B_BlockErase(uint32_t address)
{
    uint8_t     data[4];
    FLASH_state  state;

    data[0]=SST26VF064B_FLASH_BE;
    data[1]=0;
    data[2]=0;
    data[3]=0;

    state=flash_address_parse(address, &data[1]);
    if (state==FLASH_OK)
    {
        SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);

        FLASH_CE_LOW;
    	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
    	HAL_SPI_Transmit(&hspi, data, 4, SST26VF064B_TIMEOUT);
    	FLASH_CE_HIGH;

        state=flash_wait(BLOCK_ERASE_TIMEOUT);
    }

    return state;
}

FLASH_state SST26VF064B_ChipErase(void)
{
    FLASH_state  state;

    SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);
    SST26VF064B_WriteInstruction(SST26VF064B_FLASH_CE);

    state=flash_wait(CHIP_ERASE_TIMEOUT);

    return state;
}


FLASH_state SST26VF064B_Write (uint32_t address,uint8_t * data2write, uint8_t len)
{
    uint8_t     data[4];
    FLASH_state  state;

    data[0]=SST26VF064B_FLASH_PP;
    data[1]=0;
    data[2]=0;
    data[3]=0;

    state=flash_address_parse(address, &data[1]);
    if (state==FLASH_OK)
    {
    	SST26VF064B_WriteInstruction(SST26VF064B_FLASH_WREN);

    	FLASH_CE_LOW;
    	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
    	HAL_SPI_Transmit(&hspi, data, 4, SST26VF064B_TIMEOUT);
    	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
    	HAL_SPI_Transmit(&hspi, data2write, len, SST26VF064B_TIMEOUT);
    	FLASH_CE_HIGH;

        state=flash_wait(PAGE_WRITE_TIMEOUT);
    }

    return state;
}

FLASH_state SST26VF064B_Read(uint32_t address, uint8_t *read_data, uint8_t len)
{
    uint8_t     data[4];
    FLASH_state  state;

    data[0]=SST26VF064B_FLASH_READ;
    data[1]=0;
    data[2]=0;
    data[3]=0;

    state=flash_address_parse(address, &data[1]);
    if (state==FLASH_OK)
    {
    	FLASH_CE_LOW;
    	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
    	HAL_SPI_Transmit(&hspi, data, 4, SST26VF064B_TIMEOUT);
    	while(__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_RXNE));
    	HAL_SPI_Receive(&hspi, read_data, len, SST26VF064B_TIMEOUT);
    	FLASH_CE_HIGH;
    }

    return state;
}

