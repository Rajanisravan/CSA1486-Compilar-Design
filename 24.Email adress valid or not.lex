%{
%}
%%
[a-z.0-9]+@[a-z]+(.com|.in) {printf("\n valid\n");}
.+ {printf("\n Invalid\n");}
%%
int yywrap()
{}
int main()
{
printf("\nEnter : ");
yylex();
}
