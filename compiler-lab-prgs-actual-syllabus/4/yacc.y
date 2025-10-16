%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 0;

char* newTemp() {
    char *temp = (char*)malloc(5);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

int yylex(void);
int yyerror(char *s);

%}

%union { char* str; }
%token <str> ID NUM
%type <str> expr

%left '+' '-'
%left '*' '/'

%%

stmt: expr { printf("Result in %s\n", $1); }
;

expr: expr '+' expr { 
          char* t = newTemp();
          printf("%s = %s + %s\n", t, $1, $3);
          $$ = t;
      }
    | expr '-' expr {
          char* t = newTemp();
          printf("%s = %s - %s\n", t, $1, $3);
          $$ = t;
      }
    | expr '*' expr {
          char* t = newTemp();
          printf("%s = %s * %s\n", t, $1, $3);
          $$ = t;
      }
    | expr '/' expr {
          char* t = newTemp();
          printf("%s = %s / %s\n", t, $1, $3);
          $$ = t;
      }
    | ID   { $$ = $1; }
    | NUM  { $$ = $1; }
;

%%

int main() {
    printf("Enter an expression: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Error: %s\n", s);
    return 0;
}