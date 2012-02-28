//
// EmptyBorder.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_EmptyBorder


class EmptyBorder : public Border {

	protected: unsigned int top;
	protected: unsigned int left;
	protected: unsigned int bottom;
	protected: unsigned int right;

	public: EmptyBorder ( Insets* );
	public: EmptyBorder ( unsigned int, unsigned int,
						  unsigned int, unsigned int );
	public: virtual Insets* getBorderInsets ( Component* );
	public: virtual bool isBorderOpaque();
	public: virtual void paintBorder ( Component*, Graphics*, int, int,
									   unsigned int, unsigned int );

	public: virtual EmptyBorder* clone();
};


#  define DEF_EmptyBorder
#endif
