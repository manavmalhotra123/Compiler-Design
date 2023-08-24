%{
#include<stdio.h>
#include<stdlib.h>
int count = 0;
%}

%% 
"/*"[^*]*"*"[^/]*"/" {
    count++;
}
"//".* {
    count++;
}
. ECHO;
%%

int main()
{
    yyin = fopen("one.txt", "r");
    if (!yyin) {
        perror("Error opening input file");
        return 1;
    }

    yyout = fopen("two.txt", "w");
    if (!yyout) {
        perror("Error opening output file");
        fclose(yyin);
        return 1;
    }

    while (yylex() != 0) {}

    fclose(yyin);
    fclose(yyout);

    printf("Number of comments in the file are %d\n", count);

    return 0;
}
