	.file	"cs3-17.c"
	.text
	.globl	gotodiff
	.type	gotodiff, @function
gotodiff:
.LFB22:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %ecx
	movl	12(%esp), %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%edx, %ebx
	subl	%ecx, %ebx
	cmpl	%edx, %ecx
	cmovl	%ebx, %eax
.L2:
.L3:
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE22:
	.size	gotodiff, .-gotodiff
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
