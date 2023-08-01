#ifndef ASTHEADER
#define ASTHEADER
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#define ASTTYPE 
enum asttype{
    AST_SYMBOL          = 0, 
    AST_ADD             = 1, 
    AST_SUB             = 2, 
    AST_MUL             = 3, 
    AST_DIV             = 4, 
    AST_LT              = 5, 
    AST_GT              = 6, 
    AST_AND             = 7, 
    AST_NOT             = 8, 
    AST_OR              = 9, 
    AST_GE              = 10, 
    AST_LE              = 11, 
    AST_EQ              = 12, 
    AST_DIF             = 13,
    /*
            LIST
            /   \
        ELEM1    ELEM2
    OBS.: ELEM2 PODE SER LIST
    */    
    AST_LIST            = 14,
    /*
            FUNCAPP
            /   \
        FUNC     PARAM
    */    
    AST_FUNCAPP         = 15, 
    /*
            VECACC
            /   \
        VEC     INDEX
    */
    AST_VECACC          = 16,
    /*
            LITERAIS
            /   \
        LIT1     LIT2
        OBS.: LIT2 PODE SER LITERAIS
    */
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
        BLOCK   NULL
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
            VECACC
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
         EXP        NULL
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
            LIT               LITERIAS
    */
    VECSIZEVALUE    = 38,
    DECLIST = 39,
};

extern char* filename;

typedef struct astnode{
    int type;
    HashNode* symbol;
    struct astnode* left;
    struct astnode* right;
} AST;

AST* astCreate(int type, HashNode* symbol, AST* left, AST* right);
void astPrint(AST* root, int calls);
void astToFile(AST* root);
void astWrite(AST* root, FILE* file);
void content(AST*, char**, char**, char**);
void allocAndSetData(char** destiny, char* source);
#endif