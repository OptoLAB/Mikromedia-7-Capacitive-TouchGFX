/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/accel_screen/ACCELViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

ACCELViewBase::ACCELViewBase() :
    buttonCallback(this, &ACCELViewBase::buttonCallbackHandler),
    radioButtonSelectedCallback(this, &ACCELViewBase::radioButtonSelectedCallbackHandler),
    radioButtonDeselectedCallback(this, &ACCELViewBase::radioButtonDeselectedCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    box1.setPosition(1, 1, 800, 480);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(232, 196, 125));

    box4.setPosition(549, 214, 216, 256);
    box4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box4.setAlpha(70);

    box3.setPosition(29, 162, 512, 308);
    box3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box3.setAlpha(70);

    box5.setPosition(549, 94, 216, 113);
    box5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box5.setAlpha(70);

    box6.setPosition(29, 96, 512, 59);
    box6.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box6.setAlpha(70);

    box2.setPosition(42, 177, 486, 279);
    box2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_TOPBAR_TOPBAR_BG_800X480PX_ID));

    imageGraph.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_ID));
    imageGraph.setPosition(45, 180, 480, 273);
    imageGraph.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    buttonClose.setXY(740, 1);
    buttonClose.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    buttonClose.setIconXY(16, 16);
    buttonClose.setAction(buttonCallback);

    textAreaX.setXY(48, 182);
    textAreaX.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 172));
    textAreaX.setLinespacing(0);
    Unicode::snprintf(textAreaXBuffer, TEXTAREAX_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID11).getText());
    textAreaX.setWildcard(textAreaXBuffer);
    textAreaX.resizeToCurrentText();
    textAreaX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID10));

    textAreaY.setXY(256, 182);
    textAreaY.setColor(touchgfx::Color::getColorFrom24BitRGB(172, 255, 255));
    textAreaY.setLinespacing(0);
    Unicode::snprintf(textAreaYBuffer, TEXTAREAY_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID13).getText());
    textAreaY.setWildcard(textAreaYBuffer);
    textAreaY.resizeToCurrentText();
    textAreaY.setTypedText(touchgfx::TypedText(T_SINGLEUSEID12));

    textAreaZ.setXY(434, 182);
    textAreaZ.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 172, 255));
    textAreaZ.setLinespacing(0);
    Unicode::snprintf(textAreaZBuffer, TEXTAREAZ_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID15).getText());
    textAreaZ.setWildcard(textAreaZBuffer);
    textAreaZ.resizeToCurrentText();
    textAreaZ.setTypedText(touchgfx::TypedText(T_SINGLEUSEID14));

    radioButtonHPfiltar.setXY(563, 143);
    radioButtonHPfiltar.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_NORMAL_ID));
    radioButtonHPfiltar.setSelected(false);
    radioButtonHPfiltar.setDeselectionEnabled(true);

    textArea1.setXY(703, 153);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_TEXTOFF));

    textArea2.setXY(615, 153);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID16));

    radioButtonMag.setXY(41, 103);
    radioButtonMag.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_CHECK_BUTTONS_CHECK_RE_MARK_NORMAL_ID));
    radioButtonMag.setSelected(false);
    radioButtonMag.setDeselectionEnabled(true);

    textArea3.setXY(106, 113);
    textArea3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID18));

    textArea4.setXY(15, 18);
    textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID19));

    radioButtonRange2g.setXY(569, 261);
    radioButtonRange2g.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_NORMAL_ID));
    radioButtonRange2g.setSelected(false);
    radioButtonRange2g.setDeselectionEnabled(false);

    textArea2g.setXY(621, 271);
    textArea2g.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2g.setLinespacing(0);
    textArea2g.setTypedText(touchgfx::TypedText(T_SINGLEUSEID20));

    radioButtonRange4g.setXY(569, 318);
    radioButtonRange4g.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_NORMAL_ID));
    radioButtonRange4g.setSelected(false);
    radioButtonRange4g.setDeselectionEnabled(false);

    textArea4g.setXY(621, 328);
    textArea4g.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea4g.setLinespacing(0);
    textArea4g.setTypedText(touchgfx::TypedText(T_SINGLEUSEID21));

    radioButtonRange8g.setXY(569, 374);
    radioButtonRange8g.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_INACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_ACTIVE_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_RE_BUTTON_NORMAL_ID));
    radioButtonRange8g.setSelected(true);
    radioButtonRange8g.setDeselectionEnabled(false);

    textArea8g.setXY(621, 384);
    textArea8g.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea8g.setLinespacing(0);
    textArea8g.setTypedText(touchgfx::TypedText(T_SINGLEUSEID22));

    textArea6.setXY(572, 225);
    textArea6.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea6.setLinespacing(0);
    textArea6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID23));

    textArea7.setXY(566, 110);
    textArea7.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea7.setLinespacing(0);
    textArea7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID24));

    add(box1);
    add(box4);
    add(box3);
    add(box5);
    add(box6);
    add(box2);
    add(image1);
    add(imageGraph);
    add(buttonClose);
    add(textAreaX);
    add(textAreaY);
    add(textAreaZ);
    add(radioButtonHPfiltar);
    add(textArea1);
    add(textArea2);
    add(radioButtonMag);
    add(textArea3);
    add(textArea4);
    add(radioButtonRange2g);
    add(textArea2g);
    add(radioButtonRange4g);
    add(textArea4g);
    add(radioButtonRange8g);
    add(textArea8g);
    add(textArea6);
    add(textArea7);
    radioButtonGroup1.add(radioButtonHPfiltar);
    radioButtonGroup3.add(radioButtonMag);
    radioButtonGroup2.add(radioButtonRange2g);
    radioButtonGroup2.add(radioButtonRange4g);
    radioButtonGroup2.add(radioButtonRange8g);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup3.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup2.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
    radioButtonGroup1.setRadioButtonDeselectedHandler(radioButtonDeselectedCallback);
    radioButtonGroup3.setRadioButtonDeselectedHandler(radioButtonDeselectedCallback);
}

void ACCELViewBase::setupScreen()
{

}

void ACCELViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonClose)
    {
        //Interaction1
        //When buttonClose clicked change screen to MAIN_MENU
        //Go to MAIN_MENU with no screen transition
        application().gotoMAIN_MENUScreenNoTransition();
    }
}

void ACCELViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonHPfiltar)
    {
        //Interaction2
        //When radioButtonHPfiltar selected call virtual function
        //Call setHPfiltar
        setHPfiltar();
    }
    else if (&src == &radioButtonMag)
    {
        //Interaction5
        //When radioButtonMag selected call virtual function
        //Call setMagMode
        setMagMode();
    }
    else if (&src == &radioButtonRange2g)
    {
        //Interaction6
        //When radioButtonRange2g selected call virtual function
        //Call setRange
        setRange();
    }
    else if (&src == &radioButtonRange4g)
    {
        //Interaction7
        //When radioButtonRange4g selected call virtual function
        //Call setRange
        setRange();
    }
    else if (&src == &radioButtonRange8g)
    {
        //Interaction8
        //When radioButtonRange8g selected call virtual function
        //Call setRange
        setRange();
    }
}

void ACCELViewBase::radioButtonDeselectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonHPfiltar)
    {
        //Interaction3
        //When radioButtonHPfiltar deselected call virtual function
        //Call resetHPfiltar
        resetHPfiltar();
    }
    else if (&src == &radioButtonMag)
    {
        //Interaction4
        //When radioButtonMag deselected call virtual function
        //Call setAccelMode
        setAccelMode();
    }
}