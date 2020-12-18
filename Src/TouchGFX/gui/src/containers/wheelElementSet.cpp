#include <gui/containers/wheelElementSet.hpp>

wheelElementSet::wheelElementSet()
{

}

void wheelElementSet::initialize()
{
    wheelElementSetBase::initialize();
}

void wheelElementSet::updateText(int16_t value)
{
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%02d", value);
    textArea1.invalidate();
}
