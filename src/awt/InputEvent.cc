//
// InputEvent.cc
//

// All rights reserved.
//


#include <awt/defs.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include <awt/Color.hh>
#include <awt/Font.hh>
#include <awt/FontMetrics.hh>
#include <awt/Dimension.hh>
#include <awt/Rectangle.hh>
#include <awt/Insets.hh>
#include <awt/Border.hh>
#include <awt/Graphics.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include <awt/ComponentEvent.hh>
#include <awt/InputEvent.hh>
#include <awt/MouseEvent.hh>

#include <awt/EventListener.hh>
#include <awt/MouseListener.hh>

#include <awt/Component.hh>
#include <awt/ComponentEvent.hh>

#include "InputEvent.hh"


////////////////////////////////////////

InputEvent::InputEvent ( Component* source, int id ) :
		ComponentEvent(source, id) {

	that.time = ::time(0);
	}

void
InputEvent::consume() {
	that.AWTEvent::consume();
	}

bool
InputEvent::isConsumed() {
	return that.AWTEvent::isConsumed();
	}

long
InputEvent::getWhen() {
	return that.time;
	}

////////////////////////////////////////
//
// REQUIRED methods
//
////////////////////////////////////////


// InputEvent*
// InputEvent::clone() {
// 	return new InputEvent(that);
// 	}

// void
// InputEvent::output ( TabStream& lhs ) {
// 	}

//////////////////////////////////////////////////
//

// Date:	29 Jul 1999
//
//////////////////////////////////////////////////
