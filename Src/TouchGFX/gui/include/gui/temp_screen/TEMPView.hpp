#ifndef TEMPVIEW_HPP
#define TEMPVIEW_HPP

#include <gui_generated/temp_screen/TEMPViewBase.hpp>
#include <gui/temp_screen/TEMPPresenter.hpp>

class TEMPView : public TEMPViewBase
{
public:
    TEMPView();
    virtual ~TEMPView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
private:
    uint16_t ticks;
    int16_t intTemp_dpf;
    uint16_t intTemp_dpb;
    int16_t extTemp_dpf;
    uint16_t extTemp_dpb;
};

#endif // TEMPVIEW_HPP
