#include <gui/main_menu_screen/MAIN_MENUView.hpp>
#include "BitmapDatabase.hpp"

MAIN_MENUView::MAIN_MENUView()
{

}

void MAIN_MENUView::setupScreen()
{
	MAIN_MENUViewBase::setupScreen();
}

void MAIN_MENUView::tearDownScreen()
{
	Bitmap::clearCache();
    MAIN_MENUViewBase::tearDownScreen();
}

void MAIN_MENUView::handleTickEvent()
{
	if(flexButtonRGB.getPressed())
	{
		box1.setXY(flexButtonRGB.getX(),flexButtonRGB.getY());
		box1.setVisible(true);
	}
	else if(flexButtonLight.getPressed())
	{
		box1.setXY(flexButtonLight.getX(),flexButtonLight.getY());
		box1.setVisible(true);
	}
	else if(flexButtonAccel.getPressed())
	{
		box1.setXY(flexButtonAccel.getX(),flexButtonAccel.getY());
		box1.setVisible(true);
	}
	else if(flexButtonGallery.getPressed())
	{
		box1.setXY(flexButtonGallery.getX(),flexButtonGallery.getY());
		box1.setVisible(true);
	}
	else if(flexButtonMusic.getPressed())
	{
		box1.setXY(flexButtonMusic.getX(),flexButtonMusic.getY());
		box1.setVisible(true);
	}
	else if(flexButtonTemp.getPressed())
	{
		box1.setXY(flexButtonTemp.getX(),flexButtonTemp.getY());
		box1.setVisible(true);
	}
	else if(flexButtonPower.getPressed())
	{
		box1.setXY(flexButtonPower.getX(),flexButtonPower.getY());
		box1.setVisible(true);
	}
	else if(flexButtonTime.getPressed())
	{
		box1.setXY(flexButtonTime.getX(),flexButtonTime.getY());
		box1.setVisible(true);
	}
	else if(flexButtonBuzzer.getPressed())
	{
		box1.setXY(flexButtonBuzzer.getX(),flexButtonBuzzer.getY());
		box1.setVisible(true);
	}
	else if(flexButtonFlash.getPressed())
	{
		box1.setXY(flexButtonFlash.getX(),flexButtonFlash.getY());
		box1.setVisible(true);
	}
	else if(flexButtonRF.getPressed())
	{
		box1.setXY(flexButtonRF.getX(),flexButtonRF.getY());
		box1.setVisible(true);
	}
	else if(flexButtonWeather.getPressed())
	{
		box1.setXY(flexButtonWeather.getX(),flexButtonWeather.getY());
		box1.setVisible(true);
	}
	else box1.setVisible(false);

	box1.invalidate();

}
