#ifndef NEODEV_VMTYPE_STACKITEM_HPP
#define NEODEV_VMTYPE_STACKITEM_HPP

namespace neodev {

namespace vmtype {

// forward declarations
struct Array;
struct BigInt;
struct Boolean;
struct ByteArray;
struct Interop;
struct Map;
struct Struct;

struct StackItem
{
   static ByteArray asByteArray();

   static Boolean asBoolean();

   static bool asBool();

   static BigInt asBigInt();

   static int asInt();

};

// renaming StackItem to a more "beautiful" name
typedef StackItem Object;

} // namespace vmtype

} // namespace devpack

#endif
