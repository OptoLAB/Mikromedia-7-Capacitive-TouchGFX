/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/wheelElementSet1Base.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

wheelElementSet1Base::wheelElementSet1Base()
{
    setWidth(47);
    setHeight(29);
    boxWithBorder1.setPosition(0, 0, 47, 29);
    boxWithBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 138, 214));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(0);
    boxWithBorder1.setAlpha(50);

    textArea1.setPosition(0, 0, 47, 29);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 138, 214));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID512).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID511));

    add(boxWithBorder1);
    add(textArea1);
}

void wheelElementSet1Base::initialize()
{

}