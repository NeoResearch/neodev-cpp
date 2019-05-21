#ifndef NEODEV_VMTYPE_STRUCT_HPP
#define NEODEV_VMTYPE_STRUCT_HPP

namespace neodev {

namespace vmtype {

struct Struct
{
   static int length();

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace vmtype

} // namespace devpack

#endif
