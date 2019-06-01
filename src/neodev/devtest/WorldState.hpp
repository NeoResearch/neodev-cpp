#ifndef NEODEV_DEVTEST_WORLDSTATE_HPP
#define NEODEV_DEVTEST_WORLDSTATE_HPP

#ifdef NEODEV_CPP_TEST

namespace neodevtest {

typedef std::map<std::string, std::string> ContractStorage;

// global world state structure
class WorldState
{
public:
   std::map<std::string, ContractStorage> storage;
   long gasCount{ 0 };
   std::map<std::string, long> syscallFixedPrices;

   void registerFixedPrice(std::string syscall, long gasPrice)
   {
      syscallFixedPrices[syscall] = gasPrice;
   }

   void initialize()
   {
      storage.clear();
      syscallFixedPrices.clear();
      gasCount = 0;
      setPrices();
   }

   long getSyscallPrice(std::string syscall, long param = 0)
   {
      if(param != 0)
         std::cout << "WARNING: IGNORING VARIABLE PRICE ON " << syscall << std::endl;
      return syscallFixedPrices[syscall];
   }

   void setPrices()
   {
      registerFixedPrice("Neo.Runtime.GetTrigger", 1);
      registerFixedPrice("Neo.Runtime.CheckWitness", 200);
      registerFixedPrice("Neo.Runtime.Notify", 1);
      registerFixedPrice("Neo.Runtime.Log", 1);
      registerFixedPrice("Neo.Runtime.GetTime", 1);
      registerFixedPrice("Neo.Runtime.Serialize", 1);
      registerFixedPrice("Neo.Runtime.Deserialize", 1);
      registerFixedPrice("Neo.Blockchain.GetHeight", 1);
      registerFixedPrice("Neo.Blockchain.GetHeader", 100);
      registerFixedPrice("Neo.Blockchain.GetBlock", 200);
      registerFixedPrice("Neo.Blockchain.GetTransaction", 100);
      registerFixedPrice("Neo.Blockchain.GetTransactionHeight", 100);
      registerFixedPrice("Neo.Blockchain.GetAccount", 100);
      registerFixedPrice("Neo.Blockchain.GetValidators", 200);
      registerFixedPrice("Neo.Blockchain.GetAsset", 100);
      registerFixedPrice("Neo.Blockchain.GetContract", 100);
      registerFixedPrice("Neo.Header.GetHash", 1);
      registerFixedPrice("Neo.Header.GetVersion", 1);
      registerFixedPrice("Neo.Header.GetPrevHash", 1);
      registerFixedPrice("Neo.Header.GetMerkleRoot", 1);
      registerFixedPrice("Neo.Header.GetTimestamp", 1);
      registerFixedPrice("Neo.Header.GetIndex", 1);
      registerFixedPrice("Neo.Header.GetConsensusData", 1);
      registerFixedPrice("Neo.Header.GetNextConsensus", 1);
      registerFixedPrice("Neo.Block.GetTransactionCount", 1);
      registerFixedPrice("Neo.Block.GetTransactions", 1);
      registerFixedPrice("Neo.Block.GetTransaction", 1);
      registerFixedPrice("Neo.Transaction.GetHash", 1);
      registerFixedPrice("Neo.Transaction.GetType", 1);
      registerFixedPrice("Neo.Transaction.GetAttributes", 1);
      registerFixedPrice("Neo.Transaction.GetInputs", 1);
      registerFixedPrice("Neo.Transaction.GetOutputs", 1);
      registerFixedPrice("Neo.Transaction.GetReferences", 200);
      registerFixedPrice("Neo.Transaction.GetUnspentCoins", 200);
      registerFixedPrice("Neo.Transaction.GetWitnesses", 200);
      registerFixedPrice("Neo.InvocationTransaction.GetScript", 1);
      registerFixedPrice("Neo.Witness.GetVerificationScript", 100);
      registerFixedPrice("Neo.Attribute.GetUsage", 1);
      registerFixedPrice("Neo.Attribute.GetData", 1);
      registerFixedPrice("Neo.Input.GetHash", 1);
      registerFixedPrice("Neo.Input.GetIndex", 1);
      registerFixedPrice("Neo.Output.GetAssetId", 1);
      registerFixedPrice("Neo.Output.GetValue", 1);
      registerFixedPrice("Neo.Output.GetScriptHash", 1);
      registerFixedPrice("Neo.Account.GetScriptHash", 1);
      registerFixedPrice("Neo.Account.GetVotes", 1);
      registerFixedPrice("Neo.Account.GetBalance", 1);
      registerFixedPrice("Neo.Account.IsStandard", 100);
      //registerFixedPrice("Neo.Asset.Create", Asset_Create); // not fixed
      //registerFixedPrice("Neo.Asset.Renew", Asset_Renew); // not fixed
      registerFixedPrice("Neo.Asset.GetAssetId", 1);
      registerFixedPrice("Neo.Asset.GetAssetType", 1);
      registerFixedPrice("Neo.Asset.GetAmount", 1);
      registerFixedPrice("Neo.Asset.GetAvailable", 1);
      registerFixedPrice("Neo.Asset.GetPrecision", 1);
      registerFixedPrice("Neo.Asset.GetOwner", 1);
      registerFixedPrice("Neo.Asset.GetAdmin", 1);
      registerFixedPrice("Neo.Asset.GetIssuer", 1);
      //registerFixedPrice("Neo.Contract.Create", Contract_Create); // not fixed
      //registerFixedPrice("Neo.Contract.Migrate", Contract_Migrate); // // not fixed
      registerFixedPrice("Neo.Contract.Destroy", 1);
      registerFixedPrice("Neo.Contract.GetScript", 1);
      registerFixedPrice("Neo.Contract.IsPayable", 1);
      registerFixedPrice("Neo.Contract.GetStorageContext", 1);
      registerFixedPrice("Neo.Storage.GetContext", 1);
      registerFixedPrice("Neo.Storage.GetReadOnlyContext", 1);
      registerFixedPrice("Neo.Storage.Get", 100);
      //registerFixedPrice("Neo.Storage.Put", Storage_Put); // not fixed
      registerFixedPrice("Neo.Storage.Delete", 100);
      registerFixedPrice("Neo.Storage.Find", 1);
      registerFixedPrice("Neo.StorageContext.AsReadOnly", 1);
      registerFixedPrice("Neo.Enumerator.Create", 1);
      registerFixedPrice("Neo.Enumerator.Next", 1);
      registerFixedPrice("Neo.Enumerator.Value", 1);
      registerFixedPrice("Neo.Enumerator.Concat", 1);
      registerFixedPrice("Neo.Iterator.Create", 1);
      registerFixedPrice("Neo.Iterator.Key", 1);
      registerFixedPrice("Neo.Iterator.Keys", 1);
      registerFixedPrice("Neo.Iterator.Values", 1);
      registerFixedPrice("Neo.Iterator.Concat", 1);
      registerFixedPrice("Neo.Iterator.Next", 1);
      registerFixedPrice("Neo.Iterator.Value", 1);
   }
};

// global world state 'worldState'
WorldState worldState;

}
#endif // NEODEV_CPP_TEST

#endif // NEODEV_DEVTEST_WORLDSTATE_HPP