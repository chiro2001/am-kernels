.section .data
.global image, image_end
.p2align 3
image:
.incbin "images/face-400x300.bin"
.incbin "images/projectn.bin"
.incbin "images/litenes.bin"
image_end:
