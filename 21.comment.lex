%{
#include<stdio.h>
int c=0;
%}
%%
"/"[a-zA-Z0-9]+"/" {c++;}
"//"[a-zA-Z0-9]+"\n" {c++;}
%%
int yywrap( ){}
int main()
{
printf("enter the comment lines:\n");
yylex( );
printf("The number of comment lines=%d\n",c);
}
