#include <stdio.h>

// Write a program entab that replaces strings of blanks with the minimum number of tabs
// and blanks to achieve the same spacing. Use the same stops as for detab.
// When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

#define MAX_LINE_LENGTH 1000
#define TAB_SIZE 4

int getLine(char stream[], int limit);
int countWhiteSpace(int index, char stream[]);
void enTab(char to[], char from[], int length, int tabSize);

int main() {

    int length;
    char line[MAX_LINE_LENGTH];
    char formattedLine[MAX_LINE_LENGTH];

    while ((length = getLine(line, MAX_LINE_LENGTH)) != 0) {
        enTab(formattedLine, line, length, TAB_SIZE);
        printf("%s", formattedLine);
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

void enTab(char to[], char from[], int length, int tabSize) {
    int iTo, iFrom;
    iTo = iFrom = 0;

    while (iFrom < length) {
        if (from[iFrom] != ' ') {
            to[iTo++] = from[iFrom++];
            continue;
        } else {
            int fromWhiteSpace = countWhiteSpace(iFrom, from);
            int spaces = fromWhiteSpace % tabSize;
            int tabs = (fromWhiteSpace - spaces) / tabSize;
            int whiteSpaceLength = tabs + spaces;

            for (int i = 0; i < whiteSpaceLength; ++i) {
                if (tabs-- > 0)
                    to[iTo++] = '\t';
                else if (spaces-- > 0)
                    to[iTo++] = ' ';
            }
            iFrom += fromWhiteSpace;
        }
    }
    to[iTo] = '\0';
}

int countWhiteSpace(int index, char stream[]) {
    int count = 0;

    while (stream[index] == ' ') {
        count++;
        index++;
    }

    return count;
}
