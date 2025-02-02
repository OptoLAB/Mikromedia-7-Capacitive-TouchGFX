/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/weather_screen/WEATHERViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

WEATHERViewBase::WEATHERViewBase() :
    buttonCallback(this, &WEATHERViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &WEATHERViewBase::flexButtonCallbackHandler)
{

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(59, 215, 255));

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_TOPBAR_TOPBAR_BG_800X480PX_ID));

    buttonClose.setXY(740, 0);
    buttonClose.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    buttonClose.setIconXY(16, 16);
    buttonClose.setAction(buttonCallback);

    boxWithBorder1.setPosition(99, 118, 329, 188);
    boxWithBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 112, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 112, 255));
    boxWithBorder1.setBorderSize(5);
    boxWithBorder1.setAlpha(168);

    textArea1.setXY(15, 17);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID546));

    imageWeather.setXY(106, 155);
    imageWeather.setBitmap(touchgfx::Bitmap(BITMAP_D01_ID));

    textAreaInfo.setXY(15, 442);
    textAreaInfo.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textAreaInfo.setLinespacing(0);
    textAreaInfo.setTypedText(touchgfx::TypedText(T_SINGLEUSEID547));

    textAreaCity.setPosition(131, 131, 461, 24);
    textAreaCity.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textAreaCity.setLinespacing(0);
    Unicode::snprintf(textAreaCityBuffer, TEXTAREACITY_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID554).getText());
    textAreaCity.setWildcard(textAreaCityBuffer);
    textAreaCity.setTypedText(touchgfx::TypedText(T_SINGLEUSEID548));

    textAreaTemp.setPosition(227, 194, 134, 51);
    textAreaTemp.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 246, 0));
    textAreaTemp.setLinespacing(0);
    Unicode::snprintf(textAreaTempBuffer, TEXTAREATEMP_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID553).getText());
    textAreaTemp.setWildcard(textAreaTempBuffer);
    textAreaTemp.setTypedText(touchgfx::TypedText(T_SINGLEUSEID549));

    textAreaWeather.setPosition(131, 277, 461, 29);
    textAreaWeather.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textAreaWeather.setLinespacing(0);
    Unicode::snprintf(textAreaWeatherBuffer, TEXTAREAWEATHER_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID555).getText());
    textAreaWeather.setWildcard(textAreaWeatherBuffer);
    textAreaWeather.setTypedText(touchgfx::TypedText(T_SINGLEUSEID550));

    textAreaStatus.setXY(519, 85);
    textAreaStatus.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textAreaStatus.setLinespacing(0);
    Unicode::snprintf(textAreaStatusBuffer, TEXTAREASTATUS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID552).getText());
    textAreaStatus.setWildcard(textAreaStatusBuffer);
    textAreaStatus.resizeToCurrentText();
    textAreaStatus.setTypedText(touchgfx::TypedText(T_SINGLEUSEID551));

    textAreaUnit.setXY(367, 194);
    textAreaUnit.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 246, 6));
    textAreaUnit.setLinespacing(0);
    textAreaUnit.setTypedText(touchgfx::TypedText(T_SINGLEUSEID556));

    buttonRefresh.setBoxWithBorderPosition(0, 0, 188, 188);
    buttonRefresh.setBorderSize(5);
    buttonRefresh.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(255, 110, 80), touchgfx::Color::getColorFrom24BitRGB(160, 70, 50), touchgfx::Color::getColorFrom24BitRGB(255, 110, 80), touchgfx::Color::getColorFrom24BitRGB(160, 70, 50));
    buttonRefresh.setIconBitmaps(Bitmap(BITMAP_BLUE_ICONS_REFRESH_48_ID), Bitmap(BITMAP_BLUE_ICONS_REFRESH_48_ID));
    buttonRefresh.setIconXY(70, 40);
    buttonRefresh.setText(TypedText(T_SINGLEUSEID557));
    buttonRefresh.setTextPosition(0, 134, 188, 188);
    buttonRefresh.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonRefresh.setPosition(519, 118, 188, 188);
    buttonRefresh.setAction(flexButtonCallback);

    textAreaCurrent.setXY(99, 85);
    textAreaCurrent.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textAreaCurrent.setLinespacing(0);
    textAreaCurrent.setTypedText(touchgfx::TypedText(T_SINGLEUSEID558));

    buttonDebug.setBoxWithBorderPosition(0, 0, 188, 52);
    buttonDebug.setBorderSize(5);
    buttonDebug.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(255, 110, 80), touchgfx::Color::getColorFrom24BitRGB(160, 70, 50), touchgfx::Color::getColorFrom24BitRGB(255, 110, 80), touchgfx::Color::getColorFrom24BitRGB(160, 70, 50));
    buttonDebug.setIconBitmaps(Bitmap(BITMAP_BLUE_ICONS_TOOLS_32_ID), Bitmap(BITMAP_BLUE_ICONS_TOOLS_32_ID));
    buttonDebug.setIconXY(16, 14);
    buttonDebug.setText(TypedText(T_SINGLEUSEID559));
    buttonDebug.setTextPosition(13, 13, 188, 52);
    buttonDebug.setTextColors(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255), touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonDebug.setPosition(519, 340, 188, 52);
    buttonDebug.setAction(flexButtonCallback);

    add(box1);
    add(image1);
    add(buttonClose);
    add(boxWithBorder1);
    add(textArea1);
    add(imageWeather);
    add(textAreaInfo);
    add(textAreaCity);
    add(textAreaTemp);
    add(textAreaWeather);
    add(textAreaStatus);
    add(textAreaUnit);
    add(buttonRefresh);
    add(textAreaCurrent);
    add(buttonDebug);
}

void WEATHERViewBase::setupScreen()
{

}

void WEATHERViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonClose)
    {
        //Interaction1
        //When buttonClose clicked change screen to MAIN_MENU
        //Go to MAIN_MENU with no screen transition
        application().gotoMAIN_MENUScreenNoTransition();
    }
}

void WEATHERViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &buttonRefresh)
    {
        //Interaction2
        //When buttonRefresh clicked call virtual function
        //Call updateWeather
        updateWeather();
    }
    else if (&src == &buttonDebug)
    {
        //Interaction3
        //When buttonDebug clicked call virtual function
        //Call sendInfoViaCLI
        sendInfoViaCLI();
    }
}
