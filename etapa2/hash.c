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


void manager(int token){
    switch (token)
    {
    case KW_INT:        fprintf(stderr, "\nfound=[KW_INT]!\n");break;   
    case KW_REAL:       fprintf(stderr, "\nfound=[KW_REAL]!\n");break;   
    case KW_BOOL:       fprintf(stderr, "\nfound=[KW_BOOL]!\n");break;   
    case KW_CHAR:       fprintf(stderr, "\nfound=[KW_CHAR]!\n");break;   
    case KW_IF:         fprintf(stderr, "\nfound=[KW_IF]!\n");break;  
    case KW_THEN:       fprintf(stderr, "\nfound=[KW_THEN]!\n");break;   
    case KW_ELSE:       fprintf(stderr, "\nfound=[KW_ELSE]!\n");break;   
    case KW_RETURN:     fprintf(stderr, "\nfound=[KW_RETURN]!\n");break;
    case KW_INPUT:      fprintf(stderr, "\nfound=[KW_INPUT]!\n");break;    
    case KW_OUTPUT:     fprintf(stderr, "\nfound=[KW_OUTPUT]!\n");break;
    case KW_LOOP:       fprintf(stderr, "\nfound=[KW_LOOP]!\n");break;    
    case OPERATOR_DIF:  fprintf(stderr, "\nfound=[OPERATOR_DIF]!\n");break;
    case OPERATOR_EQ:   fprintf(stderr, "\nfound=[OPERATOR_EQ]!\n");break;
    case OPERATOR_GE:   fprintf(stderr, "\nfound=[OPERATOR_GE]!\n");break;
    case OPERATOR_LE:   fprintf(stderr, "\nfound=[OPERATOR_LE]!\n");break;
    case TOKEN_ERROR:   fprintf(stderr, "\nWARNING: invalid Token at line %d!!\n",getLineNumber());
    case LIT_INT:       fprintf(stderr, "\nfound=[LIT_INT]!\n");break;
    case LIT_REAL:      fprintf(stderr, "\nfound=[LIT_REAL]!\n");break;
    case LIT_CHAR:      fprintf(stderr, "\nfound=[LIT_CHAR]!\n");break;
    case LIT_STRING:    fprintf(stderr, "\nfound=[LIT_STRING]!\n");break;
    case TK_IDENTIFIER: fprintf(stderr, "\nfound=[TK_IDENTIFIER]!\n");break;
    default:            fprintf(stderr, "\nfound=[DEFAULT CASE]!\n");break;
    }
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