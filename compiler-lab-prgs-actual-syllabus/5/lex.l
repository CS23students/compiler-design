%{
#include "yacc.tab.h"
%}

%%
[0-9]+\.[0-9]+    { yylval.dtype = 2; return FLOAT; }
[0-9]+            { yylval.dtype = 1; return INT; }
[a-zA-Z][a-zA-Z0-9]* { yylval.dtype = 1; return ID; }
[\+\-\*/]         { return yytext[0]; }
[ \t\n]           { /* ignore whitespace */ }
.                 { return yytext[0]; }

%%

int yywrap() { return 1; }