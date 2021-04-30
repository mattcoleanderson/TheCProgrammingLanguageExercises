#include <stdio.h>
#include "calc.h"

#define MAXVAL 100      // maximum depth of val stack
int stackPosition = 0;  // next free stack position
double val[MAXVAL];     // value stack

// push: push f onto value stack
void push(double f) {
    if (stackPosition < MAXVAL)
        val[stackPosition++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
    if (stackPosition > 0)
        return val[--stackPosition];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
