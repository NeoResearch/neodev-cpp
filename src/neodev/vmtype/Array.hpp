#ifndef NEODEV_VMTYPE_ARRAY_HPP
#define NEODEV_VMTYPE_ARRAY_HPP

#include "StackItem.hpp"

namespace neodev {

namespace vmtype {

struct Array : Object
{
   static Array& Init();

   int size();

   Object at(int i);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace vmtype

} // namespace devpack

#endif
