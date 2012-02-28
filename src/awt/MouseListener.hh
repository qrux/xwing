//
// MouseListener.hh
//

// All rights reserved.
//


#ifndef DEF_MouseListener


class MouseListener : public EventListener {

	public: MouseListener();
	public: virtual void mouseEntered ( MouseEvent* ) = 0;
	public: virtual void mouseExited ( MouseEvent* ) = 0;
	public: virtual void mousePressed ( MouseEvent* ) = 0;
	public: virtual void mouseReleased ( MouseEvent* ) = 0;
	public: virtual void mouseClicked ( MouseEvent* ) = 0;
};


#  define DEF_MouseListener
#endif
