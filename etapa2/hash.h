#ifndef HASHHEADER
#define HASHHEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#define HASHSIZE 997

typedef struct hashnode
{
    char* text;
    struct hashnode* next;
    int type;
} HashNode;

void        hashInit();
HashNode*   hashInsert(char* text, int type);
int         hashAddress(char* text);
void        hashPrint();
HashNode*   hashFind(char* text);
int         isRunning(void);
void        initMe(void);
int         getLineNumber(void);
void        manager(int token);
void        eofFound();
void        removeChar(char* str, char c);

int     lineNumber = 1;
int     running = 1;
#endif