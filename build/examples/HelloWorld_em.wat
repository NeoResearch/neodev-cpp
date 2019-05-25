(module
  (type (;0;) (func (param i32)))
  (type (;1;) (func (param i32) (result i32)))
  (type (;2;) (func (param i32 i32)))
  (type (;3;) (func (result i32)))
  (type (;4;) (func))
  (type (;5;) (func (param i32 i32) (result i32)))
  (import "env" "abortStackOverflow" (func (;0;) (type 0)))
  (import "env" "__ZN6neodev6vmtype5Array2atEi" (func (;1;) (type 0)))
  (import "env" "__ZN6neodev6vmtype9ByteArray2atEi" (func (;2;) (type 1)))
  (import "env" "__ZN6neodev6vmtype9ByteArray3setEih" (func (;3;) (type 2)))
  (import "env" "__ZN6neodev6vmtype9ByteArray6lengthEv" (func (;4;) (type 3)))
  (import "env" "__ZN6neodev6vmtype9StackItem11asByteArrayEv" (func (;5;) (type 4)))
  (import "env" "__ZN6neodev6vmtype9StackItem5asIntEv" (func (;6;) (type 3)))
  (import "env" "__ZN6neodev7abitype6String6lengthEv" (func (;7;) (type 3)))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "tempDoublePtr" (global (;2;) i32))
  (import "env" "DYNAMICTOP_PTR" (global (;3;) i32))
  (import "global" "NaN" (global (;4;) f64))
  (import "global" "Infinity" (global (;5;) f64))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 funcref))
  (func (;8;) (type 1) (param i32) (result i32)
    (local i32)
    global.get 8
    local.set 1
    global.get 8
    local.get 0
    i32.add
    global.set 8
    global.get 8
    i32.const 15
    i32.add
    i32.const -16
    i32.and
    global.set 8
    global.get 8
    global.get 9
    i32.ge_s
    if  ;; label = @1
      local.get 0
      call 0
    end
    local.get 1
    return)
  (func (;9;) (type 3) (result i32)
    global.get 8
    return)
  (func (;10;) (type 0) (param i32)
    local.get 0
    global.set 8)
  (func (;11;) (type 2) (param i32 i32)
    local.get 0
    global.set 8
    local.get 1
    global.set 9)
  (func (;12;) (type 1) (param i32) (result i32)
    (local i32 i32 i32 i32 i32 i32)
    global.get 8
    local.set 6
    global.get 8
    i32.const 16
    i32.add
    global.set 8
    global.get 8
    global.get 9
    i32.ge_s
    if  ;; label = @1
      i32.const 16
      call 0
    end
    call 4
    local.set 2
    local.get 2
    i32.const 0
    i32.gt_s
    local.set 3
    local.get 3
    if  ;; label = @1
      i32.const 10
      local.set 1
    else
      i32.const 30
      local.set 1
    end
    local.get 1
    local.set 4
    local.get 6
    global.set 8
    local.get 4
    return)
  (func (;13;) (type 3) (result i32)
    (local i32 i32)
    global.get 8
    local.set 1
    i32.const 0
    return)
  (func (;14;) (type 5) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 8
    local.set 16
    global.get 8
    i32.const 16
    i32.add
    global.set 8
    global.get 8
    global.get 9
    i32.ge_s
    if  ;; label = @1
      i32.const 16
      call 0
    end
    i32.const 10
    local.set 7
    call 7
    local.set 8
    local.get 8
    i32.const 0
    i32.gt_s
    local.set 9
    local.get 9
    if  ;; label = @1
      local.get 7
      local.set 10
      local.get 10
      i32.const 1
      i32.add
      local.set 11
      local.get 11
      local.set 7
    end
    i32.const 0
    call 1
    call 5
    i32.const 5
    i32.const 1
    call 3
    i32.const 1
    call 1
    call 6
    local.set 12
    local.get 7
    local.set 13
    local.get 12
    local.get 13
    i32.add
    local.set 14
    i32.const 5
    call 2
    local.set 2
    local.get 2
    i32.const 255
    i32.and
    local.set 3
    local.get 14
    local.get 3
    i32.add
    local.set 4
    call 6
    local.set 5
    local.get 4
    local.get 5
    i32.add
    local.set 6
    local.get 16
    global.set 8
    local.get 6
    return)
  (func (;15;) (type 4)
    (local i32)
    global.get 0
    i32.const 0
    i32.add
    global.get 0
    i32.const 0
    i32.add
    i32.load
    global.get 0
    i32.const 8
    i32.add
    i32.add
    i32.store
    global.get 0
    i32.const 4
    i32.add
    global.get 0
    i32.const 4
    i32.add
    i32.load
    global.get 0
    i32.const 11
    i32.add
    i32.add
    i32.store)
  (func (;16;) (type 4)
    global.get 0
    i32.const 16
    i32.add
    global.set 8
    global.get 8
    i32.const 5242880
    i32.add
    global.set 9
    call 15)
  (global (;6;) (mut i32) (global.get 2))
  (global (;7;) (mut i32) (global.get 3))
  (global (;8;) (mut i32) (i32.const 0))
  (global (;9;) (mut i32) (i32.const 0))
  (global (;10;) (mut i32) (i32.const 0))
  (global (;11;) (mut i32) (i32.const 0))
  (global (;12;) (mut i32) (i32.const 0))
  (global (;13;) (mut i32) (i32.const 0))
  (global (;14;) (mut i32) (i32.const 0))
  (global (;15;) (mut i32) (i32.const 0))
  (global (;16;) (mut i32) (i32.const 0))
  (global (;17;) (mut f64) (f64.const 0x0p+0 (;=0;)))
  (global (;18;) (mut f64) (global.get 4))
  (global (;19;) (mut f64) (global.get 5))
  (global (;20;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (global (;21;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (global (;22;) i32 (i32.const 0))
  (global (;23;) i32 (i32.const 4))
  (export "__post_instantiate" (func 16))
  (export "_soi" (global 22))
  (export "_stest" (global 23))
  (data (;0;) (global.get 0) "\00\00\00\00\00\00\00\00oi\00test"))
