%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%token VAR
%token INVALID
%union {
    char* str;
}
%type <str> VAR

%%

input:
      /* empty */
    | input line
    ;

line:
      VAR     { printf("Valid variable: %s\n", $1); free($1); }
    | INVALID { printf("Invalid variable\n"); }
    ;

%%

int main() {
    printf("Enter variables (Ctrl+D to stop):\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid variable\n");
}
