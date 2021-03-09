#include <stdio.h>

// Write a program to print a histogram of the frequencies of different characters in its input.

#define LENGTH 26

int main() {

    int character;
    int maxFrequency = 0;
    int frequencies[LENGTH];

    // Set indices to 0
    for (int i = 0; i < LENGTH; ++i) {
        frequencies[i] = 0;
    }

    // Read in input
    while ((character = getchar()) != EOF) {
        if (character == ' ' || character == '\t' || character == '\n')
            continue;
        else if (character >= 'a' && character <= 'z')
            ++frequencies[character - 'a'];
        else if (character >= 'A' && character <= 'Z')
            ++frequencies[character - 'A'];
    }

    // Get maxFrequency
    for (int i = 0; i < LENGTH; ++i) {
        if (frequencies[i] > maxFrequency)
            maxFrequency = frequencies[i];
    }

    // Print histogram
    for (int y = maxFrequency; y >= -1; --y) {
        if (y > 0) {
            printf("%4d", y);
            printf(" |");
        }
        else if (y == 0)
            printf("     +");
        else
            printf("      ");

        for (int x = 0; x < LENGTH; ++x) {
            if (y == 0)
                printf("----");
            else if (y == -1)
                printf("%4c", x + 'A');
            else if (frequencies[x] >= y)
                printf(" ███");
            else
                printf("    ");
        }

        putchar('\n');

    }

}
