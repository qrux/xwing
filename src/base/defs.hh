#ifndef XW_BASE_DEFS


#ifndef TRUE
#  define TRUE (SCAST<bool>(1))
#endif

#ifndef FALSE
#  define FALSE (SCAST<bool>(0))
#endif

#define SCAST static_cast
#define RCAST reinterpret_cast
#define CCAST const_cast
#define DCAST dynamic_cast


#define ESAC break


#  define XW_BASE_DEFS
#endif
