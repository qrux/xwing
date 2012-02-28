//
// XComponent.hh
//

// All rights reserved.
//


#ifndef DEF_XComponent


class XComponent : public awt::Container {

	public: XComponent();
	public: virtual Dimension* getPreferredSize();

	public: virtual XComponent* clone() = 0;
	};


#  define DEF_XComponent
#endif
