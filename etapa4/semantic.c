#include "semantic.h"

int semanticErrors = 0;

void checkAndSetDeclarations(AST *node)
{
    if (!node)
        return;
    checkAndSetDeclarations(node->left);
    switch (node->type)
    {
        case VARDEF: 
            setHashSymbol(node, SYMBOL_VARIABLE); 
            break;
        case VECDEF: 
            setHashSymbol(node, SYMBOL_VECTOR); 
            break;
        case FUNCDEF:
            /*
            node = FUNDEF
            node->left = HEADER
            */
            if(node->left)
                setHashSymbol(node->left, SYMBOL_FUNCTION);
            /* PARAMS = VARIABLES
            node->left->right = PARAMS
            node->left->right->left = TYPENAME
            node->left->right->right = PARAMS
            node->left->right->right->left = TYPENAME
            node->left->right->right->right = PARAMS
            ...
            */
            if(node->left->right)
                for(AST* aux = node->left->right; aux != NULL; aux = aux->right)
                    setHashSymbol(aux, SYMBOL_VARIABLE);
            break;
        default: 
            break;
    }
    checkAndSetDeclarations(node->right);
}

void checkUndeclared()
{    
    int undeclaredSymbols = hashLookForSymbols(TK_IDENTIFIER);
    if(undeclaredSymbols)
    {
        fprintf(stderr, "Semantic Error: %d undeclared symbols!\n",undeclaredSymbols);
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
                node->left->right->symbol->type
            );
            semanticErrors++;
        }
        // updates type of hash node
        node->left->right->symbol->type = symbol;
        // updates datatype of hash node
        switch (node->left->left->type)
        {
            case INT:
                node->left->right->symbol->datatype = DATATYPE_INT;
                break;
            case CHAR:
                node->left->right->symbol->datatype = DATATYPE_CHAR;
                break;
            case BOOL:
                node->left->right->symbol->datatype = DATATYPE_BOOL;
                break;
            case REAL:
                node->left->right->symbol->datatype = DATATYPE_REAL;
                break;
            default:
                break;
        }
    }
}

int getSemanticErrors()
{
    return semanticErrors;
}

void checkOperands(AST* node)
{
    if(!node)
        return;
    if(node->left)
        checkOperands(node->left);
    switch (node->type)
    {
    case INPUT:                 
    case PARENTHESIS:           
    case ADD:                   
    case SUB:                   
    case MUL:                   
    case DIV:                   
    case LT:                    
    case GT:                    
    case GE :                   
    case LE :                   
    case EQ :                   
    case DIF:                   
    case AND:                   
    case NOT:                   
    case OR:                    
    case VECACC:
    case FUNCAPP:
        if(checkExpressionType(node) == DATATYPE_ERROR || checkExpressionType(node) == DATATYPE_STRING)
        {
            fprintf(stderr, "Semantic Error: invalid data type!\n");
            semanticErrors++;
        }
        break;
    case VARATTCMD:
        int left = checkExpressionType(node->left);
        int right = checkExpressionType(node->right);
        if(checkCompatibilityBetweenDataTypes(left, right) == DATATYPE_ERROR
        || checkCompatibilityBetweenDataTypes(left, right) == DATATYPE_STRING
        || node->left->symbol->type != SYMBOL_VARIABLE)
        {
            fprintf(stderr, "Semantic Error: invalid data type!\n");
            semanticErrors++;  
        }
        break;
    case OUTPUTCMD:
        if(node->left)
            for(AST* outputList = node->left; outputList != NULL; outputList = outputList->right)
            {
                int outputType = checkExpressionType(outputList->left);
                if(outputType == DATATYPE_ERROR)
                {
                    fprintf(stderr, "Semantic Error: invalid data type!\n");
                    semanticErrors++;                    
                }
            }
        break;
    case VECDEF:
        if(checkExpressionType(node) == DATATYPE_ERROR || checkExpressionType(node) == DATATYPE_STRING)
        {
            fprintf(stderr, "Semantic Error: invalid vector definition!\n");
            semanticErrors++;  
        }
        break;
    default:
        break;
    }
    if(node->right)
        checkOperands(node->right);
}

int checkExpressionType(AST* node)
{
    if(!node)
        return DATATYPE_ERROR;
    int left, right;
    switch (node->type)
    {
    case SYMBOL:
        return node->symbol->datatype;
        break;
    case TYPENAME: 
        return checkExpressionType(node->right);
        break;
    case INPUT:
        if(node->left)
            return astTypeToDataType(node->left->type);
        else
            return DATATYPE_ERROR;
        break;
    case PARENTHESIS:
        return checkExpressionType(node->left);
        break;
    // arithmetic operators
    case ADD:
    case SUB: 
    case MUL: 
    case DIV:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenArithmeticOperatorsDataTypes(left, right);
        break;
    ///////////////////////
    // comparation operators
    case LT:
    case GT:
    case GE :
    case LE :
    case EQ :
    case DIF:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenComparationOperatorsDataTypes(left, right);
        break;
    ////////////////////////
    // logic operators
    case AND:
    case NOT:
    case OR:
        left = checkExpressionType(node->left);
        right = checkExpressionType(node->right);
        return checkCompatibilityBetweenLogicOperatorsDataTypes(left, right);
        break;
    //////////////////
    case VECACC:
        if(node->right && node->right->type == VECATTCMD)
        {
            int vecType = checkExpressionType(node->left);
            int indexType = checkExpressionType(node->right->left);
            int valueType = checkExpressionType(node->right->right);
            if(
                (indexType == DATATYPE_INT || indexType == DATATYPE_CHAR)&&         
                (checkCompatibilityBetweenDataTypes(vecType, valueType))&&
                (vecType != DATATYPE_STRING)
            )
                return vecType;
            else
                return DATATYPE_ERROR;
        }
        else
        {
            right = checkExpressionType(node->right);
            if(right == DATATYPE_INT || right == DATATYPE_CHAR)
                return checkExpressionType(node->left);
            else
                return DATATYPE_ERROR;            
        }
        break;
    case VECDEF:
        if(node->left && node->right)
        {
            int vectorType = checkExpressionType(node->left);
            printf("vector type: %d\n",vectorType);
            if(node->right->left && checkCompatibilityBetweenDataTypes(checkExpressionType(node->right->left), DATATYPE_INT))
            {
                int vectorSize = atoi(node->right->left->symbol->text);
                fprintf(stderr, "\n\nvecsize = %d\n\n",vectorSize);
                if(node->right->right)
                {
                    int numberOfElements = 0;
                    for(AST* aux = node->right->right; aux != NULL; aux = aux->right)
                    {
                        numberOfElements++;
                        printf("-> %d\n", checkExpressionType(aux->left));
                        if(!checkCompatibilityBetweenDataTypes(vectorType, checkExpressionType(aux->left)))
                            return DATATYPE_ERROR;                        
                    }
                    if(numberOfElements != vectorSize)
                        return DATATYPE_ERROR;
                }
                return vectorType;
            }
            else
                return DATATYPE_ERROR;
        }
        else
            return DATATYPE_ERROR;
        break;
    case FUNCAPP:
        return checkExpressionType(node->left);
        break;
    default:
        break;
    }
}

int astTypeToDataType(int astType)
{
    switch (astType)
    {
    case INT:
        return DATATYPE_INT;
        break;
    case CHAR:
        return DATATYPE_CHAR;
        break;
    case REAL:
        return DATATYPE_REAL;
        break;
    case BOOL:
        return DATATYPE_BOOL;
        break;
    default:    
        break;
    }
    return DATATYPE_ERROR;
}

int     checkCompatibilityBetweenArithmeticOperatorsDataTypes(int dataType1, int dataType2)
{
    if((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return DATATYPE_INT;
    if(dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return DATATYPE_REAL;
    return DATATYPE_ERROR;
}
int     checkCompatibilityBetweenLogicOperatorsDataTypes(int dataType1, int dataType2)
{
    if (dataType1 == DATATYPE_BOOL && dataType2 == DATATYPE_BOOL)
        return DATATYPE_BOOL;
    else
        return DATATYPE_ERROR;
}
int     checkCompatibilityBetweenComparationOperatorsDataTypes(int dataType1, int dataType2) 
{
    if((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return DATATYPE_BOOL;
    if(dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return DATATYPE_BOOL;
    return DATATYPE_ERROR;
}

int     checkCompatibilityBetweenDataTypes(int dataType1, int dataType2) 
{
    printf("[%d, %d]\n", dataType1, dataType2);
    if((dataType1 == DATATYPE_INT || dataType1 == DATATYPE_CHAR) && (dataType2 == DATATYPE_INT || dataType2 == DATATYPE_CHAR))
        return TRUE;
    if(dataType1 == DATATYPE_REAL && dataType2 == DATATYPE_REAL)
        return TRUE;
    if (dataType1 == DATATYPE_BOOL && dataType2 == DATATYPE_BOOL)
        return TRUE;
    if(dataType1 == DATATYPE_STRING && dataType2 == DATATYPE_STRING)
        return TRUE;
    return FALSE;
}