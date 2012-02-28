#ifndef _CONTAINERS_HH


#include <base/Object.hh>
#include <base/except.hh>
#include <base/Buffer.hh>


class Iterator : public Object
{
    public:
	Iterator ( Object **, int );
    protected:
	Iterator();

    public:
	bool hasMore();
	Object *next();
	void reset();

    private:
	Object **array;
	int count;
	int i;
};


template <class T>
class TypedIterator : public Iterator
{
    public:
	TypedIterator ( Iterator *ip ) : Iterator(*ip) { }
	virtual T *next() { return DCAST<T *>(Iterator::next()); }
};


int ascComp ( const void *, const void * );
int descComp ( const void *, const void * );


class Container : public Object
{
    public:
	static const bool ASCENDING = 0;
	static const bool DESCENDING = 1;

	Container();
	virtual bool equals ( Object * );
	virtual String* toString();

	virtual void clear();
	virtual Iterator *getIterator();
	virtual int size();
	virtual void sort ( bool = ASCENDING );
	virtual void swap ( int, int );

    protected:
	Container ( int );
	virtual void add ( Object * );
	virtual int currentIndex();
	virtual Object *elementAt ( int );
	virtual void grow();
	virtual Object *removeAt ( int );
	virtual Object *removeAtEnd();
	virtual void set ( int, Object * );

    protected:
	static const unsigned int DEFAULT_TOTAL = 256;

	int total;
	Object **array;
	int count;
};


class Set : public Container
{
    public:
	Set();
	virtual void add ( Object * );
	virtual Object *get ( int );
	virtual Object *remove ( Object * );
};


class Stack : public Container
{
    public:
	Stack();
	virtual void push ( Object * );
	virtual Object *pop();
};


int isLessThan ( void *, void * );


class List : public Container
{
    public:
	List();
	List ( int );
	virtual void add ( Object * );
	virtual int find ( Object * );
	virtual Object *get ( int );
	virtual Object *remove ( int );
	virtual Object *remove ( Object * );
};


template<class T>
class PtrList : public List
{
    public:
	virtual void add ( T *ptr )
	{
		Object *p = DCAST<Object *>(ptr);
		if ( p == NULL ) throw WrongTypeException();
		List::add(p);
	}

	virtual T *getPtr ( int i )
	{
		Object *p = List::get(i);

		return DCAST<T *>(p);
	}
};


class Map : public Set
{
    public:
	Map();
	virtual String* toString();

	virtual Object *get ( Object * );
	virtual void put ( Object *, Object * );
	virtual Object *remove ( Object * );

	virtual Iterator *getKeys();
	virtual Iterator *getValues();
	virtual bool containsKey ( Object * );
	virtual bool containsValue ( Object * );

    private:
	virtual bool find ( Object *, Set * );

	Set *values;
};


#  define JG_XML_CONTAINERS_HH
#endif
