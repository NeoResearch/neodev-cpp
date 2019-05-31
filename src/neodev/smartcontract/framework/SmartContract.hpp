#ifndef NEODEV_SMARTCONTRACT_HPP
#define NEODEV_SMARTCONTRACT_HPP

#include "../../types.hpp"
// globally using vmtype and abitype every time this is used (good for users!)
using namespace neodev::vmtype;
using namespace neodev::abitype;

namespace neodev::smartcontract::framework {


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
