(module
  (type $FUNCSIG$i (func (result i32)))
  (type $FUNCSIG$v (func))
  (type $FUNCSIG$vii (func (param i32 i32)))
  (type $FUNCSIG$ii (func (param i32) (result i32)))
  (import "env" "_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv" (func $_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv))
  (import "env" "_ZN6neodev13smartcontract9framework8services3neo7Storage3PutINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_" (func $_ZN6neodev13smartcontract9framework8services3neo7Storage3PutINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_ (param i32 i32)))
  (import "env" "_ZN6neodev6vmtype5Array4InitEv" (func $_ZN6neodev6vmtype5Array4InitEv (result i32)))
  (import "env" "_ZN6neodev7abitype3StrINS_15_convert_StringEEENS0_6StringEPKc" (func $_ZN6neodev7abitype3StrINS_15_convert_StringEEENS0_6StringEPKc (param i32) (result i32)))
  (import "env" "_ZN6neodev7abitype6String4InitEv" (func $_ZN6neodev7abitype6String4InitEv (result i32)))
  (table $T0 0 anyfunc)
  (memory $0 1)
  (data (i32.const 16) "Hello\00")
  (data (i32.const 32) "World\00")
  (export "memory" (memory $0))
  (export "main" (func $main))
  (func $main (result i32)
    call $_ZN6neodev7abitype6String4InitEv
    i32.load
    call $_ZN6neodev6vmtype5Array4InitEv
    call $_ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringERNS1_6vmtype5ArrayE
    i32.const 16)
  (func $_ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringERNS1_6vmtype5ArrayE (param $0 i32) (param $1 i32)
    call $_ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv
    i32.const 16
    call $_ZN6neodev7abitype3StrINS_15_convert_StringEEENS0_6StringEPKc
    i32.const 32
    call $_ZN6neodev7abitype3StrINS_15_convert_StringEEENS0_6StringEPKc
    call $_ZN6neodev13smartcontract9framework8services3neo7Storage3PutINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_))
