//
// xwing_defs
//

// All rights reserved.
//


#ifndef DEF_xwing_defs

#include <awt/inc.hh>

/*
 * The following #define is taken from the Boehm GC code.
 * This is meant to solve the problem of MI with regard
 * to the methods found in class Collectable (gc).
 *
 * If classes A & B both derive Collectable, they will both
 * have the GC methods; if C derives A -and- B, it will
 * inherit ambiguity.  This resolves that issue.
 */
#define INLINE_GC_OPERATORS public: \
	inline void *operator new ( size_t size ) { return gc::operator new(size); } \
	inline void *operator new ( size_t size, GCPlacement gcp ) { return gc::operator new(size, gcp); } \
	inline void operator delete ( void *obj ) { gc::operator delete(obj); } \
	inline void *operator new[] ( size_t size ) { return gc::operator new[](size); } \
	inline void *operator new[] ( size_t size, GCPlacement gcp ) { return gc::operator new[](size, gcp); } \
	inline void operator delete[] ( void *obj ) { gc::operator delete[](obj); }


#  define DEF_xwing_defs
#endif
