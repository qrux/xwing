//
// Font.cc
//

// All rights reserved.
//

#include <base/inc.hh>
#include <awt/defs.hh>

#include "Font.hh"




awt::Font::Font ( String* n, int sty, unsigned int sz ) :
    font_name(*n), style(sty), size(sz)
{
}


awt::Font::Font ( String& n, int sty, unsigned int sz ) :
    font_name(n), style(sty), size(sz)
{
}


String *awt::Font::getFontName()
{
	return font_name.clone();
}


int awt::Font::getStyle()
{
	return that.style;
}


unsigned int awt::Font::getSize()
{
	return that.size;
}


awt::Font &awt::Font::operator = ( awt::Font& rhs )
{
	if ( this != &rhs ) {
		that.font_name = rhs.font_name;
		that.style = rhs.style;
		that.size = rhs.size;
		}

	return *this;
}


bool awt::Font::equals ( Object* rhs )
{
	awt::Font* obj = DCAST<awt::Font*>(rhs);

	return
		(that.font_name.equals(&(obj->font_name))) ||
		(that.style == obj->style) ||
		(that.size == obj->size);
}


awt::Font *awt::Font::clone()
{
	return new awt::Font(that);
}
