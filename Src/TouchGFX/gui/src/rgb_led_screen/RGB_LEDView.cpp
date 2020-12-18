#include <gui/rgb_led_screen/RGB_LEDView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "led/NCP5623C.h"
}


RGB_LEDView::RGB_LEDView()
{

}

void RGB_LEDView::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_BACK_ID);
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_FILL_ID);
	Bitmap::cache(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_OFF_ID);
	Bitmap::cache(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_ON_ID);

    RGB_LEDViewBase::setupScreen();
}

void RGB_LEDView::tearDownScreen()
{
	Bitmap::clearCache();
    RGB_LEDViewBase::tearDownScreen();
}

//RED LED
//-------------------------------------------------------------------------------------------
void RGB_LEDView::setRedLEDValue(int value)
{
	if(toggleButtonRED.getState())
	{
		NCP5623C_SetLED(R_LED,value);
		red=value<<3;
		colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
		colorBox.invalidate();
	}
}

void RGB_LEDView::setRedLEDState()
{
	if(toggleButtonRED.getState())
	{
		NCP5623C_SetLED(R_LED,sliderRED.getValue());
		red=sliderRED.getValue()<<3;
	}
	else
	{
		NCP5623C_SetLED(R_LED,0);
		red=0;
	}
	colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
	colorBox.invalidate();
}
//GREEN LED
//-------------------------------------------------------------------------------------------
void RGB_LEDView::setGreenLEDValue(int value)
{
	if(toggleButtonGREEN.getState())
	{
		NCP5623C_SetLED(G_LED,value);
		green=value<<3;
		colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
		colorBox.invalidate();
	}
}

void RGB_LEDView::setGreenLEDState()
{
	if(toggleButtonGREEN.getState())
	{
		NCP5623C_SetLED(G_LED,sliderGREEN.getValue());
		green=sliderGREEN.getValue()<<3;
	}
	else
	{
		NCP5623C_SetLED(G_LED,0);
		green=0;
	}
	colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
	colorBox.invalidate();
}
//BLUE LED
//-------------------------------------------------------------------------------------------
void RGB_LEDView::setBlueLEDValue(int value)
{
	if(toggleButtonBLUE.getState())
	{
		NCP5623C_SetLED(B_LED,value);
		blue=value<<3;
		colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
		colorBox.invalidate();
	}
}

void RGB_LEDView::setBlueLEDState()
{
	if(toggleButtonBLUE.getState())
	{
		NCP5623C_SetLED(B_LED,sliderBLUE.getValue());
		blue=sliderBLUE.getValue()<<3;
	}
	else
	{
		NCP5623C_SetLED(B_LED,0);
		blue=0;
	}
	colorBox.setColor(touchgfx::Color::getColorFrom24BitRGB(red, green, blue));
	colorBox.invalidate();
}
