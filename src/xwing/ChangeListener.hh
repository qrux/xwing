//
// ChangeListener.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef DEF_ChangeListener


class ChangeListener : public EventListener {

	public: ChangeListener();
	public: virtual void stateChanged ( ChangeEvent* ) = 0;
	};


#  define DEF_ChangeListener
#endif
