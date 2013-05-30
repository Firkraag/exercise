	.file	"linked_list.c"
	.text
	.globl	is_empty
	.type	is_empty, @function
is_empty:
.LFB38:
	.cfi_startproc
	movl	4(%esp), %eax
	cmpl	$0, 4(%eax)
	sete	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE38:
	.size	is_empty, .-is_empty
	.globl	is_last
	.type	is_last, @function
is_last:
.LFB39:
	.cfi_startproc
	movl	4(%esp), %eax
	cmpl	$0, 4(%eax)
	sete	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE39:
	.size	is_last, .-is_last
	.globl	find
	.type	find, @function
find:
.LFB40:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	.L4
	cmpl	%edx, (%eax)
	jne	.L8
	rep
	ret
.L7:
	cmpl	%edx, (%eax)
	.p2align 4,,7
	je	.L4
.L8:
	movl	4(%eax), %eax
	testl	%eax, %eax
	.p2align 4,,4
	jne	.L7
.L4:
	.p2align 4,,4
	rep
	ret
	.cfi_endproc
.LFE40:
	.size	find, .-find
	.globl	find_previous
	.type	find_previous, @function
find_previous:
.LFB42:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	8(%esp), %eax
	jmp	.L10
.L12:
	cmpl	%ecx, (%edx)
	je	.L11
	movl	%edx, %eax
.L10:
	movl	4(%eax), %edx
	testl	%edx, %edx
	jne	.L12
.L11:
	.p2align 4,,2
	rep
	ret
	.cfi_endproc
.LFE42:
	.size	find_previous, .-find_previous
	.globl	delete
	.type	delete, @function
delete:
.LFB41:
	.cfi_startproc
	subl	$8, %esp
	.cfi_def_cfa_offset 12
	movl	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	12(%esp), %eax
	movl	%eax, (%esp)
	call	find_previous
	movl	4(%eax), %edx
	testl	%edx, %edx
	je	.L13
	movl	4(%edx), %edx
	movl	%edx, 4(%eax)
.L13:
	addl	$8, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE41:
	.size	delete, .-delete
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Out of space! ! !"
	.text
	.globl	insert
	.type	insert, @function
insert:
.LFB43:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	40(%esp), %ebx
	movl	$8, (%esp)
	call	malloc
	testl	%eax, %eax
	jne	.L17
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	jmp	.L16
.L17:
	movl	4(%ebx), %edx
	movl	%edx, 4(%eax)
	movl	32(%esp), %edx
	movl	%edx, (%eax)
	movl	%eax, 4(%ebx)
.L16:
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE43:
	.size	insert, .-insert
	.globl	kth
	.type	kth, @function
kth:
.LFB44:
	.cfi_startproc
	movl	8(%esp), %edx
	testl	%edx, %edx
	jle	.L23
	movl	4(%esp), %eax
.L22:
	movl	4(%eax), %eax
	subl	$1, %edx
	jne	.L22
	rep
	ret
.L23:
	movl	4(%esp), %eax
	ret
	.cfi_endproc
.LFE44:
	.size	kth, .-kth
	.globl	delete_list
	.type	delete_list, @function
delete_list:
.LFB45:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %edx
	movl	4(%edx), %eax
	movl	$0, 4(%edx)
	testl	%eax, %eax
	je	.L25
.L28:
	movl	4(%eax), %ebx
	movl	%eax, (%esp)
	call	free
	movl	%ebx, %eax
	testl	%ebx, %ebx
	jne	.L28
.L25:
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE45:
	.size	delete_list, .-delete_list
	.ident	"GCC: (Gentoo 4.7.2-r1 p1.5, pie-0.5.5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
