#include <stdio.h>

// Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop.
// Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#define MAX_LINE_LENGTH 1000
#define TABSIZE 4

int getLine(char stream[], int limit);
void deTab(char to[], char from[], int length, int tabSize);

int main() {

    int length;
    char line[MAX_LINE_LENGTH];
    char formattedLine[MAX_LINE_LENGTH];

    while ((length = getLine(line, MAX_LINE_LENGTH)) > 0) {
        deTab(formattedLine, line, length, TABSIZE);
        printf("%s", formattedLine);
    }

    return 0;
}


int getLine(char stream[], int limit) {
    int character, i;

    for (i = 0; (i < limit - 1) && ((character = getchar()) != EOF) && (character != '\n'); ++i)
        stream[i] = (char) character;

    if (character == '\n')
        stream[i++] = (char) character;
    stream[i] = '\0';

    return i;
}


void deTab(char to[], char from[], int length, int tabSize) {
    int iTo, iFrom;
    iTo = iFrom = 0;

    while (iFrom < length) {
        int iSpaces = 0;

        if (from[iFrom] != '\t')
            to[iTo++] = from[iFrom];
        else
            while (iSpaces++ < tabSize)
                to[iTo++] = ' ';
        iFrom++;
    }
}
