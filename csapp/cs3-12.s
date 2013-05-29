	.file	"cs3-12.c"
	.text
	.globl	store_prod
	.type	store_prod, @function
store_prod:
.LFB22:
	.cfi_startproc
	movl	8(%esp), %eax
	movl	16(%esp), %ecx
	imull	%eax, %ecx
	mull	12(%esp)
	addl	%ecx, %edx
	movl	4(%esp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	ret
	.cfi_endproc
.LFE22:
	.size	store_prod, .-store_prod
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
