#include <base/Object.hh>
#include <base/String.hh>



bool Object::equals ( Object *p )
{
      return (p == this);
}


String *Object::toString()
{
      return new String(RCAST<void*>(this));
}


Object *Object::clone()
{
	throw NotClonable();
}


bool Object::isLessThan ( Object *obj )
{
	throw NonSortableException();
}
bool Object::isGreaterThan ( Object *obj )
{
	throw NonSortableException();
}
bool Object::isLessThanOrEqualTo ( Object *obj )
{
	throw NonSortableException();
}
bool Object::isGreaterThanOrEqualTo ( Object *obj )
{
	throw NonSortableException();
}


ostream &operator<< ( ostream &lhs, Object &rhs )
{
      return lhs << rhs.toString()->c_str();
}
