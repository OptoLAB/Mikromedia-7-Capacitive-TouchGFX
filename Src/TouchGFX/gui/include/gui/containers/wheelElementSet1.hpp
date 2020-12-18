#ifndef WHEELELEMENTSET1_HPP
#define WHEELELEMENTSET1_HPP

#include <gui_generated/containers/wheelElementSet1Base.hpp>

class wheelElementSet1 : public wheelElementSet1Base
{
public:
    wheelElementSet1();
    virtual ~wheelElementSet1() {}

    virtual void initialize();
    virtual void setText(const char *text);
protected:
};

#endif // WHEELELEMENTSET1_HPP
