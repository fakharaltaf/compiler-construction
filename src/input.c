#include "input.h"

/**
 * Reads one line from file pointer character by character
 * This function implements the character-by-character reading requirement
 * and treats newline as end-of-line as specified in the assignment
 */
int read_line_char_by_char(FILE *fp, char *buf, size_t max_len) {
    int ch;
    size_t i = 0;

    // Read characters one by one until newline or EOF
    while ((ch = fgetc(fp)) != EOF) {
        // Handle Windows line endings (CRLF) by ignoring CR
        if (ch == '\r') {
            continue;
        }
        
        // Newline ends the line (as per assignment: "Newline = End of Line")
        if (ch == '\n') {
            break;
        }
        
        // Store character if we have space (leave room for null terminator)
        if (i + 1 < max_len) {
            buf[i++] = (char)ch;
        }
        // If line is too long, we silently truncate for now
    }

    // If we hit EOF and got no characters, signal "no more lines"
    if (ch == EOF && i == 0) {
        return -1;
    }

    // Null-terminate the string
    buf[i] = '\0';
    return (int)i;
}