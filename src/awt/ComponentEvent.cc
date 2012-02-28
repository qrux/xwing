////////////////////////////////////////////////// -*- Mode: C++ -*-
//
// ComponentEvent.cc
//

// All rights reserved.
//
//////////////////////////////////////////////////

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
#include "ComponentEvent.hh"

#include <awt/InputEvent.hh>
#include <awt/MouseEvent.hh>
#include <awt/EventListener.hh>
#include <awt/MouseListener.hh>
#include <awt/Component.hh>


////////////////////////////////////////

ComponentEvent::ComponentEvent ( Component* source, int id ) :
		AWTEvent(source,id) {
	}

Component*
ComponentEvent::getComponent() {
	return DCAST<Component*>(that.getSource());
	}

////////////////////////////////////////
//
// REQUIRED methods
//
////////////////////////////////////////


ComponentEvent*
ComponentEvent::clone() {
	return new ComponentEvent(that);
	}

// void
// ComponentEvent::output ( TabStream& lhs ) {
// 	}

//////////////////////////////////////////////////
//

// Date:	29 Jul 1999
//
//////////////////////////////////////////////////
