(module
  (type (;0;) (func (param i32)))
  (type (;1;) (func (result i32)))
  (type (;2;) (func))
  (import "env" "abortStackOverflow" (func $abortStackOverflow (type 0)))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 funcref))
  (func $_main (type 1) (result i32)
    (local i32 i32 i32)
    global.get 2
    local.set 2
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
    i32.const 0
    local.set 0
    local.get 2
    global.set 2
    i32.const 10000
    return)
  (func $__post_instantiate (type 2)
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
  (export "__post_instantiate" (func $__post_instantiate))
  (export "_main" (func $_main)))
