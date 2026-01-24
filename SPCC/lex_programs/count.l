%{
    #include <stdio.h>

    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
%}

%option noyywrap

%%
    [^\s\n]+        { word_count++; char_count += yyleng; } // Words
    \n              { line_count++; char_count++; }         // New lines
    .               { char_count++; }                       // All other single characters
%%

int main() {
    printf("Enter text (Ctrl+D to end input):\n");
    yylex();
    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", line_count, word_count, char_count);
    return 0;
}

