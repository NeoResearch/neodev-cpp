(module
 (type $FUNCSIG$i (func (result i32)))
 (type $FUNCSIG$ii (func (param i32) (result i32)))
 (type $FUNCSIG$vii (func (param i32 i32)))
 (type $FUNCSIG$vi (func (param i32)))
 (import "env" "_ZN6neodev6vmtype5Array2atEi" (func $_ZN6neodev6vmtype5Array2atEi (param i32 i32)))
 (import "env" "_ZN6neodev6vmtype9ByteArray2atEi" (func $_ZN6neodev6vmtype9ByteArray2atEi (param i32) (result i32)))
 (import "env" "_ZN6neodev6vmtype9ByteArray3setEih" (func $_ZN6neodev6vmtype9ByteArray3setEih (param i32 i32)))
 (import "env" "_ZN6neodev6vmtype9ByteArray6lengthEv" (func $_ZN6neodev6vmtype9ByteArray6lengthEv (result i32)))
 (import "env" "_ZN6neodev6vmtype9StackItem11asByteArrayEv" (func $_ZN6neodev6vmtype9StackItem11asByteArrayEv (param i32)))
 (import "env" "_ZN6neodev6vmtype9StackItem5asIntEv" (func $_ZN6neodev6vmtype9StackItem5asIntEv (param i32) (result i32)))
 (import "env" "_ZN6neodev7abitype6String6lengthEv" (func $_ZN6neodev7abitype6String6lengthEv (param i32) (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 16) "oi\00")
 (data (i32.const 20) "\10\00\00\00")
 (data (i32.const 32) "test\00")
 (data (i32.const 40) " \00\00\00")
 (export "memory" (memory $0))
 (export "_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE" (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE))
 (export "_ZN11NeoContract11NothingToDoEv" (func $_ZN11NeoContract11NothingToDoEv))
 (export "_ZN11NeoContract4mainEN6neodev7abitype6StringENS0_6vmtype5ArrayE" (func $_ZN11NeoContract4mainEN6neodev7abitype6StringENS0_6vmtype5ArrayE))
 (export "main" (func $main))
 (func $_Z14GetArrayLengthN6neodev6vmtype9ByteArrayE (result i32)
  (select
   (i32.const 10)
   (i32.const 30)
   (i32.gt_s
    (call $_ZN6neodev6vmtype9ByteArray6lengthEv)
    (i32.const 0)
   )
  )
 )
 (func $_ZN11NeoContract11NothingToDoEv (result i32)
  (i32.const 0)
 )
 (func $_ZN11NeoContract4mainEN6neodev7abitype6StringENS0_6vmtype5ArrayE (result i32)
  (local $0 i32)
  (local $1 i32)
  (local $2 i32)
  (local $3 i32)
  (local $4 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $4
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 32)
    )
   )
  )
  (set_local $0
   (call $_ZN6neodev7abitype6String6lengthEv
    (i32.add
     (get_local $4)
     (i32.const 24)
    )
   )
  )
  (call $_ZN6neodev6vmtype5Array2atEi
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
   (i32.const 0)
  )
  (call $_ZN6neodev6vmtype9StackItem11asByteArrayEv
   (i32.add
    (get_local $4)
    (i32.const 8)
   )
  )
  (call $_ZN6neodev6vmtype9ByteArray3setEih
   (i32.const 5)
   (i32.const 1)
  )
  (call $_ZN6neodev6vmtype5Array2atEi
   (i32.add
    (get_local $4)
    (i32.const 16)
   )
   (i32.const 1)
  )
  (set_local $1
   (call $_ZN6neodev6vmtype9StackItem5asIntEv
    (i32.add
     (get_local $4)
     (i32.const 8)
    )
   )
  )
  (set_local $2
   (call $_ZN6neodev6vmtype9ByteArray2atEi
    (i32.const 5)
   )
  )
  (set_local $3
   (call $_ZN6neodev6vmtype9StackItem5asIntEv
    (get_local $4)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $4)
    (i32.const 32)
   )
  )
  (i32.add
   (get_local $3)
   (i32.add
    (get_local $2)
    (i32.add
     (get_local $1)
     (select
      (i32.const 11)
      (i32.const 10)
      (i32.gt_s
       (get_local $0)
       (i32.const 0)
      )
     )
    )
   )
  )
 )
 (func $main (result i32)
  (i32.const 1)
 )
)