//
// Rectangle.hh
//

// All rights reserved.
//


#ifndef DEF_Rectangle


class Rectangle : public Object {

	public: unsigned int width;
	public: unsigned int height;
	public: int x;
	public: int y;

	public: Rectangle ( unsigned int, unsigned int );
	public: Rectangle ( int, int, unsigned int, unsigned int );
	public: bool contains ( int x, int y );

	public: virtual Rectangle* clone();
	};


#  define DEF_Rectangle
#endif
