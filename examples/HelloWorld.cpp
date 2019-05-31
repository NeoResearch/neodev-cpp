#include <neodev/devpack.hpp>

class NeoContract
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
DECLARE_MAIN(NeoContract::main(String::init(), Array::init()), HAS_STORAGE, NO_DYNAMICINVOKE, "HelloWorld")
