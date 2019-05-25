(module
 (import "env" "memory" (memory $memory 256))
 (data (global.get $__memory_base) "\00\00\00\00\00\00\00\00oi\00test")
 (import "env" "table" (table $table 0 funcref))
 (import "env" "__memory_base" (global $__memory_base i32))
 (import "env" "__table_base" (global $__table_base i32))
 (global $STACKTOP (mut i32) (i32.const 0))
 (global $STACK_MAX (mut i32) (i32.const 0))
 (global $f0 (mut f32) (f32.const 0))
 (global $_soi i32 (i32.const 0))
 (global $_stest i32 (i32.const 4))
 (export "__post_instantiate" (func $__post_instantiate))
 (export "_soi" (global $_soi))
 (export "_stest" (global $_stest))
 (func $__apply_relocations (; 0 ;)
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
 (func $__post_instantiate (; 1 ;)
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
