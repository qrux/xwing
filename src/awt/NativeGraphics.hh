////////////////////////////////////////////////// -*- Mode: C++ -*-
//
// NativeGraphics.hh
//

// All rights reserved.
//
//////////////////////////////////////////////////


#ifndef DEF_NativeGraphics

#include "defs.hh"
#include "Graphics.hh"
#include "Rectangle.hh"


class NativeGraphics : public Graphics {

	friend class Frame;

	private: unsigned long mask;
	private: XGCValues values;
	private: GC gc;
	private: Region clip_mask;

	private: awt::Font* font;

	private: int cx;
	private: int cy;
	private: int tx;
	private: int ty;
	private: unsigned int width;
	private: unsigned int height;

	////////////////////////////////////////

	private: NativeGraphics();
	public: virtual Graphics* create();
	public: virtual void drawPoint ( int, int );
	public: virtual void drawLine ( int, int, int, int );
	public: virtual void drawRect ( int, int, unsigned int, unsigned int );
	public: virtual void fillRect ( int, int, unsigned int, unsigned int );
	public: virtual void fill3DRect ( int, int, unsigned int, unsigned int );
	public: virtual void draw3DRect ( int, int, unsigned int, unsigned int,
									  bool = false );

	public: virtual void drawString ( String* s, int, int );
	public: virtual void drawString ( String& s, int, int );

	public: virtual void setClip ( int, int, unsigned int, unsigned int );
	public: virtual void setColor ( Color* );
	public: virtual void setFont ( awt::Font* );
	public: virtual Color* getColor();
	public: virtual awt::Font* getFont();
	public: virtual FontMetrics* getFontMetrics();
	public: virtual void translate ( int, int );
	public: virtual void dispose();

	////////////////////////////////////////
	//
	// PRIVATE methods
	//
	////////////////////////////////////////

	private: virtual void pDrawLine ( int, int, int, int );
	private: virtual void pDrawPoint ( int, int );
	private: virtual void initGC();
	private: virtual void updateGC();
	private: virtual void createClip();

	////////////////////////////////////////
	//
	// REQUIRED methods
	//
	////////////////////////////////////////

	public: NativeGraphics ( NativeGraphics& );
	public: NativeGraphics& operator = ( NativeGraphics& );
	private: virtual void copy ( NativeGraphics& );

	public: virtual bool equals ( Object& );
	public: virtual NativeGraphics* clone();
	};

#  define DEF_NativeGraphics
#endif // DEF_NativeGraphics


//////////////////////////////////////////////////
//

// Date:	21 Jul 1999
//
//////////////////////////////////////////////////
