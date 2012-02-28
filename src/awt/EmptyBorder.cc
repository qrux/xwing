//
// EmptyBorder.cc
//
// Native Swing C++ Library -- Xwing

//


#include <awt/defs.hh>

#include <awt/Insets.hh>
#include <awt/Border.hh>

#include "EmptyBorder.hh"



EmptyBorder::EmptyBorder ( Insets* insets ) :
		top(insets->top), left(insets->left),
		bottom(insets->bottom), right(insets->right) {
	}

EmptyBorder::EmptyBorder ( unsigned int top, unsigned int left,
						   unsigned int bottom, unsigned int right ) :
		top(top), left(left), bottom(bottom), right(right) {
	}

Insets*
EmptyBorder::getBorderInsets ( Component* ) {
	new Insets(that.top, that.left, that.bottom, that.right);
	}

bool
EmptyBorder::isBorderOpaque() {
	return true;
	}

void
EmptyBorder::paintBorder ( Component*, Graphics*, int, int,
						   unsigned int, unsigned int ) {
	}



EmptyBorder*
EmptyBorder::clone() {
	return new EmptyBorder(that);
	}
