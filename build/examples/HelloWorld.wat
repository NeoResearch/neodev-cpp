(module
  (type $FUNCSIG$i (func (result i32)))
  (type $FUNCSIG$v (func))
  (type $FUNCSIG$vii (func (param i32 i32)))
  (type $FUNCSIG$ii (func (param i32) (result i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray2atEi" (func $_ZN6neodev6vmtype9ByteArray2atEi (param i32) (result i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray3setEih" (func $_ZN6neodev6vmtype9ByteArray3setEih (param i32 i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray6lengthEv" (func $_ZN6neodev6vmtype9ByteArray6lengthEv (result i32)))
  (import "env" "_ZN6neodev7abitype6Object11asByteArrayEv" (func $_ZN6neodev7abitype6Object11asByteArrayEv))
  (import "env" "_ZN6neodev7abitype6Object5asIntEv" (func $_ZN6neodev7abitype6Object5asIntEv (result i32)))
  (import "env" "_ZN6neodev7abitype6String6lengthEv" (func $_ZN6neodev7abitype6String6lengthEv (result i32)))
  (table $T0 0 anyfunc)
  (memory $0 1)
  (data (i32.const 16) "oi\00")
  (data (i32.const 20) "\10\00\00\00")
  (data (i32.const 32) "test\00")
  (data (i32.const 40) " \00\00\00")
  (export "memory" (memory $0))
  (export "_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE" (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE))
  (export "_ZN11NeoContract11NothingToDoEv" (func $_ZN11NeoContract11NothingToDoEv))
  (export "_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE" (func $_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE))
  (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE (result i32)
    i32.const 10
    i32.const 30
    call $_ZN6neodev6vmtype9ByteArray6lengthEv
    i32.const 0
    i32.gt_s
    select)
  (func $_ZN11NeoContract11NothingToDoEv (result i32)
    i32.const 0)
  (func $_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE (param $0 i32) (result i32)
    (local $1 i32)
    call $_ZN6neodev7abitype6String6lengthEv
    set_local $1
    call $_ZN6neodev7abitype6Object11asByteArrayEv
    i32.const 5
    i32.const 1
    call $_ZN6neodev6vmtype9ByteArray3setEih
    call $_ZN6neodev7abitype6Object5asIntEv
    i32.const 11
    i32.const 10
    get_local $1
    i32.const 0
    i32.gt_s
    select
    i32.add
    i32.const 5
    call $_ZN6neodev6vmtype9ByteArray2atEi
    i32.add
    call $_ZN6neodev7abitype6Object5asIntEv
    i32.add))
