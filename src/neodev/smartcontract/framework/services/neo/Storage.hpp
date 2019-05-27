#ifndef NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP
#define NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP

#include "../../../../syscalls.hpp"
#include "../../../../types.hpp"
#include "StorageContext.hpp"
#include "Iterator.hpp"

using neodev::vmtype::ByteArray;
using neodev::vmtype::BigInt;
using neodev::abitype::String;

namespace neodev::smartcontract::framework::services::neo {

class Storage
{
public:
   /// <summary>
   /// Returns current StorageContext
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_GetContext)
   static StorageContext CurrentContext();

   /// <summary>
   /// Returns the ByteArray value corresponding to given ByteArray key for Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Get)
   static ByteArray Get(StorageContext context, ByteArray key);
   
   /// <summary>
   /// Returns the ByteArray value corresponding to given String key for Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Get)
   static ByteArray Get(StorageContext context, String key);


   /// <summary>
   /// Writes ByteArray value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, ByteArray key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, ByteArray key, BigInt value);

   /// <summary>
   /// Writes String value on ByteArray key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, ByteArray key, String value);

   /// <summary>
   /// Writes ByteArray value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, String key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, String key, BigInt value);

   /// <summary>
   /// Writes String value on String key for given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Put)
   static void Put(StorageContext context, String key, String value);

   /// <summary>
   /// Deletes ByteArray key from given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Delete)
   static void Delete(StorageContext context, ByteArray key);

   /// <summary>
   /// Deletes String key from given Storage context (faster: generates opcode directly)
   /// </summary>
   
   EMIT_SYSCALL(Neo_Storage_Delete)
   static void Delete(StorageContext context, String key);

   /// <summary>
   /// Returns a ByteArray to ByteArray iterator for a ByteArray prefix on a given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Find)
   static Iterator<ByteArray, ByteArray> Find(StorageContext context, ByteArray prefix);


   /// <summary>
   /// Returns a String to ByteArray iterator for a String prefix on a given Storage context (faster: generates opcode directly)
   /// </summary>
   EMIT_SYSCALL(Neo_Storage_Find)
   static Iterator<String, ByteArray> Find(StorageContext context, String prefix);

/*
   /// <summary>
   /// Returns the ByteArray value corresponding to given ByteArray key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Get")] public static extern ByteArray Get(ByteArray key);

   /// <summary>
   /// Returns the ByteArray value corresponding to given String key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Get")] public static extern ByteArray Get(String key);

   /// <summary>
   /// Writes ByteArray value on ByteArray key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void Put(ByteArray key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on ByteArray key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void
     Put(ByteArray key, BigInt value);

   /// <summary>
   /// Writes String value on ByteArray key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void
     Put(ByteArray key, String value);

   /// <summary>
   /// Writes ByteArray value on String key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void
     Put(String key, ByteArray value);

   /// <summary>
   /// Writes BigInt value on String key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void
     Put(String key, BigInt value);

   /// <summary>
   /// Writes String value on String key for current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Put")] public static extern void
     Put(String key, String value);

   /// <summary>
   /// Deletes ByteArray key from current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Delete")] public static extern void Delete(ByteArray key);

   /// <summary>
   /// Deletes String key from given Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Delete")] public static extern void
     Delete(String key);

   /// <summary>
   /// Returns a ByteArray to ByteArray iterator for a ByteArray prefix on current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Find")] public static extern Iterator<ByteArray, ByteArray>
       Find(ByteArray prefix);

   /// <summary>
   /// Returns a String to ByteArray iterator for a String prefix on current Storage context
   /// </summary>
   [Syscall("Neo.Storage.GetContext")]
     [Syscall("Neo.Storage.Find")] public static extern Iterator<String, ByteArray>
     Find(String prefix);
*/
};
}

#endif // NEODEV_SMARTCONTRACT_FRAMEWORK_SERVICES_NEO_STORAGE_HPP