// verify the expression getchar() != EOF is 0 or 1

#include <stdio.h>

int main() {
    printf("value of the expression \"getchar() != EOF\": %d\n", getchar() != EOF);
    return 0;
}

// NOTE: The expression getchar() != EOF is equal with 1 only if input char
// is != with EOF. A useful thing to know is that on Unix like systems the EOF
// char is accessible with CTRL+D.
