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
	movl	%eax, .temp_28(%rip)

## TAC RETURN: ##
	movl	.temp_28(%rip), %eax

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
	leaq	.label_257_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_27(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_27(%rip), %eax
	movl	%eax, .x(%rip)

## TAC PRINT STRING: ##
	leaq	.label_221_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_26(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_26(%rip), %eax
	movl	%eax, .y(%rip)

## TAC PRINT STRING: ##
	leaq	.label_563_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_25(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_25(%rip), %eax
	movl	%eax, .f(%rip)

## TAC PRINT STRING: ##
	leaq	.label_450_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.f(%rip), %eax
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
	movl	.x(%rip), %eax
	movl	%eax, .a(%rip)

## TAC MOVE: ##
	movl	.y(%rip), %eax
	movl	%eax, .b(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
	movl	%eax, .temp_24(%rip)

## TAC MOVE: ##
	movl	.temp_24(%rip), %eax
	movl	%eax, .z(%rip)

## TAC PRINT STRING: ##
	leaq	.label_765_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC MOVE: ##
	movl	.x(%rip), %eax
	movl	%eax, .a(%rip)

## TAC MOVE: ##
	movl	.y(%rip), %eax
	movl	%eax, .b(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
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

## TAC EQ: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_21(%rip)

## TAC JUMP FALSE: ##
	movl .temp_21(%rip), %eax
	cmpl $1, %eax
	jne .label_12

## TAC PRINT STRING: ##
	leaq	.label_797_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_13

## TAC LABEL: ##
.label_12:

## TAC PRINT STRING: ##
	leaq	.label_920_1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_13:

## TAC GE: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setge	%al
	movzbl	%al, %eax
	movl	%eax, .temp_19(%rip)

## TAC JUMP FALSE: ##
	movl .temp_19(%rip), %eax
	cmpl $1, %eax
	jne .label_10

## TAC PRINT STRING: ##
	leaq	.label_681_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_11

## TAC LABEL: ##
.label_10:

## TAC PRINT STRING: ##
	leaq	.label_283_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_11:

## TAC LE: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setle	%al
	movzbl	%al, %eax
	movl	%eax, .temp_17(%rip)

## TAC JUMP FALSE: ##
	movl .temp_17(%rip), %eax
	cmpl $1, %eax
	jne .label_8

## TAC PRINT STRING: ##
	leaq	.label_913_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_9

## TAC LABEL: ##
.label_8:

## TAC PRINT STRING: ##
	leaq	.label_560_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_9:

## TAC GT: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setg	%al
	movzbl	%al, %eax
	movl	%eax, .temp_15(%rip)

## TAC JUMP FALSE: ##
	movl .temp_15(%rip), %eax
	cmpl $1, %eax
	jne .label_6

## TAC PRINT STRING: ##
	leaq	.label_936_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_7

## TAC LABEL: ##
.label_6:

## TAC PRINT STRING: ##
	leaq	.label_717_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_7:

## TAC LT: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, .temp_13(%rip)

## TAC JUMP FALSE: ##
	movl .temp_13(%rip), %eax
	cmpl $1, %eax
	jne .label_4

## TAC PRINT STRING: ##
	leaq	.label_237_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_5

## TAC LABEL: ##
.label_4:

## TAC PRINT STRING: ##
	leaq	.label_411_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_5:

## TAC DIF: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setne	%al
	movzbl	%al, %eax
	movl	%eax, .temp_11(%rip)

## TAC JUMP FALSE: ##
	movl .temp_11(%rip), %eax
	cmpl $1, %eax
	jne .label_2

## TAC PRINT STRING: ##
	leaq	.label_57_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC JUMP: ##
	jmp	.label_3

## TAC LABEL: ##
.label_2:

## TAC PRINT STRING: ##
	leaq	.label_810_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
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

## TAC LABEL: ##
.label_3:

## TAC EQ: ##
	movl	.x(%rip), %edx
	movl	.7(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_9(%rip)

## TAC MOVE: ##
	movl	.temp_9(%rip), %eax
	movl	%eax, .xx(%rip)

## TAC PRINT STRING: ##
	leaq	.label_585_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.xx(%rip), %eax
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

## TAC EQ: ##
	movl	.y(%rip), %edx
	movl	.3(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_8(%rip)

## TAC MOVE: ##
	movl	.temp_8(%rip), %eax
	movl	%eax, .yy(%rip)

## TAC PRINT STRING: ##
	leaq	.label_176_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.yy(%rip), %eax
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

## TAC OR: ##
	movl	.xx(%rip), %eax
	testl	%eax, %eax
	jne	LOR0
	movl	.yy(%rip), %eax
	testl	%eax, %eax
	je	LOR1
	LOR0:
	movl	$1, %eax
	jmp	LOR2
	LOR1:
	movl	$0, %eax
	LOR2:
	movl   %eax, .temp_7(%rip)

## TAC MOVE: ##
	movl	.temp_7(%rip), %eax
	movl	%eax, .xxyy(%rip)

## TAC PRINT STRING: ##
	leaq	.label_186_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.xxyy(%rip), %eax
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

## TAC NOT: ##
	movq	%rsp, %rbp
	movl	.xxyy(%rip), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_6(%rip)

## TAC MOVE: ##
	movl	.temp_6(%rip), %eax
	movl	%eax, .cond(%rip)

## TAC PRINT STRING: ##
	leaq	.label_642_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.cond(%rip), %eax
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

## TAC LABEL: ##
.label_1:

## TAC LT: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, .temp_3(%rip)

## TAC AND: ##
	movl   .temp_3(%rip), %eax
	testl  %eax, %eax
	je     LAND3
	movl   .cond(%rip), %eax
	testl  %eax, %eax
	je     LAND3
	movl   $1, %eax
	jmp    LAND4
	LAND3:
	movl   $0, %eax
	LAND4:
	movl   %eax, .temp_4(%rip)

## TAC JUMP FALSE: ##
	movl .temp_4(%rip), %eax
	cmpl $1, %eax
	jne .label_0

## TAC PRINT STRING: ##
	leaq	.label_921_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.x(%rip), %eax
	movl	%eax, %esi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC ADD: ##
	movl	.x(%rip), %edx
	movl	.1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, .temp_5(%rip)

## TAC MOVE: ##
	movl	.temp_5(%rip), %eax
	movl	%eax, .x(%rip)

## TAC PRINT STRING: ##
	leaq	.label_873_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC PRINT INT: ##
	movl	.x(%rip), %eax
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

## TAC JUMP: ##
	jmp	.label_1

## TAC LABEL: ##
.label_0:

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## DATA SECTION: ##
	.data
.temp_13:
	.long	0
.0:
	.long	0
.1:
	.long	1
.3:
	.long	3
.7:
	.long	7
.label_57_0:
	.string	"x != y"
.temp_8:
	.long	0
.temp_25:
	.long	0
.temp_21:
	.long	0
.temp_12:
	.long	0
.a:
	.long	0
.b:
	.long	0
.d:
	.long	97
.f:
	.long	2
.g:
	.long	75
.x:
	.long	0
.y:
	.long	0
.z:
	.long	0
.temp_11:
	.long	0
.temp_5:
	.long	0
.label_176_0:
	.string	"yy = "
.label_186_0:
	.string	"xx v yy = "
.temp_10:
	.long	0
.label_221_0:
	.string	"Entre com um valor para y:\n"
.label_237_0:
	.string	"x < y"
.temp_2:
	.long	0
.label_257_0:
	.string	"Entre com um valor para x:\n"
.label_283_0:
	.string	"not x >= y"
.temp_26:
	.long	0
.temp_22:
	.long	0
.temp_9:
	.long	0
.label_411_0:
	.string	"not x < y"
.label_450_0:
	.string	"Como inteiro: "
.temp_6:
	.long	0
.cond:
	.long	0
.temp_3:
	.long	0
.label_560_0:
	.string	"not x <= y"
.xx:
	.long	0
.label_563_0:
	.string	"Valor real que vai virar inteiro:\n"
.temp_27:
	.long	0
.temp_23:
	.long	0
.label_585_0:
	.string	"xx = "
.temp_0:
	.long	0
.label_642_0:
	.string	"cond = "
.label_681_0:
	.string	"x >= y"
.temp_19:
	.long	0
.label_717_0:
	.string	"not x > y"
.temp_18:
	.long	0
.label_765_0:
	.string	"soma(x, y) = "
.temp_7:
	.long	0
.label_797_0:
	.string	"x == y"
.temp_17:
	.long	0
.yy:
	.long	0
.xxyy:
	.long	0
.label_810_0:
	.string	"not x != y"
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
.label_873_0:
	.string	" -> "
.label_913_0:
	.string	"x <= y"
.temp_15:
	.long	0
.label_920_1:
	.string	"not x == y"
.label_921_0:
	.string	"inc "
.label_936_0:
	.string	"x > y"
.temp_1:
	.long	0
.temp_14:
	.long	0
.75:
	.long	75
