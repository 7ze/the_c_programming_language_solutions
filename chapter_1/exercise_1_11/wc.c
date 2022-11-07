// word count program: Find the number of lines, words & characters from input

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
    long c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%ld %ld %ld\n", nl, nw, nc);
    return 0;
}
