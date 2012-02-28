//
// BoundedRangeModel.cc
//
// Native Swing C++ Library -- Xwing

//


#include "BoundedRangeModel.hh"


BoundedRangeModel::BoundedRangeModel() :
    cls(new PtrList<ChangeListener>())
{
}
