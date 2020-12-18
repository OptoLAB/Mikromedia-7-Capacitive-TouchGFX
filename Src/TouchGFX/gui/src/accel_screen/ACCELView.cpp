#include <gui/accel_screen/ACCELView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
extern "C" {
#include "accel/FXOS8700CQ.h"
#include "led/NCP5623C.h"
}

#define GRAPH_W		480
#define GRAPH_H		272
#define ORIGIN_X	40
#define ORIGIN_Y	180
#define MIN_X		0
#define MAX_X		100
#define MIN_Y		-1000
#define MAX_Y		1000
#define LINE_W		4


ACCELView::ACCELView()
{

}

void ACCELView::setupScreen()
{
    ACCELViewBase::setupScreen();

    Bitmap::cache(BITMAP_BACKGROUND_ID);

    graph_x.setXY(ORIGIN_X, ORIGIN_Y);
    graph_y.setXY(ORIGIN_X, ORIGIN_Y);
    graph_z.setXY(ORIGIN_X, ORIGIN_Y);
    // Set the outer dimensions and color of the graph
    graph_x.setup(GRAPH_W, GRAPH_H, Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xAC));
    graph_y.setup(GRAPH_W, GRAPH_H, Color::getColorFrom24BitRGB(0xAC, 0xFF, 0xFF));
    graph_z.setup(GRAPH_W, GRAPH_H, Color::getColorFrom24BitRGB(0xFF, 0xAC, 0xFF));
    // Set the range for the x and y axis of the graph. That is
    // the max and min x/y value that can be displayed inside the
    // dimension of the graph.
    graph_x.setRange(MIN_X, MAX_X, MIN_Y, MAX_Y);
    graph_y.setRange(MIN_X, MAX_X, MIN_Y, MAX_Y);
    graph_z.setRange(MIN_X, MAX_X, MIN_Y, MAX_Y);
    // Set the line width in pixels
    graph_x.setLineWidth(LINE_W);
    graph_y.setLineWidth(LINE_W);
    graph_z.setLineWidth(LINE_W);

    add(graph_x);
    add(graph_y);
    add(graph_z);
}

void ACCELView::tearDownScreen()
{
	Bitmap::clearCache();
    ACCELViewBase::tearDownScreen();
}

void ACCELView::handleTickEvent()
{
	int16_t x,y,z;

    ticks++;

    if(!mode)
    	FXOS8700CQ_AccelGetXYZ(&x,&y,&z);
    else
    	FXOS8700CQ_MagnetometerGetXYZ(&x,&y,&z);
    graph_x.addValue(ticks, x);
    graph_y.addValue(ticks, y);
    graph_z.addValue(ticks, z);

    if (ticks%4==0)
    {

    	Unicode::snprintf(textAreaXBuffer,TEXTAREAX_SIZE,"%4d",x);
    	textAreaX.invalidate();
    	textAreaX.resizeToCurrentText();
    	textAreaX.invalidate();

    	Unicode::snprintf(textAreaYBuffer,TEXTAREAY_SIZE,"%4d",y);
    	textAreaY.invalidate();
    	textAreaY.resizeToCurrentText();
    	textAreaY.invalidate();

    	Unicode::snprintf(textAreaZBuffer,TEXTAREAZ_SIZE,"%4d",z);
    	textAreaZ.invalidate();
    	textAreaZ.resizeToCurrentText();
    	textAreaZ.invalidate();
    }


    if (ticks>=(MAX_X-MIN_X))
    {
    	graph_x.clear();
    	graph_x.invalidate();
    	graph_y.clear();
    	graph_y.invalidate();
    	graph_z.clear();
    	graph_z.invalidate();

    	ticks = 0;
    }
}
void ACCELView::setHPfiltar()
{
	textArea1.setTypedText(TypedText(T_TEXTON));
	textArea1.invalidate();
	FXOS8700CQ_AccelSetHPFilter(FXOS8700CQ_HPF_ON);
}

void ACCELView::resetHPfiltar()
{
	textArea1.setTypedText(TypedText(T_TEXTOFF));
	textArea1.invalidate();
	FXOS8700CQ_AccelSetHPFilter(FXOS8700CQ_HPF_OFF);
}
void ACCELView::setAccelMode()
{
	mode=0;
}
void ACCELView::setMagMode()
{
	mode=1;
}
void ACCELView::setRange()
{
	if(radioButtonRange2g.getSelected())
	{
		FXOS8700CQ_AccelSetRange(FXOS8700CQ_RANGE_2g);
	}
	else if(radioButtonRange4g.getSelected())
	{
		FXOS8700CQ_AccelSetRange(FXOS8700CQ_RANGE_4g);
	}
	else if(radioButtonRange8g.getSelected())
	{
		FXOS8700CQ_AccelSetRange(FXOS8700CQ_RANGE_8g);
	}
}
