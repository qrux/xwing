//
// Color.hh
//

// All rights reserved.
//


#ifndef DEF_Color


class Color : public Object {

	public: static const unsigned int RED_MASK   = 0x000000ff;
	public: static const unsigned int GREEN_MASK = 0x0000ff00;
	public: static const unsigned int BLUE_MASK  = 0x00ff0000;
	public: static const unsigned int ALPHA_MASK = 0xff000000;

	public: static Color* black;
	public: static Color* gray;
	public: static Color* darkgray;
	public: static Color* white;
	public: static Color* lavender;

	private: unsigned int alpha;
	private: unsigned int red;
	private: unsigned int green;
	private: unsigned int blue;

	////////////////////////////////////////

	public: Color ( unsigned int );
	public: Color ( unsigned int, unsigned int, unsigned int );
	public: unsigned int getAlpha();
	public: unsigned int getRed();
	public: unsigned int getGreen();
	public: unsigned int getBlue();
	public: unsigned int getRGB();

    public: virtual Color* clone();
	};


#  define DEF_Color
#endif
