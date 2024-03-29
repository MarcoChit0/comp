#include "asm.h"

static int labelCounter = 0;

void tacIntCompToASM(FILE *fptr, char *title, char *operation, TAC *tac)
{
    fprintf(fptr,
            "%s\n"
            "\tmovl	.%s(%%rip), %%edx\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\tcmpl	%%eax, %%edx\n"
            "\t%s	%%al\n"
            "\tmovzbl	%%al, %%eax\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            title,
            tac->operator1->text,
            tac->operator2->text,
            operation,
            tac->result->text);
}

void tacIntAritExpToASM(FILE *fptr, char *title, char *operation, TAC *tac)
{
    fprintf(fptr,
            "%s\n"
            "\tmovl	.%s(%%rip), %%edx\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\t%s	%%edx, %%eax\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            title,
            tac->operator1->text,
            tac->operator2->text,
            operation,
            tac->result->text);
}

void tacDivToASM(FILE *fptr, TAC *tac)
{
    fprintf(fptr,
            "## TAC_DIV: ##\n"
            "\tmovl .%s(%%rip), %%eax\n"
            "\tmovl	.%s(%%rip), %%ecx\n"
            "\tcltd\n"
            "\tidivl %%ecx\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            tac->operator1->text, tac->operator2->text, tac->result->text);
}

void tacSubToASM(FILE *fptr, TAC *tac)
{
    fprintf(fptr,
            "## TAC SUB: ##\n"
            "\tmovl .%s(%%rip), %%edx\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\tsubl	%%eax, %%edx\n"
            "\tmovl	%%edx, %%eax\n"
            "\tmovl	%%edx, .%s(%%rip)\n\n",
            tac->operator1->text, tac->operator2->text, tac->result->text);
}

void tacLabelToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC LABEL: ##\n"
        ".%s:\n\n",
        tac->result->text);
}

void tacJumpToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC JUMP: ##\n"
        "\tjmp	.%s\n\n",
        tac->result->text);
}

void tacJumpFalseToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC JUMP FALSE: ##\n"
        "\tmovl .%s(%%rip), %%eax\n"
        "\tcmpl $1, %%eax\n"
        "\tjne .%s\n\n",
        tac->operator1->text, tac->result->text);
}

void tacAndtoASM(FILE *fptr, TAC *tac)
{
    int L0 = labelCounter++;
    int L1 = labelCounter++;
    fprintf(fptr,
            "## TAC AND: ##\n"
            "\tmovl   .%s(%%rip), %%eax\n"
            "\ttestl  %%eax, %%eax\n"
            "\tje     LAND%d\n"
            "\tmovl   .%s(%%rip), %%eax\n"
            "\ttestl  %%eax, %%eax\n"
            "\tje     LAND%d\n"
            "\tmovl   $1, %%eax\n"
            "\tjmp    LAND%d\n"
            "\tLAND%d:\n"
            "\tmovl   $0, %%eax\n"
            "\tLAND%d:\n"
            "\tmovl   %%eax, .%s(%%rip)\n\n",
            tac->operator1->text,
            L0,
            tac->operator2->text,
            L0,
            L1,
            L0,
            L1,
            tac->result->text);
}

void tacOrToASM(FILE *fptr, TAC *tac)
{
    int L0 = labelCounter++;
    int L1 = labelCounter++;
    int L2 = labelCounter++;
    fprintf(fptr,
            "## TAC OR: ##\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\ttestl	%%eax, %%eax\n"
            "\tjne	LOR%d\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\ttestl	%%eax, %%eax\n"
            "\tje	LOR%d\n"
            "\tLOR%d:\n"
            "\tmovl	$1, %%eax\n"
            "\tjmp	LOR%d\n"
            "\tLOR%d:\n"
            "\tmovl	$0, %%eax\n"
            "\tLOR%d:\n"
            "\tmovl   %%eax, .%s(%%rip)\n\n",
            tac->operator1->text,
            L0,
            tac->operator2->text,
            L1,
            L0,
            L2,
            L1,
            L2,
            tac->result->text);
}

void tacNotToASM(FILE *fptr, TAC *tac)
{
    fprintf(fptr,
            "## TAC NOT: ##\n"
            "\tmovq	%%rsp, %%rbp\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\ttestl	%%eax, %%eax\n"
            "\tsete	%%al\n"
            "\tmovzbl	%%al, %%eax\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            tac->operator1->text,
            tac->result->text);
}

void tacFunctionBeginToASM(FILE *fptr, TAC *tac)
{
    if (strcmp(tac->result->text, "main") == 0)
        fprintf(fptr,
                "## TAC FUNCTION BEGIN: ##\n"
                "\t.globl	%s\n"
                "\t.type	%s, @function\n"
                "%s:\n"
                "\tpushq	%%rbp\n"
                "\tmovq	%%rsp, %%rbp\n\n",
                tac->result->text,
                tac->result->text,
                tac->result->text);
    else
        fprintf(fptr,
                "## TAC FUNCTION BEGIN: ##\n"
                "\t.globl	.%s\n"
                "\t.type	.%s, @function\n"
                ".%s:\n"
                "\tpushq	%%rbp\n"
                "\tmovq	%%rsp, %%rbp\n\n",
                tac->result->text,
                tac->result->text,
                tac->result->text);
}

void tacFunctionEndToASM(FILE *fptr)
{
    fprintf(fptr,
            "## TAC FUNCTION END: ##\n"
            "\tpopq	%%rbp\n"
            "\tret\n\n");
}

void tacPrintToASM(FILE *fptr, TAC *tac)
{
    if (tac->result->datatype == DATATYPE_STRING)
    {
        char *label = getLabel(tac->result->text);
        fprintf(fptr,
                "## TAC PRINT STRING: ##\n"
                "\tleaq	.%s(%%rip), %%rax\n"
                "\tmovq	%%rax, %%rsi\n"
                "\tleaq	.LSTRING(%%rip), %%rax\n"
                "\tmovq	%%rax, %%rdi\n"
                "\tmovl	$0, %%eax\n"
                "\tcall	printf@PLT\n\n",
                label);
    }
    else
        fprintf(fptr,
                "## TAC PRINT INT: ##\n"
                "\tmovl	.%s(%%rip), %%eax\n"
                "\tmovl	%%eax, %%esi\n"
                "\tleaq	.LINT(%%rip), %%rax\n"
                "\tmovq	%%rax, %%rdi\n"
                "\tmovl	$0, %%eax\n"
                "\tcall	printf@PLT\n\n",
                tac->result->text);
}

void tacMoveToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC MOVE: ##\n"
        "\tmovl	.%s(%%rip), %%eax\n"
        "\tmovl	%%eax, .%s(%%rip)\n\n",
        tac->operator1->text, tac->result->text);
}

void tacReturnToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC RETURN: ##\n"
        "\tmovl	.%s(%%rip), %%eax\n\n",
        tac->result->text);
}

int isDigit(char *str)
{
    for (int c = 0; c < strlen(str); c++)
        if (!isdigit(str[c]))
            return 0;
    return 1;
}

void tacVecAttToASM(FILE *fptr, TAC *tac)
{
    int digit = isDigit(tac->operator1->text) ? atoi(tac->operator1->text) : tac->operator1->text[0];
    fprintf(
        fptr,
        "## TAC VEC ATT: ##\n"
        "\tmovl	.%s(%%rip), %%eax\n"
        "\tmovl	%%eax, %d+.%s(%%rip)\n\n",
        tac->operator2->text,
        4 * digit,
        tac->result->text);
}

void tacVecAccToASM(FILE *fptr, TAC *tac)
{
    if (isDigit(tac->operator2->text))
        fprintf(
            fptr,
            "## TAC VEC ACC: ##\n"
            "\tmovl	%d+.%s(%%rip), %%eax\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            4 * atoi(tac->operator2->text),
            tac->operator1->text,
            tac->result->text);
    else
        fprintf(
            fptr,
            "## TAC VEC ACC: ##\n"
            "\tmovl	.%s(%%rip), %%eax\n"
            "\tcltq\n"
            "\tleaq	0(,%%rax,4), %%rdx\n"
            "\tleaq	.%s(%%rip), %%rax\n"
            "\tmovl	(%%rdx,%%rax), %%eax\n"
            "\tmovl	%%eax, .%s(%%rip)\n\n",
            tac->operator2->text,
            tac->operator1->text,
            tac->result->text);
}

void tacReadToASM(FILE *fptr, TAC *tac)
{
    switch (tac->result->datatype)
    {
    case DATATYPE_CHAR:
        fprintf(
            fptr,
            "## TAC READ: ##\n"
            "\tleaq	.%s(%%rip), %%rax\n"
            "\tmovq	%%rax, %%rsi\n"
            "\tleaq	.LCHAR(%%rip), %%rax\n"
            "\tmovq	%%rax, %%rdi\n"
            "\tmovl	$0, %%eax\n"
            "\tcall	__isoc99_scanf@PLT\n\n",
            tac->result->text);
        break;
    case DATATYPE_REAL:
    case DATATYPE_INT:
    default:
        fprintf(
            fptr,
            "## TAC READ: ##\n"
            "\tleaq	.%s(%%rip), %%rax\n"
            "\tmovq	%%rax, %%rsi\n"
            "\tleaq	.LINT(%%rip), %%rax\n"
            "\tmovq	%%rax, %%rdi\n"
            "\tmovl	$0, %%eax\n"
            "\tcall	__isoc99_scanf@PLT\n\n",
            tac->result->text);
        break;
    }
}

void tacFunctionCallToASM(FILE *fptr, TAC *tac)
{
    fprintf(
        fptr,
        "## TAC CALL: ##\n"
        "\tmovl $0, %%eax\n"
        "\tcall .%s\n"
        "\tmovl	%%eax, .%s(%%rip)\n\n",
        tac->operator1->text,
        tac->result->text);
}

void generateASM(TAC *tac)
{
    tacPrintBackwards(tac);
    FILE *fp = fopen("asm.s", "w");
    if (!fp)
    {
        fprintf(stderr, "Error when creating the asm file!\n");
        exit(7);
    }
    TAC *dataSection = NULL;
    TAC *t = tacReverse(tac);
    fprintf(
        fp,
        "## ASM CODE: ##\n\n"
        "## PRINT FUNCTIONS: ##\n"
        ".LINT:\n"
        "\t.string\t\"%%d\"\n"
        ".LSTRING:\n"
        "\t.string\t\"%%s\"\n"
        ".LCHAR:\n"
        "\t.string\t\"%%c\"\n\n");
    while (t)
    {
        printf("LOG: t = .%s\n", tacMap[t->type]);
        switch (t->type)
        {
        case TAC_SYMBOL:
        case TAC_BEGINBLOCK:
        case TAC_ENDBLOCK:
        case TAC_NOP:
            break;
        case TAC_ADD:
            tacIntAritExpToASM(fp, "## TAC ADD: ##", "addl", t);
            break;
        case TAC_SUB:
            tacSubToASM(fp, t);
            break;
        case TAC_MUL:
            tacIntAritExpToASM(fp, "## TAC MUL: ##", "imull", t);
            break;
        case TAC_DIV:
            tacDivToASM(fp, t);
            break;
        case TAC_GT:
            tacIntCompToASM(fp, "## TAC GT: ##", "setg", t);
            break;
        case TAC_GE:
            tacIntCompToASM(fp, "## TAC GE: ##", "setge", t);
            break;
        case TAC_LT:
            tacIntCompToASM(fp, "## TAC LT: ##", "setl", t);
            break;
        case TAC_LE:
            tacIntCompToASM(fp, "## TAC LE: ##", "setle", t);
            break;
        case TAC_EQ:
            tacIntCompToASM(fp, "## TAC EQ: ##", "sete", t);
            break;
        case TAC_DIF:
            tacIntCompToASM(fp, "## TAC DIF: ##", "setne", t);
            break;
        case TAC_AND:
            tacAndtoASM(fp, t);
            break;
        case TAC_OR:
            tacOrToASM(fp, t);
            break;
        case TAC_NOT:
            tacNotToASM(fp, t);
            break;
        case TAC_FUNCTIONBEGIN:
            tacFunctionBeginToASM(fp, t);
            break;
        case TAC_FUNCTIONEND:
            tacFunctionEndToASM(fp);
            break;
        case TAC_PRINT:
            tacPrintToASM(fp, t);
            break;
        case TAC_MOVE:
            tacMoveToASM(fp, t);
            break;
        case TAC_RETURN:
            tacReturnToASM(fp, t);
            break;
        case TAC_LABEL:
            tacLabelToASM(fp, t);
            break;
        case TAC_JMP:
            tacJumpToASM(fp, t);
            break;
        case TAC_JFALSE:
            tacJumpFalseToASM(fp, t);
            break;
        case TAC_VECATT:
            tacVecAttToASM(fp, t);
            break;
        case TAC_VECACC:
            tacVecAccToASM(fp, t);
            break;
        case TAC_FUNCTIONCALL:
            tacFunctionCallToASM(fp, t);
            break;
        case TAC_READ:
            tacReadToASM(fp, t);
            break;
        case TAC_SET_FALSE:
        {
            fprintf(
                fp,
                "## TAC SET FALSE: ##\n"
                "\tmovl   $0, %%eax\n"
                "\tmovl   %%eax, .%s(%%rip)\n\n",
                t->result->text);
        }
        break;
        case TAC_SET_TRUE:
        {
            fprintf(
                fp,
                "## TAC SET TRUE: ##\n"
                "\tmovl   $1, %%eax\n"
                "\tmovl   %%eax, .%s(%%rip)\n\n",
                t->result->text);
        }
        break;
        case TAC_VECDEFBEGIN:
        {
            if (!dataSection)
            {
                dataSection = t;
                while (dataSection->type != TAC_VECDEFEND)
                    dataSection = dataSection->next;

                t = dataSection->next;
                dataSection->next = NULL;
                goto _skipinc;
            }
            else
            {
                TAC *aux = t;
                dataSection->next = aux;
                dataSection = dataSection->next;
                for (; aux && aux->type != TAC_VECDEFEND; aux = aux->next)
                    dataSection = dataSection->next;

                t = aux->next;
                dataSection->next = NULL;
                goto _skipinc;
            }
        }
        break;
        default:
            break;
        }
        t = t->next;
    _skipinc:
    }
    // DATA SECTION
    hashToASM(fp);
    dataSection = tacReverse(dataSection);
    int vectorSize = 0;
    int startDefiningVector = 0;
    for (TAC *t = dataSection; t; t = t->next)
    {
        if (t->type == TAC_VECDEFBEGIN)
        {
            startDefiningVector = 1;
            vectorSize = atoi(t->operator1->text);
            fprintf(fp, ".%s:\n", t->result->text);
        }
        if (t->type == TAC_VECDEF && t->operator1)
        {
            vectorSize--;
            if (t->operator1->datatype == DATATYPE_REAL)
                fprintf(fp, "\t.long\t%d\n", (int)atof(t->operator1->text));

            if (t->operator1->datatype == DATATYPE_INT || t->operator1->datatype == DATATYPE_CHAR)
            {
                char *string = t->operator1->text;
                if ((int)string[0] - (int)'\'' == 0)
                {
                    // int, char <- char
                    fprintf(fp, "\t.long\t%d\n", string[1]);
                }
                else
                {
                    // int, char <- int
                    fprintf(fp, "\t.long\t%d\n", atoi(string));
                }
            }
        }
        if (t->type == TAC_VECDEFEND && startDefiningVector)
        {
            startDefiningVector = 0;
            while (vectorSize > 0)
            {
                fprintf(fp, "\t.long\t0\n");
                vectorSize--;
            }
        }
    }
    fclose(fp);
}