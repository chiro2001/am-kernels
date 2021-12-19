.section entry, "ax"
.globl _start
.type _start, @function

_start:
      addi x30, x30, 0
      jal x31, m1
m2:   addi x30, x30, 2
      jal x2, mx
m1:   addi x30, x30, 1
      jal x1, m2
mx:   .word 0x6b
