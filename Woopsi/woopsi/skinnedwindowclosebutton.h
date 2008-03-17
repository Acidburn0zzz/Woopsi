#ifndef _SKINNED_WINDOW_CLOSE_BUTTON_H_
#define _SKINNED_WINDOW_CLOSE_BUTTON_H_

#include <nds.h>
#include "decorationglyphbutton.h"
#include "graphicsport.h"
#include "skin.h"
#include "gadget.h"

using namespace std;

class SkinnedWindowCloseButton : public DecorationGlyphButton {

public:
	SkinnedWindowCloseButton(s16 x, s16 y, const WindowSkin* skin);
	virtual ~SkinnedWindowCloseButton();

	virtual void draw(Rect clipRect);
	virtual void draw();

protected:
	const WindowSkin* _skin;
};

#endif
