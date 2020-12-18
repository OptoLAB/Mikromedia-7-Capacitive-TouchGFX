#ifndef GALLERYVIEW_HPP
#define GALLERYVIEW_HPP

#include <gui_generated/gallery_screen/GALLERYViewBase.hpp>
#include <gui/gallery_screen/GalleryPresenter.hpp>
#include <gui/common/BMPFileLoader.hpp>
#include "fatfs.h"

class GALLERYView : public GALLERYViewBase
{
public:
	GALLERYView();
    virtual ~GALLERYView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void loadNext();
    virtual void loadPrevious();

    BMP_FILE_info loadImage(char* img_path);
    void updateInfo(char* img_name, BMP_FILE_info bmp);
    void updateButtonState(int img_index);
protected:
private:
    Image image;

    FATFS myFAT;
    FIL myFile;

    BitmapId bmpId;

    int num_of_imgs=0, current_img;
    TCHAR img_name[100]={0};
    char img_path[256]={0};

    uint16_t CENTER_X=400;
    uint16_t CENTER_Y=316;
    uint8_t FRAME_TICKNESS=3;
};

#endif // GALLERYVIEW_HPP
