/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/wheelElementBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

wheelElementBase::wheelElementBase()
{
    setWidth(60);
    setHeight(42);
    textArea1.setPosition(0, -2, 60, 42);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID502).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID501));

    add(textArea1);
}

void wheelElementBase::initialize()
{

}
