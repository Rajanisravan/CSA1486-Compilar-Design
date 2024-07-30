%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char alphabetList[1000] = "";
char numberList[1000] = ""; 
%}
%%
[0-9]+ { strcat(numberList, yytext); }
[a-zA-Z]+ { strcat(alphabetList, yytext); }
. { printf("Invalid input: %s\n", yytext); }
%%
int yywrap() {
 printf("Alphabets: %s\n", alphabetList);
 printf("Numbers: %s\n", numberList);
 return 1;
}
int main() {
 char input[100];
 printf("Enter the input: ");
 fgets(input, sizeof(input), stdin);
 yy_scan_string(input);
 yylex();
 return 0;
}
