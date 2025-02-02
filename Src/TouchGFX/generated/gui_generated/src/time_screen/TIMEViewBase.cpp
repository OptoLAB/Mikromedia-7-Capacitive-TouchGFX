/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/time_screen/TIMEViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

TIMEViewBase::TIMEViewBase() :
    buttonCallback(this, &TIMEViewBase::buttonCallbackHandler),
    updateItemCallback(this, &TIMEViewBase::updateItemCallbackHandler)
{

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(44, 50, 66));

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_TOPBAR_TOPBAR_BG_800X480PX_ID));

    buttonClose.setXY(740, 1);
    buttonClose.setBitmaps(touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_DARK_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    buttonClose.setIconXY(16, 16);
    buttonClose.setAction(buttonCallback);

    buttonSetTime.setXY(32, 391);
    buttonSetTime.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonSetTime.setLabelText(touchgfx::TypedText(T_SINGLEUSEID507));
    buttonSetTime.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonSetTime.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonSetTime.setAction(buttonCallback);

    buttonSetDate.setXY(234, 391);
    buttonSetDate.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonSetDate.setLabelText(touchgfx::TypedText(T_SINGLEUSEID508));
    buttonSetDate.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonSetDate.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonSetDate.setAction(buttonCallback);

    boxWithBorder1.setPosition(104, 132, 229, 192);
    boxWithBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(5);
    boxWithBorder1.setAlpha(32);

    textArea1.setXY(14, 17);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID495));

    digitalClock.setPosition(104, 152, 229, 54);
    digitalClock.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    digitalClock.setTypedText(touchgfx::TypedText(T_SINGLEUSEID496));
    digitalClock.displayLeadingZeroForHourIndicator(true);
    digitalClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock.setTime24Hour(10, 10, 0);

    analogClock.setXY(521, 103);
    analogClock.setBackground(BITMAP_BLUE_CLOCKS_BACKGROUNDS_CLOCK_STANDARD_BACKGROUND_ID, 116, 116);
    analogClock.setupSecondHand(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_SECOND_HAND_ID, 3, 66);
    analogClock.setupMinuteHand(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_MINUTE_HAND_ID, 7, 67);
    analogClock.setMinuteHandSecondCorrection(false);
    analogClock.setupHourHand(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_HOUR_HAND_ID, 7, 52);
    analogClock.setHourHandMinuteCorrection(false);
    analogClock.initializeTime24Hour(10, 10, 0);

    textAreaWeekDay.setPosition(152, 228, 124, 25);
    textAreaWeekDay.setColor(touchgfx::Color::getColorFrom24BitRGB(225, 255, 0));
    textAreaWeekDay.setLinespacing(0);
    Unicode::snprintf(textAreaWeekDayBuffer, TEXTAREAWEEKDAY_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID514).getText());
    textAreaWeekDay.setWildcard(textAreaWeekDayBuffer);
    textAreaWeekDay.setTypedText(touchgfx::TypedText(T_SINGLEUSEID513));

    textAreaDate.setPosition(162, 264, 106, 25);
    textAreaDate.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 0));
    textAreaDate.setLinespacing(0);
    Unicode::snprintf(textAreaDateBuffer, TEXTAREADATE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID498).getText());
    textAreaDate.setWildcard(textAreaDateBuffer);
    textAreaDate.setTypedText(touchgfx::TypedText(T_SINGLEUSEID497));

    modalWindow1.setBackground(touchgfx::BitmapId(BITMAP_BLUE_BACKGROUNDS_MAIN_BG_320X240PX_ID), 240, 120);
    modalWindow1.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    modalWindow1.setShadeAlpha(150);
    modalWindow1.hide();

    buttonCANCEL.setXY(207, 174);
    buttonCANCEL.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    buttonCANCEL.setIconXY(16, 16);
    buttonCANCEL.setAction(buttonCallback);
    modalWindow1.add(buttonCANCEL);

    buttonOK.setXY(53, 174);
    buttonOK.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_DONE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_DONE_32_ID));
    buttonOK.setIconXY(15, 15);
    buttonOK.setAction(buttonCallback);
    modalWindow1.add(buttonOK);

    containerTime.setPosition(53, 11, 214, 130);

    scrollWheelHours.setPosition(1, 0, 60, 130);
    scrollWheelHours.setHorizontal(false);
    scrollWheelHours.setCircular(true);
    scrollWheelHours.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelHours.setSwipeAcceleration(10);
    scrollWheelHours.setDragAcceleration(10);
    scrollWheelHours.setNumberOfItems(24);
    scrollWheelHours.setSelectedItemOffset(42);
    scrollWheelHours.setSelectedItemExtraSize(0, 0);
    scrollWheelHours.setSelectedItemMargin(0, 0);
    scrollWheelHours.setDrawableSize(42, 0);
    scrollWheelHours.setDrawables(scrollWheelHoursListItems, updateItemCallback,
                              scrollWheelHoursSelectedListItems, updateItemCallback);
    scrollWheelHours.animateToItem(0, 0);
    containerTime.add(scrollWheelHours);

    scrollWheelMinutes.setPosition(77, 0, 60, 130);
    scrollWheelMinutes.setHorizontal(false);
    scrollWheelMinutes.setCircular(true);
    scrollWheelMinutes.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelMinutes.setSwipeAcceleration(10);
    scrollWheelMinutes.setDragAcceleration(10);
    scrollWheelMinutes.setNumberOfItems(60);
    scrollWheelMinutes.setSelectedItemOffset(42);
    scrollWheelMinutes.setSelectedItemExtraSize(0, 0);
    scrollWheelMinutes.setSelectedItemMargin(0, 0);
    scrollWheelMinutes.setDrawableSize(42, 0);
    scrollWheelMinutes.setDrawables(scrollWheelMinutesListItems, updateItemCallback,
                              scrollWheelMinutesSelectedListItems, updateItemCallback);
    scrollWheelMinutes.animateToItem(0, 0);
    containerTime.add(scrollWheelMinutes);

    scrollWheelSeconds.setPosition(154, 0, 60, 130);
    scrollWheelSeconds.setHorizontal(false);
    scrollWheelSeconds.setCircular(true);
    scrollWheelSeconds.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelSeconds.setSwipeAcceleration(10);
    scrollWheelSeconds.setDragAcceleration(10);
    scrollWheelSeconds.setNumberOfItems(60);
    scrollWheelSeconds.setSelectedItemOffset(42);
    scrollWheelSeconds.setSelectedItemExtraSize(0, 0);
    scrollWheelSeconds.setSelectedItemMargin(0, 0);
    scrollWheelSeconds.setDrawableSize(42, 0);
    scrollWheelSeconds.setDrawables(scrollWheelSecondsListItems, updateItemCallback,
                              scrollWheelSecondsSelectedListItems, updateItemCallback);
    scrollWheelSeconds.animateToItem(0, 0);
    containerTime.add(scrollWheelSeconds);

    textArea2.setXY(62, 42);
    textArea2.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID505));
    containerTime.add(textArea2);

    textArea3.setXY(139, 42);
    textArea3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID506));
    containerTime.add(textArea3);
    modalWindow1.add(containerTime);

    containerDate.setPosition(2, -2, 316, 166);
    containerDate.setVisible(false);

    scrollWheelWeekDays.setPosition(244, 4, 47, 153);
    scrollWheelWeekDays.setHorizontal(false);
    scrollWheelWeekDays.setCircular(true);
    scrollWheelWeekDays.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelWeekDays.setSwipeAcceleration(10);
    scrollWheelWeekDays.setDragAcceleration(10);
    scrollWheelWeekDays.setNumberOfItems(7);
    scrollWheelWeekDays.setSelectedItemOffset(62);
    scrollWheelWeekDays.setSelectedItemExtraSize(0, 0);
    scrollWheelWeekDays.setSelectedItemMargin(0, 0);
    scrollWheelWeekDays.setDrawableSize(29, 0);
    scrollWheelWeekDays.setDrawables(scrollWheelWeekDaysListItems, updateItemCallback,
                              scrollWheelWeekDaysSelectedListItems, updateItemCallback);
    scrollWheelWeekDays.animateToItem(0, 0);
    containerDate.add(scrollWheelWeekDays);

    scrollWheelYears.setPosition(169, 4, 47, 150);
    scrollWheelYears.setHorizontal(false);
    scrollWheelYears.setCircular(true);
    scrollWheelYears.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelYears.setSwipeAcceleration(10);
    scrollWheelYears.setDragAcceleration(10);
    scrollWheelYears.setNumberOfItems(100);
    scrollWheelYears.setSelectedItemOffset(62);
    scrollWheelYears.setSelectedItemExtraSize(0, 0);
    scrollWheelYears.setSelectedItemMargin(0, 0);
    scrollWheelYears.setDrawableSize(29, 0);
    scrollWheelYears.setDrawables(scrollWheelYearsListItems, updateItemCallback,
                              scrollWheelYearsSelectedListItems, updateItemCallback);
    scrollWheelYears.animateToItem(0, 0);
    containerDate.add(scrollWheelYears);

    scrollWheelDays.setPosition(24, 4, 47, 153);
    scrollWheelDays.setHorizontal(false);
    scrollWheelDays.setCircular(true);
    scrollWheelDays.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelDays.setSwipeAcceleration(10);
    scrollWheelDays.setDragAcceleration(10);
    scrollWheelDays.setNumberOfItems(31);
    scrollWheelDays.setSelectedItemOffset(62);
    scrollWheelDays.setSelectedItemExtraSize(0, 0);
    scrollWheelDays.setSelectedItemMargin(0, 0);
    scrollWheelDays.setDrawableSize(29, 0);
    scrollWheelDays.setDrawables(scrollWheelDaysListItems, updateItemCallback,
                              scrollWheelDaysSelectedListItems, updateItemCallback);
    scrollWheelDays.animateToItem(0, 0);
    containerDate.add(scrollWheelDays);

    scrollWheelMonths.setPosition(96, 4, 47, 153);
    scrollWheelMonths.setHorizontal(false);
    scrollWheelMonths.setCircular(true);
    scrollWheelMonths.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheelMonths.setSwipeAcceleration(10);
    scrollWheelMonths.setDragAcceleration(10);
    scrollWheelMonths.setNumberOfItems(12);
    scrollWheelMonths.setSelectedItemOffset(62);
    scrollWheelMonths.setSelectedItemExtraSize(0, 0);
    scrollWheelMonths.setSelectedItemMargin(0, 0);
    scrollWheelMonths.setDrawableSize(29, 0);
    scrollWheelMonths.setDrawables(scrollWheelMonthsListItems, updateItemCallback,
                              scrollWheelMonthsSelectedListItems, updateItemCallback);
    scrollWheelMonths.animateToItem(0, 0);
    containerDate.add(scrollWheelMonths);
    modalWindow1.add(containerDate);

    add(box1);
    add(image1);
    add(buttonClose);
    add(buttonSetTime);
    add(buttonSetDate);
    add(boxWithBorder1);
    add(textArea1);
    add(digitalClock);
    add(analogClock);
    add(textAreaWeekDay);
    add(textAreaDate);
    add(modalWindow1);
}

void TIMEViewBase::setupScreen()
{
    scrollWheelHours.initialize();
    for (int i = 0; i < scrollWheelHoursListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelHoursListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelHoursSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelHoursSelectedListItems[i].initialize();
    }
    scrollWheelMinutes.initialize();
    for (int i = 0; i < scrollWheelMinutesListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelMinutesListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelMinutesSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelMinutesSelectedListItems[i].initialize();
    }
    scrollWheelSeconds.initialize();
    for (int i = 0; i < scrollWheelSecondsListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelSecondsListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelSecondsSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelSecondsSelectedListItems[i].initialize();
    }
    scrollWheelWeekDays.initialize();
    for (int i = 0; i < scrollWheelWeekDaysListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelWeekDaysListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelWeekDaysSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelWeekDaysSelectedListItems[i].initialize();
    }
    scrollWheelYears.initialize();
    for (int i = 0; i < scrollWheelYearsListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelYearsListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelYearsSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelYearsSelectedListItems[i].initialize();
    }
    scrollWheelDays.initialize();
    for (int i = 0; i < scrollWheelDaysListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelDaysListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelDaysSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelDaysSelectedListItems[i].initialize();
    }
    scrollWheelMonths.initialize();
    for (int i = 0; i < scrollWheelMonthsListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelMonthsListItems[i].initialize();
    }
    for (int i = 0; i < scrollWheelMonthsSelectedListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelMonthsSelectedListItems[i].initialize();
    }
}

void TIMEViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonClose)
    {
        //Interaction1
        //When buttonClose clicked change screen to MAIN_MENU
        //Go to MAIN_MENU with no screen transition
        application().gotoMAIN_MENUScreenNoTransition();
    }
    else if (&src == &buttonSetTime)
    {
        //Interaction3
        //When buttonSetTime clicked call virtual function
        //Call setupTimeMenu
        setupTimeMenu();
    }
    else if (&src == &buttonSetDate)
    {
        //Interaction5
        //When buttonSetDate clicked call virtual function
        //Call setupDateMenu
        setupDateMenu();
    }
    else if (&src == &buttonCANCEL)
    {
        //Interaction2
        //When buttonCANCEL clicked hide modalWindow1
        //Hide modalWindow1
        modalWindow1.setVisible(false);
        modalWindow1.invalidate();
    }
    else if (&src == &buttonOK)
    {
        //Interaction4
        //When buttonOK clicked call virtual function
        //Call setDateTime
        setDateTime();
    }
}

void TIMEViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollWheelHoursListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement* cc = (wheelElement*)d;
        scrollWheelHoursUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelHoursSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet* cc = (wheelElementSet*)d;
        scrollWheelHoursUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelMinutesListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement* cc = (wheelElement*)d;
        scrollWheelMinutesUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelMinutesSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet* cc = (wheelElementSet*)d;
        scrollWheelMinutesUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelSecondsListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement* cc = (wheelElement*)d;
        scrollWheelSecondsUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelSecondsSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet* cc = (wheelElementSet*)d;
        scrollWheelSecondsUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelWeekDaysListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement1* cc = (wheelElement1*)d;
        scrollWheelWeekDaysUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelWeekDaysSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet1* cc = (wheelElementSet1*)d;
        scrollWheelWeekDaysUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelYearsListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement1* cc = (wheelElement1*)d;
        scrollWheelYearsUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelYearsSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet1* cc = (wheelElementSet1*)d;
        scrollWheelYearsUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelDaysListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement1* cc = (wheelElement1*)d;
        scrollWheelDaysUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelDaysSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet1* cc = (wheelElementSet1*)d;
        scrollWheelDaysUpdateCenterItem(*cc, itemIndex);
    }
    if (items == &scrollWheelMonthsListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElement1* cc = (wheelElement1*)d;
        scrollWheelMonthsUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelMonthsSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        wheelElementSet1* cc = (wheelElementSet1*)d;
        scrollWheelMonthsUpdateCenterItem(*cc, itemIndex);
    }
}
