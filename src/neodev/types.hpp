#ifndef NEODEV_TYPES_HPP
#define NEODEV_TYPES_HPP

// basic types for NeoVM
#include "vmtype/Array.hpp"
#include "vmtype/BigInt.hpp"
#include "vmtype/Boolean.hpp"
#include "vmtype/ByteArray.hpp"
#include "vmtype/Interop.hpp"
#include "vmtype/Map.hpp"
#include "vmtype/StackItem.hpp"
#include "vmtype/Struct.hpp"

// types for Neo ABI (NEP-3)
#include "abitype/String.hpp"
#include "abitype/UInt160.hpp"
#include "abitype/UInt256.hpp"

// extra helper types

namespace neodev {

// just a bunch of "unofficial" helpers...

abitype::String
ConvertToString(const char* t);

bool
Equals(const abitype::String b, const char*);

vmtype::ByteArray
ConvertToByteArray(const byte* t);

constexpr long operator"" _fixed8(long double v)
{
   return v * 100000000L;
}

} // namespace neodev

#endif
