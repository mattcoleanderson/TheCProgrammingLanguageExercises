#include <stdio.h>
#include <math.h>

// Write the function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s . In particular, itob(n,s,16) formats
// n as a hexadecimal integer in s
//
// CURRENTLY ONLY WORKS FOR POSITIVE VALUES

void itob(int value, char buffer[], int base) {
    // if value is 0 set buffer and return
    if (value == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    int startDigit = (int) (log10(value) / log10(base));
    int i, j;

    for (i = 0, j = startDigit; i <= startDigit; i++, j--) {
        int maxValueOfDigit = (int) pow(base, j);

        // Value we set the digit with
        int quotient = value / maxValueOfDigit;

        // Value should only be changed if there quotient is above 0
        if (quotient != 0)
            value %= maxValueOfDigit;

        // If quotient is less than 9 then the digit is numerical
        // If quotient is higher than 9 then the digit is alphabetical
        buffer[i] = (char) ((quotient <= 9) ? (quotient + '0') : ((quotient - 10) + 'A'));
    }
    buffer[i] = '\0';
}

int main() {

    int value = -16;
    int base = 16;
    char buffer[1000];

    itob(value, buffer, base);

    printf("%s\n", buffer);

    return 0;
}
