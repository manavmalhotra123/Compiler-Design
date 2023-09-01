%option noyywrap
%{
#include <stdio.h>
%}

%%
[0-9][0-9][0-9][0-9]    {
                            int sum = 0;
                            for (int i = 0; i < 4; i++) {
                                sum += yytext[i] - '0';
                            }
                            if (sum == 9) {
                                printf("String belongs to grammar.\n");
                            } else {
                                printf("String does not belong to grammar.\n");
                            }
                        }
.*                      { printf("String does not belong to grammar.\n"); }
%%

int main() {
    yylex();
    return 0;
}
