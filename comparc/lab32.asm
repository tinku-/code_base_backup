.data
msg1: .asciiz "\n"
w1: .word 712
w2: .word 33
.text
main:
lw $s1,w1
lw $s2,w2

mul $a0,$s1,$s2
li $v0,1
syscall

la $a0,msg1
li $v0,4
syscall

mtc1 $s1,$f2
cvt.s.w $f2,$f2
mtc1 $s2,$f4
cvt.s.w $f4,$f4
mul.s $f12,$f2,$f4
li $v0,2
syscall

la $a0,msg1
li $v0,4
syscall

cvt.w.s $f12,$f12
mfc1 $a0,$f12
li $v0,1
syscall

li $v0,10
syscall
