//
// EventObject.cc
//

// All rights reserved.
//

#include <base/inc.hh>
#include <awt/defs.hh>

#include "EventObject.hh"



EventObject::EventObject ( Object* s ) : source(s) {
	}

Object*
EventObject::getSource() {
	return that.source;
	}



EventObject*
EventObject::clone() {
	return new EventObject(that);
	}
