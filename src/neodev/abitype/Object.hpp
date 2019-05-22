#ifndef NEODEV_ABITYPE_OBJECT_HPP
#define NEODEV_ABITYPE_OBJECT_HPP

namespace neodev {

namespace abitype {

// An Object can represent any type: vm or abi

struct Object
{
   //static int length();

   //static ByteArray concat(ByteArray ba);

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
};

// NEP-3 (amend) mentions an object type called "Any", which is the same provided here
typedef Object Any;

} // namespace abitype

} // namespace devpack

#endif
