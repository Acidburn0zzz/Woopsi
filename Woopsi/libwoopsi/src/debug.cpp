#include "amigascreen.h"
#include "amigawindow.h"
#include "debug.h"
#include "hardware.h"
#include "pad.h"
#include "scrollingtextbox.h"
#include "tinyfont.h"
#include "woopsi.h"
#include "woopsifuncs.h"
#include "woopsistring.h"

using namespace WoopsiUI;

Debug* Debug::_debug = NULL;

Debug::Debug() {
	_screen = NULL;
	_window = NULL;
	_textBox = NULL;
	_style = NULL;

	createGUI();
}

Debug::~Debug() {
	_screen->close();

	delete _style->font;
	delete _style;
}

void Debug::createDebug() {
	if (_debug == NULL) {
		_debug = new Debug();
	}
}

void Debug::output(const WoopsiString& text) {
	if (DEBUG_ACTIVE) {
		if (woopsiApplication != NULL) {
			createDebug();

			_debug->_textBox->appendText(">");
			_debug->_textBox->appendText(text);
			_debug->_textBox->appendText("\n");
		}
	}
}

void Debug::printf(const char* format, ...) {

	va_list args;
	va_start(args, format);

	WoopsiString str;
	str.format(format, args);

	va_end(args);

	_debug->output(str);
}


void Debug::busyWait() {
	if (DEBUG_ACTIVE) {
		while (!Hardware::getPad().isHeld(Pad::KEY_CODE_B)) {
			Hardware::waitForVBlank();
		}
		while (Hardware::getPad().isHeld(Pad::KEY_CODE_B)) {
			Hardware::waitForVBlank();
		}
	}
}

void Debug::createGUI() {

	// Add debug screen
	if (_screen == NULL) {
		_screen = new AmigaScreen("Debug", true, true);
		woopsiApplication->addGadget(_screen);
	}

	// Add debug window
	if (_window == NULL) {
		_window = new AmigaWindow(0, 13, 256, 179, "Debug Output", false, false);
		_screen->addGadget(_window);
	}

	// Create style
	if (_style == NULL) {
		_style = new GadgetStyle();
		_style->colours.back = defaultGadgetStyle->colours.back;
		_style->colours.shine = defaultGadgetStyle->colours.shine;
		_style->colours.highlight = defaultGadgetStyle->colours.highlight;
		_style->colours.shadow = defaultGadgetStyle->colours.shadow;
		_style->colours.fill = defaultGadgetStyle->colours.fill;
		_style->colours.dark = defaultGadgetStyle->colours.dark;
		_style->font = new TinyFont();
		_style->glyphFont = defaultGadgetStyle->glyphFont;
	}

	// Add textbox
	if (_textBox == NULL) {
		Rect rect;
		_window->getClientRect(rect);

		_textBox = new ScrollingTextBox(rect.x, rect.y, rect.width, rect.height, "", 50, _style);
		_window->addGadget(_textBox);
		_textBox->setTextAlignmentHoriz(MultiLineTextBox::TEXT_ALIGNMENT_HORIZ_LEFT);
		_textBox->setTextAlignmentVert(MultiLineTextBox::TEXT_ALIGNMENT_VERT_TOP);
		_textBox->appendText("Woopsi Version ");
		_textBox->appendText(WOOPSI_VERSION);
		_textBox->appendText("\n");
		_textBox->appendText(WOOPSI_COPYRIGHT);
		_textBox->appendText("\n");
	}
}

void Debug::flipToTopScreen() {
	if (!DEBUG_ACTIVE) return;
	if (woopsiApplication == NULL) return;
	
	createDebug();
	_debug->_screen->flipToTopScreen();
}

void Debug::flipToBottomScreen() {
	if (!DEBUG_ACTIVE) return;
	if (woopsiApplication == NULL) return;
	
	createDebug();
	_debug->_screen->flipToBottomScreen();
}

void Debug::flipScreens() {
	if (!DEBUG_ACTIVE) return;
	if (woopsiApplication == NULL) return;
	
	createDebug();
	_debug->_screen->flipScreens();
}

void Debug::raiseToTop() {
	if (!DEBUG_ACTIVE) return;
	if (woopsiApplication == NULL) return;
	
	createDebug();
	_debug->_screen->raiseToTop();
}

void Debug::lowerToBottom() {
	if (!DEBUG_ACTIVE) return;
	if (woopsiApplication == NULL) return;
	
	createDebug();
	_debug->_screen->lowerToBottom();
}
