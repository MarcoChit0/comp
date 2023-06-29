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
                allocAndSetData(&pNow, node->symbol->text, sizeof(node->symbol->text));
            }
            else
            {
                allocAndSetData(&pNow, "", sizeof(""));
            }
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case ADD: 
            allocAndSetData(  &pNow,  " + ",  sizeof(" + "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case SUB:
            allocAndSetData(  &pNow,  " - ",  sizeof(" - "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case MUL:
            allocAndSetData(  &pNow,  " * ",  sizeof(" * "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case DIV: 
            allocAndSetData(  &pNow,  " / ",  sizeof(" / "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case LT:  
            allocAndSetData(  &pNow,  " < ",  sizeof(" < "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case GT:  
            allocAndSetData(  &pNow,  " > ",  sizeof(" > "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case AND: 
            allocAndSetData(  &pNow,  " & ",  sizeof(" & "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case NOT: 
            allocAndSetData(  &pNow,  " ~ ",  sizeof(" ~ "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case OR:  
            allocAndSetData(  &pNow,  " | ",  sizeof(" | "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case GE:  
            allocAndSetData(  &pNow,  " >= ", sizeof(" >= "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case LE:  
            allocAndSetData(  &pNow,  " <= ", sizeof(" <= "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case EQ:  
            allocAndSetData(  &pNow,  " == ", sizeof(" == "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case DIF: 
            allocAndSetData(  &pNow,  " != ", sizeof(" != "));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case LIST:
            if(node->right != NULL)
            {
                allocAndSetData(  &pNow,  ", ", sizeof(", "));   
            }
            else
            {
                allocAndSetData( &pNow, "", sizeof(""));
            }
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case FUNCAPP:            
            allocAndSetData(  &pNow,  "(", sizeof("("));   
            allocAndSetData(  &pAfter,  ")",  sizeof(")"));
            break;
        case VECACC:            
            allocAndSetData(  &pNow,  "[", sizeof("["));
            if(node->right != NULL && node->right->type == VECATTCMD)
            { allocAndSetData(  &pAfter,  "",  sizeof("")); }
            else { allocAndSetData(  &pAfter,  "] ",  sizeof("] ")); }
            break;
        case LITERAIS:            
            allocAndSetData(  &pNow,  " ", sizeof(" "));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case INT:   
            allocAndSetData(  &pNow,  "int", sizeof("int"));        
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case CHAR:  
            allocAndSetData(  &pNow,  "char", sizeof("char"));      
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case BOOL:  
            allocAndSetData(  &pNow,  "bool", sizeof("bool"));      
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case REAL:  
            allocAndSetData(  &pNow,  "real", sizeof("real"));      
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case INPUT: 
            allocAndSetData(  &pNow,  "intput(", sizeof("input("));   
            allocAndSetData(  &pAfter,  ")",  sizeof(")"));
            break;
        case BLOCKCMD:            
            allocAndSetData(  &pNow,  "{\n", sizeof("{\n"));   
            allocAndSetData(  &pAfter,  "}",  sizeof("}"));
            break;
        case EMPTYCMD:            
            allocAndSetData(  &pNow,  ";\n", sizeof(";\n"));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case VARATTCMD:             
            allocAndSetData(  &pNow,  " = ", sizeof(" = "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case VECATTCMD:             
            allocAndSetData(  &pNow,  "] = ", sizeof("] = "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case RETURNCMD:             
            allocAndSetData(  &pNow,  "return ", sizeof("return "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case COMMANDS:            
            allocAndSetData(  &pNow,  "", sizeof(""));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case OUTPUTCMD:            
            allocAndSetData(  &pNow,  "output ", sizeof("output "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case IF:             
            allocAndSetData(  &pNow,  "if ( ", sizeof("if ( "));   
            allocAndSetData(  &pAfter,  " ) ",  sizeof(" ) "));
            break;
        case THENELSE:             
            allocAndSetData(  &pNow,  "", sizeof(""));   
            allocAndSetData(  &pAfter,  "else",  sizeof("else"));
            break;
        case LOOP:             
            allocAndSetData(  &pNow,  "loop ", sizeof("loop "));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case FUNCDEF:             
            allocAndSetData(  &pNow,  "", sizeof(""));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case HEADER:             
            allocAndSetData(  &pNow,  " ( ", sizeof(" ( "));   
            allocAndSetData(  &pAfter,  " ) ",  sizeof(" ) "));
            break;
        case TYPENAME:             
            allocAndSetData(  &pNow,  " ", sizeof(" "));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case VARDEF:             
            allocAndSetData(  &pNow,  " = ", sizeof(" = "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case VECDEF:             
            allocAndSetData(  &pNow,  " [", sizeof(" ["));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        case VECSIZEVALUE:             
            allocAndSetData(  &pNow,  "] ", sizeof("] "));   
            allocAndSetData(  &pAfter,  ";\n",  sizeof(";\n"));
            break;
        case DECLIST:             
            allocAndSetData(  &pNow,  "", sizeof(""));   
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        default: 
            allocAndSetData(  &pNow,  "",  sizeof(""));
            allocAndSetData(  &pAfter,  "",  sizeof(""));
            break;
        }
        fprintf(stderr, "1/");
        allocAndSetData(printRightNow, pNow, sizeof(pNow));
        fprintf(stderr, "2/");
        allocAndSetData(printAfterRightRecursion, pAfter, sizeof(pAfter));
        fprintf(stderr, "3\n");
        fprintf(stderr, "now = [%s]\n", *printRightNow);
        fprintf(stderr, "after = [%s]\n", *printAfterRightRecursion);
    }
    else
    {
        allocAndSetData(printRightNow, "", sizeof(""));
        allocAndSetData(printAfterRightRecursion, "", sizeof(""));
    }
}

void allocAndSetData(char** destiny, char* source, int size)
{
    fprintf(stderr, "A/");
    *destiny = (char*) calloc(1, size);
    fprintf(stderr, "B/");
    strcpy(*destiny, source);
    fprintf(stderr, "C\n");
}