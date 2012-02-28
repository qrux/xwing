//
// Font.hh
//

// All rights reserved.
//


#ifndef DEF_Font


namespace awt {


class Font : public Object
{ 
    public:
	Font ( String*, int, unsigned int );
	Font ( String&, int, unsigned int );
	virtual String* getFontName();
	virtual int getStyle();
	virtual unsigned int getSize();


    public:
	virtual bool equals ( Object* );
	virtual Font* clone();
	virtual Font &operator= ( Font & );

    private:
	String font_name;
	int style;
	unsigned int size;
};


}


#  define DEF_Font
#endif
