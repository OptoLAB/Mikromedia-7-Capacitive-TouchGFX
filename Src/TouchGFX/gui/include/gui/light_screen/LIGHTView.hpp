#ifndef LIGHTVIEW_HPP
#define LIGHTVIEW_HPP

#include <gui_generated/light_screen/LIGHTViewBase.hpp>
#include <gui/light_screen/LIGHTPresenter.hpp>

class LIGHTView : public LIGHTViewBase
{
public:
    LIGHTView();
    virtual ~LIGHTView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void updateText();
    virtual void handleTickEvent();
    virtual void updateGain(int value);
    virtual void updateIntegration(int value);
    virtual void updateBacklight(int value);
protected:
private:
    uint16_t ticks;
};

#endif // LIGHTVIEW_HPP
