# Compiler Design Model Lab - 1 Programs

## Commands to execute the lex and yacc programs

1. To compile a Lex program:

   ```
   flex `filename.l`
   gcc lex.yy.c -o `output-filename`
   ./output-filename.exe
   ```

2. To compile a Yacc/Bison program:
   For Windows, you can use GnuWin32 tools. Make sure to install them and add to your PATH.

   ```
   C:\Progra~2\GnuWin32\bin\bison.exe -d filename.y (or bison -d filename.y)
   gcc filename.tab.c lex.yy.c -o output-filename
   ./output-filename.exe
   ```

3. To compile a C program:
   ```
   gcc filename.c -o output-filename
   ./output-filename.exe
   ```

## 02. Count Vowels and Consonants using LEX

[Develop a Lex program to count the total number of vowels and consonants in the given input.](./02/)

## 03. Eliminate Left Recursion using C

[Develop a C program to eliminate left recursion from the given grammar.](./03/)

## 06. Lexical analysis for identifiers, constants

[Develop a C program to design a lexical analyzer that recognizes identifiers and constants.](./06/)

## 08. Lexical analyzer for to separate tokens using LEX

[Design a program that implements a lexical analyzer to separate tokens using Lex tool.](./08/)

## 09. Valid Arithmetic Expression using LEX

[Use Lex tool to recognize a valid arithmetic expression with operators +, -, \*, /.](./09/)

## 10. Valid Variable Name using LEX

[Design a program using Lex tool to validate a variable name starting with an alphabet followed by any number of digits or alphabets.](./10/)

## 11. Generate Machine Code from Intermediate Code using C

[Develop a C program to generate machine code from a given intermediate code.](./11/)

## 13. Identify Commands, Arithmetic operators and keywords using LEX

[Define a lexical analyzer that identifies commands, arithmetic operators and keywords from a given expression.](./13/)

## 14. Generate Machine Code from Postfix Expression using C

[Develop a C program to generate machine code from a given postfix notation.](./14/)

## 19. Type checker in variable scope and semantic error detection using C

[Implement a type checker in C to verify variable scope and semantic errors in given statements.](./19/)

## 20. Code Optimization using C

[20. Develop a code optimization program to optimize the given intermediate code using standard optimization techniques.](./20/)
