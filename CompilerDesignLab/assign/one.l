%{
#include <stdio.h>
%}

%%
([^5]*5[^5]*){2}.*    printf("String belongs to grammar.\n");
.*                    printf("String does beloings to grmmar.\n");
%%

int main() {
    yylex();
    return 0;
}

