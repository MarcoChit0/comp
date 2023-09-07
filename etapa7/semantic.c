#include "semantic.h"

int semanticErrors = 0;

void checkAndSetDeclarations(AST *node, AST *top)
{
    if (!node)
        return;
    if (top)
        astTopMatch(node, top);
    checkAndSetDeclarations(node->left, node);
    switch (node->type)
    {
    case AST_VARDEF:
        setHashSymbol(node, SYMBOL_VARIABLE);
        break;
    case AST_VECDEF:
        {
            setHashSymbol(node, SYMBOL_VECTOR);
            HashNode* vector = node->left->right->symbol;
            HashNode* size = node->right->left->symbol;
            if(atoi(size->text) > 0)
            {
                vector->content = size;
            }
            else
            {
                semanticErrors++;
                fprintf(stderr, "Semantic Error: vector with size <= 0!\n");
            }
        }
        break;
    case AST_FUNCDEF:
        /*
        node = FUNDEF
        node->left = HEADER
        */
        if (node->left)
            setHashSymbol(node->left, SYMBOL_FUNCTION);
        /* PARAMS = VARIABLES
        node->left->right = PARAMS
        node->left->right->left = TYPENAME
        node->left->right->right = PARAMS
        node->left->right->right->left = TYPENAME
        node->left->right->right->right = PARAMS
        ...
        */
        if (node->left->right)
            for (AST *aux = node->left->right; aux != NULL; aux = aux->right)
                setHashSymbol(aux, SYMBOL_VARIABLE);
        break;
    default:
        break;
    }
    checkAndSetDeclarations(node->right, node);
}

void checkUndeclared()
{
    int undeclaredSymbols = hashLookForSymbols(TK_IDENTIFIER);
    if (undeclaredSymbols)
    {
        fprintf(stderr, "Semantic Error: %d undeclared symbols!\n", undeclaredSymbols);
        semanticErrors += undeclaredSymbols;
    }
}

void setHashSymbol(AST *node, int symbol)
{
    // node = vardef | vecdef | fundef
    // node->left = typename
    // node->left->left = type
    // node->left->right = name
    if (node->left && node->left->left && node->left->right && node->left->right->symbol)
    {
        // check if there is a variable declared multiple times
        if (node->left->right->symbol->type != TK_IDENTIFIER)
        {
            fprintf(
                stderr, "Semantic Error: symbol [%s, %d] already declared!\n",
                node->left->right->symbol->text,
                node->left->right->symbol->type);
            semanticErrors++;
        }
        // updates type of hash node
        node->left->right->symbol->type = symbol;
        // updates datatype of hash node
        switch (node->left->left->type)
        {
        case AST_INT:
            node->left->right->symbol->datatype = DATATYPE_INT;
            break;
        case AST_CHAR:
            node->left->right->symbol->datatype = DATATYPE_CHAR;
            break;
        case AST_BOOL:
            node->left->right->symbol->datatype = DATATYPE_BOOL;
            break;
        case AST_REAL:
            node->left->right->symbol->datatype = DATATYPE_REAL;
            break;
        default:
            break;
        }
        // assign the hash node of the value to the hash node of the variable
        // HashNode[variable].valueContent <- HashNode[value]
        if (node->left->right->symbol->type == SYMBOL_VARIABLE && node->right && node->right->symbol)
        {
            node->left->right->symbol->content = node->right->symbol;
        }
    }
}

int getSemanticErrors()
{
    return semanticErrors;
}

void checkOperands(AST *node)
{
    if (!node)
        return;
    if (node->left)
        checkOperands(node->left);
    switch (node->type)
    {
    case AST_INPUT:
    case AST_PARENTHESIS:
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
    case AST_LT:
    case AST_GT:
    case AST_GE:
    case AST_LE:
    case AST_EQ:
    case AST_DIF:
    case AST_AND:
    case AST_NOT:
    case AST_OR:
    case AST_VECACC:
    case AST_FUNCAPP:
        if (checkExpressionType(node) == DATATYPE_ERROR || checkExpressionType(node) == DATATYPE_STRING)
        {
            fprintf(stderr, "Semantic Error: command %s with data type error at line #%d!\n", astTypeToString(node->type), node->line);
            semanticErrors++;
        }
        break;
    case AST_VARATTCMD:
    {
        int left = checkExpressionType(node->left);
        int right = checkExpressionType(node->right);
        if (!checkCompatibilityBetweenDataTypes(left, right) || node->left->symbol->type != SYMBOL_VARIABLE || left == DATATYPE_STRING)
        {
            fprintf(stderr, "Semantic Error: command %s with data type error at line #%d!\n", astTypeToString(node->type), node->line);
            semanticErrors++;
        }
    }
    break;
    case AST_OUTPUTCMD:
        if (node->left)
            for (AST *outputList = node->left; outputList != NULL; outputList = outputList->right)
            {
                int outputType = checkExpressionType(outputList->left);
                if (outputType == DATATYPE_ERROR)
                {
                    fprintf(stderr, "Semantic Error: command %s with data type error at line #%d!\n", astTypeToString(node->type), node->line);
                    semanticErrors++;
                }
            }
        break;
    case AST_VECDEF:
        if (checkExpressionType(node) == DATATYPE_ERROR || checkExpressionType(node) == DATATYPE_STRING)
        {
            fprintf(stderr, "Semantic Error: command %s with data type error at line #%d!\n", astTypeToString(node->type), node->line);
            semanticErrors++;
        }
        break;
    case AST_RETURNCMD:
    {
        AST *fundef = node;
        while (fundef != NULL && fundef->type != AST_FUNCDEF)
            fundef = fundef->top;
        if (!fundef || !checkCompatibilityBetweenDataTypes(checkExpressionType(fundef), checkExpressionType(node->left)))
        {
            fprintf(stderr, "Semantic Error: command %s with data type error at line #%d!\n", astTypeToString(node->type), node->line);
            semanticErrors++;
        }
    }
    break;
    default:
        break;
    }
    if (node->right)
        checkOperands(node->right);
}

int checkExpressionType(AST *node)
{
    if (!node)
        return DATATYPE_ERROR;
    int left, right;
    switch (node->type)
    {
    case AST_SYMBOL:
        if (node->symbol && node->symbol->type != SYMBOL_FUNCTION && node->symbol->type != SYMBOL_VECTOR)
            return node->symbol->datatype;
        else
        {
            fprintf(stderr, "Semantic Error: trying to use a symbols that is not a varible as a variable!\n");
            return DATATYPE_ERROR;
        }
        break;
    case AST_TYPENAME:
        return checkExpressionType(node->right);
        break;
    case AST_INPUT:
        if (node->left)
            return astTypeToDataType(node->left->type);
        else
            return DATATYPE_ERROR;
        break;
    case AST_PARENTHESIS:
        return checkExpressionType(node->left);
        break;
    case AST_VARATTCMD:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        if (checkCompatibilityBetweenDataTypes(left, right))
            return left;
        else
            return DATATYPE_ERROR;
    // arithmetic operators
    case AST_ADD:
    case AST_SUB:
    case AST_MUL:
    case AST_DIV:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenArithmeticOperatorsDataTypes(left, right);
        break;
    ///////////////////////
    // comparation operators
    case AST_LT:
    case AST_GT:
    case AST_GE:
    case AST_LE:
    case AST_EQ:
    case AST_DIF:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenComparationOperatorsDataTypes(left, right);
        break;
    ////////////////////////
    // logic operators
    case AST_AND:
    case AST_OR:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenLogicOperatorsDataTypes(left, right);
        break;
    case AST_NOT:
        return checkExpressionType(node->left);
        break;
    //////////////////
    case AST_VECACC:
        if (node->left && node->left->symbol && node->left->symbol->type == SYMBOL_VECTOR)
        {
            int vecType = node->left->symbol->datatype;
            if (node->right && node->right->type == AST_VECATTCMD)
            {
                int indexType = checkExpressionType(node->right->left);
                int valueType = checkExpressionType(node->right->right);
                if (
                    (indexType == DATATYPE_INT || indexType == DATATYPE_CHAR) &&
                    (checkCompatibilityBetweenDataTypes(vecType, valueType)) &&
                    (vecType != DATATYPE_STRING))
                    return vecType;
                else
                    return DATATYPE_ERROR;
            }
            else
            {
                right = checkExpressionType(node->right);
                if (right == DATATYPE_INT || right == DATATYPE_CHAR)
                    return vecType;
                else
                    return DATATYPE_ERROR;
            }
        }
        else
        {
            fprintf(stderr, "Semantic Error: using a nonvector variable as vector!\n");
            return DATATYPE_ERROR;
        }

        break;
    case AST_VECDEF:
        if (node->left && node->left && node->left->right && node->left->right->symbol && node->left->right->symbol->type == SYMBOL_VECTOR)
        {
            int vectorType = node->left->right->symbol->datatype;
            if (node->right && node->right->left && node->right->left->symbol && checkCompatibilityBetweenDataTypes(node->right->left->symbol->datatype, DATATYPE_INT))
            {
                int vectorSize = atoi(node->right->left->symbol->text);
                if (node->right->right)
                {
                    int numberOfElements = 0;
                    for (AST *aux = node->right->right; aux != NULL; aux = aux->right)
                    {
                        numberOfElements++;
                        if (!aux->left->symbol || !checkCompatibilityBetweenDataTypes(vectorType, aux->left->symbol->datatype))
                        {
                            fprintf(stderr, "Semantic Error: incompatible types of vector and parameters on vector definition\n");
                            return DATATYPE_ERROR;
                        }
                    }
                    if (numberOfElements != vectorSize)
                    {
                        fprintf(stderr, "Semantic Error: incompatible size of vector and parameters on vector definition\n");
                        return DATATYPE_ERROR;
                    }
                }
                return vectorType;
            }
            else
                return DATATYPE_ERROR;
        }
        else
        {
            fprintf(stderr, "Semantic Error: using a nonvector variable as vector!\n");
            return DATATYPE_ERROR;
        }
        break;
    case AST_FUNCAPP:
        if (node->left && node->left->symbol && node->left->symbol->type == SYMBOL_FUNCTION)
        {
            int functionType = node->left->symbol->datatype;
            AST *header = findFunctionDefinition(node, node->left->symbol->text);
            if (!header)
            {
                fprintf(stderr, "Semantic Error: did not find function definition!\n");
                return DATATYPE_ERROR;
            }
            AST *aux = node->right;
            AST *params = header->right;
            for (; params != NULL && aux != NULL; params = params->right, aux = aux->right)
                if (!checkCompatibilityBetweenDataTypes(checkExpressionType(aux->left), checkExpressionType(params->left)))
                {
                    fprintf(stderr, "Semantic Error: incompatile types between function parameters and function definition!\n");
                    return DATATYPE_ERROR;
                }
            if (!params && !aux)
            {
                AST *functionTypename = header->left;
                AST *functionName = functionTypename->right;
                HashNode *functionSymbol = functionName->symbol;
                params = header->right;
                for (; params != NULL; params = params->right)
                {
                    AST *typename = params->left;    // AST TYPENAME
                    AST *name = typename->right;     // AST SYMBOL
                    HashNode *symbol = name->symbol; // HASH SYMBOL
                    if (symbol)
                    {
                        functionSymbol->content = symbol;
                        functionSymbol = symbol;
                        functionSymbol->content = NULL;
                    }
                }
                return functionType;
            }
            fprintf(stderr, "Semantic Error: different sizes between #parameters in function call and #parameters in function definition!\n");
            return DATATYPE_ERROR;
        }
        else
        {
            fprintf(stderr, "Semantic Error: trying to call a symbol that is not function as a function!\n");
        }
        break;
    case AST_FUNCDEF:
        return checkExpressionType(node->left);
        break;
    case AST_HEADER:
        if (node->left && node->left->right && node->left->right->symbol && node->left->right->symbol->type == SYMBOL_FUNCTION)
            return node->left->right->symbol->datatype;
        else
            return DATATYPE_ERROR;
        break;
    default:
        return DATATYPE_ERROR;
        break;
    }
    return DATATYPE_ERROR;
}

int astTypeToDataType(int astType)
{
    switch (astType)
    {
    case AST_INT:
        return DATATYPE_INT;
        break;
    case AST_CHAR:
        return DATATYPE_CHAR;
        break;
    case AST_REAL:
        return DATATYPE_REAL;
        break;
    case AST_BOOL:
        return DATATYPE_BOOL;
        break;
    default:
        break;
    }
    return DATATYPE_ERROR;
}

int checkCompatibilityBetweenArithmeticOperatorsDataTypes(int dataType1, int dataType2)
{
    if ((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return DATATYPE_INT;
    if (dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return DATATYPE_REAL;
    return DATATYPE_ERROR;
}
int checkCompatibilityBetweenLogicOperatorsDataTypes(int dataType1, int dataType2)
{
    if (dataType1 == DATATYPE_BOOL && dataType2 == DATATYPE_BOOL)
        return DATATYPE_BOOL;
    else
        return DATATYPE_ERROR;
}
int checkCompatibilityBetweenComparationOperatorsDataTypes(int dataType1, int dataType2)
{
    if ((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return DATATYPE_BOOL;
    if (dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return DATATYPE_BOOL;
    return DATATYPE_ERROR;
}

int checkCompatibilityBetweenDataTypes(int dataType1, int dataType2)
{
    if ((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return TRUE;
    if (dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return TRUE;
    if (dataType1 == DATATYPE_BOOL && dataType2 == DATATYPE_BOOL)
        return TRUE;
    if (dataType1 == DATATYPE_STRING && dataType2 == DATATYPE_STRING)
        return TRUE;
    return FALSE;
}

AST *findFunctionDefinition(AST *node, char *function)
{
    if (!node)
        return NULL;
    AST *aux = node;
    while (aux->top != NULL)
        aux = aux->top;
    return findFunctionHeader(aux, function);
}

int checkFunctionHeader(AST *header, char *function)
{
    if (!header)
        return FALSE;
    if (header->type == AST_HEADER && header->left && header->left->right && strcmp(header->left->right->symbol->text, function) == 0)
        return TRUE;
    return FALSE;
}

AST *findFunctionHeader(AST *node, char *function)
{
    if (!node)
        return NULL;
    if (checkFunctionHeader(node, function))
        return node;
    AST *left = findFunctionHeader(node->left, function);
    if (left != NULL)
        return left;
    AST *right = findFunctionHeader(node->right, function);
    if (right != NULL)
        return right;
    return NULL;
}