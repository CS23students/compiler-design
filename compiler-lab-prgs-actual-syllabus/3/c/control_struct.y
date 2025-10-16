%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%expect 1

%token IF ELSE WHILE FOR SWITCH CASE DEFAULT ID NUM RELOP

%%

stmt: ifstmt
    | whilestmt
    | forstmt
    | switchstmt
    | assign ';'
    | '{' stmts '}'
    ;

stmts: /* empty */
     | stmts stmt
     ;

ifstmt: IF '(' cond ')' stmt
      | IF '(' cond ')' stmt ELSE stmt
      ;

whilestmt: WHILE '(' cond ')' stmt
         ;

forstmt: FOR '(' assign ';' cond ';' assign ')' stmt
       ;

switchstmt: SWITCH '(' ID ')' '{' cases '}'
          ;

cases: CASE NUM ':' stmt cases
     | DEFAULT ':' stmt
     | /* empty */
     ;

cond: ID RELOP ID
    | ID RELOP NUM
    ;

assign: ID '=' NUM
      | ID '=' ID
      ;

%%

int main() {
    printf("Enter a control structure: ");
     if (yyparse() == 0) {
        printf("Valid Syntax\n");
    }
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Syntax\n");
    exit(0);
}
