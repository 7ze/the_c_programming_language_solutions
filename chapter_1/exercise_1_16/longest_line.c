// program that reads a set of text lines and prints the longest and the length

#include <stdio.h>

#define LIMIT 100

int get_line(char line[], int);
void copy(char line[], char longest_line[]);

int main() {
    int length, max_length = 0;
    char line[LIMIT], longest_line[LIMIT];
    while ((length = get_line(line, LIMIT)) > 0) {
        if (length > max_length) {
            max_length = length;
            copy(line, longest_line);
        }
    }
    if (max_length > 0) {
        printf("%s", longest_line);
    }
    return 0;
}

int get_line(char line[], int limit) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n' && limit != 0) {
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

void copy(char line[], char longest_line[]) {
    int i = 0;
    while ((longest_line[i] = line[i]) != '\0') {
        i++;
    }
    return;
}
