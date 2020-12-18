#include <gui/buzzer_screen/BUZZERView.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "buzzer/buzzer.h"
}

BUZZERView::BUZZERView()
{

}

void BUZZERView::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_BACK_ID);
	Bitmap::cache(BITMAP_BLUE_SLIDER_HORIZONTAL_LARGE_SLIDER_ROUND_FILL_ID);

    BUZZERViewBase::setupScreen();
}

void BUZZERView::tearDownScreen()
{
	Bitmap::clearCache();
    BUZZERViewBase::tearDownScreen();
}
void BUZZERView::startBuzzer()
{
	BUZZER_Start();
}
void BUZZERView::stopBuzzer()
{
	BUZZER_Stop();
}
void BUZZERView::updateVolume(int value)
{
  volume=value;
}
void BUZZERView::updateTone(int value)
{
  tone=value;
}

void BUZZERView::handleTickEvent()
{
	if(buttonC.getPressed())BUZZER_SetTimerCounterPeriod(TONE_C);
	else if(buttonC_.getPressed())BUZZER_SetTimerCounterPeriod(TONE_C_);
	else if(buttonD.getPressed())BUZZER_SetTimerCounterPeriod(TONE_D);
	else if(buttonD_.getPressed())BUZZER_SetTimerCounterPeriod(TONE_D_);
	else if(buttonE.getPressed())BUZZER_SetTimerCounterPeriod(TONE_E);
	else if(buttonF.getPressed())BUZZER_SetTimerCounterPeriod(TONE_F);
	else if(buttonF_.getPressed())BUZZER_SetTimerCounterPeriod(TONE_F_);
	else if(buttonG.getPressed())BUZZER_SetTimerCounterPeriod(TONE_G);
	else if(buttonG_.getPressed())BUZZER_SetTimerCounterPeriod(TONE_G_);
	else if(buttonA.getPressed())BUZZER_SetTimerCounterPeriod(TONE_A);
	else if(buttonA_.getPressed())BUZZER_SetTimerCounterPeriod(TONE_A_);
	else if(buttonH.getPressed())BUZZER_SetTimerCounterPeriod(TONE_H);
	else BUZZER_SetTimerCounterPeriod(tone);

	BUZZER_SetTimerComparePeriod(volume);
}
