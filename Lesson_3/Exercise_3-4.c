#include <stdio.h>
#include <string.h>
#include <limits.h>

// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2 to
// the power (wordsize - 1)) . Explain why not. Modify it to print that value
// correctly regardless of the machine on which it runs
//
// The reason the original itoa function doesn't can't convert the largest negative
// is because in a 2 complements number the signed range of an integer datatype (short,
// int, long) will have a max value 1 digit shorter than the min value.
//
// For example the range of a signed short is: (-32768, 32767). The original program would
// convert the -32,768 to 32,768, however this is 1 higher than the max value size of a short (32,767)
// The method I used, is to work with an unsigned int. So when the value is converted it will fit

// Original itoa function:
//void itoa(int n, char s[]) {
//    int i, sign;
//
//    if ((sign = n) < 0)
//        n = -n;
//    i = 0;
//    do {
//        s[i++] = n % 10 + '0';
//    } while ((n /= 10) > 0);
//
//    if (sign < 0)
//        s[i++] = '-';
//    s[i] = '\0';
//
//}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = (int) (strlen(s) - 1); i <= j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int value, char to[]) {
    int i;
    unsigned int positiveValue;

    // Convert value to a positive value
    positiveValue = (value < 0) ? -value : value;

    // Add digits to string in reverse order
    i = 0;
    do {
        to[i++] = (char) (positiveValue % 10 + '0');
    } while ((positiveValue /= 10) > 0);

    // If value is negative, add - sign
    if (value < 0)
        to[i++] = '-';
    
    // Add Null char
    to[i] = '\0';

    reverse(to);
}


int main() {
    int test = INT_MIN;
    char buffer[1000];

    itoa(test, buffer);

    printf("Minimum Int Value: %i\n", test);
    printf("Value as String  : %s\n", buffer);
}
