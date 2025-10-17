// 4.	Develop a C program that generates Abstract Syntax Trees (AST) from a given arithmetic expression.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Create a new node
Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// ---------- Parser functions ----------
const char* expr;
int pos = 0;

Node* parseExpression(); // Forward declaration

Node* parseFactor() {
    if (expr[pos] == '(') {
        pos++; // skip '('
        Node* node = parseExpression();
        pos++; // skip ')'
        return node;
    } else {
        // Operand
        return createNode(expr[pos++]);
    }
}

Node* parseTerm() {
    Node* node = parseFactor();
    while (expr[pos] == '*' || expr[pos] == '/') {
        char op = expr[pos++];
        Node* newNode = createNode(op);
        newNode->left = node;
        newNode->right = parseFactor();
        node = newNode;
    }
    return node;
}

Node* parseExpression() {
    Node* node = parseTerm();
    while (expr[pos] == '+' || expr[pos] == '-') {
        char op = expr[pos++];
        Node* newNode = createNode(op);
        newNode->left = node;
        newNode->right = parseTerm();
        node = newNode;
    }
    return node;
}

// ---------- Print AST sideways ----------
void printAST(Node* root, int space) {
    if (!root) return;

    space += 5;
    printAST(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%c\n", root->data);

    printAST(root->left, space);
}

// ---------- Main ----------
int main() {
    char input[100];
    printf("Enter arithmetic expression: ");
    scanf("%s", input);

    expr = input;
    pos = 0;

    Node* root = parseExpression();

    printf("\nAbstract Syntax Tree (AST):\n");
    printAST(root, 0);

    return 0;
}

// Example Input/Output:
// Displaying sideways AST 
// Enter arithmetic expression: a*b-c+d

// Abstract Syntax Tree (AST):

//      d

// +

//           c

//      -

//                b

//           *

//                a