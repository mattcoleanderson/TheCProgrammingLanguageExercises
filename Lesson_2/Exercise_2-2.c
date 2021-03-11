#include <stdio.h>

// Write a loop equivalent to the for loop below without using && or ||:
// for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;

#define MAX_LINE_LENGTH 1000

int main() {

    int lim = MAX_LINE_LENGTH;
    char s[MAX_LINE_LENGTH];
    int c;
    int i = 0;

    while (i < lim - 1) {
        if ((c = getchar()) == '\n')
            break;
        if (c == EOF)
            break;
        else {
            s[i] = (char) c;
            i++;
        }
    }

    printf("%s", s);

}

