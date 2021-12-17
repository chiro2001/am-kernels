.section entry, "ax"
.globl _start
.type _start, @function

_start:
  addi t0, zero, 10
  addi t1, zero, 23
  addi t2, zero, 43
  addi t3, zero, -11
  add t0, t0, t1
  add t2, t0, t1
  add zero, t0, t1
  add t2, t2, t1
  add t3, t3, t3
  add t3, t3, t3
  add t3, t3, t3
  .word 0x6b