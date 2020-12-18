/*
J. Bajic - 2018.
*/

#ifndef MP3_H
#define MP3_H

#include "VS1053.h"
#include "fatfs.h"

#define PLAYING		0
#define FINISHED 	1

void MP3_SetVolume(int vol);
void MP3_SetState(int state);
int MP3_GetState(void);
unsigned long  MP3_GetPlayingPosition(void);
unsigned long  MP3_GetPlayingTime(void);
void MP3_MountSD(void);
void MP3_UnountSD(void);
void MP3_Open(const char *name);
void MP3_Close(void);
void MP3_Play(const char *name);

#endif /* MP3_H */
