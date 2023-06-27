%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"
    int yyerror(char *);
    int yylex();
%}

%union
{
        HashNode* symbol;
        AST* ast;
}



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
%token<symbol> TK_IDENTIFIER     
%token<symbol> LIT_INT           
%token<symbol> LIT_REAL          
%token<symbol> LIT_CHAR          
%token<symbol> LIT_STRING        
%token TOKEN_ERROR 

%type<ast> expressao
%type<ast> passagemParametros
%type<ast> virgulaPassagemParametrosOuVazio
%type<ast> passagemListaParametros
%type<ast> literais
%type<ast> literal


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

declaracao      : variavel
                | funcao
                ;

// variável =
//      tipo TK_IDENTIFIER = valor;
//      tipo nomeVetor[tamanhoVetor];
//      tipo nomeVetor[tamanhoVetor] vetor;
variavel: tipo TK_IDENTIFIER '=' literal ';'
        | tipo TK_IDENTIFIER '[' LIT_INT ']' literais ';'
        ;

literal : LIT_INT       {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
        | LIT_REAL      {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
        | LIT_CHAR      {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
        | LIT_STRING    {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
        ; 

literais: literal literais      {$$ = astCreate(LITERAIS, NULL, $1, $2);}
        |                       {$$ = NULL;}
        ;

// tipos = {int, real, bool, char}
tipo: KW_BOOL
    | KW_CHAR
    | KW_INT
    | KW_REAL
    ;

// função = cabeçalho corpo
// cabeçalho = tipo TK_IDENTIFIER (lista de parametros)
// corpo = bloco de comandos 
funcao  : cabecalho bloco
        ;

cabecalho   : tipo TK_IDENTIFIER '(' definicaoListaParametros ')'
            ;

definicaoParametros : tipo TK_IDENTIFIER virgulaDefinicaoParametrosOuVazio
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

atribuicao  : TK_IDENTIFIER '=' expressao ';' {astPrint($3, 0);}                  // atribuição de variável
            | TK_IDENTIFIER '[' expressao ']' '=' expressao ';'  // atribuição de vetor
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

expressao   : expressao '+' expressao {$$ = astCreate(ADD, NULL, $1, $3);}
            | expressao '-' expressao {$$ = astCreate(SUB, NULL, $1, $3);}
            | expressao '*' expressao {$$ = astCreate(MUL, NULL, $1, $3);}
            | expressao '/' expressao {$$ = astCreate(DIV, NULL, $1, $3);}
            | expressao '<' expressao {$$ = astCreate(GT,  NULL, $1, $3);}
            | expressao '>' expressao {$$ = astCreate(LT,  NULL, $1, $3);}
            | expressao '&' expressao {$$ = astCreate(AND, NULL, $1, $3);}
            | expressao '~' expressao {$$ = astCreate(NOT, NULL, $1, $3);}
            | expressao '|' expressao {$$ = astCreate(OR,  NULL, $1, $3);}
            | expressao OPERATOR_GE   expressao {$$ = astCreate(GE,  NULL, $1, $3);}
            | expressao OPERATOR_LE   expressao {$$ = astCreate(LE,  NULL, $1, $3);}
            | expressao OPERATOR_EQ   expressao {$$ = astCreate(EQ,  NULL, $1, $3);}
            | expressao OPERATOR_DIF  expressao {$$ = astCreate(DIF, NULL, $1, $3);}
            | '(' expressao ')' {$$ = $2;}
            | TK_IDENTIFIER     {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
            | LIT_INT           {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
            | LIT_CHAR          {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
            // function(params)
            | TK_IDENTIFIER '(' passagemListaParametros ')' {AST* func = astCreate(SYMBOL, $1, NULL, NULL); $$ = astCreate(FUNCAPP, NULL, func, $3);} 
            // input(type)
            // TODO: perguntar como fazer
            | KW_INPUT '(' tipo ')'   {$$ = NULL;}  
            | TK_IDENTIFIER '[' expressao ']' {AST* vec = astCreate(SYMBOL, $1, NULL, NULL); $$ = astCreate(VECACC, NULL, vec, $3);}
            // TODO: perguntar se adiciono real e string 
            ;

passagemParametros      : expressao virgulaPassagemParametrosOuVazio {$$ = astCreate(LIST, NULL, $1, $2);}
                        ;

virgulaPassagemParametrosOuVazio: ',' passagemParametros        {$$ = $2;}
                                |                               {$$ = NULL;}
                                ;

passagemListaParametros : passagemParametros    {$$ = $1;}
                        |                       {$$ = NULL;}
                        ;

%%

int yyerror(char *msg){
    fprintf(stderr, "\n\nSyntax error at line %d!!!\n\n", getLineNumber());
    exit(3);
}
