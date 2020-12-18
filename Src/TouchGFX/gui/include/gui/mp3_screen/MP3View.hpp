#ifndef MP3VIEW_HPP
#define MP3VIEW_HPP

#include <gui_generated/mp3_screen/MP3ViewBase.hpp>
#include <gui/mp3_screen/MP3Presenter.hpp>
#include <gui/containers/playlistItem.hpp>
#include <gui/common/MyScrollableContainer.hpp>

class MP3View : public MP3ViewBase
{
public:
    MP3View();
    virtual ~MP3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void playSong();
    virtual void stopSong();
    virtual void handleTickEvent();
    virtual void nextSong();
	virtual void previousSong();
	virtual void pauseSong();
	virtual void updateSelectedSong(Unicode::UnicodeChar *text);
	virtual void setVolume(int value);
	virtual void playlistItemClicked(playlistItem& element);
protected:
	static const int numberOfPlaylistItems = 50;
	playlistItem playlistItems[numberOfPlaylistItems];
	Callback<MP3View, playlistItem&> playlistItemClickedCallback;
	MyScrollableContainer playlistScrollScrollable;
private:
	unsigned int num_of_songs;
	unsigned char play;
	unsigned char max_song_name_len=50;
	unsigned char max_num_of_songs=numberOfPlaylistItems;
	char song_path[255];
	unsigned char songID;
	Unicode::UnicodeChar name[100];
};

#endif // MP3VIEW_HPP
