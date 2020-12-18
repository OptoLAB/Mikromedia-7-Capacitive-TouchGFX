/*
 * BMPFileLoader.hpp
 *
 *  Created on: Apr 20, 2020
 *      Author: Jovan
 */

#ifndef BMPFILELOADER_HPP_
#define BMPFILELOADER_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

#include "fatfs.h"

using namespace touchgfx;

typedef struct {
	unsigned long offset;
	unsigned long width;
	unsigned long height;
	unsigned int bpp;
	char *file_path;
} BMP_FILE_info;

class BMPFileLoader
{
public:
   // typedef void* FileHdl;

    static BMP_FILE_info getBMPInfoFromSD(TCHAR *file_path);
    static void loadBMPfromSD(BMP_FILE_info bmp, Bitmap bitmap);
private:
    static int readFile(FIL hdl, uint8_t* const buffer, uint32_t length);
    static void seekFile(FIL hdl, uint32_t offset);
    static uint32_t convertRGB(const unsigned char src, const unsigned char dst, uint32_t color);
};

#endif /* GUI_INCLUDE_GUI_COMMON_BMPFILELOADER_HPP_ */
