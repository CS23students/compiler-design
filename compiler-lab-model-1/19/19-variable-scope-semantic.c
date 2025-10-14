//19.	Implement a type checker in C to verify variable scope and semantic errors in given statements.

#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[10];
};

int main() {
    struct Symbol table[10];
    int n, i, j, error = 0;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    // Step 1: Input variable declarations
    for (i = 0; i < n; i++) {
        printf("Enter variable name and type (e.g., x int): ");
        scanf("%s %s", table[i].name, table[i].type);
    }

    int m;
    printf("Enter number of statements to check: ");
    scanf("%d", &m);

    // Step 2: Input and check statements
    for (i = 0; i < m; i++) {
        char var1[20], op[3], var2[20];
        printf("Enter statement (e.g., x = y): ");
        scanf("%s %s %s", var1, op, var2);

        int found1 = -1, found2 = -1;

        // Check if variables are declared
        for (j = 0; j < n; j++) {
            if (strcmp(table[j].name, var1) == 0)
                found1 = j;
            if (strcmp(table[j].name, var2) == 0)
                found2 = j;
        }

        if (found1 == -1 || found2 == -1) {
            printf("Error: Undeclared variable in statement %d\n", i + 1);
            error = 1;
        } 
        else if (strcmp(table[found1].type, table[found2].type) != 0) {
            printf("Error: Type mismatch in statement %d\n", i + 1);
            error = 1;
        } 
        else {
            printf("Statement %d is semantically correct.\n", i + 1);
        }
    }

    if (!error)
        printf("\nNo semantic errors found.\n");
    else
        printf("\nSemantic errors detected.\n");

    return 0;
}


// Enter number of variables: 3
// Enter variable name and type (e.g., x int): x int
// Enter variable name and type (e.g., x int): y int
// Enter variable name and type (e.g., x int): z float

// Enter number of statements to check: 2
// Enter statement (e.g., x = y): x = y
// Statement 1 is semantically correct.
// Enter statement (e.g., x = y): x = z
// Error: Type mismatch in statement 2

// ⚠️ Semantic errors detected.
