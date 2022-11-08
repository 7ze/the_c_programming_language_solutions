// program to print a vertical histogram of the lengths of words in its input.

#include <stdio.h>

#define FREQUENCY_LIMIT 50

int main() {
    int word_length = 0, i, j;
    long c, frequency[FREQUENCY_LIMIT], max_frequency = 0;
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
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
        }
    }
    printf("Frequency of words with respect to their length\n\n");
    for (i = 0; i < FREQUENCY_LIMIT; i++) {
        if (frequency[i])
            printf(" [%2d] ", i);
    }
    printf("\n");
    for (i = 0; i < max_frequency; i++) {
        for (j = 0; j < FREQUENCY_LIMIT; j++) {
            if (frequency[j]) {
                if(frequency[j] > i) {
                    printf("  ##  ");
                }
                else {
                    printf("      ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
