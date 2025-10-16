// 18. Design a program to generate 3-add code from given arith exp

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int tempCount = 1;

// Forward declaration
char* generateTAC(char* expr, int start, int end);

// Find the main operator in expr[start..end] (lowest precedence)
int findMainOp(char* expr, int start, int end) {
    int minPrec = 10, pos = -1, paren = 0;
    for(int i=start; i<=end; i++) {
        if(expr[i]=='(') paren++;
        else if(expr[i]==')') paren--;
        else if(paren==0) {
            int prec = -1;
            if(expr[i]=='+' || expr[i]=='-') prec = 1;
            else if(expr[i]=='*' || expr[i]=='/') prec = 2;
            if(prec != -1 && prec <= minPrec) {  // Rightmost for same prec
                minPrec = prec;
                pos = i;
            }
        }
    }
    return pos;
}

// Generate TAC recursively
char* generateTAC(char* expr, int start, int end) {
    while(expr[start]=='(' && expr[end]==')') { start++; end--; } // strip parentheses

    int opPos = findMainOp(expr, start, end);
    if(opPos == -1) {
        // single variable or number
        char* res = (char*)malloc(end-start+2);
        strncpy(res, expr+start, end-start+1);
        res[end-start+1] = '\0';
        return res;
    }

    char* left = generateTAC(expr, start, opPos-1);
    char* right = generateTAC(expr, opPos+1, end);

    char* temp = (char*)malloc(5);
    sprintf(temp, "t%d", tempCount++);
    printf("%s = %s %c %s\n", temp, left, expr[opPos], right);

    free(left);
    free(right);
    return temp;
}

int main() {
    char expr[100];
    printf("Enter arithmetic expression: ");
    scanf("%s", expr);

    printf("\nThree-Address Code:\n");
    generateTAC(expr, 0, strlen(expr)-1);

    return 0;
}


// Enter arithmetic expression: a+b*c

// Three-Address Code:
// t1 = b * c
// t2 = a + t1

// D:\compiler-lab-model-1\18>18-TAC.exe
// Enter arithmetic expression: a+b-c*d/e

// Three-Address Code:
// t1 = a + b
// t2 = c * d
// t3 = t2 / e
// t4 = t1 - t3