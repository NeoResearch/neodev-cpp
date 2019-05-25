(module
  (type $t0 (func (param i32)))
  (type $t1 (func (result i32)))
  (import "env" "abortStackOverflow" (func $abortStackOverflow (type $t0)))
  (import "env" "__memory_base" (global $env.__memory_base i32))
  (import "env" "__table_base" (global $env.__table_base i32))
  (import "env" "memory" (memory $env.memory 256 256))
  (import "env" "table" (table $env.table 0 0 funcref))
  (func $_main (type $t1) (result i32)
    (local $l0 i32) (local $l1 i32) (local $l2 i32)
    global.get $g2
    local.set $l2
    global.get $g2
    i32.const 16
    i32.add
    global.set $g2
    global.get $g2
    global.get $g3
    i32.ge_s
    if $I0
      i32.const 16
      call $abortStackOverflow
    end
    i32.const 0
    local.set $l0
    local.get $l2
    global.set $g2
    i32.const 10000
    return)
  (global $g2 (mut i32) (i32.const 2080))
  (global $g3 (mut i32) (i32.const 5244960))
  (global $g4 (mut f32) (f32.const 0x0p+0 (;=0;)))
  (export "_main" (func $_main)))
