#ifndef WHEELELEMENT1_HPP
#define WHEELELEMENT1_HPP

#include <gui_generated/containers/wheelElement1Base.hpp>

class wheelElement1 : public wheelElement1Base
{
public:
    wheelElement1();
    virtual ~wheelElement1() {}

    virtual void initialize();
    virtual void setText(const char *text);
protected:
};

#endif // WHEELELEMENT1_HPP
