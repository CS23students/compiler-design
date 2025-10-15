//13. Define a lexical analyzer that identifies commands, arithmetic operators and keywords from a given expression.
%{
#include <stdio.h>
#include <string.h>
%}

KEYWORD   int|float|char|double|if|else|while|for|return

ARITH_OP  \+|\-|\*|\/
REL_OP    <=|>=|==|!=|<|>
ASSIGN_OP =

ID        [a-zA-Z_][a-zA-Z0-9_]*

%%

{KEYWORD}      { printf("Keyword: %s\n", yytext); }
{ARITH_OP}     { printf("Arithmetic Operator: %s\n", yytext); }
{REL_OP}       { printf("Relational Operator: %s\n", yytext); }
{ASSIGN_OP}    { printf("Assignment Operator: %s\n", yytext); }
{ID}           { printf("Identifier/Command: %s\n", yytext); }
[0-9]+         { printf("Constant: %s\n", yytext); }
[ \t\n]+       { /* ignore whitespace */ }
.              { /* ignore other characters */ }

%%

int yywrap() { return 1; }

int main() {
    printf("Enter an expression: ");
    yylex();
    return 0;
}


//Enter an expression: int a = b + 10;
//Keyword: int
//Identifier/Command: a
//Assignment Operator: =
//Identifier/Command: b
//Arithmetic Operator: +
//Constant: 10

//if(a >= 5)
//Keyword: if
//Identifier/Command: a
//Relational Operator: >=
//Constant: 5
