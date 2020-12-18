#include <gui/temp_screen/TEMPView.hpp>
#include "BitmapDatabase.hpp"
extern "C" {
#include "internal/internal.h"
#include "temp/MCP9700A.h"
}

TEMPView::TEMPView()
{

}

void TEMPView::setupScreen()
{
	Bitmap::cache(BITMAP_DARK_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FILL_ID);
    TEMPViewBase::setupScreen();
}

void TEMPView::tearDownScreen()
{
	Bitmap::clearCache();
	TEMPViewBase::tearDownScreen();
}
void TEMPView::handleTickEvent()
{
	ticks++;
	if(!(ticks%8))
	{
		MCP9700A_GetTemperature(&extTemp_dpf,&extTemp_dpb);

		Unicode::snprintf(textAreaExtBuffer1,TEXTAREAEXTBUFFER1_SIZE,"%d",extTemp_dpf);
		Unicode::snprintf(textAreaExtBuffer2,TEXTAREAEXTBUFFER2_SIZE,"%d",extTemp_dpb/100);
		textAreaExt.invalidate();
		textAreaExt.resizeToCurrentText();
		textAreaExt.invalidate();

		tempProgressExt.setValue(extTemp_dpf);
		tempProgressExt.invalidate();

		INTERNAL_GetTemperature(&intTemp_dpf,&intTemp_dpb);

		Unicode::snprintf(textAreaIntBuffer1,TEXTAREAINTBUFFER1_SIZE,"%d",intTemp_dpf);
		Unicode::snprintf(textAreaIntBuffer2,TEXTAREAINTBUFFER2_SIZE,"%d",intTemp_dpb/100);
		textAreaInt.invalidate();
		textAreaInt.resizeToCurrentText();
		textAreaInt.invalidate();

		tempProgressInt.setValue(intTemp_dpf);
		tempProgressInt.invalidate();
	}

}
