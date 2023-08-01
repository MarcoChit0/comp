#ifndef HASHHEADER
#define HASHHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 997
#define NODATATYPE -1

#define DATATYPES
enum datatypesEnum
{
    DATATYPE_ERROR = -1,
    DATATYPE_INT = 0,
    DATATYPE_REAL = 1,
    DATATYPE_CHAR = 2,
    DATATYPE_BOOL = 3,
    DATATYPE_STRING = 4,
};

#define SYMBOLS
enum symbolsEnum
{
    SYMBOL_VARIABLE=0,
    SYMBOL_VECTOR=1,
    SYMBOL_FUNCTION=2,
    SYMBOL_LABEL=3,
};

typedef struct hashnode
{
    char* text;
    struct hashnode* next;
    int type;
    int datatype;
} HashNode;

void        hashInit();
HashNode*   hashInsert(char* text, int type);
int         hashAddress(char* text);
void        hashPrint();
HashNode*   hashFind(char* text);
int         hashLookForSymbols(int);
HashNode*   hashInsertWithDataType(char* text, int type, int datatype);
HashNode*   makeTemp();
HashNode*   makeLabel();

int         isRunning(void);
void        initMe(void);
int         getLineNumber(void);
void        manager(int token);
void        removeChar(char* str, char c);

extern int lineNumber;
extern int running;
#endif