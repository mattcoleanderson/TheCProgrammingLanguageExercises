#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Write the function htoi(s) , which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F .

#define MAX_LINE_LENGTH 1000

int getLine(char stream[], int limit);
unsigned long long htoi(char stream[]);

int main() {

    char line[MAX_LINE_LENGTH];
    int i = 0;


    while (getLine(line, MAX_LINE_LENGTH) > 0) {
        unsigned long long decimalValue = htoi(line);
        (decimalValue == -1) ? printf("Invalid Hexadecimal\n") : printf("%llu\n", decimalValue);
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


int numericalValueOfHexDigit(char hexDigit) {
    return (isalpha(hexDigit)) ? (tolower(hexDigit) - 'a' + 10) : (hexDigit - '0');
}

unsigned long long htoi(char stream[]) {
    unsigned long long decimalValue = 0;
    unsigned long long length = strlen(stream);
    int i = 0;


    // Skips the optional hex identifier if present
    if (stream[0] == '0' && (stream[1] == 'x' || stream[1] == 'X')) {
        i = 2;
        length -= 2;
    }
    // Reduces length if a newline feed is present
    if (stream[length-1] == '\n')
        length -= 2;

    while (i <= length) {

        if (!isxdigit(stream[i]))
            return -1;
        decimalValue += (unsigned long long) (pow(16, (double) (length - i)) * numericalValueOfHexDigit(stream[i]));

        i++;
    }

    return decimalValue;
}
