#include <neodev/devpack.hpp> // include C++ Neo devpack

class HelloWorld
{
public:
   ENTRYPOINT
   static void main(String op, Array& params)
   {
      StorageContext ctx = Storage::getContext();
      Storage::put(ctx, str("Hello"), str("World"));
   }
};

// declare entrypoint NeoContract::main as real main function
DECLARE_MAIN(HelloWorld::main(String::init(), Array::init()), HAS_STORAGE, NO_DYNAMICINVOKE, "HelloWorld SmartContract")

#ifdef NEODEV_CPP_TEST                                   // declare tests (powered by gtests library)
neodevtest::TestContractFeatures myContract = neodevtest::getContract();
neodevtest::ContractStorage& myStorage      = neodevtest::worldState.storage[myContract.getScriptHash()];

TEST(ExampleHelloWorldTests, Test_Invoke_Storage)        
{
   worldState.initialize();                              // cleaning world
   EXPECT_EQ(myStorage[toHex("Hello")], "");             // verify empty storage on key "Hello"
   String s; Array a;                                    // create invoke parameters
   HelloWorld::main(s, a);                              // invoke contract
   EXPECT_EQ(myStorage[toHex("Hello")], toHex("World")); // verify value "World" stored on key "Hello"
}
#endif
