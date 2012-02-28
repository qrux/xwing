//
// Color.cc
//

// All rights reserved.
//


#include <base/inc.hh>
#include <awt/defs.hh>

#include "Color.hh"

Color* Color::black = new Color(0,0,0);
Color* Color::gray = new Color(204,204,204);
Color* Color::darkgray = new Color(153,153,153);
Color* Color::white = new Color(255,255,255);
Color* Color::lavender = new Color(102,102,153);



Color::Color ( unsigned int rgb ) :
    alpha(255),
    red((rgb & RED_MASK)),
    green((rgb & GREEN_MASK) >> 8),
    blue((rgb & BLUE_MASK) >> 16)
{
}


Color::Color ( unsigned int r, unsigned int g, unsigned int b ) :
    alpha(255), red(r), green(g), blue(b)
{
	if ( that.red > 255 )
		that.red %= 255;
	if ( that.green > 255 )
		that.green %= 255;
	if ( that.blue > 255 )
		that.blue %= 255;
}


Color* Color::clone()
{
	return new Color(that);
}


unsigned int Color::getAlpha()
{
	return that.alpha;
}


unsigned int Color::getRed()
{
	return that.red;
}


unsigned int Color::getGreen()
{
	return that.green;
}


unsigned int Color::getBlue()
{
	return that.blue;
}


unsigned int Color::getRGB()
{
	return
		(that.alpha << 24) +
		(that.red << 16)   +
		(that.green << 8)  +
		(that.blue);
}

