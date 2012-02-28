//
// Point.hh
//

// All rights reserved.
//


#ifndef DEF_Point


class Point : public Object {

	private: int x;
	private: int y;

	public: Point();
	public: Point ( Point* );
	public: Point ( int, int );
	public: virtual bool equals ( Object* );
	public: virtual Point* getLocation();
	public: virtual int getX();
	public: virtual int getY();
	public: virtual void move ( int, int );
	public: virtual void setLocation ( int, int );
	public: virtual void setLocation ( Point* );
	public: virtual void translate ( int, int );

	public: virtual Point* clone();
	};


#  define DEF_Point
#endif
