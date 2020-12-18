#ifndef WEATHERVIEW_HPP
#define WEATHERVIEW_HPP

#include <gui_generated/weather_screen/WEATHERViewBase.hpp>
#include <gui/weather_screen/WEATHERPresenter.hpp>

class WEATHERView : public WEATHERViewBase
{
public:
    WEATHERView();
    virtual ~WEATHERView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateWeather();
    virtual void sendInfoViaCLI();
    virtual void setIcon(const char *icon);
protected:
    char city[20];
    char temperature[6];
    char weather[20];
    char icon[5];
};

#endif // WEATHERVIEW_HPP
