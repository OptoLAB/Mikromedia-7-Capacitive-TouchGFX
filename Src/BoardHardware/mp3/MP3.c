/*
J. Bajic - 2018.
*/

#include "MP3.h"
#include "string.h"

#define BYTES_2_WRITE 32
#define BUFFER_SIZE 1024
#define MAX_NUM_OF_SONGS 50

static uint8_t mp3_buffer[BUFFER_SIZE];
static unsigned long file_size=0;
static unsigned long Buffer_count, Total_Buffers;

FIL song;
FATFS mp3FAT;

int MP3_state=FINISHED;

void MP3_SetVolume(int vol)
{
	VS1053_SetVolume(vol, vol);

}

void MP3_SetState(int state)
{
	MP3_state=state;
}

int MP3_GetState(void)
{
	return MP3_state;
}

unsigned long MP3_GetPlayingPosition(void)
{
	return Buffer_count;
}
unsigned long  MP3_GetPlayingTime(void)
{
	return Total_Buffers;
}
void MP3_MountSD(void)
{
	//FRESULT fr;
	f_mount(&mp3FAT, USERPath, 1);
}
void MP3_UnountSD(void)
{
	//FRESULT fr;
	f_mount(0, USERPath, 1);
}

void MP3_Open(const char *path)
{
	f_open(&song, path, FA_READ);
	//size
	file_size=f_size(&song);
	Buffer_count=0;
	Total_Buffers = file_size / BUFFER_SIZE;

	VS1053_ResetTime();
}

void MP3_Close(void)
{
	file_size=0;
	f_close(&song);
}

void MP3_Play(const char *name)
{
	unsigned int byteCount, i;
	if(file_size==0)
	{
		MP3_Open(name);
		MP3_SetState(PLAYING);

	}
	if(file_size!=0)
	{
		if(file_size >= BUFFER_SIZE)
		{     // while there is still data, send it to mp3 codec chip
			f_read(&song, &mp3_buffer, BUFFER_SIZE, &byteCount);

			for (i=0; i<BUFFER_SIZE/BYTES_2_WRITE; i++)
			{
				VS1053_SDI_Write_32(mp3_buffer + i*BYTES_2_WRITE);
			}

			file_size -= BUFFER_SIZE;
			Buffer_count++;
		}

		if (file_size < BUFFER_SIZE)
		{     // finish playing file
			f_read(&song, &mp3_buffer, file_size, &byteCount);

			for (i=0; i<file_size; i++)
			{
				VS1053_SDI_Write(mp3_buffer[i]);
			}
			Buffer_count++;
			MP3_Close();
			MP3_SetState(FINISHED);
		}
	}
}

