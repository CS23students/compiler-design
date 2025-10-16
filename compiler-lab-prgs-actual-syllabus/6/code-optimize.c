#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int isNumber(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && str[i] != '-')
            return 0;
    }
    return 1;
}

int main()
{
    char code[MAX][MAX];
    int n, i;

    printf("Enter number of statements: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the three-address code statements:\n");
    for (i = 0; i < n; i++)
    {
        fgets(code[i], MAX, stdin);
        code[i][strcspn(code[i], "\n")] = 0;
    }

    printf("\n--- Original Code ---\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", code[i]);
    }

    printf("\n--- Optimized Code ---\n");
    for (i = 0; i < n; i++)
    {
        char lhs, op, arg1[20], arg2[20];
        int numArgs = sscanf(code[i], "%c=%[^+-*/]%c%s", &lhs, arg1, &op, arg2);

        if (numArgs == 4)
        {

            char *a = arg1;
            while (*a == ' ')
                a++;
            char *b = arg2;
            while (*b == ' ')
                b++;

            if (isNumber(a) && isNumber(b))
            {
                int v1 = atoi(a), v2 = atoi(b), res = 0;
                if (op == '+')
                    res = v1 + v2;
                else if (op == '-')
                    res = v1 - v2;
                else if (op == '*')
                    res = v1 * v2;
                else if (op == '/')
                    res = (v2 != 0) ? v1 / v2 : 0;
                printf("%c=%d\n", lhs, res);
            }

            else if (op == '*' && isNumber(b) && atoi(b) == 2)
            {
                printf("%c=%s+%s\n", lhs, a, a);
            }

            else if (op == '+' && isNumber(b) && atoi(b) == 0)
            {
                printf("%c=%s\n", lhs, a);
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 1)
            {
                printf("%c=%s\n", lhs, a);
            }
            else if (op == '*' && isNumber(b) && atoi(b) == 0)
            {
                printf("%c=0\n", lhs);
            }
            else
            {
                printf("%s\n", code[i]);
            }
        }
        else
        {
            printf("%s\n", code[i]);
        }
    }

    return 0;
}