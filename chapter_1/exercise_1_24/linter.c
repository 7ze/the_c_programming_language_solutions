// check a C program for rudimentary syntax errors like unbalanced parantheses,
// brackets and braces. Don't forget about quotes

#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct count {
    int curlybraces;
    int simplebraces;
    int squarebraces;
    int doublequotes;
    int singlequotes;
    int backticks;
};

void check_pair(char character, int count);

int main() {
    int c, in_comment = FALSE, line_comment = FALSE, block_comment = FALSE;
    struct count n = {0, 0, 0, 0, 0, 0};
    while ((c = getchar()) != EOF) {
        // comments
        if (!in_comment && c == '/') {
            c = getchar();
            if (c == '*' || c == '/')
                in_comment = TRUE;
            if (c == '/')
                line_comment = TRUE;
            if (c == '*')
                block_comment = TRUE;
        }
        // escape sequence
        if (c == '\\')
            getchar();
        if (!in_comment) {
            if (c == '{')
                n.curlybraces++;
            if (c == '}')
                n.curlybraces--;
            if (c == '(')
                n.simplebraces++;
            if (c == ')')
                n.simplebraces--;
            if (c == '[')
                n.squarebraces++;
            if (c == ']')
                n.squarebraces--;
            if (c == '"')
                n.doublequotes++;
            if (c == '\'')
                n.singlequotes++;
            if (c == '`')
                n.backticks++;
        } else {
            if (line_comment == TRUE && c == '\n') {
                in_comment = FALSE;
                line_comment = FALSE;
            } else {
                if (c == '*') {
                    if ((c = getchar()) == '/') {
                        in_comment = FALSE;
                        block_comment = FALSE;
                    }
                }
            }
        }
    }
    check_pair('{', n.curlybraces);
    check_pair('(', n.simplebraces);
    check_pair('[', n.squarebraces);
    check_pair('"', n.doublequotes);
    check_pair('\'', n.singlequotes);
    check_pair('`', n.backticks);
    return 0;
}

void check_pair(char character, int count) {
    if (count % 2 != 0)
        printf("%c doesn't have it's matching pair. Fix it!\n", character);
}
