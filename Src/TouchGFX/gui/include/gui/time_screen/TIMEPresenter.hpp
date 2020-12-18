#ifndef TIMEPRESENTER_HPP
#define TIMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TIMEView;

class TIMEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TIMEPresenter(TIMEView& v);

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

    virtual ~TIMEPresenter() {};

private:
    TIMEPresenter();

    TIMEView& view;
};

#endif // TIMEPRESENTER_HPP
