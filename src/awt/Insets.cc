//
// Insets.cc
//
// Native Swing C++ Library -- Xwing

//



#include <awt/defs.hh>

#include "Insets.hh"



Insets::Insets ( unsigned int top, unsigned int left,
				 unsigned int bottom, unsigned int right ) :
		top(top), left(left), bottom(bottom), right(right) {
	}


/*
bool
Insets::equals ( Object& obj ) {
	try {
		Insets& rhs = DC<Insets&>(obj);

		return
			(that.top == rhs.top) |
			(that.left == rhs.left) |
			(that.bottom == rhs.bottom) |
			(that.right == rhs.right);
		}
	catch ( ... ) {
		return false;
		}
	}
*/


Insets*
Insets::clone() {
	return new Insets(that);
	}
