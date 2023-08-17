%{
#include <stdio.h> // Include the standard I/O library
%}

%%
"+"         printf("PLUS\n");
"-"         printf("MINUS\n");
"*"         printf("MULTIPLY\n");
"/"         printf("DIVIDE\n");
"("         printf("LEFT PARENTHESIS\n");
")"         printf("RIGHT PARENTHESIS\n");
.           printf("UNKNOWN: %s\n", yytext);
%%

int main() {
    yylex(); // Start the lexical analysis
    return 0;
}