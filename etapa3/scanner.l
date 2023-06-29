%{
#include "hash.h"
#include "ast.h"
#include "y.tab.h"

int lineNumber = 1;
int running = 1;
%}

%x COMMENT

DIGIT   [0-9]
ID      [a-zA-Z._]
SYMBOLS [-,;\(\)\[\]\{\}=+*/%<>&|~]
STRING  [-,;\(\)\[\]\{\}=+*/%<>&|~a-zA-Z0-9\!\?\@\#\%\&\*\\\/: \.]


%%
{DIGIT}+                    {yylval.symbol = hashInsert(yytext, LIT_INT); return LIT_INT;}
{DIGIT}+[.]{DIGIT}+         {yylval.symbol = hashInsert(yytext, LIT_REAL); return LIT_REAL;}
{SYMBOLS}                   {return yytext[0];}
"int"                       {return KW_INT;}
"real"                      {return KW_REAL;}
"bool"                      {return KW_BOOL;}
"char"                      {return KW_CHAR;}
"if"                        {return KW_IF;}
"then"                      {return KW_THEN;}
"else"                      {return KW_ELSE;}
"return"                    {return KW_RETURN;}
"input"                     {return KW_INPUT;}
"output"                    {return KW_OUTPUT;}
"loop"                      {return KW_LOOP;}
{ID}+                       {yylval.symbol = hashInsert(yytext, TK_IDENTIFIER); return TK_IDENTIFIER;}    
">="                        {return OPERATOR_GE;}
"<="                        {return OPERATOR_LE;}
"=="                        {return OPERATOR_EQ;}
"!="                        {return OPERATOR_DIF;}
"\n"                        {++lineNumber;} 
[ \t]                       {}
(\')(.)(\')                 {/*removeChar(yytext, '\'');*/ yylval.symbol = hashInsert(yytext, LIT_CHAR); return LIT_CHAR;}
(\')(\\)[ tn\"](\')         {/*removeChar(yytext, '\'');*/ yylval.symbol = hashInsert(yytext, LIT_CHAR); return LIT_CHAR;}
(\"){STRING}*(\")           {/*removeChar(yytext, '\"');*/ yylval.symbol = hashInsert(yytext, LIT_STRING); return LIT_STRING;}
(\\\\\\)(.)*                {BEGIN(COMMENT);}
(\\\\)(.)*                  {}
.                           {return TOKEN_ERROR;}

<COMMENT>.                  {}
<COMMENT>"\n"               {++lineNumber;}
<COMMENT>"\/\/\/"           {BEGIN(INITIAL);}
%%

int yywrap(){
    // eof found -> stop running the program
    running = 0;
    return 1;
}