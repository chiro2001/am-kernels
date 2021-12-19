.section entry, "ax"
.globl _start
.type _start, @function

_start:
  lui x0, 100
  lui x1, 102
  lui x2, 0x4
  lui x0, 100
  .word 0x6b