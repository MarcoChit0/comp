#ifndef SEMANTICHEADER
#define SEMANTICHEADER

#include "hash.h"
#include "ast.h"
#include "y.tab.h"

#define TRUE 1
#define FALSE 0

extern int semanticErrors;

void    checkAndSetDeclarations(AST *node, AST *top);
void    checkUndeclared();
void    setHashSymbol(AST *node, int symbol);
int     getSemanticErrors();
void    checkOperands(AST* node);
int     checkExpressionType(AST* node);
int     astTypeToDataType(int);
int     checkCompatibilityBetweenArithmeticOperatorsDataTypes(int dataType1, int dataType2);
int     checkCompatibilityBetweenComparationOperatorsDataTypes(int dataType1, int dataType2);
int     checkCompatibilityBetweenLogicOperatorsDataTypes(int dataType1, int dataType2);
int     checkCompatibilityBetweenDataTypes(int dataType1, int dataType2); 
AST*    findFunctionDefinition(AST* node, char* function);
int     checkFunctionHeader(AST* header, char* function);
AST*    findFunctionHeader(AST* node, char* function);
#endif