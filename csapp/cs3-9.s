	.file	"cs3-9.c"
	.text
	.globl	arith
	.type	arith, @function
arith:
.LFB22:
	.cfi_startproc
	movl	8(%esp), %eax
	xorl	4(%esp), %eax
	sarl	$3, %eax
	notl	%eax
	subl	12(%esp), %eax
	ret
	.cfi_endproc
.LFE22:
	.size	arith, .-arith
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
