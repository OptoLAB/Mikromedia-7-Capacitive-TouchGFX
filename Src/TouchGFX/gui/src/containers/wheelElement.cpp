#include <gui/containers/wheelElement.hpp>

wheelElement::wheelElement()
{

}

void wheelElement::initialize()
{
    wheelElementBase::initialize();
}

void wheelElement::updateText(int16_t value)
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%02d", value);
    textArea1.invalidate();
}
