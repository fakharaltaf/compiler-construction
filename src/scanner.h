#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>

/**
 * Token types that our lexer can recognize
 * Based on assignment requirements: only float data type + identifiers
 */
typedef enum {
    TOKEN_FLOAT_KEYWORD,    // "float"
    TOKEN_IDENTIFIER,       // variable names like temp1, x, abc123
    TOKEN_FLOAT_NUMBER,     // float values like 12.5, 3.14
    TOKEN_ASSIGNMENT,       // "="
    TOKEN_INVALID,          // anything that doesn't match our rules
    TOKEN_END_OF_LINE       // end of current line
} TokenType;

/**
 * Structure to represent a token
 */
typedef struct {
    TokenType type;
    char value[64];  // the actual text of the token
} Token;

/**
 * Scans a line and extracts tokens using two-pointer technique
 * @param line: Input line to scan
 * @param tokens_out: File to write tokens to
 */
void scan_line(const char *line, FILE *tokens_out);

/**
 * DFA Simulator - determines token type for a given lexeme
 * @param lexeme: String to classify
 * @return: TokenType classification
 */
TokenType dfa_simulator(const char *lexeme);

#endif // SCANNER_H