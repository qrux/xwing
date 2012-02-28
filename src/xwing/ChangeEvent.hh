//
// ChangeEvent.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_ChangeEvent


class ChangeEvent : public EventObject {

	public: ChangeEvent ( Object* s );

	public: virtual ChangeEvent* clone();
	};


#  define DEF_ChangeEvent
#endif
