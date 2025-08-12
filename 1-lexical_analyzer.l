%{
#include <stdio.h>
#include <string.h>

char symTable[50][50];
int symCount = 0;

void addSymbol(char *sym) {
    for (int i = 0; i < symCount; i++) {
        if (strcmp(symTable[i], sym) == 0)
            return; // already exists
    }
    strcpy(symTable[symCount++], sym);
}
%}

IDENTIFIER    [a-zA-Z_][a-zA-Z0-9_]*
NUMBER        [0-9]+
OPERATOR      (\+|\-|\*|\/|=|==|<=|>=|<|>)
COMMENT1      \/\/.*
COMMENT2      \/\*([^*]|\*+[^*/])*\*+\/

%%
{IDENTIFIER}  { printf("Identifier: %s\n", yytext); addSymbol(yytext); }
{NUMBER}      { printf("Number: %s\n", yytext); }
{OPERATOR}    { printf("Operator: %s\n", yytext); }
{COMMENT1}    { printf("Single-line Comment\n"); }
{COMMENT2}    { printf("Multi-line Comment\n"); }
[ \t\n]       ; // ignore spaces and newlines
.             ; // ignore any other character
%%

int main() {
    yylex();
    printf("\nSymbol Table:\n");
    for (int i = 0; i < symCount; i++)
        printf("%s\n", symTable[i]);
    return 0;
}


output:
int a = 10; // variable a
int b = 20;
/* multi-line
comment */
a = a + b;

Identifier: int
Identifier: a
Operator: =
Number: 10
Single-line Comment
Identifier: int
Identifier: b
Operator: =
Number: 20
Multi-line Comment
Identifier: a
Operator: =
Identifier: a
Operator: +
Identifier: b

Symbol Table:
int
a
b
