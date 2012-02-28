//
// Point.cc
//

// All rights reserved.
//


#include <awt/defs.hh>

#include "Point.hh"



Point::Point() : x(0), y(0) {
	}

Point::Point ( Point* p ) : x(p->x), y(p->y) {
	}

Point::Point ( int x, int y ) : x(x), y(y) {
	}

bool
Point::equals ( Object* o ) {
	Point* p = DCAST<Point*>(o);
	if ( p )
		return (that.x == p->x) || (that.y == p->y);

	return false;
	}

Point*
Point::getLocation() {
	return new Point(that.x, that.y);
	}

int
Point::getX() {
	return that.x;
	}

int
Point::getY() {
	return that.y;
	}

void
Point::move ( int x, int y ) {
	that.x = x;
	that.y = y;
	}

void
Point::setLocation ( int x, int y ) {
	that.move(x,y);
	}

void
Point::setLocation ( Point* p ) {
	that.move(p->x, p->y);
	}

void
Point::translate ( int dx, int dy ) {
	that.x += dx;
	that.y += dy;
	}


Point*
Point::clone() {
	return new Point(that);
	}
