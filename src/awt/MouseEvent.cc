//
// MouseEvent.cc
//

// All rights reserved.
//


#include <awt/inc.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include <awt/Color.hh>
#include <awt/Font.hh>
#include <awt/FontMetrics.hh>
#include <awt/Dimension.hh>
#include <awt/Rectangle.hh>
#include <awt/Graphics.hh>
#include <awt/Component.hh>
#include <awt/ComponentEvent.hh>
#include <awt/InputEvent.hh>

#include "MouseEvent.hh"




MouseEvent::MouseEvent ( Component* source, int id, long, int,
						 int x, int y, int, bool ) :
		InputEvent(source, id), x(x), y(y) {
	}

int
MouseEvent::getX() {
	return that.x;
	}

int MouseEvent::getY() {
	return that.y;
	}


MouseEvent*
MouseEvent::clone() {
	return new MouseEvent(that);
	}
