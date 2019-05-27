#include <neodev/devpack.hpp>

namespace NeoContract {

ENTRYPOINT
void main(String op, Array params)
{
   StorageContext ctx = Storage::CurrentContext();

   Storage::Put(ctx, Str("Hello"), Str("World"));
}

} // namespace NeoContract

// declare entrypoint NeoContract::main as real main function
DECLARE_MAIN(NeoContract::main(String(), Array()))
