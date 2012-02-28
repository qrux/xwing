//
// MouseEvent.hh
//

// All rights reserved.
//


#ifndef DEF_MouseEvent
class Component;


class MouseEvent : public InputEvent {

	public: static const int MOUSE_CLICKED = 0;
	public: static const int MOUSE_DRAGGED = 1;
	public: static const int MOUSE_ENTERED = 3;
	public: static const int MOUSE_EXITED = 4;
	public: static const int MOUSE_FIRST = 5;
	public: static const int MOUSE_LAST = 6;
	public: static const int MOUSE_MOVED = 7;
	public: static const int MOUSE_PRESSED = 8;
	public: static const int MOUSE_RELEASED = 9;

	private: int x;
	private: int y;

	public: MouseEvent ( Component*,
						 int, long, int, int, int, int,
						 bool = false );
	public: virtual int getX();
	public: virtual int getY();

	public: virtual MouseEvent* clone();
	};


#  define DEF_MouseEvent
#endif
