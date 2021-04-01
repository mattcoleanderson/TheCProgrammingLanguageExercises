#include <stdio.h>

// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x .
// Explain why. Use this observation to write a faster version of bitCount

int bitCount(unsigned x);

int main() {

    printf("%d", bitCount(15));

    return 0;
}

int bitCount(unsigned x) {
    int bitCount = 0;
    while (x != 0) {
        x &= (x-1);
        bitCount++;
    }

    return bitCount;
}
