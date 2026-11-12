
%{
#include <stdio.h>

int yylex();
int yyerror(char *s);
%}

%start E

%%

E : E '+' T
  | T
  ;

T : T '*' F
  | F
  ;

F : '(' E ')'
  | 'i'
  ;

%%

int yylex()
{
    int c;

    do {
        c = getchar();
    } while (c == ' ' || c == '\n' || c == '\t');

    return c;
}

int yyerror(char *s)
{
    printf("Invalid Expression\n");
    return 0;
}

int main()
{
    printf("Enter expression: ");

    if (yyparse() == 0)
        printf("Valid Expression\n");

    return 0;
}





cd /d "C:\Users\harsh\OneDrive\Desktop\cdcnn"

bison -d week6_2.y

gcc week6_2.tab.c -o week6_2.exe

week6_2.exe