#include <stdio.h>
#include <string.h>

// Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with
// blanks on the left if necessary to make it wide enough

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = (int) (strlen(s) - 1); i <= j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int value, char buffer[], int minWidth) {
    int i;
    unsigned int positiveValue;

    // Convert value to a positive value
    positiveValue = (value < 0) ? -value : value;

    // Add digits to string in reverse order
    i = 0;
    do {
        buffer[i++] = (char) (positiveValue % 10 + '0');
    } while ((positiveValue /= 10) > 0);

    // If value is negative, add - sign
    if (value < 0) {
        buffer[i++] = '-';
    }

    // Adds padding
    while (i < minWidth)
        buffer[i++] = ' ';

    // Add Null char
    buffer[i] = '\0';

    reverse(buffer);
}

int main () {
    int test = -123;
    char buffer[1000];
    int minWidth = 15;

    itoa(test, buffer, minWidth);

    printf("Int Value             : %i\n", test);
    printf("Value as string       : %s\n", buffer);

    return 0;
}
