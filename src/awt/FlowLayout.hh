//
// FlowLayout.hh
//

// All rights reserved.
//


#ifndef DEF_FlowLayout


class FlowLayout : public LayoutManager {

	public: static const unsigned int LEFT = 0;
	public: static const unsigned int CENTER = 1;
	public: static const unsigned int RIGHT = 2;

	private: unsigned int align;
	private: unsigned int hgap, vgap;
	private: unsigned int rows, cols;

	private: Dimension* prev_size;

	public: FlowLayout();
	public: FlowLayout ( unsigned int );
	public: FlowLayout ( unsigned int, unsigned int, unsigned int );
	public: virtual void addLayoutComponent ( String*, Component* );
	public: virtual void addLayoutComponent ( String&, Component* );
	public: virtual void removeLayoutComponent ( Component* );
	public: virtual Dimension minimumLayoutSize ( awt::Container* );
	public: virtual Dimension preferredLayoutSize ( awt::Container* );
	public: virtual void layoutContainer ( awt::Container* );

	private: virtual void adjustAlignment ( unsigned int, awt::Container*,
											unsigned int,
											unsigned int, unsigned int );

	public: virtual FlowLayout* clone();
	};


#  define DEF_FlowLayout
#endif
