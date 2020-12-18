#include <gui/flash_screen/FLASHView.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "flash/SST26VF064B.h"
}

FLASHView::FLASHView()
{

}

void FLASHView::setupScreen()
{
    FLASHViewBase::setupScreen();
}

void FLASHView::tearDownScreen()
{
    FLASHViewBase::tearDownScreen();
}
void FLASHView::loadFlash()
{
	res=f_mount(&myFAT, USERPath, 1);

	if(res==FR_OK)
	{
		res=f_open(&flashFile, "flash/ExtFlash.bin", FA_READ);

		file_size=f_size(&flashFile);
		packet_count=0;
		address=START_PAGE_ADDRESS;
		num_of_packets = file_size / packet_size;
		flashProgressBar.setRange(0, num_of_packets);
		flashProgressBar.setValue(0);
		flashProgressBar.invalidate();
		flashProgressText.setRange(0, num_of_packets);
		flashProgressText.setValue(0);
		flashProgressText.invalidate();

		buttonLoad.setTouchable(false);
		buttonLoad.setAlpha(100);
		buttonLoad.invalidate();
		buttonErase.setTouchable(false);
		buttonErase.setAlpha(100);
		buttonErase.invalidate();

	}
}
void FLASHView::eraseFlash()
{
	containerInfo.setVisible(false);
	containerWarning.setVisible(true);
	modalWindow1.setVisible(true);
	modalWindow1.invalidate();

}
void FLASHView::hideInfo()
{
	modalWindow1.setVisible(false);
	modalWindow1.invalidate();

}
void FLASHView::deleteFlash()
{
	SST26VF064B_ChipErase();
	flashProgressBar.setValue(0);
	flashProgressBar.invalidate();
	flashProgressText.setValue(0);
	flashProgressText.invalidate();
	hideInfo();
}
void FLASHView::handleTickEvent()
{
	unsigned int byteCount;

	for(int i=0;i<8;i++)
	{
		if(file_size)
		{
			if(file_size>packet_size)
			{
				f_read(&flashFile, &paket, packet_size, &byteCount);
				while(SST26VF064B_Write(address,paket,packet_size)!=FLASH_OK);
				address+=byteCount;
				packet_count++;
				file_size-=packet_size;
			}
			else
			{
				f_read(&flashFile, &paket, packet_size, &byteCount);
				while(SST26VF064B_Write(address,paket,byteCount)!=FLASH_OK);
				packet_count++;
				file_size=0;
				f_close(&flashFile);
				f_mount(0, USERPath, 1);

				uint32_t size=packet_count*packet_size;
				Unicode::snprintf(textAreaSizeBuffer1,TEXTAREASIZEBUFFER1_SIZE,"%d",(size>>10));
				Unicode::snprintf(textAreaSizeBuffer2,TEXTAREASIZEBUFFER2_SIZE,"%d",(size&0x3FF));
				containerInfo.setVisible(true);
				containerWarning.setVisible(false);
				modalWindow1.setVisible(true);
				modalWindow1.invalidate();

				buttonLoad.setTouchable(true);
				buttonLoad.setAlpha(255);
				buttonLoad.invalidate();
				buttonErase.setTouchable(true);
				buttonErase.setAlpha(255);
				buttonErase.invalidate();


			}
			flashProgressBar.setValue(packet_count);
			flashProgressBar.invalidate();
			flashProgressText.setValue(packet_count);
			flashProgressText.invalidate();
		}
	}
}
