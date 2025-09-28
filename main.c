#include <stdio.h>
#include <stdlib.h>
#include "src/input.h"
#include "src/scanner.h"
#include "src/symtab.h"

/**
 * Simple Lexical Analyzer - Step 1 Implementation
 * 
 * This program demonstrates:
 * 1. Reading input file character by character into a buffer
 * 2. Using two pointers to extract lexemes from each line
 * 3. Basic project structure with multiple files
 * 
 * Next steps will add:
 * - DFA token classification
 * - Proper symbol table management
 * - Complete token output formatting
 */

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <input-file>\n", argv[0]);
        printf("Example: %s input.txt\n", argv[0]);
        return 1;
    }

    const char *input_path = argv[1];

    // Open input file for reading
    FILE *input_file = fopen(input_path, "r");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    // Create output files
    FILE *tokens_output = fopen("output.txt", "w");
    if (!tokens_output) {
        perror("Failed to create output.txt");
        fclose(input_file);
        return 1;
    }

    FILE *symbol_table_output = fopen("symbol_table.txt", "w");
    if (!symbol_table_output) {
        perror("Failed to create symbol_table.txt");
        fclose(tokens_output);
        fclose(input_file);
        return 1;
    }

    // Initialize symbol table
    SymbolTable symbol_table;
    init_symbol_table(&symbol_table);

    // Process input file line by line
    char line_buffer[MAX_LINE];
    int line_number = 1;
    int line_length;

    printf("=== Lexical Analyzer - Step 1 ===\n");
    printf("Reading input file: %s\n", input_path);
    printf("Processing lines (newline = end-of-line):\n\n");

    while ((line_length = read_line_char_by_char(input_file, line_buffer, sizeof(line_buffer))) != -1) {
        printf("Line %2d: '%s'\n", line_number, line_buffer);
        
        // Use two-pointer scanning to extract lexemes
        scan_line(line_buffer, tokens_output);
        
        printf("\n");
        line_number++;
    }

    // Write symbol table (empty for now, will be populated in later steps)
    write_symbol_table(&symbol_table, symbol_table_output);

    // Clean up
    fclose(symbol_table_output);
    fclose(tokens_output);
    fclose(input_file);

    printf("=== Step 1 Complete ===\n");
    printf("✓ Created output.txt with raw lexemes\n");
    printf("✓ Created symbol_table.txt (empty for now)\n");
    printf("✓ Demonstrated character-by-character reading\n");
    printf("✓ Demonstrated two-pointer lexeme extraction\n");
    printf("\nNext step: Add DFA classification for proper token types\n");

    return 0;
}