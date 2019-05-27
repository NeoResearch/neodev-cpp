#ifndef NEODEV_SMARTCONTRACT_HPP
#define NEODEV_SMARTCONTRACT_HPP

#include "types.hpp"

namespace neodev {

struct emit_abi
{};
struct emit_entrypoint
{};
// marks function to export ABI
#define EXPORT_ABI template<typename _emit = emit_abi>
// marks function as contract entrypoint
#define ENTRYPOINT template<typename _emit = emit_entrypoint>
// ensures compiler won't optimize-out the main method ;)
#define INVOKE_ENTRYPOINT(f) \
   int main()                \
   {                         \
      f;                     \
      return 0;              \
   };

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
