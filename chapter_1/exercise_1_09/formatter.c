// program to copy its input to its output, replacing each string of one or more
// blanks by a single blank

// thw way I chose to do this was to keep a counter to store the number of
// blanks

#include <stdio.h>

int main() {
    long n = 0, c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++n;
        } else {
            putchar(c);
            n = 0;
        }
        if (n == 1) {
            putchar(' ');
        }
    }
    return 0;
}

/**
// another neat way of doing this by storing last character and comparing it

#include <stdio.h>

int main(void)
{
    char c;
    char last_c = '\0';
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || last_c != ' ')
        {
            putchar(c);
        }

        last_c = c;
    }

    return 0;
}
*/
