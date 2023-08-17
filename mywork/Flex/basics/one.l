%{
#include <stdio.h>
%}

DIGIT       [0-9]
WS          [ \t\n]

%%

{DIGIT}+    { printf("NUMBER: %s\n", yytext); }
{WS}+       { /* Ignore whitespace */ }
.           { printf("UNKNOWN: %s\n", yytext); }

%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    yylex();
    return 0;
}
