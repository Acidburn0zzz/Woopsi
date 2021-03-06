// Includes
#include "keytest.h"
#include "woopsiheaders.h"

void KeyTest::startup() {
	
	/* Code below creates the output screen and associated gadgets */
	// Create screen
	AmigaScreen* outScreen = new AmigaScreen("Ouput Screen", true, false);
	woopsiApplication->addGadget(outScreen);
	
	// Move output screen to top display
	outScreen->flipToTopScreen();

	// Add output window
	AmigaWindow* window = new AmigaWindow(0, 13, 256, 179, "Key Test Window", true, false);
	outScreen->addGadget(window);

	// Get available area within window
	Rect rect;
	window->getClientRect(rect);
	
	// Add textbox
	_output = new MultiLineTextBox(rect.x, rect.y, rect.width, rect.height, "", 0, 0);
	_output->showCursor();
	window->addGadget(_output);
	
	/* Code below creates input screen and associated gadgets */
	// Create screen
	AmigaScreen* inScreen = new AmigaScreen("Input Screen", true, false);
	woopsiApplication->addGadget(inScreen);

	// Create keyboard
	_keyboard = new WoopsiKeyboard(0, 13, 0);
	_keyboard->setKeyboardEventHandler(_output);
	inScreen->addGadget(_keyboard);
}

void KeyTest::shutdown() {

	// Call base shutdown method
	Woopsi::shutdown();
}
