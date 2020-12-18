/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef WHEELELEMENT1BASE_HPP
#define WHEELELEMENT1BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class wheelElement1Base : public touchgfx::Container
{
public:
    wheelElement1Base();
    virtual ~wheelElement1Base() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard textArea1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];

private:

};

#endif // WHEELELEMENT1BASE_HPP
