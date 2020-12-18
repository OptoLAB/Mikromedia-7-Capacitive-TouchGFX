#include <gui/light_screen/LIGHTView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "ir/NEC_TimerIC.h"
#include "ir/IR_Remote_Buttons.h"
#include "als/LTR329ALS.h"
#include "display/SSD1963.h"
}

typedef struct{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
}color_t;

color_t color={0,0,0};


LIGHTView::LIGHTView()
{

}

void LIGHTView::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID);
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_FILL_ID);

	Bitmap::cache(BITMAP_BLUE_PROGRESSINDICATORS_BG_LARGE_CIRCLE_INDICATOR_BG_LINE_HALF_ID);
	Bitmap::cache(BITMAP_BLUE_PROGRESSINDICATORS_FILL_LARGE_CIRCLE_INDICATOR_FILL_LINE_HALF_ID);

	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_BACK_ID);
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_FILL_ID);

    LIGHTViewBase::setupScreen();
}

void LIGHTView::tearDownScreen()
{
	Bitmap::clearCache();
    LIGHTViewBase::tearDownScreen();
}

void LIGHTView::updateText()
{
	switch(NEC_GetCommand())
	{
	case IR_BTN_0:
		color={70,70,70};
		break;
	case IR_BTN_1:
		color={255,70,70};
		break;
	case IR_BTN_2:
		color={70,255,70};
		break;
	case IR_BTN_3:
		color={70,70,255};
		break;
	case IR_BTN_4:
		color={70,255,255};
		break;
	case IR_BTN_5:
		color={255,70,255};
		break;
	case IR_BTN_6:
		color={255,255,70};
		break;
	default:
		color={214,214,214};
		break;
	}

	box1.setColor(Color::getColorFrom24BitRGB(color.red,color.green,color.blue));
	box1.invalidate();
}

void LIGHTView::handleTickEvent()
{
	uint16_t ch1, ch0;
	ticks++;
	if(ticks%1==0)
	{
		LTR329ALS_GetMeasurements(&ch0,&ch1);
		ch0=ch0>>8;
		ch1=ch1>>8;
		circleProgressCH0.setValue(ch0);
		circleProgressCH1.setValue(ch1);
		circleProgressCH0.invalidate();
		circleProgressCH1.invalidate();

		Unicode::snprintf(textAreaCH0Buffer,TEXTAREACH0_SIZE,"%d",(ch0*100)/255);
		Unicode::snprintf(textAreaCH1Buffer,TEXTAREACH1_SIZE,"%d",(ch1*100)/255);
		textAreaCH0.invalidate();
		textAreaCH1.invalidate();
	}

}

void LIGHTView::updateBacklight(int value)
{
	SSD1963_SetBacklight(value);
}
void LIGHTView::updateGain(int value)
{
	uint8_t gain=0;
	switch(value)
	{
		case 0:
			gain=LTR329ALS_GAIN_x1;
			break;
		case 1:
			gain=LTR329ALS_GAIN_x2;
			break;
		case 2:
			gain=LTR329ALS_GAIN_x4;
			break;
		case 3:
			gain=LTR329ALS_GAIN_x8;
			break;
		case 4:
			gain=LTR329ALS_GAIN_x48;
			break;
		case 5:
			gain=LTR329ALS_GAIN_x96;
			break;
	}
	LTR329ALS_SetGain(gain);

}

void LIGHTView::updateIntegration(int value)
{
	uint8_t int_time=0, meas_time=0;
	switch(value)
	{
		case 0:
			int_time=LTR329ALS_INT_50ms;
			meas_time=LTR329ALS_MEAS_50ms;
			break;
		case 1:
			int_time=LTR329ALS_INT_100ms;
			meas_time=LTR329ALS_MEAS_100ms;
			break;
		case 2:
			int_time=LTR329ALS_INT_150ms;
			meas_time=LTR329ALS_MEAS_200ms;
			break;
		case 3:
			int_time=LTR329ALS_INT_200ms;
			meas_time=LTR329ALS_MEAS_200ms;
			break;
		case 4:
			int_time=LTR329ALS_INT_250ms;
			meas_time=LTR329ALS_MEAS_500ms;
			break;
		case 5:
			int_time=LTR329ALS_INT_300ms;
			meas_time=LTR329ALS_MEAS_500ms;
			break;
		case 6:
			int_time=LTR329ALS_INT_350ms;
			meas_time=LTR329ALS_MEAS_500ms;
			break;
		case 7:
			int_time=LTR329ALS_INT_400ms;
			meas_time=LTR329ALS_MEAS_500ms;
			break;
	}
	LTR329ALS_SetIntegrationTime(int_time);
	LTR329ALS_SetMeasurementTime(meas_time);
}
