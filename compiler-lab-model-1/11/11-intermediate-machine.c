//11. Given intermediate code as input, develop a program that generates the corresponding machine code.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char code[100][50];   // to store up to 100 TAC lines
    int count = 0;
    int i, regCount = 1;

    printf("Enter intermediate code (type END to finish):\n");

    // --- Step 1: Input all TAC lines ---
    while (1) {
        scanf("%s", code[count]);
        if (strcmp(code[count], "END") == 0)
            break;
        count++;
    }

    printf("\nGenerated Machine Code:\n");

    // --- Step 2: Process all lines ---
    for (i = 0; i < count; i++) {
        char line[50];
        strcpy(line, code[i]);

        // Handle label like L1:
        if (strchr(line, ':')) {
            printf("%s\n", line);
            continue;
        }

        // Handle goto statement
        if (strncmp(line, "goto", 4) == 0) {
            char label[10];
            sscanf(line, "goto%s", label);
            printf("JMP %s\n", label);
            continue;
        }

        // Handle if condition: ifa<10gotoL1
        if (strncmp(line, "if", 2) == 0) {
            char var[10], label[10];
            char op;
            int val;
            sscanf(line, "if%s%c%dgoto%s", var, &op, &val, label);
            printf("MOVF P %s R%d\n", var, regCount);
            printf("CMP R%d %d\n", regCount, val);
            if (op == '<')
                printf("JLT %s\n", label);
            else if (op == '>')
                printf("JGT %s\n", label);
            else if (op == '=')
                printf("JEQ %s\n", label);
            regCount++;
            continue;
        }

        // Handle assignment or arithmetic
        {
            char left[10] = "", right1[10] = "", right2[10] = "", op = 0;
            int parts;
            parts = sscanf(line, "%[^=]=%[^+*/-]%c%s", left, right1, &op, right2);

            if (parts == 2) {
                // Simple assignment (a=5 or a=b)
                if (isdigit(right1[0])) {
                    printf("MOVF P %s R%d\n", right1, regCount);
                    printf("MOVE R%d %s\n", regCount, left);
                } else {
                    printf("MOVF P %s R%d\n", right1, regCount);
                    printf("MOVE R%d %s\n", regCount, left);
                }
                regCount++;
            } else if (parts == 4) {
                // Arithmetic operation (c=a+b)
                printf("MOVF P %s R%d\n", right1, regCount);
                if (op == '+')
                    printf("ADDR (%s, R%d)\n", right2, regCount);
                else if (op == '-') 
                    printf("SUBR (%s, R%d)\n", right2, regCount);
                else if (op == '*')
                    printf("MULR (%s, R%d)\n", right2, regCount);
                else if (op == '/')
                    printf("DIVR (%s, R%d)\n", right2, regCount);
                printf("MOVE R%d %s\n", regCount, left);
                regCount++;
            }
        }
    }

    printf("HALT\n");
    return 0;
}


/*
SAMPLE INPUT
a=5
b=10
if a<10 goto L1
goto L2
L1:
c=a+b
L2:
END

SAMPLE OUTPUT

Generated Machine Code:
MOVF P 5 R1
MOVE R1 a
MOVF P 10 R2
MOVE R2 b
MOVF P a R3
CMP R3 10
JLT L1
JMP L2
L1:
MOVF P a R4
ADDR (b, R4)
MOVE R4 c
L2:
HALT

*/ 