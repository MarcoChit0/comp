#ifndef ASTHEADER
#define ASTHEADER
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#define ASTTYPE 
enum asttype{
    SYMBOL  = 0, 
    ADD     = 1, 
    SUB     = 2, 
    MUL     = 3, 
    DIV     = 4, 
    LT      = 5, 
    GT      = 6, 
    AND     = 7, 
    NOT     = 8, 
    OR      = 9, 
    GE      = 10, 
    LE      = 11, 
    EQ      = 12, 
    DIF     = 13, 
    LIST    = 14, 
    FUNCAPP = 15, 
    VECACC  = 16,
    LITERAIS = 17,
};

typedef struct astnode{
    int type;
    HashNode* symbol;
    struct astnode* left;
    struct astnode* right;
} AST;

AST* astCreate(int type, HashNode* symbol, AST* left, AST* right);
void astPrint(AST* root, int calls);

#endif