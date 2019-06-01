#ifndef NEODEV_DEVPACK_TEST_H
#define NEODEV_DEVPACK_TEST_H

// defining names of stuff used for native testing

#ifdef NEODEV_CPP_TEST

#include <map>
#include <string>
#include <iostream> // for tests

struct TestContractFeatures;

namespace neodevtest {

TestContractFeatures
getContract();

struct WorldState;

extern WorldState worldState;
}

#endif

#endif
