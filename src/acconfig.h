/* Define if libgc is present. */
#undef HAVE_LIBGC

@BOTTOM@

#ifdef HAVE_LIBGC
#  define GC_NAME_CONFLICT
#  define MALLOC	GC_malloc
#  define NEW		new (UseGC)
#else
#  define MALLOC	malloc
#  define NEW		new
#endif
