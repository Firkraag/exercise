	.file	"ex2-1.c"
	.section	.rodata
	.align 4
.LC0:
	.string	"Maximum value of type signed char is %d\n"
	.align 4
.LC1:
	.string	"Minimum value of type signed char is %d\n"
	.align 4
.LC2:
	.string	"Maximum value of type unsigned char is %u\n"
	.align 4
.LC3:
	.string	"Maximum value of type signed short is %d\n"
	.align 4
.LC4:
	.string	"Minimum value of type signed short is %d\n"
	.align 4
.LC5:
	.string	"Maximum value of type unsigned short is %u\n"
	.align 4
.LC6:
	.string	"Maximum value of type signed int is %d\n"
	.align 4
.LC7:
	.string	"Minimum value of type signed int is %d\n"
	.align 4
.LC8:
	.string	"Maximum value of type unsigned int is %u\n"
	.align 4
.LC9:
	.string	"Maximum value of type signed long is %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	movb	$8, 31(%esp)
	movw	$16, 28(%esp)
	movl	$32, 20(%esp)
	movl	$32, 24(%esp)
	movsbl	31(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	.cfi_offset 3, -12
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	leal	-1(%eax), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movsbl	31(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	movsbl	%al, %edx
	movl	$.LC1, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC2, %eax
	movl	$255, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movswl	28(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	leal	-1(%eax), %edx
	movl	$.LC3, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movswl	28(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	movswl	%ax, %edx
	movl	$.LC4, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC5, %eax
	movl	$65535, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	20(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	leal	-1(%eax), %edx
	movl	$.LC6, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	20(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	$.LC7, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC8, %eax
	movl	$-1, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	24(%esp), %eax
	subl	$1, %eax
	movl	$1, %edx
	movl	%edx, %ebx
	movl	%eax, %ecx
	sall	%cl, %ebx
	movl	%ebx, %eax
	leal	-1(%eax), %edx
	movl	$.LC9, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
