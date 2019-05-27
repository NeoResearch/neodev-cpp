(module
  (type (;0;) (func (param i32)))
  (type (;1;) (func (param i32 f64 i32 i32) (result i32)))
  (type (;2;) (func (param i32 i32)))
  (type (;3;) (func (param i32) (result i32)))
  (type (;4;) (func (param i32 i32 i32)))
  (type (;5;) (func (result i32)))
  (type (;6;) (func (param i32 i32) (result i32)))
  (type (;7;) (func))
  (import "env" "abortStackOverflow" (func $abortStackOverflow (type 0)))
  (import "env" "__ZN11NeoContract4nopuEj" (func $__ZN11NeoContract4nopuEj (type 0)))
  (import "env" "__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE" (func $__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE (type 1)))
  (import "env" "__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE" (func $__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE (type 1)))
  (import "env" "__ZN11NeoContract6nopintEi" (func $__ZN11NeoContract6nopintEi (type 0)))
  (import "env" "__ZN11NeoContract7nopbyteEh" (func $__ZN11NeoContract7nopbyteEh (type 0)))
  (import "env" "__ZN11NeoContract7nopcharEc" (func $__ZN11NeoContract7nopcharEc (type 0)))
  (import "env" "__ZN11NeoContract7nopuintEj" (func $__ZN11NeoContract7nopuintEj (type 0)))
  (import "env" "__ZN11NeoContract8nopucharEh" (func $__ZN11NeoContract8nopucharEh (type 0)))
  (import "env" "__ZN6neodev6vmtype5Array2atEi" (func $__ZN6neodev6vmtype5Array2atEi (type 2)))
  (import "env" "__ZN6neodev6vmtype9ByteArray2atEi" (func $__ZN6neodev6vmtype9ByteArray2atEi (type 3)))
  (import "env" "__ZN6neodev6vmtype9ByteArray3setEih" (func $__ZN6neodev6vmtype9ByteArray3setEih (type 4)))
  (import "env" "__ZN6neodev6vmtype9StackItem11asByteArrayEv" (func $__ZN6neodev6vmtype9StackItem11asByteArrayEv (type 0)))
  (import "env" "__ZN6neodev6vmtype9StackItem5asIntEv" (func $__ZN6neodev6vmtype9StackItem5asIntEv (type 3)))
  (import "env" "__ZN6neodev7abitype6String6lengthEv" (func $__ZN6neodev7abitype6String6lengthEv (type 3)))
  (import "env" "__memory_base" (global (;0;) i32))
  (import "env" "__table_base" (global (;1;) i32))
  (import "env" "memory" (memory (;0;) 256))
  (import "env" "table" (table (;0;) 0 funcref))
  (func $_main (type 5) (result i32)
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
    i32.const 7
    i32.add
    local.set 1
    local.get 6
    i32.const 6
    i32.add
    local.set 0
    local.get 6
    i32.const 5
    i32.add
    local.set 3
    local.get 6
    i32.const 4
    i32.add
    local.set 4
    i32.const 0
    local.set 2
    local.get 0
    local.get 3
    i32.load8_s
    i32.store8
    local.get 1
    local.get 4
    i32.load8_s
    i32.store8
    local.get 0
    local.get 1
    call $__ZN11NeoContract7neomainIN6neodev15emit_entrypointEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE
    drop
    local.get 6
    global.set 2
    i32.const 0
    return)
  (func $__ZN11NeoContract7neomainIN6neodev15emit_entrypointEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE (type 6) (param i32 i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 2
    local.set 31
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
    local.get 31
    i32.const 22
    i32.add
    local.set 5
    local.get 31
    i32.const 21
    i32.add
    local.set 4
    local.get 31
    i32.const 20
    i32.add
    local.set 3
    local.get 31
    i32.const 19
    i32.add
    local.set 2
    local.get 31
    i32.const 18
    i32.add
    local.set 23
    local.get 31
    i32.const 17
    i32.add
    local.set 24
    local.get 31
    i32.const 16
    i32.add
    local.set 26
    local.get 31
    i32.const 15
    i32.add
    local.set 27
    local.get 31
    i32.const 14
    i32.add
    local.set 29
    local.get 31
    i32.const 13
    i32.add
    local.set 6
    local.get 31
    i32.const 12
    i32.add
    local.set 7
    i32.const 1
    call $__ZN11NeoContract7nopbyteEh
    i32.const 1
    call $__ZN11NeoContract7nopuintEj
    i32.const 1
    call $__ZN11NeoContract6nopintEi
    i32.const 1
    call $__ZN11NeoContract7nopcharEc
    i32.const 1
    call $__ZN11NeoContract8nopucharEh
    i32.const 1
    call $__ZN11NeoContract4nopuEj
    local.get 2
    local.get 23
    i32.load8_s
    i32.store8
    local.get 3
    local.get 24
    i32.load8_s
    i32.store8
    i32.const 10
    f64.const 0x1.466665fb069cp+2 (;=5.1;)
    local.get 2
    local.get 3
    call $__ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE
    local.set 8
    local.get 8
    local.set 16
    local.get 4
    local.get 26
    i32.load8_s
    i32.store8
    local.get 5
    local.get 27
    i32.load8_s
    i32.store8
    i32.const 10
    f64.const 0x1.466665fb069cp+2 (;=5.1;)
    local.get 4
    local.get 5
    call $__ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE
    local.set 9
    local.get 9
    local.set 25
    i32.const 10
    local.set 28
    local.get 0
    call $__ZN6neodev7abitype6String6lengthEv
    local.set 10
    local.get 10
    i32.const 0
    i32.gt_s
    local.set 11
    local.get 11
    if  ;; label = @1
      local.get 28
      local.set 12
      local.get 12
      i32.const 1
      i32.add
      local.set 13
      local.get 13
      local.set 28
    end
    local.get 1
    i32.const 0
    call $__ZN6neodev6vmtype5Array2atEi
    local.get 29
    call $__ZN6neodev6vmtype9StackItem11asByteArrayEv
    local.get 6
    i32.const 5
    i32.const 1
    call $__ZN6neodev6vmtype9ByteArray3setEih
    i32.const 0
    call $__ZN11NeoContract7nopbyteEh
    local.get 1
    i32.const 1
    call $__ZN6neodev6vmtype5Array2atEi
    local.get 29
    call $__ZN6neodev6vmtype9StackItem5asIntEv
    local.set 14
    local.get 28
    local.set 15
    local.get 14
    local.get 15
    i32.add
    local.set 17
    i32.const 5
    call $__ZN6neodev6vmtype9ByteArray2atEi
    local.set 18
    local.get 18
    i32.const 255
    i32.and
    local.set 19
    local.get 17
    local.get 19
    i32.add
    local.set 20
    local.get 7
    call $__ZN6neodev6vmtype9StackItem5asIntEv
    local.set 21
    local.get 20
    local.get 21
    i32.add
    local.set 22
    local.get 31
    global.set 2
    local.get 22
    return)
  (func $__apply_relocations (type 7)
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
  (func $__post_instantiate (type 7)
    global.get 0
    i32.const 16
    i32.add
    global.set 2
    global.get 2
    i32.const 5242880
    i32.add
    global.set 3
    call $__apply_relocations)
  (global (;2;) (mut i32) (i32.const 0))
  (global (;3;) (mut i32) (i32.const 0))
  (global (;4;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (global (;5;) i32 (i32.const 0))
  (global (;6;) i32 (i32.const 4))
  (export "__post_instantiate" (func $__post_instantiate))
  (export "_main" (func $_main))
  (export "_soi" (global 5))
  (export "_stest" (global 6))
  (data (;0;) (global.get 0) "\00\00\00\00\00\00\00\00oi\00test"))
