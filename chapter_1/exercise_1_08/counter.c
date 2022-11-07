// program to count blanks, tabs, and newlines

#include <stdio.h>

int main() {
    long c, nblanks = 0, ntabs = 0, nlines = 0;
    while ((c = getchar()) != EOF) {
        if(c == ' ') ++nblanks;
        if(c == '\t') ++ntabs;
        if(c == '\n') ++nlines;
    }
    printf("blanks: %ld tabs: %ld lines: %ld\n", nblanks, ntabs, nlines);
    return 0;
}
