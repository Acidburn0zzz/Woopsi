/*
 * Copyright Mark Adamson 2010
 */
 
#include <nds.h>
#include "colourpicker.h"
#include "button.h"
#include "sliderhorizontal.h"
#include "woopsifuncs.h"

using namespace WoopsiUI;

ColourPicker::ColourPicker(s16 x, s16 y, u16 width, u16 height, const WoopsiString& title, u16 colour, GadgetStyle* style) : AmigaWindow(x, y, width, height, title, false, true, style) {

	Rect rect;
	getClientRect(rect);

	// Adjust rect to leave 2px padding around children
	rect.x += 2;
	rect.y += 2;
	rect.width -= 4;
	rect.height -= 4;

	// Create OK button
	_okButton = new Button(0, 0, 0, 0, "OK");

	Rect buttonRect;
	_okButton->getPreferredDimensions(buttonRect);

	// Calculate OK button dimensions
	buttonRect.width = (rect.width >> 1) - 1;
	buttonRect.x = rect.x;
	buttonRect.y = (rect.y + rect.height) - buttonRect.height;

	_okButton->changeDimensions(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);

	_okButton->setGadgetEventHandler(this);
	addGadget(_okButton);

	// Calculate cancel button dimensions
	buttonRect.x = rect.x + rect.width - buttonRect.width;
	buttonRect.y = (rect.y + rect.height) - buttonRect.height;

	// Create cancel button
	_cancelButton = new Button(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height, "Cancel");
	_cancelButton->setGadgetEventHandler(this);
	addGadget(_cancelButton);

	// Create Red Slider
	_redSlider = new SliderHorizontal(0, 0, 10, 10);

	// Calculate Red Slider dimensions
	_redSlider->getPreferredDimensions(buttonRect);

	buttonRect.width = rect.width - (rect.width >> 2) - 1;
	buttonRect.x = rect.x;
	buttonRect.y = rect.y;

	_redSlider->changeDimensions(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);

	_redSlider->setMinimumValue(0);
	_redSlider->setMaximumValue(31);
	_redSlider->setValue(23);

	_redSlider->setGadgetEventHandler(this);
	addGadget(_redSlider);

	// Calculate Green Slider Dimensions
	buttonRect.y = buttonRect.y + buttonRect.height + 1;

	// Create Green Slider
	_greenSlider = new SliderHorizontal(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);

	_greenSlider->setMinimumValue(0);
	_greenSlider->setMaximumValue(31);
	_greenSlider->setValue(0);

	_greenSlider->setGadgetEventHandler(this);
	addGadget(_greenSlider);

	// Calculate Blue Slider Dimensions
	buttonRect.y = buttonRect.y + buttonRect.height + 1;

	// Create Blue Slider
	_blueSlider = new SliderHorizontal(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);

	_blueSlider->setMinimumValue(0);
	_blueSlider->setMaximumValue(31);
	_blueSlider->setValue(0);

	_blueSlider->setGadgetEventHandler(this);
	addGadget(_blueSlider);

	// Calculate Colour button dimensions
	buttonRect.width = (rect.width >> 2) - 1;
	buttonRect.height = _redSlider->getHeight() * 3 + 2;
	buttonRect.x = rect.x + rect.width - buttonRect.width;
	buttonRect.y = rect.y;

	// Create Colour button
	_colourButton = new Button(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height,"");
	_colourButton->disable();

	addGadget(_colourButton);

	setColour(colour);
}

void ColourPicker::onResize(u16 width, u16 height) {

	// Call base class' method to ensure the basic window resizes correctly
	AmigaWindow::onResize(width, height);

	Rect rect;
	getClientRect(rect);

	// Calculate OK button dimensions
	Rect buttonRect;
	_okButton->getPreferredDimensions(buttonRect);

	buttonRect.width = (rect.width >> 1) - 1;
	buttonRect.x = rect.x;
	buttonRect.y = (rect.y + rect.height) - buttonRect.height;

	_okButton->changeDimensions(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);

	// Calculate cancel button dimensions
	buttonRect.x = rect.x + rect.width - buttonRect.width;
	buttonRect.y = (rect.y + rect.height) - buttonRect.height;

	_cancelButton->changeDimensions(buttonRect.x, buttonRect.y, buttonRect.width, buttonRect.height);
}

u16 ColourPicker::getColour() const {
	return(_colourButton->getBackColour());
}

void ColourPicker::setColour(u16 colour) {
	_colourButton->setBackColour(colour);

	_redSlider->setValue(colour & 31);
	_greenSlider->setValue((colour >> 5) & 31);
	_blueSlider->setValue((colour >> 10) & 31);
}

void ColourPicker::handleReleaseEvent(Gadget &source, const WoopsiPoint& point) {
	if (&source == _cancelButton) {

		// Close the window
		close();
		return;
	} else if (&source == _okButton) {

		// Raise events to event handler
		if (raisesEvents()) {
			_gadgetEventHandler->handleValueChangeEvent(*this);
			_gadgetEventHandler->handleActionEvent(*this);
		}

		// Close the window
		close();
		return;
	}
	
	AmigaWindow::handleReleaseEvent(*this, point);
}

void ColourPicker::handleValueChangeEvent(Gadget& source) {
	_colourButton->setBackColour(woopsiRGB(_redSlider->getValue(), _greenSlider->getValue(), _blueSlider->getValue()));
	_colourButton->markRectsDamaged();

	AmigaWindow::handleValueChangeEvent(*this);
}
