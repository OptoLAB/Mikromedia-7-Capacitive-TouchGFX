#ifndef NRFVIEW_HPP
#define NRFVIEW_HPP

#include <gui_generated/nrf_screen/NRFViewBase.hpp>
#include <gui/nrf_screen/NRFPresenter.hpp>
#include <gui/containers/btnKeySmall.hpp>

class NRFView : public NRFViewBase
{
public:
    NRFView();
    virtual ~NRFView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void btnClicked(btnKeySmall& btn);
    virtual void btnShiftClicked();
    virtual void btnBackClicked();
    virtual void btnSwitchClicked();
    virtual void btnSpaceClicked();
    virtual void btnEnterClicked();
    virtual void btnClearClicked();
    virtual void btnSendClicked();
    virtual void handleTickEvent();
    virtual void updateKeyboard(uint8_t ks);
    virtual void addKeyboard(uint8_t x,uint8_t y,uint8_t spacing);
    virtual void setupTranciever(const uint8_t *tx_addr, const uint8_t *rx_addr);

protected:
    btnKeySmall btnKeysSmall[36];
    Callback<NRFView, btnKeySmall&> btnClickedCallback;
private:
	uint8_t charPointer=0;
	uint8_t keysState=0;
	uint8_t payload_length=32;
	const uint8_t maxChars=128;
	uint8_t nRF24_payload[128];
	const uint8_t keysSpacing=54;
	const uint8_t numOfChars=26;
	const char *keys="1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM%^~|!?<>/\\@#&*-+=(),_\"\':;.";
};

#endif // NRFVIEW_HPP
