// program to remove trailing blanks and tabs from each line of input, and to
// delete entirely blank lines

#include <stdio.h>

#define LIMIT 100

int get_line(char line[], int limit);
void clear_trailing(char line[], int length);

int main() {
    int length;
    char line[LIMIT];
    while ((length = get_line(line, LIMIT)) > 0) {
        clear_trailing(line, length);
        printf("%s", line);
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

void clear_trailing(char line[], int length) {
    int i = length - 1;
    for (; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') && i >= 0; --i)
        ;
    line[i + 1] = '\n';
    line[i + 2] = '\0';
}
