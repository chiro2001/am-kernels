.section entry, "ax"
.globl _start
.type _start, @function

_start:
  addi x1, zero, 0x1
  slli x1, x1, 31
  addi x1, x1, 0x4
  sw x1, 0(x1)
	lw x1, 0(x1)
	addi	x10, zero, 0
  .word 0x6b
