#ifndef TIMEVIEW_HPP
#define TIMEVIEW_HPP

#include <gui_generated/time_screen/TIMEViewBase.hpp>
#include <gui/time_screen/TIMEPresenter.hpp>

extern "C" {
#include "internal/internal.h"
}

class TIMEView : public TIMEViewBase
{
public:
    TIMEView();
    virtual ~TIMEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void setDateTime();
    virtual void setupTimeMenu();
    virtual void setupDateMenu();

    //time scroll wheels
    virtual void scrollWheelHoursUpdateItem(wheelElement& item, int16_t itemIndex);
    virtual void scrollWheelHoursUpdateCenterItem(wheelElementSet& item, int16_t itemIndex);

    virtual void scrollWheelMinutesUpdateItem(wheelElement& item, int16_t itemIndex);
    virtual void scrollWheelMinutesUpdateCenterItem(wheelElementSet& item, int16_t itemIndex);

    virtual void scrollWheelSecondsUpdateItem(wheelElement& item, int16_t itemIndex);
    virtual void scrollWheelSecondsUpdateCenterItem(wheelElementSet& item, int16_t itemIndex);

    //date scroll wheels

    virtual void scrollWheelWeekDaysUpdateItem(wheelElement1& item, int16_t itemIndex);
    virtual void scrollWheelWeekDaysUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex);

    virtual void scrollWheelYearsUpdateItem(wheelElement1& item, int16_t itemIndex);
    virtual void scrollWheelYearsUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex);

    virtual void scrollWheelDaysUpdateItem(wheelElement1& item, int16_t itemIndex);
    virtual void scrollWheelDaysUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex);

    virtual void scrollWheelMonthsUpdateItem(wheelElement1& item, int16_t itemIndex);
    virtual void scrollWheelMonthsUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex);

protected:
private:
    const char date_months[12][4]={"Jan","Feb","Mar", "Apr", "May", "Jun", "Jul", "Avg", "Sep", "Oct", "Nov", "Dec"};
    const char date_weekday[7][3]={"Mo","Tu","We", "Th", "Fr", "Sa", "Su"};
    RTC_time time;
    RTC_date date;
    uint8_t date_time=1;
    uint8_t ticks;
};

#endif // TIMEVIEW_HPP
