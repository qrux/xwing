//
// EventObject.hh
//

// All rights reserved.
//


#ifndef DEF_EventObject


class EventObject : public Object {

	protected: Object* source;

	public: EventObject ( Object* );
	public: virtual Object* getSource();

	public: virtual EventObject* clone();
	};


#  define DEF_EventObject
#endif
