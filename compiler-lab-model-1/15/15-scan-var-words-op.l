//15. Write a lex program to scan variables, reserved words and operators of clang

%{
#include <stdio.h>
#include <string.h>

void print_token(const char *type, const char *val) {
    printf("%-15s : %s\n", type, val);
}
%}

/* Definitions */
KEYWORD     int|float|double|char|if|else|for|while|return|void
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
NUMBER      [0-9]+(\.[0-9]+)?
OPERATOR    "=="|"!="|"<="|">="|"+"|"-"|"*"|"/"|"%"
WHITESPACE  [ \t\n]+

%%

{KEYWORD}       { print_token("Keyword", yytext); }
{IDENTIFIER}    { print_token("Identifier", yytext); }
{NUMBER}        { print_token("Number", yytext); }
{OPERATOR}      { print_token("Operator", yytext); }
{WHITESPACE}    ;   // ignore whitespace
.               { /* ignore other characters */ }

%%

int yywrap() { return 1; }

int main() {
    printf("Scanning C code:\n\n");
    yylex();
    return 0;
}


//Scanning C code:

//int a = 5;
//Keyword         : int
//Identifier      : a
//Number          : 5

//float b;
//Keyword         : float
//Identifier      : b

//if(a > 0) b = a * 2;
//Keyword         : if
//Identifier      : a
//Number          : 0
//Identifier      : b
//Identifier      : a
//Operator        : *
//Number          : 2