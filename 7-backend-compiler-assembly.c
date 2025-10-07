#include <stdio.h>
#include <string.h>

int main() {
    char tac[10][30], str[30];
    int i = 0;

    printf("Enter the set of intermediate code (terminated by exit):\n");
    do {
        scanf("%s", tac[i]);
    } while (strcmp(tac[i++], "exit") != 0);

    printf("\nGenerated 8086 Assembly Code:\n");
    printf(".MODEL SMALL\n.STACK 100H\n.DATA\n");
    printf("a DW 0\nb DW 0\nc DW 0\nt1 DW 0\nt2 DW 0\n");
    printf(".CODE\nMAIN PROC\nMOV AX,@DATA\nMOV DS,AX\n\n");

    i = 0;
    do {
        strcpy(str, tac[i]);

        // case: assignment with operator (x=y+z)
        if (strchr(str, '+') || strchr(str, '-') ||
            strchr(str, '*') || strchr(str, '/')) {
            char x, y, z, op;
            sscanf(str, "%c=%c%c%c", &x, &y, &op, &z);

            printf("    MOV AX,%c\n", y);

            if (op == '+') printf("    ADD AX,%c\n", z);
            else if (op == '-') printf("    SUB AX,%c\n", z);
            else if (op == '*') {
                printf("    MOV BX,%c\n", z);
                printf("    IMUL BX\n");
            } else if (op == '/') {
                printf("    MOV BX,%c\n", z);
                printf("    CWD\n    IDIV BX\n");
            }

            printf("    MOV %c,AX\n\n", x);
        }
        // case: simple assignment (x=y)
        else if (strchr(str, '=')) {
            char x, y;
            sscanf(str, "%c=%c", &x, &y);
            printf("    MOV AX,%c\n", y);
            printf("    MOV %c,AX\n\n", x);
        }

    } while (strcmp(tac[++i], "exit") != 0);

    printf("    MOV AH,4CH\n    INT 21H\nMAIN ENDP\nEND MAIN\n");
    return 0;
}



// 🔹 Example Input (TAC)
// t1=a+b
// t2=t1*c
// c=t2
// exit

// 🔹 Example Output (8086 Assembly)
// Generated 8086 Assembly Code:
// .MODEL SMALL
// .STACK 100H
// .DATA
// a DW 0
// b DW 0
// c DW 0
// t1 DW 0
// t2 DW 0
// .CODE
// MAIN PROC
// MOV AX,@DATA
// MOV DS,AX

//     MOV AX,a
//     ADD AX,b
//     MOV t1,AX

//     MOV AX,t1
//     MOV BX,c
//     IMUL BX
//     MOV t2,AX

//     MOV AX,t2
//     MOV c,AX

//     MOV AH,4CH
//     INT 21H
// MAIN ENDP
// END MAIN
