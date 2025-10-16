%{
#include "arith_expr.tab.h"
%}

%%
[0-9]+     { yylval = atoi(yytext); return NUM; }
[\+\-\*/\(\)]   { return yytext[0]; }
[ \t\n]    ; // ignore whitespace
.          { return 0; }
%%

int yywrap() { return 1; }
