//16. Develop a pgm in c that converts the given 3 add code into assembly lang stmts

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void generateAssembly(char *lhs, char *op1, char *op, char *op2) {
    if (strcmp(op, "+") == 0)
        printf("MOV R0, %s\nADD R0, %s\nMOV %s, R0\n\n", op1, op2, lhs);
    else if (strcmp(op, "-") == 0)
        printf("MOV R0, %s\nSUB R0, %s\nMOV %s, R0\n\n", op1, op2, lhs);
    else if (strcmp(op, "*") == 0)
        printf("MOV R0, %s\nMUL R0, %s\nMOV %s, R0\n\n", op1, op2, lhs);
    else if (strcmp(op, "/") == 0)
        printf("MOV R0, %s\nDIV R0, %s\nMOV %s, R0\n\n", op1, op2, lhs);
    else
        printf("; Unsupported operation: %s\n\n", op);
}

int main() {
    char line[MAX];
    char lhs[20], op1[20], op2[20], op[3];

    printf("Enter 3-address code statements (Ctrl+D to stop):\n");

    while (fgets(line, sizeof(line), stdin)) {
        // Remove newline
        line[strcspn(line, "\n")] = 0;

        // Match TAC with spaces like: t1 = a + b
        if (sscanf(line, " %[^= ] = %[^ +*/-] %s %s", lhs, op1, op, op2) == 4) {
            generateAssembly(lhs, op1, op, op2);
        } 
        // Simple assignment: t3 = t2
        else if (sscanf(line, " %[^= ] = %s", lhs, op1) == 2) {
            printf("MOV %s, %s\n\n", lhs, op1);
        } 
        else {
            printf("; Invalid TAC format: %s\n", line);
        }
    }

    return 0;
}



// Enter 3-address code statements (Ctrl+D to stop):
// t1 = a + b
// MOV R0, a
// ADD R0, b
// MOV t1, R0

// t2 = t1 * c
// MOV R0, t1
// MUL R0, c
// MOV t2, R0

// t3 = t2 - d
// MOV R0, t2
// SUB R0, d
// MOV t3, R0

// x = t3
// MOV x, t3
