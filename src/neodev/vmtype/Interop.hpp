#ifndef NEODEV_VMTYPE_INTEROP_HPP
#define NEODEV_VMTYPE_INTEROP_HPP

namespace neodev {

namespace vmtype {

struct Interop : Object
{
   const int type = 0xf0;

   // convert Interop Interface to boolean
   static bool toBool();
};

} // namespace vmtype

} // namespace devpack

#endif
