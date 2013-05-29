	.file	"cs3-16.c"
	.text
	.globl	cond
	.type	cond, @function
cond:
.LFB22:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	testl	%eax, %eax
	je	.L1
	testl	%edx, %edx
	jle	.L1
	addl	%edx, (%eax)
.L2:
.L1:
	rep
	ret
	.cfi_endproc
.LFE22:
	.size	cond, .-cond
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
