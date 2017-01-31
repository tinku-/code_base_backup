.data
	N: .asciiz "input n \n"
	range: .asciiz "range \n"
	space: .asciiz " "
.text
	main:
		la $a0,N
		li $v0,4
		syscall
		li $v0,5
		syscall
		add $t0,$v0,$zero
		la $a0,range
		li $v0,4
		syscall
		li $v0,5
		syscall
		add $t1,$v0,$zero

		li $s0,1
		loop:
			mul $t2,$t0,$s0
			move $a0,$t2
			bge $t2,$t1,exit
			li $v0,1
			syscall
			la $a0,space
			li $v0,4
			syscall
			addi $s0,$s0,1
			#bge $t2,$t1,exit
			j loop
		exit:
			li $v0,10
			syscall

