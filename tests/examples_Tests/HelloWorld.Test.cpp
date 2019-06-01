//#include<gtest/gtest.h>
#include <gtest/gtest.h>

// core includes
#include <examples/HelloWorld.cpp>

using namespace std;
//using namespace neodev;
using namespace neodevtest;

// takes this when flag -DNEODEV_CPP_TEST is active
#ifdef NEODEV_CPP_TEST
neodevtest::TestContractFeatures myContract = neodevtest::getContract();
#endif

TEST(ExampleHelloWorldTests, Test_Name)
{
   EXPECT_EQ(myContract.name, "HelloWorld");
}

TEST(ExampleHelloWorldTests, Test_ScriptHash)
{
   // TODO: make better "scripthash"
   EXPECT_EQ(myContract.getScriptHash(), ASCIIToHexString("HelloWorld"));
}


TEST(ExampleHelloWorldTests, Test_Storage_Is_True)
{
   EXPECT_EQ(myContract.storage, true);
}

TEST(ExampleHelloWorldTests, Test_Dynamic_Invoke_Is_False)
{
   EXPECT_EQ(myContract.dynamicInvoke, false);
}

TEST(ExampleHelloWorldTests, Test_Invoke_Storage_Is_Correct)
{
   neodevtest::worldState.initialize(); // cleaning world
   EXPECT_EQ(neodevtest::worldState.gasCount, 0); // no gas consumed (yet)
   EXPECT_EQ(neodevtest::worldState.systemStorage[myContract.getScriptHash()][ASCIIToHexString("Hello")], ""); // empty storage on key "Hello"
   String s;
   Array a;
   NeoContract::main(s, a);
   EXPECT_EQ(neodevtest::worldState.gasCount, 1); // consumed some gas (TODO: fix this value)
   EXPECT_EQ(neodevtest::worldState.systemStorage[myContract.getScriptHash()][ASCIIToHexString("Hello")], ASCIIToHexString("World"));
}