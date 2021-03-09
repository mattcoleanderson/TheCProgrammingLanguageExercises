#include <stdio.h>

// Write a program to print a histogram of the lengths of words in its input.
// It is easy to draw the histogram with the bars horizontal;
// a vertical orientation is more challenging.

#define LENGTH 11

int main() {

    int character;
    long wordLength = 0;
    long wordLengths[LENGTH];
    int finalIndex = LENGTH - 1;

//    Set initial value of indices to 0
    for (int i = 0; i < LENGTH; ++i) {
        wordLengths[i] = 0;
    }

//    Keep count of number of words at specific lengths
    while ((character = getchar()) != EOF) {
        if (character != ' ' && character != '\t' && character != '\n')
            ++wordLength;
        else {
            if (wordLength == 0)
                continue;
            else if (wordLength <= finalIndex)
                ++wordLengths[wordLength - 1];
            else
                ++wordLengths[finalIndex];
            wordLength = 0;
        }
    }

//    Find the max number of words with the same length
    long max = 0;
    for (int i = 0; i < LENGTH; ++i) {
        if (max < wordLengths[i])
            max = wordLengths[i];
    }

    // Print the histogram
    for (long y = max; y >= -1; --y) {
        if (y > 0) {
            printf("%3d", y);
            printf(" |");
        }
        else if (y == 0)
            printf("    +");
        else
            printf("     ");

        for (int x = 0; x < LENGTH; ++x) {
            if (y == 0)
                printf("---");
            else if (y == -1)
                printf("%3d", x + 1);
            else if (wordLengths[x] >= y)
                printf(" ██");
            else
                printf("   ");
        }

        putchar('\n');
    }

}
