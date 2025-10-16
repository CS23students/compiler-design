%{
    #include <stdio.h>
    #include <string.h>
    char symTable[50][50];

    int symCount=0;
    void addSymbol(char *sym){
        for(int i=0;i<symCount;i++){
            if(strcmp(symTable[i],sym)==0) return;
        } 
        strcpy(symTable[symCount++],sym);
    }
%}

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER [0-9]+
OPERATOR (\+|\-|\*|\/|=|==|<=|>=|<|>)
COMMENT1 \/\/.*
COMMENT2 \/\*([^*]|\*+[^*/])*\*+\/

%%

{IDENTIFIER} {printf("Identifier: %s\n", yytext); addSymbol(yytext);}
{NUMBER}     {printf("Number: %s\n",yytext);}
{OPERATOR}   {printf("Operator: %s\n",yytext);}
{COMMENT1}   {printf("Single Line Comment\n");}
{COMMENT2}   {printf("Multi-line comment\n");}
[\t\n]       {}
.            {}
%%

int yywrap() {
    return 1;
}

int main(){
    yylex();
    printf("\nSymbol Table:\n");
    for(int i=0;i<symCount;i++)
        printf("%s\n",symTable[i]);
    return 0;
}
