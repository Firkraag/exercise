	.file	"cs3-8.c"
	.text
	.globl	shift_left2_rightn
	.type	shift_left2_rightn, @function
shift_left2_rightn:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	sall	$2, 8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	sarl	%cl, 8(%ebp)
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	shift_left2_rightn, .-shift_left2_rightn
	.section	.rodata
.LC0:
	.string	"%x\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$4, 4(%esp)
	movl	$-1, (%esp)
	call	shift_left2_rightn
	movl	$.LC0, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
