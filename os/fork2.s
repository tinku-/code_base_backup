	.file	"fork2.c"
	.section	.rodata
.LC0:
	.string	"fork"
	.align 8
.LC1:
	.string	"this is a child process and the PID is %d \n"
.LC2:
	.string	"child done"
	.align 8
.LC3:
	.string	"this is a parent process and PID of child id %d\n"
.LC4:
	.string	"parent done"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	fork
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jns	.L2
	movl	$.LC0, %edi
	call	perror
	jmp	.L3
.L2:
	cmpl	$0, -4(%rbp)
	jne	.L4
	call	getpid
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$5, %edi
	call	sleep
	movl	$.LC2, %edi
	call	puts
	jmp	.L3
.L4:
	leaq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wait
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC4, %edi
	call	puts
.L3:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
