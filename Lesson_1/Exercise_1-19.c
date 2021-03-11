#include <stdio.h>

// Write a function reverse() that reverses the character string s.
// Use it to write a program that reverses its input a line at a time.

#define MAX_LINE_LENGTH 1000

int getLine(char stream[], int limit);
void reverse(char to[], char from[], int length);

int main() {

    int length;
    char line[MAX_LINE_LENGTH];
    char reversedLine[MAX_LINE_LENGTH];

    while ((length = getLine(line, MAX_LINE_LENGTH)) != 0)
        if (length != 1) {
            reverse(reversedLine, line, length);
            printf("%s", reversedLine);
        }


    return 0;
}

int getLine(char stream[], int limit) {
    int character, i;

    for (i = 0; (i < limit) && ((character = getchar()) != EOF) && (character != '\n'); ++i)
        stream[i] = (char) character;
    if (character == '\n')
        stream[i++] = (char) character;
    stream[i] = '\0';

    return i;
}

void reverse(char to[], char from[], int length) {
    int lower = 0;
    int upper = length - 1;

    while (upper >= 0) {
        to[lower] = from[upper];

        --upper;
        ++lower;
    }
}
