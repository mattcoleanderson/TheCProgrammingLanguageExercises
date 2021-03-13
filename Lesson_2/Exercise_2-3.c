#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Write the function htoi(s) , which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F .

#define MAX_LINE_LENGTH 1000

int getLine(char stream[], int limit);
long long htoi(char stream[]);

int main() {

    char line[MAX_LINE_LENGTH];
    int i = 0;


    while (getLine(line, MAX_LINE_LENGTH) > 0) {
        long decimalValue = htoi(line);
    }

}

int getLine(char stream[], int limit) {
    int character;
    int i;
    for (i = 0; i < limit - 1 && (character = getchar()) != EOF && character != '\n'; ++i)
        stream[i] = (char) character;
    if (character == '\n')
        stream[i++] = (char) character;
    stream[i] = '\0';

    return i;
}

// TODO: Figure out how to convert Alpha Hex character to their representation in decimal form
//  EX. 'A' == 10 nad 'F' == 16

// TODO: Write algorithm to convert hex digits to decimal
long long htoi(char stream[]) {
    long decimalValue;
    unsigned long long length = strlen(stream);
    int i = 0;


    if (stream[0] == '0' && (stream[1] == 'x' || stream[1] == 'X')) {
        i = 2;
        length -= 2;
    }
    if (stream[length-1] == '\n')
        length--;

    while (i > length-1) {
        if (!isxdigit(stream[i]))
            return -1;
        decimalValue =

        i++;
    }
}
