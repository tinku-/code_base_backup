	.file	"gss1.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.globl	tree
	.bss
	.align 32
	.type	tree, @object
	.size	tree, 4000020
tree:
	.zero	4000020
	.globl	arr
	.align 32
	.type	arr, @object
	.size	arr, 4000020
arr:
	.zero	4000020
	.globl	left
	.align 32
	.type	left, @object
	.size	left, 4000020
left:
	.zero	4000020
	.globl	right
	.align 32
	.type	right, @object
	.size	right, 4000020
right:
	.zero	4000020
	.text
	.globl	_Z5buildiii
	.type	_Z5buildiii, @function
_Z5buildiii:
.LFB3536:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.L2
	movl	-24(%rbp), %eax
	cltq
	movl	arr(,%rax,4), %edx
	movl	-20(%rbp), %eax
	cltq
	movl	%edx, tree(,%rax,4)
	jmp	.L1
.L2:
	movl	-24(%rbp), %eax
	movl	-28(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %ecx
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	%ecx, %edi
	call	_Z5buildiii
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %ecx
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %edi
	call	_Z5buildiii
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	cltq
	movl	tree(,%rax,4), %edx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	cltq
	movl	tree(,%rax,4), %eax
	addl	%eax, %edx
	movl	-20(%rbp), %eax
	cltq
	movl	%edx, tree(,%rax,4)
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3536:
	.size	_Z5buildiii, .-_Z5buildiii
	.globl	_Z5queryiiiii
	.type	_Z5queryiiiii, @function
_Z5queryiiiii:
.LFB3537:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L5
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	.L6
.L5:
	movl	$0, %eax
	jmp	.L7
.L6:
	movl	-32(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jg	.L8
	movl	-28(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jg	.L8
	movl	-20(%rbp), %eax
	cltq
	movl	tree(,%rax,4), %eax
	jmp	.L7
.L8:
	movl	-28(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%rbp)
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %edi
	movl	-36(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	call	_Z5queryiiiii
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movl	-36(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z5queryiiiii
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	-8(%rbp), %edx
	addl	%edx, %eax
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3537:
	.size	_Z5queryiiiii, .-_Z5queryiiiii
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d %d"
.LC2:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3538:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	$0, -8(%rbp)
	jmp	.L10
.L11:
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	$arr, %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	addl	$1, -8(%rbp)
.L10:
	movl	-24(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L11
	movl	-24(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	movl	$0, %esi
	movl	$1, %edi
	call	_Z5buildiii
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	leaq	-12(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	scanf
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %eax
	movl	-24(%rbp), %edx
	subl	$1, %edx
	movl	%ecx, %r8d
	movl	%eax, %ecx
	movl	$0, %esi
	movl	$1, %edi
	call	_Z5queryiiiii
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L12:
	movl	-20(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L13
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3538:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB3556:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L15
	cmpl	$65535, -8(%rbp)
	jne	.L15
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3556:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_tree, @function
_GLOBAL__sub_I_tree:
.LFB3557:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3557:
	.size	_GLOBAL__sub_I_tree, .-_GLOBAL__sub_I_tree
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_tree
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
