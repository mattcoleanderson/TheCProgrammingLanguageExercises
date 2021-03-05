#include <stdio.h>

//Write a program that prints its input one word per line

int main() {

    int character;
    int previous = EOF;

    while ((character = getchar()) != EOF) {
        if ((character == ' ' || character == '\t' || character == '\n') && (previous == ' ' || previous == '\t' || previous == '\n')) {
            continue;
        } else if (character == ' ' || character == '\t') {
            previous = character;
            putchar('\n');
        } else {
            previous = character;
            putchar(character);
        }
    }

}
