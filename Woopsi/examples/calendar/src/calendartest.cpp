// Includes
#include "calendartest.h"
#include "woopsiheaders.h"
#include "debug.h"

void CalendarTest::startup() {

	// Create screen
	AmigaScreen* screen = new AmigaScreen("Test Screen", true, true);
	woopsiApplication->addGadget(screen);

	// Add window
	AmigaWindow* window = new AmigaWindow(0, 13, 256, 179, "Test Window", true, true);
	screen->addGadget(window);

	// Get available area within window
	Rect rect;
	window->getClientRect(rect);
	
	// Add calendar
	_calendar = new Calendar(rect.x, rect.y, rect.width, rect.height, 23, 12, 2013, 0);
	_calendar->setGadgetEventHandler(this);
	window->addGadget(_calendar);
}

void CalendarTest::shutdown() {

	// Call base shutdown method
	Woopsi::shutdown();
}

void CalendarTest::handleActionEvent(Gadget& source) {

	// Short version of the event handler since we know that only one gadget can
	// possibly call this
	Debug::printf("%d/%d/%d", _calendar->getDay(), _calendar->getMonth(), _calendar->getYear());
}
