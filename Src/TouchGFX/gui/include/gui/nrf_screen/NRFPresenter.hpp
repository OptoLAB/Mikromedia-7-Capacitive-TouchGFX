#ifndef NRFPRESENTER_HPP
#define NRFPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class NRFView;

class NRFPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    NRFPresenter(NRFView& v);

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

    virtual ~NRFPresenter() {};

private:
    NRFPresenter();

    NRFView& view;
};

#endif // NRFPRESENTER_HPP
