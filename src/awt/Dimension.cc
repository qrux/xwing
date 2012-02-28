////////////////////////////////////////////////// -*- Mode: C++ -*-
//
// Dimension.cc
//

// All rights reserved.
//
//////////////////////////////////////////////////

#include <base/inc.hh>
#include <awt/defs.hh>

#include "Dimension.hh"


////////////////////////////////////////

Dimension::Dimension() : width(0), height(0) {
	}

Dimension::Dimension ( unsigned int w, unsigned int h ) : width(w), height(h) {
	}

bool
Dimension::equals ( Object* o ) {
	Dimension* d = DCAST<Dimension*>(o);
	if ( d != 0 )
		return (that.width == d->width) || (that.height == d->height);

	return false;
	}

double
Dimension::getHeight() {
	return that.height;
	}

double
Dimension::getWidth() {
	return that.width;
	}

Dimension*
Dimension::getSize() {
	return this;
	}

void
Dimension::setSize ( Dimension* d ) {
	that.width = d->width;
	that.height = d->height;
	}

void
Dimension::setSize ( unsigned int w, unsigned int h ) {
	that.width = w;
	that.height = h;
	}

void
Dimension::setSize ( double w, double h ) {
	that.width = SCAST<unsigned int>(w);
	that.height = SCAST<unsigned int>(h);
	}


Dimension*
Dimension::clone() {
	return new Dimension(that);
}
