# Lexical Analyzer for Simple Language

## Overview
This is a simple lexical analyzer written in C that supports:
- Float data type (e.g., 3.14, 2.5, 99.99)
- Identifiers (letters followed by optional digits, e.g., temp1, myVar, x1)
- Newline detection

## Components

### Main Components:
- **Input Buffer**: Stores the entire input file content
- **Two Pointers**: `forward` and `lexeme_begin` to track lexemes
- **DFA Simulator**: Main function that processes tokens
- **Symbol Table**: Stores all valid tokens with their types

### Files:
- `main.c`: The main lexical analyzer code
- `input.txt`: Input source code to analyze
- `output.txt`: Generated tokens output
- `symbol_table.txt`: Symbol table showing all identified tokens

## How to Run:
1. Compile: `gcc main.c -o lexical_analyzer`
2. Run: `./lexical_analyzer`
3. Check `output.txt` and `symbol_table.txt` for results

## Rules Implemented:
- Only float data type supported
- Valid identifiers: letters followed by optional digits
- Invalid tokens are marked as "INVALID"
- Newlines are recognized as end of line
- Symbol table prevents duplicate entries
