#ifndef NEODEV_DEVPACK_HPP
#define NEODEV_DEVPACK_HPP

// basic stuff for C++ development

#include "types.hpp"
#include "smartcontract/framework/SmartContract.hpp"

// TODO: create a neo.hpp or neoservices.hpp
#include <neodev/smartcontract/framework/services/neo/Storage.hpp>

// globally using vmtype and abitype every time this is used (good for users!)
using namespace neodev::vmtype;
using namespace neodev::abitype;

// useful stuff
using namespace neodev::smartcontract::framework;
using namespace neodev::smartcontract::framework::services::neo;

#endif
