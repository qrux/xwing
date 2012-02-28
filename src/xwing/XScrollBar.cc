//
// XScrollBar.cc
//
// Native Swing C++ Library -- Xwing

//


#include <xwing/defs.hh>
#include <xwing/BoundedRangeModel.hh>
#include <xwing/DefaultBoundedRangeModel.hh>
#include <xwing/Adjustable.hh>
#include <xwing/XComponent.hh>
#include <xwing/XScrollBar.hh>



XScrollBar::XScrollBar() : model(new DefaultBoundedRangeModel()) {
	}

int
XScrollBar::getBlockIncrement() {
	return that.blockIncrement;
	}

int
XScrollBar::getMaximum() {
	return that.model->getMaximum();
	}

int
XScrollBar::getMinimum() {
	return that.model->getMinimum();
	}

int
XScrollBar::getOrientation() {
	return that.orientation;
	}

int
XScrollBar::getUnitIncrement() {
	return that.unitIncrement;
	}

int
XScrollBar::getValue() {
	return that.model->getValue();
	}

int
XScrollBar::getVisibleAmount() {
	return that.visibleAmount;
	}

void
XScrollBar::setBlockIncrement ( int n ) {
	that.blockIncrement = n;
	}

void
XScrollBar::setMaximum ( int n ) {
	that.model->setMaximum(n);
	}

void
XScrollBar::setMinimum ( int n ) {
	that.model->setMinimum(n);
	}

void
XScrollBar::setOrientation ( int n ) {
	that.orientation = n;
	}

void
XScrollBar::setUnitIncrement ( int n ) {
	that.unitIncrement = n;
	}

void
XScrollBar::setValue ( int n ) {
	that.model->setValue(n);
	}

void
XScrollBar::setVisibleAmount ( int n ) {
	that.visibleAmount = n;
	}

void
XScrollBar::paint ( Graphics* g ) {
	
	}


XScrollBar*
XScrollBar::clone()
{
	return new XScrollBar(that);
}
