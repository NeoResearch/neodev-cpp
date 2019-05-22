(module
  (type $FUNCSIG$ii (func (param i32) (result i32)))
  (type $FUNCSIG$i (func (result i32)))
  (type $FUNCSIG$vi (func (param i32)))
  (type $FUNCSIG$v (func))
  (import "env" "_Z4SizeN3neo5arrayE" (func $_Z4SizeN3neo5arrayE (result i32)))
  (import "env" "_Z5Size2N6neodev6vmtype9ByteArrayE" (func $_Z5Size2N6neodev6vmtype9ByteArrayE (result i32)))
  (import "env" "_ZN11NeoContract7toarrayENS_7uint160E" (func $_ZN11NeoContract7toarrayENS_7uint160E))
  (import "env" "_ZN3neo5array4TestEv" (func $_ZN3neo5array4TestEv (result i32)))
  (import "env" "_ZN6neodev18ConvertToByteArrayEPKh" (func $_ZN6neodev18ConvertToByteArrayEPKh (param i32)))
  (import "env" "_ZN6neodev6EqualsENS_7abitype6StringEPKc" (func $_ZN6neodev6EqualsENS_7abitype6StringEPKc (param i32) (result i32)))
  (import "env" "_ZN6neodev6vmtype9ByteArray6concatES1_" (func $_ZN6neodev6vmtype9ByteArray6concatES1_))
  (import "env" "_ZN6neodev6vmtype9ByteArray6lengthEv" (func $_ZN6neodev6vmtype9ByteArray6lengthEv (result i32)))
  (table $T0 0 anyfunc)
  (memory $0 1)
  (data (i32.const 16) "oi\00")
  (data (i32.const 20) "\10\00\00\00")
  (data (i32.const 32) "test\00")
  (data (i32.const 40) " \00\00\00")
  (data (i32.const 48) "nada\00")
  (data (i32.const 64) "\04\05\06\07")
  (data (i32.const 80) "\04\05")
  (data (i32.const 96) "\06\07")
  (data (i32.const 112) "xyz\00")
  (data (i32.const 128) "mytest\00")
  (data (i32.const 144) "\00\01\02")
  (export "memory" (memory $0))
  (export "__Size3" (func $__Size3))
  (export "__Size9" (func $__Size9))
  (export "_ZN11NeoContract10TestSecondEN6neodev7abitype6StringE" (func $_ZN11NeoContract10TestSecondEN6neodev7abitype6StringE))
  (export "TestMy" (func $TestMy))
  (export "_ZN11NeoContract14GetArrayLengthEN6neodev6vmtype9ByteArrayE" (func $_ZN11NeoContract14GetArrayLengthEN6neodev6vmtype9ByteArrayE))
  (export "_ZN11NeoContract21ExperimentArrayLengthEv" (func $_ZN11NeoContract21ExperimentArrayLengthEv))
  (export "_ZN11NeoContract16ExperimentConcatEv" (func $_ZN11NeoContract16ExperimentConcatEv))
  (export "_ZN11NeoContract11NothingToDoEv" (func $_ZN11NeoContract11NothingToDoEv))
  (export "_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE" (func $_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE))
  (export "_ZN11NeoContract8NeoMain1EN6neodev7abitype6StringEN3neo5arrayE" (func $_ZN11NeoContract8NeoMain1EN6neodev7abitype6StringEN3neo5arrayE))
  (func $__Size3 (result i32)
    i32.const 1)
  (func $__Size9 (result i32)
    i32.const 1)
  (func $_ZN11NeoContract10TestSecondEN6neodev7abitype6StringE (result i32)
    i32.const 48
    call $_ZN6neodev6EqualsENS_7abitype6StringEPKc)
  (func $TestMy (result i32)
    i32.const 3
    i32.const 2
    call $_ZN3neo5array4TestEv
    i32.const 0
    i32.gt_s
    select
    call $_Z5Size2N6neodev6vmtype9ByteArrayE
    i32.add
    i32.const 0
    i32.gt_s)
  (func $_ZN11NeoContract14GetArrayLengthEN6neodev6vmtype9ByteArrayE (result i32)
    call $_ZN6neodev6vmtype9ByteArray6lengthEv)
  (func $_ZN11NeoContract21ExperimentArrayLengthEv (result i32)
    i32.const 64
    call $_ZN6neodev18ConvertToByteArrayEPKh
    call $_ZN6neodev6vmtype9ByteArray6lengthEv
    i32.const 7
    i32.gt_s)
  (func $_ZN11NeoContract16ExperimentConcatEv (result i32)
    i32.const 80
    call $_ZN6neodev18ConvertToByteArrayEPKh
    i32.const 96
    call $_ZN6neodev18ConvertToByteArrayEPKh
    call $_ZN6neodev6vmtype9ByteArray6concatES1_
    call $_ZN6neodev6vmtype9ByteArray6lengthEv
    i32.const 7
    i32.gt_s)
  (func $_ZN11NeoContract11NothingToDoEv (result i32)
    i32.const 0)
  (func $_ZN11NeoContract4mainEN6neodev7abitype6StringEPNS1_6ObjectE (param $0 i32)
    unreachable)
  (func $_ZN11NeoContract8NeoMain1EN6neodev7abitype6StringEN3neo5arrayE (result i32)
    (local $0 i32) (local $1 i32) (local $2 i32)
    call $_ZN11NeoContract21ExperimentArrayLengthEv
    drop
    call $_ZN11NeoContract16ExperimentConcatEv
    drop
    call $_ZN11NeoContract7toarrayENS_7uint160E
    i32.const 30000030
    i32.const 50
    i32.const 112
    call $_ZN6neodev6EqualsENS_7abitype6StringEPKc
    tee_local $0
    select
    set_local $2
    i32.const 30000023
    i32.const 30000002
    get_local $0
    select
    set_local $1
    block $label$0
      i32.const 128
      call $_ZN6neodev6EqualsENS_7abitype6StringEPKc
      i32.eqz
      br_if $label$0
      get_local $1
      i32.const 1
      i32.add
      get_local $2
      i32.sub
      call $_Z4SizeN3neo5arrayE
      i32.add
      return
    end
    block $label$1
      i32.const 16
      call $_ZN6neodev6EqualsENS_7abitype6StringEPKc
      i32.eqz
      br_if $label$1
      get_local $1
      get_local $2
      i32.add
      call $_Z4SizeN3neo5arrayE
      i32.add
      i32.const -1
      i32.add
      return
    end
    i32.const 144
    call $_ZN6neodev18ConvertToByteArrayEPKh
    block $label$2
      i32.const 48
      call $_ZN6neodev6EqualsENS_7abitype6StringEPKc
      i32.eqz
      br_if $label$2
      call $TestMy
      i32.eqz
      br_if $label$2
      get_local $1
      i32.const 99
      i32.add
      get_local $2
      i32.sub
      return
    end
    i32.const 7
    i32.const -29999952
    get_local $0
    select
    i32.const 21
    i32.const 20
    i32.const 48
    call $_ZN6neodev6EqualsENS_7abitype6StringEPKc
    select
    i32.add))
