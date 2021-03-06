#include "scrollingpanel.h"
#include "damagedrectmanager.h"
#include "graphicsport.h"
#include "woopsi.h"
#include "woopsifuncs.h"
#include "woopsipoint.h"

using namespace WoopsiUI;

ScrollingPanel::ScrollingPanel(s16 x, s16 y, u16 width, u16 height, GadgetStyle* style) : Gadget(x, y, width, height, style) {
	
	Rect rect;
	getClientRect(rect);
	
	_canvasWidth = rect.width;
	_canvasHeight = rect.height;
	_canvasX = 0;
	_canvasY = 0;
	
	setAllowsVerticalScroll(true);
	setAllowsHorizontalScroll(true);
	setContentScrolled(true);

	_flags.permeable = true;
}

void ScrollingPanel::drawContents(GraphicsPort* port) {
	port->drawFilledRect(0, 0, getWidth(), getHeight(), getBackColour());
}

void ScrollingPanel::drawBorder(GraphicsPort* port) {

	// Stop drawing if the gadget indicates it should not have an outline
	if (isBorderless()) return;

	port->drawBevelledRect(0, 0, getWidth(), getHeight(), getShadowColour(), getShineColour());
}

void ScrollingPanel::jump(s32 x, s32 y) {
	// Calculate difference between jump value and current value and scroll
	scroll(x - _canvasX, y - _canvasY);
}

void ScrollingPanel::scroll(s32 dx, s32 dy) {
	
	// Ensure the screen is up-to-date before we start
	woopsiApplication->getDamagedRectManager()->redraw();

	Rect rect;
	getClientRect(rect);

	// Prevent scrolling outside boundaries
	if (_canvasX + dx < -(_canvasWidth - rect.width)) {
		dx = -(_canvasWidth - rect.width) - _canvasX;
	} else if (_canvasX + dx > 0) {
		dx = -_canvasX;
	}

	if (_canvasY + dy < -(_canvasHeight - rect.height)) {
		dy = -(_canvasHeight - rect.height) - _canvasY;
	} else if (_canvasY + dy > 0) {
		dy = -_canvasY;
	}

	// Prevent scrolling in disallowed planes
	if (!allowsVerticalScroll()) dy = 0;
	if (!allowsHorizontalScroll()) dx = 0;

	// Perform scroll if necessary
	if ((dx != 0) || (dy != 0)) {

		// Only scroll if content scrolling is enabled
		if (_isContentScrolled) {

			// Perform scroll
			WoopsiArray<Rect> revealedRects(4);
			GraphicsPort* port = newGraphicsPort(true);
			port->scroll(0, 0, dx, dy, rect.width, rect.height, &revealedRects);
			delete port;

			// Adjust the scroll values
			_canvasY += dy;
			_canvasX += dx;
			
			// Mark the revealed rects as damaged
			for (s32 i = 0; i < revealedRects.size(); ++i) {
				
				// Adjust co-ordinates from graphicsport-space to gadget space
				revealedRects[i].x += _borderSize.left;
				revealedRects[i].y += _borderSize.top;
				
				markRectDamaged(revealedRects[i]);
			}
		} else {

			// Adjust the scroll values
			_canvasY += dy;
			_canvasX += dx;
		}

		// Scroll all child gadgets
		scrollChildren(dx, dy);

		// Notify event handlers
		if (raisesEvents()) {
			_gadgetEventHandler->handleScrollEvent(*this, WoopsiPoint(dx, dy));
		}
	}
}

void ScrollingPanel::scrollChildren(s32 dx, s32 dy) {
	s16 gadgetX = 0;
	s16 gadgetY = 0;
	s16 thisX = getX();
	s16 thisY = getY();
	Gadget* gadget = NULL;

	for (s32 i = 0; i < _gadgets.size(); i++) {

		gadget = _gadgets[i];

		gadgetX = (gadget->getX() - thisX) + dx;
		gadgetY = (gadget->getY() - thisY) + dy;

		gadget->moveTo(gadgetX, gadgetY);
	}
}

void ScrollingPanel::onClick(s16 x, s16 y) {
	startDragging(x, y);
}

void ScrollingPanel::onDrag(s16 x, s16 y, s16 vX, s16 vY) {
	scroll(vX, vY);
}
