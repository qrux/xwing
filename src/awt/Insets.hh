//
// Insets.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_Insets


class Insets : public Object
{
    public: unsigned int top;
    public: unsigned int left;
    public: unsigned int bottom;
    public: unsigned int right;


    public: Insets ( unsigned int, unsigned int,
		     unsigned int, unsigned int );

    public: virtual Insets* clone();
	// public: virtual bool equals ( Object & );
};


#  define DEF_Insets
#endif
