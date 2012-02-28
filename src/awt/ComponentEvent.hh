//
// ComponentEvent.hh
//

// All rights reserved.
//


#ifndef DEF_ComponentEvent


class ComponentEvent : public AWTEvent {

	public: ComponentEvent ( Component*, int );
	public: Component* getComponent();

	public: virtual ComponentEvent* clone();
	};


#  define DEF_ComponentEvent
#endif
