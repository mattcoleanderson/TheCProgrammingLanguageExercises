#include <stdio.h>

// Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrarily long input lines,
// and as much as possible of the text.

#define MAX_LINE_LENGTH 1000

int getLine(char stream[], int limit);
void copy(char to[], char from[]);

int main() {

    int currentLength;
    int maxLength = 0;
    char currentLine[MAX_LINE_LENGTH];
    char longestLine[MAX_LINE_LENGTH];

    while ((currentLength = getLine(currentLine, MAX_LINE_LENGTH)) > 0)
        if (currentLength > maxLength) {
            maxLength = currentLength;
            copy(longestLine, currentLine);
        }
    printf("The longest line is %d character%s long\n", maxLength, (maxLength == 1) ?  "" : "s");
    printf("The longest line is:\n");
    printf("\t%s\n", longestLine);

    return 0;
}


int getLine(char stream[], int limit) {

    int character;
    int i;

    for (i = 0; (i < limit-1) && ((character = getchar()) != EOF) && (character != '\n'); ++i)
        stream[i] = (char) character;
    if (character == '\n')
        stream[i++] = (char) character;     // increment i after assigning \n because we need i to equal the length
    stream[i] = '\0';

    return --i;
}

void copy(char to[], char from[]) {
    for (int i = 0; (to[i] = from[i]) !='\0'; ++i);
}
