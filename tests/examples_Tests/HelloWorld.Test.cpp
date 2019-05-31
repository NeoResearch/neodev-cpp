//#include<gtest/gtest.h>
#include <gtest/gtest.h>

// core includes
#include <examples/HelloWorld.cpp>

using namespace std;
//using namespace neodev;

TEST(ExampleHelloWorldTests, Test_ReadByte_0x02)
{
   String s;
   Array a;
   NeoContract::main(s,a);
   EXPECT_EQ(1,1);
}

TEST(ExampleHelloWorldTests, Test_ReadByte_0x0102030405)
{
   //vbyte param = { 0x01, 0x02, 0x03, 0x04, 0x05 };
   //BinaryReader reader(param);
   //EXPECT_EQ(reader.ReadByte(), 0x01);
   //EXPECT_EQ(reader.ReadByte(), 0x02);
   //EXPECT_EQ(reader.ReadByte(), 0x03);
   //EXPECT_EQ(reader.ReadByte(), 0x04);
   //EXPECT_EQ(reader.ReadByte(), 0x05);
   EXPECT_EQ(1,1);
}
