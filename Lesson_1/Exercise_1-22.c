#include <stdio.h>

// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of input.
// Make sure your program does something intelligent with very long lines,
// and if there are no blanks or tabs before the specified column.

#define MAX_LINE_LENGTH 1000
#define FOLD_LENGTH 20
#define NO_BLANK (-1)

int getLine(char stream[], int limit);
void foldLine(char stream[], int length, int lengthPerLine);
void insertValueInArray(char stream[], int length, int pos, char value);

int main() {

    int length;
    char line[MAX_LINE_LENGTH];

    while ((length = getLine(line, MAX_LINE_LENGTH)) > 0) {
        foldLine(line, length, FOLD_LENGTH);
        printf("%s", line);
    }

    return 0;
}

int getLine(char stream[], int limit) {
    int character, i;
    for (i = 0; (i < limit-1) && ((character = getchar()) != EOF) && (character != '\n'); ++i)
        stream[i] = (char) character;
    if (character == '\n')
        stream[i++] = (char) character;
    stream[i] = '\0';

    return i;
}

void foldLine(char stream[], int length, int lengthPerLine) {
    if (--length <= lengthPerLine)
        return;

    int i = lengthPerLine - 1;
    while (i < length-1) {
        if (stream[i] == ' ' || stream[i] == '\t') {
            stream[i] = '\n';
            i += lengthPerLine;
        }
        else if (i == NO_BLANK || stream[i] == '\n') {
            i += lengthPerLine;
            insertValueInArray(stream, ++length, i, '\n');
            i += lengthPerLine;
        }
        else {
            i--;
        }
    }
}

void insertValueInArray(char stream[], int length, int pos, char value) {
    for (int i = length; i >= pos ; --i) {
        stream[i] = stream[i-1];
    }
    stream[pos] = value;
}

