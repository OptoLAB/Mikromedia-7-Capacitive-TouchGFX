#ifndef BUZZERVIEW_HPP
#define BUZZERVIEW_HPP

#include <gui_generated/buzzer_screen/BUZZERViewBase.hpp>
#include <gui/buzzer_screen/BUZZERPresenter.hpp>

class BUZZERView : public BUZZERViewBase
{
public:
    BUZZERView();
    virtual ~BUZZERView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void startBuzzer();
    virtual void stopBuzzer();
    virtual void updateVolume(int value);
    virtual void updateTone(int value);
    virtual void handleTickEvent();
protected:
private:
    uint8_t volume;
    uint8_t tone;
};

#endif // BUZZERVIEW_HPP
