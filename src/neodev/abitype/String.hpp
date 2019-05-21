#ifndef NEODEV_ABITYPE_STRUCT_HPP
#define NEODEV_ABITYPE_STRUCT_HPP

namespace neodev {

namespace abitype {

// On NeoVM level, String can be seen as a ByteArray
// Anyway, useful programming functions String-related are provided here for developers

struct String
{
   static int length();

   //static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

} // namespace abitype

} // namespace devpack

#endif
