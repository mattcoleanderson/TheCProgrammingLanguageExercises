#include <stdio.h>

// Write a function setBits(x,p,n,y) that returns x with the n bits that
// begin at position p set to the rightmost n bits of y, leaving other bits unchanged

unsigned setBits(unsigned x, int p, int n, unsigned y);

int main() {

    printf("%u", setBits(31, 3, 3, 2));

    return 0;
}

unsigned setBits(unsigned x, int p, int n, unsigned y) {

    // Creates a mask of n digits turned on
    int mask = ~(~0 << n);
    // Amount of bits to shift to p
    int shift = p+1-n;

    // Bits to be changed are turned off in x
    // Bits to be changed are turned on in y
    // OR then creates a new value with the changes in y in the position p
    return (x & ~(mask << shift)) | (y & (mask << shift));
}