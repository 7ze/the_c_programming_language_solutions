// program to copy input to its output, replacing each tab by \t, each backspace
// by \b and each backslash by \\.

#include <stdio.h>

int main() {
    long c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            c = 't';
        }
        if (c == '\b') {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\') {
            putchar('\\');
        }
        putchar(c);
    }
    return 0;
}
