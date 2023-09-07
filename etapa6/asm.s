## ASM CODE: ##

## PRINT FUNCTIONS: ##
.LINT:
	.string	"%d"
.LSTRING:
	.string	"%s"
.LCHAR:
	.string	"%c"

## TAC FUNCTION BEGIN: ##
	.globl	.soma
	.type	.soma, @function
.soma:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC ADD: ##
	movl	.a(%rip), %edx
	movl	.b(%rip), %eax
	addl	%edx, %eax
	movl	%eax, .temp_6(%rip)

## TAC RETURN: ##
	movl	.temp_6(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC MUL: ##
	movl	.x(%rip), %edx
	movl	.3(%rip), %eax
	imull	%edx, %eax
	movl	%eax, .temp_4(%rip)

## TAC_DIV: ##
	movl .48(%rip), %eax
	movl	.y(%rip), %ecx
	cltd
	idivl %ecx
	movl	%eax, .temp_3(%rip)

## TAC SUB: ##
	movl .temp_4(%rip), %edx
	movl	.temp_3(%rip), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%edx, .temp_5(%rip)

## TAC PRINT INT: ##
	movl	.temp_5(%rip), %eax
	movl	%eax, %esi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## DATA SECTION: ##
	.data
.1:
	.long	1
.2:
	.long	2
.3:
	.long	3
.a:
	.long	0
.b:
	.long	0
.x:
	.long	1
.y:
	.long	2
.temp_5:
	.long	0
.temp_2:
	.long	0
.temp_6:
	.long	0
.temp_3:
	.long	0
.temp_0:
	.long	0
.temp_4:
	.long	0
.temp_1:
	.long	0
.48:
	.long	48
