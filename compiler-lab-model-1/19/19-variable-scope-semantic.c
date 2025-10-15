//19.	Implement a type checker in C to verify variable scope and semantic errors in given statements.

#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[20];
    char type[10];
    int scope;
};

int findVar(struct Symbol table[], int n, char *name, int currentScope) {
    for (int i = n - 1; i >= 0; i--) {
        if (strcmp(table[i].name, name) == 0 && table[i].scope <= currentScope)
            return i;
    }
    return -1;
}

int main() {
    struct Symbol table[50];
    int n = 0, currentScope = 0, error = 0;
    int decls, stmts;

    printf("Number of variable declarations: ");
    scanf("%d", &decls);

    for (int i = 0; i < decls; i++) {
        char name[20], type[10];
        printf("Enter name and type: ");
        scanf("%s %s", name, type);
        strcpy(table[n].name, name);
        strcpy(table[n].type, type);
        table[n].scope = currentScope;
        n++;
    }

    printf("Number of statements: ");
    scanf("%d", &stmts);
    printf("Use '{' to enter scope, '}' to exit scope.\n");

    for (int i = 0; i < stmts; i++) {
        char var1[20], op[3], var2[20];
        scanf("%s", var1);

        if (strcmp(var1, "{") == 0) {
            currentScope++;
            i--;
            continue;
        }
        if (strcmp(var1, "}") == 0) {
            currentScope--;
            i--;
            continue;
        }

        scanf("%s %s", op, var2);

        int f1 = findVar(table, n, var1, currentScope);
        int f2 = findVar(table, n, var2, currentScope);

        if (f1 == -1 || f2 == -1) {
            printf("Error: Undeclared variable\n");
            error = 1;
        } else if (strcmp(table[f1].type, table[f2].type) != 0) {
            printf("Error: Type mismatch\n");
            error = 1;
        } else {
            printf("Statement is correct.\n");
        }
    }

    if (error)
        printf("\nSemantic errors detected.\n");
    else
        printf("\nNo semantic errors.\n");

    return 0;
}


// Number of variable declarations: 3
// Enter name and type: a int
// Enter name and type: b int
// Enter name and type: x float
// Number of statements: 4
// Use '{' to enter scope, '}' to exit scope.
// a = b
// Statement is correct.
// {
// x = a
// Statement is correct.
// y = b
// Error: Undeclared variable
// }
// a = x
// Error: Type mismatch

// Semantic errors detected.
