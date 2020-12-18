#include "BitmapDatabase.hpp"
#include <gui/gallery_screen/GALLERYView.hpp>
#include <string.h>
#include <stdio.h>

extern "C" {
#include "led/NCP5623C.h"
}


GALLERYView::GALLERYView()
{

}

void GALLERYView::setupScreen()
{
	FRESULT fr;     // Return value
	DIR dj;         // Directory search object
	FILINFO fno;    // File information


	add(image);

	f_mount(&myFAT, USERPath, 1);

    num_of_imgs=0;

    fr = f_findfirst(&dj, &fno, "images", "*.bmp");
    strcpy(img_name,fno.fname);
    sprintf((char*)img_path, "%s/%s", (char*)"images", (char*)img_name);

    while (fr == FR_OK && fno.fname[0])
    {
    	 num_of_imgs++;
    	 fr = f_findnext(&dj, &fno);
    }
    f_closedir(&dj);

    BMP_FILE_info bmp=loadImage(img_path);
    updateInfo(img_name,bmp);
    current_img=0;
    updateButtonState(current_img);

	f_mount(0, USERPath, 1);

	GALLERYViewBase::setupScreen();
}

void GALLERYView::tearDownScreen()
{
	Bitmap::dynamicBitmapDelete(bmpId);
	Bitmap::clearCache();
	GALLERYViewBase::tearDownScreen();
}

void GALLERYView::loadNext()
{
	DIR dj;         // Directory search object
	FILINFO fno;    // File information

	f_mount(&myFAT, USERPath, 1);

	f_findfirst(&dj, &fno, "images", "*.bmp");
	for(int i=0;i<(current_img+1);i++) f_findnext(&dj, &fno);
	f_closedir(&dj);

	strcpy(img_name,fno.fname);
	sprintf((char*)img_path, "%s/%s", (char*)"images", (char*)img_name);

	Bitmap::dynamicBitmapDelete(bmpId);

	BMP_FILE_info bmp=loadImage(img_path);
	updateInfo(img_name,bmp);
	current_img++;
	updateButtonState(current_img);

	f_mount(0, USERPath, 1);


}
void GALLERYView::loadPrevious()
{
	DIR dj;         // Directory search object
	FILINFO fno;    // File information

	f_mount(&myFAT, USERPath, 1);

	f_findfirst(&dj, &fno, "images", "*.bmp");  					// find first in given folder
	for(int i=0;i<(current_img-1);i++) f_findnext(&dj, &fno);		// find previous from current
	f_closedir(&dj);

	strcpy(img_name,fno.fname);												//copy image name
	sprintf((char*)img_path, "%s/%s", (char*)"images", (char*)img_name);	//form absolute path

	Bitmap::dynamicBitmapDelete(bmpId);										//delete previous image

	BMP_FILE_info bmp=loadImage(img_path);
	updateInfo(img_name,bmp);
	current_img--;
	updateButtonState(current_img);

	f_mount(0, USERPath, 1);
}
BMP_FILE_info GALLERYView::loadImage(char* img_path)
{
    BMP_FILE_info bmp=BMPFileLoader::getBMPInfoFromSD((TCHAR*)img_path);	//get info from file to be displayed
    bmpId = Bitmap::dynamicBitmapCreate(bmp.width, bmp.height, Bitmap::RGB565);	//create new image
    BMPFileLoader::loadBMPfromSD(bmp, Bitmap(bmpId));						//load new image with data from SD

    image.setBitmap(Bitmap(bmpId));
    image.setXY(CENTER_X-(bmp.width>>1), CENTER_Y-(bmp.height>>1));
    image.invalidate();

    box2.invalidate();

	boxImage.setXY(CENTER_X-(bmp.width>>1)-3, CENTER_Y-(bmp.height>>1)-3);
	boxImage.setWidth(bmp.width+6);
	boxImage.setHeight(bmp.height+6);
	boxImage.invalidate();

	return bmp;
}
void GALLERYView::updateInfo(char* img_name, BMP_FILE_info bmp)
{
    Unicode::UnicodeChar name[100];
    Unicode::strncpy(name, img_name, 100);
	Unicode::snprintf(textArea2Buffer,TEXTAREA2_SIZE,"name: %s, width: %d, height: %d, bpp: %d",name, bmp.width,bmp.height,bmp.bpp);
	textArea2.invalidate();
	textArea2.resizeToCurrentText();
	textArea2.invalidate();
}
void GALLERYView::updateButtonState(int img_index)
{
	if(img_index==0)
	{
		buttonPrevious.setAlpha(100);
		buttonPrevious.setTouchable(false);
		buttonPrevious.invalidate();
	}
	if(img_index==1)
	{
		buttonPrevious.setAlpha(255);
		buttonPrevious.setTouchable(true);
		buttonPrevious.invalidate();
	}
	if(img_index==num_of_imgs-1)
	{
		buttonNext.setAlpha(100);
		buttonNext.setTouchable(false);
		buttonNext.invalidate();
	}
	if(img_index==num_of_imgs-2)
	{
		buttonNext.setAlpha(255);
		buttonNext.setTouchable(true);
		buttonNext.invalidate();
	}

}
