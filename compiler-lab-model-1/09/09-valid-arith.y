%{
#include <stdio.h>
#include <stdlib.h>


int yylex(void);
int yyerror(char *s);

%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
input:
    expr { printf("Valid Expression\n"); }
    ;
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUM
    ;
%%

int main() {
    printf("Enter an arithmetic expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Expression\n");
    exit(0);
}
