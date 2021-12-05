#ifndef _OBJECT_HH


#include <iostream>
#include <gc_cpp.h>

#include <base/defs.hh>


#define NULL_OBJ	(RCAST<Object *>(0))
#define EQ_PRE(s)	s *rhs = DCAST<s *>(obj); if ( rhs == 0 ) return false


class String;

class Object : public gc
{
    public:
	virtual bool equals ( Object * );
	virtual String *toString();
	virtual Object *clone();

	virtual bool isLessThan ( Object * );
	virtual bool isGreaterThan ( Object * );
	virtual bool isLessThanOrEqualTo ( Object * );
	virtual bool isGreaterThanOrEqualTo ( Object * );

	friend ostream &operator << ( ostream &, Object & );
};


#  define _OBJECT_HH
#endif
