.data
	msg1: .asciiz "rev of the arr is \n"
	arr: .space 100
.text
	main:
	la $t5,arr
	li $v0,5  
	syscall

	move $s2,$v0

	li $s0,0
	li $s1,0
	loop:
		beq $s1,$s2,next
		li $v0,5
		syscall
		sw $v0,($t5)
		addi $t5,$t5,4
		addi $s1,$s1,1
		j loop	
	next:
	addi $t5,$t5,-4
	la $t4,arr

	loop2:
		beq $t5,$t4,exit
		lw $t2,($t4)
		lw $t3,($t5)
		sw $t3,($t4)
		sw $t2,($t5)
		addi $t5,$t5,-4
		addi $t4,$t4,4
		j loop2

	exit:
	la $t7,arr
		loop3:
			beq $s0,$s2,exit1
			lw $a0,($t7)
			li $v0,1
			syscall
			addi $s0,$s0,1
			addi $t7,$t7,4
			j loop3
		exit1:
			li $v0,10
			syscall	


