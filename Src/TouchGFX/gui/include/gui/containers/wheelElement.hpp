#ifndef WHEELELEMENT_HPP
#define WHEELELEMENT_HPP

#include <gui_generated/containers/wheelElementBase.hpp>

class wheelElement : public wheelElementBase
{
public:
    wheelElement();
    virtual ~wheelElement() {}

    virtual void initialize();
    virtual void updateText(int16_t value);
protected:
};

#endif // WHEELELEMENT_HPP
