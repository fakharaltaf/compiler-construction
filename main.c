// Fakhar Altaf 261949256
// Zenab Gauhar 261944521

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// making structure for symbol table entries
struct SymbolTable {
    char name[100];
    char type[20];
    int id;
};

// making global variables
char buffer[1000];
int forward = 0;
int lexeme_begin = 0;
struct SymbolTable symbols[100];
int symbol_count = 0;
FILE *output_file;
FILE *symbol_file;

// declaring functions
void readInputFile();
void DFASimulator();
int isFloat(char* lexeme);
int isIdentifier(char* lexeme);
void addToSymbolTable(char* name, char* type);
void printSymbolTable();
void resetPointers();

void main() {
    // opening output files
    output_file = fopen("output.txt", "w");
    symbol_file = fopen("symbol_table.txt", "w");
    
    // reading input file into buffer
    readInputFile();
    
    // starting lexical analysis
    DFASimulator();
    
    // printing symbol table to file
    printSymbolTable();
    
    // closing files
    fclose(output_file);
    fclose(symbol_file);
    
    printf("Lexical analysis completed!\n");
}

// reading input file character by character into buffer
void readInputFile() {
    FILE *input = fopen("input.txt", "r");
    int i = 0;
    char ch;
    
    // reading each character
    while ((ch = fgetc(input)) != EOF) {
        buffer[i] = ch;
        i++;
    }
    buffer[i] = '\0'; // adding null terminator
    fclose(input);
}

// main DFA simulator function
void DFASimulator() {
    while (forward < strlen(buffer)) {
        // skipping whitespace and tabs
        if (buffer[forward] == ' ' || buffer[forward] == '\t') {
            forward++;
            lexeme_begin = forward;
            continue;
        }
        
        // handling newline
        if (buffer[forward] == '\n') {
            fprintf(output_file, "NEWLINE\n");
            forward++;
            lexeme_begin = forward;
            continue;
        }
        
        // finding end of current lexeme
        int temp_forward = forward;
        while (temp_forward < strlen(buffer) && 
               buffer[temp_forward] != ' ' && 
               buffer[temp_forward] != '\t' && 
               buffer[temp_forward] != '\n') {
            temp_forward++;
        }
        
        // extracting lexeme
        char lexeme[100];
        int len = temp_forward - lexeme_begin;
        strncpy(lexeme, &buffer[lexeme_begin], len);
        lexeme[len] = '\0';
        
        // checking if lexeme is valid token
        if (isFloat(lexeme)) {
            fprintf(output_file, "FLOAT: %s\n", lexeme);
            addToSymbolTable(lexeme, "FLOAT");
        }
        else if (isIdentifier(lexeme)) {
            fprintf(output_file, "IDENTIFIER: %s\n", lexeme);
            addToSymbolTable(lexeme, "IDENTIFIER");
        }
        else {
            fprintf(output_file, "INVALID: %s\n", lexeme);
        }
        
        // moving pointers
        forward = temp_forward;
        lexeme_begin = forward;
    }
}

// checking if lexeme is valid float
int isFloat(char* lexeme) {
    int i = 0;
    int has_dot = 0;
    
    // checking each character
    while (lexeme[i] != '\0') {
        if (isdigit(lexeme[i])) {
            i++;
        }
        else if (lexeme[i] == '.' && has_dot == 0) {
            has_dot = 1;
            i++;
        }
        else {
            return 0; // invalid character found
        }
    }
    
    // must have at least one digit and one dot
    return (has_dot && i > 1);
}

// checking if lexeme is valid identifier
int isIdentifier(char* lexeme) {
    int i = 0;
    
    // first character must be letter
    if (!isalpha(lexeme[0])) {
        return 0;
    }
    
    i = 1;
    // remaining characters can be letters or digits
    while (lexeme[i] != '\0') {
        if (!isalnum(lexeme[i])) {
            return 0;
        }
        i++;
    }
    
    return 1;
}

// adding entry to symbol table
void addToSymbolTable(char* name, char* type) {
    // checking if already exists
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0) {
            return; // already exists
        }
    }
    
    // adding new entry
    strcpy(symbols[symbol_count].name, name);
    strcpy(symbols[symbol_count].type, type);
    symbols[symbol_count].id = symbol_count + 1;
    symbol_count++;
}

// printing symbol table to file
void printSymbolTable() {
    fprintf(symbol_file, "ID\tNAME\t\tTYPE\n");
    fprintf(symbol_file, "------------------------\n");
    
    for (int i = 0; i < symbol_count; i++) {
        fprintf(symbol_file, "%d\t%s\t\t%s\n", 
                symbols[i].id, 
                symbols[i].name, 
                symbols[i].type);
    }
}