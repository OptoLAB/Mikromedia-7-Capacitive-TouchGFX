#ifndef LIGHTPRESENTER_HPP
#define LIGHTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LIGHTView;

class LIGHTPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LIGHTPresenter(LIGHTView& v);

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

    virtual ~LIGHTPresenter() {};

private:
    LIGHTPresenter();

    LIGHTView& view;
};

#endif // LIGHTPRESENTER_HPP
