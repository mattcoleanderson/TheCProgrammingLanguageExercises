#include <stdio.h>

// Write a program to remove all trailing blanks
// and tabs from each line of input, and to delete entirely blank lines.

#define MAX_LINE_LENGTH 1000

int getLine(char stream[], int limit);
int removeWhiteSpace(char from[], int length);

int main() {

    int length;
    char line[MAX_LINE_LENGTH];
    char modifiedLine[MAX_LINE_LENGTH];

    while ((length = getLine(line, MAX_LINE_LENGTH)) > 0) {
        length = removeWhiteSpace(line, length);
        if (length != 1)
            printf("%s", line);
    }
    return 0;
}

int getLine(char stream[], int limit) {
    int character, i;

    for (i = 0; (i < limit) & ((character = getchar()) != EOF) && (character != '\n'); ++i)
        stream[i] = (char) character;
    if (character == '\n')
        stream[i++] = (char) character;
    stream[i] = '\0';

    return i;
}

int removeWhiteSpace(char from[], int length) {
    int removedCharCount = 0;
    int i;

    for (i = length - 1; (i >= 0) && ((from[i] == '\n') || (from[i] == ' ') || (from[i] == '\t')); --i) {
        from[i] = '\0';
        ++removedCharCount;
    }
    from[++i] = '\n';
    --removedCharCount;

    return length - removedCharCount;
}
