//1. Develop a program to recognise a valid control structure syntax of c lang - for loop, while, if...else if...else if, switch, do...while.


%{
#include <stdio.h>
#include <string.h>

char line[256];
int pos = 0;
int matched = 0;

void check_invalid() {
    if (!matched && pos > 0) {
        line[pos] = '\0';
        printf("Invalid control structure: %s\n", line);
    }
    matched = 0;
    pos = 0;
}

void print_match(const char *type) {
    printf("Valid control structure: %s\n", type);
    matched = 1;
}
%}

/* ---------- PATTERN DEFINITIONS ---------- */
FOR_LOOP        "for"[ \t]*"("[^)]*")"[ \t]*\{[^}]*\}?
WHILE_LOOP      "while"[ \t]*"("[^)]*")"[ \t]*\{[^}]*\}?
DO_WHILE_LOOP   "do"[ \t]*\{[^}]*\}[ \t\n]*"while"[ \t]*"("[^)]*")"
IF_BLOCK        "if"[ \t]*"("[^)]*")"[ \t]*\{[^}]*\}?
ELSE_IF_BLOCK   "else"[ \t]*"if"[ \t]*"("[^)]*")"[ \t]*\{[^}]*\}?
ELSE_BLOCK      "else"[ \t]*\{[^}]*\}?
SWITCH_BLOCK    "switch"[ \t]*"("[^)]*")"[ \t]*\{[^}]*\}?

%%

{FOR_LOOP}        { print_match("for loop"); }
{WHILE_LOOP}      { print_match("while loop"); }
{DO_WHILE_LOOP}   { print_match("do-while loop"); }
{IF_BLOCK}        { print_match("if statement"); }
{ELSE_IF_BLOCK}   { print_match("else-if statement"); }
{ELSE_BLOCK}      { print_match("else statement"); }
{SWITCH_BLOCK}    { print_match("switch statement"); }

\n                { check_invalid(); }
[^\n]             { if (pos < 255) line[pos++] = yytext[0]; }  // store input text
[ \t]+            ;  // ignore extra spaces

%%

int yywrap() { check_invalid(); return 1; }

int main() {
    printf("Enter C control structures (Ctrl+D to stop):\n");
    yylex();
    return 0;
}


//Enter C control structures (Ctrl+D to stop):
//for(i=0;i<10;i++) { printf("%d", i); }
//Valid control structure: for loop
//if(a>b) { a=b; }
//Valid control structure: if statement
//hello world
//Invalid control structure: hello world
//do { x++; } while(x<10);
//Valid control structure: do-while loop
//switch(op) { case 1: break; }
//Valid control structure: switch statement
//for(i=0;i<10;i++
//Invalid control structure: for(i=0;i<10;i++