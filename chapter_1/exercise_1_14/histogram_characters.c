// program to print a histogram of the frequencies of different characters.

#include <stdio.h>

int main() {
    int i = 0, j = 0;
    long c, ndigits[10], nlowercase_alphabets[26], nuppercase_alphabets[26],
    nspecial_characters = 0;
    for (i = 0; i < 26; i++) {
        if (i < 10) {
            ndigits[i] = 0;
        }
        nlowercase_alphabets[i] = 0;
        nuppercase_alphabets[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigits[c - '0'];
        } else if (c >= 'a' && c <= 'z') {
            ++nlowercase_alphabets[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            ++nuppercase_alphabets[c - 'A'];
        } else {
            ++nspecial_characters;
        }
    }
    printf("Frequency of characters:\n\n");
    for (i = 0; i < 10; i++) {
        if (ndigits[i]) {
            printf("[%d] |", i);
            for (j = 0; j < ndigits[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
    for (i = 0; i < 26; i++) {
        if (nlowercase_alphabets[i]) {
            printf("[%c] |", 'a' + i);
            for (j = 0; j < nlowercase_alphabets[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
    for (i = 0; i < 26; i++) {
        if (nuppercase_alphabets[i]) {
            printf("[%c] |", 'A' + i);
            for (j = 0; j < nuppercase_alphabets[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
    printf("[$]*|");
    for (i = 0; i < nspecial_characters; i++) {
        printf("#");
    }
    printf("\n\n");
    printf("*other characters\n");
    return 0;
}
