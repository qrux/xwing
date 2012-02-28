//
// Component.cc
//

// All rights reserved.
//


#include <awt/defs.hh>

#include <awt/Color.hh>
#include <awt/Font.hh>
#include <awt/FontMetrics.hh>
#include <awt/Dimension.hh>
#include <awt/Rectangle.hh>
#include <awt/Insets.hh>
#include <awt/Border.hh>
#include <awt/Graphics.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include <awt/ComponentEvent.hh>
#include <awt/InputEvent.hh>
#include <awt/MouseEvent.hh>

#include <awt/EventListener.hh>
#include <awt/MouseListener.hh>

#include "Component.hh"


Component::Component() :
    parent(0), graphics(0),
    x(0), y(0), width(0), height(0), border(0),
    font(Graphics::SWING_FONT->clone()),
    //foreground(Color::black->clone()),
    //background(Color::gray->clone())
    ml_list(new PtrList<MouseListener>())
{
	// font = Graphics::SWING_FONT->clone();
	foreground = Color::black->clone();
	background = Color::gray->clone();
}


Border* Component::getBorder()
{
	return that.border;
}


Dimension* Component::getSize()
{
	return new Dimension(that.width, that.height);
}


Rectangle* Component::getBounds()
{
	return new Rectangle(that.x, that.y, that.width, that.height);
}


int Component::getX()
{
	return that.x;
}


int Component::getY()
{
	return that.y;
}


Component *Component::getParent()
{
	return CCAST<Component*>(that.parent);
}


Graphics *Component::getGraphics()
{
	return that.graphics;
}


awt::Font *Component::getFont()
{
	return that.font;
}


FontMetrics *Component::getFontMetrics ( awt::Font *font )
{
	return new FontMetrics(font);
}


Color *Component::getForeground()
{
	return that.foreground;
}


Color *Component::getBackground()
{
	return that.background;
}


Component *Component::getComponentAt ( int x, int y )
{
	if ( that.getBounds()->contains(x,y) )
		return this;

	return 0;
}


void Component::setBorder ( Border* border )
{
	if ( that.border != border )
		that.border = border->clone();
}


void Component::setFont ( awt::Font* font )
{
	that.font = font->clone();
}


void Component::setForeground ( Color* c )
{
	that.foreground = c->clone();
}


void Component::setBackground ( Color* c )
{
	that.background = c->clone();
}


void Component::setSize ( Dimension* d )
{
	that.setSize(d->width, d->height);
}


void Component::setSize ( unsigned int w, unsigned int h )
{
	that.width = w;
	that.height = h;
}


void Component::setLocation ( unsigned int x, unsigned int y )
{
	that.x = x;
	that.y = y;
}


void Component::paint ( Graphics* g )
{
	////////////////////////////////////////
	// Paint border.
	////////////////////////////////////////

	if ( that.border )
		that.border->paintBorder(this, g, that.x, that.y,
					 that.width, that.height);
}


void Component::paintAll ( Graphics* g )
{
	if ( g )
		that.paint(g);
}


void Component::repaint()
{
	if ( that.graphics )
		that.update(that.graphics);
}


void Component::update ( Graphics* g )
{
	////////////////////////////////////////
	// Copy GC to component.
	////////////////////////////////////////

	if ( g )
	{
		if ( that.graphics != g )
		{
			if ( that.graphics )
				that.graphics->dispose();
			that.graphics = g->create();
		}

		////////////////////////////////////////
		// Fill background with color.
		////////////////////////////////////////

		that.graphics->setColor(that.background);
		that.graphics->fillRect(0, 0, that.width, that.height);

		////////////////////////////////////////
		// Paint myself.
		////////////////////////////////////////

		that.graphics->setColor(that.foreground);
		that.paint(that.graphics);
	}
}


void Component::validate()
{
	Dimension* psize;

	psize = that.getPreferredSize();
	cout << "psize: " << *psize << endl;
}


void Component::removeNotify()
{
	if ( that.graphics )
		that.graphics->dispose();
	that.graphics = 0;
}


void Component::addMouseListener ( MouseListener* l )
{
	that.ml_list->add(l);
}


void Component::dispatchEvent ( AWTEvent* evt )
{
	that.processEvent(evt);
}


void Component::processEvent ( AWTEvent* evt )
{
	Component* parent = that.getParent();
	if ( parent )
		parent->processEvent(evt);

	unsigned int count = that.ml_list->size();

	if ( count )
	{
		MouseEvent* mouse_event = DCAST<MouseEvent*>(evt);
		if ( mouse_event )
		{
			that.processMouseEvent(mouse_event);
		}
	}
}


void Component::processMouseEvent ( MouseEvent* evt )
{
	MouseListener* l;
	unsigned int count = that.ml_list->size();

	for ( int i = 0; i < count; ++i )
	{
		l = that.ml_list->getPtr(i);

		switch ( evt->getId() )
		{
		    case MouseEvent::MOUSE_PRESSED:
			    l->mousePressed(evt);
			    break;

		    case MouseEvent::MOUSE_RELEASED:
			    l->mouseReleased(evt);
			    break;

		    case MouseEvent::MOUSE_ENTERED:
			    l->mouseEntered(evt);
			    break;

		    case MouseEvent::MOUSE_EXITED:
			    l->mouseExited(evt);
			    break;

		    case MouseEvent::MOUSE_CLICKED:
			    l->mouseClicked(evt);
			    break;
		}
	}
}
