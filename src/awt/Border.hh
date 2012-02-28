//
// Border.hh
//
// Native Swing C++ Library -- Xwing

// All rights reserved.
//


#ifndef DEF_Border


class Component;
class Graphics;


class Border : public Object
{
    protected:
	Border();

    public:
	virtual Insets* getBorderInsets ( Component* ) = 0;
	virtual bool isBorderOpaque() = 0;
	virtual void paintBorder ( Component*, Graphics*, int, int, unsigned int, unsigned int ) = 0;
	virtual Border* clone() = 0;
};


#  define DEF_Border
#endif
