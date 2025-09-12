#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Function to check if a string is a number
int isNumber(char *str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != '-') return 0;
    }
    return 1;
}

int main() {
    char code[MAX][MAX];
    int n, i;

    printf("Enter number of statements: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter the three-address code statements:\n");
    for (i = 0; i < n; i++) {
        fgets(code[i], MAX, stdin);
        code[i][strcspn(code[i], "\n")] = 0; // remove newline
    }

    printf("\n--- Original Code ---\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", code[i]);
    }

    printf("\n--- Optimized Code ---\n");
    for (i = 0; i < n; i++) {
        char lhs, op, arg1[20], arg2[20];
        int numArgs = sscanf(code[i], "%c=%[^+-*/]%c%s", &lhs, arg1, &op, arg2);

        if (numArgs == 4) {
            // Trim spaces
            char *a = arg1; while (*a == ' ') a++;
            char *b = arg2; while (*b == ' ') b++;

            // Constant Folding: e.g., x=2+3 => x=5
            if (isNumber(a) && isNumber(b)) {
                int v1 = atoi(a), v2 = atoi(b), res = 0;
                if (op == '+') res = v1 + v2;
                else if (op == '-') res = v1 - v2;
                else if (op == '*') res = v1 * v2;
                else if (op == '/') res = (v2 != 0) ? v1 / v2 : 0;
                printf("%c=%d\n", lhs, res);
            }
            // Strength Reduction: e.g., x=y*2 => x=y+y
            else if (op == '*' && isNumber(b) && atoi(b) == 2) {
                printf("%c=%s+%s\n", lhs, a, a);
            }
            // Algebraic Transformations
            else if (op == '+' && isNumber(b) && atoi(b) == 0) {
                printf("%c=%s\n", lhs, a);  // x=y+0 → x=y
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 1) {
                printf("%c=%s\n", lhs, a);  // x=y*1 → x=y
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 0) {
                printf("%c=0\n", lhs);      // x=y*0 → x=0
            }
            else {
                printf("%s\n", code[i]);   // unchanged
            }
        } else {
            printf("%s\n", code[i]);   // simple assignment stays
        }
    }

    return 0;
}

----------------

🔹 Example Run
Input
5
a=2+3
b=a*2
c=b+0
d=c*1
e=c*0

Output
--- Original Code ---
a=2+3
b=a*2
c=b+0
d=c*1
e=c*0

--- Optimized Code ---
a=5
b=a+a
c=b
d=c
e=0
