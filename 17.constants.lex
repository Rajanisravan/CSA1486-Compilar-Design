%{
int cons=0;
%}
digit [0-9]
%%
{digit}+"."{digit}+ {cons++;}
{digit}+ {cons++;}
.|\n {}
%%
int yywrap(){}
int main()
{
printf("enter the code");
yylex();
printf("no.of constants %d",cons);
return 0;
}
