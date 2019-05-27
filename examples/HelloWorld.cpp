// compiler reference: https://mbebenita.github.io/WasmExplorer/

#include <neodev/smartcontract/framework/SmartContract.hpp>
#include <neodev/smartcontract/framework/services/neo/Storage.hpp>

using namespace neodev::smartcontract::framework;
using namespace neodev::smartcontract::framework::services::neo;
using namespace neodev::vmtype;
using namespace neodev::abitype;

const char* soi{ "oi" };
const char* stest{ "test" };

namespace NeoContract
{

ENTRYPOINT
void
main(String op, Array params)
{
   StorageContext ctx = Storage::CurrentContext();

/*
   int y1 = test1(10, 5.1f, op, params);
   int y2 = test2(10, 5.1f, op, params);

   int x = 10;

   if (op.length() > 0)
      x++;

   Object o = params.at(0);
   ByteArray b = o.asByteArray();
   b.set(5, 0x01);
   nopbyte(0);
   //b[7] = 0x02; (i32.store 8 => BAD!

   //int b3 = b.operator[4];
   //byte* b1 = b.asBytes(); // memory store
   //b1[4] = 0x0a+x; // memory store
   //b.at(2);

   Object o2 = params.at(1);

   return o.asInt() + x + b.at(5) + o2.asInt();
   */
}

} // namespace NeoContract

INVOKE_ENTRYPOINT(NeoContract::main(String(), Array()))
