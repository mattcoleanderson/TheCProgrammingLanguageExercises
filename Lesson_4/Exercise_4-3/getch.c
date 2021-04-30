#include <stdio.h>

#define BUFFERSIZE 100

char buffer[BUFFERSIZE];
int bufferPosition = 0;

int getCh(void){
    return (bufferPosition > 0) ? buffer[--bufferPosition] : getchar();
}

void unGetCh(int c) {
    if (bufferPosition >= BUFFERSIZE)
        printf("ungetch: too many characters\n");
    else
        buffer[bufferPosition++] = c;

}
