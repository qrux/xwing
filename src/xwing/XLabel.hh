//
// XLabel.hh
//

// All rights reserved.
//


#ifndef DEF_XLabel


class XLabel : public XComponent
{
	private: String* label;

	private: Dimension* psize;
	private: static const unsigned int padding = 5;


	public: XLabel();
	public: XLabel ( String* );
	public: virtual Dimension* getPreferredSize();
	public: virtual void setText ( String& );
	public: virtual void setText ( String * );
	public: virtual void paint ( Graphics* g );

	public: virtual XLabel* clone();
};


#  define DEF_XLabel
#endif
