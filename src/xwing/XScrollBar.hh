//
// XScrollBar.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_XScrollBar


class BoundedRangeModel;


class XScrollBar : public XComponent, public Adjustable {

	private: BoundedRangeModel* model;

	private: int blockIncrement;
	private: int orientation;
	private: int unitIncrement;
	private: int visibleAmount;

	public: XScrollBar();
	// public: virtual void addAdjustmentListener ( AdjustmentListener* );
	public: virtual int getBlockIncrement();
	public: virtual int getMaximum();
	public: virtual int getMinimum();
	public: virtual int getOrientation();
	public: virtual int getUnitIncrement();
	public: virtual int getValue();
	public: virtual int getVisibleAmount();
	// public: virtual void removeAdjustmentListener ( AdjustmentListener* );
	public: virtual void setBlockIncrement ( int );
	public: virtual void setMaximum ( int );
	public: virtual void setMinimum ( int );
	public: virtual void setOrientation ( int );
	public: virtual void setUnitIncrement ( int );
	public: virtual void setValue ( int );
	public: virtual void setVisibleAmount ( int );
	public: virtual void paint ( Graphics* );

	public: virtual XScrollBar* clone();
	};


#  define DEF_XScrollBar
#endif
