
.data
val1:
	.float 0.001

.text
main:

li $v0, 6
syscall
mov.s $f12, $f0

li $v0,2
syscall

li $v0,10
syscall