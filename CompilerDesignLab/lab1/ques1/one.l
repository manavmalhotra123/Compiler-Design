%{
#include<stdio.h>
%}

digit [0-9]
num {digit}+
snum [-+]?{num}

%%

({snum}(\.{num}))|([+-]?{num}\.{num}) {
    printf ("==>%s is a floating-point number \n", yytext);
}
({snum}) {
    printf ("==>%s is not a floating-point number \n", yytext);
}

%%

int main ()
{
    printf ("Enter any number: \n" );
    yylex();
    return 0;
}
