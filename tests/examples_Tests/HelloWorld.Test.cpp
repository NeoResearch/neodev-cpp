//#include<gtest/gtest.h>
#include <gtest/gtest.h>

// core includes
#include <examples/HelloWorld.cpp>

using namespace std;
//using namespace neodev;

// takes this when flag -DNEODEV_CPP_TEST is active
#ifdef NEODEV_CPP_TEST
TestContractFeatures _contract = neodev::_get_contract();
#endif

TEST(ExampleHelloWorldTests, Test_Name)
{
   EXPECT_EQ(_contract.name, "HelloWorld");
}

TEST(ExampleHelloWorldTests, Test_Storage_Is_True)
{
   String s;
   Array a;
   NeoContract::main(s, a);
   EXPECT_EQ(_contract.storage, true);
}

TEST(ExampleHelloWorldTests, Test_Dynamic_Invoke_Is_False)
{
   EXPECT_EQ(_contract.dynamicInvoke, false);
}

TEST(ExampleHelloWorldTests, Test_Run_Storage_Is_Correct)
{
   neodev::_systemStorage.clear(); // cleaning world (TODO: put this elsewhere)
   EXPECT_EQ(neodev::_systemStorage[_contract.name]["Hello"], "");
   String s;
   Array a;
   NeoContract::main(s, a);
   EXPECT_EQ(neodev::_systemStorage[_contract.name]["Hello"], "World");
}