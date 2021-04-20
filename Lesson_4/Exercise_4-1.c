#include <stdio.h>

// Write the function strrindex(s,t) , which returns the position of the
// rightmost occurrence of t in s , or -1 if there is none

int strrindex(const char s[], char t) {
    int position = -1;

    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == t)
            position = i;
    return position;
}

int main () {

    char test[] = "hello";
    char searchFor = 'l';

    printf("String:   %s\n", test);
    printf("Position: %i\n", strrindex(test, searchFor));

    return 0;
}

