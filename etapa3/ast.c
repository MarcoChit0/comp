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
        case SYMBOL:
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
        case ADD:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " + ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case SUB:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " - ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case MUL:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " * ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case DIV: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " / ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case LT:
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " < ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case GT: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " > ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case AND: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " & ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case NOT: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " ~ ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case OR: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " | ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case GE:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " >= ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case LE:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " <= ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case EQ:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " == ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case DIF: 
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " != ");
            allocAndSetData(  &pAfterRight,  "");
            break;
        case LIST:
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
        case FUNCAPP:    
            allocAndSetData(  &pBeforeLeft, "" );        
            allocAndSetData(  &pBetweenLeftAndRight,  "(");   
            allocAndSetData(  &pAfterRight,  ")");
            break;
        case VECACC:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "[");
            if(node->right != NULL && node->right->type == VECATTCMD)
            { allocAndSetData(  &pAfterRight,  ""); }
            else { allocAndSetData(  &pAfterRight,  "] "); }
            break;
        case LITERAIS:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  " ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case INT:   
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "int");        
            allocAndSetData(  &pAfterRight,  "");
            break;
        case CHAR:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "char");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case BOOL:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "bool");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case REAL:  
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "real");      
            allocAndSetData(  &pAfterRight,  "");
            break;
        case INPUT: 
            allocAndSetData(  &pBeforeLeft, "input(" );
            allocAndSetData(  &pBetweenLeftAndRight,  ")");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case BLOCKCMD:            
            allocAndSetData(  &pBeforeLeft, "{\n" );
            allocAndSetData(  &pBetweenLeftAndRight,  "\n}\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case EMPTYCMD:      
            allocAndSetData(  &pBeforeLeft, "" );      
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case VARATTCMD: 
            allocAndSetData(  &pBeforeLeft, "" );                  
            allocAndSetData(  &pBetweenLeftAndRight,  " = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case VECATTCMD:  
            allocAndSetData(  &pBeforeLeft, "" );                 
            allocAndSetData(  &pBetweenLeftAndRight,  "] = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case RETURNCMD:     
            allocAndSetData(  &pBeforeLeft, "return " );              
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case COMMANDS:            
            allocAndSetData(  &pBeforeLeft, "" );
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case OUTPUTCMD:            
            allocAndSetData(  &pBeforeLeft, "output " );              
            allocAndSetData(  &pBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case IF:             
            allocAndSetData(  &pBeforeLeft, "if ( " );              
            allocAndSetData(  &pBetweenLeftAndRight,  " ) ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case THENELSE:             
            allocAndSetData(  &pBeforeLeft, "" );              
            allocAndSetData(  &pBetweenLeftAndRight,  "\nelse ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case LOOP:             
            allocAndSetData(  &pBeforeLeft, "loop " );              
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case FUNCDEF: 
            allocAndSetData(  &pBeforeLeft,  "");           
            allocAndSetData(  &pBetweenLeftAndRight,  "");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case HEADER:             
            allocAndSetData(  &pBeforeLeft,  "");    
            allocAndSetData(  &pBetweenLeftAndRight,  " ( ");   
            allocAndSetData(  &pAfterRight,  " ) ");
            break;
        case TYPENAME:  
            allocAndSetData(  &pBeforeLeft,  "");               
            allocAndSetData(  &pBetweenLeftAndRight,  " ");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case VARDEF:             
            allocAndSetData(  &pBeforeLeft,  "");    
            allocAndSetData(  &pBetweenLeftAndRight,  " = ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case VECDEF:     
            allocAndSetData(  &pBeforeLeft,  "");            
            allocAndSetData(  &pBetweenLeftAndRight,  " [");   
            allocAndSetData(  &pAfterRight,  "");
            break;
        case VECSIZEVALUE:   
            allocAndSetData(  &pBeforeLeft,  "");              
            allocAndSetData(  &pBetweenLeftAndRight,  "] ");   
            allocAndSetData(  &pAfterRight,  ";\n");
            break;
        case DECLIST:          
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