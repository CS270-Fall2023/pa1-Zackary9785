	.file	"token.c"
	.text
	.section	.rodata
.LC0:
	.string	"Length of substring is: %i\n"
.LC1:
	.string	"found space or null"
	.text
	.globl	getTokens
	.type	getTokens, @function
getTokens:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -168(%rbp)
	movq	%rsi, -176(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, -152(%rbp)
	movl	$800, %edi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-176(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$0, -148(%rbp)
	movl	$0, -144(%rbp)
	movl	$0, -140(%rbp)
	movl	$0, -136(%rbp)
	jmp	.L2
.L9:
	movl	-136(%rbp), %eax
	movslq	%eax, %rdx
	movq	-168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	je	.L3
	addl	$1, -148(%rbp)
	addl	$1, -140(%rbp)
	jmp	.L4
.L3:
	movl	$0, -140(%rbp)
	addl	$1, -144(%rbp)
.L4:
	movl	-136(%rbp), %eax
	movslq	%eax, %rdx
	movq	-168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L5
	movl	-136(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	-168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L6
.L5:
	movl	-136(%rbp), %eax
	movslq	%eax, %rdx
	movq	-168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L7
.L6:
	movl	-136(%rbp), %eax
	movslq	%eax, %rdx
	movq	-168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L8
	subl	$1, -148(%rbp)
.L8:
	movl	-148(%rbp), %eax
	movl	%eax, -132(%rbp)
	movl	-132(%rbp), %eax
	cltq
	addq	$1, %rax
	movq	-176(%rbp), %rdx
	movq	(%rdx), %rbx
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, (%rbx)
	movl	-132(%rbp), %eax
	movslq	%eax, %rdx
	movq	-176(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rax
	movq	-168(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncpy@PLT
	movl	-132(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -148(%rbp)
	addl	$1, -152(%rbp)
.L7:
	addl	$1, -136(%rbp)
.L2:
	movl	-136(%rbp), %eax
	movslq	%eax, %rbx
	movq	-168(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	addq	$1, %rax
	cmpq	%rax, %rbx
	jb	.L9
	movl	-152(%rbp), %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getTokens, .-getTokens
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
