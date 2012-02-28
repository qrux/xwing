//
// Graphics.hh
//

// All rights reserved.
//


#ifndef DEF_Graphics


class Graphics : public Object
{
    public:
	static awt::Font* SWING_FONT;

    protected:
	Graphics();

    public:
	virtual Graphics* create() = 0;
	virtual void drawPoint ( int, int ) = 0;
	virtual void drawLine ( int, int, int, int ) = 0;
	virtual void drawRect ( int, int, unsigned int, unsigned int ) = 0;
	virtual void fillRect ( int, int, unsigned int, unsigned int ) = 0;
	virtual void fill3DRect ( int, int, unsigned int, unsigned int ) = 0;
	virtual void draw3DRect ( int, int, unsigned int, unsigned int, bool = false ) = 0;

	virtual void drawString ( String*, int, int ) = 0;
	virtual void drawString ( String&, int, int ) = 0;

	virtual void setClip ( int, int, unsigned int, unsigned int ) = 0;
	virtual void setColor ( Color* ) = 0;
	virtual void setFont ( awt::Font* ) = 0;
	virtual Color* getColor() = 0;
	virtual awt::Font* getFont() = 0;
	virtual FontMetrics* getFontMetrics ( awt::Font* );
	virtual FontMetrics* getFontMetrics() = 0;
	virtual void translate ( int, int ) = 0;
	virtual void dispose() = 0;

	virtual Graphics* clone() = 0;
	};


#  define DEF_Graphics
#endif
