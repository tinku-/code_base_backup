.data
msg1: .asciiz "the sum is = "
msg2: .asciiz "
the diffrence is = "

.text 

main:
li $v0,5
syscall
add $a0,$v0,$0
li $v0,5
syscall
add $t0,$a0,$v0
sub $t1,$a0,$v0

la $a0,msg1	
li $v0,4
syscall
li $a0,0
add $a0,$a0,$t0
li $v0,1
syscall

la $a0,msg2	
li $v0,4
syscall
li $a0,0
add $a0,$a0,$t1
li $v0,1
syscall

li $v0,10 
syscall    