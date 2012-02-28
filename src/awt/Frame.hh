//
// Frame.hh
//

// All rights reserved.
//


#ifndef DEF_Frame

#include "MouseEvent.hh"
#include "MouseListener.hh"
#include "Container.hh"


class Frame : public awt::Container
{
	friend class Dialog;

    public:
	static const unsigned int NOP = 1;
	static const unsigned int REPAINT = 100;
	static const unsigned int RESIZE = 101;

    private:
	unsigned int display_height;
	unsigned int display_width;

	unsigned int width;
	unsigned int height;

	bool isMapped;

	String title;
	NativeGraphics native_graphics;


    public:
	Frame();
	Frame ( String* );
	Frame ( String& );

	virtual Frame* clone();

	virtual void addNotify();
	virtual void removeNotify();
	virtual Component* getParent();
	virtual Graphics* getGraphics();
	virtual Dimension* getPreferredSize();

    private:
	void init();
};


#  define DEF_Frame
#endif
