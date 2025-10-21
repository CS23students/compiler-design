# Compiler Design Model Lab - 1 Programs

## Commands to execute the lex and yacc programs

1. To compile a Lex program:

   ```
   flex `filename.l`
   gcc lex.yy.c -o `output-filename`
   ./output-filename.exe
   ```
   
- if only lex file exists
 ```
   win_flex filename.l
   gcc lex.yy.c -o filename.exe
   filename.exe
```
- if both yaac and lex file exist
```
   win_bison -d filename.y
   win_flex filename.l
   gcc filename.tab.c lex.yy.c -o filename.exe
   filename.exe
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

## 01. recognise a valid control structure syntax of c lang - for loop, while, if...else if...else if, switch, do...while.

[Develop a program to recognise a valid control structure syntax of c lang - for loop, while, if...else if...else if, switch, do...while.](./01/)

## 02. Count Vowels and Consonants using LEX

[Develop a Lex program to count the total number of vowels and consonants in the given input.](./02/)

## 03. Eliminate Left Recursion using C

[Develop a C program to eliminate left recursion from the given grammar.](./03/)

## 04. Abstract Syntax Tree (AST) for Arithmetic Expressions using C

[Develop a C program that generates Abstract Syntax Trees (AST) from a given arithmetic expression.](./04/)

## 05. Top Down Parser with no backtracking using C - only for specific input (already defined in code)

[Design a top down parser which generates a parsing table with no backtracking](./05/)

## 06. Lexical analysis for identifiers, constants

[Develop a C program to design a lexical analyzer that recognizes identifiers and constants.](./06/)

## 07. Symbol Table Management using C

[Implement a symbol table that involves insertion, deletion, search and modify operation using C language](./07/)

## 08. Lexical analyzer for to separate tokens using LEX

[Design a program that implements a lexical analyzer to separate tokens using Lex tool.](./08/)

## 09. Valid Arithmetic Expression using LEX

[Use Lex tool to recognize a valid arithmetic expression with operators +, -, \*, /.](./09/)

## 10. Valid Variable Name using YACC

[10. Design a pgm to recognize a valid variable that starts with an alphabet followed by any no. of digits alphabets using yacc tool.](./10/)

## 11. Generate Machine Code from Intermediate Code using C

[Develop a C program to generate machine code from a given intermediate code.](./11/)

## 12. beginning with an uppercase letter followed by 5 digits or alphabets - using YACC

[Generate a valid pattern that recognises all stmts that begins with an uppercase letter followed by five digits or alphabet use yacc tool to do the same.](./12/)

## 13. Identify Commands, Arithmetic operators and keywords using LEX

[Define a lexical analyzer that identifies commands, arithmetic operators and keywords from a given expression.](./13/)

## 14. Generate Machine Code from Postfix Expression using C

[Develop a C program to generate machine code from a given postfix notation.](./14/)

## 15. lex program to scan variables, reserved words and operators of clang

[Write a lex program to scan variables, reserved words and operators of C-language](./15/)

## 16. Convert Three Address Code to Assembly Language using C

[Develop a pgm in c that converts the given 3 add code into assembly lang stmts](./16/)

## 17. Native calculator using LEX and YACC

[Use lex and yacc tool to implement a native calc.](./17/)

## 18. Generate Three Address Code for Arithmetic Expressions using C

[18. Design a program to generate 3-add code from given arith exp](./18/)

## 19. Type checker in variable scope and semantic error detection using C

[Implement a type checker in C to verify variable scope and semantic errors in given statements.](./19/)

## 20. Code Optimization using C

[20. Develop a code optimization program to optimize the given intermediate code using standard optimization techniques.](./20/)

