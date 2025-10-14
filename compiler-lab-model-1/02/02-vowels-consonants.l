// 02. Develop a Lex program to count the total number of vowels and consonants in the given input.

%{
#include <stdio.h>

int vowel_count = 0;
int consonant_count = 0;
%}

%%

[aAeEiIoOuU]      { vowel_count++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]   { consonant_count++; }
.|\n              {  }

%%

int main() {
    printf("Enter input (Ctrl+D to end on Linux/macOS or Ctrl+Z then Enter on Windows):\n");
    yylex();
    printf("\nNumber of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);
    return 0;

}
int yywrap(){
  return 1;
}

// Sample Output
//Enter input (Ctrl+D to end on Linux/macOS or Ctrl+Z then Enter on Windows):
//vowels

//Number of vowels: 2
//Number of consonants: 4
