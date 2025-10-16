#include <stdio.h>
#include <string.h>

int main()
{
    char tac[10][30], str[30];
    int i = 0;

    printf("Enter the set of intermediate code (terminated by exit):\n");
    do
    {
        scanf("%s", tac[i]);
    } while (strcmp(tac[i++], "exit") != 0);

    printf("\nGenerated 8086 Assembly Code:\n");
    printf(".MODEL SMALL\n.STACK 100H\n.DATA\n");
    printf("a DW 0\nb DW 0\nc DW 0\nt1 DW 0\nt2 DW 0\n");
    printf(".CODE\nMAIN PROC\nMOV AX,@DATA\nMOV DS,AX\n\n");

    i = 0;
    do
    {
        strcpy(str, tac[i]);

        // Check if line contains operator +, -, *, /
        char *op_ptr = strpbrk(str, "+-*/");
        if (op_ptr != NULL)
        {
            char lhs[10], arg1[10], arg2[10];
            char op = *op_ptr;

            // Parse the format: lhs=arg1 op arg2
            sscanf(str, "%[^=]=%[^+-*/]%*c%[^+-*/]", lhs, arg1, arg2);

            // Trim spaces if any (optional)
            // For simplicity, assuming no spaces in input here

            printf("    MOV AX, %s\n", arg1);

            if (op == '+')
                printf("    ADD AX, %s\n", arg2);
            else if (op == '-')
                printf("    SUB AX, %s\n", arg2);
            else if (op == '*')
            {
                printf("    MOV BX, %s\n", arg2);
                printf("    IMUL BX\n");
            }
            else if (op == '/')
            {
                printf("    MOV BX, %s\n", arg2);
                printf("    CWD\n");
                printf("    IDIV BX\n");
            }

            printf("    MOV %s, AX\n\n", lhs);
        }
        else if (strchr(str, '=') != NULL)
        {
            // Simple assignment: lhs=rhs
            char lhs[10], rhs[10];
            sscanf(str, "%[^=]=%s", lhs, rhs);

            printf("    MOV AX, %s\n", rhs);
            printf("    MOV %s, AX\n\n", lhs);
        }

    } while (strcmp(tac[++i], "exit") != 0);

    printf("    MOV AH,4CH\n    INT 21H\nMAIN ENDP\nEND MAIN\n");
    return 0;
}

