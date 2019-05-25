(module
  (type (;0;) (func))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 funcref))
  (func $__post_instantiate (type 0)
    global.get 0
    i32.const 0
    i32.add
    global.set 2
    global.get 2
    i32.const 5242880
    i32.add
    global.set 3)
  (global (;2;) (mut i32) (i32.const 0))
  (global (;3;) (mut i32) (i32.const 0))
  (global (;4;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (export "__post_instantiate" (func $__post_instantiate)))
