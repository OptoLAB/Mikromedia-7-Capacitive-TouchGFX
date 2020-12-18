#include <gui/mp3_screen/MP3View.hpp>
#include <touchgfx/Color.hpp>
#include <string.h>
#include <stdio.h>
#include "BitmapDatabase.hpp"
extern "C" {
#include "mp3/MP3.h"
}

MP3View::MP3View()
		:playlistItemClickedCallback(this, &MP3View::playlistItemClicked)
{
	playlistScroll.removeAll();
	remove(playlistScroll);

	playlistScrollScrollable.setPosition(363, 96, 416, 334);
	playlistScrollScrollable.setScrollbarsColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    playlist.setDirection(touchgfx::SOUTH);
    playlist.setPosition(0, 0, 250, 250);
    playlistScrollScrollable.add(playlist);

	playlistScrollScrollable.setScrollbarsPermanentlyVisible();
	playlistScrollScrollable.setScrollbarsVisible(false);

	add(playlistScrollScrollable);
}

void MP3View::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_LINE_FULL_ID);
	Bitmap::cache(BITMAP_DARK_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID);
	Bitmap::cache(BITMAP_DARK_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID);

	FRESULT fr;
	DIR dj;
	FILINFO fno;

	MP3_MountSD();

	// scan and search for MP3 files - copy files names to playlist items
    num_of_songs=0;
    fr = f_findfirst(&dj, &fno, "music", "*.mp3");
	while (fr == FR_OK && fno.fname[0] && num_of_songs<max_num_of_songs)
	{
		unsigned char song_len=Unicode::strlen(fno.fname);
		if(song_len<max_song_name_len)
		{
			Unicode::strncpy(name, (char*)fno.fname, max_num_of_songs);
			playlistItems[num_of_songs].setText(name,num_of_songs);
			num_of_songs++;
		}
		fr = f_findnext(&dj, &fno);
	}
	f_closedir(&dj);

	//populate MP3 playlist with found items
    for (uint8_t i = 0; i < num_of_songs; ++i)
    {
    	playlistItems[i].setAction(playlistItemClickedCallback);
        playlist.add(playlistItems[i]);
    }

    //set playlist to first song
	songID=0;
	playlistItems[0].setItem();
	playlistItems[0].getText(name);
	updateSelectedSong(name);

	//udate info text
	Unicode::snprintf(textArea3Buffer,TEXTAREA3_SIZE,"%d",num_of_songs);
	textArea3.invalidate();
	textArea3.resizeToCurrentText();
	textArea3.invalidate();

	//set default volume and execute stop
	MP3_SetVolume(50);
	stopSong();

    MP3ViewBase::setupScreen();
}

void MP3View::tearDownScreen()
{
	Bitmap::clearCache();
	MP3_UnountSD();
    MP3ViewBase::tearDownScreen();
}

void MP3View::playlistItemClicked(playlistItem& item)
{
	playlistItems[songID].resetItem();
	songID=item.getText(name);
	item.setItem();
	updateSelectedSong(name);

}
void MP3View::updateSelectedSong(Unicode::UnicodeChar *text)
{
	char song_name[max_song_name_len];

	Unicode::toUTF8(text, (uint8_t*)song_name, max_song_name_len);
	sprintf((char*)song_path,"%s/%s",(char*)"music",(char*)song_name);

	Unicode::snprintf(textArea2Buffer,TEXTAREA2_SIZE,(char*)song_path);
	textArea2.invalidate();
	textArea2.resizeToCurrentText();
	textArea2.invalidate();
}

void MP3View::playSong()
{
	MP3_Play(song_path);
	play=1;
	playProgress.setRange(0,MP3_GetPlayingTime());
}
void MP3View::stopSong()
{
	play=0;
	MP3_Close();
	playProgress.setValue(0);

}
void MP3View::nextSong()
{
	MP3_Close();

	playlistItems[songID].resetItem();
	if(songID<(num_of_songs-1))
	{
		songID++;
		playlistItems[songID].setItem();
		playlistItems[songID].getText(name);
		updateSelectedSong(name);
		playlistScrollScrollable.doScroll(0,-playlistItems[songID].getHeight());
		playlistScrollScrollable.invalidate();
	}

	MP3_Play(song_path);
}
void MP3View::previousSong()
{
	MP3_Close();

	playlistItems[songID].resetItem();
	if(songID>0)
	{
		songID--;
		playlistItems[songID].setItem();
		playlistItems[songID].getText(name);
		updateSelectedSong(name);
		playlistScrollScrollable.doScroll(0,playlistItems[songID].getHeight());

		playlistScrollScrollable.invalidate();

	}
	MP3_Play(song_path);
}
void MP3View::pauseSong()
{
	play=0;
}
void MP3View::setVolume(int value)
{
	int vol=100-value;
	MP3_SetVolume(vol);
}
void MP3View::handleTickEvent()
{
	if(play)
	{
		MP3_Play(song_path);
		playProgress.setValue(MP3_GetPlayingPosition());
		if(MP3_GetState()==FINISHED)
		{
			nextSong();
		}
	}
}
