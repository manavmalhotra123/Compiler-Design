%{
#include <stdio.h>
#include <string.h>
%}

%% 
[0-9]*222[0-9]*  { fprintf(stdout, "This string belongs to the grammar with three consecutive '222's.\n"); }
.                { fprintf(stdout, "This string doesn't belong to the grammar with three consecutive '222's.\n"); }
%%

int main()
{
    yylex();
    return 0;
}
