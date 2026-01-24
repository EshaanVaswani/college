%{

#include<stdio.h>
char Name[10];

%}

%%

[\n] {
printf("Hi %s", Name);
re
}

%%

void main() {
	char c;
	do {
		printf("What is your name??");
		scanf("%s", Name);
		printf("/nPress any key to continue(Y/y):");
		scanf("%c", &c);
		yylex();		
	} while ((c=='Y')||(c=='y'));
}
