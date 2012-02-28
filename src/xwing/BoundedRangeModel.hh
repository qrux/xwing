//
// BoundedRangeModel.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_BoundedRangeModel


#include "defs.hh"
#include "ChangeEvent.hh"
#include "ChangeListener.hh"


class BoundedRangeModel
{
	protected: int minimum;
	protected: int value;
	protected: int extent;
	protected: int maximum;
	protected: bool isAdjusting;

	protected: PtrList<ChangeListener> *cls;

	////////////////////////////////////////

	protected: BoundedRangeModel();
	public: virtual int getMinimum() = 0;
	public: virtual int getValue() = 0;
	public: virtual int getExtent() = 0;
	public: virtual int getMaximum() = 0;
	public: virtual bool getValueIsAdjusting() = 0;

	public: virtual void setMinimum ( int ) = 0;
	public: virtual void setValue ( int ) = 0;
	public: virtual void setExtent ( int ) = 0;
	public: virtual void setMaximum ( int ) = 0;
	public: virtual void setValueIsAdjusting ( bool ) = 0;
	public: virtual void setRangeProperties ( int, int, int, int, bool ) = 0;

	public: virtual void addChangeListener ( ChangeListener* ) = 0;
	protected: virtual void fireStateChanged() = 0;

	public: virtual BoundedRangeModel* clone() = 0;
};


#  define DEF_BoundedRangeModel
#endif
