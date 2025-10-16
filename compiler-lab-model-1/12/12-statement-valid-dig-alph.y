%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%token STMT
%token INVALID
%union {
    char* str;
}
%type <str> STMT

%%

input:
    | input line
    ;

line:
      STMT    { printf("Valid statement: %s\n", $1); free($1); }
    | INVALID { printf("Invalid statement\n"); }
    ;

%%

int main() {
    printf("Enter statements (Ctrl+D to stop):\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid statement\n");
}
