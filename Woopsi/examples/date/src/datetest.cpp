// Includes
#include "datetest.h"
#include "woopsiheaders.h"
#include "debug.h"

void DateTest::startup() {

	Date* date = new Date(6, 10, 2008);
	for (u8 i = 0; i < 20; i++) {
		date->addDays(-1);
		Debug::printf("%d/%d/%d", date->getDay(), date->getMonth(), date->getYear());
	}
}

void DateTest::shutdown() {

	// Call base shutdown method
	Woopsi::shutdown();
}
