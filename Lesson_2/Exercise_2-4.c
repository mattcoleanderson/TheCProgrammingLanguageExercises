#include <stdio.h>

#define MAX_LINE_LENGTH 1000

void squeeze(char string[], const char excludedChars[]);

int main() {

    char string1[] = "ahbicld";
    char string2[] = "hil";

    printf("Original String  : %s\n", string1);
    printf("Chars to Exclude : %s\n", string2);

    squeeze(string1, string2);

    printf("Formatted String : %s\n", string1);

    return 0;
}


void squeeze(char s[], const char excludedChars[]) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        for (int k = 0; excludedChars[k] != '\0'; k++) {
            if (s[i] == excludedChars[k])
                break;
            else if (excludedChars[k+1] == '\0')
                s[j++] = s[i];
        }
    s[j] = '\0';
}

