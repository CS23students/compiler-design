%{
#include <stdio.h>
#include <stdlib.h>

int resultType; // 1 = int, 2 = float


int yylex(void);
int yyerror(char *s);

%}

%union { int dtype; }
%token <dtype> INT FLOAT
%token ID
%type <dtype> expr

%left '+' '-'
%left '*' '/'

%%

stmt: expr { 
        if ($1 == 1) printf("Valid Expression. Type = int\n");
        else if ($1 == 2) printf("Valid Expression. Type = float\n");
     }
;

expr: expr '+' expr {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
     }
    | expr '-' expr {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
     }
    | expr '*' expr {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
     }
    | expr '/' expr {
        $$ = 2; // division always float
     }
    | INT   { $$ = 1; }
    | FLOAT { $$ = 2; }
    | ID    { $$ = 1; }  // assume identifiers are int for simplicity
;

%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Type Error: %s\n", s);
    return 0;
}