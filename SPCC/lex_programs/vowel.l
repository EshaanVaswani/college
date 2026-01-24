%{
    #include <stdio.h>
%}

%%
    [aAeEiIoOuU]    {printf("'%s' is a vowel.\n",yytext);}
    [a-zA-Z]        {printf("'%s' is a consonant.\n",yytext);}
    .               {printf("'%s' is not a letter.\n",yytext);}
%%

int main() {
    printf("Enter a character: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
