// program that replaces strings of blanks by the minimum number of tabs and
// blanks to achieve the same spacing.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c, nspace = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s tabstop < somefile\n", argv[0]);
        return 1;
    }
    int tabstop = atoi(argv[1]);
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nspace;
        } else {
            if (nspace > 0) {
                int ntabs = nspace / tabstop;
                for (int i = 0; i < ntabs; i++) {
                    putchar('\t');
                }
                for (int i = 0; i < nspace - ntabs * tabstop; i++) {
                    putchar(' ');
                }
                nspace = 0;
            }
            putchar(c);
        }
    }
    return 0;
}
