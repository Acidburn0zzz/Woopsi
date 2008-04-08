#include "contextmenuitem.h"
#include "graphicsport.h"

ContextMenuItem::ContextMenuItem(s16 x, s16 y, u16 width, u16 height, const char* text, u32 value, FontBase* font) : Textbox(x, y, width, height, text, font) {
	setBorderless(true);
	setTextPositionVert(TEXT_POSITION_VERT_CENTRE);
	setTextPositionHoriz(TEXT_POSITION_HORIZ_LEFT);
	_value = value;
}

void ContextMenuItem::draw(Rect clipRect) {

	GraphicsPort* port = newInternalGraphicsPort(clipRect);

	if (isClicked()) {
		port->drawFilledRect(0, 0, _width, _height, _shadowColour);
		port->drawText(_textX, _textY, _font, _text, _shineColour);
	} else {
		port->drawFilledRect(0, 0, _width, _height, _shineColour);
		port->drawText(_textX, _textY, _font, _text);
	}

	delete port;
}

bool ContextMenuItem::release(s16 x, s16 y) {
	if (Gadget::release(x, y)) {
		draw();
		return true;
	}

	return false;
}