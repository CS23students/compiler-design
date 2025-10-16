//  17. Use lex and yacc tool to implement a native calc

%{
#include "17-native-calc.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+(\.[0-9]+)?   { yylval.num = atof(yytext); return NUMBER; }
[ \t]+               ;  // ignore spaces and tabs only
\n                   { return '\n'; } // return newline to Yacc
"+"                  { return '+'; }
"-"                  { return '-'; }
"*"                  { return '*'; }
"/"                  { return '/'; }
"("                  { return '('; }
")"                  { return ')'; }
.                    { return yytext[0]; }

%%

int yywrap() { return 1; }


//Enter expressions (Ctrl+D to exit):
//3-4
//Result = -1.000000
//1+2*223-100
//Result = 347.000000
//100+200*1
//Result = 300.000000
//1+2+3+4+5+6+7+8+9
//Result = 45.000000