#ifndef TACHEADER
#define TACHEADER

#include "ast.h"

#define LISTAPPLY_DEFAULT 0
#define LISTAPPLY_REVERSE_VALUE_OP1 1
#define LISTAPPLY_REVERSE_VALUE_OP2 2
#define DEFAULTPOSITION -1

#define TACS
enum tacEnum
{
    TAC_SYMBOL = 0,
    TAC_ADD,
    TAC_SUB,
    TAC_MUL,
    TAC_DIV,
    TAC_LT,
    TAC_GT,
    TAC_AND,
    TAC_NOT,
    TAC_OR,
    TAC_GE,
    TAC_LE,
    TAC_EQ,
    TAC_DIF,
    TAC_MOVE,
    TAC_LABEL,
    TAC_JMP,
    TAC_JFALSE,
    TAC_FUNCTIONBEGIN,
    TAC_FUNCTIONEND,
    TAC_FUNCTIONCALL,
    TAC_RETURN,
    TAC_READ,
    TAC_PRINT,
    TAC_VECACC,
    TAC_VECATT,
    TAC_NOP,
    TAC_BEGINBLOCK,
    TAC_ENDBLOCK,
    TAC_VECDEFBEGIN,
    TAC_VECDEF,
    TAC_VECDEFEND,
};

static char tacMap[100][256] = {
    "TAC_SYMBOL",
    "TAC_ADD",
    "TAC_SUB",
    "TAC_MUL",
    "TAC_DIV",
    "TAC_LT",
    "TAC_GT",
    "TAC_AND",
    "TAC_NOT",
    "TAC_OR",
    "TAC_GE",
    "TAC_LE",
    "TAC_EQ",
    "TAC_DIF",
    "TAC_MOVE",
    "TAC_LABEL",
    "TAC_JMP",
    "TAC_JFALSE",
    "TAC_FUNCTIONBEGIN",
    "TAC_FUNCTIONEND",
    "TAC_FUNCTIONCALL",
    "TAC_RETURN",
    "TAC_READ",
    "TAC_PRINT",
    "TAC_VECACC",
    "TAC_VECATT",
    "TAC_NOP",
    "TAC_BEGINBLOCK",
    "TAC_ENDBLOCK",
    "TAC_VECDEFBEGIN",
    "TAC_VECDEF",
    "TAC_VECDEFEND",
};


typedef struct tacNode
{
    int position;
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
TAC* makeBinaryOperation(int operation, TAC* left, TAC* right);
TAC* tacReverse(TAC* tac);

#endif