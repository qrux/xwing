//
// XComponent.cc
//

// All rights reserved.
//


#include <xwing/defs.hh>
#include "XComponent.hh"


XComponent::XComponent() {
	}

Dimension*
XComponent::getPreferredSize() {
	return that.getSize();
	}
