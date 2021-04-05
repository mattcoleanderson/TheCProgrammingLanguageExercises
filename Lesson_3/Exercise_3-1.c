#include <stdio.h>

// Our binary search makes two tests inside the loop, when one would suffice
// (at the price of more tests outside). Write a version with only one test
// inside the loop
//
// The following is the example binary search:
//
int binSearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while(low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

int binSearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high && x != v[mid]) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

int main() {

    int x = 5;
    int v[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int n = 9;

    printf("Binary Search Original: %d\n", binSearch1(x, v, n));
    printf("Binary Search 2       : %d\n", binSearch2(x, v, n));

    return 0;
}
