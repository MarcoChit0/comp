## ASM CODE: ##

## PRINT FUNCTIONS: ##
.LINT:
	.string	"%d"
.LSTRING:
	.string	"%s"
.LCHAR:
	.string	"%c"

## TAC FUNCTION BEGIN: ##
	.globl	.teste_
	.type	.teste_, @function
.teste_:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC PRINT STRING: ##
	leaq	.label_425_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC GT: ##
	movl	.t_.(%rip), %edx
	movl	.t_..(%rip), %eax
	cmpl	%eax, %edx
	setg	%al
	movzbl	%al, %eax
	movl	%eax, .temp_39(%rip)

## TAC JUMP FALSE: ##
	movl .temp_39(%rip), %eax
	cmpl $1, %eax
	jne .label_18

## TAC RETURN: ##
	movl	.1(%rip), %eax

## TAC JUMP: ##
	jmp	.label_19

## TAC LABEL: ##
.label_18:

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC LABEL: ##
.label_19:

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.teste__
	.type	.teste__, @function
.teste__:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC PRINT STRING: ##
	leaq	.label_395_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC LT: ##
	movl	.t__.(%rip), %edx
	movl	.t__..(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, .temp_37(%rip)

## TAC JUMP FALSE: ##
	movl .temp_37(%rip), %eax
	cmpl $1, %eax
	jne .label_16

## TAC RETURN: ##
	movl	.1(%rip), %eax

## TAC JUMP: ##
	jmp	.label_17

## TAC LABEL: ##
.label_16:

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC LABEL: ##
.label_17:

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.teste___
	.type	.teste___, @function
.teste___:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC PRINT STRING: ##
	leaq	.label_365_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC EQ: ##
	movl	.t___.(%rip), %edx
	movl	.t___..(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_35(%rip)

## TAC JUMP FALSE: ##
	movl .temp_35(%rip), %eax
	cmpl $1, %eax
	jne .label_14

## TAC RETURN: ##
	movl	.1(%rip), %eax

## TAC JUMP: ##
	jmp	.label_15

## TAC LABEL: ##
.label_14:

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC LABEL: ##
.label_15:

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC PRINT STRING: ##
	leaq	.label_88_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_33(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_33(%rip), %eax
	movl	%eax, .a(%rip)

## TAC PRINT STRING: ##
	leaq	.label_52_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_32(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_32(%rip), %eax
	movl	%eax, .b(%rip)

## TAC PRINT STRING: ##
	leaq	.label_16_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_31(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_31(%rip), %eax
	movl	%eax, .c(%rip)

## TAC PRINT STRING: ##
	leaq	.label_977_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_30(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_30(%rip), %eax
	movl	%eax, .d(%rip)

## TAC PRINT STRING: ##
	leaq	.label_941_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_29(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_29(%rip), %eax
	movl	%eax, .e(%rip)

## TAC PRINT STRING: ##
	leaq	.label_905_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_28(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_28(%rip), %eax
	movl	%eax, .f(%rip)

## TAC PRINT STRING: ##
	leaq	.label_130_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	.a(%rip), %eax
	movl	%eax, .t_.(%rip)

## TAC MOVE: ##
	movl	.b(%rip), %eax
	movl	%eax, .t_..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste_
	movl	%eax, .temp_27(%rip)

## TAC PRINT INT: ##
	movl	.temp_27(%rip), %eax
	movl	%eax, %esi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	.label_820_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	.label_938_1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	.c(%rip), %eax
	movl	%eax, .t__.(%rip)

## TAC MOVE: ##
	movl	.d(%rip), %eax
	movl	%eax, .t__..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste__
	movl	%eax, .temp_25(%rip)

## TAC PRINT INT: ##
	movl	.temp_25(%rip), %eax
	movl	%eax, %esi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	.label_820_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	.label_749_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	.e(%rip), %eax
	movl	%eax, .t___.(%rip)

## TAC MOVE: ##
	movl	.f(%rip), %eax
	movl	%eax, .t___..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste___
	movl	%eax, .temp_23(%rip)

## TAC PRINT INT: ##
	movl	.temp_23(%rip), %eax
	movl	%eax, %esi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT STRING: ##
	leaq	.label_820_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	.a(%rip), %eax
	movl	%eax, .t_.(%rip)

## TAC MOVE: ##
	movl	.b(%rip), %eax
	movl	%eax, .t_..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste_
	movl	%eax, .temp_18(%rip)

## TAC EQ: ##
	movl	.temp_18(%rip), %edx
	movl	.1(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_19(%rip)

## TAC JUMP FALSE: ##
	movl .temp_19(%rip), %eax
	cmpl $1, %eax
	jne .label_10

## TAC MOVE: ##
	movl	.c(%rip), %eax
	movl	%eax, .t__.(%rip)

## TAC MOVE: ##
	movl	.d(%rip), %eax
	movl	%eax, .t__..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste__
	movl	%eax, .temp_13(%rip)

## TAC EQ: ##
	movl	.temp_13(%rip), %edx
	movl	.1(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_14(%rip)

## TAC NOT: ##
	movq	%rsp, %rbp
	movl	.temp_14(%rip), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_16(%rip)

## TAC JUMP FALSE: ##
	movl .temp_16(%rip), %eax
	cmpl $1, %eax
	jne .label_8

## TAC MOVE: ##
	movl	.e(%rip), %eax
	movl	%eax, .t___.(%rip)

## TAC MOVE: ##
	movl	.f(%rip), %eax
	movl	%eax, .t___..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .teste___
	movl	%eax, .temp_11(%rip)

## TAC EQ: ##
	movl	.temp_11(%rip), %edx
	movl	.1(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_12(%rip)

## TAC JUMP FALSE: ##
	movl .temp_12(%rip), %eax
	cmpl $1, %eax
	jne .label_7

## TAC JUMP: ##
	jmp	.label_8

## TAC LABEL: ##
.label_7:

## TAC SET FALSE: ##
	movl   $0, %eax
	movl   %eax, .temp_15(%rip)

## TAC JUMP: ##
	jmp	.label_9

## TAC LABEL: ##
.label_8:

## TAC SET TRUE: ##
	movl   $1, %eax
	movl   %eax, .temp_15(%rip)

## TAC JUMP: ##
	jmp	.label_9

## TAC LABEL: ##
.label_9:

## TAC MOVE: ##
	movl	.temp_15(%rip), %eax
	movl	%eax, .temp_17(%rip)

## TAC JUMP FALSE: ##
	movl .temp_17(%rip), %eax
	cmpl $1, %eax
	jne .label_10

## TAC JUMP: ##
	jmp	.label_11

## TAC LABEL: ##
.label_10:

## TAC SET FALSE: ##
	movl   $0, %eax
	movl   %eax, .temp_20(%rip)

## TAC JUMP: ##
	jmp	.label_12

## TAC LABEL: ##
.label_11:

## TAC SET TRUE: ##
	movl   $1, %eax
	movl   %eax, .temp_20(%rip)

## TAC JUMP: ##
	jmp	.label_12

## TAC LABEL: ##
.label_12:

## TAC MOVE: ##
	movl	.temp_20(%rip), %eax
	movl	%eax, .temp_21(%rip)

## TAC JUMP FALSE: ##
	movl .temp_21(%rip), %eax
	cmpl $1, %eax
	jne .label_6

## TAC PRINT STRING: ##
	leaq	.label_856_1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC JUMP: ##
	jmp	.label_13

## TAC LABEL: ##
.label_6:

## TAC PRINT STRING: ##
	leaq	.label_314_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC LABEL: ##
.label_13:

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## DATA SECTION: ##
	.data
.label_16_0:
	.string	"Entre com um valor para c:\n"
.temp_31:
	.long	0
.temp_13:
	.long	0
.0:
	.long	0
.1:
	.long	1
.label_52_0:
	.string	"Entre com um valor para b:\n"
.temp_29:
	.long	0
.temp_8:
	.long	0
.temp_25:
	.long	0
.label_88_0:
	.string	"Entre com um valor para a:\n"
.temp_21:
	.long	0
.temp_12:
	.long	0
.a:
	.long	0
.b:
	.long	0
.c:
	.long	0
.d:
	.long	0
.e:
	.long	0
.f:
	.long	0
.label_130_0:
	.string	"teste1: "
.temp_33:
	.long	0
.t__.:
	.long	0
.temp_11:
	.long	0
.temp_5:
	.long	0
.temp_10:
	.long	0
.temp_35:
	.long	0
.temp_2:
	.long	0
.t__..:
	.long	0
.t_..:
	.long	0
.label_314_0:
	.string	"FALSE\n"
.temp_26:
	.long	0
.temp_22:
	.long	0
.temp_37:
	.long	0
.label_365_0:
	.string	"teste 3\n"
.temp_9:
	.long	0
.label_395_0:
	.string	"teste 2\n"
.label_425_0:
	.string	"teste 1\n"
.temp_39:
	.long	0
.temp_6:
	.long	0
.temp_30:
	.long	0
.temp_3:
	.long	0
.temp_27:
	.long	0
.temp_32:
	.long	0
.temp_23:
	.long	0
.temp_0:
	.long	0
.temp_19:
	.long	0
.temp_34:
	.long	0
.temp_18:
	.long	0
.label_749_0:
	.string	"teste3: "
.temp_7:
	.long	0
.temp_36:
	.long	0
.temp_17:
	.long	0
.temp_28:
	.long	0
.label_820_0:
	.string	"\n"
.temp_24:
	.long	0
.temp_20:
	.long	0
.temp_4:
	.long	0
.temp_16:
	.long	0
.label_856_1:
	.string	"TRUE\n"
.t_.:
	.long	0
.temp_38:
	.long	0
.t___..:
	.long	0
.label_905_0:
	.string	"Entre com um valor para f:\n"
.t___.:
	.long	0
.temp_15:
	.long	0
.temp_1:
	.long	0
.label_938_1:
	.string	"teste2: "
.label_941_0:
	.string	"Entre com um valor para e:\n"
.temp_14:
	.long	0
.label_977_0:
	.string	"Entre com um valor para d:\n"
