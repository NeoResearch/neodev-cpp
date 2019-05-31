#ifndef NEODEV_VMTYPE_ARRAY_HPP
#define NEODEV_VMTYPE_ARRAY_HPP

#include "StackItem.hpp"

namespace neodev {

namespace vmtype {

struct Array : Object
{
   const int type = 0x10;

#ifdef NEODEV_CPP_TEST
   const Object* array_base; // immutable class
   Array(const Object op[])
     : array_base(op)
   {
   }

   Array() // why use this?
     : array_base(nullptr)
   {
   }
#endif

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
