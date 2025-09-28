#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024  // Maximum characters per line

/**
 * Reads one line from file pointer character by character
 * @param fp: File pointer to read from
 * @param buf: Buffer to store the line
 * @param max_len: Maximum buffer size
 * @return: Number of characters read, or -1 if no more lines
 */
int read_line_char_by_char(FILE *fp, char *buf, size_t max_len);

#endif // INPUT_H