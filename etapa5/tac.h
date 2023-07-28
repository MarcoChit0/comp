#ifndef TACHEADER
#define TACHEADER

#include "ast.h"

#define TACS
enum tacEnum
{
    TAC_SYMBOL = 0,
    TAC_ADD = 1,
    TAC_SUB = 2,
    TAC_COPY = 3,
};

static char tacMap[41][256] = {
    "TAC_SYMBOL",
    "TAC_ADD",
    "TAC_SUB",
    "TAC_COPY",
};


typedef struct tacNode
{
    int type;
    HashNode* result;
    HashNode* operator1;
    HashNode* operator2;
    struct tacNode* prev;
    struct tacNode* next; 
}TAC;

TAC* tacCreate(int, HashNode*, HashNode*, HashNode*);
void tacPrint(TAC*);
void tacPrintBackwards(TAC*);
TAC* generateCode(AST*);
TAC* tacJoin(TAC*, TAC*);


#endif