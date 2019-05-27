(module
  (type $FUNCSIG$i (func (result i32)))
  (type $FUNCSIG$vi (func (param i32)))
  (type $FUNCSIG$v (func))
  (type $FUNCSIG$iif (func (param i32 f32) (result i32)))
  (type $FUNCSIG$ii (func (param i32) (result i32)))
  (type $FUNCSIG$vii (func (param i32 i32)))
  (import "env" "_ZN11NeoContract3nopEh" (func $_ZN11NeoContract3nopEh (param i32)))
  (import "env" "_ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE" (func $_ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE (param i32 f32) (result i32)))
  (import "env" "_ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE" (func $_ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE (param i32 f32) (result i32)))
  (import "env" "_ZN11NeoContract5test3IN6neodev8emit_abiEEEvi" (func $_ZN11NeoContract5test3IN6neodev8emit_abiEEEvi (param i32)))
  (import "env" "_ZN11NeoContract5test4IN6neodev8emit_abiEEEvv" (func $_ZN11NeoContract5test4IN6neodev8emit_abiEEEvv))
  (import "env" "_ZN6neodev6vmtype5Array2atEi" (func $_ZN6neodev6vmtype5Array2atEi (param i32 i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray2atEi" (func $_ZN6neodev6vmtype9ByteArray2atEi (param i32) (result i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray3setEih" (func $_ZN6neodev6vmtype9ByteArray3setEih (param i32 i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray6lengthEv" (func $_ZN6neodev6vmtype9ByteArray6lengthEv (result i32)))
  (import "env" "_ZN6neodev6vmtype9StackItem11asByteArrayEv" (func $_ZN6neodev6vmtype9StackItem11asByteArrayEv (param i32)))
  (import "env" "_ZN6neodev6vmtype9StackItem5asIntEv" (func $_ZN6neodev6vmtype9StackItem5asIntEv (param i32) (result i32)))
  (import "env" "_ZN6neodev7abitype6String6lengthEv" (func $_ZN6neodev7abitype6String6lengthEv (param i32) (result i32)))
  (table $T0 0 anyfunc)
  (memory $0 1)
  (data (i32.const 16) "oi\00")
  (data (i32.const 20) "\10\00\00\00")
  (data (i32.const 32) "test\00")
  (data (i32.const 40) " \00\00\00")
  (export "memory" (memory $0))
  (export "_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE" (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE))
  (export "_ZN11NeoContract11NothingToDoEv" (func $_ZN11NeoContract11NothingToDoEv))
  (export "main" (func $main))
  (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE (result i32)
    i32.const 10
    i32.const 30
    call $_ZN6neodev6vmtype9ByteArray6lengthEv
    i32.const 0
    i32.gt_s
    select)
  (func $_ZN11NeoContract11NothingToDoEv (result i32)
    i32.const 0)
  (func $main (result i32)
    i32.const 10
    call $_ZN11NeoContract5test3IN6neodev8emit_abiEEEvi
    call $_ZN11NeoContract5test4IN6neodev8emit_abiEEEvv
    call $_ZN11NeoContract7neomainIN6neodev8emit_abiEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE
    drop
    i32.const 0)
  (func $_ZN11NeoContract7neomainIN6neodev8emit_abiEEEiNS1_7abitype6StringENS1_6vmtype5ArrayE (result i32)
    (local $0 i32) (local $1 i32) (local $2 i32) (local $3 i32) (local $4 i32)
    i32.const 0
    i32.const 0
    i32.load offset=4
    i32.const 32
    i32.sub
    tee_local $4
    i32.store offset=4
    i32.const 1
    call $_ZN11NeoContract3nopEh
    i32.const 10
    f32.const 0x1.466666p+2 (;=5.1;)
    call $_ZN11NeoContract5test1IiEET_ifN6neodev6vmtype9StackItemENS3_5ArrayE
    drop
    i32.const 10
    f32.const 0x1.466666p+2 (;=5.1;)
    call $_ZN11NeoContract5test2IN6neodev8emit_abiEEEiifNS1_6vmtype9StackItemENS3_5ArrayE
    drop
    get_local $4
    i32.const 24
    i32.add
    call $_ZN6neodev7abitype6String6lengthEv
    set_local $0
    get_local $4
    i32.const 16
    i32.add
    i32.const 0
    call $_ZN6neodev6vmtype5Array2atEi
    get_local $4
    i32.const 8
    i32.add
    call $_ZN6neodev6vmtype9StackItem11asByteArrayEv
    i32.const 5
    i32.const 1
    call $_ZN6neodev6vmtype9ByteArray3setEih
    get_local $4
    i32.const 16
    i32.add
    i32.const 1
    call $_ZN6neodev6vmtype5Array2atEi
    get_local $4
    i32.const 8
    i32.add
    call $_ZN6neodev6vmtype9StackItem5asIntEv
    set_local $1
    i32.const 5
    call $_ZN6neodev6vmtype9ByteArray2atEi
    set_local $2
    get_local $4
    call $_ZN6neodev6vmtype9StackItem5asIntEv
    set_local $3
    i32.const 0
    get_local $4
    i32.const 32
    i32.add
    i32.store offset=4
    get_local $3
    get_local $2
    get_local $1
    i32.const 11
    i32.const 10
    get_local $0
    i32.const 0
    i32.gt_s
    select
    i32.add
    i32.add
    i32.add))
