# Makefile for Lexical Analyzer
# Supports both Windows (MinGW/MSYS2) and Linux compilation

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = lexer
SRCDIR = src

# Source files
SOURCES = main.c $(SRCDIR)/input.c $(SRCDIR)/scanner.c $(SRCDIR)/symtab.c

# Object files (replace .c with .o)
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the lexer executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the lexer with the test input
run: $(TARGET)
	./$(TARGET) input.txt

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET) output.txt symbol_table.txt

# Clean for Windows
clean-win:
	del /Q *.o $(SRCDIR)\*.o $(TARGET).exe output.txt symbol_table.txt 2>nul || echo "Clean complete"

# Show project structure
structure:
	@echo "Project Structure:"
	@echo "├── main.c                 (main program)"
	@echo "├── input.txt              (test input)"
	@echo "├── Makefile               (build script)"
	@echo "└── src/"
	@echo "    ├── input.h/.c         (file I/O functions)"
	@echo "    ├── scanner.h/.c       (tokenization logic)"
	@echo "    └── symtab.h/.c        (symbol table management)"

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the lexer (default)"
	@echo "  run      - Build and run with input.txt"
	@echo "  clean    - Remove build artifacts (Linux/Mac)"
	@echo "  clean-win- Remove build artifacts (Windows)"
	@echo "  structure- Show project file structure"
	@echo "  help     - Show this help message"

.PHONY: all run clean clean-win structure help