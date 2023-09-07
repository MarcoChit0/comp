#include "hash.h"

HashNode *Table[HASHSIZE];

void hashInit()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        Table[i] = NULL;
    }
}

HashNode *hashInsert(char *text, int type)
{
    HashNode *newnode;
    newnode = hashFind(text);
    if (newnode != NULL)
    {
        return newnode;
    }
    newnode = (HashNode *)calloc(1, sizeof(HashNode));
    int address = hashAddress(text);
    newnode->type = type;
    newnode->datatype = NODATATYPE;
    newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
    newnode->content = NULL;
    strcpy(newnode->text, text);
    newnode->next = Table[address];
    Table[address] = newnode;
    return newnode;
}

HashNode *hashInsertWithDataType(char *text, int type, int datatype)
{
    HashNode *newnode;
    newnode = hashFind(text);
    if (newnode != NULL)
    {
        return newnode;
    }
    newnode = (HashNode *)calloc(1, sizeof(HashNode));
    int address = hashAddress(text);
    newnode->type = type;
    newnode->datatype = datatype;
    newnode->content = NULL;
    newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = Table[address];
    Table[address] = newnode;
    return newnode;
}

int hashAddress(char *text)
{
    int address = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        address = ((address * text[i]) % HASHSIZE) + 1;
    }

    return address - 1;
}

void hashPrint()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        for (HashNode *node = Table[i]; node; node = node->next)
        {
            printf("Table[%d] = {%s}, with type = {%d} and datatype = {%d}.\n", i, node->text, node->type, node->datatype);
        }
    }
}

HashNode *hashFind(char *text)
{
    int address = hashAddress(text);
    HashNode *node;
    for (node = Table[address]; node; node = node->next)
    {
        if (strcmp(node->text, text) == 0)
            return node;
    }
    return NULL;
}

int isRunning(void)
{
    return running;
}

void initMe()
{
    hashInit();
    lineNumber = 1;
    running = 1;
}

int getLineNumber()
{
    return lineNumber;
}

void removeChar(char *str, char c)
{
    int existsChar = 1, charPos = -1;
    while (existsChar)
    {
        existsChar = 0;
        for (int i = 0; i < strlen(str); ++i)
        {
            if (str[i] == c)
            {
                existsChar = 1;
                charPos = i;
                break;
            }
        }
        if (existsChar)
        {
            memmove(
                &str[charPos],
                &str[charPos + 1],
                strlen(str) - charPos);
        }
    }
}

int hashLookForSymbols(int symbolType)
{
    int symbols = 0;
    for (int i = 0; i < HASHSIZE; i++)
    {
        for (HashNode *node = Table[i]; node; node = node->next)
        {
            if (node->type == symbolType)
            {
                symbols++;
                fprintf(stderr, "Symbol [%s, %d] found!\n", node->text, node->type);
            }
        }
    }
    return symbols;
}

HashNode *makeTemp()
{
    static int temps = 0;
    char buffer[255] = "";
    sprintf(buffer, "temp_%d", temps++);
    return hashInsert(buffer, SYMBOL_TEMP);
}

HashNode *makeLabel()
{
    static int labels = 0;
    char buffer[255] = "";
    sprintf(buffer, "label_%d", labels++);
    return hashInsert(buffer, SYMBOL_LABEL);
}

char *strRemove(char *str, const char *sub) {
    size_t len = strlen(sub);
    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
    return str;
}

char* getLabel(char* str)
{
    int hashValue = hashAddress(str);
    int pos = 0;
    for(HashNode* h = Table[hashValue]; h; h = h->next)
    {   
        if(strcmp(str, h->text) == 0)
            break;
        else
            pos ++;
    }
    char* buffer = (char*) calloc(256, sizeof(char*));
    sprintf(buffer, "label_%d_%d", hashValue, pos);
    return buffer;
}


void hashToASM(FILE *fp)
{
    fprintf(
        fp,
        "## DATA SECTION: ##\n"
        "\t.data\n");
    for (int i = 0; i < HASHSIZE; i++)
    {
        for (HashNode *node = Table[i]; node; node = node->next)
        {
            if (node->type == SYMBOL_TEMP)
                fprintf(
                    fp,
                    ".%s:\n"
                    "\t.long\t0\n",
                    node->text);
            else if (node->type == SYMBOL_VARIABLE)
            {
                fprintf(fp, ".%s:\n", node->text);
                switch (node->datatype)
                {
                case DATATYPE_INT:
                case DATATYPE_BOOL:
                case DATATYPE_CHAR:
                    if (!node->content)
                        // int, char, bool <- undefined
                        fprintf(fp, "\t.long\t0\n");
                    else
                    {
                        char *string = node->content->text;
                        if ((int)string[0] - '\'' == 0)
                        {
                            // int, char, bool <- char
                            removeChar(string, '\'');
                            fprintf(fp, "\t.long\t%d\n", string[0]);
                        }
                        else
                        {
                            // int, char, bool <- int
                            fprintf(fp, "\t.long\t%d\n", atoi(string));
                        }
                    }
                    break;
                case DATATYPE_REAL:
                    fprintf(fp, "\t.long\t%d\n", node->content ? (int)atof(node->content->text) : 0);
                    break;
                default:
                    break;
                }
            }
            else if (node->datatype == DATATYPE_STRING)
            {
                char *label = getLabel(node->text);
                fprintf(
                    fp,
                    ".%s:\n"
                    "\t.string\t%s\n",
                    label,
                    node->text);
            }
            else if (node->type == SYMBOL_CONST && node->datatype == DATATYPE_INT)
            {
                fprintf(
                    fp,
                    ".%s:\n"
                    "\t.long\t%d\n",
                    node->text,
                    atoi(node->text)
                );
            }
            else if(node->type == SYMBOL_CONST && node->type == DATATYPE_CHAR)
            {
                char* string =  node->text;
                // int, char, bool <- char
                removeChar(string, '\'');
                fprintf(
                    fp,
                    ".%d:\n" 
                    "\t.long\t%d\n",
                    string[0], 
                    string[0]
                );
            }
            else if(node->type == SYMBOL_CONST && node->type == DATATYPE_REAL)
            {
                int ireal = (int) atof(node->text);
                char str[256];
                sprintf(str, "%d", ireal);
                HashNode* f = hashFind(str);
                if(!f)
                {
                    fprintf(
                        fp,
                        ".%d:\n" 
                        "\t.long\t%d\n",
                        ireal, 
                        ireal
                    );
                }
            }
        }
    }
}