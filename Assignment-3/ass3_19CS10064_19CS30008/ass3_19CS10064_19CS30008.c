#include <stdio.h>

int main() 
{
    int token;
    while(token = yylex()) 
    {
        switch(token) 
        {
            case KEYWORD: 
                printf("<KEYWORD, %d, %s>\n", token, yytext);
                break;

            case IDENTIFIER: 
                printf("<IDENTIFIER, %d, %s>\n", token, yytext);
                break;

            case INTEGER_CONSTANT: 
                printf("<INTEGER_CONSTANT, %d, %s>\n", token, yytext);
                break;

            case FLOATING_CONSTANT: 
                printf("<FLOATING_CONSTANT, %d, %s>\n", token, yytext);
                break;

            case CHAR_CONSTANT: 
                printf("<CHAR_CONSTANT, %d, %s>\n", token, yytext);
                break;

            case STRING_LITERAL: 
                printf("<STRING_LITERAL, %d, %s>\n", token, yytext);
                break;

            case PUNCTUATOR: 
                printf("<PUNCTUATOR, %d, %s>\n", token, yytext);
                break;

            case SINGLE_LINE_COMMENT_START: 
                printf("<SINGLE_LINE_COMMENT_START, %d, %s>\n", token, yytext);
                break;

            case SINGLE_LINE_COMMENT_END: 
                printf("<SINGLE_LINE_COMMENT_END, %d, %s>\n", token, yytext);
                break;

            case MULTI_LINE_COMMENT_START: 
                printf("<MULTI_LINE_COMMENT_START, %d, %s>\n", token, yytext);
                break;

            case MULTI_LINE_COMMENT_END: 
                printf("<MULTI_LINE_COMMENT_END, %d, %s>\n", token, yytext);
                break;

            default:
                printf("<INVALID_TOKEN, %s>\n", yytext);
        }
    }
    return 0;
}