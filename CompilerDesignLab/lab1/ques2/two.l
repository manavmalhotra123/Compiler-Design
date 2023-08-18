%{
#include <stdio.h>
#include <string.h>
%}

%%
int|float|char|if|else|while|for|return|do|const|static|for  { printf("Keyword: %s\n", yytext); }
[a-zA-Z_]*                  { printf("Identifier: %s\n", yytext); }
[+\-*/=<>]                                 { printf("Operator: %s\n", yytext); }
[;,(){}[\]""'']                              { printf("Punctuation: %s\n", yytext); }
.                                       
%%

int main() {
    printf("Enter your input:\n");
    yylex();
    return 0;
}
