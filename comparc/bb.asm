.data
	.align 2
	arr: .space 1000 
	n: .asciiz " "		
.text
	main:
		#input arr
		li $v0,5
		syscall
		addi $s2,$v0,0
		
		la $t2,arr
		li $t1,0
		loop:
			beq $t1,$s2,next1
			li $v0,5
			syscall
			addi $t3,$v0,0
			sw $t3,($t2)
			addi $t2,$t2,4
			addi $t1,$t1,1
			j loop
			
		next1:
		#addi $t2,$t2,-8
		add $s0,$t2,$zero
		la $t7,arr
		li $t6,0	
		out:
			ble $s0,$t7,loop2
			la $s1,arr
			in:
				bge $s1,$s0,skipin
				lw $t0,($s1)
				lw $t1,4($s1)
				ble $t0,$t1,skip
				sw $t0,4($s1)
				sw $t1,($s1)
				skip:
				addi $s1,$s1,4
				j in
			skipin:
			addi $s0,$s0,-4
			j out

		loop2:
			beq $t6,$s2,exit1
			addi $t7,$t7,4
			addi $t6,$t6,1
			lw $a0,($t7)
			li $v0,1
			syscall

			la $a0,n
			li $v0,4
			syscall
			j loop2
		exit1:
			li $v0,10
			syscall
			
			
		