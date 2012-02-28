//
// AWTEvent.hh
//

// All rights reserved.
//


#ifndef DEF_AWTEvent
class Component;


class AWTEvent : public EventObject
{
    public:
	AWTEvent ( Object*, int );
	virtual AWTEvent* clone();

	virtual int getId();

    protected:
	virtual void consume();
	virtual bool isConsumed();


    protected:
	int id;
	bool consumed;
};


#  define DEF_AWTEvent
#endif // DEF_AWTEvent


//////////////////////////////////////////////////
//

// Date:	16 July 1999
//
//////////////////////////////////////////////////
