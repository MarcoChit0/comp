#include "tac.h"

TAC *tacCreate(int type, HashNode *res, HashNode *o1, HashNode *o2)
{
    TAC *newTac = (TAC *)calloc(1, sizeof(TAC));
    newTac->position = DEFAULTPOSITION;
    newTac->type = type;
    newTac->result = res;
    newTac->operator1 = o1;
    newTac->operator2 = o2;
    newTac->prev = NULL;
    newTac->next = NULL;
    return newTac;
}

TAC *tacChangePosition(TAC *tac, int *position)
{
    tac->position = *position;
    (*position)++;
    return tac;
}

void tacPrint(TAC *tac)
{
    if (!tac)
        return;
    if (tac && tac->type == TAC_SYMBOL)
        return;
    if (tac->type == TAC_VECDEF)
        printf("TAC[%s, %s, %s, %d]\n",
               tacMap[tac->type],
               (tac->result) ? tac->result->text : "",
               (tac->operator1) ? tac->operator1->text : "",
               tac->position);
    else
        printf("TAC[%s, %s, %s, %s]\n",
               tacMap[tac->type],
               (tac->result) ? tac->result->text : "",
               (tac->operator1) ? tac->operator1->text : "",
               (tac->operator2) ? tac->operator2->text : "");
}

void tacPrintBackwards(TAC *tac)
{
    if (!tac)
        return;
    tacPrintBackwards(tac->prev);
    tacPrint(tac);
}

TAC *makeBinaryOperation(int operation, TAC *left, TAC *right)
{
    TAC *result = tacJoin(
        tacJoin(left, right),
        tacCreate(
            operation,
            makeTemp(),
            left ? left->result : NULL,
            right ? right->result : NULL));
    return result;
}

TAC *makeIfOperations(AST *ast)
{
    TAC *tacJumpFalse;
    TAC *result = NULL;
    HashNode *jumpFalseLabel = makeLabel();
    TAC *tacLabelElse = tacCreate(TAC_LABEL, jumpFalseLabel, NULL, NULL);
    TAC *expression = generateCode(ast->left);

    if (ast->right)
        switch (ast->right->type)
        {
        case AST_THENELSE:
            /*
            if EXP then TCMD else ECMD

            JFALSE jumpFalseLabel EXP NULL
            $TCMDCODE
            ...
            $TCMDCODE
            JMP afterElseCmdLabel

            jumpFalseLabel:
            $ECMDCODE
            ...
            $ECMDCODE

            afterElseCmdLabel:
            */
            if (ast->right)
            {
                HashNode *afterElseCmdLabel = makeLabel();
                TAC *tacLabelAfterElseCmd = tacCreate(TAC_LABEL, afterElseCmdLabel, NULL, NULL);
                tacJumpFalse = tacCreate(TAC_JFALSE, tacLabelElse ? tacLabelElse->result : NULL, expression ? expression->result : NULL, NULL);
                tacJumpFalse = tacJoin(expression, tacJumpFalse);

                TAC *thenCode = generateCode(ast->right->left);
                TAC *elseCode = generateCode(ast->right->right);

                tacLabelElse = tacJoin(
                    // add the jump execution to not execute the else commands after executing the then commands
                    tacJoin(
                        thenCode,
                        tacCreate(TAC_JMP, afterElseCmdLabel, NULL, NULL)),
                    // add the else label
                    tacLabelElse);
                // add label after the else to jump after the execution of then commands
                elseCode = tacJoin(elseCode, tacLabelAfterElseCmd);
                // add the code of then and else commands
                tacLabelElse = tacJoin(
                    tacLabelElse,
                    elseCode);
                result = tacJoin(tacJumpFalse, tacLabelElse);
            }
            else
            {
                printf("TAC - generateCode - error when processing an 'IF THEN ELSE' command!\n");
                exit(5);
            }

            break;
        case AST_LOOP:
            /*
            if EXP loop LCMDS

            ifLabel:
            JFALSE jumpFalseLabel EXP NULL
            $LCMDS
            ...
            $LCMDS
            JMP ifLabel

            jumpFalseLabel:
            ...
            */
            {
                HashNode *ifLabel = makeLabel();
                TAC *tacIfLabel = tacCreate(TAC_LABEL, ifLabel, NULL, NULL);
                tacJumpFalse = tacCreate(TAC_JFALSE, tacLabelElse ? tacLabelElse->result : NULL, expression ? expression->result : NULL, NULL);
                tacJumpFalse = tacJoin(expression, tacJumpFalse);
                tacJumpFalse = tacJoin(tacIfLabel, tacJumpFalse);
                TAC *loopCode = generateCode(ast->right);
                loopCode = tacJoin(loopCode, tacCreate(TAC_JMP, ifLabel, NULL, NULL));
                tacLabelElse = tacJoin(loopCode, tacLabelElse);
                result = tacJoin(tacJumpFalse, tacLabelElse);
            }
            break;
        default:
            /*
            if EXP then CMD

            JFALSE jumpFalseLabel EXP NULL
            $CMDCODE
            ...
            $CMDCODE
            jumpFalseLabel:
            ...
            */
            {
                tacJumpFalse = tacCreate(TAC_JFALSE, tacLabelElse ? tacLabelElse->result : NULL, expression ? expression->result : NULL, NULL);
                tacJumpFalse = tacJoin(expression, tacJumpFalse);
                TAC *thenCode = generateCode(ast->right);
                tacLabelElse = tacJoin(thenCode, tacLabelElse);
                result = tacJoin(tacJumpFalse, tacLabelElse);
            }
            break;
        }
    return result;
}

TAC *applyOverList(AST *ast, int type, HashNode *operator1, HashNode *operator2, int reverse)
{
    TAC *result = NULL;
    AST *aux = ast;
    int position = 0;
    while (aux)
    {
        TAC *value = generateCode(aux->left);
        TAC *code = NULL;
        switch (reverse)
        {
        case LISTAPPLY_REVERSE_VALUE_OP1:
            code = tacCreate(type, operator1, value ? value->result : NULL, operator2);
            code = tacChangePosition(code, &position);
            break;
        case LISTAPPLY_REVERSE_VALUE_OP2:
            code = tacCreate(type, operator2, operator1, value ? value->result : NULL);
            code = tacChangePosition(code, &position);
            break;
        case LISTAPPLY_DEFAULT:
        default:
            code = tacCreate(type, value ? value->result : NULL, operator1, operator2);
            code = tacChangePosition(code, &position);
            break;
        }
        result = tacJoin(result, tacJoin(value, code));
        aux = aux->right;
    }
    return result;
}

TAC *tacFunctionCall(AST *ast)
{
    /*
            FUNCAPP
            /   \
        FUNC     PARAM
                /     \
                P1     PARAM
                      /     \
                      P2     PARAM
                            /     \
                            P3     ...
    */
    TAC *result = NULL;
    AST *functionSymbol = ast->left;
    AST *params = ast->right;
    HashNode *functionHashNode = functionSymbol->symbol;
    HashNode *functionArgument = functionHashNode->content;
    while (functionArgument)
    {
        AST *param = params->left;
        TAC *paramCode = generateCode(param);
        TAC *moveParamCodeToFunctionArgument = tacCreate(TAC_MOVE, functionArgument, paramCode->result, NULL);
        functionArgument = functionArgument->content;
        params = params->right;
        result = tacJoin(result, tacJoin(paramCode, moveParamCodeToFunctionArgument));
    }
    return result;
}

TAC *shortCircuitAND(AST *ast, TAC *leftSonCode, TAC *rightSonCode)
{
    // testar esquerda.
    // se falso, ir para label de falso.
    // senão, testar direita.
    // se falso, ir para label de falso.
    // se verdadeiro, ir para label de verdadeiro.
    if (!ast)
        return NULL;

    TAC *result = NULL;

    // labels
    TAC *falseLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    TAC *trueLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    TAC *returnLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    // temp
    TAC *returnTemp = tacCreate(TAC_SYMBOL, makeTemp(), NULL, NULL);

    TAC *testarFilhoDaEsquerdaFalso = tacCreate(
        TAC_JFALSE,
        falseLabel ? falseLabel->result : NULL,
        leftSonCode ? leftSonCode->result : NULL,
        NULL);
    result = tacJoin(leftSonCode, testarFilhoDaEsquerdaFalso);
    TAC *testarFilhoDaDireitaFalso = tacCreate(
        TAC_JFALSE,
        falseLabel ? falseLabel->result : NULL,
        rightSonCode ? rightSonCode->result : NULL,
        NULL);
    TAC *filhoDaDireitaVerdadeiro = tacCreate(
        TAC_JMP,
        trueLabel ? trueLabel->result : NULL,
        NULL,
        NULL);
    result = tacJoin(
        result,
        tacJoin(
            rightSonCode,
            tacJoin(
                testarFilhoDaDireitaFalso,
                filhoDaDireitaVerdadeiro)));
    falseLabel = tacJoin(returnTemp, falseLabel);
    falseLabel = tacJoin(
        falseLabel,
        tacCreate(TAC_SET_FALSE, returnTemp ? returnTemp->result : NULL, NULL, NULL));
    falseLabel = tacJoin(
        falseLabel,
        tacCreate(TAC_JMP, returnLabel ? returnLabel->result : NULL, NULL, NULL));
    trueLabel = tacJoin(
        trueLabel,
        tacCreate(TAC_SET_TRUE, returnTemp ? returnTemp->result : NULL, NULL, NULL));
    trueLabel = tacJoin(
        trueLabel,
        tacCreate(TAC_JMP, returnLabel ? returnLabel->result : NULL, NULL, NULL));
    returnLabel = tacJoin(
        returnLabel,
        tacCreate(TAC_MOVE, makeTemp(), returnTemp ? returnTemp->result : NULL, NULL));
    trueLabel = tacJoin(trueLabel, returnLabel);
    result = tacJoin(result, tacJoin(falseLabel, trueLabel));

    return result;
}

TAC *shortCircuitOR(AST *ast, TAC *leftSonCode, TAC *rightSonCode)
{
    // testar esquerda.
    // se falso, ir para label de falso.
    // senão, testar direita.
    // se falso, ir para label de falso.
    // se verdadeiro, ir para label de verdadeiro.
    if (!ast)
        return NULL;

    TAC *result = NULL;

    // labels
    TAC *falseLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    TAC *trueLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    TAC *returnLabel = tacCreate(TAC_LABEL, makeLabel(), NULL, NULL);
    // temp
    TAC *returnTemp = tacCreate(TAC_SYMBOL, makeTemp(), NULL, NULL);
    TAC *testarFilhoDaEsquerdaVerdadeiro = tacCreate(
        TAC_NOT,
        makeTemp(),
        leftSonCode ? leftSonCode->result : NULL,
        NULL);
    TAC *testarFilhoDaEsquerdaFalso = tacCreate(
        TAC_JFALSE,
        trueLabel ? trueLabel->result : NULL,
        testarFilhoDaEsquerdaVerdadeiro ? testarFilhoDaEsquerdaVerdadeiro->result : NULL,
        NULL);
    testarFilhoDaEsquerdaFalso = tacJoin(testarFilhoDaEsquerdaVerdadeiro, testarFilhoDaEsquerdaFalso);
    result = tacJoin(leftSonCode, testarFilhoDaEsquerdaFalso);
    TAC *testarFilhoDaDireitaFalso = tacCreate(
        TAC_JFALSE,
        falseLabel ? falseLabel->result : NULL,
        rightSonCode ? rightSonCode->result : NULL,
        NULL);
    TAC *filhoDaDireitaVerdadeiro = tacCreate(
        TAC_JMP,
        trueLabel ? trueLabel->result : NULL,
        NULL,
        NULL);
    result = tacJoin(
        result,
        tacJoin(
            rightSonCode,
            tacJoin(
                testarFilhoDaDireitaFalso,
                filhoDaDireitaVerdadeiro)));
    falseLabel = tacJoin(returnTemp, falseLabel);
    falseLabel = tacJoin(
        falseLabel,
        tacCreate(TAC_SET_FALSE, returnTemp ? returnTemp->result : NULL, NULL, NULL));
    falseLabel = tacJoin(
        falseLabel,
        tacCreate(TAC_JMP, returnLabel ? returnLabel->result : NULL, NULL, NULL));
    trueLabel = tacJoin(
        trueLabel,
        tacCreate(TAC_SET_TRUE, returnTemp ? returnTemp->result : NULL, NULL, NULL));
    trueLabel = tacJoin(
        trueLabel,
        tacCreate(TAC_JMP, returnLabel ? returnLabel->result : NULL, NULL, NULL));
    returnLabel = tacJoin(
        returnLabel,
        tacCreate(TAC_MOVE, makeTemp(), returnTemp ? returnTemp->result : NULL, NULL));
    trueLabel = tacJoin(trueLabel, returnLabel);
    result = tacJoin(result, tacJoin(falseLabel, trueLabel));
}

TAC *generateCode(AST *ast)
{

    if (!ast)
        return NULL;

    TAC *result = NULL;
    TAC *rightSonCode = generateCode(ast->right);
    TAC *leftSonCode = generateCode(ast->left);

    switch (ast->type)
    {
    case AST_SYMBOL:
        result = tacCreate(TAC_SYMBOL, ast->symbol, NULL, NULL);
        break;
    case AST_ADD:
        result = makeBinaryOperation(TAC_ADD, leftSonCode, rightSonCode);
        break;
    case AST_SUB:
        result = makeBinaryOperation(TAC_SUB, leftSonCode, rightSonCode);
        break;
    case AST_MUL:
        result = makeBinaryOperation(TAC_MUL, leftSonCode, rightSonCode);
        break;
    case AST_DIV:
        result = makeBinaryOperation(TAC_DIV, leftSonCode, rightSonCode);
        break;
    case AST_LT:
        result = makeBinaryOperation(TAC_LT, leftSonCode, rightSonCode);
        break;
    case AST_GT:
        result = makeBinaryOperation(TAC_GT, leftSonCode, rightSonCode);
        break;
    case AST_AND:
        result = shortCircuitAND(ast, leftSonCode, rightSonCode);
        break;
    case AST_NOT:
        result = makeBinaryOperation(TAC_NOT, leftSonCode, rightSonCode);
        break;
    case AST_OR:
        result = shortCircuitOR(ast, leftSonCode, rightSonCode);
        break;
    case AST_GE:
        result = makeBinaryOperation(TAC_GE, leftSonCode, rightSonCode);
        break;
    case AST_LE:
        result = makeBinaryOperation(TAC_LE, leftSonCode, rightSonCode);
        break;
    case AST_EQ:
        result = makeBinaryOperation(TAC_EQ, leftSonCode, rightSonCode);
        break;
    case AST_DIF:
        result = makeBinaryOperation(TAC_DIF, leftSonCode, rightSonCode);
        break;
    case AST_INPUT:
    {
        HashNode *temp = makeTemp();
        temp->datatype;
        if (ast->left)
        {
            switch (ast->left->type)
            {
            case AST_INT:
                temp->datatype = DATATYPE_INT;
                break;
            case AST_CHAR:
                temp->datatype = DATATYPE_CHAR;
                break;
            case AST_REAL:
                temp->datatype = DATATYPE_REAL;
                break;
            case AST_BOOL:
                temp->datatype = DATATYPE_BOOL;
                break;
            default:
                temp->datatype = DATATYPE_INT;
                break;
            }
        }
        else
            temp->datatype = DATATYPE_ERROR;

        result = tacCreate(TAC_READ, temp, NULL, NULL);
    }
    break;
    case AST_FUNCAPP:
    {
        result = tacJoin(
            tacJoin(
                leftSonCode,
                tacFunctionCall(ast)),
            tacCreate(
                TAC_FUNCTIONCALL,
                makeTemp(),
                leftSonCode ? leftSonCode->result : NULL,
                NULL));
    }
    break;
    case AST_VARDEF:
        break;
    case AST_VARATTCMD:
        result = tacJoin(
            tacJoin(
                leftSonCode,
                rightSonCode),
            tacCreate(
                TAC_MOVE,
                leftSonCode ? leftSonCode->result : NULL,
                rightSonCode ? rightSonCode->result : NULL,
                NULL));
        break;
    case AST_VECATTCMD:
        result = tacJoin(
            tacJoin(
                leftSonCode,
                rightSonCode),
            tacCreate(
                TAC_VECATT,
                NULL,
                leftSonCode ? leftSonCode->result : NULL,
                rightSonCode ? rightSonCode->result : NULL));
        break;
    case AST_VECACC:
        if (ast->right && ast->right->type == AST_VECATTCMD)
        {
            rightSonCode->result = ast->left ? ast->left->symbol : NULL;
            result = tacJoin(
                leftSonCode,
                rightSonCode);
        }
        else
        {
            // tacL <- tacR <- tacNode
            result = tacJoin(
                // tacL <- tacR
                tacJoin(
                    leftSonCode,
                    rightSonCode),
                // tacR <- tacNode
                tacCreate(
                    TAC_VECACC,
                    makeTemp(),
                    leftSonCode ? leftSonCode->result : NULL,
                    rightSonCode ? rightSonCode->result : NULL));
        }
        break;
    case AST_OUTPUTCMD:
        result = applyOverList(ast->left, TAC_PRINT, NULL, NULL, LISTAPPLY_DEFAULT);
        break;
    case AST_RETURNCMD:
        result = tacJoin(
            leftSonCode,
            tacCreate(TAC_RETURN, leftSonCode ? leftSonCode->result : NULL, NULL, NULL));
        break;
    case AST_EMPTYCMD:
        result = tacCreate(TAC_NOP, NULL, NULL, NULL);
        break;
    case AST_BLOCKCMD:
    {
        if (ast->top && ast->top->type == AST_FUNCDEF)
        {
            // TAC* blockBegin = tacCreate(TAC_FUNCTIONBEGIN, NULL, NULL, NULL);
            // TAC* blockEnd = tacCreate(TAC_FUNCTIONEND, NULL, NULL, NULL);
            // result = tacJoin(tacJoin(blockBegin, leftSonCode), blockEnd);
            result = leftSonCode;
        }
        else
        {
            TAC *blockBegin = tacCreate(TAC_BEGINBLOCK, NULL, NULL, NULL);
            TAC *blockEnd = tacCreate(TAC_ENDBLOCK, NULL, NULL, NULL);
            result = tacJoin(tacJoin(blockBegin, leftSonCode), blockEnd);
        }
    }
    break;
    case AST_VECDEF:
    {
        if (ast->right)
        {
            TAC *vectorSize = generateCode(ast->right->left);
            result = tacJoin(
                leftSonCode,
                tacCreate(TAC_VECDEFBEGIN, leftSonCode ? leftSonCode->result : NULL, vectorSize ? vectorSize->result : NULL, NULL));
            TAC *vectorValue = applyOverList(ast->right->right, TAC_VECDEF, leftSonCode ? leftSonCode->result : NULL, NULL, LISTAPPLY_REVERSE_VALUE_OP1);
            result = tacJoin(
                result,
                vectorValue);
            result = tacJoin(
                result,
                tacCreate(TAC_VECDEFEND, leftSonCode ? leftSonCode->result : NULL, NULL, NULL));
        }
        else
        {
            printf("TAC - generateCode - error when processing a vector definition!\n");
            exit(5);
        }
    }
    break;
    case AST_FUNCDEF:
    {
        if (
            ast->left && ast->left->type == AST_HEADER &&
            ast->left->left && ast->left->left->type == AST_TYPENAME &&
            ast->left->left->right && ast->left->left->right->type == AST_SYMBOL)
        {
            HashNode *function = ast->left->left->right->symbol;
            result = tacJoin(
                tacJoin(
                    tacCreate(TAC_FUNCTIONBEGIN, function, NULL, NULL), /*start function definition*/
                    rightSonCode                                        /*function body*/
                    ),
                tacCreate(TAC_FUNCTIONEND, function, NULL, NULL) /*end function definition*/
            );
        }
        else
        {
            printf("TAC - generateCode - error when processing a function definition!\n");
            exit(5);
        }
    }
    break;
    case AST_IF:
        result = makeIfOperations(ast);
        break;
    default:
        result = tacJoin(leftSonCode, rightSonCode);
        break;
    }
    return result;
}

TAC *tacJoin(TAC *tac1, TAC *tac2)
{
    if (!tac1)
        return tac2;
    if (!tac2)
        return tac1;
    TAC *aux = tac2;
    while (aux->prev != NULL)
        aux = aux->prev;
    aux->prev = tac1;
    return tac2;
}

TAC *tacReverse(TAC *tac)
{
    if (!tac)
        return NULL;
    TAC *t;
    for (t = tac; t->prev; t = t->prev)
        t->prev->next = t;
    return t;
}