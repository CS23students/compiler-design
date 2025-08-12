%{
#include <stdio.h>
%}

KEYWORD     (if|else|while|for|int|float|char|return)
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
NUMBER      [0-9]+
OPERATOR    (\+|\-|\*|\/|=|==|<=|>=|<|>)
SPECIAL     [\(\)\{\}\;\,]

%%
{KEYWORD}     { printf("Keyword: %s\n", yytext); }
{IDENTIFIER}  { printf("Identifier: %s\n", yytext); }
{NUMBER}      { printf("Number: %s\n", yytext); }
{OPERATOR}    { printf("Operator: %s\n", yytext); }
{SPECIAL}     { printf("Special Symbol: %s\n", yytext); }
[ \t\n]       ; // ignore whitespace
.             { printf("Unknown: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}


int a = 5;
if (a > 0) {
    a = a + 1;
}
Keyword: int
Identifier: a
Operator: =
Number: 5
Special Symbol: ;
Keyword: if
Special Symbol: (
Identifier: a
Operator: >
Number: 0
Special Symbol: )
Special Symbol: {
Identifier: a
Operator: =
Identifier: a
Operator: +
Number: 1
Special Symbol: ;
Special Symbol: }
