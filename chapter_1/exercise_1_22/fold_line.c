// program to fold long input lines into two or more shorter lines after the
// last non-blank character that occurs before the n-th column of input.

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000

int get_line(char line[], int limit);
void fold_line(char line[], int length, int column_width);

int main(int argc, char *argv[]) {
    char line[LIMIT], length;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s column_width < somefile\n", argv[0]);
        return 1;
    }
    int column_width = atoi(argv[1]);
    while((length = get_line(line, LIMIT)) > 0) {
        if (length > column_width) {
            fold_line(line, length, column_width);
        }
        printf("%s", line);
    }
    return 0;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit; i++) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        line[i] = c;
        if (c == '\n') {
            ++i;
            break;
        }
    }
    line[i] = '\0';
    return i;
}

void fold_line(char line[], int length, int column_width) {
    int i, spaceholder, ncolumn;
    for (i = 0, ncolumn = 0; i < length; i++, ncolumn++) {
        if (line[i] == ' ') {
            spaceholder = i;
        }
        if (ncolumn == column_width) {
            line[spaceholder] = '\n';
            ncolumn = 0;
        }
    }
}
