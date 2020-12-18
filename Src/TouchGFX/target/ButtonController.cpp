/*
 * ButtonController.cpp
 *
 *  Created on: Apr 16, 2020
 *      Author: Jovan
 */
#include <platform/driver/button/ButtonController.hpp>

extern "C" {
#include "ir/NEC_TimerIC.h"
}

class MC7_Buttons : public touchgfx::ButtonController
{
    virtual void init() {  }
    virtual bool sample(uint8_t& key)
    {

      if (NEC_GetStatus())
      {
        key = 1;
        NEC_ClearStatus();
        return true;
      }
      return false;
    }
private:

};


