#ifndef CPP_DEVPACK_NEO_VM_HPP
#define CPP_DEVPACK_NEO_VM_HPP

namespace neo
{

namespace VM
{

   struct ByteArray
   {
   static int length();

   static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   // https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
   //byte operator[](int index);

   };



}

}


#endif
