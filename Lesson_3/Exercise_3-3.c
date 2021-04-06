#include <stdio.h>

// Write a function expand(s1,s2) that expands shorthand notations like a-z in the
// string s1 into the equivalent complete list abc...xyz in s2 . Allow for letters
// of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9
// and -a-z . Arrange that a leading or trailing - is taken literally

#define MAX_ARRAY_LENGTH 1000

void expand(const char from[], char to[]);

int main() {

    char string1[] = "-a-z";
    char string2[MAX_ARRAY_LENGTH];

    expand(string1, string2);

    printf("Original: %s\n", string1);
    printf("Expanded: %s\n", string2);

    return 0;
}


void expand(const char from[], char to[]) {
    int i, j;
    for (i = j = 0; from[i]; i++) {
        switch (from[i]) {
            case '-':
                // Set leading or trailing '-'
                if (i == 0 || from[i+1] == '\0')
                    to[j++] = from[i];
                // Range
                else {
                    char startRange = from[i-1];
                    char endRange = from[i+1];
                    while (startRange != endRange) {
                        if (startRange+1 < endRange)
                            to[j++] = (char) ++startRange;
                        else if (startRange-1 > endRange)
                            to[j++] = (char) --startRange;
                        else
                            break;
                    }
                }
                break;
            default:
                // Set any explicit value
                to[j++] = from[i];
                break;
        }
    }
    // Set null character
    to[j++] = from[i];

}
