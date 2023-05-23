#include "hash.h"
%%

%%
int main(){
    yylex();
}
#include "hash.c"
int yywrap(){
    // eof found
    return 1;
}