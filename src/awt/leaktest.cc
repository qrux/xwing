#include <stdlib.h>
#include <awt/inc.hh>


class MyFrame : public Frame
{
    public:
	MyFrame ( String *title ) : Frame(title)
	{
	}

	virtual void removeNotify()
	{
	}
};


int main ( int argc, char** argv )
{
	if ( argc < 2 )
	{
		cerr << "Usage: " << argv[0] << " <iters>." << endl;
		exit(1);
	}


	unsigned int iters = atoi(argv[1]);

	MyFrame frame(new String("GC tester"));
	frame.setSize(200,100);
	frame.addNotify();

	Graphics* g = frame.getGraphics();

	Object* o;
	String types[] =
		{ "awt::Font",
		  "Color",
		  "Rectangle",
		  "Dimension",
		  "Point" };

	Object* array[] =
		{ new awt::Font(new String("fixed"), 0, 12),
		  new Color(0,127,255),
		  new Rectangle(400, 300),
		  new Dimension(),
		  new Point() };

	for ( int typeCount = 0; typeCount < 5; ++typeCount )
	{
		cerr << "Type: " << types[typeCount] << endl;

		for ( int i = 0; i < iters; ++i )
		{
			o = array[typeCount]->clone();
		}
	}

	Graphics* ng = g;

	cerr << "Type: " << "NativeGraphics" << endl;
	sleep(3);

	for ( int i = 0; i < iters; ++i )
	{
		ng = g->clone();
		ng->dispose();
	}

	XUnmapWindow(glob::display, glob::win);
	XCloseDisplay(glob::display);

	glob::display = 0;

	return 0;
}
