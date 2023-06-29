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
%type<ast> tipo
%type<ast> comando
%type<ast> comandos
%type<ast> bloco
%type<ast> atribuicao
%type<ast> controleFluxo
%type<ast> outputComando
%type<ast> returnComando
%type<ast> outputElementos
%type<ast> virgulaOutputElementosOuVazio
%type<ast> funcao
%type<ast> cabecalho
%type<ast> definicaoParametros
%type<ast> virgulaDefinicaoParametrosOuVazio
%type<ast> definicaoListaParametros
%type<ast> variavel
%type<ast> declaracao
%type<ast> listaDeclaracoes
%type<ast> programa
%type<ast> nome

%left '&' '~' '|'
%left '<' '>' OPERATOR_GE  OPERATOR_LE OPERATOR_EQ OPERATOR_DIF  
%left '+' '-'
%left '*' '/'


%%
programa: listaDeclaracoes {hashPrint();  AST* root = $1; astToFile(root); $$ = root;}
        ;

listaDeclaracoes: declaracao listaDeclaracoes   {$$ = astCreate(DECLIST, NULL, $1, $2);}
                |                               {$$ = NULL;}
                ;

declaracao      : variavel {$$ = $1;}
                | funcao   {$$ = $1;}
                ;

nome    : TK_IDENTIFIER {$$ = astCreate(SYMBOL, $1, NULL, NULL);}

// variável =
//      tipo TK_IDENTIFIER = valor;
//      tipo nomeVetor[tamanhoVetor];
//      tipo nomeVetor[tamanhoVetor] vetor;
variavel: tipo nome '=' literal ';' {
        AST* typename = astCreate(TYPENAME, NULL, $1, $2);
        $$ = astCreate(VARDEF, NULL, typename, $4);
}
        | tipo nome '[' LIT_INT ']' literais ';' {
        AST* typename = astCreate(TYPENAME, NULL, $1, $2);
        AST* size = astCreate(SYMBOL, $4, NULL, NULL);
        AST* vecsizevalue = astCreate(VECSIZEVALUE, NULL, size, $6);
        $$ = astCreate(VECDEF, NULL, typename, vecsizevalue);
}
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
tipo: KW_BOOL {$$ = astCreate(BOOL, NULL, NULL, NULL);}
    | KW_CHAR {$$ = astCreate(CHAR, NULL, NULL, NULL);}
    | KW_INT  {$$ = astCreate(INT, NULL, NULL, NULL);}
    | KW_REAL {$$ = astCreate(REAL, NULL, NULL, NULL);} 
    ;

// função = cabeçalho corpo
// cabeçalho = tipo TK_IDENTIFIER (lista de parametros)
// corpo = bloco de comandos 
funcao  : cabecalho bloco {$$ = astCreate(FUNCDEF, NULL, $1, $2);}
        ;

cabecalho   : tipo nome '(' definicaoListaParametros ')' {
        AST* typename = astCreate(TYPENAME, NULL, $1, $2);
        $$ = astCreate(HEADER, NULL, typename, $4);
}
            ;

definicaoParametros : tipo nome virgulaDefinicaoParametrosOuVazio {
        AST* typename = astCreate(TYPENAME, NULL, $1, $2);
        $$ = astCreate(LIST, NULL, typename, $3);
}
                    ;

virgulaDefinicaoParametrosOuVazio   : ',' definicaoParametros   {$$ = $2;}
                                    |                           {$$ = NULL;}
                                    ;

definicaoListaParametros: definicaoParametros   {$$ = $1;}
                        |                       {$$ = NULL;}
                        ;

bloco   : '{' comandos '}'      {$$ = astCreate(BLOCKCMD, NULL, NULL, $2);}
        ;

comandos: comando comandos      {$$ = astCreate(COMMANDS, NULL, $1, $2);}
        |                       {$$ = NULL;}
        ;

comando : ';'           {$$ = astCreate(EMPTYCMD, NULL, NULL, NULL);}
        | bloco         {$$ = $1;}
        | atribuicao    {$$ = $1;}
        | controleFluxo {$$ = $1;}
        | outputComando {$$ = $1;}
        | returnComando {$$ = $1;}
        ;
                // atribuição de variável
atribuicao  : nome '=' expressao ';' {$$ = astCreate(VARATTCMD, NULL, $1, $3);}
                // atribuição de vetor
            | nome '[' expressao ']' '=' expressao ';' {
                AST* index = astCreate(VECATTCMD, NULL, $3, $6); 
                $$ = astCreate(VECACC, NULL, $1, index);
                }
            ;

controleFluxo   : KW_IF '(' expressao ')' comando {$$ = astCreate(IF, NULL, $3, $5);}
                | KW_IF '(' expressao ')' comando KW_ELSE comando {
                        AST* thenElse = astCreate(THENELSE, NULL, $5, $7);
                        $$ = astCreate(IF, NULL, $3, thenElse);
                }
                | KW_IF '(' expressao ')' KW_LOOP comando  {
                        AST* loop = astCreate(LOOP, NULL, $6, NULL);
                        $$ = astCreate(IF, NULL, $3, loop);
                }
                ;

outputComando   : KW_OUTPUT outputElementos ';' {$$ = astCreate(OUTPUTCMD, NULL, NULL, $2);}

returnComando   : KW_RETURN expressao ';' {$$ = astCreate(RETURNCMD, NULL, $2, NULL);}


outputElementos : expressao virgulaOutputElementosOuVazio       {$$ = astCreate(LIST, NULL, $1, $2);}
                | LIT_STRING virgulaOutputElementosOuVazio      {
                        AST* stringNode = astCreate(SYMBOL, $1, NULL, NULL);
                        $$ = astCreate(LIST, NULL, stringNode, $2);}
                ;

virgulaOutputElementosOuVazio   : ',' outputElementos   {$$ = $2;}
                                |                       {$$ = NULL;}
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
            | nome     {$$ = $1;}
            | LIT_INT           {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
            | LIT_CHAR          {$$ = astCreate(SYMBOL, $1, NULL, NULL);}
            // function(params)
            | nome '(' passagemListaParametros ')' {$$ = astCreate(FUNCAPP, NULL, $1, $3);} 
            // input(type)
            // TODO: perguntar como fazer
            | KW_INPUT '(' tipo ')'   {$$ = astCreate(INPUT, NULL, NULL, $3);}  
            | nome '[' expressao ']' { $$ = astCreate(VECACC, NULL, $1, $3);}
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
