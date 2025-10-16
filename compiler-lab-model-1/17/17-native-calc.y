%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    double num;
}

%token <num> NUMBER

%type <num> expr term factor

%%

input:
      /* empty */
    | input line
    ;

line:
      '\n'
    | expr '\n' { printf("Result = %lf\n", $1); }
    ;

expr:
      expr '+' term { $$ = $1 + $3; }
    | expr '-' term { $$ = $1 - $3; }
    | term          { $$ = $1; }
    ;

term:
      term '*' factor { $$ = $1 * $3; }
    | term '/' factor { $$ = $1 / $3; }
    | factor          { $$ = $1; }
    ;

factor:
      NUMBER       { $$ = $1; }
    | '(' expr ')' { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter expressions (Ctrl+D to exit):\n");
    yyparse();
    return 0;
}
