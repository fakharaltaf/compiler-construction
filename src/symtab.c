#include "symtab.h"
#include <string.h>

/**
 * Initialize the symbol table
 */
void init_symbol_table(SymbolTable *table) {
    if (!table) return;
    table->count = 0;
    
    // Clear all entries
    for (int i = 0; i < MAX_IDENTIFIERS; i++) {
        table->entries[i].name[0] = '\0';
        table->entries[i].type[0] = '\0';
    }
}

/**
 * Check if identifier already exists in symbol table
 */
static int find_identifier(const SymbolTable *table, const char *identifier) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, identifier) == 0) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

/**
 * Add identifier to symbol table if it doesn't already exist
 */
int add_to_symbol_table(SymbolTable *table, const char *identifier, const char *type) {
    if (!table || !identifier || !type) return 0;
    
    // Check if already exists
    if (find_identifier(table, identifier) >= 0) {
        return 0;  // Already exists, don't add duplicate
    }
    
    // Check if we have space
    if (table->count >= MAX_IDENTIFIERS) {
        printf("Warning: Symbol table full, cannot add '%s'\n", identifier);
        return 0;
    }
    
    // Add new entry
    int index = table->count;
    strncpy(table->entries[index].name, identifier, MAX_IDENTIFIER_LENGTH - 1);
    table->entries[index].name[MAX_IDENTIFIER_LENGTH - 1] = '\0';
    
    strncpy(table->entries[index].type, type, 15);
    table->entries[index].type[15] = '\0';
    
    table->count++;
    printf("    Added to symbol table: '%s' (type: %s)\n", identifier, type);
    
    return 1;  // Successfully added
}

/**
 * Write symbol table to file in the required format
 */
void write_symbol_table(const SymbolTable *table, FILE *file) {
    if (!table || !file) return;
    
    // Write header
    fprintf(file, "Identifier   Type\n");
    fprintf(file, "----------   ----\n");
    
    // Write each entry
    for (int i = 0; i < table->count; i++) {
        fprintf(file, "%-12s %s\n", 
                table->entries[i].name, 
                table->entries[i].type);
    }
}