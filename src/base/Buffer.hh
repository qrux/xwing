#ifndef _BUFFERS_HH


#include <strings.h>
#include <base/String.hh>


class Buffer : public Object
{
    public:
	Buffer();
	Buffer ( int );
	virtual bool equals ( Object * );
	virtual String *toString();
	virtual void collect();

	virtual void append ( const char *, int );
	virtual void append ( Buffer * );
	virtual char *c_str();
	virtual int size();

    protected:
	static const int DEFAULT_INIT_SIZE = 256;

	virtual void grow();

	int total;
	char *buffer;
	int length;
};


class StringBuffer : public Buffer
{
    public:
	StringBuffer();
	virtual String *toString();

	virtual void append ( const char * );
	virtual void append ( const char *, int );
	virtual void append ( String * );
	virtual void append ( StringBuffer *);

	virtual void appendln ( const char * );
	virtual void appendln ( const char *, int );
	virtual void appendln ( String * );
	virtual void appendln ( StringBuffer * );

	virtual int getLineCount();
	virtual String *getNextLine();

    private:
	int linePos;
};


#  define _BUFFERS_HH
#endif

