//10.Design a program using Lex tool to validate a variable name starting with an alphabet followed by any number of digits or alphabets.

%{
#include <stdio.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]*   { printf("Valid Variable: %s\n", yytext); }
\n                      { /* ignore newline */ }
.                       { printf("Invalid Variable\n"); return 0; }
%%

int yywrap() { return 1; }

int main() {
    printf("Enter variable: ");
    yylex();
    return 0;
}




//Enter variable: abc
//Valid Variable: abc

//Enter variable: 1abc
//Invalid Variable
