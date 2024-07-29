%{
int macro, header; 
%}
%%
"#define" {macro++;} 
"#include" {header++;} 
.|\n {}
%%
int yywrap(){}
int main() 
{ 
printf("enter the string:\n");
yylex(); 
printf("Number of macros= %d \n Number of headers= %d\n",macro,header); 
}
