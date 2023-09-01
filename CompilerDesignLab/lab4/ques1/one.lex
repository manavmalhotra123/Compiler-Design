%option noyywrap
%{
#include <stdio.h>
%}

%%
([^5]*5[^5]*){0,2}    { printf("String belongs to grammar.\n"); }
.*                   { printf("String does not belong to grammar.\n"); }
%%

int main() {
    yylex();
    return 0;
}
