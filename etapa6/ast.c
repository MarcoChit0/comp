#include "ast.h"
AST* astCreate(int type, HashNode* symbol, AST* left, AST* right, int line)
{
    AST* newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->left = left;
    newnode->right = right;
    newnode->symbol = symbol;
    newnode->top = NULL;
    newnode->line = line;
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
            fprintf(stderr, " ");
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
        char* printBetweenLeftAndRight = NULL;
        char* printAfterRight = NULL;
        char* printBeforeLeft = NULL;

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
    if(node != NULL)
    {
        switch (node->type)
        {
        case AST_SYMBOL:
            if(node->symbol != NULL)
            {
                allocAndSetData(printBetweenLeftAndRight, node->symbol->text);
            }
            else
            {
                allocAndSetData(printBetweenLeftAndRight, "");
            }
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_ADD:
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " + ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_SUB:
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " - ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_MUL:
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " * ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_DIV: 
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " / ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_LT:
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " < ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_GT: 
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " > ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_AND: 
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " & ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_NOT: 
            allocAndSetData(  printBeforeLeft, " ~ " );
            allocAndSetData(  printBetweenLeftAndRight,  "");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_OR: 
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " | ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_GE:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " >= ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_LE:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " <= ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_EQ:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " == ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_DIF: 
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " != ");
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_LIST:
            allocAndSetData(  printBeforeLeft, "" );
            if(node->right != NULL)
            {
                allocAndSetData(  printBetweenLeftAndRight,  ", ");   
            }
            else
            {
                allocAndSetData( printBetweenLeftAndRight, "");
            }
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_FUNCAPP:    
            allocAndSetData(  printBeforeLeft, "" );        
            allocAndSetData(  printBetweenLeftAndRight,  "(");   
            allocAndSetData(  printAfterRight,  ")");
            break;
        case AST_VECACC:            
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "[");
            if(node->right != NULL && node->right->type == AST_VECATTCMD)
            { allocAndSetData(  printAfterRight,  ""); }
            else { allocAndSetData(  printAfterRight,  "] "); }
            break;
        case AST_LITERAIS:            
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  " ");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_INT:   
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "int");        
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_CHAR:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "char");      
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_BOOL:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "bool");      
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_REAL:  
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "real");      
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_INPUT: 
            allocAndSetData(  printBeforeLeft, "input(" );
            allocAndSetData(  printBetweenLeftAndRight,  ")");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_BLOCKCMD:            
            allocAndSetData(  printBeforeLeft, "{\n" );
            allocAndSetData(  printBetweenLeftAndRight,  "\n}\n");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_EMPTYCMD:      
            allocAndSetData(  printBeforeLeft, "" );      
            allocAndSetData(  printBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_VARATTCMD: 
            allocAndSetData(  printBeforeLeft, "" );                  
            allocAndSetData(  printBetweenLeftAndRight,  " = ");   
            allocAndSetData(  printAfterRight,  ";\n");
            break;
        case AST_VECATTCMD:  
            allocAndSetData(  printBeforeLeft, "" );                 
            allocAndSetData(  printBetweenLeftAndRight,  "] = ");   
            allocAndSetData(  printAfterRight,  ";\n");
            break;
        case AST_RETURNCMD:     
            allocAndSetData(  printBeforeLeft, "return " );              
            allocAndSetData(  printBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_COMMANDS:            
            allocAndSetData(  printBeforeLeft, "" );
            allocAndSetData(  printBetweenLeftAndRight,  "");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_OUTPUTCMD:            
            allocAndSetData(  printBeforeLeft, "output " );              
            allocAndSetData(  printBetweenLeftAndRight,  ";\n");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_IF:             
            allocAndSetData(  printBeforeLeft, "if ( " );              
            allocAndSetData(  printBetweenLeftAndRight,  " ) ");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_THENELSE:             
            allocAndSetData(  printBeforeLeft, "" );              
            allocAndSetData(  printBetweenLeftAndRight,  "\nelse ");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_LOOP:             
            allocAndSetData(  printBeforeLeft, "loop " );              
            allocAndSetData(  printBetweenLeftAndRight,  "");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_FUNCDEF: 
            allocAndSetData(  printBeforeLeft,  "");           
            allocAndSetData(  printBetweenLeftAndRight,  "");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_HEADER:             
            allocAndSetData(  printBeforeLeft,  "");    
            allocAndSetData(  printBetweenLeftAndRight,  " ( ");   
            allocAndSetData(  printAfterRight,  " ) ");
            break;
        case AST_TYPENAME:  
            allocAndSetData(  printBeforeLeft,  "");               
            allocAndSetData(  printBetweenLeftAndRight,  " ");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_VARDEF:             
            allocAndSetData(  printBeforeLeft,  "");    
            allocAndSetData(  printBetweenLeftAndRight,  " = ");   
            allocAndSetData(  printAfterRight,  ";\n");
            break;
        case AST_VECDEF:     
            allocAndSetData(  printBeforeLeft,  "");            
            allocAndSetData(  printBetweenLeftAndRight,  " [");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_VECSIZEVALUE:   
            allocAndSetData(  printBeforeLeft,  "");              
            allocAndSetData(  printBetweenLeftAndRight,  "] ");   
            allocAndSetData(  printAfterRight,  ";\n");
            break;
        case AST_DECLIST:          
            allocAndSetData(  printBeforeLeft,  "");       
            allocAndSetData(  printBetweenLeftAndRight,  "");   
            allocAndSetData(  printAfterRight,  "");
            break;
        case AST_PARENTHESIS:
            allocAndSetData(  printBeforeLeft,  " (");      
            allocAndSetData(  printBetweenLeftAndRight,  ") ");   
            allocAndSetData(  printAfterRight,  "");
            break;
        default: 
            allocAndSetData(  printBeforeLeft,  "");    
            allocAndSetData(  printBetweenLeftAndRight,  "");
            allocAndSetData(  printAfterRight,  "");
            break;
        }
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

void astTopMatch(AST* node, AST* top)
{
    node->top = top;
}

char* astTypeToString(int type)
{   
    return map[type];
}