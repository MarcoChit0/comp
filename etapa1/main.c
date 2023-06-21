#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

extern FILE* yyin;
extern char* yytext;

int main(int argc, char** argv){
    int tok;
    // open the file that is passed by the user
    yyin = fopen(argv[1], "r");
    if(yyin == 0){
        printf("WARNING: Could not open the file!\n");
        exit(1);
    }
    // initialize global variables and data structures that will be used through the program.
    initMe();
    while(isRunning()){
        // read token
        tok = yylex();
        // pass token to manager
        manager(tok);
    }
    // print data base
    hashPrint();
    return 0;
}
#endif