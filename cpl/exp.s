	.file	"exp.c"
	.text
	.globl	strlen
	.type	strlen, @function
strlen:
.LFB22:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$0, %eax
	cmpb	$0, (%edx)
	je	.L2
.L3:
	addl	$1, %eax
	cmpb	$0, (%edx,%eax)
	jne	.L3
.L2:
	rep
	ret
	.cfi_endproc
.LFE22:
	.size	strlen, .-strlen
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$12, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
