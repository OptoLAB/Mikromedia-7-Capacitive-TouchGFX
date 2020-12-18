#ifndef PLAYLISTITEM_HPP
#define PLAYLISTITEM_HPP

#include <gui_generated/containers/playlistItemBase.hpp>

class playlistItem : public playlistItemBase
{
public:
    playlistItem();
    virtual ~playlistItem() {}

    virtual void initialize();
    virtual void setText(Unicode::UnicodeChar *text, uint8_t id);
    virtual uint8_t getText(Unicode::UnicodeChar *text);
    virtual void setItem();
    virtual void resetItem();
    virtual void setAction(GenericCallback< playlistItem& >& callback);
    virtual void itemSelected();
protected:
    GenericCallback< playlistItem& >* viewCallback;
private:
    uint8_t itemID;
};

#endif // PLAYLISTITEM_HPP
