%{
#include <stdio.h>
%}

%option noyywrap

%%
"int"|"float"|"if"|"else"     { printf("Keyword: %s\n", yytext); }
[0-9]+                        { printf("Number: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*        { printf("Identifier: %s\n", yytext); }
"="|"+"|"-"|"*"|"/"           { printf("Operator: %s\n", yytext); }
[;(){}]                       { printf("Punctuation: %s\n", yytext); }
[ \t\n]+                      { /* Ignore whitespace */ }
.                             { printf("Unknown: %s\n", yytext); }
%%

int main() {
    printf("Enter your code:\n");
    yylex();
    return 0;
}