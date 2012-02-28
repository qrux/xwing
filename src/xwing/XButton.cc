//
// XButton.cc
//

// All rights reserved.
//


#include <xwing/defs.hh>
#include <xwing/XComponent.hh>
#include <xwing/AbstractButton.hh>
#include <xwing/XButton.hh>



XButton::XButton() : psize(new Dimension())
{
	that.init();
}

XButton::XButton ( String* s ) :
    AbstractButton(),
    MouseAdapter(),
    label(s->clone()),
    psize(new Dimension())
{

	that.init();
}

XButton::XButton ( String& s ) :
    AbstractButton(),
    MouseAdapter(),
    label(s.clone()),
    psize(new Dimension())
{

	that.init();
}

Dimension*
XButton::getPreferredSize()
{
	unsigned int pwidth, pheight;
	FontMetrics* m = that.getFontMetrics(that.getFont());

	if ( m )
	{
		pwidth = m->stringWidth(that.label);
		pheight = m->getHeight();

		pwidth += pwidth >> 2;
		pheight *= 2;

		delete m;

		that.psize = new Dimension(pwidth, pheight);
	}

	return that.psize;
}

void
XButton::setText ( String& s )
{
	that.label = s.clone();
	that.repaint();
}



void
XButton::paint ( Graphics* g )
{
	////////////////////////////////////////
	// Colors if button pressed.
	////////////////////////////////////////

	if ( that.isMousePressed && that.isMouseInside )
		that.setBackground(Color::darkgray->clone());
	else
		that.setBackground(Color::gray->clone());
		
	Dimension* size = that.getSize();

	g->setColor(that.getBackground());
	g->fill3DRect(0, 0, size->width, size->height);

	////////////////////////////////////////
	// Draw comp boundary.
	////////////////////////////////////////

	// g->draw3DRect(0, 0, size->width, size->height);

	////////////////////////////////////////
	// Draw label.
	////////////////////////////////////////

	if ( that.label->length() )
	{
		g->setColor(that.getForeground());

		FontMetrics* m = g->getFontMetrics();
		unsigned int sw = m->stringWidth(that.label);
		unsigned int sh = m->getHeight();
		unsigned int x = (size->width - sw) / 2;
		unsigned int y = (size->height - sh) / 2;

		delete m;

		g->drawString(that.label, x, y);
	}

	////////////////////////////////////////
	// Restore original color.
	////////////////////////////////////////
}

void
XButton::mouseEntered ( MouseEvent* evt )
{
	if ( that.isMouseInside == false )
	{
		that.isMouseInside = true;

		if (that.isMousePressed == true)
		{
			that.repaint();
		} }
}

void
XButton::mouseExited ( MouseEvent* evt )
{
	if ( that.isMouseInside == true )
	{
		that.isMouseInside = false;

		if ( that.isMousePressed == true )
		{
			repaint();
		} }
}

void
XButton::mousePressed ( MouseEvent* evt )
{
#ifdef DEBUG_MOUSE
	out << "XButton::mousePressed()." << nl;
#endif // DEBUG_MOUSE

	that.isMousePressed = true;
	repaint();
}

void
XButton::mouseReleased ( MouseEvent* evt )
{
#ifdef DEBUG_MOUSE
	out << "XButton::mouseReleased() -- PAIR." << nl;
#endif // DEBUG_MOUSE

	that.isMousePressed = false;
	if ( that.isMouseInside == true )
		repaint();
}

void
XButton::mouseClicked ( MouseEvent* evt )
{
#ifdef DEBUG_MOUSE
	out << "XButton::mouseClicked()!" << nl;
#endif // DEBUG_MOUSE

	that.fireActionPerformed(new ActionEvent(this, that.label));
}

void
XButton::init()
{
	that.setForeground(Color::black->clone());
	that.addMouseListener(this);
}


XButton*
XButton::clone()
{
	return new XButton(that);
}
