#ifndef NEODEV_DEVPACK_TEST_H
#define NEODEV_DEVPACK_TEST_H

// defining names of stuff used for native testing

#ifdef NEODEV_CPP_TEST

#include <map>
#include <string>

struct TestContractFeatures;

namespace neodev {

TestContractFeatures
_get_contract();
}

namespace neodev {
typedef std::map<std::string, std::string> InternalStorage;
extern std::map<std::string, InternalStorage> _systemStorage;
}

#endif

#endif
