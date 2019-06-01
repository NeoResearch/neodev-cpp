#ifndef NEODEV_DEVPACK_HPP
#define NEODEV_DEVPACK_HPP

#ifdef NEODEV_CPP_TEST

#include "devpacktest.h"

// ===========================================
// for testing

#include <string> // STD C++

#define NO_STORAGE false
#define HAS_STORAGE true
#define NO_DYNAMICINVOKE false
#define HAS_DYNAMICINVOKE true

namespace neodevtest {

class TestContractFeatures
{
public:
   const bool storage;
   const bool dynamicInvoke;
   const std::string name;

   // TODO: improve this function with something better from runtime (hash of name?)
   std::string getScriptHash() const
   {
      return ASCIIToHexString(name);
   }

   TestContractFeatures(bool _storage, bool _dynamicInvoke, std::string _name)
     : storage(_storage)
     , dynamicInvoke(_dynamicInvoke)
     , name(_name)
   {
   }
};

} // namespace neodevtest
#else
// global deploy structures
struct _feature_has_storage
{};
struct _feature_no_storage
{};
struct _feature_has_dyninvoke
{};
struct _feature_no_dyninvoke
{};

#define NO_STORAGE _feature_no_storage
#define HAS_STORAGE _feature_has_storage
#define NO_DYNAMICINVOKE _feature_no_dyninvoke
#define HAS_DYNAMICINVOKE _feature_has_dyninvoke

template<typename storage, typename dynamicInvoke>
struct _ContractFeatures
{
   static void deploy();
};
#endif

// ===========================================

// devpack main

struct emit_abi
{};
struct emit_entrypoint
{};
// marks function to export ABI
#define EXPORT_ABI template<typename _emit = emit_abi>
// marks function as contract entrypoint
#define ENTRYPOINT template<typename _emit = emit_entrypoint>

#ifdef NEODEV_CPP_TEST
// global function that returns contract capabilities
#define DECLARE_MAIN(f, storage, dyninvoke, name)                                                 \
   namespace neodevtest {                                                                         \
   TestContractFeatures getContract() { return TestContractFeatures(storage, dyninvoke, name); }; \
   }
#else
// ensures compiler won't optimize-out the main method ;)
#define DECLARE_MAIN(f, storage, dyninvoke, name)                    \
   _ContractFeatures<storage, dyninvoke> _declare_contract_features; \
   int main()                                                        \
   {                                                                 \
      _declare_contract_features.deploy();                           \
      f;                                                             \
      return 0;                                                      \
   };
#endif

// create a world state for C++ native tests
#ifdef NEODEV_CPP_TEST
#include "devtest/WorldState.hpp"
#endif

// basic stuff for C++ development

#include "smartcontract/framework/SmartContract.hpp"
#include "types.hpp"

// TODO: create a neo.hpp or neoservices.hpp
#include <neodev/smartcontract/framework/services/neo/Storage.hpp>

// globally using vmtype and abitype every time this is used (good for users!)
using namespace neodev::vmtype;
using namespace neodev::abitype;

// useful stuff
using namespace neodev::smartcontract::framework;
using namespace neodev::smartcontract::framework::services::neo;

#endif
