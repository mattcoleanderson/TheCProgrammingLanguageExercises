#include <stdio.h>

// Write a program to print all input lines that are longer than 80 characters.

#define MAX_LINE_LENGTH 1000
#define MIN_LINE_LENGTH 80

int getLine(char stream[], int limit);

int main() {

    int currentLength;
    char currentLine[MAX_LINE_LENGTH];

    while ((currentLength = getLine(currentLine, MAX_LINE_LENGTH)) > 0)
        if (currentLength > MIN_LINE_LENGTH) {
            printf("%s\n", currentLine);
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
