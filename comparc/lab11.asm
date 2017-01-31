.data
myMsg: .asciiz "the sum is ="

.text 

main:
li $v0,5
syscall
li $a0,0
add $a0,$a0,$v0
li $v0,5
syscall
li $t0,0
add $t0,$a0,$v0

la $a0,myMsg	
li $v0,4
syscall
li $a0,0
add $a0,$a0,$t0

li $v0,1
syscall
li $v0,10 
syscall    