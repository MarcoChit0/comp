#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "semantic.h"

extern FILE* yyin;
extern char* yytext;
char* filename = "out.txt";
int yyparse();

int main(int argc, char** argv){
    int tok;
    // check if user passed input file
    if(argc < 3)
    {
        printf("\n\nWARNING: Did not receive the input file and the output file!!!\n\n");
        exit(1);
    }
    // open the file that is passed by the user
    yyin = fopen(argv[1], "r");
    if(yyin == 0){
        printf("\n\nWARNING: Could not open the input file!!!\n\n");
        exit(2);
    }
    allocAndSetData(&filename, argv[2]);
    if(filename == NULL)
    {
        printf("\n\nWARNING: Could not open the output file!!!\n\n");
        exit(2);
    }
    // initialize global variables and data structures that will be used through the program.
    initMe();
    // call parser, that will call many times yylex()
    // if syntax is ok, then nothing should happen
    // else, it will call yyerror and will exit the program with a warning message
    // and send a compilation successs message to the user
    yyparse();
    // check if there is no semantic errors
    if(getSemanticErrors())
    {
        printf("\n\nWARNING: %d semantic errors found!!!\n\n", getSemanticErrors());
        exit(4);
    }

    fprintf(stderr, "\n200 - Ok!\n"); exit(0); // Compilation Ok
    return 0;
}

#endif