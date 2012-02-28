//
// XLabel.cc
//

// All rights reserved.
//


#include <xwing/defs.hh>
#include <xwing/XComponent.hh>
#include "XLabel.hh"




XLabel::XLabel() : psize(new Dimension()) {
	that.setForeground(Color::lavender->clone());
	}

XLabel::XLabel ( String* s ) : label(s->clone()), psize(new Dimension()) {
	that.setForeground(Color::lavender->clone());
	}

Dimension*
XLabel::getPreferredSize() {
	unsigned int pwidth, pheight;
	FontMetrics* m = that.getFontMetrics(that.getFont());

	if ( m ) {
		pwidth = m->stringWidth(that.label);
		pheight = m->getHeight() << 1;

		delete m;

		that.psize = new Dimension(pwidth, pheight);
		}

	return that.psize;
	}

void
XLabel::setText ( String& text )
{
	that.label = text.clone();
	that.repaint();
}


void
XLabel::setText ( String *text )
{
	that.label = text->clone();
	that.repaint();
}


void
XLabel::paint ( Graphics* g ) {
	if ( that.label->length() ) {
		Dimension* size = that.getSize();

		FontMetrics* m = g->getFontMetrics();
		unsigned int x = (size->width - m->stringWidth(that.label)) / 2;
		unsigned int y = (size->height - m->getHeight()) / 2;

		delete m;

		g->drawString(that.label, 0, y);
		}
	}


XLabel*
XLabel::clone() {
	return new XLabel(that);
	}
