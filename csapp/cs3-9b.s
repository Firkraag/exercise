	.file	"cs3-9b.c"
	.text
	.globl	arith
	.type	arith, @function
arith:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	xorl	%edx, %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	sarl	$3, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	notl	%eax
	movl	%eax, -8(%ebp)
	movl	16(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	arith, .-arith
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
