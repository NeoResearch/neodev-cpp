// compiler reference: https://mbebenita.github.io/WasmExplorer/

#include<neodev/SmartContract.hpp>

using namespace neodev;
using namespace neodev::vmtype;
using namespace neodev::abitype;




String ConvertToString(const char* t);


bool Equals(const String b, const char*);




ByteArray ConvertToByteArray(const byte* t);


//constexpr char test[] = "test";
//constexpr char oi[] = "oi";
/*
constexpr String soi{ConvertToString("oi")};
constexpr String stest{ConvertToString("test")};//est;
*/
const char* soi{"oi"};
const char* stest{"test"};//est;

namespace neo
{

struct any
{
  //any(char argv[]);
};

extern "C" int __ArraySize();

struct array
{
  //public:
  //any(char argv[]);
  //int size();
  //{
  //  return 10;
  //}

  //[[alissas("__ArraySize")]]
  //__attribute__ ((alias("oiiii")))
  static int Test()  ; //__attribute__((aliass("__ArraySize")));
};


struct fixed8
{
  const long base;
  constexpr explicit fixed8(long l) : base{l}
  {
  }

};


/*
//[[gnu::always_inline]]
constexpr fixed8 operator "" _f8(long double v)
{
  return fixed8{(int)v*100000000L};
}
*/

constexpr long operator "" _fixed8(long double v)
{
  return v*100000000L;
}


/*
// generates 'load' instructions (avoid at all costs)
long operator "" _unused(long double v)
{
  return v*100000000L;
}
*/




/*
constexpr long toInt(fixed8 f)
{
  return f.base;
}
*/

}

using namespace neo;

int Size(array a);

//void f () __attribute__ ((weak, alias ("__f")));

extern "C" int __Size3()
{
  return 1;
}



int Size2(ByteArray a);

[[gnu::always_inline]]
//[[deprecated("because Bla")]]
extern "C" int Size4() __attribute__((deprecated("tst"),alias("__Size3")));

extern "C" int __Size9()
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


  namespace NeoContract
  {


bool TestSecond(String op)
{
  //return op == "nada";
  return Equals(op,"nada");
}

//bool TestMy(byte bts[])

//class Contract
//{
//  public:
//  static int k;




extern "C" bool TestMy(ByteArray bts)
{
  //k = 2;
  array a;
  int k = 0;
  if(a.Test() > 0)
    k++;
  int z =  Size4()+Size4()+k;
  return (Size2(bts)+z)>0 ;//bts.size()>0;
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

///typedef std::array<byte, 20> _uint160; // perhaps not good.. too complex for instructions
// good only for internals constexpr

struct uint160
{
  // nothing here
};

/*
int TestSize(_uint160 address)
{
  return address.size();
}
*/

///ByteArray _toarray(_uint160 hash);

ByteArray toarray(uint160 hash);


// cannot use _uint160 anywhere (not constexpr)
//constexpr uint160 _convert160(_uint160 hash);

int GetArrayLength(ByteArray ba)
{
  return ba.length();
}

bool ExperimentArrayLength()
{
  // explicit byte arrays should be constexpr
  constexpr byte b[] = {0x04, 0x05, 0x06, 0x07};
  ByteArray ba = ConvertToByteArray(b);
  // failure: non-member
  //byte bt = ba[0];
  return ba.length() > 7;
}

bool ExperimentConcat()
{
  // explicit byte arrays should be constexpr
  constexpr byte b1[] = {0x04, 0x05};
  constexpr byte b2[] = {0x06, 0x07};
  ByteArray ba1 = ConvertToByteArray(b1);
  ByteArray ba2 = ConvertToByteArray(b2);
  ba1.concat(ba2);

  return ba1.length() > 7;
}

bool NothingToDo()
{
   return false;
}

int NeoMain(String op, array ops)
{

  ExperimentArrayLength();
  ExperimentConcat();

  //std::array<byte, 3> t1 = {0x01,0x02,0x03};
  //_uint160 t2;
  //uint160 t3 = _convert160(t2);

  uint160 t3;

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

  //uint160 test;
  //int sz = TestSize(test);

  int p = 3 + num + sz; // + x2;// + ops.Test();
  int p2 = 10;
  if(Equals(op,"xyz"))
  {
    p += 20 ;
    p2 = 30 + num;
  }
  else
  {
    p2 = 50;
    p--;
  }

  //return op == std::string_literals::operator""s("test"s);
  //if(op == "mytest")//stest)
  if(Equals(op,"mytest"))//stest)
    return 1+p-p2+Size(ops);//ops.size();
  //else if(op == "oi")//soi)
  else if(Equals(op,"oi"))//soi)
    return -1+p+p2+Size(ops);//ops.size();
  else
  {
    const byte x[] = {0x00, 0x01, 0x02};
    ByteArray ba = ConvertToByteArray(x);
    ///printf("HELLO!!");
    if( TestSecond(op) && TestMy(ba) )
      return 99+p-p2;

    return TestSecond(op)+20-p+p2;
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
