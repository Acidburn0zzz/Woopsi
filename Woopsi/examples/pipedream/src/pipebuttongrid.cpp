#include <woopsi.h>

#include "pipebuttongrid.h"
#include "pipebuttongridgenerator.h"
#include "constants.h"
#include "pipebuttonstandard.h"
#include "pipebuttonblock.h"
#include "pipebuttonhorizontal.h"
#include "pipebuttonvertical.h"
#include "pipebuttonl1.h"
#include "pipebuttonl2.h"
#include "pipebuttonl3.h"
#include "pipebuttonl4.h"

PipeButtonGrid::PipeButtonGrid(s16 x, s16 y, u8 rows, u8 columns) : Gadget(x, y, 0, 0, 0) {
	_buttonWidth = PIPE_BUTTON_SIZE;
	_buttonHeight = PIPE_BUTTON_SIZE;
	_flags.borderless = true;
	_isComplete = false;
	
	_rows = rows;
	_columns = columns;

	generateRandomLayout(0);
}

void PipeButtonGrid::reset(u8 level) {
	_activeButtons.clear();
	_isComplete = false;

	while (getGadgetCount() > 0) {
		removeGadget(getGadget(getGadgetCount() - 1));
	}

	generateRandomLayout(level);
}

void PipeButtonGrid::generateRandomLayout(u8 level) {

	srand(woopsiApplication->getVBLCount());

	PipeButtonBase* button = NULL;

	PipeButtonGridGenerator* generator = new PipeButtonGridGenerator(_rows, _columns);
	u8* layout = generator->generateRandomTiles(level / 2);

	for (u8 y = 0; y < _rows; ++y) {
		for (u8 x = 0; x < _columns; ++x) {

			if (x == generator->getStart().getX() &&
				y == generator->getStart().getY()) {

				// Add start button
				if (y == 0) {
					button = new PipeButtonVertical(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
					button->plugTopConnector();
				} else {
					button = new PipeButtonHorizontal(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
					button->plugLeftConnector();
				}

				button->reveal();
				button->disable();
				_startButton = button;

			} else if (x == generator->getEnd().getX() &&
					   y == generator->getEnd().getY()) {

				// Add end button
				if (y == _rows - 1) {
					button = new PipeButtonVertical(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
					button->plugBottomConnector();
				} else {
					button = new PipeButtonHorizontal(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
					button->plugRightConnector();
				}

				button->reveal();
				button->disable();
				_endButton = button;

			} else if ((y == 0) || (x == 0) || (x == _columns - 1) || (y == _rows - 1)) {

				// Add a border button
				button = new PipeButtonBlock(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
				button->reveal();

			} else {
				switch (layout[x + (y * _columns)]) {
					case PipeButtonGridGenerator::TILE_TYPE_HORIZONTAL:
						button = new PipeButtonHorizontal(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_VERTICAL:
						button = new PipeButtonVertical(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_TOP_RIGHT:
						button = new PipeButtonL1(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_BOTTOM_RIGHT:
						button = new PipeButtonL2(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_BOTTOM_LEFT:
						button = new PipeButtonL3(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_TOP_LEFT:
						button = new PipeButtonL4(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
					case PipeButtonGridGenerator::TILE_TYPE_BLOCKING:
						button = new PipeButtonBlock(x * _buttonWidth, y * _buttonWidth, _buttonWidth, _buttonHeight);
						break;
				}
			}

			button->setGadgetEventHandler(this);
			addGadget(button);
		}
	}

	delete layout;

	resize(_columns * _buttonWidth, _rows * _buttonHeight);
}

bool PipeButtonGrid::isButtonActive(PipeButtonBase* button) {
	for (int i = 0; i < _activeButtons.size(); ++i) {
		if (button == _activeButtons[i]) {
			return true;
		}
	}

	return false;
}

void PipeButtonGrid::handleDropEvent(Gadget& source, const WoopsiPoint& point) {

	PipeButtonBase* sourceButton = (PipeButtonBase*)&source;
	PipeButtonBase* destButton;
	
	bool swapped = false;

	for (s32 i = 0; i < getGadgetCount(); ++i) {
		destButton = (PipeButtonBase*)getGadget(i);
		
		// Do not allow swap if the buttons are the same object, the buttons do
		// not collide, the destination cannot swap, or the destination is
		// being dragged
		if (sourceButton == destButton) continue;
		if (!sourceButton->checkCollision(destButton)) continue;
		if (!destButton->canSwap()) continue;
		if (destButton->isBeingDragged()) continue;

		if (isButtonActive(sourceButton)) continue;
		if (isButtonActive(destButton)) continue;
		
		// Exchange button co-ordinates
		s16 destX = destButton->getOriginalX();
		s16 destY = destButton->getOriginalY();
		
		destButton->moveTo(sourceButton->getOriginalX(), sourceButton->getOriginalY());
		destButton->setOriginalCoords(sourceButton->getOriginalX(), sourceButton->getOriginalY());
			
		sourceButton->setOriginalCoords(destX, destY);
		
		swapped = true;
		break;
	}
	
	if (!swapped) sourceButton->resetCoordinates();
}

void PipeButtonGrid::drawContents(GraphicsPort* port) {
	port->drawFilledRect(0, 0, getWidth(), getHeight(), getBackColour());
}

PipeButtonBase* PipeButtonGrid::getStartButton() {
	return _startButton;
}

PipeButtonBase* PipeButtonGrid::getEndButton() {
	return _endButton;
}

bool PipeButtonGrid::increaseFlow(u8 increase) {

	PipeButtonBase* active;
	
	if (_activeButtons.size() == 0) {
		_activeButtons.push_back(getStartButton());
	}

	for (s32 i = 0; i < _activeButtons.size(); ++i) {
		active = _activeButtons[i];

		active->increaseFlowLevel(increase);
	
		if (active->getFlowLevel() >= MAX_PIPE_BUTTON_FLOW) {
		
			_activeButtons.erase(i);
		
			if (!activateNextPipe(active)) {
				return false;
			}
		}
	}
	
	return true;
}

bool PipeButtonGrid::isComplete() {
	return _isComplete;
}

bool PipeButtonGrid::activateNextPipe(PipeButtonBase* activePipe) {

	PipeButtonBase* nextPipe;
	u8 connectionCount = 0;
	u8 connectedCount = 0;
	
	// Work out which of the connectors is still available and activate the
	// outgoing pipe
	if (activePipe->hasAvailableTopConnector()) {
		activePipe->plugTopConnector();
		
		connectionCount++;
		
		// Locate the grid co-ords of the button
		u8 column = (activePipe->getX() - getX()) / _buttonWidth;
		u8 row = (activePipe->getY() - getY()) / _buttonHeight;
		
		if (row > 0) {
		
			// Get the button above this
			nextPipe = getPipeButtonAt(column, row - 1);
			
			if (nextPipe->hasAvailableBottomConnector()) {
				_activeButtons.push_back(nextPipe);
				nextPipe->plugBottomConnector();

				connectedCount++;
			}
		}
	}
		
	if (activePipe->hasAvailableRightConnector()) {
		activePipe->plugRightConnector();
		
		connectionCount++;
		
		// Locate the grid co-ords of the button
		u8 column = (activePipe->getX() - getX()) / _buttonWidth;
		u8 row = (activePipe->getY() - getY()) / _buttonHeight;
		
		// Get the button to the right of this
		nextPipe = getPipeButtonAt(column + 1, row);
		
		if (nextPipe != NULL) {
			if (nextPipe->hasAvailableLeftConnector()) {
				_activeButtons.push_back(nextPipe);
				nextPipe->plugLeftConnector();

				connectedCount++;
			}
		}
	}
	
	if (activePipe->hasAvailableBottomConnector()) {
		activePipe->plugBottomConnector();
		
		connectionCount++;
		
		// Locate the grid co-ords of the button
		u8 column = (activePipe->getX() - getX()) / _buttonWidth;
		u8 row = (activePipe->getY() - getY()) / _buttonHeight;
		
		// Get the button below this
		nextPipe = getPipeButtonAt(column, row + 1);
		
		if (nextPipe != NULL) {
			if (nextPipe->hasAvailableTopConnector()) {
				_activeButtons.push_back(nextPipe);
				nextPipe->plugTopConnector();

				connectedCount++;
			}
		}
	}
	
	if (activePipe->hasAvailableLeftConnector()) {
		activePipe->plugLeftConnector();
		
		connectionCount++;
		
		// Locate the grid co-ords of the button
		u8 column = (activePipe->getX() - getX()) / _buttonWidth;
		u8 row = (activePipe->getY() - getY()) / _buttonHeight;

		// Get the button to the left of this
		nextPipe = getPipeButtonAt(column - 1, row);
					
		if (nextPipe != NULL) {
			if (nextPipe->hasAvailableRightConnector()) {
				_activeButtons.push_back(nextPipe);
				nextPipe->plugRightConnector();

				connectedCount++;
			}
		}
	}

	if (_activeButtons[_activeButtons.size() - 1] == _endButton) {
		_isComplete = true;
	}
	
	return (connectionCount == connectedCount) && (connectionCount > 0);
}

PipeButtonBase* PipeButtonGrid::getPipeButtonAt(s16 column, s16 row) {

	if (row < 0) return NULL;
	if (row >= _rows) return NULL;
	if (column < 0) return NULL;
	if (column >= _columns) return NULL;

	s16 x = column * _buttonWidth;
	s16 y = row * _buttonHeight;
	
	for (s32 i = 0; i < getGadgetCount(); ++i) {
		if (getGadget(i)->getX() - getX() == x) {
			if (getGadget(i)->getY() - getY() == y) {
				return (PipeButtonBase*)getGadget(i);
			}
		}
	}
	
	return NULL;
}

void PipeButtonGrid::redrawActiveButton() {
	for (s32 i = 0; i < _activeButtons.size(); ++i) {
		_activeButtons[i]->markRectsDamaged();
	}
}
