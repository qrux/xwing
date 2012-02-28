//
// ChangeEvent.cc
//
// Native Swing C++ Library -- Xwing

//


#include <xwing/defs.hh>
#include "ChangeEvent.hh"


ChangeEvent::ChangeEvent ( Object* s ) :
    EventObject(s)
{
}


ChangeEvent*
ChangeEvent::clone()
{
	return new ChangeEvent(that);
}
