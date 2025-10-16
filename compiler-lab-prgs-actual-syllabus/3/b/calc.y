%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);

int result;
%}

%union {
    int ival;
}

%token <ival> NUM
%type <ival> expr

%left '+' '-'
%left '*' '/'

%%

input: expr { result = $1; }
    ;

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | '(' expr ')'  { $$ = $2; }
    | NUM           { $$ = $1; }
    ;

%%

int main() {
    printf("Enter expression: ");
    if (yyparse() == 0)
        printf("Result: %d\n", result);
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}
