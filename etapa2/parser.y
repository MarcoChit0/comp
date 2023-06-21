%{
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(char *);
%}

%token KW_CHAR           
%token KW_INT            
%token KW_REAL           
%token KW_BOOL           
%token KW_IF             
%token KW_THEN           
%token KW_ELSE           
%token KW_LOOP           
%token KW_INPUT          
%token KW_OUTPUT         
%token KW_RETURN         
%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF      
%token TK_IDENTIFIER     
%token LIT_INT           
%token LIT_REAL          
%token LIT_CHAR          
%token LIT_STRING        
%token TOKEN_ERROR 

%left '&' '~' '|'
%left '<' '>' OPERATOR_GE  OPERATOR_LE OPERATOR_EQ OPERATOR_DIF  
%left '+' '-'
%left '*' '/'


%%
programa: listaDeclaracoes
        ;

listaDeclaracoes: declaracao listaDeclaracoes
                |
                ;

declaracao      : comando
                | variavel
                | funcao
                ;

// variável =
//      tipo nome = valor;
//      tipo nomeVetor[tamanhoVetor];
//      tipo nomeVetor[tamanhoVetor] vetor;
variavel: tipo nome '=' literal ';'
        | tipo nome '[' LIT_INT ']' literais ';'
        ;

nome: TK_IDENTIFIER
    ;

literal : LIT_INT       // ex: 1, 2, 3, ...
        | LIT_REAL      // ex: 1.2, 2.3, 3.4, ...
        | LIT_CHAR      // ex: 'a', 'b', 'c', ...
        | LIT_STRING    // ex: "ab", "ac", "ad", ...
        ; 

literais: literal literais
        |
        ;

// tipos = {int, real, bool, char}
tipo: KW_BOOL
    | KW_CHAR
    | KW_INT
    | KW_REAL
    ;

// função = cabeçalho corpo
// cabeçalho = tipo nome (lista de parametros)
// corpo = bloco de comandos 
funcao  : cabecalho bloco
        ;

cabecalho   : tipo nome '(' definicaoListaParametros ')'
            ;

definicaoParametros : tipo nome virgulaDefinicaoParametrosOuVazio
                    ;

virgulaDefinicaoParametrosOuVazio   : ',' definicaoParametros
                                    |
                                    ;

definicaoListaParametros: definicaoParametros
                        |
                        ;

bloco   : '{' comandos '}'
        ;

comandos: comando comandos
        |
        ;

comando : bloco
        | ';'
        | atribuicao
        | controleFluxo
        | outputComando
        | returnComando
        ;

atribuicao  : nome '=' expressao ';'                    // atribuição de variável
            | nome '[' expressao ']' '=' expressao ';'  // atribuição de vetor
            ;

controleFluxo   : KW_IF '(' expressao ')' comando
                | KW_IF '(' expressao ')' comando KW_ELSE comando
                | KW_IF '(' expressao ')' KW_LOOP comando
                ;

outputComando   : KW_OUTPUT outputElementos ';'

returnComando   : KW_RETURN expressao ';'


outputElementos : expressao virgulaOutputElementosOuVazio
                | LIT_STRING virgulaOutputElementosOuVazio
                ;

virgulaOutputElementosOuVazio   : ',' outputElementos
                                |
                                ;

expressao   : expressao '+' expressao
            | expressao '-' expressao
            | expressao '*' expressao
            | expressao '/' expressao
            | expressao '<' expressao
            | expressao '>' expressao
            | expressao '&' expressao
            | expressao '~' expressao
            | expressao '|' expressao
            | expressao OPERATOR_GE   expressao
            | expressao OPERATOR_LE   expressao
            | expressao OPERATOR_EQ   expressao
            | expressao OPERATOR_DIF  expressao
            | '(' expressao ')'
            | nome
            | LIT_INT
            | LIT_CHAR
            | nome '(' passagemListaParametros ')' // function(params)
            | KW_INPUT '(' tipo ')'     // input(type)
            | nome '[' expressao ']' // TODO: acesso a vetor é considerado expressão?
            ;

passagemParametros      : expressao virgulaPassagemParametrosOuVazio
                        ;

virgulaPassagemParametrosOuVazio: ',' passagemParametros
                                |
                                ;

passagemListaParametros : passagemParametros
                        |
                        ;

%%

int yyerror(char *msg){
    fprintf(stderr, "\n\nSyntax error at line %d!!!\n\n", getLineNumber());
    exit(3);
}
