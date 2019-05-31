#ifndef NEODEV_SMARTCONTRACT_HPP
#define NEODEV_SMARTCONTRACT_HPP

#include "../../types.hpp"
// globally using vmtype and abitype every time this is used (good for users!)
using namespace neodev::vmtype;
using namespace neodev::abitype;

namespace neodev::smartcontract::framework {

struct emit_abi
{};
struct emit_entrypoint
{};
// marks function to export ABI
#define EXPORT_ABI template<typename _emit = emit_abi>
// marks function as contract entrypoint
#define ENTRYPOINT template<typename _emit = emit_entrypoint>

#ifdef NEODEV_CPP_TEST
// main on tests (TODO: perhaps declare Storage, DynInvoke and other features here... to pass for test engine)
#define DECLARE_MAIN(f) void _nodev_nothing(){};  //\
   //int main()                \
   //{                         \
   //   f;                     \
   //   return 0;              \
   //};
#else
// ensures compiler won't optimize-out the main method ;)
#define DECLARE_MAIN(f) \
   int main()                \
   {                         \
      f;                     \
      return 0;              \
   };
#endif

class SmartContract
{
public:
   //[OpCode(OpCode.SHA1)]
   static vmtype::ByteArray Sha1(vmtype::ByteArray data);

   //[OpCode(OpCode.SHA256)]
   static vmtype::ByteArray Sha256(vmtype::ByteArray data);

   //[Syscall("Neo.Crypto.Hash160")]
   static vmtype::ByteArray Hash160(vmtype::ByteArray data);

   //[Syscall("Neo.Crypto.Hash256")]
   static vmtype::ByteArray Hash256(vmtype::ByteArray data);

   //[Syscall("Neo.Crypto.CheckSig")]
   static bool VerifySignature(vmtype::ByteArray signature, vmtype::ByteArray pubkey);

   //[Syscall("System.Crypto.Verify")]
   static bool VerifySignature(vmtype::ByteArray message, vmtype::ByteArray signature, vmtype::ByteArray pubkey);

   //[Syscall("Neo.Crypto.CheckMultiSig")]
   static bool VerifySignatures(vmtype::ByteArray signatures[], vmtype::ByteArray pubkeys[]);
};
}

#endif
