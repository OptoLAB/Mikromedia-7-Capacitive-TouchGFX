#include <gui/containers/btnKeySmall.hpp>

btnKeySmall::btnKeySmall()
{

}

void btnKeySmall::initialize()
{
    btnKeySmallBase::initialize();
}
void btnKeySmall::setText(Unicode::UnicodeChar *text, uint8_t id)
{
	btnID=id;
	Unicode::snprintf(textArea1Buffer,TEXTAREA1_SIZE,"%s",text);
	textArea1.invalidate();
}
uint8_t btnKeySmall::getText(Unicode::UnicodeChar *text)
{
	Unicode::strncpy(text,textArea1Buffer,TEXTAREA1_SIZE);
	return btnID;
}
void btnKeySmall::setAction(GenericCallback< btnKeySmall& >& callback)
{
    viewCallback = &callback;
}
void btnKeySmall::btnKeyClicked()
{
    if (viewCallback->isValid())
    {
        viewCallback->execute(*this);
    }
}
