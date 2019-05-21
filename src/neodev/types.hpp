#ifndef NEODEV_TYPES_HPP
#define NEODEV_TYPES_HPP

// basic types for NeoVM
#include "vmtype/Array.hpp"
#include "vmtype/BigInt.hpp"
#include "vmtype/Boolean.hpp"
#include "vmtype/ByteArray.hpp"
#include "vmtype/Interop.hpp"
#include "vmtype/Map.hpp"
#include "vmtype/Struct.hpp"

// types for Neo ABI (NEP-3)
#include "abitype/String.hpp"

// extra helper types

namespace neodev {

// helper type: byte
typedef unsigned char byte;

} // namespace neodev

#endif
