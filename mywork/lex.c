#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100

// Token contains the information of the token and its type
struct Token
{
    char type[MAX_TOKEN_LENGTH];
    char value[MAX_TOKEN_LENGTH];
};

struct Lexer
{
    char source_code[MAX_TOKEN_LENGTH];
    struct Token tokens[MAX_TOKEN_LENGTH];
    int token_count;
};

// Constructor of the lexer
void initLexer(struct Lexer *lexer, const char *source_code)
{
    strcpy(lexer->source_code, source_code);
    lexer->token_count = 0;
}

// Function to add a token to the token list
void addToken(struct Lexer *lexer, const char *type, const char *value)
{
    if (lexer->token_count < MAX_TOKEN_LENGTH)
    {
        strcpy(lexer->tokens[lexer->token_count].type, type);
        strcpy(lexer->tokens[lexer->token_count].value, value);
        lexer->token_count++;
    }
}

// Main function to tokenize the source code
void tokenize(struct Lexer *lexer)
{
    lexer->token_count = 0;
    char current_token[MAX_TOKEN_LENGTH];
    int i = 0;

    // Loop over the whole code we read from the file
    while (lexer->source_code[i] != '\0')
    {
        char current_char = lexer->source_code[i];

        if (isalpha(current_char))
        {
            // Identify identifiers
            int j = 0;
            current_token[j++] = current_char;
            while (isalnum(lexer->source_code[i + 1]) || lexer->source_code[i + 1] == '_')
            {
                current_char = lexer->source_code[++i];
                current_token[j++] = current_char;
            }
            current_token[j] = '\0';
            addToken(lexer, "IDENTIFIER", current_token);
        }
        else if (isdigit(current_char))
        {
            // Identify integers
            int j = 0;
            current_token[j++] = current_char;
            while (isdigit(lexer->source_code[i + 1]))
            {
                current_char = lexer->source_code[++i];
                current_token[j++] = current_char;
            }
            current_token[j] = '\0';
            addToken(lexer, "INTEGER", current_token);
        }
        else if (isspace(current_char))
        {
            // Ignore whitespaces
            i++;
            continue;
        }
        else
        {
            // Treat other characters as individual tokens
            current_token[0] = current_char;
            current_token[1] = '\0';
            addToken(lexer, current_token, current_token);
            i++;
        }
        i++;
    }
}

int main()
{
    FILE *infile = fopen("input_code.txt", "r");
    if (!infile)
    {
        fprintf(stderr, "Failed to open input_code.txt\n");
        return 1;
    }

    char source_code[MAX_TOKEN_LENGTH];
    fread(source_code, 1, sizeof(source_code), infile);
    fclose(infile);

    struct Lexer lexer;
    initLexer(&lexer, source_code);
    tokenize(&lexer);

    printf("Total number of tokens: %d\n", lexer.token_count);
    return 0;
}
