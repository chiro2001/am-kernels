.section entry, "ax"
.globl _start
.type _start, @function

_start:
  addi x0, ra, 1
  addi x0, ra, 2
  addi x0, ra, 3
  addi x0, ra, 7
  addi x0, ra, 14
  addi x0, ra, 28
  addi x0, ra, 56
  addi t6, ra, 1
  addi t6, ra, 2
  addi t6, ra, 3
  addi t6, ra, 7
  addi t6, ra, 14
  addi t6, ra, 28
  addi t6, ra, 56
  addi t6, ra, 133
  addi t6, ra, 258
  addi t6, ra, 511
  addi t6, ra, -1
  addi t6, ra, -3
  addi t6, ra, -9
  addi t6, ra, -98
  addi t6, ra, -231
  addi t6, ra, -510
  addi x30, x0, 1
  addi x30, x30, 2
  addi x30, x30, 3
  addi x30, x30, 7
  addi x30, x30, 14
  addi x30, x30, 28
  addi x30, x30, 56
  addi x30, x30, 133
  addi x30, x30, 258
  addi x30, x30, 511
  addi x30, x30, -1
  addi x30, x30, -3
  addi x30, x30, -9
  addi x30, x30, -98
  addi x30, x30, -231
  addi x30, x30, -510
  .word 0x6b