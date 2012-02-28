//
// DefaultBoundedRangeModel.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_DefaultBoundedRangeModel


class DefaultBoundedRangeModel : public Object, public BoundedRangeModel {

	public: DefaultBoundedRangeModel();

	public: virtual int getMinimum();
	public: virtual int getValue();
	public: virtual int getExtent();
	public: virtual int getMaximum();
	public: virtual bool getValueIsAdjusting();

	public: virtual void setMinimum ( int );
	public: virtual void setValue ( int );
	public: virtual void setExtent ( int );
	public: virtual void setMaximum ( int );
	public: virtual void setValueIsAdjusting ( bool );
	public: virtual void setRangeProperties ( int, int, int, int, bool );

	public: virtual void addChangeListener ( ChangeListener* );
	protected: virtual void fireStateChanged();

	public: virtual DefaultBoundedRangeModel* clone();
	};


#  define DEF_DefaultBoundedRangeModel
#endif
