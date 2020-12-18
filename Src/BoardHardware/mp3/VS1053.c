/*
J. Bajic - 2018.
*/

#include "VS1053.h"

static SPI_HandleTypeDef hspi;


void SPI_Write(uint8_t data)
{
	while(!__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&hspi, &data, 1, VS1053_TIMEOUT);
}

uint8_t SPI_Read(void)
{
	uint8_t data;

	while(__HAL_SPI_GET_FLAG(&hspi, SPI_FLAG_RXNE));
	HAL_SPI_Receive(&hspi, &data, 1, VS1053_TIMEOUT);

	return data;
}


void VS1053_SCI_Write(uint8_t address, uint16_t data_in)
{
  SET_MP3_BSYNC;

  CLR_MP3_CS;                    // select MP3 SCI
  SPI_Write(VS1053_WRITE_CODE);
  SPI_Write(address);
  SPI_Write(Hi(data_in));       // high byte
  SPI_Write(Lo(data_in));       // low byte
  SET_MP3_CS;                    // deselect MP3 SCI
  while (DREQ == 0);             // wait until DREQ becomes 1, see MP3 codec datasheet, Serial Protocol for SCI
}

void VS1053_SCI_Read(uint8_t start_address, uint8_t words_count, uint16_t *data_buffer)
{
  uint16_t temp;

  CLR_MP3_CS;                    // select MP3 SCI
  SPI_Write(VS1053_READ_CODE);
  SPI_Write(start_address);

  while (words_count--) {        // read words_count words byte per byte
    temp = SPI_Read();
    temp <<= 8;
    temp += SPI_Read();
    *(data_buffer++) = temp;
  }
  SET_MP3_CS;                   // deselect MP3 SCI
  while (DREQ == 0);             // wait until DREQ becomes 1, see MP3 codec datasheet, Serial Protocol for SCI
}

void VS1053_SDI_Write(char data_)
{

  SET_MP3_CS;
  CLR_MP3_BSYNC;

  while (DREQ == 0);             // wait until DREQ becomes 1, see MP3 codec datasheet, Serial Protocol for SCI

  SPI_Write(data_);
  SET_MP3_BSYNC;
}

void VS1053_SDI_Write_32(uint8_t *data_)
{
  uint8_t i;

  SET_MP3_CS;
  CLR_MP3_BSYNC;

  while (DREQ == 0);             // wait until DREQ becomes 1, see MP3 codec datasheet, Serial Protocol for SCI

  for (i=0; i<32; i++)
  SPI_Write(data_[i]);
  SET_MP3_BSYNC;
}

void VS1053_ResetTime(void)
{
  VS1053_SCI_Write(VS1053_DECODE_TIME_ADDR, 0);
}

void VS1053_GetDecodeTime(uint16_t *time)
{
  VS1053_SCI_Read(VS1053_DECODE_TIME_ADDR, 1, time);
}


void VS1053_SetVolume(uint8_t left, uint8_t right)
{
  uint16_t volume;

  volume = (left<<8) + right;             // calculate value
  VS1053_SCI_Write(VS1053_VOL_ADDR, volume);    // Write value to VOL register
}

void VS1053_SetDefaultMode(void)
{
  SET_MP3_BSYNC;
  SET_MP3_CS;

  // Hardware reset
  CLR_MP3_RST;
  HAL_Delay(10);
  SET_MP3_RST;

  while (DREQ == 0);

  VS1053_SCI_Write(VS1053_MODE_ADDR, 0x0800);
  VS1053_SCI_Write(VS1053_BASS_ADDR, 0x7A00);
  VS1053_SCI_Write(VS1053_CLOCKF_ADDR, 0xC000);   // default 12 288 000 Hz

  // Maximum volume is 0x00 and total silence is 0xFE.
}

void VS1053_Init(SPI_HandleTypeDef spi_handle)
{
	hspi=spi_handle;

	SET_MP3_CS;
	SET_MP3_RST;
	CLR_MP3_BSYNC;
	SET_MP3_BSYNC;

	hspi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
	HAL_SPI_Init(&hspi);
    VS1053_SetDefaultMode();
    hspi.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
    HAL_SPI_Init(&hspi);

    VS1053_SetVolume(50, 50);
    VS1053_ResetTime();
}



