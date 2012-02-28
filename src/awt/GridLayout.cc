//
// GridLayout.cc
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

#include <awt/Component.hh>
#include <awt/LayoutManager.hh>
#include <awt/Container.hh>
#include "GridLayout.hh"


////////////////////////////////////////

GridLayout::GridLayout ( unsigned int r, unsigned int c ) :
		rows(r), cols(c), hgap(5), vgap(5) {
	}

GridLayout::GridLayout ( unsigned int r, unsigned int c,
						 unsigned int h, unsigned int v ) :
		rows(r), cols(c), hgap(h), vgap(v) {
	}

void
GridLayout::addLayoutComponent ( String*, Component* ) {
	}

void
GridLayout::addLayoutComponent ( String&, Component* ) {
	}

void
GridLayout::removeLayoutComponent ( Component* ) {
	}

Dimension
GridLayout::minimumLayoutSize ( awt::Container* ) {
	}

Dimension
GridLayout::preferredLayoutSize ( awt::Container* ) {
	}

void
GridLayout::layoutContainer ( awt::Container* parent ) {
	////////////////////////////////////////
	// Get size of parent, and reduce by
	// Insets on all sides.
	////////////////////////////////////////

	Dimension* size = parent->getSize();
	Border* border = parent->getBorder();
	Insets* insets = new Insets(0,0,0,0);

	if ( border )
		insets = parent->getBorder()->getBorderInsets(parent);

	size->setSize(size->width - (insets->left + insets->right),
				  size->height - (insets->top + insets->bottom));

	////////////////////////////////////////
	// Calculate how large each component
	// should be, with the adjusted size
	// of the parent, minus the sizes of
	// the gaps between the components.
	////////////////////////////////////////

	unsigned int each_width = ((size->width - ((cols-1)*that.hgap)) / cols);
	unsigned int each_height = ((size->height - ((rows-1)*that.vgap)) / rows);

	unsigned int count = parent->getComponentCount();
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int k = 0;

	if ( count ) {
		for ( int i = 0; i < that.rows; ++i ) {
			y = insets->top + (i * (each_height + vgap));

			for ( int j = 0; j < that.cols; ++j ) {
				x = insets->left + (j * (hgap + each_width));

 				Component* c = parent->getComponent(k);

				////////////////////////////////////////
				// Laying out child components.
				////////////////////////////////////////

				c->setSize(each_width, each_height);
				c->setLocation(x,y);

				++k;
				if ( k == count ) {
					break;
					} }

			if ( k == count ) {
				break;
				} } }

	// cout << pop;
	}


GridLayout*
GridLayout::clone() {
	return new GridLayout(that);
	}
