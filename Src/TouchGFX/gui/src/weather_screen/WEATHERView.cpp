#include <gui/weather_screen/WEATHERView.hpp>
#include <BitmapDatabase.hpp>
extern "C" {
#include "wifi/wifi_weather_demo.h"
//#include "wifi//common//sl_common.h"
}

WEATHERView::WEATHERView()
{


}

void WEATHERView::setupScreen()
{
	Bitmap::cache(BITMAP_D01_ID);

    WEATHERViewBase::setupScreen();
}
void WEATHERView::updateWeather()
{
    _i32 retVal = -1;

    Unicode::strncpy(textAreaStatusBuffer,"Connecting...",TEXTAREASTATUS_SIZE);
    textAreaStatus.invalidate();
    retVal = initializeAppVariables();

    retVal = configureSimpleLinkToDefaultState();
    if(retVal < 0)
    {
        Unicode::strncpy(textAreaStatusBuffer,"Failed",TEXTAREASTATUS_SIZE);
        textAreaStatus.invalidate();
    }
    else
    {
    	retVal = sl_Start(0, 0, 0);
		if ((retVal < 0) || (ROLE_STA != retVal) )
		{
			Unicode::strncpy(textAreaStatusBuffer,"Failed",TEXTAREASTATUS_SIZE);
			textAreaStatus.invalidate();
		}
		else
		{
		    retVal = establishConnectionWithAP();
		    if(retVal < 0)
		    {
		    	Unicode::strncpy(textAreaStatusBuffer,"Failed",TEXTAREASTATUS_SIZE);
		    	textAreaStatus.invalidate();
		    }
		    else
		    {

		    	retVal = getWeather();
		        if(retVal < 0)
		        {
		        	Unicode::strncpy(textAreaStatusBuffer,"Failed",TEXTAREASTATUS_SIZE);
		        	textAreaStatus.invalidate();
		        }
		        else
		        {
		        	extractData(city,temperature,weather,icon);
		        	Unicode::strncpy(textAreaCityBuffer,city,TEXTAREACITY_SIZE);
		        	Unicode::strncpy(textAreaTempBuffer,temperature,TEXTAREATEMP_SIZE);
		        	Unicode::strncpy(textAreaWeatherBuffer,weather,TEXTAREAWEATHER_SIZE);

		        	textAreaCity.invalidate();
		        	textAreaTemp.invalidate();
					textAreaWeather.invalidate();
					setIcon(icon);
		        }
		        retVal = disconnectFromAP();
		        if(retVal < 0) Unicode::strncpy(textAreaStatusBuffer,"Failed",TEXTAREASTATUS_SIZE);
		        else Unicode::strncpy(textAreaStatusBuffer,"OK",TEXTAREASTATUS_SIZE);


		    }
		}
    }
    textAreaStatus.invalidate();
}
void WEATHERView::sendInfoViaCLI()
{
	WIFI_Exec();
}

void WEATHERView::setIcon(const char *icon)
{
	uint16_t bmp_id;

	if(strcmp(icon,"01d")==0)bmp_id=BITMAP_D01_ID;
	else if(strcmp(icon,"01n")==0)bmp_id=BITMAP_N01_ID;
	else if(strcmp(icon,"02d")==0)bmp_id=BITMAP_D02_ID;
	else if(strcmp(icon,"02n")==0)bmp_id=BITMAP_N02_ID;
	else if(strcmp(icon,"10d")==0)bmp_id=BITMAP_D10_ID;
	else if(strcmp(icon,"10n")==0)bmp_id=BITMAP_N10_ID;
	else if((strcmp(icon,"03d")==0) || (strcmp(icon,"03n")==0))bmp_id=BITMAP_D03_ID;
	else if((strcmp(icon,"04d")==0) || (strcmp(icon,"04n")==0))bmp_id=BITMAP_D04_ID;
	else if((strcmp(icon,"09d")==0) || (strcmp(icon,"09n")==0))bmp_id=BITMAP_D09_ID;
	else if((strcmp(icon,"11d")==0) || (strcmp(icon,"11n")==0))bmp_id=BITMAP_D11_ID;
	else if((strcmp(icon,"13d")==0) || (strcmp(icon,"13n")==0))bmp_id=BITMAP_D13_ID;
	else if((strcmp(icon,"50d")==0) || (strcmp(icon,"50n")==0))bmp_id=BITMAP_D50_ID;
	else bmp_id=BITMAP_D01_ID;

	Bitmap::cache(bmp_id);
	imageWeather.setBitmap(touchgfx::Bitmap(bmp_id));
	imageWeather.invalidate();

}
void WEATHERView::tearDownScreen()
{
	Bitmap::clearCache();
    WEATHERViewBase::tearDownScreen();
}
