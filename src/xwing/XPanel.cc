//
// XPanel.cc
//

// All rights reserved.
//


#include <xwing/defs.hh>
#include <xwing/XComponent.hh>
#include "XPanel.hh"



XPanel::XPanel()
{
}


XPanel*
XPanel::clone() {
	return new XPanel(that);
	}
