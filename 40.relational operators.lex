%{
#include <stdio.h>
%}

%%

[a-zA-Z]+         { printf("WORD: %s\n", yytext); }
"<="              { printf("REL_OP: <=\n"); }
">="              { printf("REL_OP: >=\n"); }
"=="              { printf("REL_OP: ==\n"); }
"!="              { printf("REL_OP: !=\n"); }
"<"               { printf("REL_OP: <\n"); }
">"               { printf("REL_OP: >\n"); }

[ \t\n]+          ;  /* Ignore whitespace */

.                 { printf("UNKNOWN: %s\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}

int yywrap(void) {
    return 1;
}
