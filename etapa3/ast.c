#include "ast.h"
AST* astCreate(int type, HashNode* symbol, AST* left, AST* right)
{
    AST* newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->left = left;
    newnode->right = right;
    newnode->symbol = symbol;
    return newnode;
}

void astPrint(AST* root, int calls)
{
    if(root != NULL)
    {
        for(int i = 0; i < calls; i++)
            fprintf(stderr, "\t");
        fprintf(stderr, "(type = %d, symbol = %d\n", root->type, root->symbol? root->symbol->type : 0);
        astPrint(root->left, calls+1);
        astPrint(root->right, calls+1);
        for(int i = 0; i < calls; i++)
            fprintf(stderr, "\t");
        fprintf(stderr, ")\n");        
    }

}

void astToFile(AST* root)
{
    FILE* file;
    if((file = fopen(filename, "w+")) != NULL)
    {    
        astWrite(root, file);   
        fclose(file);
    }
    else
    {
        fprintf(stderr, "LOG: error openning the file!\n");
        exit(4);
    }
    
}

void astWrite(AST* root, FILE* file)
{
    if(root != NULL)
    {
        if(root->left != NULL) astWrite(root->left, file);
        char* printNow;
        char* printAfter;
        content(root, &printNow, &printAfter);
        if(strcmp(printNow, "") != 0) {fputs(printNow, file);}
        if(root->right != NULL) astWrite(root->right, file);
        if(strcmp(printAfter, "") != 0) {fputs(printAfter, file);}
    }
}

void content(AST* node, char** printRightNow, char** printAfterRightRecursion)
{
    char* pNow = NULL;
    char* pAfter = NULL;
    if(node != NULL)
    {
        switch (node->type)
        {
        case SYMBOL:
            if(node->symbol != NULL)
            {
                allocAndSetData(&pNow, node->symbol->text);
            }
            else
            {
                allocAndSetData(&pNow, "");
            }
            allocAndSetData(  &pAfter,  "");
            break;
        case ADD: 
            allocAndSetData(  &pNow,  " + ");
            allocAndSetData(  &pAfter,  "");
            break;
        case SUB:
            allocAndSetData(  &pNow,  " - ");
            allocAndSetData(  &pAfter,  "");
            break;
        case MUL:
            allocAndSetData(  &pNow,  " * ");
            allocAndSetData(  &pAfter,  "");
            break;
        case DIV: 
            allocAndSetData(  &pNow,  " / ");
            allocAndSetData(  &pAfter,  "");
            break;
        case LT:  
            allocAndSetData(  &pNow,  " < ");
            allocAndSetData(  &pAfter,  "");
            break;
        case GT:  
            allocAndSetData(  &pNow,  " > ");
            allocAndSetData(  &pAfter,  "");
            break;
        case AND: 
            allocAndSetData(  &pNow,  " & ");
            allocAndSetData(  &pAfter,  "");
            break;
        case NOT: 
            allocAndSetData(  &pNow,  " ~ ");
            allocAndSetData(  &pAfter,  "");
            break;
        case OR:  
            allocAndSetData(  &pNow,  " | ");
            allocAndSetData(  &pAfter,  "");
            break;
        case GE:  
            allocAndSetData(  &pNow,  " >= ");
            allocAndSetData(  &pAfter,  "");
            break;
        case LE:  
            allocAndSetData(  &pNow,  " <= ");
            allocAndSetData(  &pAfter,  "");
            break;
        case EQ:  
            allocAndSetData(  &pNow,  " == ");
            allocAndSetData(  &pAfter,  "");
            break;
        case DIF: 
            allocAndSetData(  &pNow,  " != ");
            allocAndSetData(  &pAfter,  "");
            break;
        case LIST:
            if(node->right != NULL)
            {
                allocAndSetData(  &pNow,  ", ");   
            }
            else
            {
                allocAndSetData( &pNow, "");
            }
            allocAndSetData(  &pAfter,  "");
            break;
        case FUNCAPP:            
            allocAndSetData(  &pNow,  "(");   
            allocAndSetData(  &pAfter,  ")");
            break;
        case VECACC:            
            allocAndSetData(  &pNow,  "[");
            if(node->right != NULL && node->right->type == VECATTCMD)
            { allocAndSetData(  &pAfter,  ""); }
            else { allocAndSetData(  &pAfter,  "] "); }
            break;
        case LITERAIS:            
            allocAndSetData(  &pNow,  " ");   
            allocAndSetData(  &pAfter,  "");
            break;
        case INT:   
            allocAndSetData(  &pNow,  "int");        
            allocAndSetData(  &pAfter,  "");
            break;
        case CHAR:  
            allocAndSetData(  &pNow,  "char");      
            allocAndSetData(  &pAfter,  "");
            break;
        case BOOL:  
            allocAndSetData(  &pNow,  "bool");      
            allocAndSetData(  &pAfter,  "");
            break;
        case REAL:  
            allocAndSetData(  &pNow,  "real");      
            allocAndSetData(  &pAfter,  "");
            break;
        case INPUT: 
            allocAndSetData(  &pNow,  "intput(");   
            allocAndSetData(  &pAfter,  ")");
            break;
        case BLOCKCMD:            
            allocAndSetData(  &pNow,  "{\n");   
            allocAndSetData(  &pAfter,  "}");
            break;
        case EMPTYCMD:            
            allocAndSetData(  &pNow,  ";\n");   
            allocAndSetData(  &pAfter,  "");
            break;
        case VARATTCMD:             
            allocAndSetData(  &pNow,  " = ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case VECATTCMD:             
            allocAndSetData(  &pNow,  "] = ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case RETURNCMD:             
            allocAndSetData(  &pNow,  "return ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case COMMANDS:            
            allocAndSetData(  &pNow,  "");   
            allocAndSetData(  &pAfter,  "");
            break;
        case OUTPUTCMD:            
            allocAndSetData(  &pNow,  "output ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case IF:             
            allocAndSetData(  &pNow,  "if ( ");   
            allocAndSetData(  &pAfter,  " ) ");
            break;
        case THENELSE:             
            allocAndSetData(  &pNow,  "");   
            allocAndSetData(  &pAfter,  "else");
            break;
        case LOOP:             
            allocAndSetData(  &pNow,  "loop ");   
            allocAndSetData(  &pAfter,  "");
            break;
        case FUNCDEF:             
            allocAndSetData(  &pNow,  "");   
            allocAndSetData(  &pAfter,  "");
            break;
        case HEADER:             
            allocAndSetData(  &pNow,  " ( ");   
            allocAndSetData(  &pAfter,  " ) ");
            break;
        case TYPENAME:             
            allocAndSetData(  &pNow,  " ");   
            allocAndSetData(  &pAfter,  "");
            break;
        case VARDEF:             
            allocAndSetData(  &pNow,  " = ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case VECDEF:             
            allocAndSetData(  &pNow,  " [");   
            allocAndSetData(  &pAfter,  "");
            break;
        case VECSIZEVALUE:             
            allocAndSetData(  &pNow,  "] ");   
            allocAndSetData(  &pAfter,  ";\n");
            break;
        case DECLIST:             
            allocAndSetData(  &pNow,  "");   
            allocAndSetData(  &pAfter,  "");
            break;
        default: 
            allocAndSetData(  &pNow,  "");
            allocAndSetData(  &pAfter,  "");
            break;
        }
        fprintf(stderr, "1/");
        allocAndSetData(printRightNow, pNow);
        fprintf(stderr, "2/");
        allocAndSetData(printAfterRightRecursion, pAfter);
        fprintf(stderr, "3\n");
        fprintf(stderr, "now = [%s]\n", *printRightNow);
        fprintf(stderr, "after = [%s]\n", *printAfterRightRecursion);
    }
    else
    {
        allocAndSetData(printRightNow, "");
        allocAndSetData(printAfterRightRecursion, "");
    }
}

void allocAndSetData(char** destiny, char* source)
{
    *destiny = (char*) calloc(1, strlen(source) + 1);
    strcpy(*destiny, source);
}