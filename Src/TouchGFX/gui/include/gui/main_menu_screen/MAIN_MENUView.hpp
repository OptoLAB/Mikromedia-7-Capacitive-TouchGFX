#ifndef MAIN_MENUVIEW_HPP
#define MAIN_MENUVIEW_HPP

#include <gui_generated/main_menu_screen/MAIN_MENUViewBase.hpp>
#include <gui/main_menu_screen/MAIN_MENUPresenter.hpp>

class MAIN_MENUView : public MAIN_MENUViewBase
{
public:
    MAIN_MENUView();
    virtual ~MAIN_MENUView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
};

#endif // MAIN_MENUVIEW_HPP
