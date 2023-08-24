%{
#include<stdio.h>
extern FILE *yyin;
extern FILE *yyout;
int yylex(void);
%}

%% 
[ ]([ ])*  {
    fprintf(yyout," ");
}

([ ])*(\n)([ ])* {
    fprintf(yyout," ");
}
%%

int main()
{
    yyin = fopen("text1.txt","r");
    if(yyin == NULL)
    {
        perror("text1.txt is not opening!!!!");
    }

    yyout = fopen("text2.txt","w");
    if(yyout == NULL)
    {
        perror("text2.txt is not opening!!!!");
    }

    yylex();

    fclose(yyin);
    fclose(yyout);

    return 0;
}