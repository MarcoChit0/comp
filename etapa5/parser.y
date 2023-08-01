%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"
    #include "semantic.h"
    #include "tac.h"
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
programa: listaDeclaracoes {
        AST* root = $1;  
        checkAndSetDeclarations(root, NULL); 
        checkUndeclared(); 
        checkOperands(root);
        TAC* tac = generateCode(root);
        tacPrintBackwards(tac);
        /*hashPrint();*/ 
        astToFile(root); 
        $$ = root;}
        ;

listaDeclaracoes: declaracao listaDeclaracoes   {$$ = astCreate(AST_DECLIST, NULL, $1, $2, getLineNumber());}
                |                               {$$ = NULL;}
                ;

declaracao      : variavel {$$ = $1;}
                | atribuicao {$$ = $1;}
                | funcao   {$$ = $1;}
                ;

nome    : TK_IDENTIFIER {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}

// variável =
//      tipo TK_IDENTIFIER = valor;
//      tipo nomeVetor[tamanhoVetor];
//      tipo nomeVetor[tamanhoVetor] vetor;
variavel: tipo nome '=' literal ';' {
        AST* typename = astCreate(AST_TYPENAME, NULL, $1, $2, getLineNumber());
        $$ = astCreate(AST_VARDEF, NULL, typename, $4, getLineNumber());
}
        | tipo nome '[' LIT_INT ']' literais ';' {
        AST* typename = astCreate(AST_TYPENAME, NULL, $1, $2, getLineNumber());
        AST* size = astCreate(AST_SYMBOL, $4, NULL, NULL, getLineNumber());
        AST* vecsizevalue = astCreate(AST_VECSIZEVALUE, NULL, size, $6, getLineNumber());
        $$ = astCreate(AST_VECDEF, NULL, typename, vecsizevalue, getLineNumber());
}
        ;

literal : LIT_INT       {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
        | LIT_REAL      {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
        | LIT_CHAR      {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
        | LIT_STRING    {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
        ; 

literais: literal literais      {$$ = astCreate(AST_LITERAIS, NULL, $1, $2, getLineNumber());}
        |                       {$$ = NULL;}
        ;

// tipos = {int, real, bool, char}
tipo: KW_BOOL {$$ = astCreate(AST_BOOL, NULL, NULL, NULL, getLineNumber());}
    | KW_CHAR {$$ = astCreate(AST_CHAR, NULL, NULL, NULL, getLineNumber());}
    | KW_INT  {$$ = astCreate(AST_INT, NULL, NULL, NULL, getLineNumber());}
    | KW_REAL {$$ = astCreate(AST_REAL, NULL, NULL, NULL, getLineNumber());} 
    ;

// função = cabeçalho corpo
// cabeçalho = tipo TK_IDENTIFIER (lista de parametros)
// corpo = bloco de comandos 
funcao  : cabecalho bloco {$$ = astCreate(AST_FUNCDEF, NULL, $1, $2, getLineNumber());}
        ;

cabecalho   : tipo nome '(' definicaoListaParametros ')' {
        AST* typename = astCreate(AST_TYPENAME, NULL, $1, $2, getLineNumber());
        $$ = astCreate(AST_HEADER, NULL, typename, $4, getLineNumber());
}
            ;

definicaoParametros : tipo nome virgulaDefinicaoParametrosOuVazio {
        AST* typename = astCreate(AST_TYPENAME, NULL, $1, $2, getLineNumber());
        $$ = astCreate(AST_LIST, NULL, typename, $3, getLineNumber());
}
                    ;

virgulaDefinicaoParametrosOuVazio   : ',' definicaoParametros   {$$ = $2;}
                                    |                           {$$ = NULL;}
                                    ;

definicaoListaParametros: definicaoParametros   {$$ = $1;}
                        |                       {$$ = NULL;}
                        ;

bloco   : '{' comandos '}'      {$$ = astCreate(AST_BLOCKCMD, NULL, $2, NULL, getLineNumber());}
        ;

comandos: comando comandos      {$$ = astCreate(AST_COMMANDS, NULL, $1, $2, getLineNumber());}
        |                       {$$ = NULL;}
        ;

comando : ';'           {$$ = astCreate(AST_EMPTYCMD, NULL, NULL, NULL, getLineNumber());}
        | bloco         {$$ = $1;}
        | atribuicao    {$$ = $1;}
        | controleFluxo {$$ = $1;}
        | outputComando {$$ = $1;}
        | returnComando {$$ = $1;}
        ;
                // atribuição de variável
atribuicao  : nome '=' expressao ';' {$$ = astCreate(AST_VARATTCMD, NULL, $1, $3, getLineNumber());}
                // atribuição de vetor
            | nome '[' expressao ']' '=' expressao ';' {
                AST* index = astCreate(AST_VECATTCMD, NULL, $3, $6, getLineNumber()); 
                $$ = astCreate(AST_VECACC, NULL, $1, index, getLineNumber());
                }
            ;

controleFluxo   : KW_IF '(' expressao ')' comando {$$ = astCreate(AST_IF, NULL, $3, $5, getLineNumber());}
                | KW_IF '(' expressao ')' comando KW_ELSE comando {
                        AST* thenElse = astCreate(AST_THENELSE, NULL, $5, $7, getLineNumber());
                        $$ = astCreate(AST_IF, NULL, $3, thenElse, getLineNumber());
                }
                | KW_IF '(' expressao ')' KW_LOOP comando  {
                        AST* loop = astCreate(AST_LOOP, NULL, $6, NULL, getLineNumber());
                        $$ = astCreate(AST_IF, NULL, $3, loop, getLineNumber());
                }
                ;

outputComando   : KW_OUTPUT outputElementos ';' {$$ = astCreate(AST_OUTPUTCMD, NULL, $2, NULL, getLineNumber());}

returnComando   : KW_RETURN expressao ';' {$$ = astCreate(AST_RETURNCMD, NULL, $2, NULL, getLineNumber());}


outputElementos : expressao virgulaOutputElementosOuVazio       {$$ = astCreate(AST_LIST, NULL, $1, $2, getLineNumber());}
                | LIT_STRING virgulaOutputElementosOuVazio      {
                        AST* stringNode = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());
                        $$ = astCreate(AST_LIST, NULL, stringNode, $2, getLineNumber());}
                ;

virgulaOutputElementosOuVazio   : ',' outputElementos   {$$ = $2;}
                                |                       {$$ = NULL;}
                                ;

expressao   : expressao '+' expressao {$$ = astCreate(AST_ADD, NULL, $1, $3, getLineNumber());}
            | expressao '-' expressao {$$ = astCreate(AST_SUB, NULL, $1, $3, getLineNumber());}
            | expressao '*' expressao {$$ = astCreate(AST_MUL, NULL, $1, $3, getLineNumber());}
            | expressao '/' expressao {$$ = astCreate(AST_DIV, NULL, $1, $3, getLineNumber());}
            | expressao '<' expressao {$$ = astCreate(AST_LT,  NULL, $1, $3, getLineNumber());}
            | expressao '>' expressao {$$ = astCreate(AST_GT,  NULL, $1, $3, getLineNumber());}
            | expressao '&' expressao {$$ = astCreate(AST_AND, NULL, $1, $3, getLineNumber());}
            | expressao '~' expressao {$$ = astCreate(AST_NOT, NULL, $1, $3, getLineNumber());}
            | expressao '|' expressao {$$ = astCreate(AST_OR,  NULL, $1, $3, getLineNumber());}
            | expressao OPERATOR_GE   expressao {$$ = astCreate(AST_GE,  NULL, $1, $3, getLineNumber());}
            | expressao OPERATOR_LE   expressao {$$ = astCreate(AST_LE,  NULL, $1, $3, getLineNumber());}
            | expressao OPERATOR_EQ   expressao {$$ = astCreate(AST_EQ,  NULL, $1, $3, getLineNumber());}
            | expressao OPERATOR_DIF  expressao {$$ = astCreate(AST_DIF, NULL, $1, $3, getLineNumber());}
            | '(' expressao ')' {$$ = astCreate(AST_PARENTHESIS, NULL, $2, NULL, getLineNumber());}
            | nome              {$$ = $1;}
            | LIT_INT           {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
            | LIT_CHAR          {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
            | LIT_REAL          {$$ = astCreate(AST_SYMBOL, $1, NULL, NULL, getLineNumber());}
            // function(params)
            | nome '(' passagemListaParametros ')' {$$ = astCreate(AST_FUNCAPP, NULL, $1, $3, getLineNumber());} 
            // input(type)
            // TODO: perguntar como fazer
            | KW_INPUT '(' tipo ')'   {$$ = astCreate(AST_INPUT, NULL, $3, NULL, getLineNumber());}  
            | nome '[' expressao ']' { $$ = astCreate(AST_VECACC, NULL, $1, $3, getLineNumber());}
            // TODO: perguntar se adiciono real e string 
            ;

passagemParametros      : expressao virgulaPassagemParametrosOuVazio {$$ = astCreate(AST_LIST, NULL, $1, $2, getLineNumber());}
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
