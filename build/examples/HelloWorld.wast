(module
 (type $FUNCSIG$v (func))
 (import "env" "_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv" (func $_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 16) "oi\00")
 (data (i32.const 20) "\10\00\00\00")
 (data (i32.const 32) "test\00")
 (data (i32.const 40) " \00\00\00")
 (export "memory" (memory $0))
 (export "main" (func $main))
 (func $main (result i32)
  (call $_ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringENS1_6vmtype5ArrayE)
  (i32.const 0)
 )
 (func $_ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringENS1_6vmtype5ArrayE
  (call $_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv)
 )
)
