#ifndef NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_ITERATOR_HPP
#define NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_ITERATOR_HPP

#include "../../../../syscalls.hpp"
#include "../../../../types.hpp"

namespace neodev::smartcontract::framework::services::neo {

template<class TKey, class TValue>
class Iterator
{
public:
   EMIT_SYSCALL(Neo_Iterator_Next)
   static bool next();

   EMIT_SYSCALL(Neo_Iterator_Key)
   static TKey key();

   EMIT_SYSCALL(Neo_Iterator_Value)
   static TValue value();
};
}

#endif // NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_ITERATOR_HPP