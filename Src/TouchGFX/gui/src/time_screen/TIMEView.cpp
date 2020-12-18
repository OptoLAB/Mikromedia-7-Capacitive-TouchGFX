#include <gui/time_screen/TIMEView.hpp>
#include <BitmapDatabase.hpp>
#include <stdio.h>

TIMEView::TIMEView()
{

}

void TIMEView::setupScreen()
{
	Bitmap::cache(BITMAP_BLUE_CLOCKS_BACKGROUNDS_CLOCK_STANDARD_BACKGROUND_ID);
	Bitmap::cache(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_HOUR_HAND_ID);
	Bitmap::cache(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_MINUTE_HAND_ID);
	Bitmap::cache(BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_SECOND_HAND_ID);

    TIMEViewBase::setupScreen();
}

void TIMEView::tearDownScreen()
{
	Bitmap::clearCache();

    TIMEViewBase::tearDownScreen();
}
//TIME-------------------------------------------------------------------------------
void TIMEView::scrollWheelHoursUpdateItem(wheelElement& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void TIMEView::scrollWheelHoursUpdateCenterItem(wheelElementSet& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void TIMEView::scrollWheelMinutesUpdateItem(wheelElement& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void TIMEView::scrollWheelMinutesUpdateCenterItem(wheelElementSet& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void TIMEView::scrollWheelSecondsUpdateItem(wheelElement& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void TIMEView::scrollWheelSecondsUpdateCenterItem(wheelElementSet& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
//DATE---------------------------------------------------------------------------------
void TIMEView::scrollWheelWeekDaysUpdateItem(wheelElement1& item, int16_t itemIndex)
{
	item.setText(date_weekday[itemIndex]);
}
void TIMEView::scrollWheelWeekDaysUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex)
{
	item.setText(date_weekday[itemIndex]);
}

void TIMEView::scrollWheelYearsUpdateItem(wheelElement1& item, int16_t itemIndex)
{
	char temp[3];
	sprintf((char*)temp,"%02d",(itemIndex));
	item.setText(temp);
}
void TIMEView::scrollWheelYearsUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex)
{
	char temp[3];
	sprintf((char*)temp,"%02d",(itemIndex));
	item.setText(temp);
}

void TIMEView::scrollWheelDaysUpdateItem(wheelElement1& item, int16_t itemIndex)
{
	char temp[3];
	sprintf((char*)temp,"%02d",(itemIndex+1));
	item.setText(temp);
}
void TIMEView::scrollWheelDaysUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex)
{
	char temp[3];
	sprintf((char*)temp,"%02d",(itemIndex+1));
	item.setText(temp);
}

void TIMEView::scrollWheelMonthsUpdateItem(wheelElement1& item, int16_t itemIndex)
{
	item.setText(date_months[itemIndex]);
}
void TIMEView::scrollWheelMonthsUpdateCenterItem(wheelElementSet1& item, int16_t itemIndex)
{
	item.setText(date_months[itemIndex]);
}
void TIMEView::setupTimeMenu()
{
	date_time=1;

	containerDate.setVisible(false);
	containerTime.setVisible(true);

    modalWindow1.setVisible(true);
    modalWindow1.invalidate();
}
void TIMEView::setupDateMenu()
{
	date_time=0;

	containerDate.setVisible(true);
	containerTime.setVisible(false);

    modalWindow1.setVisible(true);
    modalWindow1.invalidate();
}
void TIMEView::setDateTime()
{
	if(date_time)
	{
		time.hours=scrollWheelHours.getSelectedItem();
		time.minutes=scrollWheelMinutes.getSelectedItem();
		time.seconds=scrollWheelSeconds.getSelectedItem();
		INTERNAL_SetTime(time);
	}
	else
	{
		date.days=scrollWheelDays.getSelectedItem()+1;
		date.months=scrollWheelMonths.getSelectedItem()+1;
		date.years=scrollWheelYears.getSelectedItem();
		date.weekDay=scrollWheelWeekDays.getSelectedItem()+1;
		INTERNAL_SetDate(date);
	}

    modalWindow1.setVisible(false);
    modalWindow1.invalidate();
}
void TIMEView::handleTickEvent()
{
	ticks++;
	if(!(ticks%8))
	{
		time=INTERNAL_GetTime();

		digitalClock.setTime24Hour(time.hours, time.minutes, time.seconds);
		digitalClock.invalidate();

		analogClock.setTime24Hour(time.hours, time.minutes, time.seconds);
		analogClock.invalidate();

		date=INTERNAL_GetDate();

		Unicode::snprintf(textAreaDateBuffer,TEXTAREADATE_SIZE,"%02d/%02d/%02d",date.days,date.months,date.years);
		textAreaDate.invalidate();

		char wd[10];
		switch(date.weekDay)
		{
			case 1: sprintf((char*)wd,"%s",(char*)"Monday");
					break;
			case 2: sprintf((char*)wd,"%s",(char*)"Tuesday");
					break;
			case 3: sprintf((char*)wd,"%s",(char*)"Wednesday");
					break;
			case 4: sprintf((char*)wd,"%s",(char*)"Thursday");
					break;
			case 5: sprintf((char*)wd,"%s",(char*)"Friday");
					break;
			case 6:sprintf((char*)wd,"%s",(char*)"Saturday");
					break;
			case 7: sprintf((char*)wd,"%s",(char*)"Sunday");
					break;

		}
		Unicode::strncpy(textAreaWeekDayBuffer,wd,TEXTAREAWEEKDAY_SIZE);
		textAreaWeekDay.invalidate();
	}
}
