%{
    #include <stdio.h>
%}

%%
    [0-9]+          { printf("'%s' is a number.\n", yytext); }
    [a-zA-Z]+       { printf("'%s' is a word.\n", yytext); }
    [a-zA-Z0-9]+    { printf("'%s' is alphanumeric but not a pure word or number.\n", yytext); }
    .|\n            { /* Ignore other characters or newline */ }
%%

int main() {
    printf("Enter input (word or number): ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
