//12. Generate a valid pattern that recognises all stmts that begins with an uppercase letter followed by five digits or alphabet use yacc tool to do the same


%{
#include "12-statement-valid-dig-alph.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[A-Z][a-zA-Z0-9]{5}   { yylval.str = strdup(yytext); return STMT; }
[A-Za-z0-9]+           { return INVALID; }   // treat whole word as invalid
[ \t\n]+               ;   // ignore whitespace
.                      { return INVALID; }   // single chars also invalid

%%

int yywrap() { return 1; }


//Enter statements (Ctrl+C to stop):
//asdasad
//Invalid statement
//ABCDE
//Invalid statement
//Ab1123
//Valid statement: Ab1123
//AbCd12
//Valid statement: AbCd12
//A1234
//Invalid statement
//ABCDEF
//Valid statement: ABCDEF
//A1234
//Invalid statement
//A12345
//Valid statement: A12345