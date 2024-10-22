/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mp3_screen/MP3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

MP3ViewBase::MP3ViewBase() :
    buttonCallback(this, &MP3ViewBase::buttonCallbackHandler),
    sliderValueChangedCallback(this, &MP3ViewBase::sliderValueChangedCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    box1.setPosition(0, 1, 800, 480);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(87, 181, 100));

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_TOPBAR_TOPBAR_BG_800X480PX_ID));

    buttonClose.setXY(740, 1);
    buttonClose.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    buttonClose.setIconXY(16, 16);
    buttonClose.setAction(buttonCallback);

    textArea1.setXY(15, 17);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID40));

    box4.setPosition(29, 445, 756, 25);
    box4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box4.setAlpha(84);

    textArea2.setXY(33, 445);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2Buffer[0] = 0;
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID43));

    box3.setPosition(29, 364, 230, 66);
    box3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box3.setAlpha(84);

    box2.setPosition(363, 96, 420, 334);
    box2.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    box2.setAlpha(84);

    circle1.setPosition(29, 99, 230, 230);
    circle1.setCenter(115, 115);
    circle1.setRadius(115);
    circle1.setLineWidth(0);
    circle1.setArc(0, 360);
    circle1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    circle1.setPainter(circle1Painter);
    circle1.setAlpha(84);

    playProgress.setXY(89, 165);
    playProgress.setProgressIndicatorPosition(0, 0, 104, 104);
    playProgress.setRange(0, 100);
    playProgress.setCenter(52, 52);
    playProgress.setRadius(42);
    playProgress.setLineWidth(16);
    playProgress.setStartEndAngle(0, 360);
    playProgress.setCapPrecision(180);
    playProgress.setBackground(touchgfx::Bitmap(BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_CIRCLE_INDICATOR_BG_LINE_FULL_ID));
    playProgressPainter.setBitmap(touchgfx::Bitmap(BITMAP_DARK_PROGRESSINDICATORS_FILL_MEDIUM_CIRCLE_INDICATOR_FILL_LINE_FULL_ID));
    playProgress.setPainter(playProgressPainter);
    playProgress.setValue(0);

    buttonPlay.setXY(111, 187);
    buttonPlay.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_PLAY_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_PLAY_32_ID));
    buttonPlay.setIconXY(20, 15);
    buttonPlay.setAction(buttonCallback);

    buttonStop.setXY(111, 269);
    buttonStop.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_STOP_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_STOP_32_ID));
    buttonStop.setIconXY(15, 15);
    buttonStop.setAction(buttonCallback);

    buttonPause.setXY(111, 99);
    buttonPause.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_PAUSE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_PAUSE_32_ID));
    buttonPause.setIconXY(18, 15);
    buttonPause.setAction(buttonCallback);

    buttonNext.setXY(196, 187);
    buttonNext.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_GO_NEXT_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_GO_NEXT_32_ID));
    buttonNext.setIconXY(15, 16);
    buttonNext.setAction(buttonCallback);

    buttonPrevious.setXY(29, 187);
    buttonPrevious.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_GO_BACK_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_GO_BACK_32_ID));
    buttonPrevious.setIconXY(15, 16);
    buttonPrevious.setAction(buttonCallback);

    volume.setXY(40, 369);
    volume.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_DARK_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_DARK_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER_ROUND_NOB_ID));
    volume.setupHorizontalSlider(4, 8, 3, 0, 144);
    volume.setValueRange(0, 100);
    volume.setValue(50);
    volume.setNewValueCallback(sliderValueChangedCallback);

    textArea4.setXY(29, 71);
    textArea4.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID155));

    textArea5.setXY(29, 334);
    textArea5.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea5.setLinespacing(0);
    textArea5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID156));

    textArea3.setXY(363, 71);
    textArea3.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea3.setLinespacing(0);
    Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID466).getText());
    textArea3.setWildcard(textArea3Buffer);
    textArea3.resizeToCurrentText();
    textArea3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID463));

    playlistScroll.setPosition(363, 96, 422, 34);
    playlistScroll.setScrollbarsColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    playlist.setDirection(touchgfx::SOUTH);
    playlist.setPosition(0, 0, 250, 250);
    playlistScroll.add(playlist);
    playlistScroll.setScrollbarsPermanentlyVisible();
    playlistScroll.setScrollbarsVisible(false);

    add(box1);
    add(image1);
    add(buttonClose);
    add(textArea1);
    add(box4);
    add(textArea2);
    add(box3);
    add(box2);
    add(circle1);
    add(playProgress);
    add(buttonPlay);
    add(buttonStop);
    add(buttonPause);
    add(buttonNext);
    add(buttonPrevious);
    add(volume);
    add(textArea4);
    add(textArea5);
    add(textArea3);
    add(playlistScroll);
}

void MP3ViewBase::setupScreen()
{

}

void MP3ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonClose)
    {
        //Interaction1
        //When buttonClose clicked change screen to MAIN_MENU
        //Go to MAIN_MENU with screen transition towards East
        application().gotoMAIN_MENUScreenSlideTransitionEast();
    }
    else if (&src == &buttonPlay)
    {
        //Interaction3
        //When buttonPlay clicked call virtual function
        //Call playSong
        playSong();
    }
    else if (&src == &buttonStop)
    {
        //Interaction4
        //When buttonStop clicked call virtual function
        //Call stopSong
        stopSong();
    }
    else if (&src == &buttonPause)
    {
        //Interaction7
        //When buttonPause clicked call virtual function
        //Call pauseSong
        pauseSong();
    }
    else if (&src == &buttonNext)
    {
        //Interaction5
        //When buttonNext clicked call virtual function
        //Call nextSong
        nextSong();
    }
    else if (&src == &buttonPrevious)
    {
        //Interaction6
        //When buttonPrevious clicked call virtual function
        //Call previousSong
        previousSong();
    }
}

void MP3ViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &volume)
    {
        //Interaction8
        //When volume value changed call virtual function
        //Call setVolume
        setVolume(value);
    }
}
