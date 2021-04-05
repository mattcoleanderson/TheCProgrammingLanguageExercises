#include <stdio.h>

// Write a function escape(s,t) that converts characters like newline
// and tab into visible escape sequences like \n and \t as it copies
// the string t to s . Use a switch . Write a function for the other
// direction as well, converting escape sequences into the real characters

#define MAX_LINE_LENGTH 1000

void escape(const char from[], char to[]);
void unescape(const char from[], char to[]);

int main() {

    char line[] = "Hello\thow are you \\ doing today?\n \"I'm doing fine\"";
    char formattedLine[MAX_LINE_LENGTH];
    char unformattedLine[MAX_LINE_LENGTH];

    escape(line, formattedLine);

    printf("\nOriginal Line   :\n\n %s\n", line);
    printf("\nFormatted Line  :\n\n %s\n", formattedLine);

    unescape(formattedLine, unformattedLine);

    printf("\nUnformatted Line:\n\n %s\n", unformattedLine);

    return 0;
}

void escape(const char from[], char to[]) {
    int i, j;
    for (i = j = 0; from[i] != '\0'; i++, j++) {
        switch (from[i]) {
            case '\n':
                to[j++] = '\\';
                to[j] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j] = 't';
                break;
            case '\v':
                to[j++] = '\\';
                to[j] = 'v';
                break;
            case '\b':
                to[j++] = '\\';
                to[j] = 'b';
                break;
            case '\r':
                to[j++] = '\\';
                to[j] = 'r';
                break;
            case '\f':
                to[j++] = '\\';
                to[j] = 'f';
                break;
            case '\a':
                to[j++] = '\\';
                to[j] = 'a';
                break;
            case '\\':
                to[j++] = '\\';
                to[j] = '\\';
                break;
            case '\?':
                to[j++] = '\\';
                to[j] = '?';
                break;
            case '\'':
                to[j++] = '\\';
                to[j] = '\'';
                break;
            case '\"':
                to[j++] = '\\';
                to[j] = '"';
                break;
            default:
                to[j] = from[i];
                break;
        }
    }
    // null character
    to[j] = from[i];
}

void unescape(const char from[], char to[]) {
    int i, j;
    for (i = j = 0; from[i] != '\0'; i++, j++) {
        switch (from[i]) {
            case '\\':
                switch (from[++i]) {
                    case 'n':
                        to[j] = '\n';
                        break;
                    case 't':
                        to[j] = '\t';
                        break;
                    case 'v':
                        to[j] = '\v';
                        break;
                    case 'b':
                        to[j] = '\b';
                        break;
                    case 'r':
                        to[j] = '\r';
                        break;
                    case 'f':
                        to[j] = '\f';
                        break;
                    case 'a':
                        to[j] = '\a';
                        break;
                    case '\\':
                        to[j] = '\\';
                        break;
                    case '?':
                        to[j] = '\?';
                        break;
                    case '\'':
                        to[j] = '\'';
                        break;
                    case '"':
                        to[j] = '\"';
                        break;
                    default:
                        to[j] = from[i];
                }
                break;
            default:
                to[j] = from[i];
        }
    }
    // null character
    to[j] = from[i];
}

