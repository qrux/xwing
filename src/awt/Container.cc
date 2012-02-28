////////////////////////////////////////////////// -*- Mode: C++ -*-
//
// Container.cc
//

// All rights reserved.
//
//////////////////////////////////////////////////


#include <awt/defs.hh>

#include <awt/Color.hh>
#include <awt/Font.hh>
#include <awt/FontMetrics.hh>
#include <awt/Dimension.hh>
#include <awt/Point.hh>
#include <awt/Rectangle.hh>
#include <awt/Insets.hh>
#include <awt/Border.hh>
#include <awt/Graphics.hh>
#include <awt/Point.hh>

#include <awt/EventObject.hh>
#include <awt/AWTEvent.hh>
#include <awt/ComponentEvent.hh>
#include <awt/InputEvent.hh>
#include <awt/MouseEvent.hh>

#include <awt/EventListener.hh>
#include <awt/MouseListener.hh>

#include <awt/Component.hh>
#include <awt/LayoutManager.hh>
#include <awt/FlowLayout.hh>

#include "Container.hh"


////////////////////////////////////////

awt::Container::Container() :
    list(new PtrList<Component>()),
    lm(new FlowLayout())
{
}

Component*
awt::Container::add ( Component* c ) {
	c->parent = this;
	that.list->add(c);

	that.lm->layoutContainer(this);

	return c;
	}

Component*
awt::Container::getComponent ( unsigned int i ) {
	return that.list->getPtr(i);
	}

Component*
awt::Container::getComponentAt ( int x, int y ) {
	Component* c;
	Rectangle* bounds;
	Component* target = that.Component::getComponentAt(x,y);
	unsigned int count = list->size();

	for ( int i = 0; i < count; ++i ) {
		c = list->getPtr(i);
		bounds = c->getBounds();

		if ( bounds->contains(x,y) ) {
			target = c;

			if ( (c = c->getComponentAt(x - bounds->x, y - bounds->y)) ) {
				target = c;
				} } }

	return target;
	}

unsigned int
awt::Container::getComponentCount() {
	return that.list->size();
	}

LayoutManager*
awt::Container::getLayout() {
	return that.lm;
	}

void
awt::Container::setLayout( LayoutManager* lm ) {
	that.lm = lm;
	}

void
awt::Container::paintAll ( Graphics* g ) {
	that.lm->layoutContainer(this);

	Dimension* size = that.getSize();
	unsigned int count = that.list->size();

	for ( int i = 0; i < count; ++i ) {
		Component* c = that.getComponent(i);
		Rectangle* bounds = c->getBounds();

		g->translate(bounds->x, bounds->y);
		g->setClip(bounds->x, bounds->y, bounds->width, bounds->height);

		c->paint(g);

		g->setClip(-bounds->x, -bounds->y, size->width, size->height);
		g->translate(-bounds->x, -bounds->y);
		}
	}

void
awt::Container::paintComponents ( Graphics* g ) {
	that.paintAll(g);
	}

void
awt::Container::update ( Graphics* g ) {
	////////////////////////////////////////
	// Update myself.
	////////////////////////////////////////

	that.Component::update(g);

	////////////////////////////////////////
	// Update children.
	////////////////////////////////////////

	unsigned int count = that.list->size();

	if ( count ) {
		that.lm->layoutContainer(this);

		Dimension* size = that.getSize();

		Border* border = that.getBorder();
		Insets* insets = new Insets(0,0,0,0);
		if ( border )
			insets = border->getBorderInsets(this);

		size->width -= (insets->left + insets->right);
		size->height -= (insets->top + insets->bottom);

		for ( int i = 0; i < count; ++i ) {
			Component* c = that.getComponent(i);
			Rectangle* bounds = c->getBounds();

			g->translate(bounds->x, bounds->y);
			g->setClip(bounds->x, bounds->y,
							bounds->width, bounds->height);

			c->update(g);

			g->setClip(-bounds->x, -bounds->y,
							size->width, size->height);
			g->translate(-bounds->x, -bounds->y);
			} }
	}

void
awt::Container::validate() {
	that.Component::validate();

	unsigned int count = that.list->size();
	for ( int i = 0; i < count; ++i )
		that.list->getPtr(i)->validate();

	that.lm->layoutContainer(this);
	}

void
awt::Container::removeNotify() {
	that.Component::removeNotify();

	unsigned int count = that.list->size();
	for ( int i = 0; i < count; ++i )
		that.list->getPtr(i)->removeNotify();
	}

////////////////////////////////////////
//
// REQUIRED methods
//
////////////////////////////////////////


//////////////////////////////////////////////////
//

// Date:	20 Jul 1999
//
//////////////////////////////////////////////////
