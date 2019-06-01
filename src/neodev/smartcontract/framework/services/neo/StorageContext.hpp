#ifndef NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGECONTEXT_HPP
#define NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGECONTEXT_HPP

#include "../../../../types.hpp"

#ifdef NEODEV_CPP_TEST
#include <map>
#include <string>
#include "../../../../devpacktest.h"
#endif

namespace neodev::smartcontract::framework::services::neo {

struct StorageContext
{
#ifdef NEODEV_CPP_TEST
   // implement real storage
   neodevtest::ContractStorage& contractStorage;

   StorageContext(neodevtest::ContractStorage& _contractStorage)
     : contractStorage(_contractStorage)
   {
   }
#endif
};

} // namespace

#endif // NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGECONTEXT_HPP