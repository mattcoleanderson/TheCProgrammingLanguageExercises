#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Extend atof to handle scientific notation of the form 123.45e-6 where a
// floating-point number may be followed by e or E and an optionally signed exponent

double atod(char s[]) {
    int i = 0;
    double number = 0;

    // Handle negative values
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;

    // Handle Whole Numbers
    for ( ; s[i] != '.' && tolower(s[i]) != 'e' && s[i] != '\0'; i++)
        number = (number * 10) + (s[i] - '0');

    // Handle decimals
    if (s[i] == '.') {
        i++; // Step past '.'
        for (int j = 1; tolower(s[i]) != 'e' && s[i] != '\0'; j++, i++)
            number += ((s[i] - '0') / pow(10, j));
    }

    // Handle scientific notation
    if (tolower(s[i]) == 'e') {
        double notationValue = 0;
        i++; // Step past 'e'

        // Handle negative notation
        int notationSign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;

        // Assign notationValue
        for ( ; s[i] != '\0'; i++)
            notationValue = (notationValue * 10) + (s[i] - '0');

        notationValue = pow(10, (notationValue * notationSign));
        number *= notationValue;
    }

    return number * sign;
}

int main() {

    char test[] = {"123.456E27"};

    printf("%g\n", atod(test));


    return 0;
}

