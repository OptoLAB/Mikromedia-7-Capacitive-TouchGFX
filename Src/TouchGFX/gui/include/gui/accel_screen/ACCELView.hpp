#ifndef ACCELVIEW_HPP
#define ACCELVIEW_HPP

#include <gui_generated/accel_screen/ACCELViewBase.hpp>
#include <gui/accel_screen/ACCELPresenter.hpp>
#include <gui/common/Graph.hpp>

class ACCELView : public ACCELViewBase
{
public:
    ACCELView();
    virtual ~ACCELView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void setHPfiltar();
    virtual void resetHPfiltar();
    virtual void setAccelMode();
    virtual void setMagMode();
    virtual void setRange();
protected:
    int ticks;
    Graph graph_x;
    Graph graph_y;
    Graph graph_z;
    uint8_t mode=0;
};

#endif // ACCELVIEW_HPP
