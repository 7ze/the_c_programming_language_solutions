// program that replaces tabs in the input with the proper number of blanks to
// space to the next tab stop. Assume a fixed set of tab stops, say every n
// columns.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s tabstop < somefile\n", argv[0]);
        return 1;
    }
    int tabstop = atoi(argv[1]);
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < tabstop; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
