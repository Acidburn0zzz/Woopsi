#include "listboxdataitem.h"

using namespace WoopsiUI;

ListBoxDataItem::ListBoxDataItem(const char* text,
								 const u32 value,
								 const bool isSelected,
								 const u16 normalTextColour,
								 const u16 normalBackColour,
								 const u16 selectedTextColour,
								 const u16 selectedBackColour) : ListDataItem(text, value, isSelected) {

	_normalTextColour = normalTextColour;
	_normalBackColour = normalBackColour;
	_selectedTextColour = selectedTextColour;
	_selectedBackColour = selectedBackColour;
}
