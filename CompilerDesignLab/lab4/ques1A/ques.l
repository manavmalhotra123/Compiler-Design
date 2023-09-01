%option noyywrap
%{
#include <stdio.h>
%}

%%
[0-9]*1[0-9]{9}    { printf("String belongs to grammar.\n"); }
.*                   { printf("String does not belong to grammar.\n"); }
%%

int main() {
    yylex();
    return 0;
}
