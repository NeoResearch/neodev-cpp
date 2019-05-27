// compiler reference: https://mbebenita.github.io/WasmExplorer/

#include <neodev/SmartContract.hpp>

using namespace neodev;
using namespace neodev::vmtype;
using namespace neodev::abitype;

const char* soi{ "oi" };
const char* stest{ "test" };

ByteArray
toarray(UInt160 hash);

// cannot use _UInt160 anywhere (not constexpr)
//constexpr UInt160 _convert160(_UInt160 hash);

int
GetArrayLength(ByteArray ba)
{
   if (ba.length() > 0)
      return 10;
   else
      return 30;
   //return ba.length();
}

/*
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
*/

namespace NeoContract {

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

//#define operator [index] GetAt(index, __FUNCTION__)

/*
int __op();

int z = 10;
class Testing
{
   public:
   int k() noexcept __attribute__((pure))
   {
      z++;
      return z;
   }


   int operator[] (int index) __attribute__((deprecated("tst"),alias("__op")));;

};
*/

void
nop(byte b);

template<typename rtype = int>
rtype
test1(int x, float k, Object b, Array c);

EXPORT_ABI
int
test2(int x, float k, Object b, Array c);

EXPORT_ABI
void
test3(int k);

EXPORT_ABI
void
test4();

ENTRYPOINT
int
neomain(String op, Array params)
{
   nop(1);
   int y1 = test1(10, 5.1f, op, params);
   int y2 = test2(10, 5.1f, op, params);

   int x = 10;

   if (op.length() > 0)
      x++;

   //Testing t;
   //x = t[10];
   //x = t.k();
   //x = t.k() + z;

   Object o = params.at(0);
   ByteArray b = o.asByteArray();
   b.set(5, 0x01);
   //int b3 = b.operator[4];
   //byte* b1 = b.asBytes(); // memory store
   //b1[4] = 0x0a+x; // memory store
   //b.at(2);

   Object o2 = params.at(1);

   /*
   int b3[6] = {0,0,0,0,0,0};
   int z = 8;

   if(op.length()>100)
   {
      b3[0] = 20;
      //z = 20;
   }
   else  if(op.length()>200)
   {
      b3[1] = 30;
      //z = 30;
   }
   else 
   if(op.length()>400)
   {
      b3[2] = 45;
      //nop(b3[2]+op.length());
      //z = 45;
      nop(z);
   }
   */

   //op.length();
   //op.length();

   //b1[0] = 0x10;

   //char c[10];
   //c[0] = 'A';

   //nop(b3[2]);
   //nop(z);
   //nop(z);

   //return x+c[1]+b1[4]+b3[5];
   //return x+c[0]+b3[5]+b3[3];
   //return x+c[0]+b3[0]+b3[1]+b3[2];
   //return x+c[0]+b3[0]+b3[1]+b3[2]+z;
   //return o;
   return o.asInt() + x + b.at(5) + o2.asInt();
}

/*
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
      return 1 + p - p2 + ops.size(); //ops.size();
   //else if(op == "oi")//soi)
   else if (Equals(op, "oi"))         //soi)
      return -1 + p + p2 + ops.size(); //ops.size();
   else {
      const byte x[] = { 0x00, 0x01, 0x02 };
      ByteArray ba = ConvertToByteArray(x);

      return   20 - p + p2;
   }
*/
//}

//}; // end class

} // namespace

class NeoContract1
{
};

class MyContract : public NeoContract1
{
public:
   ENTRYPOINT
   static int xxmain(String op, Array args)
   {
      return 100;
   }
};

INVOKE_ENTRYPOINT(NeoContract::neomain(String(), Array()))

// xxmain is ignored during optimization, since it's not used ;)