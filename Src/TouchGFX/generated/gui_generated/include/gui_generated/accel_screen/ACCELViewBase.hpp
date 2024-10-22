/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ACCELVIEWBASE_HPP
#define ACCELVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/accel_screen/ACCELPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>

class ACCELViewBase : public touchgfx::View<ACCELPresenter>
{
public:
    ACCELViewBase();
    virtual ~ACCELViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void setHPfiltar()
    {
        // Override and implement this function in ACCEL
    }

    virtual void resetHPfiltar()
    {
        // Override and implement this function in ACCEL
    }

    virtual void setAccelMode()
    {
        // Override and implement this function in ACCEL
    }

    virtual void setMagMode()
    {
        // Override and implement this function in ACCEL
    }

    virtual void setRange()
    {
        // Override and implement this function in ACCEL
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Box box4;
    touchgfx::Box box3;
    touchgfx::Box box5;
    touchgfx::Box box6;
    touchgfx::Box box2;
    touchgfx::Image image1;
    touchgfx::ScalableImage imageGraph;
    touchgfx::ButtonWithIcon buttonClose;
    touchgfx::TextAreaWithOneWildcard textAreaX;
    touchgfx::TextAreaWithOneWildcard textAreaY;
    touchgfx::TextAreaWithOneWildcard textAreaZ;
    touchgfx::RadioButton radioButtonHPfiltar;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea2;
    touchgfx::RadioButton radioButtonMag;
    touchgfx::TextArea textArea3;
    touchgfx::TextArea textArea4;
    touchgfx::RadioButton radioButtonRange2g;
    touchgfx::TextArea textArea2g;
    touchgfx::RadioButton radioButtonRange4g;
    touchgfx::TextArea textArea4g;
    touchgfx::RadioButton radioButtonRange8g;
    touchgfx::TextArea textArea8g;
    touchgfx::TextArea textArea6;
    touchgfx::TextArea textArea7;
    touchgfx::RadioButtonGroup<1> radioButtonGroup1;
    touchgfx::RadioButtonGroup<1> radioButtonGroup3;
    touchgfx::RadioButtonGroup<3> radioButtonGroup2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAX_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaXBuffer[TEXTAREAX_SIZE];
    static const uint16_t TEXTAREAY_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaYBuffer[TEXTAREAY_SIZE];
    static const uint16_t TEXTAREAZ_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaZBuffer[TEXTAREAZ_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ACCELViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<ACCELViewBase, const touchgfx::AbstractButton&> radioButtonSelectedCallback;
    touchgfx::Callback<ACCELViewBase, const touchgfx::AbstractButton&> radioButtonDeselectedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);
    void radioButtonDeselectedCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 9600;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // ACCELVIEWBASE_HPP
