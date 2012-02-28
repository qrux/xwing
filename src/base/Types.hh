//
// Types.hh
//
// Native Swing C++ Library -- Xwing

//


#ifndef _TYPES_HH


#include <base/Object.hh>
#include <base/String.hh>


template <class T>
class ___Type : public Object
{
    public:
	___Type ( T t ) : value(t)
	{
	}

	virtual bool equals ( Object *obj )
	{
		EQ_PRE(___Type<T>);
		return (this->value == rhs->value);
	}


	virtual Object *clone()
	{
		return new ___Type<T>(this->value);
	}


	virtual String *toString()
	{
		return new String(this->value);
	}

	virtual bool isLessThan ( Object *obj )
	{
		EQ_PRE(___Type<T>);
		return (this->value < rhs->value);
	}
	virtual bool isGreaterThan ( Object *obj )
	{
		EQ_PRE(___Type<T>);
		return (this->value > rhs->value);
	}
	virtual bool isLessThanOrEqualTo ( Object *obj )
	{
		EQ_PRE(___Type<T>);
		return (this->value <= rhs->value);
	}
	virtual bool isGreaterThanOrEqualTo ( Object *obj )
	{
		EQ_PRE(___Type<T>);
		return (this->value >= rhs->value);
	}

	T getValue()
	{
		return this->value;
	}

	void setValue ( T t )
	{
		this->value = t;
	}

    private:
	T value;
};


typedef ___Type<char> Char;
typedef ___Type<short> Short;
typedef ___Type<unsigned short> UShort;
typedef ___Type<int> Int;
typedef ___Type<unsigned int> UInt;
typedef ___Type<float> Float;
typedef ___Type<double> Double;
typedef ___Type<bool> Boolean;



#  define _TYPES_HH
#endif
