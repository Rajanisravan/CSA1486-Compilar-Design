%{
%}
%%
\<[^>]*\> {printf("%s\n is html tag",yytext);}
.|\n;
%%
int yywrap(){}
int main()
{
yylex();
}
