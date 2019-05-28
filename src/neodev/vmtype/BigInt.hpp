#ifndef NEODEV_VMTYPE_BIGINT_HPP
#define NEODEV_VMTYPE_BIGINT_HPP

namespace neodev {

namespace vmtype {

struct BigInt : Object
{
   const int type = 0x02;
};

} // namespace vmtype

} // namespace devpack

#endif
