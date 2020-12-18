#ifndef RGB_LEDPRESENTER_HPP
#define RGB_LEDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RGB_LEDView;

class RGB_LEDPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    RGB_LEDPresenter(RGB_LEDView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~RGB_LEDPresenter() {};

private:
    RGB_LEDPresenter();

    RGB_LEDView& view;
};

#endif // RGB_LEDPRESENTER_HPP
