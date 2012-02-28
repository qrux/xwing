//
// XFrame.cc
//

// All rights reserved.
//


#include <xwing/defs.hh>
#include <xwing/XComponent.hh>
#include <xwing/XPanel.hh>
#include "XFrame.hh"


XFrame::XFrame() {
	}

XFrame::XFrame ( String* title ) : Frame(title->clone()) {
	}

XFrame::XFrame ( String& title ) : Frame(title.clone()) {
	}

awt::Container*
XFrame::getContentPane() {
	return &(that.content_pane);
	}

Component*
XFrame::getComponentAt ( int x, int y ) {
	return that.content_pane.getComponentAt(x,y);
	}

void
XFrame::setBorder ( Border* border ) {
	that.Component::setBorder(border);
	that.content_pane.setBorder(border);
	}

void
XFrame::setSize ( unsigned int width, unsigned int height ) {
	that.Component::setSize(width, height);
	that.content_pane.setSize(width, height);
	}

void
XFrame::setVisible ( bool val ) {
	if ( val == true )
		that.addNotify();
	else
		that.removeNotify();
	}

void
XFrame::paint ( Graphics* g ) {
	that.content_pane.paint(g);
	}

void
XFrame::paintAll ( Graphics* g ) {
	that.content_pane.paintAll(g);
	}

void
XFrame::paintComponents ( Graphics* g ) {
	that.content_pane.paintComponents(g);
	}

void
XFrame::update ( Graphics* g ) {
	that.content_pane.update(g);
	}


XFrame*
XFrame::clone() {
	return new XFrame(that);
	}
