//14. Develop a C program to generate machine code from a given postfix notation.


#include <stdio.h>
#include <ctype.h>

void generateMachineCode(char postfix[]) {
    char stack[20];
    int top = -1;
    int temp = 1;  // Temporary register counter

    printf("\nGenerated Machine Code:\n");

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        if (isalnum(symbol)) { // Operand
            stack[++top] = symbol;
        } else { // Operator
            char op2 = stack[top--];
            char op1 = stack[top--];

            printf("LOAD %c\n", op1);
            switch (symbol) {
                case '+': printf("ADD %c\n", op2); break;
                case '-': printf("SUB %c\n", op2); break;
                case '*': printf("MUL %c\n", op2); break;
                case '/': printf("DIV %c\n", op2); break;
            }
            printf("STORE T%d\n", temp);
            stack[++top] = 'T'; // Push temporary variable
            temp++;
        }
    }
}

int main() {
    char postfix[20];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    generateMachineCode(postfix);

    return 0;
}



// Sample Input/Output
// Enter a postfix expression: ab+cd*-

// Generated Machine Code:
// LOAD a
// ADD b
// STORE T1
// LOAD c
// MUL d
// STORE T2
// LOAD T
// SUB T
// STORE T3