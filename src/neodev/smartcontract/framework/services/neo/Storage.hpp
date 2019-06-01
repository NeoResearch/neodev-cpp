#ifndef NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP
#define NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP

#include "../../../../syscalls.hpp"
#include "../../../../types.hpp"
#include "Iterator.hpp"
#include "StorageContext.hpp"

using neodev::abitype::String;
using neodev::vmtype::BigInt;
using neodev::vmtype::ByteArray;

namespace neodev::smartcontract::framework::services::neo {

class Storage
{
public:
   /// <summary>
   /// Returns current StorageContext
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_GetContext)
   static StorageContext getContext();

   /// <summary>
   /// Returns the ByteArray value corresponding to given ByteArray key for Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Get)
   static ByteArray get(StorageContext context, ByteArray key);

   /// <summary>
   /// Returns the ByteArray value corresponding to given String key for Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Get)
   static ByteArray get(StorageContext context, String key);

   /// <summary>
   /// Writes ByteArray value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, ByteArray key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, ByteArray key, BigInt value);

   /// <summary>
   /// Writes String value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, ByteArray key, String value);

   /// <summary>
   /// Writes ByteArray value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, String key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, String key, BigInt value);

   /// <summary>
   /// Writes String value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void put(StorageContext context, String key, String value);

   /// <summary>
   /// Deletes ByteArray key from given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Delete)
   static void del(StorageContext context, ByteArray key);

   /// <summary>
   /// Deletes String key from given Storage context (faster: generates opcode directly)
   /// </summary>

   EMIT_SYSCALL(Neo_Storage_Delete)
   static void del(StorageContext context, String key);

   /// <summary>
   /// Returns a ByteArray to ByteArray iterator for a ByteArray prefix on a given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Find)
   static Iterator<ByteArray, ByteArray> find(StorageContext context, ByteArray prefix);

   /// <summary>
   /// Returns a String to ByteArray iterator for a String prefix on a given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Find)
   static Iterator<String, ByteArray> find(StorageContext context, String prefix);

   /// <summary>
   /// Returns the ByteArray value corresponding to given ByteArray key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Get)
   static ByteArray get(ByteArray key);

   /// <summary>
   /// Returns the ByteArray value corresponding to given String key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Get)
   static ByteArray get(String key);

   /// <summary>
   /// Writes ByteArray value on ByteArray key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(ByteArray key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on ByteArray key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(ByteArray key, BigInt value);

   /// <summary>
   /// Writes String value on ByteArray key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(ByteArray key, String value);

   /// <summary>
   /// Writes ByteArray value on String key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(String key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on String key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(String key, BigInt value);

   /// <summary>
   /// Writes String value on String key for current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Put)
   static void put(String key, String value);

   /// <summary>
   /// Deletes ByteArray key from current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Delete)
   static void del(ByteArray key);

   /// <summary>
   /// Deletes String key from given Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Delete)
   static void del(String key);

   /// <summary>
   /// Returns a ByteArray to ByteArray iterator for a ByteArray prefix on current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Find)
   static Iterator<ByteArray, ByteArray> find(ByteArray prefix);

   /// <summary>
   /// Returns a String to ByteArray iterator for a String prefix on current Storage context
   /// </summary>
   EMIT_SYSCALL2(Neo_Storage_GetContext, Neo_Storage_Find)
   static Iterator<String, ByteArray> find(String prefix);
};

// Implementations for C++ native tests (TODO: move for external file and #include here)
#include "../../../../devpacktest.h"

#ifdef NEODEV_CPP_TEST
// implementation of Storage stuff for native tests

EMIT_SYSCALL(Neo_Storage_GetContext)
StorageContext
Storage::getContext()
{
   std::cout << "DEBUG: GETTING CONTEXT FROM STORAGE!" << std::endl;
   neodevtest::worldState.gasCount += neodevtest::worldState.getSyscallPrice("Neo.Storage.GetContext");
   return StorageContext(neodevtest::worldState.storage[neodevtest::getContract().getScriptHash()]);
}

EMIT_SYSCALL(Neo_Storage_Put)
void
Storage::put(StorageContext context, String key, String value)
{
   std::cout << "DEBUG: WRITING ON STORAGE!" << std::endl;
   neodevtest::worldState.gasCount += neodevtest::worldState.getSyscallPrice("Neo.Storage.Put", 10000);
   // TODO: convert to hex string before! all data must be in hex format
   context.contractStorage[neodevtest::ASCIIToHexString(key.str_base)] = neodevtest::ASCIIToHexString(value.str_base);
}

EMIT_SYSCALL(Neo_Storage_Get)
ByteArray
Storage::get(StorageContext context, String key)
{
   std::cout << "DEBUG: READING FROM STORAGE!" << std::endl;
   neodevtest::worldState.gasCount += neodevtest::worldState.getSyscallPrice("Neo.Storage.Get");
   return ByteArray(context.contractStorage[neodevtest::ASCIIToHexString(key.str_base)]);
}
#endif
}

#endif // NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP