//
// ActionEvent.hh
//

// All rights reserved.
//


#ifndef DEF_ActionEvent


class ActionEvent : public AWTEvent {

	public: static const unsigned int ACTION_PERFORMED = 0;

	private: String command;

	public: ActionEvent ( Object*, int, String* );
	public: ActionEvent ( Object*, int, String& );
	public: ActionEvent ( Object*, String* );
	public: ActionEvent ( Object*, String& );

	public: virtual ActionEvent* clone();
	};


#  define DEF_ActionEvent
#endif
