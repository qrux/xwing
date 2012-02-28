//
// InputEvent.hh
//

// All rights reserved.
//


#ifndef DEF_InputEvent


class InputEvent : public ComponentEvent {

	public: time_t time;

	public: InputEvent ( Component*, int );
	public: virtual void consume();
	public: virtual bool isConsumed();
	public: virtual long getWhen();
	};


#  define DEF_InputEvent
#endif
