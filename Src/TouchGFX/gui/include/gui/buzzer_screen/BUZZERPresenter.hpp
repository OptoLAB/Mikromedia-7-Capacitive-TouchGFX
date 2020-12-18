#ifndef BUZZERPRESENTER_HPP
#define BUZZERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class BUZZERView;

class BUZZERPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    BUZZERPresenter(BUZZERView& v);

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

    virtual ~BUZZERPresenter() {};

private:
    BUZZERPresenter();

    BUZZERView& view;
};

#endif // BUZZERPRESENTER_HPP
