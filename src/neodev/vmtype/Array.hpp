#ifndef NEODEV_VMTYPE_ARRAY_HPP
#define NEODEV_VMTYPE_ARRAY_HPP

#include "StackItem.hpp"

namespace neodev {

namespace vmtype {

struct Array : Object
{
   const int type = 0x10;

   // initializes an empty array ref (should not do anything, just a stub)
   NOEMIT()
   static Array& init();

   int size();

   Object at(int i);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace vmtype

} // namespace devpack

#endif
