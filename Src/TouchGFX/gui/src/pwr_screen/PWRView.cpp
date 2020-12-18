#include <gui/pwr_screen/PWRView.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>
extern "C" {
#include "power/pwr.h"
}


static float batV[11]={
		2.77	,	//	0%
		//3.11	,	//	5%
		3.19	,	//	10%
		//3.21	,	//	15%
		3.23	,	//	20%
		//3.25	,	//	25%
		3.27	,	//	30%
		//3.29	,	//	35%
		3.30	,	//	40%
		//3.32	,	//	45%
		3.34	,	//	50%
		//3.35	,	//	55%
		3.37	,	//	60%
		//3.41	,	//	65%
		3.45	,	//	70%
		//3.48	,	//	75%
		3.52	,	//	80%
		//3.58	,	//	85%
		3.61	,	//	90%
		//3.65	,	//	95%
		3.7			//	100%

};

PWRView::PWRView()
{

}

void PWRView::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_PROGRESSINDICATORS_BG_LARGE_CIRCLE_INDICATOR_BG_FULL_ID);
	Bitmap::cache(BITMAP_LIGHTNING_ID);
	radioButtonDC.setTouchable(0);
	radioButtonBAT.setTouchable(0);
    PWRViewBase::setupScreen();
}
void PWRView::updateProgress(uint8_t value)
{
	batProgress.setValue(value*10);
	if(value<2)batProgressPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(200, 0, 0));
	else if(value<4)batProgressPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(200, 200, 0));
	else batProgressPainter.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 200, 0));
	batTextProgress.setValue(value*10);
	batProgress.invalidate();
}
void PWRView::tearDownScreen()
{
	Bitmap::clearCache();
    PWRViewBase::tearDownScreen();
}

void PWRView::handleTickEvent()
{
	ticks++;
	if(!(ticks%16))
	{
		PWR_GetBatteryVoltage(&bat_dpf, &bat_dpb);
		float batVoltageLevel=(float)bat_dpf+(float)bat_dpb/1000;

		if(PWR_GetDCDetect())
		{
			radioButtonDC.setSelected(0);
			textArea4.setTypedText(TypedText(T_DCOFF));
		}
		else
		{
			radioButtonDC.setSelected(1);
			textArea4.setTypedText(TypedText(T_DCON));

		}

		if(PWR_GetPSStat())
		{
			imageChargeStatus.setVisible(true);
			radioButtonBAT.setSelected(1);
			textArea5.setTypedText(TypedText(T_BATON));

			volts++;
			if(volts>10)volts=0;
			updateProgress(volts);
		}
		else
		{
			imageChargeStatus.setVisible(false);
			radioButtonBAT.setSelected(0);
			textArea5.setTypedText(TypedText(T_BATOFF));
			for(volts=0; volts<11;volts++)
			{
				if(batVoltageLevel<batV[volts])
					break;
			}
			updateProgress(volts);
		}


		radioButtonDC.invalidate();
		radioButtonBAT.invalidate();

		textArea4.invalidate();
		textArea4.resizeToCurrentText();

		textArea5.invalidate();
		textArea5.resizeToCurrentText();

		Unicode::snprintf(textArea7Buffer1,TEXTAREA7BUFFER1_SIZE,"%d",bat_dpf);
		Unicode::snprintf(textArea7Buffer2,TEXTAREA7BUFFER2_SIZE,"%d",bat_dpb/10);
		textArea7.invalidate();
		textArea7.resizeToCurrentText();
	}
}
