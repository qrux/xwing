#include <stdlib.h>
#include <string.h>
#include <base/Container.hh>



/* ----------------------------------------------------------------------
 *
 * Iterator: step-thru list.
 *
 */
Iterator::Iterator ( Object **p, int n ) :
    array(p),
    count(n),
    i(0)
{
}


bool Iterator::hasMore()
{
	return ( i < count );
}


Object *Iterator::next()
{
	return array[i++];
}


void Iterator::reset()
{
	i = 0;
}


/* ----------------------------------------------------------------------
 *
 * Sorting comparators (functions for std C-lib qsort())
 *
 */
int ascComp ( const void *a, const void *b )
{
	Object *oA = *(RCAST<Object **>(CCAST<void *>(a)));
	Object *oB = *(RCAST<Object **>(CCAST<void *>(b)));

	if ( oA->isLessThan(oB) )
		return -1;
	else if ( oA->isGreaterThan(oB) )
		return 1;

	return 0;
}


int descComp ( const void *a, const void *b )
{
	Object *oA = *(RCAST<Object **>(CCAST<void *>(a)));
	Object *oB = *(RCAST<Object **>(CCAST<void *>(b)));

	if ( oA->isLessThan(oB) )
		return 1;
	else if ( oA->isGreaterThan(oB) )
		return -1;

	return 0;
}


/* ----------------------------------------------------------------------
 *
 * Container: generic container using GC placement NEW.
 *
 */
Container::Container()
{
	this->count = 0;
	this->total = Container::DEFAULT_TOTAL;

#ifdef DEBUG_JG_CONTAINER
	cerr << "Container::ctor(): allocating memory." << endl;
#endif

	for ( int i = 0; i < 10000; ++i )
		new String("Hello, world!");

#ifdef DEBUG_JG_CONTAINER
		cerr << "                   DEFAULT_TOTAL: " << Container::DEFAULT_TOTAL << endl;
		cerr << "                   this->array: " << this->array << endl;
#endif

		// this->array = new(UseGC) (Object*)[Container::DEFAULT_TOTAL];

		this->array = NEW (Object*)[Container::DEFAULT_TOTAL];

#ifdef DEBUG_JG_CONTAINER
		cerr << "Container::ctor(): Never here!" << endl;
#endif
}


Container::Container ( int n )
{
	this->count = 0;
	this->total = n;
	this->array = NEW (Object*)[this->total];
}


bool Container::equals ( Object *obj )
{
	EQ_PRE(Container);

	int current = this->count;

	if ( current != rhs->count )
		return FALSE;

	for ( int i = 0; i < current; ++i )
		if ( this->array[i] != rhs->array[i] )
			return FALSE;

	return TRUE;
}


String *Container::toString()
{
	StringBuffer *buffer = new StringBuffer();

	buffer->append("[");

	int current = this->count;

	if ( current > 0 )
	{
		buffer->append(this->array[0]->toString());
	}
	for ( int i = 1; i < current; ++i )
	{
		buffer->append(", ");
		buffer->append(this->array[i]->toString());
	}

	buffer->append("]");

	return buffer->toString();
}


void Container::clear()
{
	this->count = 0;
}


Iterator *Container::getIterator()
{
	Object **p = NEW (Object*)[this->count];

	for ( int i = 0; i < this->count; ++i )
		p[i] = this->array[i];

	return new Iterator(p, this->count);
}


int Container::size()
{
	return this->count;
}


void Container::sort ( bool direction )
{
	if ( direction == List::ASCENDING )
		::qsort(this->array, this->count, sizeof(Object *), ::ascComp);
	else
		::qsort(this->array, this->count, sizeof(Object *), ::descComp);
}


void Container::swap ( int a, int b )
{
	Object *temp = this->array[a];
	this->array[a] = this->array[b];
	this->array[b] = temp;
}


/*
 * -------------------- PROTECTED --------------------
 */

void Container::add ( Object *p )
{
	while ( this->count >= this->total )
		this->grow();

	this->array[(this->count)++] = p;
}


int Container::currentIndex()
{
	return this->count - 1;
}


Object *Container::elementAt ( int i )
{
	if ( i > this->count )
		return NULL_OBJ;
	if ( i < 0 )
		throw new IndexOutOfBoundsException();

	return this->array[i];
}


void Container::grow()
{
#ifdef DEBUG_JG_CONTAINER
	cerr << "Container::grow(): ing...." << endl;
#endif

	unsigned int n = this->total << 1;
	Object **temp = NEW (Object*)[n];

	memcpy(temp, this->array, this->total * sizeof(Object *));

	this->array = temp;
	this->total = n;

#ifdef DEBUG_JG_CONTAINER
	cerr << "                   this->size: " << this->total << endl;
#endif
}


Object *Container::removeAt ( int i )
{
	Object *p;

	if ( i > this->count )
		throw new IndexOutOfBoundsException();

	p = this->array[i];

	Object **pos = this->array + i;

	if ( this->count != i )
		memmove(pos, pos + 1, (this->count - i) * sizeof(Object *));

	--count;

	return p;
}


Object *Container::removeAtEnd()
{
	/*
	 * Remember to use 1 (one) less than the count!
	 */

	return this->removeAt(this->count - 1);
}


void Container::set ( int n, Object *p )
{
	if ( n > this->count )
		throw new IndexOutOfBoundsException();

	this->array[n] = p;
}


/* ----------------------------------------------------------------------
 *
 * Set : a container with set semantics.
 *
 */

Set::Set()
{
}


void Set::add ( Object *p )
{
	int count = this->currentIndex();

	for ( int i = 0; i < count; ++i )
		if ( this->elementAt(i)->equals(p) )
			return;

	Container::add(p);
}


Object *Set::get ( int i )
{
	return this->elementAt(i);
}


Object *Set::remove ( Object *p )
{
	int i = 0;
	int count = this->size();

	for ( ; i < count; ++i )
		if ( this->get(i)->equals(p) )
			return this->removeAt(i);

	throw new NotFoundException();
}


/* ----------------------------------------------------------------------
 *
 * Stack: container with stack semantics.
 *
 */

Stack::Stack()
{
}


void Stack::push ( Object *p )
{
	Container::add(p);
}


Object *Stack::pop()
{
	return Container::removeAtEnd();
}


/* ----------------------------------------------------------------------
 *
 * List: container with list/vector semantics
 *
 */
List::List()
{
}


List::List ( int n ) :
    Container(n)
{
}


void List::add ( Object *p )
{
	Container::add(p);
}


Object *List::get ( int i )
{
	return Container::elementAt(i);
}


int List::find ( Object *obj )
{
	int count = this->size();

	for ( int i = 0; i < count; ++i )
		if ( this->elementAt(i)->equals(obj) )
			return i;

	return -1;
}


Object *List::remove ( int i )
{
	return Container::removeAt(i);
}


/*
 * Dangerous!  This method removes all the elements in the list
 * which match the reference value in <p>.  Use a Set
 * if you want set semantics!
 */

Object *List::remove ( Object *p )
{
	int i = 0;
	int count = this->size();
	Object *ret = NULL;

	for ( ; i < count; ++i )
		if ( this->get(i)->equals(p) )
			ret = Container::removeAt(i);

	if ( ret == NULL )
		throw new NotFoundException();
	
	return ret;
}


/* ----------------------------------------------------------------------
 *
 * Map: container with map semantics
 *
 */
Map::Map() :
    values(new Set())
{
}


String *Map::toString()
{
	StringBuffer *buffer = new StringBuffer();

	buffer->append("[");

	int current = this->size();

	if ( current > 0 )
	{
		buffer->append(Set::get(0)->toString());
		buffer->append(" = ");
		buffer->append(this->values->get(0)->toString());
	}
	for ( int i = 1; i < current; ++i )
	{
		buffer->append(", ");

		buffer->append(Set::get(i)->toString());
		buffer->append(" = ");
		buffer->append(this->values->get(i)->toString());
	}

	buffer->append("]");

	return buffer->toString();
}


Object *Map::get ( Object *p )
{
	int i = 0;
	int count = this->size();

	for ( ; i < count ; ++i )
		if ( this->elementAt(i)->equals(p) )
			return this->values->get(i);

	return NULL_OBJ;
}


void Map::put ( Object *k, Object *v )
{
	this->add(k);
	this->values->add(v);
}


Object *Map::remove ( Object *k )
{
	Object *p = this->get(k);

	this->values->remove(p);
	Set::remove(k);
}


Iterator *Map::getKeys()
{
	return this->getIterator();
}


Iterator *Map::getValues()
{
	return this->values->getIterator();
}


bool Map::containsKey ( Object *p )
{
	this->find(p, CCAST<Set*>(SCAST<Set*>(this)));
}


bool Map::containsValue ( Object *p )
{
	this->find(p, this->values);
}


bool Map::find ( Object *p, Set *s )
{
	int i = 0;
	int count = s->size();

	for ( ; i < count ; ++i )
		if ( s->get(i)->equals(p) )
			return i;

	throw new NotFoundException();
}
