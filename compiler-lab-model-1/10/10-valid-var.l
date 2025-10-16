//10. Design a pgm to recognize a valid variable that starts with an alphabet followed by any no. of digits alphabets using yacc tool.

%{
#include "10-valid-var.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[A-Za-z][A-Za-z0-9]*    { yylval.str = strdup(yytext); return VAR; }
[ \t\n]+                ;    // ignore whitespace
[A-Za-z0-9]+            { return INVALID; }  // whole invalid token
.                       { return INVALID; }  // any single invalid character

%%

int yywrap() { return 1; }


//Enter variables (Ctrl+C to stop):
//213
//Invalid variable
//Ab12
//Valid variable: Ab12
//12V
//Invalid variable
//A12
//Valid variable: A12
//abc123
//Valid variable: abc123
//1abc
//Invalid variable
