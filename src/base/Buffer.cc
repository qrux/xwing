#include <string.h>
#include <base/Buffer.hh>



/* ----------------------------------------------------------------------
 *
 * Buffer methods
 *
 */

Buffer::Buffer() :
    buffer(NULL),
    length(0),
    total(Buffer::DEFAULT_INIT_SIZE)
{
	this->buffer = NEW char[this->total];
}


Buffer::Buffer ( int n ) :
    buffer(NULL),
    length(0),
    total(n)
{
	this->buffer = NEW char[this->total];
}


bool Buffer::equals ( Object *obj )
{
	EQ_PRE(Buffer);

	if ( this->length != rhs->length )
		return FALSE;

	return (memcmp(this->buffer, rhs->buffer, this->length) == 0) ? TRUE : FALSE;
}


String *Buffer::toString()
{
	char *temp;

	temp = NEW char[this->length + 3];
	temp[0] = '[';
	temp[this->length+1] = ']';
	temp[this->length+2] = 0;
	memcpy(temp + 1, this->buffer, this->length);

	return new String(temp);
}


void Buffer::collect()
{
	this->buffer = 0;
}


void Buffer::append ( const char *p, int n )
{
	if ( p == NULL || n == 0 )
		return;

	while ( (this->total - this->length) < n )
		grow();

	memcpy(this->buffer + this->length, p, n);

	this->length += n;
}


void Buffer::append ( Buffer *pb )
{
	this->append(pb->buffer, pb->length);
}


char *Buffer::c_str()
{
	char *p = NEW char[this->length];
	memcpy(p, this->buffer, this->length);

	return p;
}


int Buffer::size()
{
	return this->length;
}


void Buffer::grow()
{
	char *p = NEW char[this->total + (this->total >> 1)];

	memcpy(p, this->buffer, this->length);

	this->buffer = p;
	this->total += (this->total >> 1);
}


/* ----------------------------------------------------------------------
 *
 * StringBuffer methods
 *
 */

StringBuffer::StringBuffer() :
    linePos(0)
{
}


String *StringBuffer::toString()
{
	return new String(this->buffer);
}


void StringBuffer::append ( const char *s )
{
	if ( s == NULL )
		return;
      
	Buffer::append(s, strlen(s));
	this->buffer[this->length] = 0;
}


void StringBuffer::append ( const char *ps, int n )
{
	if( ps == NULL )
		return;

	Buffer::append(ps, n);
}


void StringBuffer::append ( String *ps )
{
	if ( ps == NULL )
		return;

	Buffer::append(ps->c_str(), ps->length());
}


void StringBuffer::append ( StringBuffer *ps )
{
	if ( ps == NULL )
		return;

	Buffer::append(ps->buffer, ps->length);
}


void StringBuffer::appendln ( const char *ps )
{
	this->appendln(ps, strlen(ps));
}


void StringBuffer::appendln ( const char *ps, int n )
{
	if ( ps == NULL )
		return;

	char *tmp = NEW char[n + 2];
	tmp[n + 1] = 0;
	tmp[n] = '\n';

	memcpy(tmp, ps, n);

	Buffer::append(tmp, n+2);
}


void StringBuffer::appendln ( String *ps )
{
	if ( ps == NULL )
		return;

	this->appendln(ps->c_str(), ps->length());
}


void StringBuffer::appendln ( StringBuffer *ps )
{
	this->appendln(ps->buffer, ps->length);
}


int StringBuffer::getLineCount()
{
	int k = 0;
	char *p = this->buffer;

	while ( (p = RCAST<char *>(memchr(p, '\n', this->length - (p - this->buffer)))) != 0 )
	{
		++p;
		++k;
	}

	return k;
}


String *StringBuffer::getNextLine()
{
	char *start = this->buffer + this->linePos;
	char *pos = index(start, '\n');

	if ( pos == NULL )
		return NULL;

	int len = (pos - start);
	linePos += (len + 1);

	return new String(start, len);
}
