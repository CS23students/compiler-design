// 5. Design a top down parser which generates a parsing table with no backtracking

#include <stdio.h>
#include <string.h>

#define MAX 50

// Terminals and Non-terminals
char terminals[][3] = {"id", "+", "*", "(", ")", "$"};
char nonTerminals[][3] = {"E", "E'", "T", "T'", "F"};

char* table[5][6];  // Parsing table

// Map symbols to indexes
int getNTIndex(char* nt) {
    for(int i=0;i<5;i++) if(strcmp(nonTerminals[i],nt)==0) return i;
    return -1;
}
int getTIndex(char* t) {
    for(int i=0;i<6;i++) if(strcmp(terminals[i],t)==0) return i;
    return -1;
}

// Initialize LL(1) parsing table
void initTable() {
    for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
            table[i][j] = NULL;

    table[getNTIndex("E")][getTIndex("id")] = "T E'";
    table[getNTIndex("E")][getTIndex("(")] = "T E'";

    table[getNTIndex("E'")][getTIndex("+")] = "+ T E'";
    table[getNTIndex("E'")][getTIndex(")")] = "#";
    table[getNTIndex("E'")][getTIndex("$")] = "#";

    table[getNTIndex("T")][getTIndex("id")] = "F T'";
    table[getNTIndex("T")][getTIndex("(")] = "F T'";

    table[getNTIndex("T'")][getTIndex("*")] = "* F T'";
    table[getNTIndex("T'")][getTIndex("+")] = "#";
    table[getNTIndex("T'")][getTIndex(")")] = "#";
    table[getNTIndex("T'")][getTIndex("$")] = "#";

    table[getNTIndex("F")][getTIndex("id")] = "id";
    table[getNTIndex("F")][getTIndex("(")] = "( E )";
}

// Print parsing table
void printTable() {
    printf("Parsing Table:\n");
    printf("%-5s","NT/T");
    for(int j=0;j<6;j++) printf("%-10s", terminals[j]);
    printf("\n");
    for(int i=0;i<5;i++){
        printf("%-5s", nonTerminals[i]);
        for(int j=0;j<6;j++){
            if(table[i][j]) printf("%-10s", table[i][j]);
            else printf("%-10s", "-");
        }
        printf("\n");
    }
}

// Simple stack
char stack[MAX][10];
int top=-1;
void push(char* s){ strcpy(stack[++top], s);}
char* pop(){ return stack[top--];}
char* peek(){ return stack[top];}

int main() {
    char input[100];
    initTable();
    printTable();

    printf("\nEnter input string (tokens separated by space, end with $):\n");
    fgets(input,sizeof(input),stdin);

    // Tokenize input
    char tokens[20][10];
    int tokenCount=0;
    char* tok = strtok(input," \n");
    while(tok){ strcpy(tokens[tokenCount++],tok); tok=strtok(NULL," \n"); }

    // Initialize stack
    push("$");
    push("E");

    int i=0;
    printf("\n%-30s%-30s%-20s\n", "Stack", "Input", "Action");
    while(top>=0){
        char* X = peek();
        char* a = tokens[i];
        printf("%-30s%-30s", X, a);

        if(strcmp(X,a)==0){ // match terminal
            pop(); i++;
            printf("%-20s\n","Match terminal");
        }
        else if(getNTIndex(X)!=-1){ // non-terminal
            int r=getNTIndex(X), c=getTIndex(a);
            char* prod = table[r][c];
            if(prod==NULL){
                printf("%-20s\n","Error! No rule");
                return 0;
            }
            pop();
            if(strcmp(prod,"#")!=0){  // # represents epsilon
                char tempProd[50];
                strcpy(tempProd, prod); // copy to avoid modifying literal
                char temp[20][10]; int k=0;
                char* t = strtok(tempProd," ");
                while(t){ strcpy(temp[k++],t); t=strtok(NULL," "); }
                for(int j=k-1;j>=0;j--) push(temp[j]);
            }
            printf("%-20s\n", prod);
        }
        else{
            printf("%-20s\n","Error! Unexpected symbol");
            return 0;
        }
    }

    if(strcmp(tokens[i-1],"$")==0)
        printf("\nInput ACCEPTED by grammar.\n");
    else
        printf("\nInput REJECTED.\n");

    return 0;
}


// only for this input: id + id * id $ and this production rules 
// will not work for other inputs or grammars
// Parsing Table:
// NT/T id        +         *         (         )         $
// E    T E'      -         -         T E'      -         -
// E'   -         + T E'    -         -         #         #
// T    F T'      -         -         F T'      -         -
// T'   -         #         * F T'    -         #         #
// F    id        -         -         ( E )     -         -

// Enter input string (tokens separated by space, end with $):
// id + id * id $

// Stack                         Input                         Action
// E                             id                            T E'
// T                             id                            F T'
// F                             id                            id
// id                            id                            Match terminal
// T'                            +                             #
// E'                            +                             + T E'
// +                             +                             Match terminal
// T                             id                            F T'
// F                             id                            id
// id                            id                            Match terminal
// T'                            *                             * F T'
// *                             *                             Match terminal
// F                             id                            id
// id                            id                            Match terminal
// T'                            $                             #
// E'                            $                             #
// $                             $                             Match terminal

// Input ACCEPTED by grammar.
