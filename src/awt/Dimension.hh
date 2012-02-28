//
// Dimension.hh
//

// All rights reserved.
//


#ifndef DEF_Dimension


class Dimension : public Object {

	public: unsigned int width;
	public: unsigned int height;

	public: Dimension();
	public: Dimension ( unsigned int, unsigned int );
	public: virtual bool equals ( Object* );
	public: virtual double getHeight();
	public: virtual double getWidth();
	public: virtual Dimension* getSize();
	public: virtual void setSize ( Dimension* );
	public: virtual void setSize ( unsigned int, unsigned int );
	public: virtual void setSize ( double, double );

	public: virtual Dimension* clone();
	};


#  define DEF_Dimension
#endif
