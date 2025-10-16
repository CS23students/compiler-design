%{
    #include <stdio.h>
%}

KEYWORD (if|else|while|for|int|float|char|return)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER [0-9]+
OPERATOR (\+|\-|\*|\/|==|<=|>=|<|>|=)
SPECIAL [\(\)\{\}\;/,]

%%

{KEYWORD}    {printf("Keyword: %s\n",yytext);}
{IDENTIFIER} {printf("Identifier: %s\n",yytext);}
{NUMBER}     {printf("Number: %s\n",yytext);}
{OPERATOR}   {printf("Operator: %s\n",yytext);}
{SPECIAL}    {printf("Special Symbol: %s\n",yytext);}
[ \t\n]     ;  // Ignore whitespace and newline
.           {printf("Unknown: %s\n",yytext);}

%%

int yywrap() {
    return 1;
}

int main(){
    yylex();
    return 0;
}
