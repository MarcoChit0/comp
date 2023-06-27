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