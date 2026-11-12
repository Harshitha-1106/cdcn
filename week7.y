
%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int yylex();
int yyerror(char *s);
int result;
%}

%union {
    int num;
}

%token <num> NUMBER
%type <num> E S

%start S

%left '+' '-'
%left '*' '/'

%%

S : E { result = $1; }
  ;

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E {
        if($3 == 0) {
            printf("Division by zero\n");
            exit(1);
        }
        $$ = $1 / $3;
    }
  | '(' E ')' { $$ = $2; }
  | NUMBER    { $$ = $1; }
  ;

%%

int yylex() {
    int c = getchar();

    if(c == ' ' || c == '\t' || c == '\n')
        return yylex();

    if(isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &yylval.num);
        return NUMBER;
    }

    return c;
}

int main() {
    printf("Enter expression: ");

    if(yyparse() == 0)
        printf("Result = %d\n", result);

    return 0;
}

int yyerror(char *s) {
    printf("Invalid expression\n");
    return 0;
}
