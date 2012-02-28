//
// Graphics.cc
//

// All rights reserved.
//


#include <awt/defs.hh>

#include <awt/Color.hh>
#include <awt/Font.hh>
#include <awt/FontMetrics.hh>

#include "Graphics.hh"


/* 
 * Default font.
 */
awt::Font* Graphics::SWING_FONT = new awt::Font(new String("-*-lucida-bold-r-*-*-12-*-*-*-*-*-*-*"), 2, 12);



Graphics::Graphics()
{
}


FontMetrics *Graphics::getFontMetrics ( awt::Font* font )
{
	return new FontMetrics(font);
}
