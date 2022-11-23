// program to print all input lines that are longer than 80 characters

#include <stdio.h>

#define LIMIT 100
#define MAX 80

int get_line(char line[], int limit);

int main() {
    int length;
    char line[LIMIT];
    while ((length = get_line(line, LIMIT)) > 0) {
        if (length > MAX) {
            printf("%s", line);
        } 
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
