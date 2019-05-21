(module
 (type $FUNCSIG$ii (func (param i32) (result i32)))
 (type $FUNCSIG$i (func (result i32)))
 (type $FUNCSIG$vi (func (param i32)))
 (type $FUNCSIG$v (func))
 (import "env" "_Z18ConvertTobytearrayPKh" (func $_Z18ConvertTobytearrayPKh (param i32)))
 (import "env" "_Z4SizeN3neo5arrayE" (func $_Z4SizeN3neo5arrayE (result i32)))
 (import "env" "_Z5Size29bytearray" (func $_Z5Size29bytearray (result i32)))
 (import "env" "_Z6Equals9neostringPKc" (func $_Z6Equals9neostringPKc (param i32) (result i32)))
 (import "env" "_ZN11NeoContract7toarrayENS_7uint160E" (func $_ZN11NeoContract7toarrayENS_7uint160E))
 (import "env" "_ZN3neo5array4TestEv" (func $_ZN3neo5array4TestEv (result i32)))
 (import "env" "_ZN9bytearray6concatES_" (func $_ZN9bytearray6concatES_))
 (import "env" "_ZN9bytearray6lengthEv" (func $_ZN9bytearray6lengthEv (result i32)))
 (table 0 anyfunc)
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
 (export "_ZN11NeoContract10TestSecondE9neostring" (func $_ZN11NeoContract10TestSecondE9neostring))
 (export "TestMy" (func $TestMy))
 (export "_ZN11NeoContract14GetArrayLengthE9bytearray" (func $_ZN11NeoContract14GetArrayLengthE9bytearray))
 (export "_ZN11NeoContract21ExperimentArrayLengthEv" (func $_ZN11NeoContract21ExperimentArrayLengthEv))
 (export "_ZN11NeoContract16ExperimentConcatEv" (func $_ZN11NeoContract16ExperimentConcatEv))
 (export "_ZN11NeoContract11NothingToDoEv" (func $_ZN11NeoContract11NothingToDoEv))
 (export "_ZN11NeoContract7NeoMainE9neostringN3neo5arrayE" (func $_ZN11NeoContract7NeoMainE9neostringN3neo5arrayE))
 (func $__Size3 (result i32)
  (i32.const 1)
 )
 (func $_ZN11NeoContract10TestSecondE9neostring (result i32)
  (call $_Z6Equals9neostringPKc
   (i32.const 48)
  )
 )
 (func $TestMy (result i32)
  (i32.gt_s
   (i32.add
    (select
     (i32.const 3)
     (i32.const 2)
     (i32.gt_s
      (call $_ZN3neo5array4TestEv)
      (i32.const 0)
     )
    )
    (call $_Z5Size29bytearray)
   )
   (i32.const 0)
  )
 )
 (func $_ZN11NeoContract14GetArrayLengthE9bytearray (result i32)
  (call $_ZN9bytearray6lengthEv)
 )
 (func $_ZN11NeoContract21ExperimentArrayLengthEv (result i32)
  (call $_Z18ConvertTobytearrayPKh
   (i32.const 64)
  )
  (i32.gt_s
   (call $_ZN9bytearray6lengthEv)
   (i32.const 7)
  )
 )
 (func $_ZN11NeoContract16ExperimentConcatEv (result i32)
  (call $_Z18ConvertTobytearrayPKh
   (i32.const 80)
  )
  (call $_Z18ConvertTobytearrayPKh
   (i32.const 96)
  )
  (call $_ZN9bytearray6concatES_)
  (i32.gt_s
   (call $_ZN9bytearray6lengthEv)
   (i32.const 7)
  )
 )
 (func $_ZN11NeoContract11NothingToDoEv (result i32)
  (i32.const 0)
 )
 (func $_ZN11NeoContract7NeoMainE9neostringN3neo5arrayE (result i32)
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (drop
   (call $_ZN11NeoContract21ExperimentArrayLengthEv)
  )
  (drop
   (call $_ZN11NeoContract16ExperimentConcatEv)
  )
  (call $_ZN11NeoContract7toarrayENS_7uint160E)
  (set_local $2
   (select
    (i32.const 30000030)
    (i32.const 50)
    (tee_local $0
     (call $_Z6Equals9neostringPKc
      (i32.const 112)
     )
    )
   )
  )
  (set_local $1
   (select
    (i32.const 30000023)
    (i32.const 30000002)
    (get_local $0)
   )
  )
  (block $label$0
   (br_if $label$0
    (i32.eqz
     (call $_Z6Equals9neostringPKc
      (i32.const 128)
     )
    )
   )
   (return
    (i32.add
     (i32.sub
      (i32.add
       (get_local $1)
       (i32.const 1)
      )
      (get_local $2)
     )
     (call $_Z4SizeN3neo5arrayE)
    )
   )
  )
  (block $label$1
   (br_if $label$1
    (i32.eqz
     (call $_Z6Equals9neostringPKc
      (i32.const 16)
     )
    )
   )
   (return
    (i32.add
     (i32.add
      (i32.add
       (get_local $1)
       (get_local $2)
      )
      (call $_Z4SizeN3neo5arrayE)
     )
     (i32.const -1)
    )
   )
  )
  (call $_Z18ConvertTobytearrayPKh
   (i32.const 144)
  )
  (block $label$2
   (br_if $label$2
    (i32.eqz
     (call $_Z6Equals9neostringPKc
      (i32.const 48)
     )
    )
   )
   (br_if $label$2
    (i32.eqz
     (call $TestMy)
    )
   )
   (return
    (i32.sub
     (i32.add
      (get_local $1)
      (i32.const 99)
     )
     (get_local $2)
    )
   )
  )
  (i32.add
   (select
    (i32.const 7)
    (i32.const -29999952)
    (get_local $0)
   )
   (select
    (i32.const 21)
    (i32.const 20)
    (call $_Z6Equals9neostringPKc
     (i32.const 48)
    )
   )
  )
 )
)
