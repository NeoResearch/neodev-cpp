#ifndef NEODEV_ABITYPE_OBJECT_HPP
#define NEODEV_ABITYPE_OBJECT_HPP

namespace neodev {

namespace abitype {

using namespace vmtype;
// An Object can represent any type: vm or abi



struct Object
{
   //static int length();

   static vmtype::ByteArray asByteArray();

   static vmtype::Boolean asBoolean();

   static bool asBool();

   static vmtype::BigInt asBigInt();

   static int asInt();

   //operator ByteArray();

   // todo: more   

   //failure: cannot be non-member
   //byte operator[](int index);
   //https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

   //operator int() __attribute__((weak, alias ("__ftest")));
};

//Object __ftest();

//Object::operator int();

//neodev::abitype::Object::operator ByteArray();



// NEP-3 (amend) mentions an object type called "Any", which is the same provided here
typedef Object Any;

} // namespace abitype

} // namespace devpack

#endif
