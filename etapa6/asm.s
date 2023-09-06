## ASM CODE: ##

## PRINT FUNCTIONS: ##
.PRINTINT:
	.string	"%d"
.PRINTSTRING:
	.string	"%s"

.PRINTFLOAT:
	.string	"%f"

## TAC FUNCTION BEGIN: ##
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC MOVE: ##
	movl	0(%rip), %eax
	movl	%eax, a(%rip)

## TAC SUB: ##
	movl d(%rip), %edx
	movl	i(%rip), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%edx, temp_20(%rip)

## TAC MOVE: ##
	movl	temp_20(%rip), %eax
	movl	%eax, d(%rip)

## TAC MOVE: ##
	movl	5(%rip), %eax
	movl	%eax, d(%rip)

## TAC VEC ATT: ##
	movl	55(%rip), %eax
	movl	%eax, 400+v(%rip)

## TAC ADD: ##
	movl	a(%rip), %edx
	movl	d(%rip), %eax
	addl	%edx, %eax
	movl	%eax, temp_18(%rip)

## TAC VEC ACC: ##
	movl	temp_18(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	v(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, temp_19(%rip)

## TAC PRINT INT: ##
	movl	temp_19(%rip), %eax
	movl	%eax, %esi
	leaq	.PRINTINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	d(%rip), %eax
	movl	%eax, %esi
	leaq	.PRINTINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	2(%rip), %eax
	movl	%eax, i(%rip)

## TAC PRINT STRING: ##
	leaq	"Digite um numero: "(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	temp_15(%rip), %eax
	movl	%eax, d(%rip)

## TAC PRINT STRING: ##
	leaq	"Digite mais um numero: "(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC LABEL: ##
label_4:

## TAC LT: ##
	movl	i(%rip), %edx
	movl	10(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, temp_12(%rip)

## TAC JUMP FALSE: ##
	movl temp_12(%rip), %eax
	cmpl $1, %eax
	jne label_3

## TAC MOVE: ##
	movl	temp_14(%rip), %eax
	movl	%eax, i(%rip)

## TAC MOVE: ##
	movl	temp_13(%rip), %eax
	movl	%eax, d(%rip)

## TAC JUMP: ##
	jmp	label_4

## TAC LABEL: ##
label_3:

## TAC PRINT STRING: ##
	leaq	"Incrementado algumas vezes a fica "(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC ADD: ##
	movl	2(%rip), %edx
	movl	x(%rip), %eax
	addl	%edx, %eax
	movl	%eax, temp_8(%rip)

## TAC PRINT INT: ##
	movl	temp_8(%rip), %eax
	movl	%eax, %esi
	leaq	.PRINTINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	a(%rip), %eax
	movl	%eax, %esi
	leaq	.PRINTINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	""(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC EQ: ##
	movl	a(%rip), %edx
	movl	15(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, temp_5(%rip)

## TAC JUMP FALSE: ##
	movl temp_5(%rip), %eax
	cmpl $1, %eax
	jne label_2

## TAC ADD: ##
	movl	a(%rip), %edx
	movl	1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, temp_6(%rip)

## TAC MOVE: ##
	movl	temp_6(%rip), %eax
	movl	%eax, a(%rip)

## TAC PRINT STRING: ##
	leaq	"A era=15"(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC LABEL: ##
label_2:

## TAC EQ: ##
	movl	i(%rip), %edx
	movl	100(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, temp_2(%rip)

## TAC JUMP FALSE: ##
	movl temp_2(%rip), %eax
	cmpl $1, %eax
	jne label_0

## TAC PRINT STRING: ##
	leaq	"Nao tem como isso..."(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC JUMP: ##
	jmp	label_1

## TAC LABEL: ##
label_0:

## TAC PRINT STRING: ##
	leaq	"OK!"(%rip), %rax
	movq	%rax, %rsi
	leaq	.PRINTSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC LABEL: ##
label_1:

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	incn
	.type	incn, @function
incn:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC ADD: ##
	movl	x(%rip), %edx
	movl	n(%rip), %eax
	addl	%edx, %eax
	movl	%eax, temp_0(%rip)

## TAC RETURN: ##
	movl	temp_0(%rip), %eax
	popq	%rbp
	ret

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## DATA SECTION: ##
	.data
temp_13:
	.long	0
temp_8:
	.long	0
"A era=15":
	.string	"A era=15\n"
temp_12:
	.long	0
a:
	.long	65
b:
	.long	0
c:
	.long	120
d:
	.long	100
f:
	.long	2
i:
	.long	1
n:
	.long	0
x:
	.long	0
temp_11:
	.long	0
temp_5:
	.long	0
"Digite mais um numero: ":
	.string	"Digite mais um numero: \n"
temp_10:
	.long	0
temp_2:
	.long	0
temp_9:
	.long	0
"OK!":
	.string	"OK!\n"
temp_6:
	.long	0
temp_3:
	.long	0
temp_0:
	.long	0
temp_19:
	.long	0
"Digite um numero: ":
	.string	"Digite um numero: \n"
temp_18:
	.long	0
temp_7:
	.long	0
temp_17:
	.long	0
"Nao tem como isso...":
	.string	"Nao tem como isso...\n"
"":
	.string	"\n"
temp_20:
	.long	0
temp_4:
	.long	0
temp_16:
	.long	0
temp_15:
	.long	0
temp_1:
	.long	0
temp_14:
	.long	0
"Incrementado algumas vezes a fica ":
	.string	"Incrementado algumas vezes a fica "
v:
	.long	97
	.long	0
	.long	98
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
matrix:
