////////////////////////////////////////////////// -*- Mode: C++ -*-
//
// ActionEvent.cc
//

// All rights reserved.
//
//////////////////////////////////////////////////

#include <base/inc.hh>
#include <awt/defs.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include "ActionEvent.hh"


////////////////////////////////////////

ActionEvent::ActionEvent ( Object* s, int i, String* cmd ) :
		AWTEvent(s,i), command(*cmd) {
	}

ActionEvent::ActionEvent ( Object* s, int i, String& cmd ) :
		AWTEvent(s,i), command(cmd) {
	}

ActionEvent::ActionEvent ( Object* s, String* cmd ) :
		AWTEvent(s, ActionEvent::ACTION_PERFORMED), command(cmd) {
	}

ActionEvent::ActionEvent ( Object* s, String& cmd ) :
		AWTEvent(s, ActionEvent::ACTION_PERFORMED), command(cmd) {
	}

////////////////////////////////////////
//
// REQUIRED methods
//
////////////////////////////////////////

ActionEvent*
ActionEvent::clone() {
	return new ActionEvent(that);
	}

// void
// ActionEvent::output ( TabStream& lhs ) {
// 	}

//////////////////////////////////////////////////
//

// Date:	16 July 1999
//
//////////////////////////////////////////////////
