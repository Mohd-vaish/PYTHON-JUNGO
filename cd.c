#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    TOKEN_IF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_UNKNOWN,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    char value[64];
} Token;

const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case TOKEN_IF: return "IF";
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_OPERATOR: return "OPERATOR";
        case TOKEN_LPAREN: return "LPAREN";
        case TOKEN_RPAREN: return "RPAREN";
        case TOKEN_LBRACE: return "LBRACE";
        case TOKEN_RBRACE: return "RBRACE";
        case TOKEN_ASSIGN: return "ASSIGN";
        case TOKEN_SEMICOLON: return "SEMICOLON";
        case TOKEN_UNKNOWN: return "UNKNOWN";
        case TOKEN_END: return "END";
        default: return "UNKNOWN";
    }
}

Token getNextToken(const char **input) {
    Token token;
    token.value[0] = '\0';

    while (isspace(**input)) (*input)++;

    if (**input == '\0') {
        token.type = TOKEN_END;
        return token;
    }

    if (isalpha(**input)) {
        int i = 0;
        while (isalnum(**input)) {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';

        if (strcmp(token.value, "if") == 0)
            token.type = TOKEN_IF;
        else
            token.type = TOKEN_IDENTIFIER;

        return token;
    }

    if (isdigit(**input)) {
        int i = 0;
        while (isdigit(**input)) {
            token.value[i++] = **input;
            (*input)++;
        }
        token.value[i] = '\0';
        token.type = TOKEN_NUMBER;
        return token;
    }

    char ch = **input;
    (*input)++;

    switch (ch) {
        case '(': token.type = TOKEN_LPAREN; strcpy(token.value, "("); break;
        case ')': token.type = TOKEN_RPAREN; strcpy(token.value, ")"); break;
        case '{': token.type = TOKEN_LBRACE; strcpy(token.value, "{"); break;
        case '}': token.type = TOKEN_RBRACE; strcpy(token.value, "}"); break;
        case ';': token.type = TOKEN_SEMICOLON; strcpy(token.value, ";"); break;
        case '=': token.type = TOKEN_ASSIGN; strcpy(token.value, "="); break;
        case '+': case '-': case '*': case '/':
        case '<': case '>': case '!':
            token.type = TOKEN_OPERATOR;
            token.value[0] = ch;
            token.value[1] = '\0';
            break;
        default:
            token.type = TOKEN_UNKNOWN;
            token.value[0] = ch;
            token.value[1] = '\0';
    }

    return token;
}

int main() {

    const char *input = "if (a > 10) { x = a + 1; }";

    const char *ptr = input;
    Token token;

    do {
        token = getNextToken(&ptr);
        printf("%s : %s\n", tokenTypeToString(token.type), token.value);
    } while (token.type != TOKEN_END);

    return 0;
}
