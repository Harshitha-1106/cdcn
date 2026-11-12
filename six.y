%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Node{
	char data[50];
	struct Node *left ,*right;
};

struct Node * createNode(char *data,struct Node *l,struct Node *r){
	struct Node *n=malloc(sizeof(struct Node));
	strcpy(n->data,data);
	n->left=l;
	n->right=r;
return n;
}

void Printtree(struct Node *n, int space) {
    if(n == NULL) return;

    space += 5;

    Printtree(n->right, space);

    printf("\n");
    for(int i = 5; i < space; i++)
        printf(" ");

    printf("%s\n", n->data);

    Printtree(n->left, space);
}

struct Node *root;
int yylex();
int yyerror(char *s);
%}

%union{
	char *str;
	struct Node *node;
}

%token<str> ID;
%type<node> E T F;

%%
E : E '+' T {$$=createNode("+",$1,$3); root=$$;}
   | T {$$=$1; root=$$;}
   ;
T : T '*' F {$$=createNode("*",$1,$3);}
   | F {$$=$1;}
  ;
F : '(' E ')' {$$=$2;}
  | ID {$$=createNode($1,NULL,NULL);}
  ;
%%

int yylex(){
	int c=getchar();
	if(c==' '|| c=='\t') return yylex();
	if(c=='\n'|| c==EOF) return 0;
	if(isalpha(c)) {
		yylval.str=malloc(2);
		yylval.str[0]=c;
		yylval.str[1]='\0';
		return ID;
	}
return c;
}

int main(){
  printf("enter: ");
  if(yyparse()==0){
       printf("ast\n");
       Printtree(root,0);
	}
return 0;
}

int yyerror(char *s){
   printf("invalid");
return 0;
}


bison -d week10.y

gcc week10.tab.c -o week10.exe

week10.exe