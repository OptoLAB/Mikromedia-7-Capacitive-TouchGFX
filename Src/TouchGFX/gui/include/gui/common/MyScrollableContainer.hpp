/*
 * MyScrollableContainer.hpp
 *
 *  Created on: Apr 23, 2020
 *      Author: Jovan
 */

#ifndef MYSCROLLABLECONTAINER_HPP
#define MYSCROLLABLECONTAINER_HPP

#include <touchgfx/containers/ScrollableContainer.hpp>

using namespace touchgfx;
class MyScrollableContainer : public ScrollableContainer
{
public:
	MyScrollableContainer();
	~MyScrollableContainer(){}
	bool doScroll(int16_t deltaX, int16_t deltaY);
};

#endif /* GUI_INCLUDE_GUI_COMMON_MYSCROLLABLECONTAINER_HPP_ */
