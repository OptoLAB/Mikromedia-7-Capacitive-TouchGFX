/*
 * SST26VF064B.h
 *
 *  Created on: Apr 20, 2020
 *      Author: Jovan
 */
#include "stm32f7xx_hal.h"

#ifndef SST26VF064B_H
#define SST26VF064B_H

#define	FLASH_CE_PORT			GPIOH
#define FLASH_CE_PIN			GPIO_PIN_12

#define FLASH_CE_HIGH           FLASH_CE_PORT->BSRR = FLASH_CE_PIN
#define FLASH_CE_LOW            FLASH_CE_PORT->BSRR = (uint32_t)FLASH_CE_PIN << 16

#define SST26VF064B_TIMEOUT 1000

#define  SST26VF064B_FLASH_NOOP       0x00     // No operation
#define  SST26VF064B_FLASH_RSTEN      0x66     // Reset enable
#define  SST26VF064B_FLASH_RST        0x99     // Reset memory   (1)
#define  SST26VF064B_FLASH_EQIO       0x38     // Enable Quad I/O
#define  SST26VF064B_FLASH_RSTQIO     0xFF     // Reset Quad I/O    (2)
#define  SST26VF064B_FLASH_RDSR       0x05     // Read status register
#define  SST26VF064B_FLASH_WRSR       0x01     // Write status register
#define  SST26VF064B_FLASH_RDCR       0x35     // Read configuration register
#define  SST26VF064B_FLASH_READ       0x03     // Read memory
#define  SST26VF064B_FLASH_HREAD      0x0B     // Read memory at higher speed
#define  SST26VF064B_FLASH_SQOR       0x6B     // SPI Quad Output Read   (3)
#define  SST26VF064B_FLASH_SQIOR      0xEB     // SPI Quad I/O Read   (4)
#define  SST26VF064B_FLASH_SDOR       0x3B     // SPI Dual Output Read   (5)
#define  SST26VF064B_FLASH_SDIOR      0xBB     // SPI Dual I/O Read   (6)
#define  SST26VF064B_FLASH_SB         0xC0     // Set Burst Length
#define  SST26VF064B_FLASH_RBSQI      0x0C     // SQI Read Burst with Wrap
#define  SST26VF064B_FLASH_RBSPI      0xEC     // SPI Read Burst with Wrap   (4)
#define  SST26VF064B_FLASH_DUMMY_DATA 0x00     // Dummy data for reading
#define  SST26VF064B_FLASH_JEDECID    0x9F     // JEDEC-ID Read
#define  SST26VF064B_FLASH_QUADJID    0xAF     // Quad I/O J-ID Read
#define  SST26VF064B_FLASH_SFDP       0x5A     // Serial Flash Discoverable Parameters
#define  SST26VF064B_FLASH_WREN       0x06     // Write Enable
#define  SST26VF064B_FLASH_WRDI       0x04     // Write Disable
#define  SST26VF064B_FLASH_SE         0x20     // Erase 4 KBytes of Memory Array   (7)
#define  SST26VF064B_FLASH_BE         0xD8     // Erase 64, 32 or 8 KBytes of Memory Array   (8)
#define  SST26VF064B_FLASH_CE         0xC7     // Erase Full Array
#define  SST26VF064B_FLASH_PP         0x02     // Page Program
#define  SST26VF064B_FLASH_SPIQUADPP  0x32     // SQI Quad Page Program   (3)
#define  SST26VF064B_FLASH_WRSU       0xB0     // Suspends Program/Erase
#define  SST26VF064B_FLASH_WRRE       0x30     // Resumes Program/Erase
#define  SST26VF064B_FLASH_RBPR       0x72     // Read Block-Protection Register
#define  SST26VF064B_FLASH_WBPR       0x42     // Write Block-Protection Register
#define  SST26VF064B_FLASH_LBPR       0x8D     // Lock Down Block-Protection Register
#define  SST26VF064B_FLASH_NVWLDR     0xE8     // non-Volatile Write LockDown Register
#define  SST26VF064B_FLASH_ULBPR      0x98     // Global Block Protection Unlock
#define  SST26VF064B_FLASH_RSID       0x88     // Read Security ID
#define  SST26VF064B_FLASH_PSID       0xA5     // Program User Security ID area
#define  SST26VF064B_FLASH_LSID       0x85     // Lockout Security ID Programming

#define START_PAGE_ADDRESS               0x010000
#define END_PAGE_ADDRESS                 0x7FFFFF

typedef enum
{
    FLASH_OK                = 0,
    FLASH_ERROR             = 1
} FLASH_state;

void SST26VF064B_WriteInstruction(uint8_t instruction);
void SST26VF064B_SetConfig (uint8_t config);
uint8_t SST26VF064B_GetConfig(void);
uint8_t SST26VF064B_GetStatus(void);
FLASH_state SST26VF064B_Init(SPI_HandleTypeDef 	spi_handle);
FLASH_state SST26VF064B_SectorErase(uint32_t address);
FLASH_state SST26VF064B_BlockErase(uint32_t address);
FLASH_state SST26VF064B_ChipErase(void);
FLASH_state SST26VF064B_Write (uint32_t address,uint8_t * data2write, uint8_t len);
FLASH_state SST26VF064B_Read(uint32_t address, uint8_t *read_data, uint8_t len);

#endif /* SST26VF064B_H */
