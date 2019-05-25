(module
 (type $FUNCSIG$vi (func (param i32)))
 (import "env" "memory" (memory $memory 256 256))
 (import "env" "table" (table $table 0 0 funcref))
 (import "env" "__memory_base" (global $__memory_base i32))
 (import "env" "__table_base" (global $__table_base i32))
 (import "env" "abortStackOverflow" (func $abortStackOverflow (param i32)))
 (global $STACKTOP (mut i32) (i32.const 2080))
 (global $STACK_MAX (mut i32) (i32.const 5244960))
 (global $f0 (mut f32) (f32.const 0))
 (export "_main" (func $_main))
 (func $_main (; 1 ;) (result i32)
  (local $$0 i32)
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
  (local.set $$0
   (i32.const 0)
  )
  (global.set $STACKTOP
   (local.get $sp)
  )
  (return
   (i32.const 10000)
  )
 )
)
