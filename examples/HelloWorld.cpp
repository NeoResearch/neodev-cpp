// compiler reference: https://mbebenita.github.io/WasmExplorer/

#include <neodev/SmartContract.hpp>

using namespace neodev;
using namespace neodev::vmtype;
using namespace neodev::abitype;

const char* soi{ "oi" };
const char* stest{ "test" };

namespace neo {

struct any
{
   //any(char argv[]);
};

extern "C" int
__ArraySize();

/*
struct fixed8
{
   const long base;
   constexpr explicit fixed8(long l)
     : base{ l }
   {
   }
};
*/

}

using namespace neo;

int
Size(Array a);

//void f () __attribute__ ((weak, alias ("__f")));

extern "C" int
__Size3()
{
   return 1;
}

int
Size2(ByteArray a);

[[gnu::always_inline]]
  //[[deprecated("because Bla")]]
  extern "C" int
  Size4() __attribute__((deprecated("tst"), alias("__Size3")));

extern "C" int
__Size9()
{
   return 1;
}

/*
struct entrypoint
{
  entrypoint(int argc, char* argv[]);
  String getstring();
  any* getany();
};

//extern "C" entrypoint Entry(int argc, char* argv[]);
entrypoint Entry(int argc, char* argv[]);
*/

namespace NeoContract {

bool
TestSecond(String op)
{
   //return op == "nada";
   return Equals(op, "nada");
}

//bool TestMy(byte bts[])

//class Contract
//{
//  public:
//  static int k;

extern "C" bool
TestMy(ByteArray bts)
{
   //k = 2;
   Array a;
   int k = 0;
   //if(a.Test() > 0)
   //  k++;
   int z = Size4() + Size4() + k;
   return (Size2(bts) + z) > 0; //bts.size()>0;
}

/*
//constexpr std::array<byte,3>
constexpr byte* AddressToScriptHash(const char v[])
{
  byte scripthash[] = {0x00, 0x01, 0x02};
  for(unsigned i=0; i<sizeof(v); i++)
    scripthash[i] = v[i];
    return scripthash;
}
*/

// TODO: on C++17 perhaps possible to hash on compile time

///typedef std::array<byte, 20> _UInt160; // perhaps not good.. too complex for instructions
// good only for internals constexpr

///ByteArray _toarray(_UInt160 hash);

ByteArray
toarray(UInt160 hash);

// cannot use _UInt160 anywhere (not constexpr)
//constexpr UInt160 _convert160(_UInt160 hash);

int
GetArrayLength(ByteArray ba)
{
   return ba.length();
}

bool
ExperimentArrayLength()
{
   // explicit byte arrays should be constexpr
   constexpr byte b[] = { 0x04, 0x05, 0x06, 0x07 };
   ByteArray ba = ConvertToByteArray(b);
   // failure: non-member
   //byte bt = ba[0];
   return ba.length() > 7;
}

bool
ExperimentConcat()
{
   // explicit byte arrays should be constexpr
   constexpr byte b1[] = { 0x04, 0x05 };
   constexpr byte b2[] = { 0x06, 0x07 };
   ByteArray ba1 = ConvertToByteArray(b1);
   ByteArray ba2 = ConvertToByteArray(b2);
   ba1.concat(ba2);

   return ba1.length() > 7;
}

bool
NothingToDo()
{
   return false;
}

/**
 * @api {get} /user/:id Request User information
 * @apiName GetUser
 * @apiGroup User
 *
 * @apiParam {Number} id Users unique ID.
 *
 * @apiSuccess {String} firstname Firstname of the User.
 * @apiSuccess {String} lastname  Lastname of the User.
 */

Object
main(String op, Object params[])
{
   int x = 10;

   Object o;
   return o;
}

int
NeoMain1(String op, Array ops)
{

   ExperimentArrayLength();
   ExperimentConcat();

   //std::array<byte, 3> t1 = {0x01,0x02,0x03};
   //_UInt160 t2;
   //UInt160 t3 = _convert160(t2);

   UInt160 t3;

   ByteArray b1 = toarray(t3);

   constexpr long num2 = 0.3_fixed8;
   //long num3 = 0.3_unused;
   long num3 = 0;
   long num = num2 + NothingToDo() + num3;

   //float x2 = 3.5;
   //printf("%f",x2);

   //constexpr fixed8 number = 0.5_f8;

   //constexpr long num2 = num + toInt(number);
   int sz = 0;

   //UInt160 test;
   //int sz = TestSize(test);

   int p = 3 + num + sz; // + x2;// + ops.Test();
   int p2 = 10;
   if (Equals(op, "xyz")) {
      p += 20;
      p2 = 30 + num;
   } else {
      p2 = 50;
      p--;
   }

   //return op == std::string_literals::operator""s("test"s);
   //if(op == "mytest")//stest)
   if (Equals(op, "mytest"))         //stest)
      return 1 + p - p2 + Size(ops); //ops.size();
   //else if(op == "oi")//soi)
   else if (Equals(op, "oi"))         //soi)
      return -1 + p + p2 + Size(ops); //ops.size();
   else {
      const byte x[] = { 0x00, 0x01, 0x02 };
      ByteArray ba = ConvertToByteArray(x);
      ///printf("HELLO!!");
      if (TestSecond(op) && TestMy(ba))
         return 99 + p - p2;

      return TestSecond(op) + 20 - p + p2;
   }
}

//}; // end class

} // namespace

/*
int main(int argc, char* argv[])
{
  //entrypoint e = Entry(argc, argv);
  //NeoMain(e.getstring(), e.getany());
  int k = sizeof(argv);
  any anyarray[argc];
  array args;
  return NeoContract::NeoMain(argv[k], args);
   //return NeoMain()
  //any ops[0];
  //int k = NeoMain(soi, ops);
  //k++;
  //return k+argc;
}
*/
