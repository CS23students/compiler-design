//9.	Use Lex tool to recognize a valid arithmetic expression with operators +, -, *, /.

%{
#include "09-valid-arith.tab.h"
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUM; }
[\+\-\*/\(\)]   { return yytext[0]; }
[ \t\n]    ; // ignore whitespace
.          { return 0; }
%%

int yywrap() { return 1; }



//Enter an arithmetic expression: a+b
//Invalid Expression

//Enter an arithmetic expression: 5+2*5
//Valid Expression