#ifndef _STRINGS_HH


#include <base/except.hh>

#define STRING(s) (DCAST<String *>(s))


char *gc_strdup ( char * );
char *gc_strndup ( char *, int );
void gc_strcat ( char *, char * );


/* ----------------------------------------------------------------------
 *
 * jg::String: a nice[*] string class
 *
 * [*]  For some sufficiently lax definition of "nice" [**]
 * [**] Meaning IMNSHO =P
 *
 * Hey.  Bite me.  =)
 *
 */

class List;

class String : public Object
{
    public:
	String();
	String ( char, int );
	String ( const char * );
	String ( const char *, int );
	String ( int );
	String ( unsigned int );
	String ( double );
	String ( String * );
	String ( void * );
	virtual String *clone();
	virtual bool equals ( const char *);
	virtual bool equals ( Object *);
	virtual String* toString();
	void collect();

	char *c_str();
	int length();
	char charAt ( int );

	int index ( char c, int );
	int index ( char c );
	String *replace ( const char *, const char * );
	String *replace ( String *, String * );
	//int rindex ( char c, int );
	//int rindex ( char c );
	String *substr ( int, int );
	String *substr ( int );

	String *trim();

	List *tokenize ( const char *, List * = NULL );
	List *tokenize ( String *, List * = NULL );

	char charValue();
	int intValue();
	double doubleValue();

	bool beginsWith ( const char * );
	bool beginsWith ( String * );
	bool contains ( const char * );
	bool contains ( String * );

    private:
	char *buffer;
	int size;
};


#  define _STRINGS_HH
#endif
