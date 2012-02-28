//
// awt_defs
//

// All rights reserved.
//


#ifndef DEF_awt_defs

#include <time.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>

#ifdef index
#  undef index
#endif

#ifdef rindex
#  undef rindex
#endif

#include <base/inc.hh>

#define that (*this)


namespace glob {

extern Display* display;
extern unsigned int screen;
extern Window win;

}

#  define DEF_awt_defs
#endif
