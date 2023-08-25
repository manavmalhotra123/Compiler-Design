%{
#include <stdio.h>
%}

%%
[0-9]*00$        printf("String belongs to grammar: Ending with '00'\n");
.*           printf("String does not belong to the grammar.\n");
%%

int main() {
    yylex();
    return 0;
}
