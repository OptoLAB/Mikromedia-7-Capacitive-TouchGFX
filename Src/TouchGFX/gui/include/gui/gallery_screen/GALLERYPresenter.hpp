#ifndef GALLERYPRESENTER_HPP
#define GALLERYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GALLERYView;

class GALLERYPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GALLERYPresenter(GALLERYView& v);

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

    virtual ~GALLERYPresenter() {};

private:
    GALLERYPresenter();

    GALLERYView& view;
};

#endif // GALLERYPRESENTER_HPP
