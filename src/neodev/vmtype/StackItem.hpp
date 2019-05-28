#ifndef NEODEV_VMTYPE_STACKITEM_HPP
#define NEODEV_VMTYPE_STACKITEM_HPP

#include "../syscalls.hpp"

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
   ByteArray asByteArray();

   Boolean asBoolean();

   bool asBool();

   BigInt asBigInt();

   int asInt();

   NOEMIT()
   void nop();

   NOEMIT()
   static void use(StackItem&);
};

// renaming StackItem to a more "beautiful" name
typedef StackItem Object;

} // namespace vmtype

} // namespace devpack

#endif
