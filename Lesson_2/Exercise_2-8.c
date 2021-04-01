#include <stdio.h>

// Write a function rightRot(x,n) that returns the value of the integer x rotated to the right by n bit positions

unsigned rightRot(unsigned x, unsigned n);

int main() {

    printf("%u", rightRot(4, 32));

    return 0;
}

unsigned rightRot(unsigned x, unsigned n) {

    // If 0 wasn't unsigned we would end up with 0 for the maskRotation
    unsigned maskRotation = ~(~0U >> 1);

    while (n-- > 0) {
        if (x & 1)
            x = (x >> 1) | maskRotation;
        else
            x = x >> 1;
    }
    return x;
}
