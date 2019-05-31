#ifndef NEODEV_DEVPACK_HPP
#define NEODEV_DEVPACK_HPP

// basic stuff for C++ development

#include "smartcontract/framework/SmartContract.hpp"
#include "types.hpp"

// TODO: create a neo.hpp or neoservices.hpp
#include <neodev/smartcontract/framework/services/neo/Storage.hpp>

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
struct ContractFeatures
{
   static void deploy();
};

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
// main on tests (TODO: perhaps declare Storage, DynInvoke and other features here... to pass for test engine)
#define DECLARE_MAIN(f, storage, dyninvoke) void _nodev_nothing(){}; //\
   //int main()                \
   //{                         \
   //   f;                     \
   //   return 0;              \
   //};
#else
// ensures compiler won't optimize-out the main method ;)
#define DECLARE_MAIN(f, storage, dyninvoke)                         \
   ContractFeatures<storage, dyninvoke> _declare_contract_features; \
   int main()                                                       \
   {                                                                \
      _declare_contract_features.deploy();                          \
      f;                                                            \
      return 0;                                                     \
   };

#endif

// globally using vmtype and abitype every time this is used (good for users!)
using namespace neodev::vmtype;
using namespace neodev::abitype;

// useful stuff
using namespace neodev::smartcontract::framework;
using namespace neodev::smartcontract::framework::services::neo;

#endif
