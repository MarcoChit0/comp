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
	movl	.a.(%rip), %edx
	movl	.b.(%rip), %eax
	addl	%edx, %eax
	movl	%eax, .temp_117(%rip)

## TAC RETURN: ##
	movl	.temp_117(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.subtracao
	.type	.subtracao, @function
.subtracao:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC SUB: ##
	movl .a..(%rip), %edx
	movl	.b..(%rip), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%edx, .temp_116(%rip)

## TAC RETURN: ##
	movl	.temp_116(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.multiplicacao
	.type	.multiplicacao, @function
.multiplicacao:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC MUL: ##
	movl	.a...(%rip), %edx
	movl	.b...(%rip), %eax
	imull	%edx, %eax
	movl	%eax, .temp_115(%rip)

## TAC RETURN: ##
	movl	.temp_115(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.divisao
	.type	.divisao, @function
.divisao:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_DIV: ##
	movl .a....(%rip), %eax
	movl	.b....(%rip), %ecx
	cltd
	idivl %ecx
	movl	%eax, .temp_114(%rip)

## TAC RETURN: ##
	movl	.temp_114(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.testaVetor
	.type	.testaVetor, @function
.testaVetor:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC PRINT STRING: ##
	leaq	.label_505_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_113(%rip)

## TAC PRINT INT: ##
	movl	.temp_113(%rip), %eax
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
	leaq	.label_313_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_111(%rip)

## TAC PRINT INT: ##
	movl	.temp_111(%rip), %eax
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
	leaq	.label_121_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_109(%rip)

## TAC PRINT INT: ##
	movl	.temp_109(%rip), %eax
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
	leaq	.label_926_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_107(%rip)

## TAC PRINT INT: ##
	movl	.temp_107(%rip), %eax
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
	leaq	.label_359_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_104(%rip)

## TAC MOVE: ##
	movl	.temp_104(%rip), %eax
	movl	%eax, .a.(%rip)

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_105(%rip)

## TAC MOVE: ##
	movl	.temp_105(%rip), %eax
	movl	%eax, .b.(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
	movl	%eax, .temp_103(%rip)

## TAC PRINT INT: ##
	movl	.temp_103(%rip), %eax
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

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_94(%rip)

## TAC MOVE: ##
	movl	.temp_94(%rip), %eax
	movl	%eax, .a.(%rip)

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_95(%rip)

## TAC MOVE: ##
	movl	.temp_95(%rip), %eax
	movl	%eax, .b.(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
	movl	%eax, .temp_93(%rip)

## TAC VEC ATT: ##
	movl	.temp_93(%rip), %eax
	movl	%eax, 0+.vector(%rip)

## TAC PRINT STRING: ##
	leaq	.label_390_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_89(%rip)

## TAC MOVE: ##
	movl	.temp_89(%rip), %eax
	movl	%eax, .a..(%rip)

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_90(%rip)

## TAC MOVE: ##
	movl	.temp_90(%rip), %eax
	movl	%eax, .b..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .subtracao
	movl	%eax, .temp_88(%rip)

## TAC PRINT INT: ##
	movl	.temp_88(%rip), %eax
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

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_79(%rip)

## TAC MOVE: ##
	movl	.temp_79(%rip), %eax
	movl	%eax, .a..(%rip)

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_80(%rip)

## TAC MOVE: ##
	movl	.temp_80(%rip), %eax
	movl	%eax, .b..(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .subtracao
	movl	%eax, .temp_78(%rip)

## TAC VEC ATT: ##
	movl	.temp_78(%rip), %eax
	movl	%eax, 4+.vector(%rip)

## TAC PRINT STRING: ##
	leaq	.label_427_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_74(%rip)

## TAC MOVE: ##
	movl	.temp_74(%rip), %eax
	movl	%eax, .a...(%rip)

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_75(%rip)

## TAC MOVE: ##
	movl	.temp_75(%rip), %eax
	movl	%eax, .b...(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .multiplicacao
	movl	%eax, .temp_73(%rip)

## TAC PRINT INT: ##
	movl	.temp_73(%rip), %eax
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

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_64(%rip)

## TAC MOVE: ##
	movl	.temp_64(%rip), %eax
	movl	%eax, .a...(%rip)

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_65(%rip)

## TAC MOVE: ##
	movl	.temp_65(%rip), %eax
	movl	%eax, .b...(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .multiplicacao
	movl	%eax, .temp_63(%rip)

## TAC VEC ATT: ##
	movl	.temp_63(%rip), %eax
	movl	%eax, 8+.vector(%rip)

## TAC PRINT STRING: ##
	leaq	.label_60_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_59(%rip)

## TAC MOVE: ##
	movl	.temp_59(%rip), %eax
	movl	%eax, .a....(%rip)

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_60(%rip)

## TAC MOVE: ##
	movl	.temp_60(%rip), %eax
	movl	%eax, .b....(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .divisao
	movl	%eax, .temp_58(%rip)

## TAC PRINT INT: ##
	movl	.temp_58(%rip), %eax
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

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_49(%rip)

## TAC MOVE: ##
	movl	.temp_49(%rip), %eax
	movl	%eax, .a....(%rip)

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_50(%rip)

## TAC MOVE: ##
	movl	.temp_50(%rip), %eax
	movl	%eax, .b....(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .divisao
	movl	%eax, .temp_48(%rip)

## TAC VEC ATT: ##
	movl	.temp_48(%rip), %eax
	movl	%eax, 12+.vector(%rip)

## TAC PRINT STRING: ##
	leaq	.label_505_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	0+.vector(%rip), %eax
	movl	%eax, .temp_45(%rip)

## TAC PRINT INT: ##
	movl	.temp_45(%rip), %eax
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
	leaq	.label_313_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	4+.vector(%rip), %eax
	movl	%eax, .temp_43(%rip)

## TAC PRINT INT: ##
	movl	.temp_43(%rip), %eax
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
	leaq	.label_121_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	8+.vector(%rip), %eax
	movl	%eax, .temp_41(%rip)

## TAC PRINT INT: ##
	movl	.temp_41(%rip), %eax
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
	leaq	.label_926_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_39(%rip)

## TAC PRINT INT: ##
	movl	.temp_39(%rip), %eax
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

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.recebeEntradaETestaSoma
	.type	.recebeEntradaETestaSoma, @function
.recebeEntradaETestaSoma:
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
	leaq	.temp_37(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_37(%rip), %eax
	movl	%eax, .x(%rip)

## TAC PRINT STRING: ##
	leaq	.label_221_1(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_36(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_36(%rip), %eax
	movl	%eax, .y(%rip)

## TAC PRINT STRING: ##
	leaq	.label_563_0(%rip), %rax
	movq	%rax, %rsi
	leaq	.LSTRING(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT

## TAC READ: ##
	leaq	.temp_35(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC MOVE: ##
	movl	.temp_35(%rip), %eax
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
	movl	%eax, .a.(%rip)

## TAC MOVE: ##
	movl	.y(%rip), %eax
	movl	%eax, .b.(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
	movl	%eax, .temp_34(%rip)

## TAC MOVE: ##
	movl	.temp_34(%rip), %eax
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
	movl	%eax, .a.(%rip)

## TAC MOVE: ##
	movl	.y(%rip), %eax
	movl	%eax, .b.(%rip)

## TAC CALL: ##
	movl $0, %eax
	call .soma
	movl	%eax, .temp_33(%rip)

## TAC PRINT INT: ##
	movl	.temp_33(%rip), %eax
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

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.comparaXeY
	.type	.comparaXeY, @function
.comparaXeY:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC EQ: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_31(%rip)

## TAC JUMP FALSE: ##
	movl .temp_31(%rip), %eax
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
	movl	%eax, .temp_29(%rip)

## TAC JUMP FALSE: ##
	movl .temp_29(%rip), %eax
	cmpl $1, %eax
	jne .label_10

## TAC PRINT STRING: ##
	leaq	.label_681_1(%rip), %rax
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
	movl	%eax, .temp_27(%rip)

## TAC JUMP FALSE: ##
	movl .temp_27(%rip), %eax
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
	movl	%eax, .temp_25(%rip)

## TAC JUMP FALSE: ##
	movl .temp_25(%rip), %eax
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
	leaq	.label_717_1(%rip), %rax
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
	movl	%eax, .temp_23(%rip)

## TAC JUMP FALSE: ##
	movl .temp_23(%rip), %eax
	cmpl $1, %eax
	jne .label_4

## TAC PRINT STRING: ##
	leaq	.label_237_1(%rip), %rax
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
	movl	%eax, .temp_21(%rip)

## TAC JUMP FALSE: ##
	movl .temp_21(%rip), %eax
	cmpl $1, %eax
	jne .label_2

## TAC PRINT STRING: ##
	leaq	.label_57_2(%rip), %rax
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

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.testeLoop
	.type	.testeLoop, @function
.testeLoop:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC LABEL: ##
.label_1:

## TAC LT: ##
	movl	.x(%rip), %edx
	movl	.y(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, .temp_17(%rip)

## TAC EQ: ##
	movl	.x(%rip), %edx
	movl	.7(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_14(%rip)

## TAC EQ: ##
	movl	.y(%rip), %edx
	movl	.5(%rip), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_13(%rip)

## TAC OR: ##
	movl	.temp_14(%rip), %eax
	testl	%eax, %eax
	jne	LOR0
	movl	.temp_13(%rip), %eax
	testl	%eax, %eax
	je	LOR1
	LOR0:
	movl	$1, %eax
	jmp	LOR2
	LOR1:
	movl	$0, %eax
	LOR2:
	movl   %eax, .temp_15(%rip)

## TAC NOT: ##
	movq	%rsp, %rbp
	movl	.temp_15(%rip), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, .temp_16(%rip)

## TAC AND: ##
	movl   .temp_17(%rip), %eax
	testl  %eax, %eax
	je     LAND3
	movl   .temp_16(%rip), %eax
	testl  %eax, %eax
	je     LAND3
	movl   $1, %eax
	jmp    LAND4
	LAND3:
	movl   $0, %eax
	LAND4:
	movl   %eax, .temp_18(%rip)

## TAC JUMP FALSE: ##
	movl .temp_18(%rip), %eax
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
	movl	%eax, .temp_19(%rip)

## TAC MOVE: ##
	movl	.temp_19(%rip), %eax
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

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	.divisaoImpossivel
	.type	.divisaoImpossivel, @function
.divisaoImpossivel:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_DIV: ##
	movl .numeradorDivisaoImpossivel(%rip), %eax
	movl	.0(%rip), %ecx
	cltd
	idivl %ecx
	movl	%eax, .temp_5(%rip)

## TAC RETURN: ##
	movl	.temp_5(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## TAC FUNCTION BEGIN: ##
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_4(%rip)

## TAC PRINT INT: ##
	movl	.temp_4(%rip), %eax
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

## TAC READ: ##
	leaq	.temp_2(%rip), %rax
	movq	%rax, %rsi
	leaq	.LINT(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT

## TAC VEC ATT: ##
	movl	.temp_2(%rip), %eax
	movl	%eax, 12+.vector(%rip)

## TAC VEC ACC: ##
	movl	12+.vector(%rip), %eax
	movl	%eax, .temp_1(%rip)

## TAC PRINT INT: ##
	movl	.temp_1(%rip), %eax
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

## TAC RETURN: ##
	movl	.0(%rip), %eax

## TAC FUNCTION END: ##
	popq	%rbp
	ret

## DATA SECTION: ##
	.data
.temp_100:
	.long	0
.temp_70:
	.long	0
.temp_31:
	.long	0
.temp_13:
	.long	0
.a..:
	.long	0
.temp_85:
	.long	0
.temp_58:
	.long	0
.0:
	.long	0
.1:
	.long	1
.2:
	.long	2
.3:
	.long	3
.4:
	.long	4
.5:
	.long	5
.7:
	.long	7
.temp_105:
	.long	0
.temp_92:
	.long	0
.label_57_2:
	.string	"x != y"
.label_60_0:
	.string	"vector[3] = divisao(vector[3], vector[0]): "
.temp_29:
	.long	0
.temp_52:
	.long	0
.temp_8:
	.long	0
.temp_25:
	.long	0
.temp_21:
	.long	0
.temp_12:
	.long	0
.d:
	.long	97
.f:
	.long	2
.g:
	.long	75
.temp_74:
	.long	0
.temp_47:
	.long	0
.temp_40:
	.long	0
.temp_86:
	.long	0
.temp_68:
	.long	0
.x:
	.long	0
.label_121_0:
	.string	"vector[2]: "
.y:
	.long	0
.z:
	.long	0
.temp_116:
	.long	0
.temp_33:
	.long	0
.temp_11:
	.long	0
.temp_5:
	.long	0
.b..:
	.long	0
.temp_66:
	.long	0
.temp_87:
	.long	0
.temp_78:
	.long	0
.temp_95:
	.long	0
.temp_59:
	.long	0
.temp_10:
	.long	0
.temp_110:
	.long	0
.label_221_1:
	.string	"Entre com um valor para y:\n"
.temp_101:
	.long	0
.temp_53:
	.long	0
.temp_35:
	.long	0
.label_237_1:
	.string	"x < y"
.temp_2:
	.long	0
.temp_64:
	.long	0
.temp_46:
	.long	0
.label_257_0:
	.string	"Entre com um valor para x:\n"
.temp_106:
	.long	0
.temp_88:
	.long	0
.temp_117:
	.long	0
.label_283_0:
	.string	"not x >= y"
.temp_90:
	.long	0
.label_313_0:
	.string	"vector[1]: "
.temp_62:
	.long	0
.temp_26:
	.long	0
.temp_73:
	.long	0
.temp_22:
	.long	0
.temp_37:
	.long	0
.temp_98:
	.long	0
.temp_89:
	.long	0
.label_359_0:
	.string	"vector[0] = soma(vector[0], vector[1]): "
.temp_111:
	.long	0
.temp_9:
	.long	0
.temp_60:
	.long	0
.label_390_0:
	.string	"vector[1] = subtracao(vector[1], vector[2]): "
.temp_54:
	.long	0
.temp_45:
	.long	0
.10:
	.long	10
.label_411_0:
	.string	"not x < y"
.temp_77:
	.long	0
.label_427_0:
	.string	"vector[2] = multiplicacao(vector[2], vector[3]): "
.b...:
	.long	0
.temp_102:
	.long	0
.temp_93:
	.long	0
.temp_39:
	.long	0
.label_450_0:
	.string	"Como inteiro: "
.temp_6:
	.long	0
.temp_107:
	.long	0
.temp_30:
	.long	0
.label_505_0:
	.string	"vector[0]: "
.a.:
	.long	0
.temp_112:
	.long	0
.cond:
	.long	0
.temp_44:
	.long	0
.temp_3:
	.long	0
.temp_55:
	.long	0
.label_560_0:
	.string	"not x <= y"
.xx:
	.long	0
.label_563_0:
	.string	"Valor real que vai virar inteiro:\n"
.temp_72:
	.long	0
.b.:
	.long	0
.temp_27:
	.long	0
.temp_96:
	.long	0
.temp_32:
	.long	0
.temp_23:
	.long	0
.temp_69:
	.long	0
.temp_0:
	.long	0
.temp_103:
	.long	0
.temp_76:
	.long	0
.temp_67:
	.long	0
.temp_80:
	.long	0
.temp_113:
	.long	0
.temp_91:
	.long	0
.temp_108:
	.long	0
.label_681_1:
	.string	"x >= y"
.temp_19:
	.long	0
.temp_43:
	.long	0
.temp_34:
	.long	0
.temp_65:
	.long	0
.label_717_1:
	.string	"not x > y"
.temp_56:
	.long	0
.temp_99:
	.long	0
.temp_81:
	.long	0
.temp_18:
	.long	0
.b....:
	.long	0
.temp_50:
	.long	0
.label_765_0:
	.string	"soma(x, y) = "
.temp_7:
	.long	0
.temp_63:
	.long	0
.temp_36:
	.long	0
.temp_71:
	.long	0
.label_797_0:
	.string	"x == y"
.a...:
	.long	0
.temp_17:
	.long	0
.yy:
	.long	0
.xxyy:
	.long	0
.temp_82:
	.long	0
.label_810_0:
	.string	"not x != y"
.temp_28:
	.long	0
.a....:
	.long	0
.temp_94:
	.long	0
.label_820_0:
	.string	"\n"
.temp_114:
	.long	0
.temp_49:
	.long	0
.temp_42:
	.long	0
.temp_24:
	.long	0
.temp_20:
	.long	0
.temp_104:
	.long	0
.temp_61:
	.long	0
.temp_4:
	.long	0
.temp_16:
	.long	0
.label_873_0:
	.string	" -> "
.temp_75:
	.long	0
.temp_57:
	.long	0
.temp_83:
	.long	0
.temp_109:
	.long	0
.temp_38:
	.long	0
.temp_51:
	.long	0
.label_913_0:
	.string	"x <= y"
.temp_15:
	.long	0
.label_920_1:
	.string	"not x == y"
.label_921_0:
	.string	"inc "
.label_926_0:
	.string	"vector[3]: "
.label_936_0:
	.string	"x > y"
.temp_1:
	.long	0
.numeradorDivisaoImpossivel:
	.long	0
.temp_97:
	.long	0
.temp_84:
	.long	0
.temp_79:
	.long	0
.temp_48:
	.long	0
.temp_41:
	.long	0
.temp_115:
	.long	0
.temp_14:
	.long	0
.var:
	.long	120
.75:
	.long	75
.veeeetor:
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
.vector:
	.long	97
	.long	98
	.long	99
	.long	100
