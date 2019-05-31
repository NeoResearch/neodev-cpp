(module
  (type $FUNCSIG$v (func))
  (type $FUNCSIG$ii (func (param i32) (result i32)))
  (import "env" "memory" (memory $memory 256))
  (import "env" "memoryBase" (global $memoryBase i32))
  (import "env" "__Z3nopv" (func $__Z3nopv))
  (import "env" "__ZN1X6methodEv" (func $__ZN1X6methodEv (param i32) (result i32)))
  (global $STACKTOP (mut i32) (i32.const 0))
  (global $STACK_MAX (mut i32) (i32.const 0))
  (export "__post_instantiate" (func $__post_instantiate))
  (export "_main" (func $_main))
  (export "runPostSets" (func $runPostSets))
  (func $_main (result i32)
    (local $0 i32) (local $1 i32) (local $2 i32) (local $3 i32)
    global.get $STACKTOP
    local.set $2
    global.get $STACKTOP
    i32.const 16
    i32.add
    global.set $STACKTOP
    local.get $2
    local.set $0
    call $__Z3nopv
    local.get $0
    i32.const 10
    i32.store
    local.get $0
    call $__ZN1X6methodEv
    local.set $1
    local.get $0
    i32.load
    local.set $3
    local.get $1
    i32.const 5
    i32.le_s
    if  ;; label = @1
      block  ;; label = @2
        local.get $2
        global.set $STACKTOP
        local.get $3
        return
      end
    end
    local.get $3
    i32.const 2
    i32.add
    local.set $1
    local.get $0
    local.get $1
    i32.store
    local.get $2
    global.set $STACKTOP
    local.get $1)
  (func $runPostSets
    nop)
  (func $__post_instantiate
    global.get $memoryBase
    global.set $STACKTOP
    global.get $STACKTOP
    i32.const 5242880
    i32.add
    global.set $STACK_MAX
    call $runPostSets)
  (type (;2;) (func (result i32))))

