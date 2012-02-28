//
// FlowLayout.cc
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

#include "FlowLayout.hh"



FlowLayout::FlowLayout() :
		align(FlowLayout::CENTER),
		hgap(5), vgap(5),
		rows(0), cols(0),
		prev_size(new Dimension()) {
	}

FlowLayout::FlowLayout ( unsigned int a ) :
		align(a),
		hgap(5), vgap(5),
		rows(0), cols(0),
		prev_size(new Dimension()) {

	if ( that.align > 2 )
		that.align = FlowLayout::CENTER;
	}

FlowLayout::FlowLayout ( unsigned int a, unsigned int h, unsigned int v ) :
		align(a),
		hgap(h), vgap(v),
		rows(0), cols(0),
		prev_size(new Dimension()) {

	if ( that.align > 2 )
		that.align = FlowLayout::CENTER;
	}

void
FlowLayout::addLayoutComponent ( String*, Component* ) {
	}

void
FlowLayout::addLayoutComponent ( String&, Component* ) {
	}

void
FlowLayout::removeLayoutComponent ( Component* ) {
	}

Dimension
FlowLayout::minimumLayoutSize ( awt::Container* ) {
	}

Dimension
FlowLayout::preferredLayoutSize ( awt::Container* ) {
	}

void
FlowLayout::layoutContainer ( awt::Container* parent ) {
	unsigned int count = parent->getComponentCount();

	if ( count ) {
		Dimension* size = parent->getSize();
		Border* border = parent->getBorder();
		Insets* insets = new Insets(0,0,0,0);

		if ( border )
			insets = parent->getBorder()->getBorderInsets(parent);

		size->setSize(size->width - (insets->left + insets->right),
					  size->height - (insets->top + insets->bottom));

		unsigned int max_row_height = 0;
		unsigned int accum_width = 0;
		unsigned int accum_height = insets->top;

		Dimension* each_size;
		Component* c;

		unsigned int prev_index = 0;

		if ( size->width != that.prev_size->width ) {
			unsigned int i = 0;

			for ( ; i < count; ++i ) {
				c = parent->getComponent(i);
				each_size = c->getPreferredSize();

				if ( (each_size->width + accum_width) > size->width) {

					////////////////////////////////////////
					// Adjust for alignment.
					////////////////////////////////////////

					that.adjustAlignment(size->width - accum_width, parent,
										 insets->left,
										 prev_index, i);
					prev_index = i;

					////////////////////////////////////////
					// Reset values.
					////////////////////////////////////////

					accum_height += max_row_height;
					accum_width = 0;

					max_row_height = 0;
					}

				////////////////////////////////////////
				// Laying out child components.
				////////////////////////////////////////

				c->setLocation(accum_width, accum_height);
				c->setSize(each_size);

				accum_width += each_size->width;
				if ( each_size->height > max_row_height ) {
					max_row_height = each_size->height;
					} }

			////////////////////////////////////////
			// Adjust for alignment for last row
			// of components, because the inner
			// loop only detects change, which
			// is (nrows - 1) rows.
			////////////////////////////////////////

			that.adjustAlignment(size->width - accum_width, parent,
								 insets->left,
								 prev_index, i);
			}

		that.prev_size = size;
		}
	}

void
FlowLayout::adjustAlignment ( unsigned int remainder, awt::Container* parent,
							  unsigned int left_offset,
							  unsigned int begin, unsigned int end ) {

	if ( that.align != that.LEFT ) {
		unsigned int tx;

		switch ( that.align ) {
			case that.RIGHT:
				tx = remainder;
				break;

			case that.CENTER:
				tx = remainder >> 1;
				break;
			}

		Component *c;

		for ( int index = begin; index < end; ++index ) {
			c = parent->getComponent(index);
			c->setLocation(c->getX() + tx + left_offset, c->getY());
			} }
	}


FlowLayout*
FlowLayout::clone() {
	return new FlowLayout(that);
	}
