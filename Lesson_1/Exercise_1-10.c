#include <stdio.h>

// Write a program to copy its input to its output, replacing each tab by \t ,
// each backspace by \b , and each backslash by \\ .
// This makes tabs and backspaces visible in an unambiguous way.

int main() {

    int character;
    char backspace = '\b';
    char tab = '\t';
    char backslash = '\\';

    while ((character = getchar()) != EOF) {
        if (character == backspace)
            printf("\\b");
        else if (character == tab)
            printf("\\t");
        else if (character == backslash)
            printf("\\\\");
        else
            putchar(character);
    }

}
