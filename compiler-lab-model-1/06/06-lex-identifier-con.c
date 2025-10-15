//06. Develop a C program to design a lexical analyzer that recognizes identifiers and constants.

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isKeyword(char str[]) {
    char *keywords[] = {"int", "float", "char", "double", "if", "else", "while", "for", "return"};
    int n = sizeof(keywords)/sizeof(keywords[0]);
    for(int i = 0; i < n; i++)
        if(strcmp(str, keywords[i]) == 0) return 1;
    return 0;
}

int main() {
    char str[200];
    printf("Enter a statement: ");
    fgets(str, sizeof(str), stdin);

    char token[50];
    int i = 0, j = 0;

    // Tokenization process
    while(str[i] != '\0') {
        if(str[i] == ' ' || str[i] == '\n') { 
            if(j > 0) {
                token[j] = '\0';
                if(isKeyword(token))
                    printf("%s : Keyword\n", token);
                else if(isdigit(token[0]))
                    printf("%s : Constant\n", token);
                else
                    printf("%s : Identifier\n", token);
                j = 0;
            }
            i++;
            continue;
        }

        // Check for operators
        if(str[i] == '=' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ';') {
            if(j > 0) {
                token[j] = '\0';
                if(isKeyword(token))
                    printf("%s : Keyword\n", token);
                else if(isdigit(token[0]))
                    printf("%s : Constant\n", token);
                else
                    printf("%s : Identifier\n", token);
                j = 0;
            }
            printf("%c : Operator\n", str[i]);
            i++;
            continue;
        }

        token[j++] = str[i++];
    }

    return 0;
}



// Enter a statement: int a=10
// int : Keyword
// a : Identifier
// = : Operator
// 10 : Constant
