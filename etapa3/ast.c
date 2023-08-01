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
        char* printBetweenLeftAndRight;
        char* printAfterRight;
        char* printBeforeLeft;

        content(root, &printBeforeLeft, &printBetweenLeftAndRight, &printAfterRight);
        if(strcmp(printBeforeLeft, "") != 0) {fputs(printBeforeLeft, file);}
        if(root->left != NULL) astWrite(root->left, file);
        if(strcmp(printBetweenLeftAndRight, "") != 0) {fputs(printBetweenLeftAndRight, file);}
        if(root->right != NULL) astWrite(root->right, file);
        if(strcmp(printAfterRight, "") != 0) {fputs(printAfterRight, file);}
    }
}

void content(AST* node, char** printBeforeLeft, char** printBetweenLeftAndRight, char** printAfterRight)
{
    char* pBeforeLeft = NULL;
    char* pBetweenLeftAndRight = NULL;
    char* pAfterRight = NULL;
    if(node != NULL)
    {
        switch (node->type)
        {
        case AST_SYMBOL:
            if(node->symbol != NULL)
            {
                allocAndSetData(&pBetweenLeftAndRight, node->symbol->text);
            }
            else
            {
                allocAndSetData(&pBetweenLeftAndRight, "");
            }
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_ADD:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " + ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_SUB:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " - ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_MUL:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " * ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_DIV: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " / ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_LT:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " < ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_GT: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " > ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_AND: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " & ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_NOT: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " ~ ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_OR: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " | ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_GE:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " >= ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_LE:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " <= ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_EQ:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " == ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_DIF: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " != ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_LIST:
            allocAndSetData(  &pBeforeLeft, "" );
            if(node->right != NULL)
            {
                allocAndSetData(  &pBetweenLeftAndRight,  ", ");   
            }
            else
            {
                allocAndSetData( &pBetweenLeftAndRight, "");
            }
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_FUNCAPP:    
            allocAndSetData(  &pBeforeLeft, "" );        
            allocAndSetData(  &pBetweenLeftAndRight,  "(");   
            allocAndSetData(  &pAfterRight,  ")");
            break;
        case AST_VECACC:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "[");
            if(node->right != NULL && node->right->type == AST_VECATTCMD)
            { allocAndSetData(  &pAfterRight,  ""); }
            else { allocAndSetData(  &pAfterRight,  "] "); }
            break;
        case AST_LITERAIS:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_INT:   
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "int");        
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_CHAR:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "char");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_BOOL:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "bool");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_REAL:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "real");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_INPUT: 
            allocAndSetData(  &pBeforeLeft, "input(" );
            allocAndSetData(  &pBetweenLeftAndRight,  ")");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_BLOCKCMD:            
            allocAndSetData(  &pBeforeLeft, "{\n" );
            allocAndSetData(  &pBetweenLeftAndRight,  "\n}\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case EMPTYCMD:      
            allocAndSetData(  &pBeforeLeft, "" );      
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_VARATTCMD: 
            allocAndSetData(  &pBeforeLeft, "" );                  
            allocAndSetData(  &pBetweenLeftAndRight,  " = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case AST_VECATTCMD:  
            allocAndSetData(  &pBeforeLeft, "" );                 
            allocAndSetData(  &pBetweenLeftAndRight,  "] = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case AST_RETURNCMD:     
            allocAndSetData(  &pBeforeLeft, "return " );              
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_COMMANDS:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_OUTPUTCMD:            
            allocAndSetData(  &pBeforeLeft, "output " );              
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_IF:             
            allocAndSetData(  &pBeforeLeft, "if ( " );              
            allocAndSetData(  &pBetweenLeftAndRight,  " ) ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_THENELSE:             
            allocAndSetData(  &pBeforeLeft, "" );              
            allocAndSetData(  &pBetweenLeftAndRight,  "\nelse ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_LOOP:             
            allocAndSetData(  &pBeforeLeft, "loop " );              
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_FUNCDEF: 
            allocAndSetData(  &pBeforeLeft,  "");           
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_HEADER:             
            allocAndSetData(  &pBeforeLeft,  "");    
            allocAndSetData(  &pBetweenLeftAndRight,  " ( ");   
            allocAndSetData(  &pAfterRight,  " ) ");
            break;
        case AST_TYPENAME:  
            allocAndSetData(  &pBeforeLeft,  "");               
            allocAndSetData(  &pBetweenLeftAndRight,  " ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_VARDEF:             
            allocAndSetData(  &pBeforeLeft,  "");    
            allocAndSetData(  &pBetweenLeftAndRight,  " = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case AST_VECDEF:     
            allocAndSetData(  &pBeforeLeft,  "");            
            allocAndSetData(  &pBetweenLeftAndRight,  " [");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AST_VECSIZEVALUE:   
            allocAndSetData(  &pBeforeLeft,  "");              
            allocAndSetData(  &pBetweenLeftAndRight,  "] ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case AST_DECLIST:          
            allocAndSetData(  &pBeforeLeft,  "");       
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        default: 
            allocAndSetData(  &pBeforeLeft,  "");    
            allocAndSetData(  &pBetweenLeftAndRight,  "");
            allocAndSetData(  &pAfterRight,  "");
            break;
        }
        allocAndSetData(printBeforeLeft, pBeforeLeft);
        allocAndSetData(printBetweenLeftAndRight, pBetweenLeftAndRight);
        allocAndSetData(printAfterRight, pAfterRight);
    }
    else
    {
        allocAndSetData(printBeforeLeft, "");
        allocAndSetData(printBetweenLeftAndRight, "");
        allocAndSetData(printAfterRight, "");
    }
}

void allocAndSetData(char** destiny, char* source)
{
    *destiny = (char*) calloc(1, strlen(source) + 1);
    strcpy(*destiny, source);
}