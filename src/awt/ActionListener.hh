//
// ActionListener.hh
//

// All rights reserved.
//


#ifndef DEF_ActionListener


class ActionListener : public EventListener {

	public: ActionListener();
	public: virtual void actionPerformed ( ActionEvent* ) = 0;

	public: virtual ActionListener* clone() = 0;
	};


#  define DEF_ActionListener
#endif
