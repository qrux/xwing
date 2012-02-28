#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <base/String.hh>
#include <base/Container.hh>
#include <base/Buffer.hh>



/* ----------------------------------------------------------------------
 *
 *    gc_strdup()
 *
 */

char *gc_strdup ( const char *src )
{
	if ( src == NULL )
		return NULL;

	char *buffer;
	int length = strlen(src);

	buffer = NEW char[length + 1];
	buffer[length] = 0;
	memcpy(buffer, src, length);

	return buffer;
}


/* ----------------------------------------------------------------------
 *
 *    gc_strndup()
 *
 */

char *gc_strndup ( const char *src, int n )
{
	if ( src == NULL  ||  n == 0 )
		return NULL;

	char *buffer;
	int length = strlen(src);

	if ( n < length )
		length = n;

	buffer = NEW char[length + 1];
	buffer[length] = 0;
	memcpy(buffer, src, length);

	return buffer;
}


/* ----------------------------------------------------------------------
 *
 *    gc_strcat()
 *
 */

void gc_strcat ( const char *dest, const char *src )
{
	char *buffer;
	int destLen = strlen(dest);
	int srcLen = strlen(src);

	buffer = NEW char[destLen + srcLen + 1];
	buffer[destLen + srcLen] = 0;

	memcpy(buffer, dest, destLen);
	memcpy(buffer + destLen, src, srcLen);

	dest = buffer;
}


/* ----------------------------------------------------------------------
 *
 *    String
 *
 */


String::String()
{
	this->buffer = NEW char[1];
	this->size = 0;

	this->buffer[0] = 0;
}


String::String ( char c, int n ) :
    buffer(NULL),
    size(0)
{
	if ( n >= 0 )
	{
		this->buffer = NEW char[n + 1];
		this->buffer[n] = 0;
		memset(this->buffer, c, n);
		this->size = n;
	}
}


String::String ( const char *s )
{
	if ( s != NULL )
	{
		this->buffer = strdup(s);
		this->size = strlen(this->buffer);
	}
	else
	{
		this->buffer = NEW char[1];
		this->size = 0;

		this->buffer[0] = 0;
	}
}


String::String ( const char *s, int n ) :
    size(n)
{
	this->buffer = NEW char[n + 1];
	this->buffer[n] = 0;
	memcpy(this->buffer, s, n);
}


String::String ( int i )
{
	this->buffer = NEW char[256];
	(this->buffer)[255] = 0;

	sprintf(this->buffer, "%d", i);
	this->size = strlen(this->buffer);
}


String::String ( unsigned int i )
{
	this->buffer = NEW char[256];
	(this->buffer)[255] = 0;

	sprintf(this->buffer, "%u", i);
	this->size = strlen(this->buffer);
}


String::String ( double d )
{
	this->buffer = NEW char[256];
	(this->buffer)[255] = 0;

	sprintf(this->buffer, "%f", d);
	this->size = strlen(this->buffer);
}


String::String ( String *s )
{
	if ( s != NULL )
	{
		this->buffer = strdup(s->buffer);
		this->size = strlen(this->buffer);
	}
	else
	{
		this->buffer = NEW char[1];
		this->size = 0;

		this->buffer[0] = 0;
	}
}


String::String ( void *p )
{
	this->buffer = NEW char[256];
	(this->buffer)[255] = '0';

	sprintf(this->buffer, "%p", p);
	this->size = strlen(this->buffer);
}


String *String::clone()
{
	return new String(this->buffer);
}


bool String::equals ( const char *str )
{
	return this->equals(new String(str));
}


bool String::equals ( Object *obj )
{
	EQ_PRE(String);

#ifdef DEBUG_JG_XML_STRINGS
	cerr << "  String::equals(): lhs: [" << this->buffer << "]" << endl;
	cerr << "                        rhs: [" << rhs->buffer << "]" << endl;
	cerr << "  String::equals(): lhs: [" << this->size << "]" << endl;
	cerr << "                        rhs: [" << rhs->size << "]" << endl;
#endif

	return (this->size == rhs->size)
		&&
		!memcmp(this->buffer, rhs->buffer, this->size);
}


String *String::toString()
{
	return this;
}


void String::collect()
{
	this->size = 0;
	this->buffer = 0;
}


char *String::c_str()
{
	return strdup(this->buffer);
}


int String::length()
{
	return this->size;
}


char String::charAt ( int n )
{
	if ( n < 0  ||  n > this->size-1 )
		throw new IndexOutOfBoundsException();

	return this->buffer[n];
}


int String::index ( char c, int n )
{
	if ( n < 0  ||  n > (this->size - 1) )
		throw new IndexOutOfBoundsException();

	for ( int i = n; i < this->size; ++i )
		if ( this->buffer[i] == c )
			return i;

	throw new NotFoundException();
}


int String::index ( char c )
{
	this->index(c, 0);
}


String *String::replace ( const char *orig, const char *repl )
{
	char *from = this->buffer;
	char *pos = NULL;
	int length = strlen(orig);

	StringBuffer *b = new StringBuffer();

	while ( (pos = strstr(from, orig)) != NULL )
	{
		/*
		 * Put the part before <orig> into the buffer.
		 */

		 b->append(from, pos-from);

		 /*
		  * Put <repl> into it's place.
		  */

		 b->append(repl);

		 /*
		  * Advance past <orig>, continue.
		  */

		 from += (pos - from) + length;
	}

	/*
	 * Get the last bit.
	 */

	b->append(from);

	return b->toString();
}


String *String::replace ( String *orig, String *repl )
{
	this->replace(orig->buffer, repl->buffer);
}


//int String::rindex ( char c, int n )
//{
	//if ( n < 0  ||  n > this->size-1 )
		//throw new IndexOutOfBoundsException();
//
	//for ( int i = this->size - (n + 1); i >= 0; --i )
		//if ( this->buffer[i] == c )
			//return i;
//
	//throw new NotFoundException();
//}
//
//
//int String::rindex ( char c )
//{
	//this->rindex(c, this->size-1);
//}


String *String::substr ( int n, int m )
{
	if ( n < 0  ||  (n+m) < 0  ||  n > size  ||  (n+m) > size )
		throw new IndexOutOfBoundsException();

	if ( m == 0 )
		return new String();

	return new String(this->buffer+n, m);
}


String *String::substr ( int n )
{
	return this->substr(n, this->size-n);
}


String *String::trim()
{
	if ( this->size == 0 )
		return new String(this);

	char *temp = strdup(this->buffer);

	int i = 0;

	while ( temp[i] == ' '
		||
		temp[i] == '\t'
		||
		temp[i] == '\n'
		||
		temp [i] == '\r' )

		++i;

	/*
	 * String is full of whitespace!!
	 */

	if ( i == this->size )
		return new String();

	int j = this->size-1;

	while ( temp[j] == ' '
		||
		temp[j] == '\t'
		||
		temp[j] == '\n'
		||
		temp[j] == '\r' )

		--j;

#ifdef DEBUG_JG_XML_STRINGS
	cerr << "  buffer: " << this->buffer << endl;
	cerr << "    i: " << i << endl;
	cerr << "    j: " << j << endl;
#endif

	if ( i == 0  &&  j == this->size-1)
		return new String(this);

	return this->substr(i, (j-i)+1);
}


List *String::tokenize ( const char *delims, List *tokens )
{
#ifdef DEBUG_JG_XML_STRINGS_tok
	cerr << "String::tokenize()." << endl;
#endif

	int count = strlen(delims);
	int lastDelimIndex = 0;

	if ( tokens == NULL )
		tokens = new List();

#ifdef DEBUG_JG_XML_STRINGS_tok
	cerr << "String::tokenize: this->buffer: " << this->buffer << endl;
	cerr << "String::tokenize: this->size  : " << this->size << endl;
#endif

	if ( this->buffer == NULL  ||  this->size == 0 )
		return tokens;

	for ( int i = 0; i < this->size; ++i )
	{
		for ( int j = 0; j < count; ++j )
		{
			if ( this->buffer[i] == delims[j] )
			{
				/*
				 * This is important!  If the last delimiter was the
				 * previous character, we don't want to create a
				 * new token, or else we'll have null tokens between
				 * delimiters!
				 */
				if ( (i - lastDelimIndex) != 0 )
				{
					tokens->add(this->substr(lastDelimIndex, i - lastDelimIndex));

#ifdef DEBUG_JG_XML_STRINGS_tok
					cerr << '.';
#endif
				}

				/*
				 * This is important!  We still need to track
				 * the location of the index of the last delimiter
				 * encountered, or else the next token will contain
				 * delimiters (if they are found contiguously!
				 */
				lastDelimIndex = i + 1;
			}
		}
	}

#ifdef DEBUG_JG_XML_STRINGS_tok
	cerr << endl;
#endif

	if ( lastDelimIndex != (this->size) )
		tokens->add(this->substr(lastDelimIndex));

	return tokens;
}


List *String::tokenize ( String *delims, List *list )
{
	return this->tokenize(delims->c_str(), list);
}


char String::charValue()
{
	return this->buffer[0];
}


int String::intValue()
{
	return atoi(this->buffer);
}


double String::doubleValue()
{
	return atof(this->buffer);
}


bool String::beginsWith ( const char *s )
{
	String *str = new String(s);

	return this->beginsWith(str);
}


bool String::beginsWith ( String *str )
{
	if ( str->size > this->size )
		return FALSE;

	return !memcmp(this->buffer, str->buffer, str->size);
}


bool String::contains ( const char *s )
{
	return strstr(this->buffer, s);
}


bool String::contains ( String *str )
{
	return this->contains(str->c_str());
}
