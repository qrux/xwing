//
// FontMetrics.hh
//

// All rights reserved.
//


#ifndef DEF_FontMetrics


class FontMetrics : public Object {

	private: XFontStruct* font_info;


	public: FontMetrics ( awt::Font* f );
	public: virtual unsigned int getAscent();
	public: virtual unsigned int getHeight();
	public: virtual unsigned int stringWidth ( String* );
	public: virtual unsigned int stringWidth ( String& );

	public: virtual FontMetrics* clone();
	};


#  define DEF_FontMetrics
#endif
