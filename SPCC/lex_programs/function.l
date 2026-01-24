%{
void display(char*);

%}

%%

[\n] {
char name[20];
printf("Enter your name: ");
scanf("%s",name);
display(&name[0]);
return 1;

}

%%

void display(char *in){
printf("Hellloooo %s", in);
}

void main() {
yylex();
}