(module
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$iidii (func (param i32 f64 i32 i32) (result i32)))
 (type $FUNCSIG$vii (func (param i32 i32)))
 (type $FUNCSIG$ii (func (param i32) (result i32)))
 (import "env" "memory" (memory $memory 256))
 (data (global.get $__memory_base) "\00\00\00\00\00\00\00\00oi\00test")
 (import "env" "table" (table $table 0 funcref))
 (import "env" "__memory_base" (global $__memory_base i32))
 (import "env" "__table_base" (global $__table_base i32))
 (import "env" "abortStackOverflow" (func $abortStackOverflow (param i32)))
 (import "env" "__ZN11NeoContract3nopEh" (func $__ZN11NeoContract3nopEh (param i32)))
 (import "env" "__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE" (func $__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE (param i32 f64 i32 i32) (result i32)))
 (import "env" "__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE" (func $__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE (param i32 f64 i32 i32) (result i32)))
 (import "env" "__ZN6neodev6vmtype5Array2atEi" (func $__ZN6neodev6vmtype5Array2atEi (param i32 i32)))
 (import "env" "__ZN6neodev6vmtype9ByteArray2atEi" (func $__ZN6neodev6vmtype9ByteArray2atEi (param i32) (result i32)))
 (import "env" "__ZN6neodev6vmtype9ByteArray3setEih" (func $__ZN6neodev6vmtype9ByteArray3setEih (param i32 i32)))
 (import "env" "__ZN6neodev6vmtype9StackItem11asByteArrayEv" (func $__ZN6neodev6vmtype9StackItem11asByteArrayEv (param i32)))
 (import "env" "__ZN6neodev6vmtype9StackItem5asIntEv" (func $__ZN6neodev6vmtype9StackItem5asIntEv (param i32) (result i32)))
 (import "env" "__ZN6neodev7abitype6String6lengthEv" (func $__ZN6neodev7abitype6String6lengthEv (param i32) (result i32)))
 (global $STACKTOP (mut i32) (i32.const 0))
 (global $STACK_MAX (mut i32) (i32.const 0))
 (global $f0 (mut f32) (f32.const 0))
 (global $_soi i32 (i32.const 0))
 (global $_stest i32 (i32.const 4))
 (export "__post_instantiate" (func $__post_instantiate))
 (export "_main" (func $_main))
 (export "_soi" (global $_soi))
 (export "_stest" (global $_stest))
 (func $_main (; 10 ;) (result i32)
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
  (drop
   (call $__ZN11NeoContract7neomainIN6neodev15emit_entrypointEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE
    (local.get $$$byval_copy)
    (local.get $$$byval_copy1)
   )
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return
   (i32.const 0)
  )
 )
 (func $__ZN11NeoContract7neomainIN6neodev15emit_entrypointEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE (; 11 ;) (param $$0 i32) (param $$1 i32) (result i32)
  (local $$$byval_copy i32)
  (local $$$byval_copy1 i32)
  (local $$$byval_copy2 i32)
  (local $$$byval_copy3 i32)
  (local $$10 i32)
  (local $$11 i32)
  (local $$12 i32)
  (local $$13 i32)
  (local $$14 i32)
  (local $$15 i32)
  (local $$16 i32)
  (local $$17 i32)
  (local $$18 i32)
  (local $$19 i32)
  (local $$2 i32)
  (local $$20 i32)
  (local $$21 i32)
  (local $$22 i32)
  (local $$23 i32)
  (local $$24 i32)
  (local $$3 i32)
  (local $$4 i32)
  (local $$5 i32)
  (local $$6 i32)
  (local $$7 i32)
  (local $$8 i32)
  (local $$9 i32)
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
  (local.set $$$byval_copy3
   (i32.add
    (local.get $sp)
    (i32.const 21)
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
    (i32.const 19)
   )
  )
  (local.set $$$byval_copy
   (i32.add
    (local.get $sp)
    (i32.const 18)
   )
  )
  (local.set $$3
   (i32.add
    (local.get $sp)
    (i32.const 17)
   )
  )
  (local.set $$4
   (i32.add
    (local.get $sp)
    (i32.const 16)
   )
  )
  (local.set $$6
   (i32.add
    (local.get $sp)
    (i32.const 15)
   )
  )
  (local.set $$7
   (i32.add
    (local.get $sp)
    (i32.const 14)
   )
  )
  (local.set $$9
   (i32.add
    (local.get $sp)
    (i32.const 13)
   )
  )
  (local.set $$10
   (i32.add
    (local.get $sp)
    (i32.const 12)
   )
  )
  (call $__ZN11NeoContract3nopEh
   (i32.const 1)
  )
  (i32.store8
   (local.get $$$byval_copy)
   (i32.load8_s
    (local.get $$3)
   )
  )
  (i32.store8
   (local.get $$$byval_copy1)
   (i32.load8_s
    (local.get $$4)
   )
  )
  (local.set $$11
   (call $__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE
    (i32.const 10)
    (f64.const 5.0999999)
    (local.get $$$byval_copy)
    (local.get $$$byval_copy1)
   )
  )
  (local.set $$2
   (local.get $$11)
  )
  (i32.store8
   (local.get $$$byval_copy2)
   (i32.load8_s
    (local.get $$6)
   )
  )
  (i32.store8
   (local.get $$$byval_copy3)
   (i32.load8_s
    (local.get $$7)
   )
  )
  (local.set $$12
   (call $__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE
    (i32.const 10)
    (f64.const 5.0999999)
    (local.get $$$byval_copy2)
    (local.get $$$byval_copy3)
   )
  )
  (local.set $$5
   (local.get $$12)
  )
  (local.set $$8
   (i32.const 10)
  )
  (local.set $$13
   (call $__ZN6neodev7abitype6String6lengthEv
    (local.get $$0)
   )
  )
  (local.set $$14
   (i32.gt_s
    (local.get $$13)
    (i32.const 0)
   )
  )
  (if
   (local.get $$14)
   (block
    (local.set $$15
     (local.get $$8)
    )
    (local.set $$16
     (i32.add
      (local.get $$15)
      (i32.const 1)
     )
    )
    (local.set $$8
     (local.get $$16)
    )
   )
  )
  (call $__ZN6neodev6vmtype5Array2atEi
   (local.get $$1)
   (i32.const 0)
  )
  (call $__ZN6neodev6vmtype9StackItem11asByteArrayEv
   (local.get $$9)
  )
  (call $__ZN6neodev6vmtype9ByteArray3setEih
   (i32.const 5)
   (i32.const 1)
  )
  (call $__ZN6neodev6vmtype5Array2atEi
   (local.get $$1)
   (i32.const 1)
  )
  (local.set $$17
   (call $__ZN6neodev6vmtype9StackItem5asIntEv
    (local.get $$9)
   )
  )
  (local.set $$18
   (local.get $$8)
  )
  (local.set $$19
   (i32.add
    (local.get $$17)
    (local.get $$18)
   )
  )
  (local.set $$20
   (call $__ZN6neodev6vmtype9ByteArray2atEi
    (i32.const 5)
   )
  )
  (local.set $$21
   (i32.and
    (local.get $$20)
    (i32.const 255)
   )
  )
  (local.set $$22
   (i32.add
    (local.get $$19)
    (local.get $$21)
   )
  )
  (local.set $$23
   (call $__ZN6neodev6vmtype9StackItem5asIntEv
    (local.get $$10)
   )
  )
  (local.set $$24
   (i32.add
    (local.get $$22)
    (local.get $$23)
   )
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return
   (local.get $$24)
  )
 )
 (func $__apply_relocations (; 12 ;)
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
 (func $__post_instantiate (; 13 ;)
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
