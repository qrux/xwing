//
// MouseAdapter.hh
//

// All rights reserved.
//


#ifndef DEF_MouseAdapter


class MouseAdapter : public MouseListener {

	public: MouseAdapter();
	public: virtual void mouseEntered ( MouseEvent* );
	public: virtual void mouseExited ( MouseEvent* );
	public: virtual void mousePressed ( MouseEvent* );
	public: virtual void mouseReleased ( MouseEvent* );
	public: virtual void mouseClicked ( MouseEvent* );

	public: virtual MouseAdapter* clone();
	};


#  define DEF_MouseAdapter
#endif
