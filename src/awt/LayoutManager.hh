//
// LayoutManager.hh
//

// All rights reserved.
//


#ifndef DEF_LayoutManager

namespace awt {
class Container;
}


class LayoutManager : public Object {

	public: LayoutManager();
	public: virtual void addLayoutComponent ( String*, Component* ) = 0;
	public: virtual void addLayoutComponent ( String&, Component* ) = 0;
	public: virtual void removeLayoutComponent ( Component* ) = 0;
	public: virtual Dimension minimumLayoutSize ( awt::Container* ) = 0;
	public: virtual Dimension preferredLayoutSize ( awt::Container* ) = 0;
	public: virtual void layoutContainer ( awt::Container* ) = 0;
};


#  define DEF_LayoutManager
#endif
