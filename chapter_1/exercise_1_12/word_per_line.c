// program that prints it input one world per line

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
    long c, state;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = IN;
            putchar(c);
        }
        else if (state == IN) {
            state = OUT;
            putchar('\n');
        }
    }
    return 0;
}
