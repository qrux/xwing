//
// DefaultBoundedRangeModel.cc
//
// Native Swing C++ Library -- Xwing

//


#include "defs.hh"
#include "BoundedRangeModel.hh"

#include "DefaultBoundedRangeModel.hh"



DefaultBoundedRangeModel::DefaultBoundedRangeModel()
{
}

int DefaultBoundedRangeModel::getMinimum()
{
	return that.minimum;
}

int DefaultBoundedRangeModel::getValue()
{
	return that.value;
}

int DefaultBoundedRangeModel::getExtent()
{
	return that.extent;
}

int DefaultBoundedRangeModel::getMaximum()
{
	return that.maximum;
}

bool DefaultBoundedRangeModel::getValueIsAdjusting()
{
	return that.isAdjusting;
}

////////////////////////////////////////

void DefaultBoundedRangeModel::setMinimum ( int n )
{
	that.minimum = n;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::setValue ( int n )
{
	that.value = n;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::setExtent ( int n )
{
	that.extent = n;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::setMaximum ( int n )
{
	that.maximum = n;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::setValueIsAdjusting ( bool n )
{
	that.isAdjusting = n;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::setRangeProperties ( int max,
						    int min,
						    int val,
						    int ext,
						    bool isAdj )
{
	that.maximum = max;
	that.minimum = min;
	that.value = val;
	that.extent = ext;
	that.isAdjusting = isAdj;
	that.fireStateChanged();
}

void DefaultBoundedRangeModel::addChangeListener ( ChangeListener* cl )
{
	cls->add(cl);
}

////////////////////////////////////////
//
// PROTECTED methods
//
////////////////////////////////////////

void DefaultBoundedRangeModel::fireStateChanged()
{
}


DefaultBoundedRangeModel *DefaultBoundedRangeModel::clone()
{
	return new DefaultBoundedRangeModel(that);
}
