#ifndef ASTHEADER
#define ASTHEADER
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#define ASTTYPE 
enum asttype{
    SYMBOL          = 0, 
    ADD             = 1, 
    SUB             = 2, 
    MUL             = 3, 
    DIV             = 4, 
    LT              = 5, 
    GT              = 6, 
    AND             = 7, 
    NOT             = 8, 
    OR              = 9, 
    GE              = 10, 
    LE              = 11, 
    EQ              = 12, 
    DIF             = 13,
    /*
            LIST
            /   \
        ELEM1    ELEM2
    OBS.: ELEM2 PODE SER LIST
    */    
    LIST            = 14,
    /*
            FUNCAPP
            /   \
        FUNC     PARAM
    */    
    FUNCAPP         = 15, 
    /*
            VECACC
            /   \
        VEC     INDEX
    */
    VECACC          = 16,
    LITERAIS        = 17,
    /*
            TYPE
            /   \
        NULL     NULL
    */
    INT             = 18,
    CHAR            = 19,
    BOOL            = 20,
    REAL            = 21,
    /*
            INPUT
            /   \
        TYPE     NULL
    */   
    INPUT           = 22,
    /*
            BLOCKCMD
            /   \
        BLOCK    NULL
    */    
    BLOCKCMD        = 23,
    /*
            EMPTYCMD
            /   \
        NULL     NULL
    */    
    EMPTYCMD        = 24,
    /*
            VARATTCMD
            /       \
         VAR         ATT
    */    
    VARATTCMD       = 25,
    /*
            VECAPP
            /   \
         VEC     VECATTCMD
                /         \
           INDEX           ATT
    */    
    VECATTCMD       = 26,
    /*
            RETURNCMD
            /       \
         EXP         NULL
    */   
    RETURNCMD       = 27,
    /*
            COMMANDS
            /   \
         CMD     CMD
    */
    COMMANDS        = 28,
    /*
            OUTPUTCMD
            /       \
         EXP         NULL
    */   
    OUTPUTCMD       = 29,
    /*
              IF
            /   \
         EXP     CMD
    */    
    IF              = 30,
    /*
              IF 
            /   \
         EXP     THENELSE
                /        \
             CMD          CMD
    */    
    THENELSE        = 31,
    /*
              IF 
            /   \
         EXP     LOOP
                /    \
             CMD      NULL
    */    
    LOOP            = 32,
    /*
            FUNCDEF
            /   \
         HEADER  BLOCK
    */
    FUNCDEF         = 33,
    /*
            FUNCDEF
            /   \
         HEADER  BLOCK
        /      \
    TYPENAME    PARAMS
    OBS.: PARAMS = LIST OF TYPENAME
    */
    HEADER          = 34,
    /*
           TYPENAME
            /   \
        TYPE     NAME
    */
    TYPENAME        = 35,
    /*
           VARDEF
            /   \
    TYPENAME     LIT
    */
    VARDEF          = 36,
    /*
           VECDEF
            /   \
    TYPENAME     VECSIZEVALUE
    */
    VECDEF          = 37,
    /*
           VECDEF
            /   \
    TYPENAME     VECSIZEVALUE
                /            \
            LIT               LIST
    */
    VECSIZEVALUE    = 38,
    DECLIST = 39,
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