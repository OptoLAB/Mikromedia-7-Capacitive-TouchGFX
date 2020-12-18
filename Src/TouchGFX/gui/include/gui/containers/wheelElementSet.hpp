#ifndef WHEELELEMENTSET_HPP
#define WHEELELEMENTSET_HPP

#include <gui_generated/containers/wheelElementSetBase.hpp>

class wheelElementSet : public wheelElementSetBase
{
public:
    wheelElementSet();
    virtual ~wheelElementSet() {}

    virtual void initialize();
    virtual void updateText(int16_t value);
protected:
};

#endif // WHEELELEMENTSET_HPP
