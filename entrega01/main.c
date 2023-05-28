#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(){
    int tok;
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