#include <stdio.h>

// Rewrite the function lower, which converts upper case
// letters to lower case, with a conditional expression instead of if-else

int lower(int c);

int main() {

    char character = 'A';

    printf("%c", lower(character));

    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

