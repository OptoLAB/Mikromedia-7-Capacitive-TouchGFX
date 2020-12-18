/*
 * BMPFileLoader.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: Jovan
 */


#include <gui/common/BMPFileLoader.hpp>
#include <touchgfx/Color.hpp>
#include "fatfs.h"

#define BMP_DIB     0x0E
#define BMP_WIDTH   0x12
#define BMP_HEIGHT  0x16
#define BMP_BPP     0x1C
#define BMP_COLORS  0x2E

#define RGB111 	(0)
#define RGB332 	(1)
#define RGB565	(2)
#define RGB888 	(3)

#define DEFAULT_FORMAT RGB565

int BMPFileLoader::readFile(FIL hdl, uint8_t* const buffer, uint32_t length)
{
    UINT r=0;
    f_read(&hdl, buffer, length, &r);
    if (r != length)
    {
        return 1;
    }
    return 0;
}

void BMPFileLoader::seekFile(FIL hdl, uint32_t offset)
{
	f_lseek(&hdl, offset);
}

uint32_t BMPFileLoader::convertRGB(const unsigned char src, const unsigned char dst, uint32_t color)
{
    uint8_t r,g,b;

    if(src==RGB111)//RGB111
    {
        r=(color>>2)&0x01;
        g=(color>>1)&0x01;
        b=(color&0x01);
        if(dst==RGB332)      return ((r<<7)|(g<<4)|(b<<1));
        else if(dst==RGB565) return ((r<<15)|(g<<10)|(b<<4));
        else if(dst==RGB888) return ((r<<23)|(g<<15)|(b<<7));
        else            	 return color;
    }
    else if(src==RGB332)//RGB332
    {
        r=(color>>5)&0x07;
        g=(color>>2)&0x07;
        b=(color&0x03);
        if(dst==RGB111)      return (((r>>2)<<2)|((g>>2)<<1)|(b>>1));
        else if(dst==RGB565) return ((r<<13)|(g<<8)|(b<<3));
        else if(dst==RGB888) return ((r<<21)|(g<<13)|(b<<6));
        else           		 return color;

    }
    else if(src==RGB565)//RGB565
    {
        r=(color>>11)&0x1F;
        g=(color>>5)&0x3F;
        b=(color&0x1F);
        if(dst==RGB111)      return (((r>>4)<<2)|((g>>5)<<1)|(b>>4));
        else if(dst==RGB332) return (((r>>2)<<5)|((g>>3)<<2)|(b>>3));
        else if(dst==RGB888) return ((r<<19)|(g<<10)|(b<<3));
        else            	 return color;
    }
    else if(src==RGB888)//RGB888
    {
        r=(color>>16)&0xFF;
        g=(color>>8)&0xFF;
        b=(color&0xFF);
        if(dst==RGB111)      return (((r>>7)<<2)|((g>>7)<<1)|(b>>7));
        else if(dst==RGB332) return (((r>>5)<<5)|((g>>5)<<2)|(b>>6));
        else if(dst==RGB565) return (((r>>3)<<11)|((g>>2)<<5)|(b>>3));
        else            	 return color;
    }
    else return color;
}
BMP_FILE_info BMPFileLoader::getBMPInfoFromSD(TCHAR *file_path)
{
    uint8_t data[4];
    FIL myFile;
    unsigned int byteCount;
    BMP_FILE_info bmp;

    //open
    f_open(&myFile, file_path, FA_READ);

    //offset
    f_lseek(&myFile, BMP_DIB);
    f_read(&myFile, &data, 4, &byteCount);
    bmp.offset=((data[3]<<24)|(data[2]<<16) |(data[1]<<8)|(data[0]))+BMP_DIB;

    //get image width
    f_lseek(&myFile, BMP_WIDTH);
    f_read(&myFile, &data, 4, &byteCount);
    bmp.width=(data[3]<<24)|(data[2]<<16)|(data[1]<<8)|(data[0]);

    //get image height
    f_lseek(&myFile, BMP_HEIGHT);
    f_read(&myFile, &data, 4, &byteCount);
    bmp.height=(data[3]<<24)|(data[2]<<16)|(data[1]<<8)|(data[0]);

    //get image Bits Per Pixel
    f_lseek(&myFile, BMP_BPP);
    f_read(&myFile, &data, 4, &byteCount);
    bmp.bpp=(data[1]<<8)|(data[0]);

    bmp.file_path=file_path;

    f_close(&myFile);

    return bmp;
}

void BMPFileLoader::loadBMPfromSD(BMP_FILE_info bmp, Bitmap bitmap)
{
    FIL myFile;
	unsigned int byteCount;

    uint32_t color, line, last_line;
    uint8_t  data[4];
    uint32_t n_colors;
    uint32_t y, x, endX, endY, x_offset;
    uint8_t i, format, bytes, pixels;
    uint8_t img_line[800*4]={0};
    uint8_t color_palette[1024];


    uint16_t* const buffer16 = (uint16_t*)Bitmap::dynamicBitmapGetAddress(bitmap.getId());

    //open
    f_open(&myFile, (TCHAR*)bmp.file_path, FA_READ);


    //get num of colors in palette for low bpp
    if(bmp.bpp<=8)
    {
        f_lseek(&myFile, BMP_COLORS);
        f_read(&myFile, &data, 4, &byteCount);
        n_colors=(data[3]<<24)|(data[2]<<16)|(data[1]<<8)|(data[0]);
    }
    //go to image data
    f_lseek(&myFile, bmp.offset);

    //read color pallete for low bpp
    if(bmp.bpp<=8)
    {
        if(n_colors==0)n_colors=(1<<bmp.bpp);
        f_read(&myFile, &color_palette, 4*n_colors, &byteCount);
        bmp.offset+=4*n_colors;
    }

    //Prepare
    format=bmp.bpp>>3;
    bytes=format;
    if(format>3)format=3;
    pixels=0;
    if(!bytes) // 2 pixels per 1 byte
    {
      bytes=1;
      pixels=1;
    }

    endX=bmp.width;
    endY=bmp.height;
    if((endX)>bitmap.getWidth())endX=bitmap.getWidth(); //crop width
    if((endY)>bitmap.getHeight())						//crop height
    {
    	bmp.offset=bmp.offset+(bmp.width>>pixels)*(endY-bitmap.getHeight())*bytes;
        f_lseek(&myFile, bmp.offset);
        endY=bitmap.getHeight();
    }

    line=0;
    last_line=(endY-1)*bitmap.getWidth();

    for(y=0;y<endY;y++)
    {

        f_read(&myFile, &img_line, (bmp.width)*bytes>>pixels, &byteCount);

        for(x=0;x<endX;x++)
        {
            color=0;
            //get pixel color
            x_offset=(x)*bytes;
            for(i=0;i<bytes;i++) color|=img_line[(x_offset>>pixels)+i]<<(i<<3);
            if(pixels)color=(color>>((~x_offset&pixels)<<2))&0x0F; //get only nibble
            //for low bpp get color from color table
            if(bmp.bpp<=8)
            {
                color=(color_palette[4*color]|(color_palette[4*color+1]<<8)|(color_palette[4*color+2]<<16));
                format=3;
            }
            //convert pixel to default color format if needed
            if(format!=2) color=convertRGB(format,DEFAULT_FORMAT,color);

            buffer16[x+last_line-line]=color;
        }
        line+=bitmap.getWidth();
    }

    //close
    f_close(&myFile);

}
