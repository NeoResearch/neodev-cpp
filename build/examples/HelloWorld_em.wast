(module
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$v (func))
 (import "env" "memory" (memory $memory 256))
 (data (global.get $__memory_base) "\00\00\00\00\00\00\00\00oi\00test")
 (import "env" "table" (table $table 0 funcref))
 (import "env" "__memory_base" (global $__memory_base i32))
 (import "env" "__table_base" (global $__table_base i32))
 (import "env" "abortStackOverflow" (func $abortStackOverflow (param i32)))
 (import "env" "__ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv" (func $__ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv))
 (global $STACKTOP (mut i32) (i32.const 0))
 (global $STACK_MAX (mut i32) (i32.const 0))
 (global $f0 (mut f32) (f32.const 0))
 (global $_soi i32 (i32.const 0))
 (global $_stest i32 (i32.const 4))
 (export "__post_instantiate" (func $__post_instantiate))
 (export "_main" (func $_main))
 (export "_soi" (global $_soi))
 (export "_stest" (global $_stest))
 (func $_main (; 2 ;) (result i32)
  (local $$$byval_copy i32)
  (local $$$byval_copy1 i32)
  (local $$0 i32)
  (local $$1 i32)
  (local $$2 i32)
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
  (local.set $$$byval_copy1
   (i32.add
    (local.get $sp)
    (i32.const 7)
   )
  )
  (local.set $$$byval_copy
   (i32.add
    (local.get $sp)
    (i32.const 6)
   )
  )
  (local.set $$1
   (i32.add
    (local.get $sp)
    (i32.const 5)
   )
  )
  (local.set $$2
   (i32.add
    (local.get $sp)
    (i32.const 4)
   )
  )
  (local.set $$0
   (i32.const 0)
  )
  (i32.store8
   (local.get $$$byval_copy)
   (i32.load8_s
    (local.get $$1)
   )
  )
  (i32.store8
   (local.get $$$byval_copy1)
   (i32.load8_s
    (local.get $$2)
   )
  )
  (call $__ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringENS1_6vmtype5ArrayE
   (local.get $$$byval_copy)
   (local.get $$$byval_copy1)
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return
   (i32.const 0)
  )
 )
 (func $__ZN11NeoContract4mainIN6neodev13smartcontract9framework15emit_entrypointEEEvNS1_7abitype6StringENS1_6vmtype5ArrayE (; 3 ;) (param $$0 i32) (param $$1 i32)
  (local $label i32)
  (local $sp i32)
  (local.set $sp
   (global.get $STACKTOP)
  )
  (call $__ZN6neodev13smartcontract9framework8services3neo7Storage14CurrentContextINS_36_emit_syscall_Neo_Storage_GetContextEEENS3_14StorageContextEv)
  (return)
 )
 (func $__apply_relocations (; 4 ;)
  (local $temp i32)
  (i32.store
   (i32.add
    (global.get $__memory_base)
    (i32.const 0)
   )
   (i32.add
    (i32.load
     (i32.add
      (global.get $__memory_base)
      (i32.const 0)
     )
    )
    (i32.add
     (global.get $__memory_base)
     (i32.const 8)
    )
   )
  )
  (i32.store
   (i32.add
    (global.get $__memory_base)
    (i32.const 4)
   )
   (i32.add
    (i32.load
     (i32.add
      (global.get $__memory_base)
      (i32.const 4)
     )
    )
    (i32.add
     (global.get $__memory_base)
     (i32.const 11)
    )
   )
  )
 )
 (func $__post_instantiate (; 5 ;)
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
  (call $__apply_relocations)
 )
)
