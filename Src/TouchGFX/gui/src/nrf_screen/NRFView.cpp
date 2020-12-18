#include <gui/nrf_screen/NRFView.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "nRF/nrf24.h"
#include "led/NCP5623C.h"
}

NRFView::NRFView():btnClickedCallback(this, &NRFView::btnClicked)
{

}


void NRFView::setupScreen()
{
	int i=0;
	static const uint8_t nRF24_TX_ADDR[] = "00001";
	static const uint8_t nRF24_RX_ADDR[] = "00002";

	//setup transciever
	nRF24_LowerSpiSpeed();
	setupTranciever(nRF24_TX_ADDR, nRF24_RX_ADDR);

	//clear message box
	for(i=0;i<maxChars;i++)MessageBuffer[i]='\0';
	Message.resizeToCurrentText();
	Message.invalidate();

	//set qwerty keyboard
	addKeyboard(122,208,54);
	updateKeyboard(keysState);

    NRFViewBase::setupScreen();
}
void NRFView::setupTranciever(const uint8_t *tx_addr, const uint8_t *rx_addr)
{
	nRF24_DisableAA(0xFF);
	nRF24_SetRFChannel(115);
	nRF24_SetDataRate(nRF24_DR_1Mbps);
	nRF24_SetCRCScheme(nRF24_CRC_1byte);
	nRF24_SetAddrWidth(5);
	nRF24_SetAddr(nRF24_PIPETX, tx_addr); // program TX address
    nRF24_SetAddr(nRF24_PIPE1, rx_addr); // program address for RX pipe #1
    nRF24_SetRXPipe(nRF24_PIPE1, nRF24_AA_OFF, 32); // Auto-ACK: disabled, payload length: 5 bytes
	nRF24_SetTXPower(nRF24_TXPWR_0dBm);
	nRF24_SetOperationalMode(nRF24_MODE_RX);
	nRF24_ClearIRQFlags();
	nRF24_SetPowerMode(nRF24_PWR_UP);
	nRF24_CE_H;
}
void NRFView::addKeyboard(uint8_t x,uint8_t y,uint8_t spacing)
{
	int i=0, v=0, h=0;

	btnShift.setXY(x+spacing/2, y+spacing*3);
	btnBackspace.setXY(x+spacing/2+spacing*8, y+spacing*3);
	btnSwitch.setXY(x+spacing/2, y+spacing*4);
	btnSpace.setXY(x+spacing/2+spacing*3, y+spacing*4);
	btnEnter.setXY(x+spacing/2+spacing*6, y+spacing*4);

	updateKeyboard(keysState);
	for(i=0;i<36;i++)
	{
		btnKeysSmall[i].setXY(0+x+h,y+v);
		btnKeysSmall[i].setAction(btnClickedCallback);
		add(btnKeysSmall[i]);

		h+=spacing;
		if(i==9){h=0; v+=spacing;}
		if(i==19){h=spacing/2; v+=spacing;}
		if(i==28){h=spacing/2+spacing; v+=spacing;}
	}
}
void NRFView::updateKeyboard(uint8_t ks)
{
	int i=0, k=0;
	Unicode::UnicodeChar name[10]={0};

	for(i=0;i<36;i++)
	{
		Unicode::fromUTF8((uint8_t *)(&keys[k]), name, 1);
		btnKeysSmall[i].setText(name,i);
		btnKeysSmall[i].invalidate();
		if(i==9) k+=ks*numOfChars;
		k++;
	}
}

void NRFView::btnClicked(btnKeySmall& btn)
{
	Unicode::UnicodeChar name[3];
	if(charPointer<(maxChars-1))
	{
		btn.getText(name);
		Unicode::strncpy(MessageBuffer+charPointer,name,1);
		charPointer++;
		Message.resizeToCurrentText();
		Message.invalidate();
	}

}
void NRFView::btnShiftClicked()
{
	if(keysState==0)keysState=1;
	else if(keysState==1)keysState=0;
	updateKeyboard(keysState);
}

void NRFView::btnBackClicked()
{
	if(charPointer>0)
	{
		charPointer--;
		MessageBuffer[charPointer]='\0';
		Message.invalidate();
	}
}

void NRFView::btnSwitchClicked()
{
	if(keysState!=2)keysState=2;
	else if(keysState==2)keysState=0;
	updateKeyboard(keysState);
}

void NRFView::btnSpaceClicked()
{
	if(charPointer<maxChars)
	{
		MessageBuffer[charPointer]=' ';
		charPointer++;
		Message.invalidate();
	}
}

void NRFView::btnEnterClicked()
{
	if(charPointer<(maxChars-1))
	{
		MessageBuffer[charPointer]='\n';
		charPointer++;
		Message.resizeToCurrentText();
		Message.invalidate();
	}
}
void NRFView::btnClearClicked()
{
	int i=0;
	//clear message box
	for(i=0;i<maxChars;i++)MessageBuffer[i]='\0';
	Message.invalidate();
	Message.resizeToCurrentText();
	charPointer=0;
}

void NRFView::btnSendClicked()
{
	uint8_t i, n;
	uint16_t msg_len=0;

	//clear and get payload
	for (i = 0; i < maxChars; i++) nRF24_payload[i] = '\0';
	Unicode::toUTF8(MessageBuffer, nRF24_payload, maxChars);
	msg_len=Unicode::strlen((const char*)nRF24_payload);
	n=msg_len>>5;// /32

	//switch tx mode
	nRF24_SetOperationalMode(nRF24_MODE_TX);
	nRF24_CE_L;

	//transmit paket
	for(i=0;i<n;i++)
	{
		if(nRF24_TransmitPacket(nRF24_payload+(i<<5), payload_length)==nRF24_TX_SUCCESS) NCP5623C_SetLED(R_LED,1);
		else NCP5623C_SetLED(B_LED,1);
	}
	if(msg_len%32)
	{
		if(nRF24_TransmitPacket(nRF24_payload+(n<<5), payload_length)==nRF24_TX_SUCCESS) NCP5623C_SetLED(R_LED,1);
		else NCP5623C_SetLED(B_LED,1);
	}
	HAL_Delay(10);
	NCP5623C_SetLED(R_LED,0);
	NCP5623C_SetLED(B_LED,0);

	//switch back to rx mode
	nRF24_SetOperationalMode(nRF24_MODE_RX);
	nRF24_CE_H;

}
void NRFView::handleTickEvent()
{
	uint8_t i;
	//check if payload is available
	if (nRF24_GetStatus_RXFIFO() != nRF24_STATUS_RXFIFO_EMPTY)
	{
		NCP5623C_SetLED(G_LED,1);

		nRF24_ReadPayload(nRF24_payload, &payload_length);
		nRF24_ClearIRQFlags();

		for (i = 0; i < maxChars; i++) MessageBuffer[i] = '\0';

		Unicode::fromUTF8(nRF24_payload, MessageBuffer, maxChars);
		charPointer=Unicode::strlen(MessageBuffer);

		Message.invalidate();
		Message.resizeToCurrentText();
		Message.invalidate();
	}
	else NCP5623C_SetLED(G_LED,0);
}
void NRFView::tearDownScreen()
{
	nRF24_SetPowerMode(nRF24_PWR_DOWN);
	nRF24_ReturnSpiSpeed();
    NRFViewBase::tearDownScreen();
}
