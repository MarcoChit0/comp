#include "tac.h"

TAC* tacCreate(int type, HashNode* res, HashNode* o1, HashNode* o2)
{
    TAC* newTac = (TAC*) calloc(1, sizeof(TAC));
    newTac->type = type;
    newTac->result = res;
    newTac->operator1 = o1;
    newTac->operator2 = o2;
    newTac->prev = NULL;
    newTac->next = NULL;
    return newTac;
}

void tacPrint(TAC* tac)
{
    if(!tac || (tac != NULL && tac->type == TAC_SYMBOL))
        return;
    
    printf("TAC[%s, %s, %s, %s]",
        tacMap[tac->type],
        (tac->result)? tac->result->text : "",
        (tac->operator1)? tac->operator1->text : "",
        (tac->operator2)? tac->operator2->text : ""
    );
}
void tacPrintBackwards(TAC* tac)
{
    if(!tac)
        return;
    tacPrintBackwards(tac->prev);
    tacPrint(tac);
}
TAC* generateCode(AST* ast)
{
    TAC* result;
    TAC* code[2]; // left and right sons

    if(!ast)
        return NULL;
    
    code[0] = generateCode(ast->left);
    code[1] = generateCode(ast->right);
 
    switch (ast->type)
    {
    case SYMBOL:
        result = tacCreate(TAC_SYMBOL, ast->symbol, NULL, NULL);
        break;
    case ADD:
        result = tacJoin(
            tacJoin(code[0], code[1]),
            tacCreate(
                TAC_ADD, 
                makeTemp(), 
                code[0] ? code[0]->result : NULL,
                code[1] ? code[1]->result : NULL 
            )
        );
        break;
    case VARATTCMD:
        result = tacJoin(
            code[0], 
            tacCreate(
                TAC_COPY, 
                ast->symbol,
                code[0] ? code[0]->result : NULL,
                NULL
            )
        );
        break;
    
    default:

        break;
    }
    return result;
}

TAC* tacJoin(TAC* tac1, TAC* tac2)
{
    if (!tac1)
        return tac2;
    if (!tac2)
        return tac1;
    TAC* aux = tac2;
    while(aux->prev != NULL) 
        aux = aux->prev;
    aux->prev = tac1;
    return tac2;
}