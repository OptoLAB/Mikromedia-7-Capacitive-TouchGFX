#ifndef FLASHVIEW_HPP
#define FLASHVIEW_HPP

#include <gui_generated/flash_screen/FLASHViewBase.hpp>
#include <gui/flash_screen/FLASHPresenter.hpp>
#include "fatfs.h"

class FLASHView : public FLASHViewBase
{
public:
    FLASHView();
    virtual ~FLASHView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void loadFlash();
    virtual void eraseFlash();
    virtual void deleteFlash();
    virtual void hideInfo();
    virtual void handleTickEvent();
protected:
private:
    unsigned long file_size=0;
    unsigned long packet_count;
	unsigned long num_of_packets;

	uint16_t packet_size=128;
	uint8_t paket[128];
	uint32_t address;

	FATFS myFAT;
	FIL flashFile;
	FRESULT res;
};

#endif // FLASHVIEW_HPP
