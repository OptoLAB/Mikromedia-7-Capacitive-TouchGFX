#ifndef RGB_LEDVIEW_HPP
#define RGB_LEDVIEW_HPP

#include <gui_generated/rgb_led_screen/RGB_LEDViewBase.hpp>
#include <gui/rgb_led_screen/RGB_LEDPresenter.hpp>

class RGB_LEDView : public RGB_LEDViewBase
{
public:
    RGB_LEDView();
    virtual ~RGB_LEDView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setRedLEDValue(int value);
    virtual void setRedLEDState();
    virtual void setGreenLEDValue(int value);
    virtual void setGreenLEDState();
    virtual void setBlueLEDValue(int value);
    virtual void setBlueLEDState();
protected:
private:
    uint8_t red=0, green=0, blue=0;
};

#endif // RGB_LEDVIEW_HPP
