#include <stdio.h>

// Write a program to count blanks, tabs, and newlines.

int main() {

    int characters;
    int newLines = 0;
    int blanks = 0;
    int tabs = 0;

    while ((characters = getchar()) != EOF) {
        if (characters == '\n')
            ++newLines;
        else if (characters == ' ')
            ++blanks;
        else if (characters == '\t')
            ++tabs;
    }
    printf("New Lines: %d\n", newLines);
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);

}
