#include <gui/containers/wheelElement1.hpp>

wheelElement1::wheelElement1()
{

}

void wheelElement1::initialize()
{
    wheelElement1Base::initialize();
}

void wheelElement1::setText(const char *text)
{
	Unicode::strncpy(textArea1Buffer, text, TEXTAREA1_SIZE);
	textArea1.invalidate();
}
