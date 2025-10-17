//7. Implement a symbol table that involves insertion, deletion, search and modify operation using C language


#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for a symbol
struct Symbol {
    char name[30];
    char type[10];
    int size;
};

// Symbol table and count
struct Symbol table[MAX];
int count = 0;

// Function declarations
void insert();
void display();
void search();
void modify();
void deleteSymbol();

int main() {
    int choice;

    printf("=== SYMBOL TABLE IMPLEMENTATION ===\n");

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Modify\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: modify(); break;
            case 5: deleteSymbol(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Insert a new symbol
void insert() {
    if (count >= MAX) {
        printf("Symbol Table Full!\n");
        return;
    }

    char name[30], type[10];
    int size;

    printf("Enter symbol name: ");
    scanf("%s", name);
    printf("Enter data type: ");
    scanf("%s", type);
    printf("Enter size: ");
    scanf("%d", &size);

    // Check for duplicates
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol already exists!\n");
            return;
        }
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].size = size;
    count++;

    printf("Symbol inserted successfully!\n");
}

// Display symbol table
void display() {
    if (count == 0) {
        printf("Symbol Table is empty!\n");
        return;
    }

    printf("\n%-20s %-10s %-5s\n", "Name", "Type", "Size");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10s %-5d\n", table[i].name, table[i].type, table[i].size);
    }
}

// Search for a symbol
void search() {
    char name[30];
    printf("Enter symbol name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Symbol found: %s | Type: %s | Size: %d\n",
                   table[i].name, table[i].type, table[i].size);
            return;
        }
    }
    printf("Symbol not found!\n");
}

// Modify an existing symbol
void modify() {
    char name[30];
    printf("Enter symbol name to modify: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("Enter new data type: ");
            scanf("%s", table[i].type);
            printf("Enter new size: ");
            scanf("%d", &table[i].size);
            printf("Symbol modified successfully!\n");
            return;
        }
    }
    printf("Symbol not found!\n");
}

// Delete a symbol
void deleteSymbol() {
    char name[30];
    printf("Enter symbol name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }
            count--;
            printf("Symbol deleted successfully!\n");
            return;
        }
    }
    printf("Symbol not found!\n");
}


// === SYMBOL TABLE IMPLEMENTATION ===

// 1. Insert
// 2. Display
// 3. Search
// 4. Modify
// 5. Delete
// 6. Exit
// Enter your choice: 1
// Enter symbol name: x
// Enter data type: int
// Enter size: 4
// Symbol inserted successfully!

// Enter your choice: 1
// Enter symbol name: y
// Enter data type: float
// Enter size: 8
// Symbol inserted successfully!

// Enter your choice: 2
// Name                 Type       Size
// --------------------------------------
// x                    int        4
// y                    float      8

// Enter your choice: 3
// Enter symbol name to search: x
// Symbol found: x | Type: int | Size: 4

// Enter your choice: 4
// Enter symbol name to modify: x
// Enter new data type: double
// Enter new size: 8
// Symbol modified successfully!

// Enter your choice: 5
// Enter symbol name to delete: y
// Symbol deleted successfully!

// Enter your choice: 2
// Name                 Type       Size
// --------------------------------------
// x                    double     8
