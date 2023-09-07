etapa6: main.o y.tab.o lex.yy.o  hash.o ast.o semantic.o tac.o asm.o
	gcc main.o y.tab.o lex.yy.o  hash.o ast.o semantic.o tac.o asm.o -o etapa6

main.o: main.c
	gcc -c main.c

semantic.o: semantic.c
	gcc -c semantic.c

hash.o: hash.c
	gcc -c hash.c

asm.o: asm.c
	gcc -c asm.c

tac.o: tac.c
	gcc -c tac.c

ast.o: ast.c
	gcc -c ast.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm *.o etapa6 lex.yy.c y.tab.c

run:
	make && ./etapa6 input.in output.out > printoutput.out && gcc asm.s -o compiled.exe && ./compiled.exe