/*
 * MyScrollableContainer.cpp
 *
 *  Created on: Apr 23, 2020
 *      Author: Jovan
 */

#include <gui/common/MyScrollableContainer.hpp>


MyScrollableContainer::MyScrollableContainer()
{

}

bool MyScrollableContainer::doScroll(int16_t deltaX, int16_t deltaY)
{
	return ScrollableContainer::doScroll(deltaX, deltaY);
}
