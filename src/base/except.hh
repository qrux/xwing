#ifndef JG_JCS_EXCEPT_HH


#include <base/Object.hh>


class Exception : public Object {};
class NotClonable : public Exception {};
class IndexOutOfBoundsException : public Exception {};
class NotFoundException : public Exception {};
class WrongTypeException : public Exception {};
class NonSortableException : public Exception {};


#  define JG_JCS_EXCEPT_HH
#endif
