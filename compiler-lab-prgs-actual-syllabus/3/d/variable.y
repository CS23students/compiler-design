%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);

%}

%token LETTER DIGIT

%%
variable: LETTER rest { printf("Valid Variable\n"); }
rest: LETTER rest
    | DIGIT rest
    | /* empty */
    ;
%%

int main() {
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Variable\n");
    exit(0);
}
