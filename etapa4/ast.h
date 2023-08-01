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
    AST_LITERAIS        = 17,
    /*
            TYPE
            /   \
        NULL     NULL
    */
    AST_INT             = 18,
    AST_CHAR            = 19,
    AST_BOOL            = 20,
    AST_REAL            = 21,
    /*
            INPUT
            /   \
        TYPE     NULL
    */   
    AST_INPUT           = 22,
    /*
            BLOCKCMD
            /   \
        BLOCK   NULL
    */    
    AST_BLOCKCMD        = 23,
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
    AST_VARATTCMD       = 25,
    /*
            VECACC
            /   \
         VEC     VECATTCMD
                /         \
           INDEX           ATT
    */    
    AST_VECATTCMD       = 26,
    /*
            RETURNCMD
            /       \
         EXP         NULL
    */   
    AST_RETURNCMD       = 27,
    /*
            COMMANDS
            /   \
         CMD     CMD
    */
    AST_COMMANDS        = 28,
    /*
            OUTPUTCMD
            /       \
         EXP        NULL
    */   
    AST_OUTPUTCMD       = 29,
    /*
              IF
            /   \
         EXP     CMD
    */    
    AST_IF              = 30,
    /*
              IF 
            /   \
         EXP     THENELSE
                /        \
             CMD          CMD
    */    
    AST_THENELSE        = 31,
    /*
              IF 
            /   \
         EXP     LOOP
                /    \
             CMD      NULL
    */    
    AST_LOOP            = 32,
    /*
            FUNCDEF
            /   \
         HEADER  BLOCK
    */
    AST_FUNCDEF         = 33,
    /*
            FUNCDEF
            /   \
         HEADER  BLOCK
        /      \
    TYPENAME    PARAMS
    OBS.: PARAMS = LIST OF TYPENAME
    */
    AST_HEADER          = 34,
    /*
           TYPENAME
            /   \
        TYPE     NAME
    */
    AST_TYPENAME        = 35,
    /*
           VARDEF
            /   \
    TYPENAME     LIT
    */
    AST_VARDEF          = 36,
    /*
           VECDEF
            /   \
    TYPENAME     VECSIZEVALUE
    */
    AST_VECDEF          = 37,
    /*
           VECDEF
            /   \
    TYPENAME     VECSIZEVALUE
                /            \
            LIT               LITERIAS
    */
    AST_VECSIZEVALUE    = 38,
    AST_DECLIST         = 39,
    /*
        PARENTHESIS
            |
           EXP

    */
    AST_PARENTHESIS     = 40,
};

static char map[41][256] = {
    "SYMBOL",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "LT",
    "GT",
    "AND",
    "NOT",
    "OR",
    "GE", 
    "LE", 
    "EQ", 
    "DIF",
    "LIST",
    "FUNCAPP",
    "VECACC",
    "LITERAIS",
    "INT",
    "CHAR",
    "BOOL",
    "REAL",
    "INPUT",
    "BLOCKCMD",
    "EMPTYCMD",
    "VARATTCMD",
    "VECATTCMD",
    "RETURNCMD",
    "COMMANDS",
    "OUTPUTCMD",
    "IF",
    "THENELSE",
    "LOOP",
    "FUNCDEF",
    "HEADER",
    "TYPENAME",
    "VARDEF",          
    "VECDEF",          
    "VECSIZEVALUE",    
    "DECLIST",         
    "PARENTHESIS"};

extern char* filename;

typedef struct astnode{
    int type;
    HashNode* symbol;
    struct astnode* left;
    struct astnode* right;
    struct astnode* top;
    int line;
} AST;

AST*    astCreate(int type, HashNode* symbol, AST* left, AST* right, int line);
void    astPrint(AST* root, int calls);
void    astToFile(AST* root);
void    astWrite(AST* root, FILE* file);
void    content(AST*, char**, char**, char**);
void    allocAndSetData(char** destiny, char* source);
void    astTopMatch(AST* node, AST* top);
char*   astTypeToString(int type);

#endif