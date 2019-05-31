(module
  (type (;0;) (func (param i32)))
  (type (;1;) (func))
  (type (;2;) (func (param i32 i32 i32)))
  (type (;3;) (func (result i32)))
  (type (;4;) (func (param i32) (result i32)))
  (type (;5;) (func (param i32 i32)))
  (import "env" "abortStackOverflow" (func $abortStackOverflow (type 0)))
  (import "env" "__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv" (func $__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv (type 1)))
  (import "env" "__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv" (func $__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv (type 1)))
  (import "env" "__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_" (func $__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_ (type 2)))
  (import "env" "__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v" (func $__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v (type 3)))
  (import "env" "__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc" (func $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc (type 4)))
  (import "env" "__ZN6neodev7abitype6String4initEv" (func $__ZN6neodev7abitype6String4initEv (type 3)))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 funcref))
  (func $_main (type 3) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32)
    global.get 2
    local.set 6
    global.get 2
    i32.const 16
    i32.add
    global.set 2
    global.get 2
    global.get 3
    i32.ge_s
    if  ;; label = @1
      i32.const 16
      call $abortStackOverflow
    end
    local.get 6
    i32.const 8
    i32.add
    local.set 0
    local.get 6
    local.set 2
    i32.const 0
    local.set 1
    call $__ZN17_ContractFeaturesI20_feature_has_storage21_feature_no_dyninvokeE6deployEv
    call $__ZN6neodev7abitype6String4initEv
    local.set 3
    local.get 2
    local.get 3
    i32.store
    call $__ZN6neodev6vmtype5Array4initINS_7_noemitEEERS1_v
    local.set 4
    local.get 0
    local.get 2
    i32.load
    i32.store
    local.get 0
    local.get 4
    call $__ZN11NeoContract4mainI15emit_entrypointEEvN6neodev7abitype6StringERNS2_6vmtype5ArrayE
    local.get 6
    global.set 2
    i32.const 0
    return)
  (func $__ZN11NeoContract4mainI15emit_entrypointEEvN6neodev7abitype6StringERNS2_6vmtype5ArrayE (type 5) (param i32 i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 2
    local.set 12
    global.get 2
    i32.const 32
    i32.add
    global.set 2
    global.get 2
    global.get 3
    i32.ge_s
    if  ;; label = @1
      i32.const 32
      call $abortStackOverflow
    end
    local.get 12
    i32.const 20
    i32.add
    local.set 4
    local.get 12
    i32.const 16
    i32.add
    local.set 3
    local.get 12
    i32.const 12
    i32.add
    local.set 2
    local.get 12
    i32.const 24
    i32.add
    local.set 6
    local.get 12
    i32.const 4
    i32.add
    local.set 7
    local.get 12
    local.set 8
    local.get 1
    local.set 5
    call $__ZN6neodev13smartcontract9framework8services3neo7Storage10getContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv
    global.get 0
    i32.const 0
    i32.add
    call $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc
    local.set 9
    local.get 7
    local.get 9
    i32.store
    global.get 0
    i32.const 6
    i32.add
    call $__ZN6neodev7abitype3strINS_15_convert_StringEEENS0_6StringEPKc
    local.set 10
    local.get 8
    local.get 10
    i32.store
    local.get 2
    local.get 6
    i32.load8_s
    i32.store8
    local.get 3
    local.get 7
    i32.load
    i32.store
    local.get 4
    local.get 8
    i32.load
    i32.store
    local.get 2
    local.get 3
    local.get 4
    call $__ZN6neodev13smartcontract9framework8services3neo7Storage3putINS_29_emit_syscall_Neo_Storage_PutEEEvNS3_14StorageContextENS_7abitype6StringES9_
    local.get 12
    global.set 2
    return)
  (func $__post_instantiate (type 1)
    global.get 0
    i32.const 16
    i32.add
    global.set 2
    global.get 2
    i32.const 5242880
    i32.add
    global.set 3)
  (global (;2;) (mut i32) (i32.const 0))
  (global (;3;) (mut i32) (i32.const 0))
  (global (;4;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (global (;5;) i32 (i32.const 5242896))
  (export "__post_instantiate" (func $__post_instantiate))
  (export "_main" (func $_main))
  (export "__declare_contract_features" (global 5))
  (data (;0;) (global.get 0) "Hello\00World"))
