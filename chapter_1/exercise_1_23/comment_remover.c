// program to remove all the comments from a C program

#include <stdio.h>

#define LIMIT 1000
#define TRUE 1
#define FALSE 0

int in_comment = 0;
int get_line(char line[], int limit);
void remove_single_comment(char line[], int length);
void remove_block_comment(char line[], int length);
void copy(char line[], char copy[]);

int main() {
    char line[LIMIT];
    int length;
    while ((length = get_line(line, LIMIT)) > 0) {
        remove_single_comment(line, length);
        remove_block_comment(line, length);
        printf("%s", line);
    }
    return 0;
}

int get_line(char line[], int limit) {
    int i, c;
    for (i = 0; i < limit; i++) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        line[i] = c;
        if (c == '\n') {
            ++i;
            break;
        }
    }
    line[i] = '\0';
    return i;
}

void remove_single_comment(char line[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (line[i] == '/' && line[i + 1] == '/') {
            line[i] = '\n';
            line[i + 1] = '\0';
        }
    }
}

void remove_block_comment(char line[], int length) {
    int i, j;
    char new_line[LIMIT];
    new_line[0] = '\0';
    for (i = 0, j = 0; i < length; i++) {
        if (i != length - 1 && line[i] == '/' && line[i + 1] == '*') {
            in_comment = TRUE;
        }
        if (in_comment == FALSE) {
            new_line[j] = line[i];
            ++j;
        }
        if (in_comment == TRUE && line[i - 1] == '*' && line[i] == '/') {
            in_comment = FALSE;
        }
    }
    new_line[j] = '\0';
    copy(new_line, line);
}

void copy(char line[], char copy[]) {
    int i = 0;
    while ((copy[i] = line[i]) != '\0') {
        ++i;
    }
}
