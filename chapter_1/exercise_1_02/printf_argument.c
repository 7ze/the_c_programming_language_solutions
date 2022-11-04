// find out what happens when printf's argument string contains \c, where c is
// some character

#include <stdio.h>

int main() {
    printf("1.newline: hello,\nworld!");

    printf("\n2.tab: hello,\tworld!");

    printf("\n3.backspace: hello,\bworld!");

    printf("\n4.alert: hello,\aworld!");

    printf("\n5.vertical tab: hello,\vworld!");

    // carriage return moves cursor position to beginning of line
    printf("\n6.carriage return: hello,\rworld!");

    // formfeed page break ASCII control character.
    // Considered as whitespace by isspace() function
    printf("\n7.formfeed page break: hello,\fworld!");

    // escapes the next character
    printf("\n8.escape character: hello,\eworld!");

    printf("\n9.single quote: hello,\'world!");

    printf("\n10.double quotes: hello,\"world!");

    printf("\n11.backslash: hello,\\world");

    printf("\n12.question mark: hello,\?world");

    printf("\n");
    return 0;
}
