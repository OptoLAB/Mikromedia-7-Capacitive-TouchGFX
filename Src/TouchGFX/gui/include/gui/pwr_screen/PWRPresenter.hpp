#ifndef PWRPRESENTER_HPP
#define PWRPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PWRView;

class PWRPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PWRPresenter(PWRView& v);

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

    virtual ~PWRPresenter() {};

private:
    PWRPresenter();

    PWRView& view;
};

#endif // PWRPRESENTER_HPP
