#ifndef MAIN_MENUPRESENTER_HPP
#define MAIN_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MAIN_MENUView;

class MAIN_MENUPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MAIN_MENUPresenter(MAIN_MENUView& v);

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

    virtual ~MAIN_MENUPresenter() {};

private:
    MAIN_MENUPresenter();

    MAIN_MENUView& view;
};

#endif // MAIN_MENUPRESENTER_HPP
