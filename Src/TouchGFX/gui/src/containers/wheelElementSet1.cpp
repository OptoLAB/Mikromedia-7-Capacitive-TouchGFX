#include <gui/containers/wheelElementSet1.hpp>

wheelElementSet1::wheelElementSet1()
{

}

void wheelElementSet1::initialize()
{
    wheelElementSet1Base::initialize();
}
void wheelElementSet1::setText(const char *text)
{
	Unicode::strncpy(textArea1Buffer, text, TEXTAREA1_SIZE);
	textArea1.invalidate();
}
