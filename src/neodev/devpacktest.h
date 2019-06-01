#ifndef NEODEV_DEVPACK_TEST_H
#define NEODEV_DEVPACK_TEST_H

// defining names of stuff used for native testing  (and test utils)

#ifdef NEODEV_CPP_TEST

#include <iostream> // for tests
#include <map>
#include <string>
#include <sstream>
#include <iomanip> // hex

namespace neodevtest {

struct TestContractFeatures;

TestContractFeatures
getContract();

struct WorldState;

extern WorldState worldState;

// test utils (string to hex)
std::string
ASCIIToHexString(const std::string& chars)
{
   std::stringstream ss;
   for (unsigned i = 0; i < chars.size(); i++)
      ss << std::setfill('0') << std::setw(2) << std::hex << int((unsigned char)chars[i]);
   return ss.str();
}

std::string
toHex(const std::string& chars)
{
   return ASCIIToHexString(chars);
}

} // namespace neodevtest

#endif

#endif
