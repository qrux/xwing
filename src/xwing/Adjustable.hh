//
// Adjustable.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_Adjustable


class Adjustable {

	public: Adjustable();
	// public: virtual void addAdjustmentListener ( AdjustmentListener* ) = 0;
	public: virtual int getBlockIncrement() = 0;
	public: virtual int getMaximum() = 0;
	public: virtual int getMinimum() = 0;
	public: virtual int getOrientation() = 0;
	public: virtual int getUnitIncrement() = 0;
	public: virtual int getValue() = 0;
	public: virtual int getVisibleAmount() = 0;
	// public: virtual void removeAdjustmentListener ( AdjustmentListener* );
	public: virtual void setBlockIncrement ( int ) = 0;
	public: virtual void setMaximum ( int ) = 0;
	public: virtual void setMinimum ( int ) = 0;
	public: virtual void setOrientation ( int ) = 0;
	public: virtual void setUnitIncrement ( int ) = 0;
	public: virtual void setValue ( int ) = 0;
	public: virtual void setVisibleAmount ( int ) = 0;

	};


#  define DEF_Adjustable
#endif
