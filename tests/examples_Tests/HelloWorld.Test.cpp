//#include<gtest/gtest.h>
#include <gtest/gtest.h>

// core includes
#include <examples/HelloWorld.cpp>

using namespace std;
//using namespace neodev;

// takes this when flag -DNEODEV_CPP_TEST is active
#ifdef NEODEV_CPP_TEST
TestContractFeatures f = ::_get_contract();
#endif

TEST(ExampleHelloWorldTests, Test_Storage_Is_True)
{
   String s;
   Array a;
   NeoContract::main(s, a);
   EXPECT_EQ(f.storage, true);
}

TEST(ExampleHelloWorldTests, Test_Dynamic_Invoke_Is_False)
{
   EXPECT_EQ(f.dynamicInvoke, false);
}
