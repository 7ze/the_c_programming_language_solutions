// program to print a histogram of the lengths of words in its input.

#include <stdio.h>

#define FREQUENCY_LIMIT 50

int main() {
    int i, j, word_length;
    long c, frequency[FREQUENCY_LIMIT];
    word_length = 0;
    for (i = 0; i < FREQUENCY_LIMIT; i++) {
        frequency[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            ++word_length;
        } else if (word_length != 0) {
            ++frequency[word_length];
            word_length = 0;
        }
    }
    for (i = 0; i < FREQUENCY_LIMIT; i++) {
        if (frequency[i]) {
            printf("[%d] |", i);
            for (j = 0; j < frequency[i]; j++) {
                printf("##");
            }
            printf("\n");
        }
    }
    printf("Frequency of words with respect to their length\n");
    return 0;
}
