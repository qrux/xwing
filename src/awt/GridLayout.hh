//
// GridLayout.hh
//

// All rights reserved.
//


#ifndef DEF_GridLayout


class GridLayout : public LayoutManager {

	private: unsigned int rows;
	private: unsigned int cols;

	private: unsigned int hgap;
	private: unsigned int vgap;

	public: GridLayout ( unsigned int = 1, unsigned int = 1 );
	public: GridLayout ( unsigned int, unsigned int,
						 unsigned int, unsigned int );
	public: virtual void addLayoutComponent ( String*, Component* );
	public: virtual void addLayoutComponent ( String&, Component* );
	public: virtual void removeLayoutComponent ( Component* );
	public: virtual Dimension minimumLayoutSize ( awt::Container* );
	public: virtual Dimension preferredLayoutSize ( awt::Container* );
	public: virtual void layoutContainer ( awt::Container* );

	public: virtual GridLayout* clone();
	};


#  define DEF_GridLayout
#endif
