#ifndef BTNKEYSMALL_HPP
#define BTNKEYSMALL_HPP

#include <gui_generated/containers/btnKeySmallBase.hpp>

class btnKeySmall : public btnKeySmallBase
{
public:
    btnKeySmall();
    virtual ~btnKeySmall() {}

    virtual void initialize();
    virtual void setText(Unicode::UnicodeChar *text, uint8_t id);
    virtual uint8_t getText(Unicode::UnicodeChar *text);
    virtual void setAction(GenericCallback< btnKeySmall& >& callback);
    virtual void btnKeyClicked();
protected:
    GenericCallback< btnKeySmall& >* viewCallback;
private:
    uint8_t btnID;
};

#endif // BTNKEYSMALL_HPP
