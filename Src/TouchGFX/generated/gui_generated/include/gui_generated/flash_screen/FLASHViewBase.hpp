/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FLASHVIEWBASE_HPP
#define FLASHVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/flash_screen/FLASHPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/progress_indicators/ImageProgress.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/progress_indicators/TextProgress.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class FLASHViewBase : public touchgfx::View<FLASHPresenter>
{
public:
    FLASHViewBase();
    virtual ~FLASHViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void loadFlash()
    {
        // Override and implement this function in FLASH
    }

    virtual void eraseFlash()
    {
        // Override and implement this function in FLASH
    }

    virtual void hideInfo()
    {
        // Override and implement this function in FLASH
    }

    virtual void deleteFlash()
    {
        // Override and implement this function in FLASH
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Image image1;
    touchgfx::ButtonWithIcon buttonClose;
    touchgfx::TextArea textArea1;
    touchgfx::ImageProgress flashProgressBar;
    touchgfx::ButtonWithLabel buttonLoad;
    touchgfx::ButtonWithLabel buttonErase;
    touchgfx::TextArea textArea2;
    touchgfx::TextProgress flashProgressText;
    touchgfx::ModalWindow modalWindow1;
    touchgfx::Container containerInfo;
    touchgfx::TextAreaWithTwoWildcards textAreaSize;
    touchgfx::TextArea textArea3;
    touchgfx::Image image2;
    touchgfx::ButtonWithLabel buttonOK;
    touchgfx::Container containerWarning;
    touchgfx::TextArea textArea4;
    touchgfx::Image image3;
    touchgfx::ButtonWithIcon buttonDelete;
    touchgfx::ButtonWithIcon buttonCancel;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREASIZEBUFFER1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textAreaSizeBuffer1[TEXTAREASIZEBUFFER1_SIZE];
    static const uint16_t TEXTAREASIZEBUFFER2_SIZE = 4;
    touchgfx::Unicode::UnicodeChar textAreaSizeBuffer2[TEXTAREASIZEBUFFER2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<FLASHViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // FLASHVIEWBASE_HPP
