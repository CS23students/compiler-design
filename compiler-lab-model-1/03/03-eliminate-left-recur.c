//3.	Develop a C program to eliminate left recursion from a grammar.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], non_terminal;
    char beta[20][20], alpha[20][20];
    int i, j = 0, k = 0;

    printf("Enter production (Example: E=E+T|T): ");
    scanf("%s", input);

    non_terminal = input[0]; // e.g., 'E'
    int len = strlen(input);

    i = 2; // skip 'E=' part
    while (i < len) {
        if (input[i] == non_terminal) {
            // Left-recursive production
            i++;
            int n = 0;
            while (input[i] != '|' && input[i] != '\0') {
                alpha[j][n++] = input[i++];
            }
            alpha[j][n] = '\0';
            j++;
        } else {
            // Non-left-recursive production
            int n = 0;
            while (input[i] != '|' && input[i] != '\0') {
                beta[k][n++] = input[i++];
            }
            beta[k][n] = '\0';
            k++;
        }
        if (input[i] == '|') i++;
    }

    if (j == 0) {
        printf("No Left Recursion found!\n");
    } else {
        // Print transformed grammar
        printf("\nGrammar after eliminating Left Recursion:\n");
        
        // A -> beta A'
        printf("%c -> ", non_terminal);
        for (i = 0; i < k; i++) {
            printf("%s%c'%s", beta[i], non_terminal, (i == k - 1) ? "" : " | ");
        }
        printf("\n");

        // A' -> alpha A' | ε
        printf("%c' -> ", non_terminal);
        for (i = 0; i < j; i++) {
            printf("%s%c'%s", alpha[i], non_terminal, (i == j - 1) ? " | ε" : " | ");
        }
        printf("\n");
    }

    return 0;
}


// Enter production (Example: E=E+T|T): A=Ab|c

// Grammar after eliminating Left Recursion:
// A -> cA'
// A' -> bA' | ε
