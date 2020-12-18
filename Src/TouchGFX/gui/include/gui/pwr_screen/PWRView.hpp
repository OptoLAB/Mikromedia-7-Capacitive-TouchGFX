#ifndef PWRVIEW_HPP
#define PWRVIEW_HPP

#include <gui_generated/pwr_screen/PWRViewBase.hpp>
#include <gui/pwr_screen/PWRPresenter.hpp>

class PWRView : public PWRViewBase
{
public:
    PWRView();
    virtual ~PWRView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void updateProgress(uint8_t value);
protected:
private:
    uint8_t ticks=0;
    uint8_t volts=0;
    int16_t bat_dpf;
    uint16_t bat_dpb;
};

#endif // PWRVIEW_HPP
