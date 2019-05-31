(module
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$v (func))
 (type $FUNCSIG$viii (func (param i32 i32 i32)))
 (type $FUNCSIG$i (func (result i32)))
 (type $FUNCSIG$ii (func (param i32) (result i32)))
 (import "env" "memory" (memory $memory 256))
 (data (global.get $__memory_base) "Hello\00World")
 (import "env" "table" (table $table 0 funcref))
 (import "env" "__memory_base" (global $__memory_base i32))
 (import "env" "__table_base" (global $__table_base i32))
 (import "env" "abortStackOverflow" (func $abortStackOverflow (param i32)))
 (import "env" "__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv" (func $__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv))
 (import "env" "__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv" (func $__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv))
 (import "env" "__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_" (func $__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_ (param i32 i32 i32)))
 (import "env" "__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v" (func $__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v (result i32)))
 (import "env" "__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc" (func $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc (param i32) (result i32)))
 (import "env" "__ZN6neodev7abitype6String4initEv" (func $__ZN6neodev7abitype6String4initEv (result i32)))
 (global $STACKTOP (mut i32) (i32.const 0))
 (global $STACK_MAX (mut i32) (i32.const 0))
 (global $f0 (mut f32) (f32.const 0))
 (global $__declare_contract_features i32 (i32.const 5242896))
 (export "__post_instantiate" (func $__post_instantiate))
 (export "_main" (func $_main))
 (export "__declare_contract_features" (global $__declare_contract_features))
 (func $_main (; 7 ;) (result i32)
  (local $$$byval_copy i32)
  (local $$0 i32)
  (local $$1 i32)
  (local $$2 i32)
  (local $$3 i32)
  (local $label i32)
  (local $sp i32)
  (local.set $sp
   (global.get $STACKTOP)
  )
  (global.set $STACKTOP
   (i32.add
    (global.get $STACKTOP)
    (i32.const 16)
   )
  )
  (if
   (i32.ge_s
    (global.get $STACKTOP)
    (global.get $STACK_MAX)
   )
   (call $abortStackOverflow
    (i32.const 16)
   )
  )
  (local.set $$$byval_copy
   (i32.add
    (local.get $sp)
    (i32.const 8)
   )
  )
  (local.set $$1
   (local.get $sp)
  )
  (local.set $$0
   (i32.const 0)
  )
  (call $__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv)
  (local.set $$2
   (call $__ZN6neodev7abitype6String4initEv)
  )
  (i32.store
   (local.get $$1)
   (local.get $$2)
  )
  (local.set $$3
   (call $__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v)
  )
  (i32.store
   (local.get $$$byval_copy)
   (i32.load
    (local.get $$1)
   )
  )
  (call $__ZN11NeoContract4mainI15emit_entrypointEEvN6neodev7abitype6StringERNS2_6vmtype5ArrayE
   (local.get $$$byval_copy)
   (local.get $$3)
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return
   (i32.const 0)
  )
 )
 (func $__ZN11NeoContract4mainI15emit_entrypointEEvN6neodev7abitype6StringERNS2_6vmtype5ArrayE (; 8 ;) (param $$0 i32) (param $$1 i32)
  (local $$$byval_copy i32)
  (local $$$byval_copy1 i32)
  (local $$$byval_copy2 i32)
  (local $$2 i32)
  (local $$3 i32)
  (local $$4 i32)
  (local $$5 i32)
  (local $$6 i32)
  (local $$7 i32)
  (local $label i32)
  (local $sp i32)
  (local.set $sp
   (global.get $STACKTOP)
  )
  (global.set $STACKTOP
   (i32.add
    (global.get $STACKTOP)
    (i32.const 32)
   )
  )
  (if
   (i32.ge_s
    (global.get $STACKTOP)
    (global.get $STACK_MAX)
   )
   (call $abortStackOverflow
    (i32.const 32)
   )
  )
  (local.set $$$byval_copy2
   (i32.add
    (local.get $sp)
    (i32.const 20)
   )
  )
  (local.set $$$byval_copy1
   (i32.add
    (local.get $sp)
    (i32.const 16)
   )
  )
  (local.set $$$byval_copy
   (i32.add
    (local.get $sp)
    (i32.const 12)
   )
  )
  (local.set $$3
   (i32.add
    (local.get $sp)
    (i32.const 24)
   )
  )
  (local.set $$4
   (i32.add
    (local.get $sp)
    (i32.const 4)
   )
  )
  (local.set $$5
   (local.get $sp)
  )
  (local.set $$2
   (local.get $$1)
  )
  (call $__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv)
  (local.set $$6
   (call $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc
    (i32.add
     (global.get $__memory_base)
     (i32.const 0)
    )
   )
  )
  (i32.store
   (local.get $$4)
   (local.get $$6)
  )
  (local.set $$7
   (call $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc
    (i32.add
     (global.get $__memory_base)
     (i32.const 6)
    )
   )
  )
  (i32.store
   (local.get $$5)
   (local.get $$7)
  )
  (i32.store8
   (local.get $$$byval_copy)
   (i32.load8_s
    (local.get $$3)
   )
  )
  (i32.store
   (local.get $$$byval_copy1)
   (i32.load
    (local.get $$4)
   )
  )
  (i32.store
   (local.get $$$byval_copy2)
   (i32.load
    (local.get $$5)
   )
  )
  (call $__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_
   (local.get $$$byval_copy)
   (local.get $$$byval_copy1)
   (local.get $$$byval_copy2)
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return)
 )
 (func $__post_instantiate (; 9 ;)
  (global.set $STACKTOP
   (i32.add
    (global.get $__memory_base)
    (i32.const 16)
   )
  )
  (global.set $STACK_MAX
   (i32.add
    (global.get $STACKTOP)
    (i32.const 5242880)
   )
  )
 )
)
