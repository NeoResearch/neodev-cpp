(module
  (table $T0 0 anyfunc)
  (memory $0 1)
  (export "memory" (memory $0))
  (export "main" (func $main))
  (type $t0 (func (result i32)))
  (func $main (result i32)
    i32.const 10000))
