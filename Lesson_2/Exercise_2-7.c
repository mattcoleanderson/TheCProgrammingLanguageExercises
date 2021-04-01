#include <stdio.h>

// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged

unsigned invert(unsigned x, int p, int n);

int main() {

    printf("%u", invert(27, 3, 3));

    return 0;
}

unsigned invert(unsigned x, int p, int n) {

    // Creates a mask of n digits turned on
    int mask = ~(~0 << n);
    // Amount of bits to shift to p
    int shift = p+1-n;

    return x ^ (mask << shift);
}
