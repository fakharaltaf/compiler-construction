#include "scanner.h"
#include <string.h>
#include <ctype.h>

/**
 * Simple two-pointer scanner for Step 1
 * This extracts lexemes (chunks) from the input line
 * We'll enhance this in later steps with proper DFA validation
 */
void scan_line(const char *line, FILE *tokens_out) {
    if (!line || !tokens_out) return;
    
    const char *start = line;  // Pointer 1: marks start of current lexeme
    const char *curr = line;   // Pointer 2: moves forward to find end
    
    printf("  Scanning: '%s'\n", line);
    
    while (*curr) {
        // Skip whitespace
        while (*curr && (*curr == ' ' || *curr == '\t')) {
            curr++;
        }
        
        if (*curr == '\0') break;  // End of line
        
        // Mark start of new lexeme
        start = curr;
        
        // Move curr pointer until we hit whitespace or end
        while (*curr && *curr != ' ' && *curr != '\t') {
            curr++;
        }
        
        // Extract the lexeme
        int length = curr - start;
        if (length > 0 && length < 63) {  // Reasonable size limit
            char lexeme[64];
            strncpy(lexeme, start, length);
            lexeme[length] = '\0';
            
            // For Step 1: just write the raw lexeme to output
            // In Step 3, we'll use DFA to classify it properly
            fprintf(tokens_out, "%s\n", lexeme);
            printf("    Found lexeme: '%s'\n", lexeme);
        }
    }
}

/**
 * DFA Simulator - placeholder for Step 3
 * This will classify lexemes into token types
 */
TokenType dfa_simulator(const char *lexeme) {
    if (!lexeme) return TOKEN_INVALID;
    
    // Placeholder implementation - we'll build this in Step 3
    if (strcmp(lexeme, "float") == 0) {
        return TOKEN_FLOAT_KEYWORD;
    }
    else if (strcmp(lexeme, "=") == 0) {
        return TOKEN_ASSIGNMENT;
    }
    // More classification logic will go here in Step 3
    
    return TOKEN_INVALID;
}