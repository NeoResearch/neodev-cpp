//#include<gtest/gtest.h>
#include <gtest/gtest.h>

// core includes
#include <examples/HelloWorld.cpp> 

using namespace std;
//using namespace neodev;
// import things:  ASCIIToHexString(), worldState, getContract(), TestContractFeatures
using namespace neodevtest;

// takes this when flag -DNEODEV_CPP_TEST is active
#ifdef NEODEV_CPP_TEST
neodevtest::TestContractFeatures myContract = neodevtest::getContract();
neodevtest::ContractStorage& myStorage = worldState.storage[myContract.getScriptHash()];
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
   worldState.initialize();                                                                        // cleaning world
   EXPECT_EQ(worldState.gasCount, 0);                                                              // no gas consumed (yet)
   EXPECT_EQ(myStorage[toHex("Hello")], ""); // empty storage on key "Hello"
   String s;
   Array a;
   NeoContract::main(s, a);
   EXPECT_EQ(worldState.gasCount, 1); // consumed some gas (TODO: fix this value)
   EXPECT_EQ(myStorage[toHex("Hello")], toHex("World"));
}