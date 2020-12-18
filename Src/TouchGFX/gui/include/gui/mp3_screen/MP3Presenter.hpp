#ifndef MP3PRESENTER_HPP
#define MP3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MP3View;

class MP3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    MP3Presenter(MP3View& v);

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

    virtual ~MP3Presenter() {};

private:
    MP3Presenter();

    MP3View& view;
};

#endif // MP3PRESENTER_HPP
