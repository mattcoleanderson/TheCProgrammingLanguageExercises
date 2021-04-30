#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getOperator: get next operator or numeric operand
int getOperator(char s[]) {
    int i, c;

    while ((s[0] = c = getCh()) == ' ' || c == '\t' || c == '\n')
        ;
    s[1] = '\0';
    i = 0;

    // not a number
    if (!isdigit(c) && c != '.') {
        char currentC = (char) c;

        // Check if negative
        if (c == '-' && isdigit(c = getCh()))
            s[++i] = (char) c;
        else {
            return currentC;
        }
    }

    // collect integer part
    if (isdigit(c))
        while (isdigit(s[++i] = c = getCh()))
            ;
    // collect fraction part
    if (c == '.')
        while (isdigit(s[++i] = c = getCh()))
            ;

    s[i] = '\0';

    if (c != EOF)
        unGetCh(c);

    return NUMBER;
}
