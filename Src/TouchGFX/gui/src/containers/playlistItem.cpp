#include <gui/containers/playlistItem.hpp>

playlistItem::playlistItem()
{

}

void playlistItem::initialize()
{
    playlistItemBase::initialize();
}
void playlistItem::setText(Unicode::UnicodeChar *text, uint8_t id)
{
	itemID=id;
	Unicode::snprintf(textArea1Buffer,TEXTAREA1_SIZE,"%s",text);
	textArea1.resizeToCurrentText();
	textArea1.invalidate();
}
uint8_t playlistItem::getText(Unicode::UnicodeChar *text)
{
	Unicode::strncpy(text,textArea1Buffer,TEXTAREA1_SIZE);
	return itemID;
}
void playlistItem::setItem()
{
	flexButton1.setPressed(1);
}
void playlistItem::resetItem()
{
	flexButton1.setPressed(0);
}
void playlistItem::setAction(GenericCallback< playlistItem& >& callback)
{
    viewCallback = &callback;
}
void playlistItem::itemSelected()
{
    if (viewCallback->isValid())
    {
        viewCallback->execute(*this);
    }
}
