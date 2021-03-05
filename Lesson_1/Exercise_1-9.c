#include <stdio.h>

// Write a program to copy its input to its output,
// replacing each string of one or more blanks by a single blank.

int main() {

    int character;

    // Set to "EOF" so variable starts with an integer value unique to any typed character
    int previousCharacter = EOF;

    while ((character = getchar()) != EOF) {
        if (character != ' ' || previousCharacter != ' ') {
            putchar(character);
            previousCharacter = character;
        }
    }

}
