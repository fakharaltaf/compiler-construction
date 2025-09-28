#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>

#define MAX_IDENTIFIERS 100
#define MAX_IDENTIFIER_LENGTH 64

/**
 * Symbol table entry structure
 * Stores identifier name and its type (only float for this assignment)
 */
typedef struct {
    char name[MAX_IDENTIFIER_LENGTH];
    char type[16];  // "float" for this assignment
} SymbolEntry;

/**
 * Symbol table structure
 */
typedef struct {
    SymbolEntry entries[MAX_IDENTIFIERS];
    int count;
} SymbolTable;

/**
 * Initialize the symbol table
 * @param table: Pointer to symbol table to initialize
 */
void init_symbol_table(SymbolTable *table);

/**
 * Add an identifier to the symbol table (if not already present)
 * @param table: Pointer to symbol table
 * @param identifier: Name of the identifier
 * @param type: Type of the identifier ("float")
 * @return: 1 if added, 0 if already exists
 */
int add_to_symbol_table(SymbolTable *table, const char *identifier, const char *type);

/**
 * Write symbol table contents to file
 * @param table: Pointer to symbol table
 * @param file: File to write to
 */
void write_symbol_table(const SymbolTable *table, FILE *file);

#endif // SYMTAB_H