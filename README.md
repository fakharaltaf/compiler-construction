# Lexical Analyzer - Compiler Construction Assignment

A step-by-step implementation of a lexical analyzer in C, built according to assignment requirements.

## 📁 Project Structure

```
compiler-construction/
├── main.c                 # Main program entry point
├── input.txt              # Test input file
├── Makefile               # Build automation
├── README.md              # This file
└── src/                   # Source code modules
    ├── input.h/.c         # File I/O and character reading
    ├── scanner.h/.c       # Tokenization and DFA logic
    └── symtab.h/.c        # Symbol table management
```

## 🎯 Assignment Requirements Implemented

### ✅ Step 1 (Current)
- [x] **Character-by-character reading** into input buffer
- [x] **Two pointers** technique for lexeme extraction  
- [x] **Newline = End of Line** processing
- [x] **Multiple file structure** with proper headers
- [x] Creates `output.txt` and `symbol_table.txt` files

### 🔄 Coming Next
- [ ] **DFASimulator()** function with transition table
- [ ] **Float data type** validation (only floats allowed)
- [ ] **Identifier validation** (starts with letter, followed by letters/digits)
- [ ] **Symbol table** population with identifiers and types
- [ ] **Proper token classification** and output formatting

## 🚀 How to Build and Run

### On Windows (PowerShell/CMD):
```bash
# Compile all files together
gcc -Wall -Wextra -o lexer.exe main.c src/input.c src/scanner.c src/symtab.c

# Run the lexer
./lexer.exe input.txt
```

### On Linux/Ubuntu:
```bash
# Using Makefile (recommended)
make run

# Or compile manually
gcc -Wall -Wextra -o lexer main.c src/input.c src/scanner.c src/symtab.c
./lexer input.txt
```

## 📝 Input Format

The lexer expects input files with:
- Only `float` data type declarations
- Simple assignments with float values
- Identifiers starting with letters, followed by letters/digits
- No semicolons required (newline = end of statement)

### Example `input.txt`:
```
float temp1
temp1 = 12.5
float x
x = 3.14159
```

## 📤 Output Files

### `output.txt` - Token List
Currently shows raw lexemes (Step 1). Will show classified tokens in Step 3.
```
float
temp1
temp1
=
12.5
...
```

### `symbol_table.txt` - Identifier Table
Will be populated in later steps with format:
```
Identifier   Type
----------   ----
temp1        float
x            float
```

## 🏗️ Implementation Progress

| Step | Feature | Status |
|------|---------|--------|
| 1 | File I/O + Two Pointers | ✅ Complete |
| 2 | DFA Design | 🔄 Next |
| 3 | Token Classification | ⏳ Planned |
| 4 | Symbol Table Population | ⏳ Planned |
| 5 | Final Integration | ⏳ Planned |

## 🔧 Development Notes

- **Modular Design**: Each component in separate files for maintainability
- **Header Guards**: Prevent multiple inclusion issues
- **Cross-Platform**: Works on Windows and Linux
- **Memory Safe**: Proper buffer bounds checking
- **Assignment Compliant**: Follows all specified requirements

---

**Next Step**: Ready for Step 2 - implementing the DFA state machine for token classification.
