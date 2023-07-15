#include "hash.h"

HashNode* Table[HASHSIZE];

void hashInit(){
    for (int i = 0; i < HASHSIZE; i++){
        Table[i] = NULL;
    }
}

HashNode* hashInsert(char* text, int type){
    HashNode* newnode;
    newnode = hashFind(text);
    if (newnode != NULL){
        return newnode;
    }
    newnode = (HashNode*) calloc (1, sizeof(HashNode));
    int address = hashAddress(text);
    newnode->type = type;
    newnode->text = (char*) calloc (strlen(text)+1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = Table[address];
    Table[address] = newnode;
    return newnode;
}

int hashAddress(char* text){
    int address = 1;
    for (int i = 0; i < strlen(text); i++){
        address = (( address * text[i]) % HASHSIZE) + 1;
    }

    return address - 1;
}

void hashPrint(){
    for (int i = 0; i < HASHSIZE; i++){
        for (HashNode* node = Table[i]; node; node = node->next){
            printf("Table[%d] = {%s}, with type = {%d}.\n",i, node->text, node->type);
        }
    }
}

HashNode* hashFind(char* text){
    int address = hashAddress(text);
    HashNode* node;
    for (node = Table[address]; node; node = node->next){
        if (strcmp(node->text, text) == 0)
            return node;
    }
    return NULL;
}

int isRunning(void){
    return running;
}

void initMe(){
    hashInit();
    lineNumber = 1;
    running = 1;
}

int getLineNumber(){
    return lineNumber;
}

void removeChar(char* str, char c){
    int existsChar = 1, charPos = -1;
    while(existsChar){
        existsChar = 0;
        for(int i = 0; i < strlen(str); ++i){
            if (str[i] == c){
                existsChar = 1;
                charPos = i;
                break;
            }
        }
        if (existsChar){
            memmove(
                &str[charPos], 
                &str[charPos+1], 
                strlen(str) - charPos
            );
        }
    }
}