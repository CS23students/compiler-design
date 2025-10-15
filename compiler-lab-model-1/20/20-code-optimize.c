//20.	Develop a code optimization program to optimize the given intermediate code using standard optimization techniques.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char lhs[10];
    char rhs[50];
} Instruction;

// Function to check if a string is a number
int isNumber(char *str) {
    int i = 0;
    if (str[0] == '-') i = 1;
    for (; str[i]; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int main() {
    Instruction code[MAX];
    int n;

    printf("Enter number of instructions: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter instructions (format: a=3+2, b=a*2, etc.):\n");
    for (int i = 0; i < n; i++) {
        char line[50];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;
        sscanf(line, "%[^=]=%s", code[i].lhs, code[i].rhs);
    }

    printf("\n--- Optimized Code ---\n");
    for (int i = 0; i < n; i++) {
        char lhs[10], rhs[50];
        strcpy(lhs, code[i].lhs);
        strcpy(rhs, code[i].rhs);

        char arg1[20], arg2[20];
        char op;

        // Try to parse "arg1 op arg2"
        if (sscanf(rhs, "%[^+-*/]%c%s", arg1, &op, arg2) == 3) {
            // Trim spaces
            char *a = arg1;
            while (*a == ' ') a++;
            char *b = arg2;
            while (*b == ' ') b++;

            // Constant Folding: both numbers
            if (isNumber(a) && isNumber(b)) {
                int val1 = atoi(a), val2 = atoi(b), res = 0;
                if (op == '+') res = val1 + val2;
                else if (op == '-') res = val1 - val2;
                else if (op == '*') res = val1 * val2;
                else if (op == '/') res = (val2 != 0) ? val1 / val2 : 0;
                printf("%s = %d\n", lhs, res);
            }
            // Strength Reduction: multiply by 2
            else if (op == '*' && isNumber(b) && atoi(b) == 2) {
                printf("%s = %s + %s\n", lhs, a, a);
            }
            // Algebraic simplifications
            else if (op == '+' && isNumber(b) && atoi(b) == 0) {
                printf("%s = %s\n", lhs, a);
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 1) {
                printf("%s = %s\n", lhs, a);
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 0) {
                printf("%s = 0\n", lhs);
            }
            else {
                printf("%s = %s\n", lhs, rhs);
            }
        } else {
            // Single assignment
            printf("%s = %s\n", lhs, rhs);
        }
    }

    return 0;
}


// Input:

// Enter number of instructions: 4
// a=3+2
// b=a*3
// c=b+0
// d=c*2


// Output:

// --- Optimized Code ---
// a = 5
// b = a*3
// c = b
// d = c + c