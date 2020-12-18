/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>
#include <touchgfx/transitions/SlideTransition.hpp>











#include <touchgfx/transitions/SlideTransition.hpp>








#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/main_menu_screen/MAIN_MENUView.hpp>
#include <gui/main_menu_screen/MAIN_MENUPresenter.hpp>
#include <gui/rgb_led_screen/RGB_LEDView.hpp>
#include <gui/rgb_led_screen/RGB_LEDPresenter.hpp>
#include <gui/light_screen/LIGHTView.hpp>
#include <gui/light_screen/LIGHTPresenter.hpp>
#include <gui/accel_screen/ACCELView.hpp>
#include <gui/accel_screen/ACCELPresenter.hpp>
#include <gui/gallery_screen/GALLERYView.hpp>
#include <gui/gallery_screen/GALLERYPresenter.hpp>
#include <gui/mp3_screen/MP3View.hpp>
#include <gui/mp3_screen/MP3Presenter.hpp>
#include <gui/temp_screen/TEMPView.hpp>
#include <gui/temp_screen/TEMPPresenter.hpp>
#include <gui/pwr_screen/PWRView.hpp>
#include <gui/pwr_screen/PWRPresenter.hpp>
#include <gui/time_screen/TIMEView.hpp>
#include <gui/time_screen/TIMEPresenter.hpp>
#include <gui/buzzer_screen/BUZZERView.hpp>
#include <gui/buzzer_screen/BUZZERPresenter.hpp>
#include <gui/flash_screen/FLASHView.hpp>
#include <gui/flash_screen/FLASHPresenter.hpp>
#include <gui/nrf_screen/NRFView.hpp>
#include <gui/nrf_screen/NRFPresenter.hpp>
#include <gui/weather_screen/WEATHERView.hpp>
#include <gui/weather_screen/WEATHERPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public touchgfx::MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< MAIN_MENUView,
            touchgfx::meta::TypeList< RGB_LEDView,
            touchgfx::meta::TypeList< LIGHTView,
            touchgfx::meta::TypeList< ACCELView,
            touchgfx::meta::TypeList< GALLERYView,
            touchgfx::meta::TypeList< MP3View,
            touchgfx::meta::TypeList< TEMPView,
            touchgfx::meta::TypeList< PWRView,
            touchgfx::meta::TypeList< TIMEView,
            touchgfx::meta::TypeList< BUZZERView,
            touchgfx::meta::TypeList< FLASHView,
            touchgfx::meta::TypeList< NRFView,
            touchgfx::meta::TypeList< WEATHERView,
            touchgfx::meta::Nil > > > > > > > > > > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< MAIN_MENUPresenter,
            touchgfx::meta::TypeList< RGB_LEDPresenter,
            touchgfx::meta::TypeList< LIGHTPresenter,
            touchgfx::meta::TypeList< ACCELPresenter,
            touchgfx::meta::TypeList< GALLERYPresenter,
            touchgfx::meta::TypeList< MP3Presenter,
            touchgfx::meta::TypeList< TEMPPresenter,
            touchgfx::meta::TypeList< PWRPresenter,
            touchgfx::meta::TypeList< TIMEPresenter,
            touchgfx::meta::TypeList< BUZZERPresenter,
            touchgfx::meta::TypeList< FLASHPresenter,
            touchgfx::meta::TypeList< NRFPresenter,
            touchgfx::meta::TypeList< WEATHERPresenter,
            touchgfx::meta::Nil > > > > > > > > > > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef touchgfx::meta::TypeList< touchgfx::NoTransition,
            touchgfx::meta::TypeList< SlideTransition<EAST>,
            touchgfx::meta::Nil >
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef touchgfx::meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoMAIN_MENUScreenNoTransition();
    }
protected:
    FrontendHeapBase(touchgfx::AbstractPartition& presenters, touchgfx::AbstractPartition& views, touchgfx::AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP