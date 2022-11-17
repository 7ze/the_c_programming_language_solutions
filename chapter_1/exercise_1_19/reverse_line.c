#include <stdio.h>

#define LIMIT 100

int get_line(char line[], int limit);
void reverse(char s[], char reverse[], int length);

int main() {
    char line[LIMIT], rev[LIMIT];
    int length;
    while ((length = get_line(line, LIMIT)) > 0) {
        reverse(line, rev, length);
        printf("%s", rev);
    }
    return 0;
}

int get_line(char line[], int limit) {
    int c, i = 0;
    // limit - 1 because last character is reserved for '\0'
    while ((c = getchar()) != EOF && c != '\n' && (limit - 1) > 0) {
        line[i] = c;
        --limit;
        ++i;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void reverse(char s[], char reverse[], int length) {
    int j = 0;
    // s[length] is \0
    if (s[length - 1] == '\n') {
        --length;
    }
    for (int i = length - 1; i >= 0; i--, j++) {
        reverse[j] = s[i];
    }
    reverse[j] = '\n';
    reverse[j + 1] = '\0';
}
