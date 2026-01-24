%{

void display(char[], int);

%}

%%

[a-zA-Z]+[\n] {
int flag=1;
display(yytext,flag);
return 1;
}

[0-9]+[\n] {
int flag=0;
display(yytext,flag);
return 1;
}

.+ {
int flag=-1;
display(yytext,flag);
return 1;
}

%%

void display(char str[], int flag) {
if(flag==1)
	printf("The string %s is a word\n", str);
else if(flag==0)	
	printf("The string %d is a digit\n", atoi(str));
else 	
	printf("The string is either a word or digit\n");
}

void main(){
printf("Enter a string to check whether it is word or digit\n");
yylex();
}